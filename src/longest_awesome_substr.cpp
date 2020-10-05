#include <iostream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/find-longest-awesome-substring/

2 different solutions described below - longestAwesome and longestAwesome1.
Neither work on Leetcode, fails on time complexity. 
*/

class Solution
{
public:
    Solution()
    {
        _charCounts = vector<int>(10);
    }
    void populateCharCounts(const string& s)
    {
        for (auto c : s)
        {
            ++_charCounts[c - '0'];
        }
    }
    
    bool isSubstrPalindrome(const string& s, int i, int j)
    {
        bool evenLen = (j - i + 1) % 2 == 0;
        vector<int> v = _charCounts;
        for (int k = 0; k < i; ++k) --v[s[k] - '0'];
        for (int k = j+1; k < s.size(); ++k) --v[s[k] - '0'];
        int oddCnt = 0;
        for (auto cnt : v)
        {
            if (cnt % 2) ++oddCnt;
        }
        
        return evenLen ? (oddCnt == 0) : (oddCnt == 1);
    }
    
    int longestAwesome1(string s)
    {
        populateCharCounts(s);
        for (int i = s.size(); i > 0; --i)
        {
            for (int j = 0; j + i <= s.size(); ++j)
            {
                if (isSubstrPalindrome(s, j, j + i - 1)) return i;
            }
        }
        return 1;
    }
    
    int longestAwesome(string s)
    {
        populateCharCounts(s);
        int oddCnt = 0;
        for (auto cnt : _charCounts)
        {
            if (cnt % 2) ++oddCnt;
        }
        bool evenLen = s.size() % 2 ? false : true;
        int maxAwesomeSubStrLen = 1;
        if ((evenLen && !oddCnt) || (!evenLen && oddCnt == 1))
        {
            return s.size();
        }
        int n = s.size();
        int substrlen = 0, currOddCnt = 0;
        vector<int> currCharCounts;
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                --_charCounts[s[i-1] - '0'];
                if (_charCounts[s[i-1] - '0'] % 2) ++oddCnt;
                else if (oddCnt > 0) --oddCnt;
            }
            
            currOddCnt = oddCnt;
            currCharCounts = _charCounts;
            for (int j = n-1; j >= i; --j)
            {
                if (j < n-1)
                {
                    //cout << "\t currCharCounts[ " << s[j+1] - '0' << "]: "<< currCharCounts[s[j+1] - '0'] << "\n";
                    --currCharCounts[s[j+1] - '0'];
                    if (currCharCounts[s[j+1] - '0'] % 2) ++currOddCnt;
                    else if (currOddCnt > 0) --currOddCnt;
                    //cout << "\t currCharCounts[ " << s[j+1] - '0' << "]: "<< currCharCounts[s[j+1] - '0'] << "\n";   
                }
                substrlen = j - i + 1;
                evenLen = substrlen % 2 ? false : true;
                if (((evenLen && !currOddCnt) || (!evenLen && currOddCnt == 1)) && maxAwesomeSubStrLen < substrlen)
                {
                    maxAwesomeSubStrLen = substrlen;
                }
                //cout << "i: " << i << ", j: " << j << ", currOddCnt: " << currOddCnt << ", maxAwesomeSubStrLen: " << maxAwesomeSubStrLen << "\n";
            }
        }
        
        return maxAwesomeSubStrLen;
    }
    
private:
    vector<int> _charCounts;
};

int main()
{
    Solution s;
    //int res = s.longestAwesome("3242415");
    //int res = s.longestAwesome("12345678");
    //int res = s.longestAwesome("213123");
    //int res = s.longestAwesome("00");
    int res = s.longestAwesome("51224");
    cout << "res: " << res << "\n";
    return 0;
}