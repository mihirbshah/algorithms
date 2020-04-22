/*
 * wiggle_sort.h
 *
 *  Created on: Jul 11, 2019
 *      Author: mihir
 */

#include <vector>
#include <algorithm>

using namespace std;

#ifndef SRC_WIGGLE_SORT_H_
#define SRC_WIGGLE_SORT_H_

void wiggleSort(vector<int>& nums)
{
	vector<int> temp_nums(nums);
	sort(temp_nums.begin(), temp_nums.end());
	int mid = (temp_nums.size() + 1) / 2;
	int end = temp_nums.size();
	for (int i = 0; i < temp_nums.size(); ++i)
	{
		nums[i] = (i & 1) ? temp_nums[--end] : temp_nums[--mid];
	}
}



#endif /* SRC_WIGGLE_SORT_H_ */
