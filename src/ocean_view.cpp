// 1762. Buildings With an Ocean View

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        const int n = heights.size();
        vector<int> res({n - 1});
        int maxh = heights[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            if (heights[i] > maxh) res.push_back(i);
            maxh = max(maxh, heights[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    return 0;
}