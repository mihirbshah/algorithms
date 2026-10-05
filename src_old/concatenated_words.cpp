// 472. Concatenated Words

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "util.h"

using namespace std;

// working solution but TLE'ed. Very close to actual answer, but don't have time to debug in detail
class Solution 
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) 
    {
        vector<string> res;
        unordered_set<string> skipwords;
        sort(words.begin(), words.end(), [&](const string& w1, const string& w2){ return w1.size() > w2.size(); });
        for (auto w : words)
        {
            if (concatenatedWord(words, w, skipwords, true)) 
            {
                res.push_back(w);
                dp.insert(w);
                skipwords.insert(w);
            }
            
        }
        
        return res;
    }
    
private:
    
    bool concatenatedWord(const vector<string>& words, string word, unordered_set<string> skipwords, bool primary)
    {
        //cout << "Current word is: " << word << "\n";
        if (!primary && !word.size()) return true;
        for (auto w : words)
        {
            if ((primary && w == word) || skipwords.count(w)) continue;
            vector<size_t> res = substrPos(word, w);
            for (auto pos : res)
            {
                skipwords.insert(w);
                string w1 = word.substr(0, pos);
                string w2 = word.substr(pos + w.size(), word.size() - (pos + w.size() - 1));
                //cout << "word: " << word << ", w: " << w << ", w1: " << w1 << ", w2: " << w2 << "\n";
                if ((dp.count(w1) || concatenatedWord(words, w1, skipwords, primary && false)) && 
                    (dp.count(w2) || concatenatedWord(words, w2, skipwords, primary && false))) 
                {
                    dp.insert(w1);
                    dp.insert(w2);
                    return true;
                }
                skipwords.erase(w);
            }
        }
        return false;
    }
    
    vector<size_t> substrPos(const string& word, const string& s)
    {
        vector<size_t> res;
        size_t pos = word.find(s);
        while (pos != string::npos)
        {
            res.push_back(pos);
            pos = word.find(s, pos + s.size());
        }
        return res;
    }
    
    unordered_set<string> dp;
};

int main()
{
    //vector<string> words({"cat","dog","catdog"});
    vector<string> words({"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"});
    Solution o;
    vector<string> res = o.findAllConcatenatedWordsInADict(words);
    cout << "result: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}