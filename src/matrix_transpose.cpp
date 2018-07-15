/*
 * matrix_transpose.cpp
 *
 *  Created on: Jul 15, 2018
 *      Author: mihir
 */

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;
using Row = vector<int>;
using Matrix = vector<Row>;

string stringify_matrix(const Matrix& m)
{
	string s;
	for (const auto& v : m)
	{
		s += stringify_container(v.begin(), v.end());
		s += "\n";
	}
	return s;
}

Matrix transpose(Matrix& m)
{
	Matrix tm;
	for (int i = 0; i < m[0].size(); ++i)
	{
		Row r;
		for (const auto& v : m)
			r.push_back(v[i]);
		tm.push_back(r);
	}

	return move(tm);
}

/*
int main()
{
	//Matrix m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	//Matrix m = {{1, 2, 3}, {4, 5, 6}};
	//Matrix m = {{1, 2, 3}};
	Matrix m = {{1}, {2}, {3}};
	//Matrix m = {};

	cout << "transpose: \n" << stringify_matrix(transpose(m)) << "\n";
}
*/
