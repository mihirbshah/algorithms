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



int main()
{
    return 0;
}