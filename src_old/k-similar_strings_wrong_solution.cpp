/*
 * k-similar_strings.cpp
 *
 *  Created on: Jul 19, 2018
 *      Author: mihir
 */



#include <iostream>
#include <unordered_map>
#include <vector>
#include "util.h"

using namespace std;

using Positions = vector<int>;
using PositionMap = unordered_map<char, Positions>;

void populate_pmap(const string& s, PositionMap& pmap)
{
	for (int i = 0; i < s.size(); ++i)
	{
		if (pmap.find(s[i]) != pmap.end()) pmap[s[i]].push_back(i);
		else pmap[s[i]] = {i};
	}
}

void disp_pmap(PositionMap& pmap)
{
	for (const auto& k : pmap)
		cout << k.first << ": " << stringify_container(k.second.begin(), k.second.end()) << "\n";
}

void invalidate_pos(char c, int pos, PositionMap& pmap)
{
	//cout << "Invalidating pos: " << pos << " for char: " << c << "\n";
	Positions& indices = pmap[c];
	/*for (int i = 0; i < pmap[c].size(); ++i)
	{
		if (pmap[c][i] == pos) pmap[c][i] = -1;
	}*/

	//cout << "Retrieved current indices: " << stringify_container(indices.begin(), indices.end()) << "\n";
	for (auto& p : indices)
	{
		if (p == pos) p = -1;
	}
}

void update_pos(char c, int oldpos, int newpos, PositionMap& pmap)
{
	//cout << "Updating oldpos: " << oldpos << " for char: " << c << " to newpos: " << newpos << "\n";
	Positions& indices = pmap[c];
	/*for (int i = 0; i < pmap[c].size(); ++i)
	{
		if (pmap[c][i] == oldpos) pmap[c][i] = newpos;
	}*/

	for (auto& p : indices)
	{
		if (p == oldpos) p = newpos;
	}
}

void swap_char(string& a, int source, int dest, int& kdistance)
{
	swap(a[source], a[dest]);
	++kdistance;
}

int valid_pos_size(const Positions& pos, int& first_valid_index)
{
	int cnt = 0;
	for (auto p : pos)
	{
		if (p != -1)
		{
			++cnt;
			if (first_valid_index == -1) first_valid_index = p;
			//if (p > first_valid_index) first_valid_index = p;
		}
	}
	return cnt;
}

int ksimilarity_not_working(string a, string b)
{
	PositionMap pmap;
	populate_pmap(a, pmap);

	int kdistance = 0;

	cout << "\n";
	for (int i = 0; i < a.size(); ++i)
	{
		cout << "i: " << i << ", a: " << a << ", b: " << b << ", kdistance: " << kdistance << "\n";
		if (a[i] == b[i]) continue;
		const char& desired_char = b[i];
		Positions pos = pmap[desired_char];
		if (pos.size() == 1 && pos[0] != -1)
		{
			disp_pmap(pmap);
			invalidate_pos(a[pos[0]], pos[0], pmap);
			update_pos(a[i], i, pos[0], pmap);
			swap_char(a, i, pos[0], kdistance);
		}
		else
		{
			disp_pmap(pmap);
			for (auto& p : pos) if (p != -1 && a[p] == b[p]) p = -1;
			int first_valid_index = -1;
			if (valid_pos_size(pos, first_valid_index) == 1)
			{
				invalidate_pos(a[first_valid_index], first_valid_index, pmap);
				if (a[i] == b[first_valid_index]) invalidate_pos(a[i], i, pmap);
				else update_pos(a[i], i, first_valid_index, pmap);

				swap_char(a, i, first_valid_index, kdistance);
				continue;
			}

			for (auto& p : pos)
			{
				if (p != -1 && a[i] == b[p])
				{
					first_valid_index = p;
					break;
				}
			}

			invalidate_pos(a[first_valid_index], first_valid_index, pmap);
			if (a[i] == b[first_valid_index]) invalidate_pos(a[i], i, pmap);
			else update_pos(a[i], i, first_valid_index, pmap);
			swap_char(a, i, first_valid_index, kdistance);
		}
	}
	cout << "a: " << a << ", b: " << b << ", kdistance: " << kdistance << "\n";
	cout << "\n";

	return kdistance;
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
	//string a = "ab", b = "ba";
	//string a = "abc", b = "bca";
	//string a = "abac", b = "baca";
	//string a = "aabc", b = "abca";
	//string a = "abcde", b = "deabc";
	string a = "aabbccddee", b = "cbeddebaac";
	cout << "kdistance for a[" << a << "] and b[" << b  << "]: " << ksimilarity_not_working(a, b) << "\n";

	for (auto p : inputs)
	{
		cout << "kdistance for a[" << p[0] << "] and b[" << p[1]  << "]: " << ksimilarity_not_working(p[0], p[1]) << "\n";
	}
}*/
