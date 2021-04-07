// 679. 24 Game

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    bool judgePoint24(vector<int>& nums) 
    {
        vector<double> tmp(nums.begin(), nums.end());
        return dfs(tmp);
    }
    
private:
    bool dfs(vector<double>& nums)
    {
        const int n = nums.size();
        if (n == 1)
        {
            return fabs(nums[0] - 24.0) < 1e-8;
        }
        
        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                vector<double> tmp;
                for (int k = 0; k < n; ++k)
                {
                    if (k != i && k != j) tmp.push_back(nums[k]);
                }
                
                tmp.push_back(nums[i] + nums[j]);
                if (dfs(tmp)) return true;
                
                tmp.back() = (nums[i] - nums[j]);
                if (dfs(tmp)) return true;
                
                tmp.back() = (nums[i] * nums[j]);
                if (dfs(tmp)) return true;
                
                tmp.back() = (nums[i] / nums[j]);
                if (dfs(tmp)) return true;
                
                tmp.back() = (nums[j] - nums[i]);
                if (dfs(tmp)) return true;
                
                tmp.back() = (nums[j] / nums[i]);
                if (dfs(tmp)) return true;
            }
        }
        
        return false;
    }
};

int main()
{
    return 0;
}