// 1169. Invalid Transactions

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "util.h"

using namespace std;

class Solution 
{
public:
    vector<string> invalidTransactions(vector<string>& transactions) 
    {
        vector<vector<string>> trans;
        for (auto& t : transactions)
        {
            trans.push_back(split(t, ","));
        }
        
        auto comp = [&](vector<string>& v1, vector<string>& v2)
        {
            if (v1[0] != v2[0]) return v1[0] < v2[0];
            else if (v1[1] != v2[1]) return v1[1] < v2[1];
            else if (v1[3] != v2[3]) return v1[3] < v2[3];
            return v1[2] < v2[2];
        };
        
        sort(trans.begin(), trans.end(), comp);
        
        unordered_set<int> res;
        
        const int n = trans.size();
        for (int i = 0; i < n; ++i)
        {
            cout << "name i: " << trans[i][0] << ", city i: " << trans[i][3] << ", time i: " << trans[i][1] << "\n";
            if (stoi(trans[i][2]) > 1000) res.insert(i);
            for (int j = i + 1; j < n; ++j)
            {
                cout << "name j: " << trans[j][0] << ", city j: " << trans[j][3] << ", time j: " << trans[j][1] << "\n";
                if (trans[i][0] != trans[j][0]) break;
                if (trans[i][3] == trans[j][3]) continue;
                const int t1 = stoi(trans[i][1]), t2 = stoi(trans[j][1]);
                if (abs(t1 - t2) <= 60)
                {
                    res.insert(i);
                    res.insert(j);
                }
            }
        }
        
        vector<string> invalid;
        
        for (auto i : res)
        {
            invalid.push_back(join(trans[i], ","));
        }
        
        return invalid;
    }
    
private:
    vector<string> split(string s, string d)
    {
        vector<string> res;
        int start = 0, end = s.find(d);
        while(end != string::npos)
        {
            res.push_back(s.substr(start, end - start));
            start = end + d.size();
            end = s.find(d, start);
        }
        res.push_back(s.substr(start, end - start));
        return res;
    }
    
    string join(vector<string> v, string d)
    {
        string ret;
        const int n = v.size();
        for (int i = 0; i < n; ++i)
        {
            ret += v[i];
            if (i != n - 1) ret += d;
        }
        return ret;
    }
};

int main()
{
    vector<string> v({"alice,20,800,mtv","alice,50,100,beijing"});
    Solution o;
    vector<string> res = o.invalidTransactions(v);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}