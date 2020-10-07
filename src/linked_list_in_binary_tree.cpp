#include <iostream>
#include "tree_util.h"

using namespace std;

/*
https://leetcode.com/problems/linked-list-in-binary-tree/
*/

namespace
{
    int null = numeric_limits<int>::lowest();
    using TreeNode = TreeUtils::TreeNode;
}

class Solution 
{
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        return preOrder(root, head, head);
    }
private:
    bool preOrder(TreeNode* tnode, ListNode* lnode, ListNode* head)
    {
        if (!tnode->left && !tnode->right)
        {
            return (tnode->val == lnode->val && !lnode->next) || (tnode->val == head->val && !head->next);
        }
        
        ListNode* lnext = head;
        if (tnode->val == lnode->val) 
        {
            if (!lnode->next) return true;
            lnext = lnode->next;
        }
        else if (tnode->val == head->val)
        {
            if (!head->next) return true;
            lnext = head->next;
        }
        
        bool leftres = false, rightres = false;
        if (tnode->left) leftres = preOrder(tnode->left, lnext, head);
        if (tnode->right) rightres = preOrder(tnode->right, lnext, head);
        return leftres | rightres;
    }
};

int main()
{
    return 0;
}