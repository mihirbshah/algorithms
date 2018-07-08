/*
 * sub_array_sum.cpp
 *
 *  Created on: Jul 8, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/
 */


// TODO Comment this code and both the approaches below

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

struct SumNode
{
	long sum;
	//int sindex, eindex, size;
	int size;
	SumNode(long sum_, int size_) : sum(sum_), size(size_) {}
	//SumNode(long sum_, int sindex_, int eindex_) : sum(sum_), sindex(sindex_), eindex(eindex_), size(eindex_ - sindex_ + 1) {}
};

using SumList = vector<long>;
using NumList = vector<int>;
using SumListList = vector<SumList>;

int min_subarray_using_prefixes(const NumList& nums, int k)
{
	SumList prefixes = {0};
	for (int i = 0; i < nums.size(); ++i)
	{
		prefixes.push_back(nums[i] + prefixes[i]);
	}

	int prefix_len = prefixes.size();

	for (int i = nums.size(); i >= 1; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			int pair_len = prefix_len - i;
			if (prefixes[j + pair_len] - prefixes[j] >= k) return pair_len;
		}
	}

	return -1;
}

int min_subarray(const NumList& nums, int k)
{
	SumListList sums;

    sums.push_back({});
    sums.push_back({});

	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[i] >= k) return 1;
		sums[0].emplace_back(nums[i]);
	}

	for (int i = 0; i < sums[0].size() - 1; ++i)
	{
		if (sums[0][i] + sums[0][i+1] >= k) return 2;
		sums[1].emplace_back(sums[0][i] + sums[0][i+1]);
	}

	int sum_meta_index = 1, subr_meta_index = 0, curr_meta_index = 2;
	int curr_size = 3;

	while (curr_meta_index < nums.size())
	{
        sums.push_back({});

		for (int i = 0; i < sums[sum_meta_index].size() - 1; ++i)
		{
			long temp_sum = sums[sum_meta_index][i] + sums[sum_meta_index][i+1] - sums[subr_meta_index][i+1];
			if (temp_sum >= k) return curr_size;
			sums[curr_meta_index].emplace_back(temp_sum);
		}
		++sum_meta_index;
		++subr_meta_index;
		++curr_meta_index;
		++curr_size;

		for (int j = 0; j < subr_meta_index; ++j)
		{
			sums[j].clear();
		}
	}

	return -1;
}

/*
int main()
{
	NumList nums = {1, 3, 10, -3, -11, 7, 16, -2};
	//NumList nums = {};
	int k = 17;
	//cout << "nums.size: " << nums.size() << "\n";
	cout << "size of minimum subarray with sum at least [" << k << "]: " << min_subarray_using_prefixes(nums, k) << "\n";
}
*/
