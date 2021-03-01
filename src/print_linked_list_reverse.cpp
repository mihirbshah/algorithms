// 1265. Print Immutable Linked List in Reverse

#include <iostream>
#include <stack>

using namespace std;

class Solution 
{
public:
    void printLinkedListInReverse(ImmutableListNode* head) 
    {
        stack<ImmutableListNode*> stk;
        while (head)
        {
            stk.push(head);
            head = head->getNext();
        }
        
        while(!stk.empty())
        {
            stk.top()->printValue();
            stk.pop();
        }
    }
};

int main()
{
    return 0;
}