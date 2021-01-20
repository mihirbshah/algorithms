// 973. K Closest Points to Origin

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include "util.h"

using namespace std;

using Point = vector<int>;
using PointList = vector<Point>;
using PointPair = pair<long, Point>;
using PointDist = vector<PointPair>;

class Solution
{
public:    
    PointList kClosest(PointList& points, int K) 
    {
        PointDist pDist;
        for (const auto p : points) pDist.push_back(make_pair(dist(p), p));
        sort(pDist.begin(), pDist.end(), [&](PointPair p1, PointPair p2){ return p1.first < p2.first; });
        PointList res;
        for (int i = 0; i < K; ++i)
        {
            res.push_back(pDist[i].second);
        }
        return res;
    }
    
private:
    long dist(const Point& point)
    {
        return pow(point[0], 2) + pow(point[1], 2);
    }
};

int main()
{
    //PointList points = {{1,3},{-2,2}}; int K = 1;
    PointList points = {{3,3},{5,-1},{-2,4}}; int K = 2;
    Solution o;
    PointList res = o.kClosest(points, K);
    for (auto v : res) print_container(v.begin(), v.end());
    
    return 0;
}