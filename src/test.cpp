/*
 * test.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: mihir
 */

#include <iostream>
#include "util.h"
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> v({1,2,3,4,5,6});
    auto it = remove_if(v.begin(), v.end(), [&](int e){ return e == 6; });
    cout << distance(it, v.end()) << "\n";
    //v.erase(remove_if(v.begin(), v.end(), [&](int e){ return e == 5; }));
    //v.erase(v.end());
    //print_container(v.begin(), v.end());
    return 0;
}


