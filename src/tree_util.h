/*
 * tree_util.h
 *
 *  Created on: Jul 7, 2018
 *      Author: mihir
 */

#ifndef TREE_UTIL_H_
#define TREE_UTIL_H_

#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using TreeVals = vector<int>;

class TreeUtils
{
public:
	static int treenull;

	struct TreeNode
	{
		TreeNode* left;
		TreeNode* right;
		int val;
		TreeNode(int v) : left(NULL), right(NULL), val(v) {}
	};

	static TreeNode* make_tree(const TreeVals& vals);

	static void inorder(TreeNode* node)
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

	static void preorder(TreeNode* node)
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

	static void postorder(TreeNode* node)
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
};

#endif
