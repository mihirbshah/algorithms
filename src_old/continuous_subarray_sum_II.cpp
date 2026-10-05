// 523. Continuous Subarray Sum

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    /*
    Solution copied from 
    https://leetcode.com/problems/continuous-subarray-sum/discuss/99499/Java-O(n)-time-O(k)-space
    Intuition -
    1.
    For e.g. in case of the array [23,2,6,4,7] the running sum is [23,25,31,35,42] and the remainders are [5,1,1,5,0]. We got remainder 5 at index 0 and at index 3. That means, in between these two indexes we must have added a number which is multiple of the k. Hope this clarifies your doubt :)

    2.
    Running sum from first element to index i : sum_i. If we mod k, it will be some format like : sum_i = k * x + modk_1
    Running sum from first element to index j : sum_j. If we mod k, it will be some format like : sum_j = k * y + modk_2
    If they have the same mod, which is modk_1 == modk_2, subtracting these two running sum we get the 
    difference sum_i - sum_j = (x - y) * k = constant * k, and the difference is the sum of elements between index i and j, 
    and the value is a multiple of k.


    */
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        int sum = 0;
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if (k) sum %= k;
            int prev_i = i;
            if (prefixSum.count(sum))
            {
                prev_i = prefixSum[sum];
                if (i - prev_i > 1) return true;
            }
            else
                prefixSum[sum] = i;
        }
        return false;
    }
    /*
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        int sum = 0;
        const int n = nums.size();
        
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if (i)
            {
                if (!sum) return true;
                if (!k && !sum) return true;
                if (nums[i] && ((k > 0) && prefixSum.count(sum % k)) || ((k < 0) && prefixSum.count((-1 * sum) % k))) return true;
            }
            if (k > 0) ++prefixSum[sum % k];
            else if (k < 0) ++prefixSum[(-1 * sum) % k];
        }
        
        return false;
    }*/
};

int main()
{
    vector<int> nums({23, 2, 4, 6, 7}); int k = 6;
    //vector<int> nums({23, 2, 6, 4, 7}); int k = 6;
    Solution o;
    bool res = o.checkSubarraySum(nums, k);
    cout << "res: " << res << "\n";
    return 0;
}