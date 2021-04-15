// 1347. Minimum Number of Steps to Make Two Strings Anagram

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int minSteps(string s, string t) 
    {
        unordered_map<char, int> scnt, tcnt;
        
        for (const auto& c : s) ++scnt[c];
        for (const auto& c : t) ++tcnt[c];
        int steps = 0;
        for (const auto& [k, v] : scnt)
        {
            if (tcnt.count(k) && scnt[k] > tcnt[k]) steps += scnt[k] - tcnt[k];
            else if (!tcnt.count(k)) steps += scnt[k];
        }
        return steps;
    }
};

int main()
{
    return 0;
}