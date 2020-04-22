/*
 * https://leetcode.com/problems/largest-values-from-labels/
 * We have a set of items: the i-th item has value values[i] and label labels[i].

	Then, we choose a subset S of these items, such that:

	|S| <= num_wanted
	For every label L, the number of items in S with label L is <= use_limit.
	Return the largest possible sum of the subset S.



	Example 1:

	Input: values = [5,4,3,2,1], labels = [1,1,2,2,3], num_wanted = 3, use_limit = 1
	Output: 9
	Explanation: The subset chosen is the first, third, and fifth item.
	Example 2:

	Input: values = [5,4,3,2,1], labels = [1,3,3,3,2], num_wanted = 3, use_limit = 2
	Output: 12
	Explanation: The subset chosen is the first, second, and third item.
	Example 3:

	Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 1
	Output: 16
	Explanation: The subset chosen is the first and fourth item.
	Example 4:

	Input: values = [9,8,8,7,6], labels = [0,0,0,1,1], num_wanted = 3, use_limit = 2
	Output: 24
	Explanation: The subset chosen is the first, second, and fourth item.


	Note:

	1 <= values.length == labels.length <= 20000
	0 <= values[i], labels[i] <= 20000
	1 <= num_wanted, use_limit <= values.length

	Solution:
	We need to follow a greedy approach by always selecting the biggest items in values
	and adding the to sum. This needs to be done until we have num_wanted number of items
	summed up. Also, we need to enforce an additional constraint that if the label of the item
	being added to sum has appeared use_limit number of times, then we should skip that item.

	To achieve this, we create a vector of (values, labels) pair and sort it by values in descending order.
	Time: O(n log n)
	Space: O(n)
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <unordered_map>

using namespace std;

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit)
{
	using value_label_pair = pair<int, int>;
	vector<value_label_pair> value_labels;
	for (int i = 0; i < values.size(); ++i)
	{
		value_labels.push_back(make_pair(values[i], labels[i]));
	}
	sort(value_labels.begin(), value_labels.end(), [](value_label_pair a, value_label_pair b) {return a.first > b.first;});

	using label_map = unordered_map<int, int>;
	label_map lmap;
	for (auto l : labels)
	{
		lmap[l] = 0;
	}

	long sum = 0;
	for (auto vl : value_labels)
	{
		if (lmap[vl.second] < use_limit)
		{
			sum += vl.first;
			++lmap[vl.second];
			if (!--num_wanted) break;
		}
	}

	return sum;
}
