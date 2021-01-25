// 211. Design Add and Search Words Data Structure

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class WordDictionary 
{
public:
    /** Initialize your data structure here. */
    WordDictionary() : words(vector<unordered_set<string>>(501, unordered_set<string>({})))
    {
    }
    
    void addWord(string word) 
    {
        words[word.size()].insert(word);
    }
    
    bool search(string word) 
    {
        const unordered_set<string>& wset = words[word.size()];
        for (const auto& s : wset)
        {
            if (match(s, word)) return true;
        }
        return false;
    }
    
private:
    bool match(const string& str, const string& regex)
    {
        const int n = str.size();
        for (int i = 0; i < n; ++i)
        {
            if (regex[i] == '.' || str[i] == regex[i]) continue;
            else return false;
        }
        return true;
    }
    
    vector<unordered_set<string>> words;
};

int main()
{
    return 0;
}