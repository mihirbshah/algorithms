// 430. Flatten a Multilevel Doubly Linked List

#include <iostream>
#include <utility>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// For a better solution, refer https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/discuss/152066/c%2B%2B-about-10-lines-solution

class Solution 
{
public:
    Node* flatten(Node* head) 
    {
        auto p = flattenChild(head);
        return p.first;
    }

private:
    pair<Node*, Node*> flattenChild(Node* head)
    {
        Node* node = head;
        Node* tail = head;
        while (node)
        {
            tail = node;
            if (node->child)
            {
                Node* oldNext = node->next;
                auto newNext = flattenChild(node->child);
                (newNext.second)->next = oldNext;
                if (oldNext) 
                {
                    oldNext->prev = newNext.second;
                }
                node->next = newNext.first;
                newNext.first->prev = node;
                node->child = nullptr;
                tail = newNext.second;
                node = oldNext;
            }
            else
            {
                node = node->next;
            }
        }
        
        return {head, tail};
    }
};

int main()
{
    return 0;
}