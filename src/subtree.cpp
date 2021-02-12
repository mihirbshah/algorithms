// 572. Subtree of Another Tree

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        vector<TreeNode*> matchingRootNodes;
        populateMatchingRootNodes(matchingRootNodes, s, t->val);
        for (auto node : matchingRootNodes)
        {
            if (matchTree(node, t)) return true;
        }
        return false;
    }
    
private:
    void populateMatchingRootNodes(vector<TreeNode*>& v, TreeNode* node, int matchVal)
    {
        if (!node) return;
        if (node->val == matchVal) v.push_back(node);
        populateMatchingRootNodes(v, node->left, matchVal);
        populateMatchingRootNodes(v, node->right, matchVal);
    }
    
    bool matchTree(TreeNode* s, TreeNode* t)
    {
        if (!s && !t) return true;
        if ((!s && t) || (s && !t)) return false;
        if (s->val != t-> val) return false;
        return matchTree(s->left, t->left) && matchTree(s->right, t->right);
    }
};

int main()
{
    return 0;
}