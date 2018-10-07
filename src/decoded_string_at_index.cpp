/*
 * decoded_string_at_index.cpp
 *
 *  Created on: Oct 6, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/decoded-string-at-index/description/
 *
 *  An encoded string S is given.  To find and write the decoded string to a tape, the encoded string is read one character at a time and the following steps are taken:

If the character read is a letter, that letter is written onto the tape.
If the character read is a digit (say d), the entire current tape is repeatedly written d-1 more times in total.
Now for some encoded string S, and an index K, find and return the K-th letter (1 indexed) in the decoded string.



Example 1:

Input: S = "leet2code3", K = 10
Output: "o"
Explanation:
The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".
Example 2:

Input: S = "ha22", K = 5
Output: "h"
Explanation:
The decoded string is "hahahaha".  The 5th letter is "h".
Example 3:

Input: S = "a2345678999999999999999", K = 1
Output: "a"
Explanation:
The decoded string is "a" repeated 8301530446056247680 times.  The 1st letter is "a".


Note:

2 <= S.length <= 100
S will only contain lowercase letters and digits 2 through 9.
S starts with a letter.
1 <= K <= 10^9
The decoded string is guaranteed to have less than 2^63 letters.
 *
 */


#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
#include <utility>

using namespace std;

/*
 * Algorithm:
 * We do not need to maintain the actual generate string resulted from the computations of un-rolling (run length encoded) RLE input string.
 * Doing that would need enormous amount of memory. Instead, what we need to observe is, we can encounter the kth char
 * in one of the 2 different ways -
 * 1. As a 'first class' char directly from the input RLE string
 * e.g. Input: 'abc22', if k=3, we directly return 'c' as the answer
 * 2. As a 'generated' char derived by applying RLE un-rolling computation on the current list of char's
 * e.g. Input: 'abc12', if k=8, then the un-rolled string would look like 'abcabcabcabc' and 8th char would be 'b'.
 * In this case, since the size of last repetition is 6 chars long (abcabc), and we need 8th char, we can instead
 * find 8 % 6 = 2nd char in the un-repeated original string (abcabc). Now, applying the same logic again, the length of
 * the next repetition was 3 (abc), we can ignore the repeated block, and instead look for 2 % 3 = 2nd char in the
 * un-repeated original string (abc). This decomposes into case (1.) above and we get our answer as 'b'.
 *
 */
string decoded_at_index(string s, long k)
{
	// prev is used to hold old value of curr when applying computations
	// curr tells us how many chars have we seen until now
	long prev = 0, curr = 0;

	// last_seen_char maintains the latest 'first class' char from the input RLE string that we have seen
	char last_seen_char = s[0];

	// For each char in the string, check if it is an alphabet or a number.
	for (auto c : s)
	{
		// If alphabet - check if we have seen kth char and if so, return that.
		if (isalpha(c))
		{
			++curr;
			last_seen_char = c;
			if (curr == k) return string(1, last_seen_char);
		}
		else // if number
		{
			// store old value of curr
			prev = curr;
			// re-calculate curr as curr * n if n is the next digit
			curr *=  (c - 48);
			// if we have reached kth char, then return the last_seen_char as that would be the kth char after 'n' repetitions in the prev line.
			if (curr == k) return string(1, last_seen_char);
			// else if we have seen more chars than k
			else if (curr > k)
			{
				// after ignoring the repetitions (size of prev), calculate how many chars are left to be seen from k
				curr = k % prev;
				// handle edge case: if no chars are left to be seen, that means the last char of the repetition is the desired kth char.
				// last_seen_char will hold that char
				if (curr == 0) return string(1, last_seen_char);
				// otherwise, recursively call this func with the leftover chars from k as the new k
				return decoded_at_index(s, curr);
			}
		}
	}
	return "";
}

/*
int main()
{
	vector<pair<string, int>> sv = {{"leet2code3", 10},
									{"ha22", 5},
									{"a2345678999999999999999", 80000},
									{"ajx37nyx97niysdrzice4petvcvmcgqn282zicpbx6okybw93vhk782unctdbgmcjmbqn25rorktmu5ig2qn2y4xagtru2nehmsp", 976159153},
									};

	for (auto p : sv)
		cout << "s: " << p.first << ", k: " << p.second << ", result: " << decoded_at_index(p.first, p.second) << "\n";

	return 0;
}
*/
