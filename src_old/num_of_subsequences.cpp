// 1498. Number of Subsequences That Satisfy the Given Sum Condition

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution 
{
public:
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, res = 0;
        long MOD = 1e9 + 7;
        
        vector<int> powers(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            powers[i] = powers[i - 1] * 2 % MOD;
        }
        
        while (l <= r)
        {
            if (nums[l] + nums[r] <= target)
            {
                double exp = r - l;
                res = long(res + powers[exp]) % MOD;
                ++l;
            }
            else
            {
                --r;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}