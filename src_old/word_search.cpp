// 79. Word Search

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return true;
        if (board.empty() || board[0].empty()) return false;
        
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                // traverse the board to find the first char
                if (dfsSearch(board, word, 0, i, j)) return true;
        return false;
    }
private:
    int m;
    int n;
    bool dfsSearch(vector<vector<char>>& board, string& word, int k, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n || word[k] != board[i][j]) return false;
        if (k == word.length() - 1) return true;  // found the last char

        char cur = board[i][j];
        board[i][j] = '*';  // used
        bool search_next = dfsSearch(board, word, k+1, i-1 ,j) 
                        || dfsSearch(board, word, k+1, i+1, j) 
                        || dfsSearch(board, word, k+1, i, j-1)
                        || dfsSearch(board, word, k+1, i, j+1);
        board[i][j] = cur;  // reset
        return search_next;
    }
};

/* BUGGY

class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        const int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == word[0] && bfs(board, word, i, j)) return true;
            }
        }
        
        return false;
    }
    
private:
    bool bfs(const vector<vector<char>>& board, const string& word, int x, int y)
    {
        cout << "x: " << x << ", y: " << y << "\n";
        queue<vector<int>> q;
        const int m = board.size(), n = board[0].size(), w = word.size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        q.push({x, y, 0});
        
        while (!q.empty())
        {
            queue<vector<int>> tq;
            while (!q.empty())
            {
                auto& v = q.front();
                q.pop();
                const int i = v[0], j = v[1], k = v[2];
                cout << "i: " << i << ", j: " << j << ", k: " << k << "\n";
                if (visited[i][j]) continue;
                if (board[i][j] != word[k]) continue;
                visited[i][j] = true;
                if (k == w - 1) return true;
                
                cout << "exploring neighbours\n";
                for (const auto& d : dirs)
                {
                    const int a = i + d[0], b = j + d[1], c = k + 1;
                    if (validPos(a, b, c, m, n, w)) tq.push({a, b, c});
                }
            }
            q.swap(tq);
        }
        
        return false;
    }
    
    bool validPos(int i, int j, int k, int m, int n, int w)
    {
        return i >= 0 && i < m && j >= 0 && j < n && k >= 0 && k < w;
    }
    
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
};
*/

int main()
{
    //vector<vector<char>> board({{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}}); string word = "ABCCED";
    vector<vector<char>> board({{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}}); string word = "ABCESEEEFS";
    Solution o;
    bool res = o.exist(board, word);
    cout << "res: " << res << "\n";
    return 0;
}