// 1477. Find Two Non-overlapping Sub-arrays Each With Target Sum

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int minSumOfLengths(vector<int>& arr, int target) 
    {
        unordered_map<int, int> sums;
        int sum = 0;
        sums[0] = -1;
        for (int i = 0; i < arr.size(); ++i)
        {
            sum += arr[i];
            sums[sum] = i;
        }
        
        int res = INT_MAX;
        int len1 = INT_MAX;
        sum = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            int len2 = INT_MAX;
            sum += arr[i];
            if (sums.count(sum - target)) len1 = min(len1, i - sums[sum - target]);
            if (sums.count(sum + target) && len1 != INT_MAX) len2 = sums[sum + target] - i;
            if (len1 != INT_MAX && len2 != INT_MAX) res = min(res, len1 + len2);
        }
        
        return res == INT_MAX ? -1 : res;
    }
};

int main()
{
    vector<int> v({1,1,1,2,2,2,4,4}); int t = 6;
    Solution o;
    int res = o.minSumOfLengths(v, t);
    cout << "res: " << res << "\n";
    return 0;
}