// 1528. Shuffle String

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Cyclic SORT solution without using extra space - 
// https://leetcode.com/problems/shuffle-string/discuss/755923/Used-Cyclic-Sort-with-O(1)-SPACE-and-O(N)-Time-complexity



class Solution 
{
public:
    string restoreString(string s, vector<int>& indices) 
    {
        string res(s);
        for (int i = 0; i < s.size(); ++i) res[indices[i]] = s[i];
        return res;
    }
};

int main()
{
    
    return 0;
}