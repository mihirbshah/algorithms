/*
 * reordered_power_of_2.cpp
 *
 *  Created on: Jul 15, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/reordered-power-of-2/description/
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <math.h>
#include "util.h"

using namespace std;

string bucket_sort(const string& s)
{
	array<int, 10> a = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (const char& c : s)
		++a[c - '0'];

	string r;
	for (int i = 0; i < 10; ++i)
		if (a[i]) r.append(string(a[i], '0' + i));

	return move(r);
}

/*
 * If the original number is N digits long, then the max number that can be
 * expressed with N digits is N 9's. This max number has at most B = 3N + ceil(N/3)
 * number of binary digits.
 *
 * Since a power of 2 has exactly one 1 bit and rest all 0 bits, we can have B powers of
 * 2 that can be expressed with a binary number of size B.
 *
 * So all we need to do now is find each such power of 2 and check if it's an anagram of the
 * original number. If yes, then we have an answer.
 */
bool reordered_power_of_2(long n)
{
	string numstr = bucket_sort(to_string(n));
	int numdigits = numstr.size();
	int max_binary_digits = (3 * numdigits) + ceil(numdigits / 3.0);
	long mask = 1;

	for (int i = 0; i < max_binary_digits; ++i)
		if (numstr == bucket_sort(to_string(mask << i))) return true;

	return false;
}

/*
int main()
{
	//for  (auto n : {1, 10, 16, 24, 46})
	  //cout << "reordered_power_of_2: [" << n << "]: " << reordered_power_of_2(n) << "\n";
	  cout << "reordered_power_of_2: [" << 9589924583 << "]: " << reordered_power_of_2(9589924583) << "\n";
}
*/
