// 368. Largest Divisible Subset

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

class Solution 
{
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        
        int maxIndex = n - 1;
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (nums[j] % nums[i] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > dp[maxIndex]) maxIndex = i;
                }
            }
        }
        
        vector<int> res;
        while (maxIndex != -1)
        {
            res.push_back(nums[maxIndex]);
            maxIndex = parent[maxIndex];
        }
        
        return res;
    }
};

int main()
{
    vector<int> nums({1,2,4,8});
    Solution o;
    vector<int> res = o.largestDivisibleSubset(nums);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}