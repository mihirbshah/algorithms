// 1770. Maximum Score from Performing Multiplication Operations

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;


class Solution 
{
public:
    int maximumScore(vector<int>& nums, vector<int>& mult) 
    {
        const int n = nums.size(), m = mult.size();
        
        //The key here is to realize that instead of 3D dp dp[i][left][right],
        //we can use 2D dp like dp[i][left] because,
        //for a given 'i', if we have selected 'left' no. of items from the left side,
        //then we would have to select (i - left) no. of items from the right side.
        //i.e. right = N - (i - left) where N is total size of nums. 
        //So, 'right' is always derived from 'left' and 'i', thus we don't need
        //to make it a dp dimension. 
        
        vector<vector<int>> dp(1000, vector<int>(1000, INT_MIN));
        return dfs(nums, mult, dp, 0, 0, n - 1);
    }
private:
    int dfs(vector<int>& nums, vector<int>& mult, vector<vector<int>>& dp, int i, int l, int r)
    {
        if (i >= mult.size() || l > r) return 0;
        if (dp[i][l] != INT_MIN) return dp[i][l];
        
        int r1 = mult[i] * nums[l] + dfs(nums, mult, dp, i + 1, l + 1, r);
        int r2 = mult[i] * nums[r] + dfs(nums, mult, dp, i + 1, l, r - 1);
        return dp[i][l] = max(r1, r2);
    }
};


/*
class Solution 
{
public:
    int maximumScore(vector<int>& nums, vector<int>& mult) 
    {
        const int n = nums.size(), m = mult.size();
        vector<int> left(m + 1, 0), right(m + 1, 0);
        for (int i = 0; i < m; ++i)
        {
            left[i + 1] = left[i] + nums[i] * mult[i];
            right[m - 1 - i] = right[m - i] + nums[n - 1 - i] * mult[i];
        }
        
        cout << "left: " << stringify_container(left.begin(), left.end()) << "\n";
        cout << "right: " << stringify_container(right.begin(), right.end()) << "\n";
        int maxScore = INT_MIN;
        for (int i = 1; i <= m; ++i)
        {
            maxScore = max(maxScore, left[i - 1] + right[i - 1]);
        }
        
        return maxScore;
    }
};
*/

int main()
{
    vector<int> nums({1,2,3}), mult({3,2,1});
    Solution o; 
    int res = o.maximumScore(nums, mult);
    cout << "res: " << res << "\n";
    return 0;
}