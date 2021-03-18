// 1209. Remove All Adjacent Duplicates in String II

#include <iostream>
#include <string>
#include <unordered_map>
#include "util.h"

using namespace std;

class Solution 
{
public:
    /*
    string removeDuplicates(string s, int k) 
    {
        const int n = s.size();
        unordered_map<char, int> dup;
        bool scan = true;
        for (int i = 0; i + k - 1 < n;)
        {
            cout << "i: " << i << "\n";
            if (scan)
            {
                for (int j = 0; j < k; ++j) ++dup[s[i + j]];
            }
            else
            {
                --dup[s[i - 1]];
                if (!dup[s[i - 1]]) dup.erase(s[i - 1]);
                ++dup[s[i + k - 1]];
            }
            
            //cout << "dup: " << stringify_container(dup.begin(), dup.end()) << "\n";
            if (dup.size() == 1)
            {
                dup.clear();
                for (int j = i; j < i + k; ++j) s[j] = '-';
                i = i + k;
                scan = true;
            }
            else
            {
                ++i;
                scan = false;
            }
        }
        string s1;
        for (int i = 0; i < n; ++i)
            if (s[i] != '-') s1 += s[i];
        
        cout << "s1: " << s1 << "\n";
        return s == s1 ? s : removeDuplicates(s1, k);
    }
    */
    
    string removeDuplicates(string s, int k) 
    {
        cout << "s: " << s << "\n";
        int b = 0, e = 0;
        const int n = s.size();
        unordered_map<char, int> cnt;
        while (e < n)
        {
            //cout << "b: " << b << ", e: " << e << ", cnt.size: " << cnt.size() << "\n";

            if (e - b + 1 <= k)
            {
                ++cnt[s[e]];
                ++e;
                if (cnt.size() == 1 && cnt[cnt.begin()->first] == 3)
                {
                    //cout << "clearing\n";
                    if (cnt.size() == 1) cout << "cnt[" << s[e - 1] << "]: " << cnt[s[e - 1]] << "\n";
                    for (int j = b; j < e; ++j) s[j] = '-';
                    cnt.clear();
                    b = e;
                    //e = b;
                    //continue;
                }
            }
            else
            {
                //++cnt[s[e]];
                --cnt[s[b]];
                if (!cnt[s[b]]) cnt.erase(s[b]);
                ++b;
            }
        }
        
        string s1;
        for (auto c : s)
        {
            if (c != '-') s1 += c;
        }
        
        return s == s1 ? s : removeDuplicates(s1, k);
    }
};

int main()
{
    string s = "deeedbbcccbdaa"; int k = 3;
    //string s = "pbbcggttciiippooaais"; int k = 2;
    Solution o;
    string res = o.removeDuplicates(s, k);
    cout << "res: " << res << "\n";
    return 0;
}