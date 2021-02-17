// 1576. Replace All ?'s to Avoid Consecutive Repeating Characters

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Solution 
{
public:
    string modifyString(string s) 
    {
        const int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != '?') continue;
            char c = 'a' + rand() % 26;
            while (true)
            {
                if ((i > 0 && c == s[i - 1]) || (i < n - 1 && c == s[i + 1])) c = 'a' + rand() % 26;
                else break;
            }
            s[i] = c;
        }
        return s;
    }
};

int main()
{
    //string s = "?zs";
    //string s = "ubv?w";
    //string s = "j?qg??b";
    string s = "??yw?ipkj?";
    Solution o;
    string res = o.modifyString(s);
    cout << "res: " << res << "\n";
    return 0;
}
