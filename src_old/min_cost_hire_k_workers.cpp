/*
 * min_cost_hire_k_workers.cpp
 *
 *  Created on: Oct 7, 2018
 *      Author: mihir
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "util.h"

using namespace std;

double min_cost_to_hire_workers(const vector<int>& quality, const vector<int>& wage, int k)
{
	using wq_pair = pair<int, int>;
	vector<wq_pair> wq;

	for (int i = 0; i < quality.size(); ++i)
		wq.push_back({wage[i], quality[i]});

	sort(wq.begin(), wq.end(),
			[](const wq_pair& a, const wq_pair& b) -> bool
			{
				return a.first < b.first;
			});

	int ref_wage = wq[0].first, ref_quality = wq[0].second;
	double total_cost = 0;

	for (int i = 0; i < wq.size(); ++i)
	{

	}

	return 0;
}

/*
int main()
{
	//using vp = pair<vector<int>, vector<int>>;
	//using kp = pair<vp, int>;
	//vector<kp> ip = {
	//		{{{3,1,10,10,1}, {4,8,2,2,7}}, 3}
	//};

	//for (auto i : ip)
	//{
	//	min_cost_to_hire_workers((ip.first).first, (ip.first).second, ip.second);
	//}
	min_cost_to_hire_workers({3,1,10,10,1}, {4,8,2,2,7}, 3);
}
*/
