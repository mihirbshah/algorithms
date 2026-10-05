// 253. Meeting Rooms II

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        vector<int> starts, ends;
        for (const auto& v : intervals)
        {
            starts.push_back(v[0]);
            ends.push_back(v[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        const int n = intervals.size();
        
        int rooms = 0, endIndex = 0;
        for (int i = 0; i < n; ++i)
        {
            if (starts[i] < ends[endIndex]) ++rooms;
            else ++endIndex;
        }
        
        return rooms;
    }
};

/*
class Solution 
{
public:
    int minMeetingRooms(vector<vector<int>>& intervals) 
    {
        if (intervals.size() == 1) return 1;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2){ return v1[1] < v2[1] || (v1[1] == v2[1] && v1[0] > v2[0]); });
        
        for (auto& v : intervals)
        {
            cout << "[" << v[0] << ", " << v[1] << "], ";
        }
        cout << "\n";
        
        const int n = intervals.size();
        int rooms = 1;
        for (int i = 0; i < n - 1; ++i)
        {
            if (intervals[i][1] < intervals[i + 1][1])
            {
                if (intervals[i + 1][0] < intervals[i][1]) ++rooms;
            }
            else
            {
                ++rooms; 
            }
        }
        
        return rooms;
    }
};
*/

int main()
{
    //vector<vector<int>> intervals({{6,15}, {13,20}, {6,17}});
    vector<vector<int>> intervals({{9,16}, {6,16}, {1,9}, {3,15}});
    Solution o;
    int res = o.minMeetingRooms(intervals);
    cout << "res: " << res << "\n";
    return 0;
}