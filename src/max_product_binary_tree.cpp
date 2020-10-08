#include <iostream>
#include <vector>
#include <math.h>

#include "tree_util.h"
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

This code works for all except 1 testcase on leetcode where it fails due to time limit exceeded.
*/

namespace
{
    using TreeNode = TreeUtils::TreeNode;
    int null = numeric_limits<int>::lowest();
}

class Solution 
{
public:
    int maxProduct(TreeNode* root)
    {
        postOrder(root, 0);
        constexpr int MOD = 1e9 + 7;
        return maxProd % MOD;
    }
    
private:
    long postOrder(TreeNode* node, long parentSum) 
    {
        if (!node->left && !node->right) return node->val;
        long lsum = 0, rsum = 0;
        if (node->left) lsum = postOrder(node->left, parentSum + node->val);
        if (node->right) rsum = postOrder(node->right, parentSum + node->val + lsum);
        if (node->left) lsum = postOrder(node->left, parentSum + node->val + rsum);
        maxProd = max(maxProd, max((long)lsum * (rsum + node->val + parentSum), (long)rsum * (lsum + node->val + parentSum)));
        return lsum + rsum + node->val;
    }

    long maxProd = 0; 
};

int main()
{
    TreeVals vals = {1,null,2,null,null,3,4,null,null,null,null,null,null,5,6};
    Solution o;
    TreeNode* root = TreeUtils::make_tree(vals);
    int res = o.maxProduct(root);
    cout << "res: " << res << "\n";
    return 0;
}