// 3. Longest Substring Without Repeating Characters

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        int longest = 0, lastLongest = 1;
        const int n = s.size();
        unordered_set<char> unique;
        
        for (int i = 0; i < n; ++i)
        {
            if (i - 1 >= 0) unique.erase(s[i - 1]);
            int j = i - 1 + lastLongest;
            while (j < n && !unique.count(s[j])) unique.insert(s[j++]);
            lastLongest = unique.size();
            longest = max(longest, lastLongest);
            //cout << "i: " << i << ", longest: " << longest << "\n";
        }
        
        return longest;
    }
};

int main()
{
    Solution o;
    int res = o.lengthOfLongestSubstring("");
    cout << "res: " << res << "\n";
    return 0;
}