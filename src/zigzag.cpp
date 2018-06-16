/*
 * zigzag.cpp
 *  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
 *
 *  Created on: Jun 16, 2018
 *      Author: mihir
 */


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// https://leetcode.com/problems/zigzag-conversion

using namespace std;

void populate_matrix(const string& s, int rows, vector<string>& matrix)
{
	// Start filling the matrix column wise, starting with the column 0
	// Each column can at most accommodate "rows" no. of characters

	auto it = s.begin();
	int col = 0;
	while (it != s.end())
	{
		// Fill the current column with rows no. of chars
		// Stop filling prematurely if you reach end of string (it != s.end())
		for (int i = 0; i < rows && it != s.end(); ++i)
		{
			matrix[i][col] = *it++;
		}
		// Move to the next column
		++col;

		// Fill one char per column in this loop
		// This is where we do the zigzag portion of the string
		// For "rows" no. of rows, we will have rows-2 such fills of one char each at max
		// subject to the input string still being available
		// So, barring locations 0 and rows-1 for a given column, we will one char per column
		// for each column
		for (int i = rows - 2; i > 0 && it != s.end(); --i)
			matrix[i][col++] = *it++;
	}
}

string display_matrix(const vector<string>& matrix)
{
	// Create the result string by excluding spaces from the matrix strings
	string res;
	for (auto s : matrix)
		res.append(s.begin(), remove(s.begin(), s.end(), ' '));
	return res;
}

string zigzag(const string& s, int rows)
{
	// if input rows < 1, we return a blank string
	if (rows < 1)
		return "";
	// create a result vector of "rows" no. of strings, each initialized to a string of len(s) spaces
	vector<string> matrix(rows, string(s.length(), ' '));
	populate_matrix(s, rows, matrix);
	return display_matrix(matrix);
}

int main()
{
	string s = "ABCDE"; int rows = 4;
	cout << "input: " << s << ", result: " << zigzag(s, rows) << "\n";
}
