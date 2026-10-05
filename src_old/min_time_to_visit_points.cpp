// 1266. Minimum Time Visiting All Points

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution 
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        const int n = points.size();
        int d = 0;
        for (int i = 0; i < n - 1; ++i)
        {
            const int x1 = points[i][0], y1 = points[i][1], x2 = points[i + 1][0], y2 = points[i + 1][1];
            int xd = x1 - x2, yd = y1 - y2;
            if (abs(xd) <= abs(yd))
            {
                d += abs(xd);
                d += abs(yd) - abs(xd);
            }
            else
            {
                d += abs(yd);
                d += abs(xd) - abs(yd);
            }
        }
        return d;
    }
};

int main()
{
    vector<vector<int>> points({{3,2},{-2,2}});
    Solution o;
    int res = o.minTimeToVisitAllPoints(points);
    cout << "res: " << res << "\n";
    return 0;
}