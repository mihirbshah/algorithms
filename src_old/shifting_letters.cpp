/*
 * shifting_letters.cpp
 *
 *  Created on: Jul 23, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/shifting-letters/description/
 */


#include <iostream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;

/*
 * Since shifts[i] means shifting first i+1 chars by the value of shift[i],
 * if n = size(shifts), then
 * char 0 is shifted n times
 * char 1 is shifted n-1 times etc.
 *
 * Thus we calculate effective shifts for each char by finding a cumulative sum
 * of shifts array starting from the end.
 * Now, 'a' + 25 = 'z', but 'a' + 26 = 'a'. This means each effective shift should be
 * at most 25. To achieve this, we do (x % 26) for each x in effective shift.
 *
 * Now, we simply need to add this effective shift to each char positions in input string.
 * However, 'z' + 1 should still roll over to 'a'. To achieve this, we do -
 * a + (z - a) % 26
 * z - a represents the distance of 'z' from 'a'. And since we add this distanct back to 'a',
 * we want this distance to be max 25 such that 'a' + 25 = 'z'. So, we again perform
 * dist % 26 to bring it within the range of [0, 25]
 */
string shifting_letters(string s, vector<int> shifts)
{
	int len = shifts.size();
	vector<long> effective_shifts((len-- + 1), 0);
	for (auto i = shifts.rbegin(); i != shifts.rend(); ++i, --len)
		effective_shifts[len] = (effective_shifts[len + 1] + (*i)) % 26;
	for (int i = 0, j = 0; i < s.size(), j < effective_shifts.size() - 1; ++i, ++j)
		s[i] = 'a' + (((s[i] + effective_shifts[j]) - 'a') % 26);

	return s;
}

class Solution {
public:
string shiftingLetters(string s, vector<int> shifts)
{
    for (int i = shifts.size() - 2; i >= 0; --i)
    {
        shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
    }
    for (auto& n : shifts) n %= 26;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] + shifts[i] > 'z')
        {
            int d = 'z' - s[i];
            s[i] = 'a' + shifts[i] - d - 1;
        }
        else
        {
            s[i] += shifts[i];
        }
    }
    return s;
}
};

/*
int main()
{
	string s = "abc";
	vector<string> strings = {"abc", "ruu"};
	vector<vector<int>> shifts = {{3,5,9},
			                      {13},
								  {},
								  {23,24,25,26},
								  {26,9,17}
	};

	for (auto s : strings)
	  for (auto shift : shifts)
		  cout << "shifting_letters for[" << s << "] with shift[" << stringify_container(shift.begin(), shift.end()) << "] is "
		       << shifting_letters(s, shift) << "\n";
}
*/
