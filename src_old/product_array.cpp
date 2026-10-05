// 238. Product of Array Except Self

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

class Solution 
{
public:
    /*vector<int> productExceptSelf(vector<int>& nums) 
    {
        const int s = nums.size();
        vector<int> left(s, 1), right(s, 1);
        for (int i = 1; i < s; ++i)
        {
            left[i] = left[i - 1] * nums[i - 1];
            right[s - i - 1] = right[s - i] * nums[s - i];
        }
        vector<int> res(s, 1);
        for (int i = 0; i < s; ++i) res[i] = left[i] * right[i];
        return res;
    }*/
    
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        const int s = nums.size();
        vector<int> res(s, 1);
        int product = 1;
        for (int i = 1; i < s; ++i)
        {
            product *= nums[i - 1];
            res[i] *= product;
        }
        product = 1;
        for (int i = s - 2; i >= 0; --i)
        {
            product *= nums[i + 1];
            res[i] *= product;
        }
        return res;
    }
};

int main()
{
    Solution o;
    vector<int> nums({1,2,3,4});
    vector<int> res = o.productExceptSelf(nums);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}