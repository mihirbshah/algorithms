/*
https://leetcode.com/problems/stone-game-vii/
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int stoneGameVII(vector<int>& stones)
    {
        return dfs(stones, 0, stones.size() - 1, accumulate(stones.begin(), stones.end(), 0));
    }

private:
    int dfs(const vector<int>& stones, int i, int j, int sum)
    {
        if (i == j) return dp[i][j] = 0;
        
        if (dp[i][j] == INT_MIN)
        {
            int leftPick = sum - stones[i] - dfs(stones, i + 1, j, sum - stones[i + 1]);
            int rightPick = sum - stones[j] - dfs(stones, i, j - 1, sum - stones[j - 1]);
            dp[i][j] = max(leftPick, rightPick)
        }
        
        return dp[i][j];
    }

    vector<int> dp(1001, vector<int>(1001, INT_MIN));
};

int main()
{
    Solution s;
    vector<int> v = {5,3,1,4,2};
    int res = s.stoneGameVII(v);
    cout << "res: " << res << "\n";
    return 0;
}