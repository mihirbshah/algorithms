// 1400. Construct K Palindrome Strings

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    bool canConstruct(string s, int k) 
    {
        if (s.size() < k) return false;
        unordered_map,char, int> cnt;
        for (auto c : s) ++cnt[c];
        for (const auto& [k, v] : cnt) oddchars += (v % 2);
        return oddchars <= k;
    }
};

int main()
{
    return 0;
}