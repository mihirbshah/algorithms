// 1610. Maximum Number of Visible Points

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define PI 3.14159265

// partially working solution
class Solution 
{
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) 
    {
        vector<double> angles(points.size(), INT_MAX);
        int common = 0;
        for(const auto p : points)
        {
            int x = p[0] - location[0];
            int y = p[1] - location[1];
            if (!x && !y)
            {
                ++common;
                continue;
            }
            double ang = atan2(x, y) * 180 / PI;
            //cout << "point: [" << p[0] << "," << p[1] << "],  ang: " << ang << "\n";
            angles.push_back(ang);
        }
        
        const double halfang = angle / 2;
        
        int maxVisible = 0;
        for (int d = 0; d <= 360; ++d)
        {
            int visible = 0;
            for (const auto ang : angles)
            {
                visible += ((ang <= (d + halfang)) && (ang >= (d - halfang)));
            }
            maxVisible = max(maxVisible, visible);
        }
        
        return common + maxVisible;
    }
};

int main()
{
    //vector<vector<int>> points({{2,1},{2,2},{3,3}}); int angle = 90; vector<int> loc({1,1});
    //vector<vector<int>> points({{2,1},{2,2},{3,4},{1,1}}); int angle = 90; vector<int> loc({1,1});
    vector<vector<int>> points({{1,0},{2,1}}); int angle = 13; vector<int> loc({1,1});
    
    Solution o;
    int maxVisible = o.visiblePoints(points, angle, loc);
    cout << "maxVisible: " << maxVisible << "\n";
    return 0;
}