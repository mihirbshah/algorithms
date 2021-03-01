// 1262. Greatest Sum Divisible by Three

#include <iostream>
#include <vector>

using namespace std;

// solution from https://leetcode.com/problems/greatest-sum-divisible-by-three/discuss/559999/Come-here-if-you-can't-seem-to-get-it-(Full-Explanation-%2B-uncondensed-code)
class Solution 
{
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        const int s = nums.size();
        vector<vector<int>> dp(s + 1, vector<int>(3, INT_MIN));
        dp[0][0] = 0;
        for (int i = 1; i <= s; ++i)
        {
            const int n = nums[i - 1];
            if (n % 3 == 0)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + n);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][1] + n);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][2] + n);
            }
            else if (n % 3 == 1)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] + n);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + n);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + n);            
            }
            else if (n % 3 == 2)
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + n);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] + n);
                dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] + n);            
            }
        }
        return dp[s][0] == INT_MIN ? 0 : dp[s][0];
    }
};

int main()
{
    return 0;
}