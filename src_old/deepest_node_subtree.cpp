/*
 * deepest_node_subtree.cpp
 *
 *  Created on: Jul 15, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
 */


#include <iostream>
#include "tree_util.h"

/*
 * ResultNode is used to track the deepest node for a given parent.
 * max_depth: the depth of the deepest node
 * node: deepest parent whos subtree includes the nodes with depth max_depth
 * cnt: number of deepest nodes with depth max_depth in the 'node's subtree
 */
struct ResultNode
{
	int max_depth;
	int cnt;
	TreeUtils::TreeNode* node;
	ResultNode(int d, int c, TreeUtils::TreeNode* n) : max_depth(d), cnt(c), node(n) {}
	// max_depth is initialized to -1 since we start numbering depth from 0 for root
	ResultNode() : max_depth(-1), cnt(0), node(NULL) {}
};

/*
 * We do a post order traversal where each child returns the deepest node ResultNode at its level.
 * If a node is a leaf node, then it has no further children so we just return its depth as the deepest depth
 * Otherwise, we collect the ResultNode values for left and right childs.
 * If their deepest node's depths are the same, then we return the sum of their ResultNodes back to current node's parent
 * Otherwise, we return the deeper one of the left and right childs.
 */
ResultNode _deepest_node_subtree(TreeUtils::TreeNode* node, int depth)
{
	if (!node->left && !node->right) return ResultNode(depth, 1, node);
	ResultNode left, right;
	if (node->left) left = _deepest_node_subtree(node->left, depth + 1);
	if (node->right) right = _deepest_node_subtree(node->right, depth + 1);
	// TODO return using shared_ptr and create objects on heap to avoid copying objects
	if (left.max_depth == right.max_depth) return ResultNode(left.max_depth, left.cnt + right.cnt, node);
	else if (left.max_depth > right.max_depth) return left;
	else return right;
}

/*
 * Collect the deepest nodes from the left and right subtree of the root and
 * return either their sum (if their are both equal) or the one which is deepest.
 */
TreeUtils::TreeNode* deepest_node_subtree(TreeUtils::TreeNode* node)
{
	// boundary check: If root is null
	if (!node) return NULL;
	ResultNode left, right;
	if (node->left) left = _deepest_node_subtree(node->left, 1);
	if (node->right) right = _deepest_node_subtree(node->right, 1);
	if (left.max_depth == right.max_depth) return node;
	else if (left.max_depth > right.max_depth) return left.node;
	else return right.node;
}

/*
int main()
{
	//TreeUtils::TreeNode* root = TreeUtils::make_tree({3,5,1,6,2,0,8,TreeUtils::treenull,TreeUtils::treenull,7,4});
	TreeUtils::TreeNode* root = TreeUtils::make_tree({});
	TreeUtils::TreeNode* result = deepest_node_subtree(root);
	if (result)
		cout << "deepest_node_subtree: " << result->val << "\n";
	else
		cout << "deepest_node_subtree: NULL \n";
}
*/
