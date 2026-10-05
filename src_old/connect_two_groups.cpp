#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution
{
public:
    using CostMap = unordered_map<int, vector<int>>;
    
    int connectTwoGroups(vector<vector<int>>& cost)
    {
        const int rows = cost.size(), cols = cost[0].size();
        connected = vector(rows, vector(cols, false));
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                updateSmallestCost(smallestCosts1, i, j, cost[i][j]);
                updateSmallestCost(smallestCosts2, j, i, cost[i][j]);
            }
        }
        
        unordered_set<int> notConnected(cols);
        //iota(notConnected.begin(), notConnected.end(), 0);
        for (int j = 0; j < cols; ++j) notConnected.insert(j);

        for (int i = 0; i < rows; ++i)
        {
            connected[i][smallestCosts1[i][0]] = true;
            notConnected.erase(smallestCosts1[i][0]);
        }
        
        /*for (const auto& e : notConnected)
        {
            const auto r = smallestCosts2[e][0];
            for (int j = 0; j < cols; ++j)
                connected[r][j] = false;
            connected[r][e] = true;
        }*/
        for (const auto& e : notConnected)
        {
            int costDelta = INT_MAX;
            int index = -1;
            for (int i = 0; i < rows; ++i)
            {
                int costToRemove = 0;   
                for (int j = 0; j < cols; ++j)
                {
                    if (connected[i][j]) costToRemove += cost[i][j];
                }
                if (costDelta > cost[i][e] - costToRemove)
                {
                    costDelta = cost[i][e] - costToRemove;
                    index = i;
                }
            }
            for (int j = 0; j < cols; ++j)
               connected[index][j] = false; 
            connected[index][e] = true;
        }
        
        notConnected.clear();
        for (int j = 0; j < cols; ++j)
        {
            bool isConnected = false;
            for (int i = 0; i < rows; ++i)
            {
                isConnected |= connected[i][j];
            }
            if (!isConnected) notConnected.insert(j);
        }
        
        for (const auto& e : notConnected)
        {
            connected[smallestCosts2[e][0]][e] = true;
        }
        
        int res = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                res += connected[i][j] ? cost[i][j] : 0;
            }
        }
        
        return res;
    }
    
private:
    void updateSmallestCost(CostMap& map, int key, int index, int val)
    {
        if (!map.count(key))
        {
            map[key] = {index, val};
        }
        else
        {
            if (val < map[key][1]) 
            {
                map[key][0] = index;
                map[key][1] = val;
            }
        }
    }
    
    CostMap smallestCosts1, smallestCosts2;
    vector<vector<bool>> connected;
};

int main()
{
    vector<vector<int>> c1 = {{15, 96}, {36, 2}};
    vector<vector<int>> c2 = {{1, 3, 5}, {4, 1, 1}, {1, 5, 3}};
    vector<vector<int>> c3 = {{2, 5, 1}, {3, 4, 7}, {8, 1, 2}, {6, 2, 4}, {3, 8, 8}};
    vector<vector<int>> c4 = {{93,56,92},{53,44,18},{86,44,69},{54,60,30}};
    Solution o;
    int res = o.connectTwoGroups(c4);
    cout << "res: " << res << "\n";
    return 0;
}