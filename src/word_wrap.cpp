/*
QUESTION 1: WORD WRAP
Given a list of words and a max line length, create a function that returns a wrapped list with dash separated words
EXAMPLE
input:
["Tom","is","a","dragon","that","breathes","fire"]
maximum length of characters per line = 9

output:
["Tom-is-a-",
"dragon-t-",
"hat-brea-",
"thes-fire"]

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void fullJustify(vector<string>& words, int maxWidth) {
    vector<string> res;
    int  l = 0, j = 0;
    for(int i = 0; i < words.size();) 
    {
        int width = 0;
        string temp;
        while (width < maxWidth && i < words.size()) 
        {
            for(j = l; (j < words[i].size() && width < maxWidth - 1); j++) 
            {
                temp += words[i][j];
                width++;
                l = 0;
            }
           
            if (width == (maxWidth - 1) && j < words[i].size()) 
            {
                if(i != words.size() - 1) 
                    temp += '-';
                else
                    temp += words[i][j++];
                l = j;
            }
            else 
            {
                if(i != words.size() - 1)
                    temp += '-';
                i++;
            }
            width++;
        }
        res.push_back((temp));
    }
    
    for(auto it = res.begin(); it != res.end(); it++) {
        
        cout << *it << endl;
    }
}


int main()
{
    //vector<string> s = {"Tom","is","a","dragonfly","that","breathes","fire"};
    vector<string> s = {"Tom","is","a","dragonfly","that","breathesfire"};
    //vector<string> s = {"Tom","is","a","dragon","that","breathes","fire"};
    fullJustify (s, 9);
    return 0;
}
