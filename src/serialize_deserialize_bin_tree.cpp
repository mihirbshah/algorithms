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

/*
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
*/

class Codec
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        int h = getLevel(root);
        string res(pow(2, h) - 1, '');
        _serialize(root, res, 0, res.size() - 1);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        return _deserialize(data, 0, data.size() - 1);
    }

private:
    int getLevel(TreeNode* root)
    {
        if (!root) return 0;
        return 1 + max(getLevel(root->left), getLevel(root->right));
    }
    
    void _serialize(TreeNode* node, string& res, int l, int r)
    {
        int mid = l + r / 2;
        res[mid] = node ? node->val : 'X';
        _serialize(node->left, res, l, mid - 1);
        _serialize(node->right, res, mid + 1, r);
    }
    
    TreeNode* _deserialize(stirng& data, int l, int r)
    {
        int mid = l + r / 2;
        if (data[mid] == 'X') return nullptr;
        TreeNode* node = new TreeNode(data[mid] - '0');
        node->left = _deserialize(data, l, mid - 1);
        node->right = _deserialize(data, mid + 1, r);
        return node;
    }
};

int main()
{
    return 0;
}