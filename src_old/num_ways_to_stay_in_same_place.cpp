// 1269. Number of Ways to Stay in the Same Place After Some Steps

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int numWays(int steps, int arrLen) 
    {
        memo.resize(steps/2 + 1, vector<int>(steps + 1, -1));
        return dfs(0, arrLen, steps);
    }

private:
    int dfs(int arrIndex, int arrLen, int stepsLeft)
    {
        if (!arrIndex && !stepsLeft) return 1;
        if (arrIndex < 0 || arrIndex >= arrLen || !stepsLeft || arrIndex > stepsLeft) return 0;
        if (memo[arrIndex][stepsLeft] != -1) return memo[arrIndex][stepsLeft];
        int ret = dfs(arrIndex - 1, arrLen, stepsLeft - 1) % mod;
        ret = (ret + dfs(arrIndex + 1, arrLen, stepsLeft - 1) % mod) % mod;
        ret = (ret + dfs(arrIndex, arrLen, stepsLeft - 1) % mod) % mod;
        return memo[arrIndex][stepsLeft] = ret;
    }
    
    const int mod = 1e9 + 7;
    vector<vector<int>> memo;
};

int main()
{
    int steps = 4, arrLen = 2;
    Solution o;
    int res = o.numWays(steps, arrLen);
    cout << "res: " << res << "\n";
    return 0;
}