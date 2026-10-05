// 1644. Lowest Common Ancestor of a Binary Tree II

#include <iostream>
#include <utility>

using namespace std;

class Solution 
{
public:
    using boolPair = pair<bool, bool>;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* res = nullptr;
        lca(root, p, q, res);
        return res;
    }
    
private:
    boolPair lca(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& res)
    {
        if (!node) return make_pair(false, false);
        boolPair self = make_pair(node->val == p->val, node->val == q->val);
        boolPair left = lca(node->left, p, q, res);
        boolPair right = lca(node->right, p, q, res);
        boolPair ret = make_pair(self.first || left.first || right.first, self.second || left.second || right.second);
        if (ret.first && ret.second && !res) res = node;
        return ret;
    }
};

int main()
{
    return 0;
}