/*
 * rleIterator.cpp
 *
 *  Created on: Oct 5, 2018
 *      Author: mihir
 */

#include <iostream>
#include <vector>

using namespace std;

class RLEIterator {
public:
    RLEIterator(vector<int> A) : curr(0), v(A) {}

    int next(int n) {
    	if (curr > v.size() || (curr == v.size() - 2 && v[curr] < n))
    	{
    		v[curr] = 0;
    		return -1;
    	}

        if (v[curr] >= n)
        {
        	v[curr] -= n;
        	return v[curr + 1];
        }
        else
        {
        	curr += 2;
        	return next(n - v[curr - 2]);
        }
    }

private:
    long curr;
    vector<int> v;
};

/*
int main()
{
	vector<int> a = {635,606,576,391,370,981,36,21,961,185,124,210,801,937,22,426,101,260,221,647,350,180,504,39,101,989,199,358,732,839,919,169,673,967,58,676,846,342,250,597,442,174,472,410,569,509,311,357,838,251};
	vector<int> pos = {5039,62,3640,671,67,395,262,839,74,43,42,77,13,6,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	RLEIterator obj(a);
	cout << "vector length: " << a.size() << "\n";
	for (auto p : pos)
	{
		cout << "p: " << p << ", next(p): " << obj.next(p) << ", curr: " << obj.curr << ", v[curr]: " << obj.v[obj.curr] << "\n";
	}
}
*/
