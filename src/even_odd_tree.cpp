#include <iostream>
#include <queue>
#include "tree_util.h"

/*
https://leetcode.com/problems/even-odd-tree/
*/

using namespace std;

namespace
{
    int null = numeric_limits<int>::lowest();
    bool isEven(int n) { return !(n % 2); }
    bool isOdd(int n) { return n % 2; }
    using TreeNode = TreeUtils::TreeNode;
}

class Solution {
public:
    bool isEvenOddTree(TreeNode* root)
    {
        using TreeQ = queue<TreeNode*>;
        TreeQ q;
        q.push(root);
        bool even = true;
        int prev = INT_MIN;
        
        while (!q.empty())
        {
            TreeQ tq;
            prev = even ? INT_MIN : INT_MAX;
            //cout << "evenodd: " << (even ? "even" : "odd") << ",  prev: " << prev << "\n";
            while (!q.empty())
            {
                auto e = q.front();
                q.pop();
                //cout << e->val << ", ";
                if (even && (isEven(e->val) || e->val <= prev)) return false;
                else if (!even && (isOdd(e->val) || e->val >= prev)) return false;
                prev = e->val;
                if (e->left) tq.push(e->left);
                if (e->right) tq.push(e->right);
            }
            //cout << "\n\n";
            even = !even;
            q.swap(tq);
        }
        
        return true;
    }
};

int main()
{
    //TreeVals vals = {1,10,4,3,null,7,9,12,8,null,null,6,null,null,2};
    //TreeVals vals = {5,4,2,3,3,7};
    //TreeVals vals = {5,9,1,3,5,7};
    //TreeVals vals = {1};
    TreeVals vals = {11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17};
    TreeNode* root = TreeUtils::make_tree(vals);
    //TreeUtils::inorder(root);
    //cout << "\n\n\n";
    Solution o;
    bool res = o.isEvenOddTree(root);
    cout << "res: " << (res ? "true" : "false") << "\n";
    return 0;
}