/*
 * matrix_flip_score.cpp
 *
 *  Created on: Jul 4, 2018
 *      Author: mihir
 */

#include <iostream>
#include <vector>
#include <array>
#include "util.h"

using namespace std;

using row = vector<int>;
using matrix = vector<row>;

int MAX_row_size = 20;

row powers;

void populate_powers()
{
	int n = 1;
	for (int i = 0; i <= MAX_row_size; ++i)
	{
		powers.push_back(n);
		n = n << 1;
	}
}

// assumption: n is 0 or 1
int flip_number(int n)
{
	return n ? 0 : 1;
}

void flip_vector(row& cr)
{
	for (auto& e : cr)
		e = flip_number(e);
	//for_each(cr.begin(), cr.end(), flip_number);
}

void flip_row(matrix& m, short r)
{
	flip_vector(m[r]);
}

void flip_col(matrix& m, short c)
{
	for(auto& v : m) v[c] = flip_number(v[c]);
}

row where_zero(const row& cr)
{
	row res;
	for (int i = 0; i < cr.size(); ++i)
		if (!cr[i]) res.push_back(i);
	return res;
}

bool all_ones(const row& cr)
{
	for (const auto& e : cr)
		if (!e) return false;
	return true;
}

int row_cost(const row& cr)
{
	int i = 0, cost = 0;
	for (auto it = cr.rbegin(); it != cr.rend(); ++it)
		cost += (*it) * powers[i++];
	return cost;
}

int matrix_cost(const matrix& m)
{
	int cost = 0;
	for (auto v : m) cost += row_cost(v);
	return cost;
}

int max_row_score(row& cr)
{
	row temp = cr;
	flip_vector(temp);
	return max(row_cost(cr), row_cost(temp));
}

int matrix_score_first_cut(matrix& m)
{
	populate_powers();
	int row_size = m.size(), col_size = m[0].size();
	int curr_max_score = 0;

		curr_max_score = 0;
		if (!all_ones(m[0]))
		{
			flip_vector(m[0]);
			if (!all_ones(m[0]))
			{
				flip_vector(m[0]);
				row zero_loc = where_zero(m[0]);
				for (auto i : zero_loc)
					flip_col(m, i);
			}
		}

		for (int j = 1; j < row_size; ++j)
		{
			row temp = m[j];
			flip_vector(temp);
			if (row_cost(temp) > row_cost(m[j])) flip_vector(m[j]);
		}


		for (int c = 0; c < col_size; ++c)
		{
			int col_sum = 0;
			for (int r = 0; r < row_size; ++r)
			{
				col_sum += m[r][c];
			}
			curr_max_score += max(col_sum, row_size - col_sum) * powers[col_size - c - 1];
		}

	return curr_max_score;
}

int matrixScore_leetcode(matrix& A)
{
	int R = A.size(), C = A[0].size();
	int ans = 0;
	cout << "\n";
	for (int c = 0; c < C; ++c)
	{
		int col = 0;
		for (int r = 0; r < R; ++r)
		{
			col += A[r][c] ^ A[r][0];
			cout << "col: " << col << "\n";
		}
		ans += max(col, R - col) * (1 << (C-1-c));
		cout << "==== ans: " << max(col, R - col) * (1 << (C-1-c)) << "\n";
	}
	return ans;
}

row get_col(const matrix& m, short c)
{
	row col;
	for (int r = 0; r < m.size(); ++r)
		col.push_back(m[r][c]);
	return col;
}

int matrix_score(matrix& m)
{
	populate_powers();
	int row_size = m.size(), col_size = m[0].size(), score = 0;

	if (!all_ones(get_col(m, 0)))
	{
		flip_col(m, 0);
		if (!all_ones(get_col(m, 0)))
		{
			flip_col(m, 0);
			row zero_loc = where_zero(get_col(m, 0));
			for (auto i : zero_loc)
				flip_row(m, i);
		}
	}

	score = row_size * powers[col_size - 1];
	int col_sum = 0;
	for (int c = 1; c < col_size; ++c)
	{
		col_sum = 0;
		for (int r = 0; r < row_size; ++r)
			col_sum += m[r][c];
		score += max(col_sum, row_size - col_sum) * powers[col_size - 1 - c];
	}
	return score;
}

int main()
{
	//matrix m = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
	//matrix m = {{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 0, 1}};
	//matrix m = {{1, 0, 0, 1}};
	//matrix m = {{1, 1, 1, 1, 0}, {0, 1, 0, 1, 1}, {1, 0, 0, 1, 1}};
	matrix m = {{0, 1}, {1, 1}};

	cout << "matrix_score: " << matrix_score(m) << "\n";
	//cout << "matrix_score (their): " << matrixScore(m) << "\n";
}
