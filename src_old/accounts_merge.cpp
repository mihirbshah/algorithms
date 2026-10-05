// 721. Accounts Merge


#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include "util.h"

using namespace std;

// This is an implementation of union-find disjoint set data structure

class Solution
{
public:
    using VIterator = vector<string>::const_iterator;
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
    {
        const int n = accounts.size();
        unordered_map<string, string> _accountOwner;
        
        for (int i = 0; i < n; ++i)
        {
            makeSet(accounts[i].begin() + 1, accounts[i].end());
            for_each(accounts[i].begin() + 1, accounts[i].end(), [&](const auto& s){ _accountOwner[s] = *accounts[i].begin(); });
        }
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 2; j < accounts[i].size(); ++j)
            {
                _union(accounts[i][j], accounts[i][1]);
            }
        }
        
        unordered_map<string, set<string>> parentToChildren;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                parentToChildren[find(accounts[i][j])].insert(accounts[i][j]);
            }
        }
        
        vector<vector<string>> result;
        for(const auto& [key, val] : parentToChildren)
        {
            vector<string> v({_accountOwner[key]});
            v.insert(v.end(), val.begin(), val.end());
            result.push_back(v);
        }
        
        return result;
    }
    
private:
    void makeSet(VIterator begin, VIterator end)
    {
        while (begin != end)
        {
            _parents[*begin] = *begin;
            ++begin;
        }
    }
    
    string find(const string& s)
    {
        if (_parents[s] == s) return s;
        return find(_parents[s]);
    }
    
    void _union(const string& s1, const string& s2)
    {
        _parents[find(s1)] = find(s2);
    }
    
    unordered_map<string, string> _parents;
};

int main()
{
    vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
    Solution o;
    vector<vector<string>> result = o.accountsMerge(accounts);
    for (auto v : result)
    {
        cout << stringify_container(v.begin(), v.end()) << "\n";
    }
    
    return 0;
}