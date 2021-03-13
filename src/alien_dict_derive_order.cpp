// 269. Alien Dictionary

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution
{
public:
    string alienOrder(vector<string>& words) 
    {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        const int n = words.size();
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < words[i].size(); ++j) indegree[words[i][j]] = 0;
        }
        
        for (int i = 0; i < n - 1; ++i)
        {
            const string& w1 = words[i];
            const string& w2 = words[i + 1];
            const int minlen = min(w1.size(), w2.size());
            for (int j = 0; j < minlen; ++j)
            {
                if (w1[j] != w2[j])
                {
                    auto& vertices = graph[w1[j]];
                    if (!vertices.count(w2[j]))
                    {
                        vertices.insert(w2[j]);
                        ++indegree[w2[j]];
                    }
                    break;
                }
                if (j == minlen - 1 and w1.size() > w2.size()) return "";
            }
        }
        
        queue<char> q;
        for (const auto& [vertex, degree] : indegree)
        {
            if (!degree) q.push(vertex);
        }
        
        string res;
        while (!q.empty())
        {
            char c = q.front();
            res += c;
            q.pop();
            for (const auto& v : graph[c])
            {
                --indegree[v];
                if (!indegree[v]) q.push(v);
            }
        }
        
        return res.size() == indegree.size() ? res : "";
    }
};

int main()
{
    //vector<string> words({"wrt","wrf","er","ett","rftt"});
    vector<string> words({"ax", "by", "cz"});
    Solution o;
    string res = o.alienOrder(words);
    cout << "res: " << res << "\n";
    return 0;
}