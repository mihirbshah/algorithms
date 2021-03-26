// 1626. Best Team With No Conflicts

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Solution taken from https://leetcode.com/problems/best-team-with-no-conflicts/discuss/899475/Fairly-easy-DP
class Solution 
{
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        vector<pair<int, int>> players;
        const int n = scores.size();
        for (int i = 0; i < n; ++i) players.push_back(make_pair(ages[i], scores[i]));
        
        sort(players.begin(), players.end(), greater<pair<int, int>>());
        
        vector<int> dp(n, INT_MIN);
        int res = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            int score = players[i].second;
            dp[i] = score;
            for (int j = 0; j < i; ++j)
            {
                if (players[j].second >= score)
                    dp[i] = max(dp[i], dp[j] + score);
            }
            
            res = max(res, dp[i]);
        }
        
        return res;
    }
};

int main()
{
    return 0;
}