// 1614. Maximum Nesting Depth of the Parentheses

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    int maxDepth(string s) 
    {
        int cnt = 0, maxc = INT_MIN;
        for (auto c: s)
        {
            if (c == '(') ++cnt;
            if (c == ')') --cnt;
            maxc = max(maxc, cnt);
        }
        return maxc;
    }
};

int main()
{
    return 0;
}