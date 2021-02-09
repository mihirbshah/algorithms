// 1152. Analyze User Website Visit Pattern

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "util.h"

using namespace std;

class Solution {
public:
    using VStr = vector<string>;
    VStr mostVisitedPattern(VStr& username, vector<int>& timestamp, VStr& website) 
    {
        const int n = username.size();
        unordered_set<string> users(username.begin(), username.end());
        unordered_map<string, vector<pair<string, int>>> userSite;
        for (int i = 0; i < n; ++i)
        {
            userSite[username[i]].push_back(make_pair(website[i],timestamp[i]));
        }
        
        for (auto& [ke, v] : userSite)
        {
            sort(v.begin(), v.end(), [&](const pair<string, int>& p1, const pair<string, int>& p2){ return p1.second < p2.second; });
            cout << "user: " << ke << ", sites: ";
            for (const auto& p : v)
                cout << p.first << ", ";
            cout << "\n";
            updateUsage(v);
        }
        
        vector<pair<string, int>> vused;
        for (const auto& [ke, v] : usage)
        {
            cout << "key: " << ke << ", value: " << v << "\n";
            vused.push_back(make_pair(ke, v));
        }
        
        sort(vused.begin(), vused.end(), [&](const pair<string, int>& p1, const pair<string, int>& p2){ return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first); });
        
        VStr mostused;
        int hused = vused.front().second;
        for (const auto& p : vused)
        {
            cout << "p.first: " << p.first << ", p.second: " << p.second << "\n";
            if (p.second == hused) mostused.push_back(p.first);
        }
        
        sort(mostused.begin(), mostused.end());
        
        string s = mostused.front();
        
        cout << "most used: " << s << "\n";
        int prev = 0;
        VStr res;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ':')
            {
                res.push_back(s.substr(prev, i - prev));
                prev = i + 1;
            }
        }
        res.push_back(s.substr(prev, s.size() - prev));
        
        return res;
    }
        
private:
    void updateUsage(const vector<pair<string, int>>& uw)
    {
        const int n = uw.size();
        if (n < 3) return;
        for (int i = 0; i <= n - 3; ++i)
        {
            for (int j = i + 1; j <= n - 2; ++j)
            {
                for (int k = j + 1; k <= n - 1; ++k)
                {
                    string kk = uw[i].first + ":" + uw[j].first + ":" + uw[k].first;
                    ++usage[kk];
                }
            }
        }
    }
    
    unordered_map<string, int> usage;
};

int main()
{
    //vector<string> users({"joe","joe","joe","james","james","james","james","mary","mary","mary"});
    //vector<int> times({1,2,3,4,5,6,7,8,9,10});
    //vector<string> sites({"home","about","career","home","cart","maps","home","home","about","career"});

    vector<string> users({"h","eiy","cq","h","cq","txldsscx","cq","txldsscx","h","cq","cq"});
    vector<int> times({527896567,334462937,517687281,134127993,859112386,159548699,51100299,444082139,926837079,317455832,411747930});
    vector<string> sites({"hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","yljmntrclw","hibympufi","yljmntrclw"});

    Solution o;
    vector<string> res = o.mostVisitedPattern(users, times, sites);
    print_container(res.begin(), res.end());
    return 0;
}