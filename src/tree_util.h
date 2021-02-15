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

template <class T>
class TreeUtils
{
public:
    using TreeVals = vector<T>;

	static T treenull;

	struct TreeNode
	{
		TreeNode* left;
		TreeNode* right;
		T val;
		TreeNode(T v) : left(NULL), right(NULL), val(v) {}
	};

	static TreeNode* make_tree(const TreeVals& vals)
    {
        if (vals.empty()) return NULL;
        return _make_tree(vals, 0);
    }

	static void inorder(TreeNode* node)
	{
		if (!node || node->val == numeric_limits<T>::lowest())
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
		if (!node || node->val == numeric_limits<T>::lowest())
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
		if (!node || node->val == numeric_limits<T>::lowest())
		{
			cout << "NULL ";
			return;
		}
		postorder(node->left);
		postorder(node->right);
		cout << node->val << " ";
	}
    
    static bool isLeaf(TreeNode* node)
    {
        return !node->left && !node->right;
    }
    
    static TreeNode* _make_tree(const TreeVals& vals, size_t index)
    {
        if (vals.at(index) == numeric_limits<T>::lowest()) return NULL;
        TreeNode* node = new TreeNode(vals.at(index));
        size_t lindex = 2 * index + 1, rindex = 2 * index + 2;
        if (lindex < vals.size()) node->left = _make_tree(vals, lindex);
        if (rindex < vals.size()) node->right = _make_tree(vals, rindex);
        return node;
    }

};

template<class T>
T TreeUtils<T>::treenull = numeric_limits<T>::lowest();

#endif
