#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
*/

namespace
{
    using Range = vector<int>;
    using Partition = vector<Range>;
}

class Solution 
{
public:
    int minNumberOperations(Range& target) 
    {
        return minOps(target, 0, target.size() - 1);
    }
    
    //lee215 solution
    int minNumberOperations_1(vector<int>& A) 
    {
        int res = A[0];
        for (int i = 1; i < A.size(); ++i)
            res += max(A[i] - A[i - 1], 0);
        return res;
    }


private:
    int smallestElemIndex(const Range& target, int begin, int end)
    {
        //1+ is needed because end is always one element past the last element
        return distance(target.begin(), min_element(target.begin() + begin, 1 + target.begin() + end)); 
    }
    
    void reduceDeltaFromRange(Range& target, int begin, int end, int delta)
    {
        //1+ is needed because end is always one element past the last element
        transform(target.begin() + begin,
                  1 + target.begin() + end,
                  target.begin() + begin,
                  [&](int e){ return e - delta; }
                 );
    }
    
    Partition partitionSet(const Range& target, int begin, int end, int delim)
    {
        Partition p;
        int prev = begin;
        for (int i = begin; i <= end; ++i)
        {
            if (target[i] == delim)
            {
                if (prev <= i - 1)
                {
                    p.push_back({prev, i - 1});
                }
                prev = i + 1;
            }
        }
        if (prev <= end) p.push_back({prev, end});
        return p;
    }
    
    int minOps(Range& target, int begin, int end)
    {
        //cout << "=== Called minOps === \n";
        //cout << "begin: " << begin << ", end: " << end << "\n";
        int i = smallestElemIndex(target, begin, end);
        //cout << "smallestElemIndex: " << i << "\n";
        int minSteps = target[i];
        //cout << "minSteps(1): " << minSteps << "\n";
        reduceDeltaFromRange(target, begin, end, minSteps);
        //cout << "target: " << stringify_container(target.begin(), target.end()) << "\n";
        Partition p = partitionSet(target, begin, end, target[i]);
        for (auto r : p)
        {
            minSteps += minOps(target, r[0], r[1]);
        }
        //cout << "minSteps(2): " << minSteps << "\n";
        return minSteps;
    }    
};

int main()
{
    //Range v = {1,2,3,2,1};
    //Range v = {3,1,1,2};
    //Range v = {3,1,5,4,2};
    Range v = {1,1,1,1};
    
    Solution o;
    int res = o.minNumberOperations(v);
    cout << "res: " << res << "\n";
    return 0;
}