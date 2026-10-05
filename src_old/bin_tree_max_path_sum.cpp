// 124. Binary Tree Maximum Path Sum

#include <iostream>
#include "tree_util.h"

using namespace std;

using TreeNode = TreeUtils::TreeNode;

class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        int maxSum = INT_MIN;
        const int treeSum = postOrder(root, maxSum);
        return max(maxSum, treeSum);
    }
    
private:
    int postOrder(TreeNode* node, int& maxSum)
    {
        if (!node) return 0;
        const int lsum = postOrder(node->left, maxSum);
        const int rsum = postOrder(node->right, maxSum);
        const int nval = node->val;
        const int maxChildSum = max(nval, max(nval + rsum, nval + lsum));
        maxSum = max(maxSum, max(nval + lsum + rsum, maxChildSum));
        return maxChildSum;
    }
};

int main()
{
    vector<int> v({2, -1, -2});
    TreeNode* root = TreeUtils::make_tree(v);
    Solution o;
    const int res = o.maxPathSum(root);
    cout << "res: " << res << "\n";
    return 0;
}