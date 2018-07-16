/*
 * tree_util.cpp
 *
 *  Created on: Jul 15, 2018
 *      Author: mihir
 */


#include "tree_util.h"

namespace
{

TreeUtils::TreeNode* _make_tree(const TreeVals& vals, size_t index)
{
	if (vals.at(index) == numeric_limits<int>::lowest()) return NULL;
	TreeUtils::TreeNode* node = new TreeUtils::TreeNode(vals.at(index));
	size_t lindex = 2 * index + 1, rindex = 2 * index + 2;
	if (lindex < vals.size()) node->left = _make_tree(vals, lindex);
	if (rindex < vals.size()) node->right = _make_tree(vals, rindex);
	return node;
}

};


TreeUtils::TreeNode* TreeUtils::make_tree(const TreeVals& vals)
{
	if (vals.empty()) return NULL;
	return _make_tree(vals, 0);
}

int TreeUtils::treenull = numeric_limits<int>::lowest();
