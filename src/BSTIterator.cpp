// 173. Binary Search Tree Iterator

#include <iostream>
#include <vector>
#include <stack>
#include "tree_util.h"

using TreeNode = TreeUtils::TreeNode;

using namespace std;

/*
//Running solution using O(n) space
class BSTIterator 
{
public:
    BSTIterator(TreeNode* root) : vi({-1})
    {
        inorder(root);
    }
    
    int next() 
    {
        return vi[++i];
    }
    
    bool hasNext() 
    {
        return i < vi.size() - 1;
    }
    
private:
    void inorder(TreeNode* node)
    {
        if (!node) return;
        inorder(node->left);
        vi.push_back(node->val);
        inorder(node->right);
    }
    
    vector<int> vi;
    int i = 0;
};
*/

// working solution using stack O(h) space
class BSTIterator 
{
public:
    BSTIterator(TreeNode* root)
    {
        pushLeft(root);
    }
    
    int next() 
    {
        TreeNode* ptr = si.top();
        si.pop();
        pushLeft(ptr->right);
        return ptr->val;
    }
    
    bool hasNext() 
    {
        return !si.empty();
    }
    
private:
    void pushLeft(TreeNode* node)
    {
        while (node)
        {
            si.push(node);
            node = node->left;
        }
    }
    
    stack<TreeNode*> si;
};


int main()
{
    return 0;
}