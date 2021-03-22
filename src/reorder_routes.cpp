#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
*/

namespace
{
    using AdjList = unordered_map<int, unordered_set<int>>;
}

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        for (auto connection : connections)
        {
            const int x = connection[0], y = connection[1];
            upsert(inbound, y, x);
            upsert(outbound, x, y);
        }
        unordered_set<int> visited;
        return dfs(0, visited);
    }
    
private:
    
    void upsert(AdjList& list, int x, int y)
    {
        if (!list.count(x)) list[x] = {y};
        else list[x].insert(y);
    }
    
    int dfs(int n, unordered_set<int>& visited)
    {
        int res = 0;
        visited.insert(n);
        if (inbound.count(n))
        {
            for (auto e : inbound[n])
            {
                if (!visited.count(e)) res += dfs(e, visited);
            }
        }
        
        if (outbound.count(n))
        {
            for (auto e : outbound[n])
            {
                if (!visited.count(e)) res += (1 + dfs(e, visited));
            }
        }
        visited.erase(n);
        return res;
    }
    
    AdjList inbound, outbound;
};

int main()
{
    Solution o;
    vector<vector<int>> v = {{0,1},{1,3},{2,3},{4,0},{4,5}}; int n = 6;
    //vector<vector<int>> v = {{1,0},{1,2},{3,2},{3,4}}; int n = 5;
    //vector<vector<int>> v = {{1,0},{2,0}}; int n = 3;
    
    int res = o.minReorder(n,v);
    cout << "res: " << res << "\n";
    return 0;
}