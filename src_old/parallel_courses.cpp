// 1136. Parallel Courses

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <queue>

using namespace std;

class Solution 
{
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) 
    {
        vector<vector<int>> graph(n + 1, vector<int>());
        vector<int> indegree(n + 1, 0);
        for (const auto& r : relations)
        {
            graph[r[0]].push_back(r[1]);
            ++indegree[r[1]];
        }
        
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; ++i)
        {
            if (!indegree[i]) q.push({i, 1});
        }
        
        int maxdepth = 0;
        int numStudied = 0;
        while (!q.empty())
        {
            auto [e, depth] = q.front();
            q.pop();
            ++numStudied;
            maxdepth = max(maxdepth, depth);
            for (auto c : graph[e])
            {
                --indegree[c];
                if (!indegree[c]) q.push({c, depth + 1});
            }
        }
        
        return numStudied == n ? maxdepth : -1;
    }
};

/* // partially working solution
class Solution 
{
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) 
    {
        unordered_map<int, unordered_set<int>> graph;
        unordered_set<int> noparent;
        vector<bool> visited(n + 1, false);
        for (const auto& r : relations)
        {
            graph[r[1]].insert(r[0]);
            noparent.insert(r[1]);
            if (noparent.count(r[0])) noparent.erase(r[0]);
        }
        
        int res = INT_MIN;
        for (auto np : noparent)
        {
            res = max(res, dfs(graph, visited, np));
        }
        
        return res;
    }
    
private:
    int dfs(unordered_map<int, unordered_set<int>>& graph, vector<bool>& visited, int n)
    {
        if (visited[n]) return -1;
        visited[n] = true;
        int res = 0;
        for (auto c : graph[n])
        {
            auto ret = dfs(graph, visited, c);
            if (ret == -1) return ret;
            res = max(res, ret);
        }
        return 1 + res;
    }
};
*/


int main()
{
    vector<vector<int>> relations({{1,3},{2,3}}); int n = 3;
    Solution o;
    int res = o.minimumSemesters(n, relations);
    cout << "res: " << res << "\n";
    return 0;
}