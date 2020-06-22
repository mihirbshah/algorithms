#include <iostream>

using namespace std;

/*
  https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/
  Solution based on - https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/discuss/574923/JavaC%2B%2BPython-DP-O(1)-Space
*/
int numWays(int n)
{
  long a121 = 6, a123 = 6;
  long b121, b123;
  const int MOD = 1e9 + 7; 

  for (int i = 1; i < n; ++i)
  {
    b121 = 3 * a121 + 2 * a123;
    b123 = 2 * a121 + 2 * a123;
    a121 = b121 % MOD;
    a123 = b123 % MOD;
  }
  return (a121 + a123) % MOD;
}

int main()
{
  cout << "numWays: " << numWays(2) << "\n";
  return 0;
}
