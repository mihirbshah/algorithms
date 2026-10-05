/*
 * k-similar_strings.cpp
 *
 *  Created on: Jul 20, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/k-similar-strings/description/
 *
 *  Credit: This solution has been copied and re-implemented from above link
 */

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * This function will find 'neighbors' of s. It will find the first location
 * 'i' where s[i] != b[i]. This is the location that needs to be swapped.
 * Now, it will find all the possible chars in s in the range [i+1, s.size())
 * that match b[i] i.e. the chars which can be swapped with s[i].
 * Each time it find a char, it will swap them to generate a 'neighbor' and then
 * re-swap them to get back to original string s for future swaps.
 * All the neighbors are returned as a vector<string>
 */
vector<string> neighbours(string s, const string& b)
{
	int i = 0;
	vector<string> neighbour;
	for (; i < s.size(); ++i)
		if (s[i] != b[i]) break;

	for (int j = i+1; j < s.size(); ++j)
	{
		if (s[j] == b[i])
		{
			swap(s[i], s[j]);
			neighbour.push_back(s);
			swap(s[j], s[i]);
		}
	}

	return neighbour;
}

/*
 * In order to find the minimum swaps needed to string a to convert it to
 * string b, we need to traverse string a from left to right and match it
 * char by char to the corresponding position in string b. If the position, does
 * not match, then we need a swap. Let's say this happens at index i.
 *
 * We would need to swap a[i] with character(s) in 'a' that match b[i]. Since there could
 * be >=1 number of such characters, at every stage (i), we can have several possibilities
 * of resultant strings obtained post swapping. We cannot discard any of these so we need to
 * consider each of them.
 *
 * We will maintain a queue structure to hold these different intermediate possibilities. Let's
 * call them neighbors. Each time, we pop a string from this queue, we find all its neighbors i.e.
 * strings that can be obtained by swapping exactly 1 char at position i. And then we insert all of
 * these neighbors in the queue.
 *
 * We maintain another structure in the form of a map of strings -> int to hold the "k-distance" of
 * intermediate neighbors such that map[s] = t indicates string s needed 't' no. of swaps on the
 * original string a to convert it to string s.
 *
 * In this manner, as we find neighbors, at some point, we will generate and hit the final string b.
 * The value of map[b] would be the final answer.
 */
int ksimilarity(string a, string b)
{
	unordered_map<string, int> kcnt;
	queue<string> q;
	q.push(a);
	// kcnt[a] is always 0 by definition since no swaps have been performed on 'a' yet.
	kcnt[a] = 0;

	string t;
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		if (b == t) return kcnt[t];
		for (const auto& s : neighbours(t, b))
		{
			if (kcnt.find(s) == kcnt.end() || kcnt[s] > kcnt[t] + 1)
				kcnt[s] = kcnt[t] + 1;
			q.push(s);
		}
	}

	return b.size();
}

/*
int main()
{
	vector<vector<string> > inputs = {{"ab", "ba"},
			                          {"abc", "bca"},
							          {"abac", "baca"},
	                                  {"aabc", "abca"},
	                                  {"abcde", "deabc"},
									  {"abcbca", "ababcc"},
									  {"bccaba", "abacbc"},
									  {"aabbccddee", "cbeddebaac"}
	};

	for (auto p : inputs)
		cout << "kdistance for a[" << p[0] << "] and b[" << p[1]  << "]: " << ksimilarity(p[0], p[1]) << "\n";
}
*/
