// 1696. Jump Game VI

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// O(n^2) solution
/*
class Solution 
{
public:
    int maxResult(vector<int>& nums, int k) 
    {
        vector<int> dp(nums.size(), INT_MIN);
        return dfs(nums, k, 0, dp);
    }
    
private:
    int dfs(vector<int>& nums, int k, int i, vector<int>& dp)
    {
        if (dp[i] != INT_MIN) return dp[i];
        const int n = nums.size();
        int tscore = INT_MIN;
        for (int j = i + 1; j <= min(n - 1, i + k); ++j)
        {
            tscore = max(tscore, nums[i] + dfs(nums, k, j, dp));
        }
        return dp[i] = (tscore == INT_MIN) ? nums[i] : tscore;
    }
};
*/


// For O(n) solution, refer - https://leetcode.com/problems/jump-game-vi/discuss/978462/C%2B%2B-DP-%2B-Monoqueue-O(n)

// Below solution is O(n log n)


class Solution 
{
public:
    int maxResult(vector<int>& nums, int k) 
    {
        const int n = nums.size();
        auto comp1 = [&](const pair<int, int>& p1, const pair<int, int>& p2) {return  p1.second < p2.second; };
        auto comp2 = [&](const pair<int, int>& p1, const pair<int, int>& p2) {return  p1.first < p2.first; };
        // pqi queue maintains the higest index at the top
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp1)> pqi(comp1);
        // pqe queue maintains the highest score at the top
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp2)> pqe(comp2);
        
        vector<int> dp(n, INT_MIN);
        
        for (int i = n - 1; i >= 0; --i)
        {
            dp[i] = nums[i] + (pqe.size() ? pqe.top().first : 0);
            pqi.push({dp[i], i});
            pqe.push({dp[i], i});
            if (pqi.size() > k)
            {
                auto p = pqi.top();
                pqi.pop();
                // When an element goes out of sliding window, we remove it from pqi
                // At the same time, we need to ensure we remove all elements with index
                // >= the removed index from pqe to ensure it correctly reflects the max
                // element in the current sliding window
                while (pqe.top().second >= p.second) pqe.pop();
            }
        }
        return dp[0];
    }
};

int main()
{
    vector<int> nums({1,-5,-20,4,-1,3,-6,-3}); int k = 2;
    Solution o;
    int res = o.maxResult(nums, k);
    cout << "res: " << res << "\n";
    return 0;
}