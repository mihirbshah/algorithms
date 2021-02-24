// 1305. All Elements in Two Binary Search Trees

#include <iostream>
#include <vector>

using namespace std;

// For 1 pass traversal solution, refer https://leetcode.com/problems/all-elements-in-two-binary-search-trees/discuss/464073/C%2B%2B-One-Pass-Traversal

class Solution 
{
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> l1, l2;
        inorder(root1, l1);
        inorder(root2, l2);
        return merge(l1, l2);
    }
    
private:
    void inorder(TreeNode* node, vector<int>& v)
    {
        if (!node) return;
        inorder(node->left, v);
        v.push_back(node->val);
        inorder(node->right, v);
    }
    
    vector<int> merge(const vector<int>& l1, const vector<int>& l2)
    {
        int i = 0, j = 0;
        const int m = l1.size(), n = l2.size();
        vector<int> res;
        for (; i < m && j < n;)
        {
            if (l1[i] < l2[j])
            {
                res.push_back(l1[i++]);
            }
            else
            {
                res.push_back(l2[j++]);
            }
        }
        
        if (i < m && j >= n)
        {
            for (int k = i; k < m; ++k) res.push_back(l1[k]);
        }
        else if (i >= m && j < n)
        {
            for (int k = j; k < n; ++k) res.push_back(l2[k]);
        }
        
        return res;
    }
};

int main()
{
    return 0;
}