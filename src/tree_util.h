/*
 * tree_util.h
 *
 *  Created on: Jul 7, 2018
 *      Author: mihir
 */

#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using TreeVals = vector<int>;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(int v) : left(NULL), right(NULL), val(v) {}
};

namespace
{

TreeNode* _make_tree(const TreeVals& vals, size_t index)
{
	if (vals.at(index) == numeric_limits<int>::lowest()) return NULL;
	TreeNode* node = new TreeNode(vals.at(index));
	size_t lindex = 2 * index + 1, rindex = 2 * index + 2;
	if (lindex < vals.size()) node->left = _make_tree(vals, lindex);
	if (rindex < vals.size()) node->right = _make_tree(vals, rindex);
	return node;
}

};

TreeNode* make_tree(const TreeVals& vals)
{
	if (vals.empty()) return NULL;
	return _make_tree(vals, 0);
}


void inorder(TreeNode* node)
{
	if (!node || node->val == numeric_limits<int>::lowest())
	{
		cout << "NULL ";
		return;
	}
	inorder(node->left);
	cout << node->val << " ";
	inorder(node->right);
}

void preorder(TreeNode* node)
{
	if (!node || node->val == numeric_limits<int>::lowest())
	{
		cout << "NULL ";
		return;
	}
	cout << node->val << " ";
	preorder(node->left);
	preorder(node->right);
}

void postorder(TreeNode* node)
{
	if (!node || node->val == numeric_limits<int>::lowest())
	{
		cout << "NULL ";
		return;
	}
	postorder(node->left);
	postorder(node->right);
	cout << node->val << " ";
}

