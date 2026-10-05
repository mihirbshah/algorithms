// 1249. Minimum Remove to Make Valid Parentheses

#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        unordered_set<int> removals;
        const int l = s.size();
        for (int i = 0; i < l; ++i)
        {
            if (s[i] == '(') 
            {
                _stk.push(i);
                continue;
            }
            else if (s[i] == ')')
            {
                if (_stk.empty()) removals.insert(i);
                else _stk.pop();
            }
        }
                
        while(!_stk.empty())
        {
            removals.insert(_stk.top());
            _stk.pop();
        }
        
        string res;
        for (int i = 0; i < l; ++i) 
        {
            if (!removals.count(i)) res += s[i];
        }
        
        return res;    
    }

private:
    stack<int> _stk;
    
};

int main()
{
    //string s = "lee(t(c)o)de)";
    //string s = "a)b(c)d";
    //string s = "))((";
    string s = "(a(b(c)d)";
    Solution o;
    string res = o.minRemoveToMakeValid(s);
    cout << "res: " << res << "\n";
    return 0;
}