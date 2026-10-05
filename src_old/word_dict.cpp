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

/*
Trie based solution, copied from - https://leetcode.com/problems/design-add-and-search-words-data-structure/discuss/59552/C%2B%2B-Trie

class TrieNode {
public:
    TrieNode *next[26]{};
    bool is_leaf = false;
    TrieNode *get(char c) { return next[c - 'a']; }
    void add(char c) { next[c - 'a'] = new TrieNode; }
};

class WordDictionary {
public:
    WordDictionary() : root(new TrieNode) {}
    void addWord(const string &word) {
        auto p = root;
        for (auto c : word) {
            if (!p->get(c)) p->add(c);
            p = p->get(c);
        }
        p->is_leaf = true;
    }
    bool search(const string &word) {  return search(word, 0, root); }
private:
    bool search(const string &word, int pos, TrieNode *root) {
        if (pos == word.size()) return root->is_leaf;
        if (word[pos] != '.') {
            root = root->get(word[pos]);
            return root ? search(word, pos + 1, root) : false;
        }
        for (auto i = 0; i < 26; ++i)
            if (root->next[i] && search(word, pos + 1, root->next[i]))
                return true;
        return false;
    }
    TrieNode *root;
};

*/

int main()
{
    return 0;
}