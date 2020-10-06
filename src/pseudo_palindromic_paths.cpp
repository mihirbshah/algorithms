#include <iostream>
#include <string>
#include <utility>
#include "tree_util.h"
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
*/

namespace
{
    int null = numeric_limits<int>::lowest();
    using TreeNode = TreeUtils::TreeNode;
}

class Solution 
{
public:
    int pseudoPalindromicPaths(TreeNode* root) 
    {
        inorder(root, "");
        return pseudoPalindrome;
    }
    
private:
    pair<bool, bool> evenOdd(const vector<int>& v)
    {
        int oddcnt = 0;
        for (const auto& e : v) oddcnt += (e % 2);
        return make_pair(oddcnt == 0, oddcnt == 1);
    }
    
    bool isPseudoPalindrome(const string& s)
    {
        const int slen = s.size();
        vector<int> v(9, 0);
        for (const auto& c : s) ++v[c - '1'];
        pair<bool, bool> evenodd = evenOdd(v);
        return slen % 2 ? evenodd.second : evenodd.first;
    }
    
    void inorder(TreeNode* node, string nodesSoFar)
    {
        nodesSoFar += to_string(node->val);
        if (TreeUtils::isLeaf(node))
        {
            pseudoPalindrome += isPseudoPalindrome(nodesSoFar);
            return;
        }
        
        if (node->left) inorder(node->left, nodesSoFar);
        if (node->right) inorder(node->right, nodesSoFar);
    }
    
    int pseudoPalindrome = 0;
};

int main()
{
    TreeVals vals = {2,3,1,3,1,null,1};
    TreeNode* root = TreeUtils::make_tree(vals);
    Solution o;
    int res = o.pseudoPalindromicPaths(root);
    cout << "res: " << res << "\n";
    return 0;
}