// 1368. Minimum Cost to Make at Least One Valid Path in a Grid

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/*
class Solution 
{
public:
    int minCost(vector<vector<int>>& grid) 
    {
        return dfs(grid, 0, 0, 0, 0);
    }
    
private:
    int dfs(vector<vector<int>>& grid, int ci, int cj, int pi, int pj)
    {
        bool flip = false;
        int rows = grid.size(), cols = grid[0].size();
        if (ci == rows - 1 && cj == cols - 1) 
        {
            return 0;
        }
        
        if (grid[ci][cj] == 4) flip = true;
        else if (grid[ci][cj] == 3 && ci < rows - 1) flip = false;
        else if (grid[ci][cj] == 3 && ci == rows - 1) flip = true;
        else if (ci == pi && grid[ci][cj] != grid[pi][pj]) flip = true;
        else if (grid[ci][cj] == 1 && cj == cols - 1) flip = true;
        else if (grid[ci][cj] == 2 && cj == 0) flip = true;
        
        cout << "ci: " << ci << ", cj: " << cj << ", pi: " << pi << ", pj: " << pj << ", flip: " << (flip ? "true" : "false") << "\n";
        if (!flip)
        {
            auto next = getNextCell(ci, cj, grid[ci][cj]);
            return dfs(grid, next.first, next.second, ci, cj);
        }
        else
        {
            int res = INT_MAX;
            auto next = getNextCell(ci, cj, (pi == 0 && pj == 0) ? 1 : grid[pi][pj]);
            if (next.first < rows && next.second < cols && next.first >= 0 && next.second >= 0) 
            {
                cout << "checkpoint 1: ci: " << ci << ", cj: " << cj << ", first: " << next.first << ", second: " << next.second << "\n";
                int oldDir = grid[ci][cj];
                grid[ci][cj] = (pi == 0 && pj == 0) ? 1 : grid[pi][pj];
                res = min(res, 1 + dfs(grid, next.first, next.second, ci, cj));
                cout << "checkpoint 1: ci: " << ci << ", cj: " << cj << ", res: " << res << "\n";
                grid[ci][cj] = oldDir;
            }
            next = getNextCell(ci, cj, 3);
            if (next.first < rows && next.second < cols  && next.first >= 0 && next.second >= 0) 
            {
                cout << "checkpoint 2: ci: " << ci << ", cj: " << cj << ", first: " << next.first << ", second: " << next.second << "\n";
                int oldDir = grid[ci][cj];
                grid[ci][cj] = 3;
                res = min(res, 1 + dfs(grid, next.first, next.second, ci, cj));
                cout << "checkpoint 2: ci: " << ci << ", cj: " << cj << ", res: " << res << "\n";
                grid[ci][cj] = oldDir;
            }
            return res;
        }
        
        return 0;
    }
    
    pair<int, int> getNextCell(int ci, int cj, int dir)
    {
        if (dir == 1) return make_pair(ci, cj + 1);
        if (dir == 2) return make_pair(ci, cj - 1);
        if (dir == 3) return make_pair(ci + 1, cj);
        if (dir == 4) return make_pair(ci - 1, cj);
        return make_pair(ci, cj);
    }
};
*/


class Solution 
{
public:
    int minCost(vector<vector<int>>& grid) 
    {
        vector<vector<int>> dir({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
        const int m = grid.size(), n = grid[0].size();
        deque<vector<int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push_front({0, 0, 0});
        while (!q.empty())
        {
            auto v = q.front();
            q.pop_front();
            int r = v[0], c = v[1], cost = v[2];
            if (r == m - 1 && c == n - 1) return cost;
            if (visited[r][c]) continue;
            visited[r][c] = true;
            for (int i = 0; i <= 3; ++i)
            {
                int newr = r + dir[i][0], newc = c + dir[i][1];
                if (newr < 0 || newr >= m || newc < 0 || newc >= n) continue;
                if (i + 1 == grid[r][c]) // if we are moving in the same direction as grid[r][c] then no cost
                    q.push_front({newr, newc, cost});
                else
                    q.push_back({newr, newc, cost + 1}); // else cost + 1 to flip the direction of grid[r][c]
            }
        }
        
        return -1;
    }
};


int main()
{
    //vector<vector<int>> grid({{1,1,3},{3,2,2},{1,1,4}});
    //vector<vector<int>> grid({{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}});
    vector<vector<int>> grid({{2,2,2},{2,2,2}});
    
    Solution o;
    int res = o.minCost(grid);
    cout << "res: " << res << "\n";
    return 0;
}