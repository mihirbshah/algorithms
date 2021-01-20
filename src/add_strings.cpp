// 415. Add Strings

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    string addStrings(string num1, string num2) 
    {
        string res;
        int s1 = num1.size(), s2 = num2.size();
        int l = min(s1, s2);
        int carry = 0;
        string base;
        for (int i = s1 - 1, j = s2 - 1, k = l - 1; k >= 0; --k)
        {
            cout << "char1: " << num1[i] << ", char2: " << num2[j] << "\n";
            base = to_string(carry + (num1[i] - '0') + (num2[j] - '0'));
            if (base.size() > 1)
            {
                res.push_back(base[1]);
                carry = (base[0] - '0');
            }
            else
            {
                res.push_back(base[0]);
                carry = 0;
            }
            --i; --j;
        }
        
        const string& bigger = s1 > s2 ? num1 : (s2 > s1 ? num2 : "");
        if (bigger.size())
        {
            const int m = bigger.size() - l;
            for (int i = m - 1; i >= 0; --i)
            {
                cout << "char1: " << bigger[i] << "\n";
                base = to_string(carry + (bigger[i] - '0'));
                if (base.size() > 1)
                {
                    res.push_back(base[1]);
                    carry = (base[0] - '0');
                }
                else
                {
                    res.push_back(base[0]);
                    carry = 0;
                }
            }
        }
        
        if (carry) res.push_back(carry + '0');
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    //string n1 = "98", n2 = "9";
    //string n1 = "123", n2 = "456";
    string n1 = "408", n2 = "5";
    Solution o;
    string res = o.addStrings(n1, n2);
    cout << "res: " << res << "\n";
    return 0;
}