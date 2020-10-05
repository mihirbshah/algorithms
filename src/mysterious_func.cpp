#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/

This solution is taken from https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/discuss/743741/Detailed-General-Ideasolution-for-such-problems-(-AND-OR-GCD-)-in-O(N-*-log(-max(arri)-)-)
*/
class Solution 
{
public:
    int closestToTarget(vector<int>& arr, int target) 
    {
        vector<unordered_set<int>> v(arr.size(), unordered_set<int>({}));
        v[0].insert({arr[0]});
        
        for (int i = 1; i < arr.size(); ++i)
        {
            v[i].insert({arr[i]});
            for (const auto& e : v[i-1])
            {
                v[i].insert(arr[i] & e);
            }
        }
        
        int res = INT_MAX;
        for (const auto& s : v)
        {
            for (const auto& e : s)
            {
                res = min(res, abs(target-e))
            }
        }
        
        return res;
    }
};

int main()
{
    Solution o;
    int res = o.closestToTarget({9,12,3,7,15}, 5);
    cout << "res: " << res "\n";
    return 0;
}