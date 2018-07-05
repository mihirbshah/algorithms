/*
 * lemonade_change.cpp
 *
 *  Created on: Jul 4, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/lemonade-change/description/
 *
 *  At a lemonade stand, each lemonade costs $5.

Customers are standing in a queue to buy from you, and order one at a time (in the order specified by bills).

Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill.  You must provide the correct change to each customer, so that the net transaction is that the customer pays $5.

Note that you don't have any change in hand at first.

Return true if and only if you can provide every customer with correct change.

 *
 *  0 <= bills.length <= 10000
    bills[i] will be either 5, 10, or 20.
 *
 */


#include <iostream>
#include <vector>
#include <array>

using namespace std;

bool lemonade_change(const vector<int>& bills)
{
	// We store the counts of $5, $10, $20 bills in an array of length 3
	// We could use a map too but it is an overkill here.
	array<short, 3> count = {0,0,0};
	for (auto e : bills)
	{
		// For a $5 bill, we just need to increment the count and move on
		if (e == 5) ++count[0];
		else if (e == 10)
		{
			// For $10 bill, we need at least $5 change.
			++count[1];
			if (count[0]) --count[0];
			else return false;
		}
		else if (e == 20)
		{
			// For $20 bill, we need either three $5's or a $10 and a $5 change.
			// We give preference to giving out $10 first because $5 is needed more
			// number of times than $10.
			++count[2];
			if (count[1] >= 1 && count[0])
			{
				--count[1]; --count[0];
			}
			else if (count[0] >= 3) count[0] -= 3;
			else return false;
		}
	}

	return true;
}

/*
int main()
{
	cout << "lemonade_change: " << lemonade_change({5,5,5,5,10,20,10}) << "\n";
}
*/

