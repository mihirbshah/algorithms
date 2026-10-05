// 1631. Path With Minimum Effort

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// dijkstra
class Solution 
{
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        const int m = heights.size(), n = heights[0].size();
        auto comp = [&](const vector<int>& v1, const vector<int>& v2){ return v1[0] > v2[0]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));
        
        vector<int> dir({-1, 0, 1, 0, -1});
        
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            int effort = pq.top()[0], x = pq.top()[1], y = pq.top()[2];
            pq.pop();
            if (x == m - 1 && y == n - 1) return effort;
            
            if (effort >= efforts[x][y]) continue;
            efforts[x][y] = effort;
            
            for (int i = 0; i < 4; ++i)
            {
                int newX = x + dir[i], newY = y + dir[i + 1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n)
                {
                    pq.push({max(effort, abs(heights[x][y] - heights[newX][newY])), newX, newY});
                }
            }
        }
        
        return -1;
    }
    

};

int main()
{
    return 0;
}