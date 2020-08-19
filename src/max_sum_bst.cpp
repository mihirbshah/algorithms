#include <iostream>
#include "tree_util.h"
#include <algorithm>
#include <utility>

namespace
{
    int null = numeric_limits<int>::lowest();
    using NodeState = pair<int, bool>;
}

NodeState _maxSumBST(TreeUtils::TreeNode* node)
{
    if (!node) return NodeState(0, true);
    if (!node->left && !node->right) return NodeState(max(node->val, 0),true);
    
    NodeState lsum = _maxSumBST(node->left);
    NodeState rsum = _maxSumBST(node->right);
    
    bool lcheck = lsum.second && (node->left ? node->left->val < node->val : true);
    bool rcheck = rsum.second && (node->right ? node->right->val > node->val : true);
    bool isBST = lcheck && rcheck;
    
    if (isBST) return NodeState(max({lsum.first, rsum.first, lsum.first + rsum.first + node->val}), true);
    else return NodeState(max(lsum.first, rsum.first), false);
}

int maxSumBST(TreeUtils::TreeNode* node)
{
    return _maxSumBST(node).first;
}

int main()
{
    TreeVals vals1 = {1,4,3,2,4,2,5,null,null,null,null,null,null,4,6};
    TreeVals vals2 = {4,3,null,1,2};
    TreeVals vals3 = {-4,-2,-5};
    TreeVals vals4 = {2,1,3};
    TreeVals vals5 = {5,4,8,3,null,6,3};
    TreeVals vals6 = {4,8,null,6,1,9,null,-5,4,null,null,null,-3,null,10};
    
    TreeUtils::TreeNode* root = TreeUtils::make_tree(vals6);
	//TreeUtils::preorder(root);
    int res = maxSumBST(root);
    cout << "result: " << res << "\n";
    return 0;
}