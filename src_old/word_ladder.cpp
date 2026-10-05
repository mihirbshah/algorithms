// 127. Word Ladder

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// Solution gets TLE'ed because of recursion. But the logic is correct. Just need to implement this using queue.
// For Iterative queue based approach, refer - https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS

class Solution 
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {    
        int res = ladderLengthRecurse(beginWord, endWord, wordList, 1, {});
        return res == INT_MAX ? 0 : res;
    }
    
private:
    bool isOneLetterDiff(const string& w1, const string& w2)
    {
        int c = 0;
        for (int i = 0; i < w1.size(); ++i) c += (w1[i] != w2[i]);
        return c == 1;
    }
    
    vector<int> oneLetterDiffWords(const string& word, const vector<string>& wordList, unordered_set<int> skipIndices)
    {
        vector<int> res;
        for (int i = 0; i < wordList.size(); ++i)
        {
            if (skipIndices.count(i)) continue;
            if (isOneLetterDiff(word, wordList[i])) res.push_back(i);
        }
        return res;
    }
    
    int ladderLengthRecurse(const string& word, const string& endWord, const vector<string>& wordList, int len, unordered_set<int> skipIndices)
    {
        if (word == endWord) return len;
        
        int minLen = INT_MAX;
        for (auto i : oneLetterDiffWords(word, wordList, skipIndices))
        {
            skipIndices.insert(i);
            minLen = min(minLen, ladderLengthRecurse(wordList[i], endWord, wordList, len + 1, skipIndices));
            skipIndices.erase(i);
        }
        return minLen;
    }
};

int main()
{
    string bw = "hit", ew = "cog"; vector<string> wl({"hot","dot","dog","lot","log","cog"});
    Solution o;
    int res = o.ladderLength(bw, ew, wl);
    cout << "res: " << res << "\n";
    return 0;
}