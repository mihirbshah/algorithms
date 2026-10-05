// 1514. Path with Maximum Probability

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution 
{
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) 
    {
        unordered_map<int, vector<pair<int, double>>> graph;
        for (int i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(make_pair(v, succProb[i]));
            graph[v].push_back(make_pair(u, succProb[i]));
        }
                
        priority_queue<pair<double, int>> pq;
        vector<double> probability(n, 0);
        pq.push(make_pair(1, start));
        while (!pq.empty())
        {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (node == end) return prob;
            
            if (prob < probability[node]) continue;
            probability[node] = prob;
            
            for (const auto neighbor : graph[node])
            {
                pq.push({prob * neighbor.second, neighbor.first});
            }
        }
        
        return 0;
    }
};

int main()
{
    vector<vector<int>> edges({{0,1}});
    vector<double> succProb({0.5});
    int n = 3, start = 0, end = 2;
    Solution o;
    double res = o.maxProbability(n, edges, succProb, start, end);
    cout << "res: " << res << "\n";
    return 0;
}