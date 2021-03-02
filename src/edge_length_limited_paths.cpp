// 1697. Checking Existence of Edge Length Limited Paths

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <numeric>

using namespace std;

/*
// Solution gets TLE'ed
class Solution 
{
public:
    using Edges = vector<vector<int>>;
    
    vector<bool> distanceLimitedPathsExist(int n, Edges& edgeList, Edges& queries) 
    {
        for (const auto& e: edgeList)
        {
            int v1 = e[0], v2 = e[1], len = e[2];
            if (graph[v1].count(v2)) 
            {
                graph[v1][v2] = min(graph[v1][v2], len);
                graph[v2][v1] = min(graph[v2][v1], len);
            }
            else 
            {
                graph[v1][v2] = len;
                graph[v2][v1] = len;
            }
        }
                
        vector<bool> res;
        for (const auto& q : queries)
        {
            for (int i = 0; i < n; ++i) visited[i] = false;
            res.push_back(dfs(q[0], q[1], q[2]));
        }
        
        return res;
    }
    
private:
    bool dfs(int src, int dest, int len)
    {
        visited[src] = true;
        bool res = false;
        for (const auto& [v, d] : graph[src])
        {
            if (visited[v] || d >= len) continue;
            if (v == dest && d < len)
            {
                res = true;
                break;
            }
            bool ret = dfs(v, dest, len);
            if (ret) 
            {
                res = ret && d < len;
                break;
            }
        }
        return res;
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, unordered_map<int, int>> graph;
};
*/


class UnionFind 
{
public:
    UnionFind(int n) : parent(n) 
    {
        iota(parent.begin(), parent.end(), 0);
    }
    
    void connect(int a, int b) 
    {
        parent[find(a)] = find(b);
    }
    
    int find(int a) 
    {
        return parent[a] == a ? a : (parent[a] = find(parent[a]));
    }
    
private:
    vector<int> parent;
};

class Solution 
{
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& E, vector<vector<int>>& Q) 
    {
        vector<bool> ans(Q.size());
        for (int i = 0; i < Q.size(); ++i) Q[i].push_back(i);
        sort(begin(Q), end(Q), [&](auto &a, auto &b) { return a[2] < b[2]; });
        sort(begin(E), end(E), [&](auto &a, auto &b) { return a[2] < b[2]; });
        UnionFind uf(n);
        int i = 0;
        for (auto &q : Q) 
        { 
            int u = q[0], v = q[1], limit = q[2], qid = q[3];
            for (; i < E.size() && E[i][2] < limit; ++i) uf.connect(E[i][0], E[i][1]); 
            ans[qid] = uf.find(u) == uf.find(v);
        }
        
        return ans;
    }
};


int main()
{
    //vector<vector<int>> edges({{0,1,2},{1,2,4},{2,0,8},{1,0,16}});
    //vector<vector<int>> queries({{0,1,2},{0,2,5}});
    //int n = 3;
    //vector<vector<int>> edges({{0,1,10},{1,2,5},{2,3,9},{3,4,13}});
    //vector<vector<int>> queries({{0,4,14},{1,4,13}});
    //int n = 5;
    vector<vector<int>> edges({{9,1,53},{3,2,66},{12,5,99},{9,7,26},{1,4,78},{11,1,62},{3,10,50},{12,1,71},{12,6,63},{1,10,63},{9,10,88},{9,11,59},{1,4,37},{4,2,63},{0,2,26},{6,12,98},{9,11,99},{4,5,40},{2,8,25},{4,2,35},{8,10,9},{11,9,25},{10,11,11},{7,6,89},{2,4,99},{10,4,63}});
    vector<vector<int>> queries({{10,8,43}});
    int n = 13;

    
    Solution o;
    vector<bool> res = o.distanceLimitedPathsExist(n, edges, queries);
    for (auto r : res) cout << (r ? "true" : "false") << ", ";
    cout << "\n";
    return 0;
}