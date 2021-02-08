// 763. Partition Labels

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include "util.h"

using namespace std;

class Solution 
{
public:
    /*
    vector<int> partitionLabels(string s) 
    {
        vector<pair<int, int>> startEnd(26, make_pair(-1, -1));
        const int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (startEnd[s[i] - 'a'].first == -1) startEnd[s[i] - 'a'] = make_pair(i, i);
            else startEnd[s[i] - 'a'].second = i;
        }
        
        vector<pair<int, int>> partitions;
        for (const auto& pos : startEnd)
        {
            if (pos.first == -1) continue;
            int overlappIndex = -1;
            
            for (int i = 0; i < partitions.size(); ++i)
            {
                if (!(pos.first > partitions[i].second || pos.second < partitions[i].first))
                    overlappIndex = i;
            }
        }
    }*/
    vector<int> partitionLabels(string S) {
        vector<int> charIdx(26, 0);
        for(int i = 0; i < S.size(); i++){
            charIdx[S[i]-'a'] = i;
        }
        
        vector<int> results;
        
        int maxIdx = -1, lastIdx = 0;
        for(int i = 0; i < S.size(); i++)
        {
            maxIdx = max(maxIdx, charIdx[S[i]-'a']);
            if(i == maxIdx) 
            {
                results.push_back(maxIdx - lastIdx + 1);
                lastIdx = i+1;
            }
        }
        return results;
    }

};




int main()
{
    //string s = "ababcbacadefegdehijhklij";
    string s = "abababcd";
    Solution o;
    vector<int> res = o.partitionLabels(s);
    print_container(res.begin(), res.end());
    return 0;
}