// 1091. Shortest Path in Binary Matrix

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

class Solution 
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}});
        const int n = grid.size();
        q.push({0, 0});
        int res = 0;
        while (!q.empty())
        {
            ++res;
            queue<pair<int, int>> q1;
            while(!q.empty())
            {
                auto p = q.front();
                q.pop();
                if (!grid[p.first][p.second])
                {
                    grid[p.first][p.second] = 1;
                    if (p.first == n - 1 && p.second == n - 1) return res;
                    for (auto d : dir) 
                    {
                        const int i = p.first + d.first, j = p.second + d.second;
                        if (i >= 0 && i < n && j >= 0 && j < n) q1.push({i, j});
                    }
                }
            }
            q.swap(q1);
        }
        
        return -1;
    }
};

int main()
{
    return 0;
}