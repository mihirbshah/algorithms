#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

/*
https://leetcode.com/problems/shortest-path-to-get-all-keys/
*/

namespace
{
    int DefaultKeyMask = 0;
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool bounded(int i, int j, int rowBound, int colBound)
    {
        return (i >= 0) && (i < rowBound) && (j >= 0) && (j < colBound);
    }
};

class Solution
{
private:
    struct State
    {
        int i, j, keyMask;
        State(int i_, int j_, int keyMask_) : 
            i(i_), 
            j(j_), 
            keyMask(keyMask_)
        {
        }
        
        string str() const
        {
            return to_string(i) + to_string(j) + to_string(keyMask);
        }        
    };
    
    struct StateHasher
    {
        size_t operator()(const State& s) const
        {
            return hash<string>()(s.str());
        }
    };
    
    struct StateComparator
    {
        bool operator()(const State& s1, const State& s2) const
        {
            return s1.str() == s2.str();
        }
    };
    
    int addKey(char c, int mask) const
    {
        return mask |= (1 << (c - 'a'));
    }
    
    bool keyAvailable(char c, int mask) const
    {
        return 0 != (mask & 1 << (c - 'A'));
    }
    
    bool allKeysPresent(int mask, int maxKey) const
    {
        return mask == (1 << maxKey) - 1;
    }
    
public:
    int shortestPathAllKeys(vector<string>& grid)
    {
        int rows = grid.size(), cols = grid[0].size();
        int x = -1, y = -1, mask = 0;
        int maxKey = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                char c = grid[i][j];
                if ('@' == c)
                {
                    x = i; y = j;
                }
                else if (c >= 'a' && c <= 'f')
                {
                    maxKey = max(maxKey, 1 + (c - 'a'));
                }
            }
        }
        
        queue<State> q;
        q.emplace(x, y, DefaultKeyMask);
        unordered_set<State, StateHasher, StateComparator> visited;
        visited.emplace(x, y, DefaultKeyMask);
        int steps = 0;
        
        while(!q.empty())
        {
            size_t size = q.size();
            for (int i = 0; i < size; ++i)
            {
                State curr = q.front();
                q.pop();
                
                if (allKeysPresent(curr.keyMask, maxKey)) return steps;
                    
                for (auto dir : dirs)
                {
                    x = curr.i + dir[0];
                    y = curr.j + dir[1];
                    int newKeyMask = curr.keyMask;
                    if (bounded(x, y, rows, cols))
                    {
                        char c = grid[x][y];
                        if ('#' == c) continue;
                        if (c >= 'A' && c <= 'F' && !keyAvailable(c, newKeyMask)) continue;
                        if (c >= 'a' && c <= 'f') newKeyMask = addKey(c, newKeyMask);
                        State newState(x, y, newKeyMask);
                        if (!visited.count(newState))
                        {
                            visited.insert(newState);
                            q.push(newState);
                        }
                    }
                }
            }
            ++steps;
        }
        
        return -1;
    }
};

int main()
{
    Solution o;
    vector<string> grid1 = {"@.a.#", "###.#", "b.A.B"};
    vector<string> grid2 = {"@..aA","..B#.","....b"};
    vector<string> grid3 = {"@...a",".###A","b.BCc"};
    
    int res = o.shortestPathAllKeys(grid3);
    cout << "res: " << res << "\n";
    
    return 0;
}