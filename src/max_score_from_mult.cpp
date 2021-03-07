// 1770. Maximum Score from Performing Multiplication Operations

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int maximumScore(vector<int>& nums, vector<int>& mult) 
    {
        const int n = nums.size(), m = mult.size();
        vector<vector<int>> dp(1000, vector<int>(1000, INT_MIN));
        return dfs(nums, mult, dp, 0, 0, n - 1);
    }
private:
    int dfs(vector<int>& nums, vector<int>& mult, vector<vector<int>>& dp, int i, int j, int k)
    {
        if (i >= mult.size() || j > k) return 0;
        if (dp[i][j] != INT_MIN) return dp[i][j];
        
        int r1 = mult[i] * nums[j] + dfs(nums, mult, dp, i + 1, j + 1, k);
        int r2 = mult[i] * nums[k] + dfs(nums, mult, dp, i + 1, j, k - 1);
        return dp[i][j] = max(r1, r2);
    }
};

int main()
{
    vector<int> nums({-5,-3,-3,-2,7,1}), mult({-10,-5,3,4,6});
    Solution o; 
    int res = o.maximumScore(nums, mult);
    cout << "res: " << res << "\n";
    return 0;
}