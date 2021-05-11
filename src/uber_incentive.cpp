#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int incentive(vector<int> vals)
    {
        const int n = vals.size();
        // pair of -> total_sum, min
        vector<pair<int, int>> dp(n + 1);
        dp[0] = {0, INT_MAX};
        int maxval = INT_MIN;
        
        for (int i = 1; i <= n; ++i)
        {
            int currVal = vals[i - 1] * vals[i - 1];
            int prevVal = dp[i - 1].first * dp[i - 1].second;
            int cumVal = (dp[i - 1].first + vals[i - 1]) * min(dp[i - 1].second, vals[i - 1]);
            
            if (currVal > cumVal) dp[i] = {vals[i - 1], vals[i - 1]};
            else if (cumVal >= prevVal) dp[i] = {dp[i - 1].first + vals[i - 1], min(dp[i - 1].second, vals[i - 1])};
            else dp[i] = {vals[i - 1], vals[i - 1]};
            
            maxval = max(maxval, dp[i].first * dp[i].second);
        }
        
        return maxval;
    }
};

int main()
{
    Solution o;
    //vector<int> v = {3,1,6,4,5,2};
    vector<int> v = {3, 1, 6, 4, 5, 2, 4, 5};
    int res = o.incentive(v);
    cout << "res: " << res << "\n";
    return 0;
}