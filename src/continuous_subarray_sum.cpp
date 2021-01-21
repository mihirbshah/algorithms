// 560. Subarray Sum Equals K

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    /*int subarraySum(vector<int>& nums, int k) 
    {
        const int n = nums.size();
        vector<vector<int>> sums(n, vector<int>(n, 0));
        int count = 0;
        
        for (int i = 0; i < n; ++i) 
        {
            sums[i][i] = nums[i];
            if (sums[i][i] == k) ++count;
        }
        
        for (int w = 2; w <= n; ++w)
        {
            for (int i = 0; i + w - 1 < n; ++i)
            {
                sums[i][i + w - 1] = sums[i][i] + sums[i + 1][i + w - 1];
                if (sums[i][i + w - 1] == k) ++count;
            }
        }
        
        return count;
    }*/
    
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> prefixSums;
        prefixSums[0] = 1;
        const int n = nums.size();
        long sum = 0;
        int count = 0;
        
        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if (prefixSums.count(sum - k)) count += prefixSums[sum - k];
            ++prefixSums[sum];
        }
        
        return count;
    }
};

int main()
{
    Solution o;
    //vector<int> nums{1,1,1}; int k = 2;
    //vector<int> nums{1,2,3}; int k = 3;
    vector<int> nums{-5, 10, -3, 1, 6}; int k = 7;
    
    int res = o.subarraySum(nums, k);
    cout << "res: " << res << "\n";
    
    return 0;
}