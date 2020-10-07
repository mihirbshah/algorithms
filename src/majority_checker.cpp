#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
https://leetcode.com/problems/online-majority-element-in-subarray/

This solution is taken from https://leetcode.com/problems/online-majority-element-in-subarray/discuss/356108/C%2B%2B-160-ms-frequency-%2B-binary-search
*/

namespace
{
    using List1D = vector<int>;
    //using List2D = vector<vector<int>>;
    using IndexMap = unordered_map<int, vector<int>>;
    //const int MAX_ELEMENT_VAL = 20000;
}
class MajorityChecker
{
public:
    MajorityChecker(List1D& arr) 
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            indices[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) 
    {
        for (const auto& bucket : indices)
        {
            if (bucket.second.size() < threshold) continue;
            auto low = lower_bound (bucket.second.begin(), bucket.second.end(), left);
            auto high = upper_bound (bucket.second.begin(), bucket.second.end(), right);
            if (distance(low, high) >= threshold) return bucket.first;
        }
        return -1;
    }

private:
    IndexMap indices;
};

/*class MajorityChecker_mihir 
{
public:
    MajorityChecker(List1D& arr) 
    {
        List1D runningCounts(MAX_ELEMENT_VAL, 0);
        // dummy row with all 0's to simply code later
        _prefixCounts.push_back(runningCounts);
        
        for (int i = 1; i <= arr.size(); ++i)
        {
            ++runningCounts[arr[i-1]];
            _prefixCounts.push_back(runningCounts);
        }
    }
    
    int query(int left, int right, int threshold) 
    {
        // C++2x but O(n) space
        List1D subarrCounts(MAX_ELEMENT_VAL, 0);
        std::transform(_prefixCounts[right+1].begin(), 
                       _prefixCounts[right+1].end(), 
                       _prefixCounts[left].begin(), 
                       subarrCounts.begin(), 
                       std::minus<int>());        
        auto it = find_if(subarrCounts.begin(), subarrCounts.end(), [&](int e){ return e >= threshold; });
        return it == subarrCounts.end() ? -1 : distance(subarrCounts.begin(), it);
        
        //C++98 but O(1) space
        //const List1D& rList = _prefixCounts[right+1], lList = _prefixCounts[left];
        //for (int i = 0; i < MAX_ELEMENT_VAL; ++i)
        //{
        //    if (rList[i] - lList[i] >= threshold) return i;
        //}
        //return -1;
        
    }
    
private:
    List2D _prefixCounts;
};
*/

int main()
{
    List1D v = {1,1,2,2,1,1};
    MajorityChecker o(v);
    int res = o.query(2,3,2);
    cout << "res: " << res << "\n";
    return 0;
}