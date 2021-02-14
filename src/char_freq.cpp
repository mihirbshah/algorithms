// 1647. Minimum Deletions to Make Character Frequencies Unique

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Solution 
{
public:
    int minDeletions(string s) 
    {
        vector<list<char>> freqchar(1e5 + 1e5);
        vector<int> charfreq(26, 0);
        
        for (auto c : s) ++charfreq[c - 'a'];
        for (int i = 0; i < 26; ++i) freqchar[charfreq[i]].push_front(i + 'a');
        int del = 0;
        for (int i = freqchar.size() - 1; i > 0; --i)
        {
            if (freqchar[i].size() <= 1) continue;
            while (freqchar[i].size() > 1)
            {
                char c = freqchar[i].front();
                freqchar[i].pop_front();
                freqchar[i - 1].push_front(c);
                ++del;
            }
        }
        return del;
    }
};

int main()
{
    string s = "abcabc";
    Solution o;
    int res = o.minDeletions(s);
    cout << "res: " << res << "\n";
    return 0;
}