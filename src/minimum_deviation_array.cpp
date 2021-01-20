#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    int minimumDeviation(vector<int>& nums) 
    {
        for(auto& num : nums) if (num % 2) num = 2 * num;
        sort(nums.begin(), nums.end());
        long smallestIdx = 0, dev = 0, prevDev = 0;
        const int n = nums.size();
        for (int i = 1; i < n; ++i)
        {
            if (nums[smallestIdx] % 2) nums[smallestIdx] = 2 * nums[smallestIdx];
            while (nums[i] % 2 == 0) nums[i] = nums[i] / 2;
            //if (nums[i] < nums[smallestIdx]) nums[i] = 2 * nums[i];
            prevDev = dev;
            if (nums[i] < nums[smallestIdx])
            {
                if (i - 1 > smallestIdx)
                {
                    dev = nums[i - 1] - (nums[i] % 2 ? 2 * nums[i] : nums[i]);
                }
                else
                {
                    dev = nums[smallestIdx] - nums[i];
                }
                smallestIdx = i;
            }
            else
            {
                dev = nums[i] - nums[smallestIdx];
            }
        }
        return dev;
    }
};

int main()
{
    Solution s;
    //vector<int> v = {1,2,3,4};
    //vector<int> v = {4,1,5,20,3};
    vector<int> v = {2,10,8};
    cout << "res : " << s.minimumDeviation(v) << "\n";
    return 0;
}