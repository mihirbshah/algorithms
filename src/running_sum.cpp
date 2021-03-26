// 1480. Running Sum of 1d Array

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> runningSum(vector<int>& nums) 
    {
        const int n = nums.size();
        for (int i = 1; i < n; ++i) nums[i] += nums[i - 1];
        return nums;
    }
};

int main()
{
    return 0;
}