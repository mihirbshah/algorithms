#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>

using namespace std;

/*
* This is an implementation of a singly linked list with node-level locks to
* ensure mutual exclusion. The structure looks like this:
*          head_ -> node_0 -> node_1 -> ... -> node_n -> tail_
* Note that head_ and tail_ are dummy nodes.
*/
class LockBasedLinkedList {
public:
    // Initialize head_ to point to tail_ (empty list).
    LockBasedLinkedList() {
        tail_ = new Node(0);
        head_ = new Node(0, tail_);
    }

    /*
    * Insert a node with value val at position pos.
    *
    * To ensure mutual exclusion, the locks of the current node and the
    * previous nodes must be acquired for insertion to work. As soon as the
    * locks are acquired the code does roughly the following:
    *
    *      | prev -> node | prev -> node | prev    node |
    *      |              |          ^   |   v      ^   |
    *      |   new_node   |   new_node   |   new_node   |
    */
    void insert(int val, int pos) {
        Node *new_node = new Node(val);
        Node *prev = head_;
        unique_lock<mutex> prev_lk(prev->m);
        Node *node = prev->next;
        unique_lock<mutex> node_lk(node->m);
        for (int i = 0; i < pos && node != tail_; i++) {
            prev = node;
            node = node->next;
            prev_lk.swap(node_lk);
            node_lk = unique_lock<mutex>(node->m);
        }
        new_node->next = node;
        prev->next = new_node;
    }

    /*
    * Erase the node at position pos.
    *
    * To ensure mutual exclusion, follow the steps from insert(). As soon as
    * the locks are acquired the code does roughly the following:
    *
    *    (*)     (*)            (*)     (*)            (*)
    *  | prev -> node -> next | prev    node -> next | prev ---------> next |
    *  |                      |   v--------------^   |                      |
    *
    * (*) highlights the nodes whose locks are acquired.
    */
    void erase(int pos) {
        Node *prev = head_;
        unique_lock<mutex> prev_lk(prev->m);
        Node *node = prev->next;
        unique_lock<mutex> node_lk(node->m);
        for (int i = 0; i < pos && node != tail_; i++) {
            prev = node;
            node = node->next;
            prev_lk.swap(node_lk);
            node_lk = unique_lock<mutex>(node->m);
        }
        if (node == tail_) {
            return;
        }
        prev->next = node->next;
        node_lk.unlock();
        delete node;
    }

    int get(int pos) {
        Node *prev = head_;
        unique_lock<mutex> prev_lk(prev->m);
        Node *node = prev->next;
        unique_lock<mutex> node_lk(node->m);
        for (int i = 0; i < pos && node != tail_; i++) {
            prev = node;
            node = node->next;
            prev_lk.swap(node_lk);
            node_lk = unique_lock<mutex>(node->m);
        }
        if (node == tail_) {
            return 0;
        }
        return node->val;
    }

private:
    struct Node {
        int val;
        Node *next;
        mutex m;

        Node(int val_, Node *next_ = nullptr) : val(val_), next(next_) {}
    };

    Node *head_, *tail_;
};

void testNThread(int n) {
    const int N = 10;
    vector<thread> threads(n);
    LockBasedLinkedList lst;
    for (int i = 0; i < n; i++) {
        threads[i] = thread([i, &lst, N]() {
            for (int j = 0; j < N; j++) {
                lst.insert(i, 0);
            }
        });
    }
    for (int i = 0; i < n; i++) {
        threads[i].join();
    }
    for (int i = 0; i < N * n; i++) {
        int val = lst.get(0);
        lst.erase(0);
        cout << val << " ";
    }
    cout << "\n";
}

int main(int argc, char **argv) {
    int n = 10;
    if (argc >= 2) {
        n = atoi(argv[1]);
    }
    testNThread(n);
}

