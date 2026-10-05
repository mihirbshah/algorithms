// 199. Binary Tree Right Side View

#include <iostream>
#include "tree_util.h"
#include <string>
#include <vector>
#include <queue>

using namespace std;
using TreeNode = TreeUtils::TreeNode;

class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        queue<TreeNode*> q;
        qpush(q, root);
        TreeNode* curr = nullptr;
        vector<int> res({});
        while (!q.empty())
        {
            queue<TreeNode*> subq;
            while (!q.empty())
            {
                curr = q.front();
                q.pop();
                qpush(subq, curr->left);
                qpush(subq, curr->right);
            }
            q.swap(subq);
            if (curr) res.push_back(curr->val);
        }
        return res;
    }
    
private:
    void qpush(queue<TreeNode*>& q, TreeNode* node)
    {
        if (node) q.push(node);
    }
};


/*
Using preorder, copied from - https://leetcode.com/problems/binary-tree-right-side-view/discuss/56003/My-C%2B%2B-solution-modified-preorder-traversal

class Solution {
public:
    void recursion(TreeNode *root, int level, vector<int> &res)
    {
        if(root==NULL) return ;
        if(res.size()<level) res.push_back(root->val);
        recursion(root->right, level+1, res);
        recursion(root->left, level+1, res);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }
};

*/

int main()
{
    return 0;
}