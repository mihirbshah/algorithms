#include <iostream>
#include <math.h>

using namespace std;

class Solution
{
public:
    
    int racecar1(int target)
    {
        double logval = log2(target + 1);
        int logceil = ceil(logval);
        int logfloor = floor(logval);
        int upperDelta = (pow(2, logceil) - 1) - target;
        int lowerDelta = target - (pow(2, logfloor) - 1);
        return min(logceil + upperDelta * 2, logfloor + lowerDelta * 3);
    }
    
    int dp[10001];
    
    int racecar(int t) {
        if (dp[t] > 0) return dp[t];
        int n = floor(log2(t)) + 1, res;
        if (1 << n == t + 1) dp[t] = n;
        else {
            dp[t] = racecar((1 << n) - 1 - t) + n + 1;
            for (int m = 0; m < n - 1; ++m)
                dp[t] = min(dp[t], racecar(t - (1 << (n - 1)) + (1 << m)) + n + m + 1);
        }
        return dp[t];
    }

};

int main()
{
    Solution o;
    int res = o.racecar(9);
    cout << "res: " << res << "\n";
    return 0;
}