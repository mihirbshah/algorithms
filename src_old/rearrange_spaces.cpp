// 1592. Rearrange Spaces Between Words

#include <iostream>
#include <string>

using namespace std;

class Solution 
{
public:
    string reorderSpaces(string text) 
    {
        const int n = text.size();
        int spaces = 0, words = 0, lastCharIndex = -1;
        for (int i = 0; i < n; ++i)
        {
            spaces += (text[i] == ' ');
            words += (text[i] != ' ' && (!i || text[i - 1] == ' '));
            lastCharIndex = (text[i] != ' ' ? i : lastCharIndex);
        }
        
        int spacesBetweenWords = (words > 1 ? spaces / (words - 1) : 0);
        int extraSpaces = (words > 1 ? spaces % (words - 1) : spaces);
        string inBetweenSpaces(spacesBetweenWords, ' ');
        string endSpaces(extraSpaces, ' ');
        string res;
        for (int i = 0; i < n;)
        {
            while (text[i] == ' ') ++i;
            while (i < n && text[i] != ' ') 
            {
                res += text[i];
                ++i;
            }
            
            if (i < lastCharIndex) res += inBetweenSpaces;            
        }
        
        res += endSpaces;
        return res;
    }
};

int main()
{
    //string s = "  this   is  a sentence ";
    //string s = " practice   makes   perfect";
    //string s = "hello   world";
    //string s = "  walks  udp package   into  bar a";
    string s = " a ";
    Solution o;
    string res = o.reorderSpaces(s);
            for (int i = 0; i < res.size(); ++i)
            {
                if (res[i] == ' ') cout << "#";
                else cout << res[i];
            }
            cout << "\n";

    return 0;
}