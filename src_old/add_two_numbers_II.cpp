// 445. Add Two Numbers II

#include <iostream>
#include <stack>

using namespace std;

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        stack<ListNode*> stk1, stk2;
        push(stk1, l1);
        push(stk2, l2);
        int sum = 0, carry = 0, base = 0;
        ListNode* head = nullptr;
        while (!stk1.empty() && !stk2.empty())
        {
            sum = carry + stk1.top()->val + stk2.top()->val;
            stk1.pop();
            stk2.pop();
            carry = sum / 10; 
            base = sum % 10;
            ListNode* l = new ListNode(base);
            l->next = head;
            head = l;
        }
        
        auto& s = stk1.empty() ? stk2 : stk1;
        while (!s.empty())
        {
            sum = carry + s.top()->val;
            s.pop();
            carry = sum / 10;
            base = sum % 10;
            ListNode* l = new ListNode(base);
            l->next = head;
            head = l;
        }
        
        if (carry)
        {
            ListNode* l = new ListNode(carry);
            l->next = head;
            head = l;
        }
        
        return head;
    }
    
private:
    void push(stack<ListNode*>& stk, ListNode* l)
    {
        while (l)
        {
            stk.push(l);
            l = l->next;
        }
    }
};

int main()
{
    return 0;
}