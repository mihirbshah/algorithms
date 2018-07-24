/*
 * max_seating_distance.cpp
 *
 *  Created on: Jul 20, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/maximize-distance-to-closest-person/description/
 */

#include <iostream>
#include <vector>
#include <math.h>
#include "util.h"


using namespace std;

/*
 * We maintain 2 markets - begin and end.
 * For each group of 0's surrounded by 1's on either side, begin and end hold
 * the positions of the starting and ending 1.
 * At the start boundary, begin = -1 and end hold the position of ending 1.
 * At the end boundary, begin holds the position of starting 1 and end = -1
 *
 * At any point in time, no. of zeroes in a given range [begin,end] N = end - (begin + 1)
 * At the start/end boundaries, max_dist = N
 * Inside of the array (non-boundaries), max_dist = ceil(N / 2) since the mid point will be farthest
 * away from the 1's on the either side of the range.
 */
int max_dist_to_closest(const vector<int>& seats)
{
	int begin = -1, end = -1, max_dist = 0, curr_dist = 0;

	for (int i = 0; i < seats.size(); ++i)
	{
		if (seats[i])
		{
			end = i;
			curr_dist = end - (begin + 1);
			if (begin != -1) curr_dist = ceil(curr_dist / 2.0);
			if (curr_dist > max_dist) max_dist = curr_dist;
			// move 'begin' forward to the previous 'end' for the next iteration
			begin = end;
		}
	}

	if (begin < seats.size())
	{
		end = seats.size();
		curr_dist = end - (begin + 1);
		if (curr_dist > max_dist) max_dist = curr_dist;
	}

	return max_dist;
}

/*
int main()
{
	vector<vector<int>> inputs = {{1,0,0,0,1,0,1},
			                       {1,0,0,0},
								   {0,1},
								   {1,0}
	};

	for (auto v : inputs)
		cout << "max_dist to closest for [" << stringify_container(v.begin(), v.end()) << "]: " << max_dist_to_closest(v) << "\n";
}
*/
