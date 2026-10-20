#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindromic(string s) {
        string result = "";
        for (char c : s) {
            result.append(std::bitset<8>(97 + (c - 'a')).to_string());
        }

        return std::equal(result.begin(), result.begin() + result.size() / 2, result.rbegin());
    }
};