/*
 * regex.cpp
 *
 *  Created on: Jun 18, 2018
 *      Author: mihir
 *
 *  Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).

Note:

s could be empty and contains only lowercase letters a-z.
p could be empty and contains only lowercase letters a-z, and characters like . or *.
Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
 *
 */

// https://leetcode.com/problems/regular-expression-matching/description/
// solution as implemented in - https://www.youtube.com/watch?v=l3hda49XcDE



#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

using MatchMatrix = vector<vector<bool> >;

namespace
{
// empty char represents a null char we prepend to the beginning of the
// input text and patterns to make algorithm easier to implement
const char empty_char = ' ';

void disp_matrix(const MatchMatrix& m)
{
	cout << "\n === matrix ===\n";
	for (const auto& v : m)
	{
		for (const auto& e : v)
		{
			cout << e << "  ";
		}
		cout << "\n";
	}
}
}

bool validate_text(const string& s)
{
	// text only allows chars a-z
	for (int i = 0; i < s.length(); ++i)
		if (s[i] < 'a' || s[i] > 'z') return false;

	return true;
}

bool validate_regex(const string& p)
{
	// if len=1, p[0] != *
	if (p.length() == 1 && p[0] == '*') return false;

	// every * should be preceded by [a-z] or .
	for (int i = 0; i < p.length(); ++i)
		if ((p[i] == '*' && p[i-1] == '*') || p[i] < 'a' || p[i] > 'z') return false;

	return true;;
}

bool is_match(string s, string p)
{
	// if text or pattern validation fails, return false
	if (!validate_text(s) || !validate_regex(p)) return false;

	// prepend default null char to text and pattern to cater to simplfy code
	s = empty_char + s; p = empty_char + p;

	size_t s_len = s.length();
	size_t p_len = p.length();

	// matrix is a 2D matrix of bools, with each cell [i,j] representing when pattern[0:j]
	// matches text[0:i]
	// pattern runs horizontal (cols) and text runs vertical (rows)
	MatchMatrix matrix(s_len, vector<bool>(p_len, false));

	// [0,0] is always true - base case where text and pattern are both null
	matrix[0][0] = true;

	// first column is false because null pattern cannot match non-null text
	for (int i = 1; i < s_len; ++i) matrix[i][0] = false;

	for (int i = 0; i < s_len; ++i)
	{
		// start from 1 because we already pre-filled column 0
		for (int j = 1; j < p_len; ++j)
		{
			// p[j] is an english char
			if (p[j] >= 'a' && p[j] <= 'z')
				matrix[i][j] = (s[i] == p[j]) ? matrix[i-1][j-1] : false;
			// p[j] is .
			else if (p[j] == '.')
				// . matches anything except our default null char
				matrix[i][j] = s[i] == empty_char ? false : matrix[i-1][j-1];
			else if (p[j] == '*')
				// p[j] is * then we have 2 cases -
				// 1. zero occurrence of p[j-1] in text
				// 2. one or more occurrence of p[j-1] in text
				// The bitwise OR operation below represents the greedy pattern match for *
				// We try to match as much of the '*' as we can (case 1 or 2).
				matrix[i][j] =
						((p[j-1] == s[i] || p[j-1] == '.') && (s[i] != empty_char) ? matrix[i-1][j] : false) | matrix[i][j-2];
			else
				matrix[i][j] = false;
		}
	}

	//disp_matrix(matrix);
	return matrix[s_len - 1][p_len - 1];
}

/*int main()
{
	vector<pair<string, string> > inputs;
	inputs.push_back(make_pair("aa", "a"));
	inputs.push_back(make_pair("aa", "a."));
	inputs.push_back(make_pair("aa", "a*"));
	inputs.push_back(make_pair("aa", "aa"));
	inputs.push_back(make_pair("aa", "aaa"));
	inputs.push_back(make_pair("aa", "aab*"));
	inputs.push_back(make_pair("aa", "aa*"));
	inputs.push_back(make_pair("ab", ".*"));
	inputs.push_back(make_pair("aab", "c*a*b"));
	inputs.push_back(make_pair("mississippi", "mis*is*p*."));
	inputs.push_back(make_pair("aa", "*"));
	inputs.push_back(make_pair("aa", "a**"));
	inputs.push_back(make_pair("", ""));
	inputs.push_back(make_pair("", ".*"));
	inputs.push_back(make_pair("", "a*"));
	inputs.push_back(make_pair("", ".*a*b*"));
	inputs.push_back(make_pair("aaaaaaaaaaa", ".*b*"));
	inputs.push_back(make_pair("aaaaaaaaaaa", ".*a*"));
	inputs.push_back(make_pair("baac", ".*a*."));
	inputs.push_back(make_pair("baac", ".*a*"));



	for (const auto& p : inputs)
	{
		//cout << "processing " << p.first << ", " << p.second << "\n";
		cout << "text: " << p.first << ", pattern: " << p.second << ", match: " << (is_match(p.first, p.second) ? "True" : "False") << "\n";
	}
}*/

