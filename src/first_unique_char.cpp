// 387. First Unique Character in a String

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int firstUniqChar(string s) 
    {
        unordered_map<char, int> index;
        for (int i = 0; i < s.size(); ++i)
        {
            if (index.count(s[i])) index[s[i]] = INT_MAX;
            else index[s[i]] = i;
        }
        
        int res = INT_MAX;
        for (auto& [k, v] : index)
        {
            res = min(res, v);
        }
        
        return res;
    }
};

int main()
{
    return 0;
}