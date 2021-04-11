// 56. Merge Intervals

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        
        sort(intervals.begin(), 
             intervals.end(), 
             [&](const vector<int>& v1, const vector<int>& v2){ return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]); });
        
        int start = intervals[0][0], end = intervals[0][1];
        const int n = intervals.size();
        
        for (int i = 1; i < n; ++i)
        {
            if (intervals[i][0] > end)
            {
                res.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
                continue;
            }
            
            end = max(end, intervals[i][1]);
        }
        
        res.push_back({start, end});
        
        return res;
    }
};

int main()
{
    return 0;
}