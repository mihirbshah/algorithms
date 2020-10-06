#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include "util.h"

using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) 
    {
        unordered_map<int, vector<int>> inbound, outbound;
        for (auto connection : connections)
        {
            const int x = connectoion[0], y = connection[1];
            if (!inbound.count[y]) inbound[y] = {x}
            else inbound[y].push_back(x);
            if (!outbound.count[x]) outbound[x] = {y}
            else outbound[x].push_back(y);
        }
    }
};

int main()
{
    Solution o;
    //vector<vector<int>> v = {{0,1},{1,3},{2,3},{4,0},{4,5}}; int n = 6;
    for (auto sv : v)
        cout << "sv: " << stringify_container(sv.begin(), sv.end()) << "   ";
    cout << "\n";
    int res = o.minReorder(n,v);
    cout << "res: " << res << "\n";
    return 0;
}