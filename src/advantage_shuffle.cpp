/*
 * advantage_shuffle.cpp
 *
 *  Created on: Jul 15, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/advantage-shuffle/description/
 */

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include "util.h"

using namespace std;

namespace
{
using List = vector<int>;
int null = numeric_limits<int>::lowest();

struct Result
{
	int val;
	int pos;
	int a_elem;
	Result(int v, int p) : val(v), pos(p), a_elem(null) {}
};

using ResultList = vector<Result>;
};

List _advantage_shuffle(List a, List b)
{
	ResultList br;
	for (int i = 0; i < b.size(); ++i)
		br.push_back(Result(b[i], i));

	sort(a.begin(), a.end());
	sort(br.begin(), br.end(),
		 [](const Result& left, const Result& right) -> bool
		 {
		 	 return left.val < right.val;
		 });

	cout << "after sorting br \n";
	for (const auto& e : br)
		cout << "val: " << e.val << ", pos: " << e.pos << ", a_elem: " << e.a_elem << "\n";

	int pos = 0;
	for (; a[pos] < br[pos].val; ++pos);

	int j = 0;
	for (int i = pos; i < a.size(); ++i)
	{
		if (a[i] > br[j].val)
		{
			br[j++].a_elem = a[i];
		}
	}

	for (int i = 0; i < pos; ++i)
		br[j++].a_elem = a[i];

	sort(br.begin(), br.end(),
		 [](const Result& left, const Result& right) -> bool
		 {
		 	 return left.pos < right.pos;
		 });

	cout << "after matching \n";
	for (const auto& e : br)
		cout << "val: " << e.val << ", pos: " << e.pos << ", a_elem: " << e.a_elem << "\n";

	List res;
	for (const auto& v : br)
		res.push_back(v.a_elem);

	return res;
}

/*
 * Since we want A[i] > B[i] for as many i's as possible, we will first
 * sort A and B in ascending order. Now we will find the first elem in A
 * which is greater than B[0]. This element "maps" to B[0]. From this point
 * onwards, we iterate through successive elements of A and B and if
 * A[i] > B[i], then map A[i] to B[i]. Note that because there could repetitions,
 * we could have multiple A[i]'s mapped to same B[i]. So we need to maintain a map
 * of B[i] -> list of A[i]'s. When A[i] is mapped to a certain B[i], we set visited[i]=true
 * indicating that, that A[i] is mapped.
 *
 * At the end of this step, all unmapped A[i]'s are not mapped sequentially to all unmapped B[i]'s.
 * And then we just need to iterate for each element in original B array and find its mapped A[i]
 * and create a result array with those values.
 */
List advantage_shuffle(List a, List b)
{
	List br = b;
	vector<bool> visited(a.size(), false);
	unordered_map<int, vector<int>> m;
	sort(a.begin(), a.end());
	sort(br.begin(), br.end());

	int pos = 0;
	for (; a[pos] <= br[0]; ++pos);

	int j = 0;
	for (int i = pos; i < a.size(); ++i)
	{
		if (a[i] > br[j])
		{
			if (m.find(br[j]) != m.end()) m[br[j++]].push_back(a[i]);
			else m[br[j++]] = {a[i]};
			visited[i] = true;
		}
	}

	for (int k = 0; k < visited.size(); ++k)
	{
		if (!visited[k])
		{
			if (m.find(br[j]) != m.end()) m[br[j++]].push_back(a[k]);
			else m[br[j++]] = {a[k]};
		}
	}

	List res;
	for (const auto& v : b)
	{
		res.push_back(m[v].back());
		m[v].pop_back();
	}

	return res;
}


int main()
{
	//List r = advantage_shuffle({12, 24, 8, 32}, {13, 25, 32, 11});
	//List r = advantage_shuffle({2, 7, 11, 15}, {1, 10, 4, 11});
	//List r = advantage_shuffle({2, 0, 4, 1, 2}, {1, 3, 0, 0, 2});
	List r = advantage_shuffle({5621,1743,5532,3549,9581}, {913,9787,4121,5039,1481});

	print_container(r.begin(), r.end());
}
