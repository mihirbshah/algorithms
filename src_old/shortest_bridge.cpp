// 934. Shortest Bridge

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    int shortestBridge(vector<vector<int>>& a) 
    {
        const int m = a.size(), n = a[0].size();
        
        bool found = false;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (a[i][j] == 1)
                {
                    dfs(a, q, visited, i, j);
                    found = true;
                    break;
                }   
            }
            if (found) break;
        }
        
        int res = 0;
        while (!q.empty())
        {
            queue<pair<int, int>> tq;
            while (!q.empty())
            {
                auto p = q.front();
                q.pop();
                for (const auto& d : dir)
                {
                    int x = p.first + d.first;
                    int y = p.second + d.second;
                    if (x < 0 || y < 0 || x >= m || y >= n || visited[x][y]) continue;
                    if (a[x][y]) return res;
                    visited[x][y] = true;
                    a[x][y] = 1;
                    tq.push({x, y});
                }
            }
            q.swap(tq);
            ++res;
        }
        
        return -1;
    }
    
private:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    void dfs(vector<vector<int>>& a, queue<pair<int, int>>& q, vector<vector<bool>>& visited, int i, int j)
    {
        const int m = a.size(), n = a[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || !a[i][j]) return;
        visited[i][j] = true;
        q.push({i, j});
        for (const auto& d : dir)
        {
            int x = i + d.first;
            int y = j + d.second;
            if (x < 0 || y < 0 || x >= m || y >= n) continue; 
            dfs(a, q, visited, x, y);
        }
    }
};

int main()
{
    return 0;
}