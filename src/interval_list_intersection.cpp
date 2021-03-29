// 986. Interval List Intersections

#include <iostream>
#include <vector>
#include "util.h"


class Solution 
{
public:
    using VList = vector<vector<int>>;
    VList intervalIntersection(VList& A, VList& B) 
    {
        int i = 0, j = 0;
        const int m = A.size(), n = B.size();
        VList res;
        while (i < m && j < n)
        {
            if (intersect(A[i], B[j]))
            {
                res.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
            }
            
            if (A[i][1] < B[j][1]) ++i;
            else ++j;
        }
        return res;
    }
    
private:
    bool intersect(const vector<int>& a, const vector<int>& b)
    {
        return (a[0] <= b[0] && a[1] >= b[1]) || (a[0] <= b[0] && a[1] <= b[1] && a[1] >= b[0]) ||
               (b[0] <= a[0] && b[1] >= a[1]) || (b[0] <= a[0] && b[1] <= a[1] && b[1] >= a[0]);
    }
};


int main()
{
    //VList firstList({{0,2},{5,10},{13,23},{24,25}});
    //VList secondList({{1,5},{8,12},{15,24},{25,26}});
    
    //VList firstList({{1,3}, {5,9}});
    //VList secondList({});

    //VList firstList({});
    //VList secondList({{4,8}, {10,12}});

    VList firstList({{1,7}});
    VList secondList({{3,10}});

    Solution o;
    VList res = o.intervalIntersection(firstList, secondList);
    for (const auto& l : res)
        cout << stringify_container(l.begin(), l.end()) << "\n";
    return 0;
}