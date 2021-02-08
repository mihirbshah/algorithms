// 1192. Critical Connections in a Network

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "util.h"

using namespace std;

class Solution 
{
public:
    using Graph = unordered_map<int, vector<int>>;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        Graph graph(n);
        for (const auto c : connections) 
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }
        
        vector<vector<int>> critical;
        for (const auto& [node, edges] : graph)
        {
            for (const auto& edge : edges)
            {
                if (isCritical(graph, node, edge) && node > edge) critical.push_back({node, edge});
            }
        }
        return critical;
    }
    
private:
    bool canReachTarget(Graph& graph, int edge, int target, unordered_set<int> traversed)
    {
        const vector<int>& edges = graph[edge];
        if (find(edges.begin(), edges.end(), target) != edges.end()) return true;
        traversed.insert(edge);
        for (const auto& e : edges)
        {
            if (traversed.count(e) != 0) continue;
            if (canReachTarget(graph, e, target, traversed)) return true;
        }
        
        return false;
    }
    
    bool isCritical(Graph& graph, int source, int target)
    {
        bool ret = true;
        for (const auto& e : graph[source])
        {
            if (e == target) continue;
            ret &= !canReachTarget(graph, e, target, {source});
        }
        
        return ret;
    }
};

int main()
{
    vector<vector<int>> g({{0,1},{1,2},{2,0},{1,3}}); int n = 4;
    //vector<vector<int>> g({{0,1},{1,2},{2,0},{1,3},{3,4},{4,5},{5,3}}); int n = 6;
    Solution o;
    vector<vector<int>> res = o.criticalConnections(n, g);
    for (const auto& edge : res)
    {
        cout << "[" << edge[0] << ", " << edge[1] << "]\n";
    }
    return 0;
}