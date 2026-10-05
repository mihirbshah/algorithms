// 301. Remove Invalid Parentheses

#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <vector>
#include "util.h"

using namespace std;

class Solution 
{
public:
    /*
    The basic idea is to check if a string is valid, then add that to the result and 
    don't process it any further. 
    If it is not valid, then generate its substrings by removing 1 char at a time, and
    apply the same logic on those substrings.
    This will form a BFS tree where,
    level 0 indicates no chars removed
    level 1 indicates 1 char removed
    level 2 indicates 2 char removed etc.
    
    The important thing here is, once we find a valid string at one level, then we don't need
    to process any further levels since the question asks for minimum number of 
    parantheses to be removed to form a valid string. This is ensures by this clause -
                else if (res.empty())
    
    It is possible that for e.g. at level 1, we had 3 strings out of which 1st string was invalid,
    so we added its substrings at level 2 in the queue. And later we found that 2nd and 3rd strings
    at level 1 are valid. So ideally, we should not process the substrings from level 2. However the 
    code below still processes them. But this is ok because of following reasons -
    1. For a string to be valid, it has to be of even length
    2. If the string at level 0 was of odd length, and we found some valid strings at level 1, then the level 2
    substrings will be again of odd length. So they can never yield a valid string.
    3. If the string at level 0 was even length, then we can never find a valid string at level 1 since they'd
    all be of odd length. So the earliest we can find a valid string now will be at level 2. 
    */
    vector<string> removeInvalidParentheses(string s) 
    {
        queue<string> q;
        q.push(s);
        string qs;
        vector<string> res;
        unordered_set<string> seen;
        
        while (!q.empty())
        {
            qs = q.front();
            q.pop();
            
            if (seen.count(qs)) continue;
            seen.insert(qs);
            
            if (isValid(qs)) res.push_back(qs);
            else if (res.empty())
            {
                for (int i = 0; i < qs.size(); ++i)
                {
                    if (qs[i] != '(' && qs[i] != ')') continue;
                    q.push(qs.substr(0, i) + qs.substr(i + 1));
                }
            }
        }
        
        return res;
    }
    
private:
    bool isValid(const string& s)
    {
        int count = 0;
        for (auto c : s)
        {
            if (c == '(') ++count;
            else if (c == ')') --count;
            if (count < 0) return false;
        }
        return !count;
    }
};

int main()
{
    string s = "()())()";
    //string s = "(a)())()";
    //string s = ")(";
    Solution o;
    vector<string> res = o.removeInvalidParentheses(s);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}