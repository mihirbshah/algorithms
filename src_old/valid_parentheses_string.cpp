// 678. Valid Parenthesis String

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*class Solution 
{
public:
    bool checkValidString(string s) 
    {
        vector<vector<bool>> dp(100, vector<bool>(100, false));
        return dfs(s, 0, 0, dp);
    }
    
private:
    bool dfs(const string& s, int pos, int cnt, vector<vector<bool>>& dp)
    {
        if (pos >= s.size()) return !cnt;
        if (cnt < 0) return false;
        if (dp[pos][cnt]) return true;
        
        if (s[pos] == '(') return dp[pos][cnt] = dfs(s, pos + 1, cnt + 1, dp);
        else if (s[pos] == ')') return dp[pos][cnt] = dfs(s, pos + 1, cnt - 1, dp);
        else if (s[pos] == '*') return dp[pos][cnt] = dfs(s, pos + 1, cnt, dp) || dfs(s, pos + 1, cnt + 1, dp) || dfs(s, pos + 1, cnt - 1, dp);
        return false;
    }
};
*/

class Solution 
{
public:
    bool checkValidString(string s) 
    {
        int cmin = 0, cmax = 0; // open parentheses count in range [cmin, cmax]
        for (char c : s) 
        {
            if (c == '(') 
            {
                cmax++;
                cmin++;
            } 
            else if (c == ')') 
            {
                cmax--;
                cmin--;
            } 
            else if (c == '*') 
            {
                cmax++; // if `*` become `(` then openCount++
                cmin--; // if `*` become `)` then openCount--
                // if `*` become `` then nothing happens
                // So openCount will be in new range [cmin-1, cmax+1]
            }
            
            if (cmax < 0) return false; // Currently, don't have enough open parentheses to match close parentheses-> Invalid
                                        // For example: ())(
            cmin = max(cmin, 0);   // It's invalid if open parentheses count < 0 that's why cmin can't be negative
        }
        
        return cmin == 0; // Return true if can found `openCount == 0` in range [cmin, cmax]
    }
};


int main()
{
    return 0;
}