// 1254. Number of Closed Islands

#include <iostream>
#include <vector>

using namespace std;

// For iterative solution, refer https://leetcode.com/problems/number-of-closed-islands/discuss/425150/JavaC%2B%2B-with-picture-Number-of-Enclaves
class Solution 
{
public:
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = 0;
        dfs(grid, 0, 0, n);
        return n;
    }
    
private:
    void dfs(vector<vector<int>>& grid, int i, int j, int& c)
    {
        //cout << "i: " << i << ", j: " << j << "\n";
        const int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) return;
        if (grid[i][j] == 0) 
        {
            c += sweepZeros(grid, i, j);
            //cout << "c: " << c << "\n";
        }
        
        if (grid[i][j] == 1) grid[i][j] = -1;
        dfs(grid, i - 1, j, c);
        dfs(grid, i + 1, j, c);
        dfs(grid, i, j - 1, c);
        dfs(grid, i, j + 1, c);
    }
    
    bool sweepZeros(vector<vector<int>>& grid, int i, int j)
    {
        //cout << "sweepZeros: i: " << i << ", j: " << j << "\n";
        const int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (grid[i][j] == 1 || grid[i][j] == -1) return true;
        grid[i][j] = 1;
        bool b1 = sweepZeros(grid, i - 1, j);
        bool b2 = sweepZeros(grid, i + 1, j);
        bool b3 = sweepZeros(grid, i, j - 1);
        bool b4 = sweepZeros(grid, i, j + 1);
        return b1 && b2 && b3 && b4;
    }
};

int main()
{
    vector<vector<int>> grid({{1,1,1,1,1,1,1},{1,0,0,0,0,0,1},{1,0,1,1,1,0,1},{1,0,1,0,1,0,1},{1,0,1,1,1,0,1},{1,0,0,0,0,0,1},{1,1,1,1,1,1,1}});
    Solution o;
    int res = o.closedIsland(grid);
    cout << "res: " << res << "\n";
    return 0;
}