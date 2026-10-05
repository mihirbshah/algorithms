#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Solution
{
private:
    string s1, s2, evil;
    int n;
    int MOD = 1e9 + 7;

    int goodString(string pre, int pos)
    {
        if (string::npos != pre.find(evil)) return 0;
        if (pos >= n) 
        {
            if (pre > s2 || pre < s1) return 0;
            cout << pre << "\n";
            return 1;
        }
        
        long cnt = 0;
        for (char c = 'a'; c <= 'z'; ++c)
        {
            cnt = (cnt + goodString(pre + c, pos + 1)) % MOD;
        }
        
        return cnt;
    }
    
public:
    
    int findGoodStrings(int n_, string s1_, string s2_, string evil_)
    {
        s1 = s1_; s2 = s2_; evil = evil_; n = n_;
        long cnt = 0;
        string pre = "";
        int i = 0;
        for (; (i < n) && (s1[i] == s2[i]); ++i);
        if (string::npos != (s1_.substr(0, i)).find(evil)) return 0;
        s1 = s1_.substr(i, s1_.length() - i);
        s2 = s2_.substr(i, s2_.length() - i);
        for (char c = s1[0]; c <= s2[0]; ++c)
        {
            cnt = (cnt + goodString(pre + c, i + 1)) % MOD;
        }
        
        return cnt;
    }    
};

int main()
{
    Solution o;
    //Solution o3(2, "gx", "gz", "x");
    //int res = o.findGoodStrings(2, "aa", "da", "b");
    int res = o.findGoodStrings(2, "aa", "da", "b");
    //int res = o.findGoodStrings(3, "szc", "zyi", "p");
    //int res = o.findGoodStrings(2, "gx", "gz", "x");
    //int res = o.findGoodStrings(8, "leetcode", "leetgoes", "leet");
    cout << "res: " << res << "\n";
    return 0;
}