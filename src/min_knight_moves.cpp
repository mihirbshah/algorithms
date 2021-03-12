// 1197. Minimum Knight Moves

#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <string>

using namespace std;

class Solution 
{
public:
    int minKnightMoves(int x, int y) 
    {
        unordered_map<string, int> dp;
        return dfs(abs(x), abs(y), dp);
    }
    
private:
    int dfs(int x, int y, unordered_map<string, int>& dp)
    {
        if (x + y == 0) return 0;
        else if (x + y == 2) return 2;
        const string key = to_string(x) + ":" + to_string(y);
        if (dp.count(key)) return dp[key];
        int res = INT_MAX;
        for (auto o : offsets)
        {
            res = min(res, dfs(abs(x + o.first), abs(y + o.second), dp));
        }
        return dp[key] = 1 + res;
    }
    
    vector<pair<int, int>> offsets = {{-1, -2}, {-2, -1}};
};

int main()
{
    Solution o;
    int res = o.minKnightMoves(5, 5);
    cout << "res: " << res << "\n";
    return 0;
}