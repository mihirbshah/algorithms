#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

Note: Code runs fine on local compiler but throws heap memory exception on leetcode
*/

namespace
{
    using AdjList = unordered_map<int, unordered_set<int>>;
}

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        numElems = n;
        for (auto connection : connections)
        {
            const int x = connection[0], y = connection[1];
            upsert(inbound, y, x);
            upsert(outbound, x, y);
        }
        dfs(0);
        return flips;
    }
    
private:
    
    void upsert(AdjList& list, int x, int y)
    {
        if (!list.count(x)) list[x] = {y};
        else list[x].insert(y);
    }
    
    void dfs(int n)
    {
        cout << "node: " << n << ", flips: " << flips << "\n";
        //cout << "connected: " << stringify_container(connected.begin(), connected.end()) << "\n";
        if (!connected.count(n)) return;
        if (connected.size() == numElems) return;
        
        if (inbound[n].size())
        {
            for (auto e : inbound[n])
            {
                cout << "== (inbound) node == " << n << "\n";
                connected.insert(e);
                dfs(e);
            }
        }
        
        if (outbound[n].size())
        {
            for (auto e : outbound[n])
            {
                cout << "== (outbound) node == " << n << "\n";
                if (!connected.count(e))
                {
                    outbound[n].erase(e);
                    inbound[e].erase(n);
                    upsert(inbound, n, e);
                    upsert(outbound, e, n);
                    connected.insert(e);
                    ++flips;
                    dfs(e);
                }
            }
        }
    }
    
    AdjList inbound, outbound;
    unordered_set<int> connected = {0};
    int flips = 0;
    int numElems;
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