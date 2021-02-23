// 1331. Rank Transform of an Array

#include <iostream>
#include <vector>
#include <unordered_map>
#include "util.h"

using namespace std;

class Solution 
{
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        if (!arr.size()) return {};
        vector<int> res(arr);
        sort(arr.begin(), arr.end());
        unordered_map<int, int> m;
        int cnt = 1;
        m[arr[0]] = cnt;
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i] != arr[i - 1]) m[arr[i]] = ++cnt;
        }
        for (int i = 0; i < res.size(); ++i) res[i] = m[res[i]];
        return res;
    }
};

int main()
{
    vector<int> arr({37,12,28,9,100,56,80,5,12});
    Solution o;
    vector<int> res = o.arrayRankTransform(arr);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}