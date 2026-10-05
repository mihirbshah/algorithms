// 1382. Balance a Binary Search Tree

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    TreeNode* balanceBST(TreeNode* root) 
    {
        inorder(root);
        return constructBST(0, sorted.size() - 1);
    }

private:
    TreeNode* constructBST(int start, int end)
    {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode *node = sorted[mid];
        node->left = constructBST(start, mid - 1);
        node->right = constructBST(mid + 1, end);
        return node;
    }
    void inorder(TreeNode* node)
    {
        if (!node) return;
        inorder(node->left);
        sorted.push_back(node);
        inorder(node->right);
    }
    
    vector<TreeNode*> sorted;
};

int main()
{
    return 0;
}