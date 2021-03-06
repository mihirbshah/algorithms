// 343. Integer Break

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int integerBreak(int n) 
    {
        vector<int> dp(max(2, n + 1), INT_MIN);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i / 2; ++j)
            {
            //let's say i = 8, we are trying to fill dp[8]:if 8 can only be broken into 2 parts, the answer could be among 1 * 7, 2 * 6, 3 * 5, 4 * 4... but these numbers can be further broken. so we have to compare 1 with dp[1], 7 with dp[7], 2 with dp[2], 6 with dp[6]...etc
                dp[i] = max(dp[i], max(j, dp[j]) * max(i - j, dp[i - j]));
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution o;
    int res = o.integerBreak(8);
    cout << "res: " << res << "\n";
    return 0;
}