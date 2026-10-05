// 1297. Maximum Number of Occurrences of a Substring

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution 
{
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) 
    {
        const int n = s.size();
        string t;
        unordered_map<string, int> substrCnt;
        int maxCnt = 0;
        
        
        for (int i = 0; i + minSize - 1 < n; ++i)
        {
            t = s.substr(i, minSize);
            unordered_set<char> unique(t.begin(), t.end());
            /*if (!unique.size()) unique.insert(t.begin(), t.end());
            else
            {
                unique.erase(s[i - 1]);
                unique.insert(s[i + minSize - 1]);
            }*/
            
            if (unique.size() > maxLetters) continue;
            maxCnt = max(maxCnt, ++substrCnt[t]);
            
            /*
            unordered_set<char> unique1(unique);
            cout << "i: " << i << "maxCnt: " << maxCnt << ", unique.size: " << unique1.size() << "\n";
            for (int j = i + minSize; j < i + maxSize && j < n; ++j)
            {
                if (!unique1.count(s[j]))
                {
                    if (substrCnt[t] + 1 > maxLetters) break;
                    unique1.insert(s[j]);
                }
                    
                t += s[j];
                maxCnt = max(maxCnt, ++substrCnt[t]);
                cout << "j: " << i << "maxCnt: " << maxCnt << "\n";
            }*/
        }
        
        return maxCnt;
    }
};

int main()
{
    //string s = "aababcaab"; int maxLetters = 2, minSize = 3, maxSize = 4;
    //string s = "aaaa"; int maxLetters = 1, minSize = 3, maxSize = 3;
    //string s = "aabcabcab"; int maxLetters = 2, minSize = 2, maxSize = 3;
    string s = "eddcdfcfbbbdedbcddebbfbbdddacfecddacabdbddabfffdecebcabfbdeadecffbcdccecdebbaaaeebefbabeaefbebecdfcd"; int maxLetters = 1, minSize = 5, maxSize = 24;
    Solution o;
    int res = o.maxFreq(s, maxLetters, minSize, maxSize);
    cout << "res: " << res << "\n";
    return 0;
}