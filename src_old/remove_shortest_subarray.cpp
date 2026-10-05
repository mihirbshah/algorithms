// 1574. Shortest Subarray to be Removed to Make Array Sorted
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Almost working solution, copied from https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/discuss/830416/Java-Increasing-From-Left-Right-and-Merge-O(n)
class Solution 
{
public:
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        const int size = arr.size();
        int i = 0, j = size - 1;
        while (i < size - 1 && arr[i] <= arr[i + 1]) ++i;
        if (i == size) return 0;
        while (j > i && arr[j - 1] <= arr[j]) --j;
        int res = min(size - i - 1, j);
        int m = 0, n = j;
        while (m < i && n < size)
        {
            if (arr[m] <= arr[n]) 
            {
                res = min(res, n - m - 1);
                ++m;
            }
            else ++n;
        }
        return res;
    }
};

int main()
{
    vector<int> v({1,2,3,10,4,2,3,5});
    Solution o;
    int res = o.findLengthOfShortestSubarray(v);
    cout << "res: " << res << "\n";
    return 0;
}