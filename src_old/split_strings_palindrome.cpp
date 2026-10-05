// 1616. Split Two Strings to Make Palindrome

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    bool checkPalindromeFormation(string a, string b) 
    {
        const int n = a.size();
        if (n < 2) return true;
        return checkPalidrome(a, b) || checkPalidrome(b, a);
    }
    
private:
    bool checkPalidrome(const string& s, const string& t)
    {
        int i = 0, j = s.size() - 1, mid = s.size() / 2;
        while (s[i] == t[j] && i <= j)
        {
            ++i;
            --j;
        }
        
        if (i >= mid) return true;
        else
        {
            return isSubstrPalindrome(s, i, j) || isSubstrPalindrome(t, i, j);
        }
        
        return false;
    }
    
    bool isSubstrPalindrome(const string& s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};

int main()
{
    //string a = "x", b = "y";
    //string a = "abdef", b = "fecab";
    //string a = "ulacfd", b = "jizalu";
    //string a = "xbdef", b = "xecab";
    string a = "aejbaalflrmkswrydwdkdwdyrwskmrlfqizjezd", b = "uvebspqckawkhbrtlqwblfwzfptanhiglaabjea";
    Solution o;
    bool res = o.checkPalindromeFormation(a, b);
    cout << "res: " << (res ? "true" : "false") << "\n";
    return 0;
}