// 1583. Count Unhappy Friends

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    int unhappyFriends(int n, vector<vector<int>>& prefs, vector<vector<int>>& pairs)
    {
        unordered_map<int, int> pairmap;
        unordered_map<int, vector<int>> prefIndex;
        
        for (int j = 0; j < n; ++j)
        {
            vector<int> indices(n, -1);
            auto& pr = prefs[j];
            for (int i = 0; i < pr.size(); ++i) indices[pr[i]] = i;
            prefIndex[j] = indices;
        }
        
        for (const auto& p : pairs)
        {
            pairmap[p[0]] = p[1];
            pairmap[p[1]] = p[0];
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) res += isUnhappy(prefs, pairmap, prefIndex, i);
        return res;
    }
    
private:
    bool isUnhappy(vector<vector<int>>& prefs, unordered_map<int, int>& pairs, unordered_map<int, vector<int>>& prefIndex, int x)
    {
        for (const auto& f : prefs[x])
        {
            if (f == pairs[x]) return false;
            if (unhappy(prefs, pairs, prefIndex, f, x)) return true;
        }
        
        return false;
    }
    
    bool unhappy(vector<vector<int>>& prefs, unordered_map<int, int>& pairs, unordered_map<int, vector<int>>& prefIndex, int u, int x)
    {
        return prefIndex[u][x] < prefIndex[u][pairs[u]];
    }
};

int main()
{
    vector<vector<int>> prefs({{1, 2, 3}, {3, 2, 0}, {3, 1, 0}, {1, 2, 0}}); 
    vector<vector<int>> pairs({{0, 1}, {2, 3}});
    Solution o;
    int res = o.unhappyFriends(4, prefs, pairs);
    cout << "res: " << res << "\n";
    return 0;
}