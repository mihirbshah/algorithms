/*
 * tree_distance.cpp
 *
 *  Created on: Jul 7, 2018
 *      Author: mihir
 *
 *  We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 *  https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 */


#include <iostream>
#include "tree_util.h"
#include "util.h"

namespace
{
int null = numeric_limits<int>::lowest();
int default_distanct = -1;
};


/*
 * node: Current node under consideration
 * target: target node w.r.t which we need to find distances of other nodes
 * k: target distance
 * distance: distance of current node from the target node. (More details below)
 * result: vector where we accumulate results
 *
 * We work by passing around a "distance" which indicates the distance of current node from
 * the target node. By default, this distance is set to -1 until we encounter the target node.
 * Once we find the target node, we start passing around the distance to its immediate neighbors
 * i.e. its children (by recursive calls) and its parent (by returning a value).
 * After this, each successive recursive call or a return would increment the value of this distance
 * variable until we hit the target distance. When we hit the target distance at a particular node, we
 * add that node to the result set.
 */
int _kdistance(TreeNode* node, TreeNode* target, int distance, int k, vector<int>& result)
{
	// safety check
	if (!node) return default_distanct;

	// if we have hit the target node
	if (node->val == target->val)
	{
		// if target distance (k) = 0, then answer is this node itself
		if (!k)
		{
			result.push_back(node->val);
			return default_distanct;
		}

		// make recursive calls to its left/right children with initial distance=1
		if (node->left) _kdistance(node->left, target, 1, k, result);
		if (node->right) _kdistance(node->right, target, 1, k, result);
		// return initial distance=1 to its parent which will then start tracking the distance from
		// this target node
		return 1;
	}
	else // if we have hit a non-target node
	{
		// if the current distance of this node from the target node is k, then add it to the
		// result set and return immediately (since none of its children are ever going to be in
		// the final result set)
		if (distance == k)
		{
			result.push_back(node->val);
			return default_distanct;
		}

		// if distance=-1 i.e. we haven't hit the target node yet
		if (distance == default_distanct)
		{
			int ret = -1;
			// make a recursive call on left child with distance=-1
			if (node->left) ret = _kdistance(node->left, target, default_distanct, k, result);

			// if left child notifies that the current distance of this node is same as k, then add the node
			// to the result set and return (no need to call on right child since if the parent is in the result,
			// its un-traversed children are not going to be in the final result set)
			if (ret == k)
			{
				result.push_back(node->val);
				return default_distanct;
			}

			// if left child yields -1 (i.e. target node not found yet), make recursive call to right child
			if (ret == default_distanct)
			{
				if (node->right) ret = _kdistance(node->right, target, default_distanct, k, result);

				// if right child notifies that the current distance of this node is same as k, then add the node
				// to the result set and return (no need to call on left child since if the parent is in the result,
				// its un-traversed children are not going to be in the final result set)
				if (ret == k)
				{
					result.push_back(node->val);
					return default_distanct;
				}

				// if right child yields -1 i.e. no target node found yet, then just return back with -1
				if (ret == default_distanct) return default_distanct;
				else
				{
					// if right child returns a distance != -1 or k (i.e. for e.g. we get k-1 from right child),
					// then it means that there is a possibility that one of the children in the left subtree of
					// this current node could be in the final result set. This is why we look **again** on the left
					// subtree of this node.
					// Note that we had already looked through the left subtree earlier and this is the second time we
					// are doing that. However, this duplication of efforts is needed because by default, we always look
					// left first followed by right. However, if the target lies in the right subtree of a node, then there
					// could be some nodes in its left subtree which could actually be at a distance of k from the target node.
					if (node->left) _kdistance(node->left, target, ret + 1, k, result);
					return ret + 1;
				}
			}
			else
			{
				// If left child returns a distance != -1 and k, then there is a possibility
				// that one of the children in the right subtree could be in the final result set.
				// So, we look to the right child here.
				// Note: the return value of the right child does not matter here since we are anyway
				// going to return ret + 1 back
				if (node->right) _kdistance(node->right, target, ret + 1, k, result);
				// The return value (ret + 1) does the job of incrementing the distance of parent(current node)
				// from the final target node. Since "ret" indicates the distance of current node, its parent
				// would be at a distanct of ret + 1
				return ret + 1;
			}
		}
		else
		{
			// If the input distance is != -1 and k, then it means that the target node has been encountered.
			// In this case, we simply traverse the left and right subtrees for any potential results, and then
			// finally just return back -1.
			// Note: this return value does not matter because when it finally percolates back up to the "target" node,
			// that node will take care of returning the right thing back to its parent.
			if (node->left) _kdistance(node->left, target, distance+1, k, result);
			if (node->right) _kdistance(node->right, target, distance+1, k, result);
			return default_distanct;
		}
	}
}

vector<int> kdistance(TreeNode* root, TreeNode* target, int k)
{
	vector<int> result;
	_kdistance(root, target, -1, k, result);
	return result;
}

int main()
{
	//TreeVals vals = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, null, null, null, null, 12, 13, 14, null};
	//TreeVals vals = {};
	TreeVals vals = {0,2,1,null,null,3};
	TreeNode* root = make_tree(vals);
	//preorder(root);
	TreeNode* target = new TreeNode(3);
	int k = 3;
	vector<int> result = kdistance(root, target, k);
	cout << "kdistance: " << stringify_container(result.begin(), result.end());
}

