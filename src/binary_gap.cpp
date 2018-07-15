/*
 * binary_gap.cpp
 *
 *  Created on: Jul 15, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/binary-gap/description/
 */

#include <iostream>

using namespace std;

/*
 * in order to extract a single binary digit, we follow this basic routine -
 * r = n & 1
 * n = n >> 1
 * Now, we need to track the positions of '1' and update current count and max count accordingly.
 * For this, we maintain a bool found_one indicating if a '1' has been encountered yet or not.
 * This will help us decide whether or not we should increment current count when we encounter a '0'.
 * Another thing we always do is to reset current count = 1 each time we encounter '1' and then decide if
 * max count needs to be updated or not.
 */
int binary_gap(int n)
{
	int mask = 1;
	int r = 0;
	int maxcnt = 0, cnt = 0;
	bool found_one = false;

	while (n)
	{
		r = n & mask;
		if (r)
		{
			if (cnt > maxcnt) maxcnt = cnt;
			cnt = 1;
			found_one = true;
		}
		else if (found_one) ++cnt;
		n >>= 1;
	}

	return maxcnt;
}

int main()
{
	for (auto i : {22, 5, 6, 8, 343})
		cout << "bin_gap[" << i << "]: " << binary_gap(i) << "\n";
}
