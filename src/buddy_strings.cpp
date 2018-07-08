/*
 * buddy_strings.cpp
 *
 *  Created on: Jul 8, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/buddy-strings/description/
 *
 *  Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.

 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// if a string contains more than one occurance of any char, then return true else return false
bool two_or_more_of_same_char(const string& s)
{
	unordered_map<char, int> m;
	for (auto c : s)
	{
		if (m.find(c) != m.end()) return true;
		else m[c] = 1;
	}
	return false;
}

/*
 * This function will return true iff there are *exactly* 2 chars in string 'a' which can be swapped to get to string 'b'
 */
bool buddy_strings(string a, string b)
{
	// if strings are of different sizes or they are both empty, then nothing can be swapped so return false
	if ((a.size() != b.size()) || (a.empty() && b.empty())) return false;

	// if strings are the same, then if there are 2 char's which can be swapped to still get the same string, then return true
	// else return false. For e.g. "ab" == "ab" but nothing can be swapped in "ab" so we return false for this.
	// But "abab" == "abab" and we can swap the two a's or b's to still get "abab". Same with "aaaa" == "aaaa"
	if (a == b) return two_or_more_of_same_char(a);

	// after handling the special cases above, now apply the base algorithm -
	// 1. Find the first to points of differences in the 2 strings - diff1 and diff2
	// 2. Swap chars in positions diff1 and diff2 in string 'a' to see if we get string 'b'
	// 3. if we get b, then return true, else return false
	int diff1 = -1, diff2 = -1, i = 0;

	while (a[i] == b[i] && i < a.size()) ++i;
	if(i < a.size()) diff1 = i++;
	while (a[i] == b[i] && i < a.size()) ++i;
	if(i < a.size()) diff2 = i++;

	if (diff1 != -1 && diff2 != -1) swap(a[diff1], a[diff2]);

	return a == b;
}

int main()
{
	string a = "abab", b = "abab";
	cout << "buddy_strings: " << buddy_strings(a, b) << "\n";
}
