#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[100001] = {};

/* https://leetcode.com/problems/restore-the-array/ */

class Solution
{
  public:
  int dfs(string s, int k, int i) 
  {
    cout << "=== i: " << i << " ===\n";
    if (i == s.size())
    {
      //cout << "i: " << i << "\n";
      return 1;
    }
  
    if (s[i] == '0')
    {
      //cout << "i: " << i << "\n";
      return 0;
    }
    
    if (!dp[i]) 
    {
      long num = 0;
      for (long sz = 1; i + sz <= s.size(); ++sz) 
      {
        num = num * 10 + s[i + sz - 1] - '0';
        //cout << "i: " << i << ", num: " << num << "\n";
        if (num > k)
          break;
        dp[i] = (dp[i] + dfs(i + sz)) % 1000000007;
      }
    }
    
    //cout << "i: " << i << ", dp[" << i << "]: " << dp[i] << "\n";
    return dp[i];
  }
  
  int numberOfArrays(string s, int k) 
  {
    return dfs(s, k, 0);
  }
};

int main()
{
  string s1 = "1317"; int k1 = 2000;
  Solution obj;
  int res = obj.numberOfArrays(s1, k1);
  cout << "res: " << res << "\n";
  return 0;
}
