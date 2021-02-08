// 994. Rotting Oranges

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution 
{
public:
    using cell = pair<int, int>;
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<cell> q;
        const int m = grid.size();
        const int n = grid[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isRotten(grid, i, j)) q.push(make_pair(i, j));
            }
        }
                
        int mins = 0;
        while (!q.empty())
        {
            queue<cell> tq;
            while (!q.empty())
            {
                cell c = q.front();
                //cout << "Rotten at: [" << c.first << ", " << c.second << "]\n";
                q.pop();
                if (isFresh(grid, c.first - 1, c.second)) enqueueFresh(grid, c.first - 1, c.second, tq);
                if (isFresh(grid, c.first + 1, c.second)) enqueueFresh(grid, c.first + 1, c.second, tq);
                if (isFresh(grid, c.first, c.second - 1)) enqueueFresh(grid, c.first, c.second - 1, tq);
                if (isFresh(grid, c.first, c.second + 1)) enqueueFresh(grid, c.first, c.second + 1, tq);
            }
            if (tq.size()) ++mins;
            q.swap(tq);
        }
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (isFresh(grid, i, j)) return -1;
            }
        }
        
        return mins;
    }
    
private:
    void enqueueFresh(vector<vector<int>>& grid, int i, int j, queue<cell>& q)
    {
        grid[i][j] = '2';
        q.push(make_pair(i, j));
    }
    
    bool isRotten(const vector<vector<int>>& grid, int i, int j)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 2;
    }
    
    bool isFresh(const vector<vector<int>>& grid, int i, int j)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        return i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1;
    }

};

int main()
{
    //vector<vector<int>> grid({{2,1,1},{1,1,0},{0,1,1}});
    //vector<vector<int>> grid({{2,1,1},{0,1,1},{1,0,1}});
    vector<vector<int>> grid({{0,2}});
    Solution o;
    int res = o.orangesRotting(grid);
    cout << "res: " << res << "\n";
    return 0;
}