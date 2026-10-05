// 242. Valid Anagram

#include <iostream>
#include <string>
#include <unordered_multiset>

using namespace std;

class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        return unordered_multiset<char>(s.begin(), s.end()) == unordered_multiset<char>(t.begin(), t.end());
    }
};

int main()
{
    return 0;
}