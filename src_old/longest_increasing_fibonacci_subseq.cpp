/*
 * longest_increasing_fibonacci_subseq.cpp
 *
 *  Created on: Oct 3, 2018
 *      Author: mihir
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include "util.h"

using namespace std;

unordered_map<long, int> pos;
unordered_map<long, bool> included;

int _len_longest_fibonacci_subseq(long curr, long prev, int max_len)
{
	if (pos.end() != pos.find(curr - prev) && pos[curr - prev] < pos[prev])
	{
		included[curr - prev] = true;
		return _len_longest_fibonacci_subseq(prev, curr - prev, max_len + 1);
	}
	else
		return max_len;
}

int len_longest_fibonacci_subseq(vector<int>& v)
{
	int len = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		pos[v[i]] = i;
		included[v[i]] = false;
	}

	int curr_len = 0;
	for (int i = v.size() - 1; i >= 0; --i)
	{
		if (!included[v[i]])
		{
			for (int j = i - 1; j >= 0; --j)
			{
				curr_len = 1 + _len_longest_fibonacci_subseq(v[i], v[j], 1);
				len = curr_len > len ? curr_len : len;
			}
		}
	}

	return len < 3 ? 0 : len;
}

/*
int main()
{
	vector<vector<int>> mv = {
		{1, 2, 3, 4, 5, 6, 7, 8},
		{1, 3, 7, 11, 12, 14, 18},
		{1, 3, 5},
	};

	for (auto v : mv)
		cout << "vector [" << stringify_container(v.begin(), v.end())
			 << "], length of longest fibonacci subsequence: "
			 << len_longest_fibonacci_subseq(v) << "\n";
	return 0;
}
*/
