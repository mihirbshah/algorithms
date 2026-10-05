// 1200. Minimum Absolute Difference

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());
        const int n = arr.size();
        int diff = INT_MAX;
        for (int i = 0; i < n - 1; ++i)
        {
            diff = min(diff, abs(arr[i] - arr[i + 1]));
        }
        
        vector<vector<int>> res;
        for (int i = 0; i < n - 1; ++i)
        {
            if (abs(arr[i] - arr[i + 1]) == diff)
            {
                res.push_back({arr[i], arr[i + 1]});
            }
        }
        
        return res;
    }
};

int main()
{
    return 0;
}