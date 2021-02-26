// 1245. Tree Diameter

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution 
{
public:
    int treeDiameter(vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>> tree;
        for (auto edge : edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited({});
        int res = 0;
        dfs(tree, 0, visited, res);
        return res;
    }
    
private:
    int dfs(unordered_map<int, vector<int>>& tree, int v, unordered_set<int>& visited, int& maxLen)
    {
        int path = 0;
        priority_queue<int> q;
        visited.insert(v);
        cout << "handling node: " << v << "\n";
        for (auto c : tree[v])
        {
            if (visited.count(c)) continue;
            cout << "scanning neighbour: " << c << "\n";
            q.push(dfs(tree, c, visited, maxLen));
        }
        visited.erase(v);
        int localLongestPath = 0, localSecondLongestPath = 0;
        if (!q.empty())
        {
            localLongestPath = q.top();
            q.pop();
        }
        if (!q.empty())
        {
            localSecondLongestPath = q.top();
            q.pop();
        }
        maxLen = max(maxLen, localLongestPath + localSecondLongestPath);
        cout << "localLongestPath: " << localLongestPath << ", localSecondLongestPath: " << localSecondLongestPath << ", maxLen: " << maxLen << "\n";
        return localLongestPath + 1;
    }
};

int main()
{
    //vector<vector<int>> edges({{0,1},{1,2},{2,3},{1,4},{4,5}});
    vector<vector<int>> edges({{0,1},{1,2},{0,3},{3,4},{2,5},{3,6}});
    
    Solution o; 
    int res = o.treeDiameter(edges);
    cout << "res: " << res << "\n";
    return 0;
}