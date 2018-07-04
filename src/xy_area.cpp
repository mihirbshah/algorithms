/*
 * xy_area.cpp
 *
 *  Created on: Jun 19, 2018
 *      Author: mihir
 *
 *  https://leetcode.com/problems/container-with-most-water/description/
 *
 *  Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

    Note: You may not slant the container and n is at least 2.
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_area_bruteforce(const vector<int>& height)
{
	if (height.size() < 2) return 0;

	int area = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		for (int j = i+1; j < height.size(); ++j)
		{
			area = max(area, (j - i) * min(height[i], height[j]));
		}
	}

	return area;
}

/* Start with 2 pointers on the 2 ends of the array and get an initial value of area
 Now, as we move inwards, we are going to reduce the length (distance on x axis) of
 the rectangle. So if we want a larger area, our only bet is to keep increasing the
 height of the rectangle. Out of the 2 heights we have at every step, we will always
 try to increase the smaller one by moving its pointer. We repeat these steps until
 the 2 pointers cross i.e. we have exhausted all the points.
 */
int max_area(const vector<int>& height)
{
	// if zero or one point, then max area is 0
	if (height.size() < 2) return 0;

	// initialize area with -1 and not 0 because we could have 2 legitimate
	// points with 0 as their y coordinates and if the question is
	// modified to even give the points that constitute the max area, then
	// we need an initial default area <0.
	int area = -1;
	for (int i = 0, j = height.size() - 1; i < j;)
	{
		area = max(area, (j - i) * min(height[i], height[j]));
		if (height[i] < height[j]) ++i;
		else --j;
	}
	return area;
}

int main()
{
	vector<int> height = {6};
	cout << "max area (brute force): " << max_area_bruteforce(height) << "\n";
	cout << "max area (linear): " << max_area(height) << "\n";
}

