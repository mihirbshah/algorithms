// 797. All Paths From Source to Target

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        queue<pair<int, vector<int>>> q;
        q.push({0, {}});
        vector<vector<int>> paths;
        const int target = graph.size() - 1;
        
        while (!q.empty())
        {
            queue<pair<int, vector<int>>> tq;
            while (!q.empty())
            {
                auto p = q.front();
                q.pop();
                p.second.push_back(p.first);
                if (p.first == target)
                {
                    paths.push_back(p.second);
                    continue;
                }
                
                for (auto node : graph[p.first])
                {
                    tq.push({node, p.second});
                }
            }
            q.swap(tq);
        }
        
        return paths;
    }
};

int main()
{
    return 0;
}