// 1209. Remove All Adjacent Duplicates in String II

#include <iostream>
#include <string>
#include <unordered_map>
#include "util.h"

using namespace std;

class Solution 
{
public:
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
};

int main()
{
    //string s = "deeedbbcccbdaa"; int k = 3;
    string s = "pbbcggttciiippooaais"; int k = 2;
    Solution o;
    string res = o.removeDuplicates(s, k);
    cout << "res: " << res << "\n";
    return 0;
}