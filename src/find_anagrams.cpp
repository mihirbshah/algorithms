// 438. Find All Anagrams in a String

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "util.h"

using namespace std;

class Solution 
{
public:
    vector<int> findAnagrams(string s, string p) 
    {
        using CharMap = unordered_map<char, int>;
        CharMap pmap, smap;
        
        for (int c = 'a'; c <= 'z'; ++c)
        {
            pmap[c] = 0; smap[c] = 0;
        }
        
        for (const auto& c : p) ++pmap[c];
        
        const int sn = s.size(), pn = p.size();
        int i = 0;
        for (; i < pn; ++i) ++smap[s[i]];
        
        vector<int> indices;
        for (; i < sn; ++i)
        {
            if (pmap == smap) indices.push_back(i - pn);
            --smap[s[i - pn]];
            ++smap[s[i]];
        }
        
        if (pmap == smap) indices.push_back(i - pn);
        
        return indices;
    }    
};

int main()
{
    string s = "cbaebabacd", p = "abc";
    //string s = "abab", p = "ab";
    Solution o;
    vector<int> res = o.findAnagrams(s, p);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}