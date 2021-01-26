// 297. Serialize and Deserialize Binary Tree

#include <iostream>
#include <string>
#include <deque>
#include "tree_util.h"
#include <iterator>
#include <sstream>
#include <stdlib.h>

using namespace std;
using TreeNode = TreeUtils::TreeNode;

class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string res;
        _serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        istringstream iss(data);
        deque<string> q(istream_iterator<string>({iss}), istream_iterator<string>());
        return _deserialize(q);
    }
    
private:
    void _serialize(TreeNode* node, string& res)
    {
        if (!node)
        {
            res += "X ";
            return;
        }
        res += (to_string(node->val) + " ");
        _serialize(node->left, res);
        _serialize(node->right, res);
    }
    
    TreeNode* _deserialize(deque<string>& q)
    {
        if (!q.empty())
        {
            string s = q.front();
            q.pop_front();
            if (s == "X") return nullptr;
            TreeNode* node = new TreeNode(atoi(s.c_str()));
            node->left = _deserialize(q);
            node->right = _deserialize(q);
            return node;
        }
        return nullptr;
    }
};


int main()
{
    return 0;
}