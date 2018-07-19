/*
 * backspace_string_compare.cpp
 *
 *  Created on: Jul 18, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/backspace-string-compare/description/
 */

#include <iostream>
#include <string>

using namespace std;

namespace
{
const char& null_char = ' ';
};

/*
 * This function will take in a string with backspaces in it
 * and return a result string with the backspaces applied.
 * Each application of backspace will convert the char into a
 * null_char.
 */
void apply_backspace(string& s)
{
	// bs_pos indicates current position from where it should
	// apply the next found backspace. This is maintained for
	// efficiency reason to avoid having to compare previously
	// backspaced chars repeatedly.
	int bs_pos = -1;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '#')
		{
			for (int j = bs_pos; j >= 0; --j)
			{
				if (s[j] >= 'a' && s[j] <= 'z')
				{
					s[j] = null_char;
					bs_pos = j;
					break;
				}
			}
		}
		else
			bs_pos = i;
	}
}

/*
 * this function takes in 2 strings after applying their backspaces
 * and compares if the resultant strings are equal or not.
 * Basic idea is, for each string, skip over all backspaces and null_char's
 * and only compare alphabets. And if the strings are of different lengths, then
 * make sure the addition suffix is all backspaces or null_char's. If we have a
 * valid alphbet in the leftover suffix, then that means the 2 strings dont match.
 */
bool compare(const string& s, const string& t)
{
	int i = 0, j = 0;
	while (i < s.size() && j < t.size())
	{
		while (s[i] == '#' || s[i] == null_char) ++i;
		while (t[j] == '#' || t[j] == null_char) ++j;
		if (s[i] != t[j]) return false;
		++i; ++j;
	}

	if (i >= s.size() && j < t.size())
	{
		while (t[j] == '#' || t[j] == null_char) ++j;
		if (j != t.size()) return false;
	}

	if (j >= t.size() && i < s.size())
	{
		while (s[i] == '#' || s[i] == null_char) ++i;
		if (i != s.size()) return false;
	}

	return true;
}

bool backspace_compare(string s, string t)
{
	apply_backspace(s);
	apply_backspace(t);
	return compare(s, t);
}

int main()
{
	cout << "backspace_compare: " << backspace_compare("a##b", "#a#c") << "\n";;
}
