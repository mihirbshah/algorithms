// 200. Number of Islands

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        const int m = grid.size(), n = grid[0].size();
        int islands = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++islands;
                    eraseNeighbours(grid, i, j);
                }
            }
        }
        return islands;
    }
    
private:
    void eraseNeighbours(vector<vector<char>>& grid, int i, int j)
    {
        const int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        eraseNeighbours(grid, i - 1, j);
        eraseNeighbours(grid, i + 1, j);
        eraseNeighbours(grid, i, j - 1);
        eraseNeighbours(grid, i, j + 1);
    }
};

int main()
{
    return 0;
}