// 1642. Furthest Building You Can Reach

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) 
    {
        auto comp = [&](int a, int b) { return a > b; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        int i;
        for (i = 1; i < heights.size(); ++i)
        {
            int d = heights[i] - heights[i - 1];
            if (d > 0) pq.push(d);
            if (pq.size() > ladders)
            {
                bricks -= pq.top();
                pq.pop();
            }
            if (bricks < 0) break; 
        }
        return i - 1;
    }
};

int main()
{
    vector<int> h({4,12,2,7,3,18,20,3,19}); int bricks = 10, ladders = 2;
    Solution o;
    int res = o.furthestBuilding(h, bricks, ladders);
    cout << "res: " << res << "\n";
    return 0;
}