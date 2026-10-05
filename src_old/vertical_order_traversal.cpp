// 314. Binary Tree Vertical Order Traversal

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> verticalOrder(TreeNode* root) 
    {
        map<int, vector<vector<int>>> m;
        int pos = 0;
        dfs(root, 0, m, 0, pos);
        vector<vector<int>> res;
        
        for (auto& [k, v] : m) 
        {
            sort(v.begin(), v.end());
            vector<int> vv;
            for (auto& p : v)
                vv.push_back(p[2]);
            res.push_back(vv);
        }
        
        return res;
    }
    
private:
    /* 
    For every element, we keep track of 3 things -
    level - level of the node in the tree, this lets us sort the nodes vertically in the same column. 
    pos - sort of a counter, that increments with every node. This let's us sort nodes horizontally at the same level
    value - value of the node
    
    level is stored before pos because we want to first sort by level in each column, and for the nodes
    at the same level same column, we then want to sort by pos. 
    
    Note that because we call left tree first, the pos of nodes in the left will always be < those in the right sub trees.
    This ensures proper sort order. 
    */
    void dfs(TreeNode* node, int col, map<int, vector<vector<int>>>& m, int level, int& pos)
    {
        if (!node) return;
        m[col].push_back({level, pos, node->val});
        dfs(node->left, col - 1, m, level + 1, ++pos);
        dfs(node->right, col + 1, m, level + 1, ++pos);
    }
};

int main()
{
    return 0;
}