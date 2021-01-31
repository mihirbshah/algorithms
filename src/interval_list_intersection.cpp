// 986. Interval List Intersections

#include <iostream>
#include <vector>
#include "util.h"

using VList = vector<vector<int>>;

/*
// Partially working solution
class Solution 
{
public:
    VList intervalIntersection(VList& listi, VList& listj) 
    {
        int csi = -1, cei = -1, csj = -1, cej = -1, pei = -1, pej = -1;
        int indexi = 0, indexj = 0;
        
        setStartEnd(listi, indexi, csi, cei);
        setStartEnd(listj, indexj, csj, cej);
        VList res;
        while (isValid(csi) && isValid(cei) &&
               isValid(csj) && isValid(cej))
        {
            cout << "indexi: " << indexi
                 << ", indexj: " << indexj
                 << ", csi: " << csi
                 << ", cei: " << cei
                 << ", csj: " << csj
                 << ", cej: " << cej
                 << ", pei: " << pei
                 << ", pej: " << pej
                 << "\n";
            exhaustPrev(res, pei, pej, csi, cei);
            exhaustPrev(res, pej, pei, csj, cej);
            if (csj <= cei && csi <= cej) res.push_back({max(csi, csj), min(cei, cej)});
            setPrev(pei, pej, cei, cej);
            ++indexi; ++indexj;
            setStartEnd(listi, indexi, csi, cei);
            setStartEnd(listj, indexj, csj, cej);
        }
                cout << "indexi: " << indexi
                 << ", indexj: " << indexj
                 << ", csi: " << csi
                 << ", cei: " << cei
                 << ", csj: " << csj
                 << ", cej: " << cej
                 << ", pei: " << pei
                 << ", pej: " << pej
                 << "\n";

        exhaustPrev(res, pei, pej, csi, cei);
        exhaustPrev(res, pej, pei, csj, cej);
        
        return res;
    }
    
private:
    void setPrev(int& pei, int& pej, int cei, int cej)
    {
        pei = -1; pej = -1;
        if (cei < cej)
        {
            pei = -1; pej = cej;
        }
        else
        {
            pei = cei; pej = -1;
        }
    }
    
    void exhaustPrev(VList& res, int pex, int pey, int& csx, int cex)
    {
        if (!isValid(pex) && isValid(pey) && isValid(csx) && isValid(cex))
        {
            if (csx <= pey)
            {
                res.push_back({csx, pey});
                csx = min(pey + 1, cex);
            }
        }
    }
    
    bool isValid(const int& i)
    {
        return i >= 0;
    }
    
    void setStartEnd(const VList& l, int i, int& cs, int& ce)
    {
        if (i >= l.size())
        {
            cs = -1; ce = -1; 
            return;
        }
        
        const int n = l[i].size();
        if (n) 
        {
            cs = l[i][0]; ce = l[i][n - 1];
        }
        else 
        {
            cs = -1; ce = -1;
        }
    }
};
*/

class Solution 
{
public:
    VList intervalIntersection(VList& A, VList& B) 
    {
        VList res;
        for (auto i = 0, j = 0; i < A.size() && j < B.size(); A[i][1] < B[j][1] ? ++i : ++j) {
            auto start = max(A[i][0], B[j][0]);
            auto end = min(A[i][1], B[j][1]);
            if (start <= end) 
                res.push_back({start, end});
        }
        return res;    
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