// 680. Valid Palindrome II


#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    bool validPalindrome(string s)
    {
        return _validPalindrome(s, 0, s.size() - 1, 0);
    }
    
    bool _validPalindrome(string s, int i, int j, int count) 
    {
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                ++i; --j;
            }
            else
            {
                if (count == 1) return false;
                ++count;
                return _validPalindrome(s, i + 1, j, count) || _validPalindrome(s, i, j - 1, count);
            }
        }
        return true;
    }
    
};

/*
class Solution 
{
public:
    bool validPalindrome(string s) 
    {
        return match(s, 0, s.size() - 1, false);
    }
    
private:
    bool match(const string& s, int left, int right, bool erased)
    {
        if (left >= right) return true;
        
        if (s[left] != s[right])
        {
            return erased ? false : match(s, left + 1, right, true) || match(s, left, right - 1, true);
        }
        
        return match(s, left + 1, right - 1, erased);
    }
};
*/
int main()
{
    //string s = "aba";
    //string s = "abca";
    string s = "abcdcab";
    Solution o;
    bool res = o.validPalindrome(s);
    cout << "res: " << res << "\n";
    return 0;
}