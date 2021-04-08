// 1029. Two City Scheduling

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        unordered_set<int> a, b;
        const int n = costs.size();
        for (int i = 0; i < n; ++i)
        {
            if (costs[i][0] < costs[i][1]) 
            {
                cout << "ai: " << i << "\n";
                a.insert(i);
            }
            else 
            {
                cout << "bi: " << i << "\n";
                b.insert(i);
            }
        }
        
        const int an = a.size(), bn = b.size();
        int diff = an - bn;
        if (diff)
        {
            auto& vmax = diff > 0 ? a : b;
            auto& vmin = diff > 0 ? b : a;
            auto comp = [](const pair<int, int>& p1, const pair<int, int>& p2){ return p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first); };
            set<pair<int, int>, decltype(comp)> s(comp);
            for (auto i : vmax) 
            {
                s.insert({i, abs(costs[i][0] - costs[i][1])});
            }
            diff = abs(diff);
            
            for (auto ss: s) cout << "i: " << ss.first << ", diff: " << ss.second << "\n";
            while (diff > 0)
            {
                cout << "diff: " << diff << ", first: " << s.begin()->first << "\n";
                vmin.insert(s.begin()->first);
                vmax.erase(s.begin()->first);
                s.erase(s.begin());
                diff = (vmax.size() - vmin.size());
            }
        }
        
        int res = 0;
        for (auto i : a) res += costs[i][0];
        for (auto i : b) res += costs[i][1];
        return res;
    }
};

int main()
{
    vector<vector<int>> costs({{259,770},{448,54},{926,667},{184,139},{840,118},{577,469}});
    Solution o;
    int res = o.twoCitySchedCost(costs);
    cout << "res: " << res << "\n";
    return 0;
}