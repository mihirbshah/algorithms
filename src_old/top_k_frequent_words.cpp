// 692. Top K Frequent Words

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int K) 
    {
        unordered_map<string, int> freq;
        for (const auto& w : words) ++freq[w];
        
        using Pair = pair<string, int>;
        auto comp = [](const Pair& p1, const Pair& p2){ return p1.second > p2.second || (p1.second == p2.second && p2.first > p1.first); };
        using PQueue = priority_queue<Pair, vector<Pair>, decltype(comp)>;
        PQueue pq(comp);
        
        for (const auto& [k, v] : freq)
        {
            pq.emplace(k, v);
            if (pq.size() > K) pq.pop();
        }
        
        vector<string> res;
        while (!pq.empty())
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}
