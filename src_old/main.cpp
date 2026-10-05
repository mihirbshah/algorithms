/*
 * main.cpp
 *
 *  Created on: Feb 12, 2019
 *      Author: mihir
 */

#include "util.h"
#include "wiggle_sort.h"


int main()
{
	vector<int> ip = {1, 3, 2, 2, 3, 1};
	wiggleSort(ip);
	print_container(ip.begin(), ip.end());
	return 0;
}

