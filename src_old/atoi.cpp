/*
 * atoi.cpp
 *
 * Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.
 *
 *  Created on: Jun 16, 2018
 *      Author: mihir
 *
 */

//https://leetcode.com/problems/string-to-integer-atoi/description/

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <limits>
#include <vector>

using namespace std;

int32_t my_atoi(string str)
{
	// strip leading spaces so that we have a sign or a digit (if its a valid number) at pos 0
	str.erase(0, str.find_first_not_of(" "));
	// neg/pos represent whether there is a leading -/+ sign in the input
	// It is imp to check for len>1 here to account for inputs like "-" or "+"
	bool neg = str.length() > 1 && '-' == str[0];
	bool pos = str.length() > 1 && '+' == str[0];
	// Anything which is not of the form "[-+]?[0-9]*" is not a valid int
	bool valid = (isdigit(str[0])) ||
			     (neg && isdigit(str[1])) ||
				 (pos && isdigit(str[1]));

	// return 0 for invalid numbers
	if (!valid) return 0;

	// Find the position of the first digit in the input
	auto begin_num_it = str.begin(), end_num_it = str.end();
	for (auto it = str.begin(); it != str.end(); ++it)
	{
		if (isdigit(*it))
		{
			begin_num_it = it;
			break;
		}
	}

	// Find the position of the last digit in the input
	for (auto it = begin_num_it; it != str.end(); ++it)
	{
		if (!isdigit(*it))
		{
			end_num_it = it;
			break;
		}
	}

	// Create a "working" string composed of the digits in the range found above
	string num(begin_num_it, end_num_it);
	// This is a v imp step. It is needed to graciously handle extremely long numbers
	// Removing leading zeros gives us a real estimate of length of the "working" string
	// which we use below to determine if input length is longer than length of max number
	// represented by int32
	num.erase(0, num.find_first_not_of("+-0"));
	long long res = 0;
	short power_range = 0;
	bool limit_exceeded = false;
	int32_t limit = numeric_limits<int32_t>::max();
	// Find max digits in decimal representation of the max int32 number
	int max_digits = static_cast<int>(log10(limit) + 1);
	if (num.length() > max_digits) limit_exceeded = true;
	else
	{
		for (auto it = num.rbegin(); it != num.rend(); ++it)
		{
			// This is plain arithmetic to convert a char to digit and build a number
			res += pow(10, power_range++) * (*it - 48);
			if (res > limit)
			{
				limit_exceeded = true;
				break;
			}
		}
	}

	// Return min/max if the input was greater than max int32 number based on the sign
	if (limit_exceeded) return neg ? numeric_limits<int32_t>::min() : numeric_limits<int32_t>::max();
	// Else return the result normalized with the sign
	return res = (neg ? -1 : 1) * res;
}


/*int main()
{
	vector<string> v = {"9128347233212",
						"-91283472332",
						"123",
						"-123",
						"",
						"  145",
						"  a-191",
						"- 123",
						" -a321",
						"-1a23",
						"0",
						"-0",
						"199    abc",
						"-231  nvf",
						"000",
						"-00",
						"-0123",
						"0123",
						"+1",
						"+-2",
						"    +0a32",
						"    000000000000123456789"
						};

	//string s = "    +0a32";
	for (auto s : v)
		cout << "input: " << s << ", result: " << my_atoi(s) << "\n";
}*/
