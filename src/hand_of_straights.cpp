/*
 * hand_of_straights.cpp
 *
 *  Created on: Jul 24, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/hand-of-straights/description/
 */


#include <iostream>
#include <vector>
#include <tuple>
#include "util.h"

using namespace std;

bool hand_of_straights(vector<int> hand, int w)
{
	// If hand size is not a multiple of w then we can't arrange the hand
	// in equal sets of size w. So return false
	if (hand.size() % w) return false;

	// sort the hand to ensure we pick numbers in consecutive order
	sort(hand.begin(), hand.end());

	// counters: array of counter where counters[i] keeps track of size of set 'i' in the hand
	// Each set has max 'w' elements so we will need (hand.size / w) number of counters.
	vector<int> counters(hand.size() / w, 0);

	// max_vals: array to keep track of current max value from the hand for each set
	vector<int> max_vals(hand.size() / w, 0);

	// curr_counter_index: current counter number that will be preferred first while assigning a hand element
	// active_counters: current active number of counters (different from max no. of counters)
	int curr_counter_index = 0, active_counters = 0;

	// for each element of the hand
	for (int i = 0; i < hand.size(); ++i)
	{
		// first element is always assigned to the first set. Increment active_counters to 1.
		if (i == 0)
		{
			counters[curr_counter_index] = 1;
			max_vals[curr_counter_index] = hand[i];
			++active_counters;
		}
		else // for all other elements
		{
			// If current set is full (i.e. counter[curr_counter_index[ == w) then
			// increment curr_counter_index to the next counter
			if (counters[curr_counter_index] == w) ++curr_counter_index;

			// Starting from the current counter, find the right set where this element can be assigned
			// based on whether -
			// a. Set has enough space left to accommodate this element
			// b. Current element is next consecutive number to the set's max element
			int j = curr_counter_index;
			for (; j < active_counters; ++j)
			{
				if (hand[i] == max_vals[j] + 1)
				{
					++counters[j];
					max_vals[j] = hand[i];
					break;
				}
			}

			// If we cannot find any set where this element can be assigned
			if (j == active_counters)
			{
				// If we haven't exhausted all the counters yet, then create a new set and
				// assign this element to that set.
				if (active_counters + 1 <= counters.size())
				{
					max_vals[active_counters] = hand[i];
					counters[active_counters++] = 1;
				}
				// If we have exhausted all the counters, then just bail out
				else return false;
			}
		}
	}

	// Once all elements are assigned, check that all counters size = w. If not then return false.
	for (auto cnt : counters)
		if (cnt != w) return false;

	return true;
}


int main()
{
	vector<pair<vector<int>, int>> inputs = {make_pair(vector<int>({1,2,3,6,2,3,4,7,8}), 3),
			                                 make_pair(vector<int>({1,2,3,4,5}), 4),
											 make_pair(vector<int>({4,2,3,1,6,5}), 6),
											 make_pair(vector<int>({4,2,3,1,6,5}), 1),
											 make_pair(vector<int>({1,1,2,2,3,3}), 3)
	};

	for (auto p : inputs)
	{
		cout << "hand_of_straights for hand [ " << stringify_container(p.first.begin(), p.first.end()) << "] and w = "
			 << p.second << " is: " << hand_of_straights(p.first, p.second) << "\n";
	}
}
