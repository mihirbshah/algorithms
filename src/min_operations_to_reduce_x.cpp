// 1658. Minimum Operations to Reduce X to Zero

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution 
{
public:
    int minOperations(vector<int>& nums, int x) 
    {
        const int n = nums.size();
        int minSteps = INT_MAX;
        int l = 0, r = 0;
        long sum = accumulate(begin(nums), end(nums), 0);
        while (l <= r)
        {
            if (sum < x)
            {
                sum += nums[l];
                ++l;
            }
            else if (sum >= x)
            {
                if (sum == x) minSteps = min(minSteps, l + n - r);
                if (r < n) 
                {
                    sum -= nums[r];
                    ++r;
                }
                else
                    break;
            }            
        }
        
        return minSteps == INT_MAX ? -1 : minSteps;
    }
    
    /*
    int minOperations(vector<int>& nums, int x) 
    {
        const int n = nums.size();
        int minSteps = INT_MAX;
        vector<int> left(n + 1, 0), right(n + 1, 0);
        for (int i = 1; i <= n; ++i) 
        {
            left[i] = nums[i - 1] + left[i - 1];
            if (left[i] == x) minSteps = min(minSteps, i);
        }
        
        for (int i = 1; i <= n; ++i) 
        {
            right[i] = nums[n - i] + right[i - 1];
            if (right[i] == x) minSteps = min(minSteps, i);
        }
        
        int i = 1, j = 1;
        for (; i <= n && j <= n && left[i] <= x && right[j] <= x; )
        {
            cout << "i: " << i << ", j: " << j << ", left[i]: " << left[i] << ", right[j]: " << right[j] << "\n";
            if (left[i] + right[j] == x) minSteps = min(minSteps, i + j);
            
            if (left[i] < right[j]) ++i;
            else if (right[j] < left[i]) ++j;
            else 
            {
                ++i;
                ++j;
            }
        }
        
        if ((i > n || left[i] > x) && j <= n && right[j] < x)
        {
            for (; j <= n; ++j) if (right[j] + left[i - 1] == x) min(minSteps, i + j);
        }
        
        if ((j > n || right[j] > x) && i <= n && left[i] < x)
        {
            for (; i <= n; ++i) if (left[i] + right[j - 1] == x) min(minSteps, i + j);
        }
        
        return minSteps == INT_MAX ? -1 : minSteps;
    }*/
};


int main()
{
    vector<int> v({1,1,4,2,3}); int x = 5;
    //vector<int> v({5,6,7,8,9}); int x = 4;
    //vector<int> v({3,2,20,1,1,3}); int x = 10;
    Solution o; 
    int res = o.minOperations(v, x);
    cout << "res: " << res << "\n";
    return 0;
}