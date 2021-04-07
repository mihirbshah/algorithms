// 1740. Find Distance in a Binary Tree

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;


class Solution 
{
public:
    int findDistance(TreeNode* root, int p, int q) 
    {
        int res = 0;
        dfs(root, p, q, 0, res);
        return res;
    }
    
private:
    int dfs(TreeNode* root, int p, int q, int depth, int& res)
    {
        if (!root) return -1;
        
        int left = dfs(root->left, p, q, depth + 1, res);
        int right = dfs(root->right, p, q, depth + 1, res);
        
        if (root->val == p || root->val == q) 
        {
            if (!res && (left != -1 || right != -1)) res = max(left, right) - depth;
            return depth;
        }
        
        if (left != -1 && right != -1)
        {
            if (!res) res = left + right;
            return res;
        }
        
        if (left != -1 || right != -1) return max(left, right);
        
        return -1;
    }
};

/*
class Solution 
{
public:
    int findDistance(TreeNode* root, int p, int q) 
    {
        vector<int> pParents, qParents;
        populateAncestors(root, p, pParents);
        populateAncestors(root, q, qParents);
        const int m = pParents.size(), n = qParents.size();
        bool found = false;
        int i,j;
        for (i = 0; i < m; ++i)
        {
            for (j = 0; j < n; ++j)
            {
                if (pParents[i] == qParents[j])
                {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        
        return i + j;
    }
    
private:
    bool populateAncestors(TreeNode* node, int v, vector<int>& parents)
    {
        if (!node) return false;
        if (node->val == v) 
        {
            parents.push_back(node->val);
            return true;
        }
        bool l = populateAncestors(node->left, v, parents);
        if (l)
        {
            parents.push_back(node->val);
            return true;
        }
        bool r = populateAncestors(node->right, v, parents);
        if (r)
        {
            parents.push_back(node->val);
            return true;
        }
        return false;
    }
};
*/


int main()
{
    return 0;
}