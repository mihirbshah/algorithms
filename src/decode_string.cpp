// 394. Decode String

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution 
{
public:
    string decodeString(string s) 
    {
        stack<string> stk;
        const int n = s.size();
        for (int i = 0; i < n;)
        {
            if (isdigit1(s[i]))
            {
                string t(1, s[i++]);
                while (isdigit1(s[i])) 
                {
                    t += s[i];
                    ++i;
                }
                stk.push(t);
            }
            else if (s[i] == '[') 
            {
                ++i;
                continue;
            }
            else if (isalpha1(s[i]))
            {
                string t(1, s[i++]);
                while (isalpha1(s[i])) 
                {
                    t += s[i];
                    ++i;
                }
                stk.push(t);
            }
            else if (s[i] == ']')
            {
                ++i;
                string s;
                while (!stk.empty())
                {
                    if (isalpha1(stk.top()[0]))
                    {
                        s = stk.top() + s;
                        stk.pop();
                    }
                    else break;
                }
                
                int cnt = 0;
                if (isdigit1(stk.top()[0]))
                {
                    cnt = stoi(stk.top());
                    stk.pop();
                }
                string ts = s;
                while (--cnt > 0)
                {
                    ts += s;
                }
                stk.push(ts);
            }
        }
        
        string res;
        while (!stk.empty())
        {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
    
private:
    bool isdigit1(char c)
    {
        return c >= '0' && c <= '9';
    }
    
    bool isalpha1(char c)
    {
        return c >= 'a' && c <= 'z';
    }
};

int main()
{
    string s = "3[a2[c]]";
    cout << "s: " << s << "\n";
    Solution o;
    string res = o.decodeString(s);
    cout << "res: " << res << "\n";
    return 0;
}