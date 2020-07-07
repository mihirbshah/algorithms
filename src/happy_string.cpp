#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "util.h"

using namespace std;


/*
  https://leetcode.com/problems/longest-happy-string/
  
  Assume that instead of 3 characters, we only have 2 characters. So the problem becomes much more simpler -
  We can arrange the two characters such that we have roughly 2-1-2-1.... pattern i.e. if count(C1) > count(C2),
  then take 2 C1's followed by a C2 followed by 2 C1's etc. At some point, if count(C2) > count(C1), then we reverse
  the roles and do 2 C2's followed by a C1 etc. 
  
  For 3 characters, we can follow the same approach as for 2 characters by handling 2 characters at a time. In order to 
  do this, we need to handle the two characters with highest count and leave aside the 3rd character for now.
  At some point the count one or both of the two characters will be lesser than the 3rd character, and that time, we can handle
  the 3rd character as well. 
*/
string _longestDiverseString(int lg, int med, int sm, char ch_lg = 'a', char ch_med = 'b', char ch_sm = 'c') {
    // Following two IF conditions literally just ensure that the order a >= b >= c is observed to 
    // enable us to handle 2 characters at a time.
    if (lg < med)
        return _longestDiverseString(med, lg, sm, ch_med, ch_lg, ch_sm);
    if (med < sm)
        return _longestDiverseString(lg, sm, med, ch_lg, ch_sm, ch_med);
    
    // If we have exhausted all of the 2nd character, then just repeat the 1st character for min(2, a) times
    if (med == 0)
        return string(min(2, lg), ch_lg);
    
    // Otherwise, pick min(2, a) number of 1st character interspersed with 0/1 number of 2nd character
    auto use_lg = min(2, lg), use_med = lg - use_lg >= med ? 1 : 0; 
    
    // Generate the string so far and append the leftover using a recursive call
    return string(use_lg, ch_lg) +  string(use_med, ch_med) + _longestDiverseString(lg - use_lg, med - use_med, sm, ch_lg, ch_med, ch_sm);
}

/*
string longestDiverseString(int a, int b, int c)
{
    vector<vector<int>> v = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] > b[0];}); 
    string res;
    for (auto sv : v)
    {
        res += string(sv[0], sv[1]);
    }
    int m = c, cnta = 0, cntb = 0, cntc = 0;
    for (int i = 0; i < res.size(); ++i)
    {
        if (res[i] == 'a')
        {
            ++cnta; cntb = cntc = 0;
        }
        if (res[i] == 'b')
        {
            ++cntb; cnta = cntc = 0;
        }
        if (res[i] == 'c')
        {
            ++cntc; cnta = cntb = 0;
        }
        if (cnta >= 3 || cntb >= 3 || cntc >= 3)
        {
            if (cnta >= 3) cnta = 0;
            if (cntb >= 3) cntb = 0;
            if (cntc >= 3) cntc = 0;
            if (m >= res.size())
            {
                return res.substr(0, i-1);
            }
            swap(res[i], res[m]);
            ++m;
        }
    }
    
    return res;
}
*/

int main()
{
    //int a1 = 2, b1 = 3, c1 = 4;
    int a1 = 1, b1 = 1, c1 = 7;
    string res1 = _longestDiverseString(c1, b1, a1, 'c', 'b', 'a');
    //string res2 = longestDiverseString(a1, b1, c1);
    cout << "res1: " << res1 << "\n";
    cout << "res2: " << res2 << "\n";
    return 0;
}