#include <iostream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;


void print3D(const IntVector3D& mat)
{
  for (const auto& v : mat)
  {
    for (const auto& sv : v)
    {
      for (const auto& e : sv)
      {
        cout << e << " ";
      }
      cout << "\t\n";
    }
    cout << "\n";
  }
}

void print2D(const IntVector2D& mat)
{
  for (const auto& v : mat)
  {
    for (auto e : v)
    {
      cout << e << " ";
    }
    cout << "\n";
  }
}

class Solution {
  public:
    typedef vector<vector<vector<int>>> IntVector3D;
    typedef vector<vector<int>> IntVector2D;
    
    int ways(vector<string>& pizza, int k) 
    {
      _m = pizza.size(); 
      _n = pizza[0].size();
      _dp = vector(k, vector(_m, vector(_n, -1)));
      // preSum[r][c] is the total number of apples in pizza[r:][c:]
      _preSum = vector(_m+1, vector(_n+1, 0)); 
      
      for (int r = _m - 1; r >= 0; r--)
        for (int c = _n - 1; c >= 0; c--)
          _preSum[r][c] = _preSum[r][c+1] + _preSum[r+1][c] - _preSum[r+1][c+1] + (pizza[r][c] == 'A');
      
      //print2D(_preSum);
      return dfs(k-1, 0, 0);
    }

    int dfs(int k, int r, int c) 
    {
      if (_preSum[r][c] == 0) return 0; // if the remain piece has no apple -> invalid
      if (k == 0) return 1; // found valid way after using k-1 cuts
      if (_dp[k][r][c] != -1) 
      {
        cout << "k=" << k << ", r=" << r << ", c=" << c << "\n";
        return _dp[k][r][c];
      }
      int ans = 0;
      
      // cut in horizontal
      for (int nr = r + 1; nr < _m; nr++) 
        if (_preSum[r][c] - _preSum[nr][c] > 0) // cut if the upper piece contains at least one apple
          ans = (ans + dfs(k - 1, nr, c)) % MOD;
    
      // cut in vertical
      for (int nc = c + 1; nc < _n; nc++) 
        if (_preSum[r][c] - _preSum[r][nc] > 0) // cut if the left piece contains at least one apple
          ans = (ans + dfs(k - 1, r, nc)) % MOD;
        
      return _dp[k][r][c] = ans;
    }

  private:
    long long MOD = 1000000007;
    int _m = 0;
    int _n = 0;
    IntVector3D _dp;
    IntVector2D _preSum;
};

int main()
{
  Solution s;
  vector<string> v = {"A..","AAA","..."};
  int w = s.ways(v, 3);
  cout << "ways: " << w << "\n";
  return 0;
}
