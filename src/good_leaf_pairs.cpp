#include <iostream>
#include <vector>
#include "tree_util.h"
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
*/

namespace
{
    int null = numeric_limits<int>::lowest();
    using LeafList = vector<int>;
    using TreeNode = TreeUtils::TreeNode;
}

class Solution {
public:
    int countPairs(TreeNode* root, int distance) 
    {
        _dist = distance;
        postOrder(root);
        return _goodPairs;
        
    }
private:
    void updateGoodPairs(const LeafList& lv, const LeafList& rv)
    {
        for (auto le : lv)
        {
            for (auto re : rv)
            {
                if (_dist >= le + re) 
                {
                    ++_goodPairs;
                    //cout << "== goodPairs: " << _goodPairs << " ==\n";
                }
            }
        }
    }
    
    void incrementAndJoin(LeafList& lv, const LeafList& rv)
    {
        lv.insert(lv.end(), std::make_move_iterator(rv.begin()), std::make_move_iterator(rv.end()));
        transform(lv.begin(), lv.end(), lv.begin(), [](int e){ return e+1; });
    }
    
    LeafList postOrder(TreeNode* elem)
    {
        if (TreeUtils::isLeaf(elem))
        {
            //cout << "elem: " << elem->val << "\n";
            return LeafList({1});
        }
        LeafList lv, rv;
        if (elem->left) lv = postOrder(elem->left);
        if (elem->right) rv = postOrder(elem->right);
        //cout << "elem: " << elem->val << ", lv: " << stringify_container(lv.begin(), lv.end()) << ", rv: " << stringify_container(rv.begin(), rv.end()) << "\n";
        updateGoodPairs(lv, rv);
        incrementAndJoin(lv, rv);
        //cout << "return list: " << stringify_container(lv.begin(), lv.end()) << "\n";
        return lv;
    }
    
    int _dist = 0;
    int _goodPairs = 0;
};

int main()
{
    //TreeVals vals = {1,2,3,null,4}; int dist = 3;
    //TreeVals vals = {1,2,3,4,5,6,7}; int dist = 3;
    //TreeVals vals = {100}; int dist = 1;
    TreeVals vals = {7,1,4,6,null,5,3,null,null,null,null,null,null,null,2}; int dist = 3;
    
    TreeNode* root = TreeUtils::make_tree(vals);
    Solution o;
    int res = o.countPairs(root, dist);
    cout << "res: " << res << "\n";
    return 0;
}
