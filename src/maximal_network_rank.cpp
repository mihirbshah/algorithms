#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

/*
    https://leetcode.com/problems/maximal-network-rank/submissions/
*/

class Solution 
{
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<int> nodeRanks(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        for (const auto& road : roads)
        {
            ++nodeRanks[road[0]];
            ++nodeRanks[road[1]];
            connected[road[0]][road[1]] = true;
            connected[road[1]][road[0]] = true;
        }
        
        /*vector<int> highestNodeRankIndices;
        const auto maxElem = max_element(nodeRanks.begin(), nodeRanks.end());
        for (int i = 0; i < nodeRanks.size(); ++i)
        {
            if (nodeRanks[i] == maxElem) highestNodeRankIndices.push_back(i);
        }*/
        cout << "nodeRanks: " << stringify_container(nodeRanks.begin(), nodeRanks.end()) << "\n";
        int res = INT_MIN;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j != i && j < n; ++j)
            {
                res = max(res, nodeRanks[i] + nodeRanks[j] - (connected[i][j] ? 1 : 0));
            }
        }
        
        return res;
        
    }
};

int main()
{
    vector<vector<int>> roads = {{0,1},{0,3},{1,2},{1,3}}; int n = 4;
    Solution o; 
    int res = o.maximalNetworkRank(n, roads);
    cout << "res: " << res << "\n";
    return 0;
}