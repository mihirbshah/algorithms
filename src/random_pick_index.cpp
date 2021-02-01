// 398. Random Pick Index

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

/*
// Using extra memory
class Solution 
{
public:
    Solution(vector<int>& nums) 
    {
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (m.count(nums[i])) m[nums[i]].push_back(i);
            else m[nums[i]] = {i};
        }
    }
    
    int pick(int target) 
    {
        const int i = rand() % m[target].size();
        return m[target][i];
    }

private:
    unordered_map<int, vector<int>> m;
};
*/

// Without using any extra memory
class Solution {
public:
    Solution(vector<int> nums) : _nums(nums)
    {
    }

    int pick(int target) 
    {
        int cnt = 0, ret = -1, len = _nums.size();
        for (int i = 0; i < len; ++i) 
        {
            if (_nums[i] != target) continue;
            if (random() % (++cnt) == 0) ret = i;
        }
        return ret;
    }
    
private:
    vector<int> _nums;
};

int main()
{
    return 0;
}