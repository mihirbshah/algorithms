// 611. Valid Triangle Number

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int triangleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), greater<int>());
        const int n = nums.size();
        int tnum = 0;
        for (int i = 0; i < n - 2; ++i)
        {
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                if (nums[j] + nums[k] > nums[i]) 
                {
                    tnum += (k - j);
                    ++j;
                }
                else --k;
            }
        }
        
        return tnum;
    }
};

int main()
{
    return 0;
}