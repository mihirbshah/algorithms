#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/string-compression-ii/submissions/

Let dp[i][j] be the minimum length RLE string fothe substring until position 'i' with at most 'j' characters removed.
Then the final result would be stored in dp[n][k] where n is the size of 's'

At every position 'i', we have 2 options:
1. Remove the char at position 'i' and then the solution would be from dp[i-1][j-1] i.e. the remove j-1 characters from substring until i-1 position.
2. Keep the char at position 'i' and remove the j characters from the substring until position i-1.

For case 2., one way to think is if we keep char at position 'i', then the solution would be from dp[i-1][j].
However, this is not correct because dp[i-1][j] simply represents best solution to remove at most 'j' chars from
substring until i-1 position. However, for case 2., it also matters which 'j' chars are dropped. To understand why, 
consider k=2 and the following substring up until position i-1: bcaa, so that dp[i-1][2] = 2
and let's say the char at position i is 'a'. 
Now, we can achieve dp[i-1][2] = 2 by removing 'b' & 'c' or by removing 'a' & 'a'. Both yield the same result.
if we remove 'b'&'c', then the final result after considering the char 'a' at position i is aaa with RLE=a3 (size=2).
But if we remove 'a'&'a', then the final result after considering the char 'a' at position i is bca with RLE=bca (size=3).
So, this example illustrates why it is important to care about which chars are dropped from dp[i-1][j] in case 2 above. 

Since we are anyway retaining the char at position 'i' in case 2, it makes sense to keep all other occurances of it as well
from 0 to i-1 so that they can be compressed in the same RLE. And any distinct chars that occur in between can be removed
as ong as our j > 0. And we need to do this for every prefix substring from 0 to i-1 to find out which one yields the best result. 
*/
class Solution
{
    public:    
    int getLengthOfOptimalCompression(string s, int k)
    {
        dp = vector(n+1, vector(k+1, INT_MAX));
        for (int i = 0; i < dp[0].size(); ++i) dp[0][i] = 0;

        int n = s.size();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                if (j > 0) dp[i][j] = dp[i-1][j-1];
                int removed = 0, cnt = 0;
                for (int p = i; p > 0; --p)
                {
                    if (s[p - 1] == s[i - 1]) 
                    {
                        ++cnt;
                    }
                    else
                    {
                        ++removed;
                        if (removed > j) break;
                    }
                    dp[i][j] = min(dp[i][j], dp[p-1][j-removed] + numlen(cnt));
                }
            }
        }
        
        return dp[n][k];
    }
    
    private:    
    int numlen(int n)
    {
        if (n == 0) return 0;
        else if (n == 1) return 1;
        else if (n <= 9) return 2;
        else if (n <= 99) return 3;
        else return 4;
    }
    
    vector<vector<int>> dp;
};

int main()
{
    Solution o;
    //int res = o.getLengthOfOptimalCompression("aabbaa", 2);
    int res = o.getLengthOfOptimalCompression("aaabcccd", 2);    
    cout << "res: " << res << "\n";
    return 0;
}