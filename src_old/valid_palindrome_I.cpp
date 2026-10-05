// 125. Valid Palindrome

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Solution 
{
public:
    bool isPalindrome(string s) 
    {
        int i = 0, j = s.size() - 1;
        const int n = s.size();
        while(i <= j)
        {
            while(i < n && !isalnum(s[i])) ++i;
            while(j > 0 && !isalnum(s[j])) --j;
            if (i > j) return true;
            cout << "i: " << s[i] << ", j: " << s[j] << "\n";
            if (toupper(s[i]) != toupper(s[j])) return false;
            ++i; --j;
        }
        
        return true;
    }    
};

int main()
{
    //string s = "A man, a plan, a canal: Panama";
    // string s = "race a car";
    string s = " ";
    Solution o;
    bool res = o.isPalindrome(s);
    cout << "res: " << res << "\n";
    return 0;
}