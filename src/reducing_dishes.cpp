#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/reducing-dishes

*/
int maxSatisfaction(vector<int>& s)
{
    int res = 0, currRes = 0;
    int currSum = 0;
    sort(s.begin(), s.end(), greater<>());
    for (const auto& e : s)
    {
        currRes += (e + currSum);
        if (currRes > res) res = currRes;
        currSum += e;
    }
    return res;
}

int main()
{
    vector<int> v1 = {-1,-8,0,5,-9};
    vector<int> v2 = {-2,5,-1,0,3,-3};
    int res = maxSatisfaction(v2);
    cout << "res: " << res << "\n";
    return 0;
}
