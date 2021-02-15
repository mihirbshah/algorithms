// 1597. Build Binary Expression Tree From Infix Expression

#include <iostream>
#include <string>
#include <stack>
#include "tree_util.h"

using namespace std;
using Node = TreeUtils::TreeNode;

class Solution 
{
public:
    Node* expTree(string s) 
    {
        int pos = lastPlusMinusAtRootLevel(s);
        if (pos != -1)
        {
            Node* ptr = new Node(s[pos]);
            ptr->left = expTree(s.substr(0, pos));
            ptr->right = expTree(s.substr(pos + 1, s.size() - pos - 1));
            return ptr;       
        }
        
        stack<Node*> stk;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (isdigit(s[i]) || s[i] == '*' || s[i] == '/')
            {
                stk.push(new Node(s[i]));
            }
            else if (s[i] == ')')
            {
                int j = matchingBracket(s, i);                
                Node* ptr = expTree(s.substr(j + 1, i - j - 1));
                stk.push(ptr);
                i = j;
            }
        }
        
        return processStack(stk);
    }
        
private:
    int lastPlusMinusAtRootLevel(string s)
    {
        int bracketCnt = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if ((s[i] == '-' || s[i] == '+') && !bracketCnt) return i;
            if (s[i] == ')') ++bracketCnt;
            if (s[i] == '(') --bracketCnt;
        }
        return -1;
    }
    
    int matchingBracket(string s, int pos)
    {
        int bracketCnt = 1;
        int j;
        for (j = pos - 1; j >= 0; --j)
        {
            if (s[j] == ')') ++bracketCnt;
            if (s[j] == '(') 
            {
                --bracketCnt;
                if (!bracketCnt) break;
            }
        }
        return j;
    }
    
    Node* processStack(stack<Node*>& stk)
    {
        while (stk.size() > 1)
        {
            Node* lptr = stk.top();
            stk.pop();
            Node* optr = stk.top();
            stk.pop();
            Node* rptr = stk.top();
            stk.pop();
            optr->left = lptr;
            optr->right = rptr;
            stk.push(optr);
        } 
        return stk.top();
    }
};

int main()
{
    //string s = "2-3/(5*2)+1";
    //string s = "3*4-2*5";
    //string s = "(1/2/3)";
    //string s = "3*(9-6*5)";
    string s = "(9*9-(9-7)*3)/(3*1)";
    Solution o;
    Node* ptr = o.expTree(s);
    return 0;
}