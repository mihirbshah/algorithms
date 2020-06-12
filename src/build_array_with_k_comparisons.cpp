#include <iostream>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

We have 3 dimensions here - n,m,k
Let ways[n][m][k] be the number of ways we can build an array of size n, with max element m and search cost k
Since the problem asks to build an array of size n, the subproblem would be to build an array of size n-1
Now that we have pegged one dimension n-1, for the other 2 dimensions, we don't need to use them to characterize 
the size of a sub problem. Rather they are used to simply find all possible combinations that can occur on the 
sub problem of size n-1. For 2 dimensions m,k there are 4 possible combinations - 
a. n-1: m-1, k-1 -> max element is m-1 and search cost is k-1
b. n-1: m-1, k   -> max element is m-1 and search cost is k
c. n-1: m, k-1   -> max element is m   and search cost is k-1
d. n-1: m,k      -> max element is m   and search cost is k

(b.) cannot occur since there is no way to arrive at ways[n][m][k] from ways[n-1][m-1][k] since adding nth element as 'm' would increment search cost to k+1
(c.) cannot occur since there is no way to arrive at ways[n][m][k] from ways[n-1][m][k-1] since max element is already 'm' so nothing would increment search cost to k

So (a.) and (d.) are only valid scenarios. 

In the end, the result will be sum of all ways[n][i][k] where i = 1 to m since the max element is allowed to be between 1-m but search cost has to be exactly k and number of elements have to be exactly n
*/
int numOfArrays(int n, int m, int cost)
{
  vector<vector<vector<int>>> ways(51, vector<vector<int>>(101, vector<int>(51, 0)));
  const int MOD = 1e9 + 7;

  for (int j = 1; j <= m; ++j)
  {
    ways[1][j][1] = 1;
  }

  for (int i = 1; i <= n; ++i)
  {
    for (int j = 1; j <= m; ++j)
    {
      for (int k = 1; k <= cost; ++k)
      {
        long long temp = 0;
        for (int l = 1; l <= j-1; ++l)
        {
          temp += ways[i-1][l][k-1] % MOD;
        }
        ways[i][j][k] += ((j * ways[i-1][j][k]) + temp) % MOD;
      }
    }
  }

  int res = 0;
  for (int j = 1; j <= m; ++j)
  {
    res += ways[n][j][cost] % MOD;
  }

  return res;
}

int main()
{
  int res = numOfArrays(2,3,1);
  cout << "ways: " << res << "\n";
  return 0;
}
