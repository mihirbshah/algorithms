// 98. Validate Binary Search Tree

#include <iostream>
#include <utility>
#include <stack>

using namespace std;

// Iterative
class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        stack<TreeNode*> stk;
        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        
        while (!stk.empty() || curr)
        {
            pushLeft(stk, curr);
            curr = stk.top();
            stk.pop();
            if (prev && curr->val <= prev->val) return false;
            prev = curr;
            curr = curr->right;
        }
        
        return true;
    }
    
private:
    void pushLeft(stack<TreeNode*>& stk, TreeNode* node)
    {
        while (node)
        {
            stk.push(node);
            node = node->left;
        }
    }
};

// Recursive
class Solution 
{
public:
    bool isValidBST(TreeNode* root) 
    {
        auto p = validBST(root);
        return p.first;
    }
    
private:
    pair<bool, pair<int, int>> validBST(TreeNode* node)
    {
        if (!node) return {true, make_pair(0, 0)};
        
        pair<bool, pair<int, int>> left{true, make_pair(0, 0)}, right{true, make_pair(0, 0)};
        
        if (node->left) left = validBST(node->left);
        if (!left.first) return {left.first, make_pair(max(node->val, left.second.first), min(node->val, left.second.second))};
        
        if (node->right) right = validBST(node->right);
        
        bool bst = left.first && 
                   right.first && 
                   (!node->left || node->val > left.second.first) && 
                   (!node->right || node->val < right.second.second);
        
        int maxval = node->val, minval = node->val;
        if (node->left) 
        {
            maxval = max(maxval, left.second.first);
            minval = min(minval, left.second.second);
        }
        if (node->right) 
        {
            maxval = max(maxval, right.second.first);
            minval = min(minval, right.second.second);
        }        
        
        return {bst, make_pair(maxval, minval)};
    }
};

int main()
{
    return 0;
}