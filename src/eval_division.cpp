// 399. Evaluate Division

#include <iostream>
#include <unordered_map>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, vector<pair<string, double>>> graph;
        const int n = equations.size();
        for (int i = 0; i < n; ++i)
        {
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        
        vector<double> res;
        for (auto& q : queries)
        {
            res.push_back(eval(graph, q));
        }
        
        return res;
    }
    
private:
    double eval(unordered_map<string, vector<pair<string, double>>>& graph, vector<string>& query)
    {
        string source = query[0], target = query[1];
        if (!graph.count(source) || !graph.count(target)) return -1.0;
        queue<pair<string, double>> q;
        q.push({source, 1.0});
        unordered_map<string, bool> visited;
        
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            if (p.first == target) return p.second;
            visited[p.first] = true;
            for (auto& child : graph[p.first])
            {
                if (!visited[child.first]) q.push({child.first, p.second * child.second});
            }
        }
        
        return -1.0;
    }
};

int main()
{
    return 0;
}