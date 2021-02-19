// 1424. Diagonal Traverse II

#include <iostream>
#include <vector>
#include "util.h"
#include <algorithm>

using namespace std;

// Solution gets TLEed
// For O(m.n) solution, refer - https://leetcode.com/problems/diagonal-traverse-ii/discuss/597698/JavaC%2B%2B-HashMap-with-Picture-Clean-code-O(N)
class Solution 
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        const int m = nums.size();
        int n = 0;
        for (const auto& num : nums) n = max(n, (int)num.size());
        
        vector<int> res;
        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < (r == m - 1 ? n : 1); ++c)
            {
                int i = r, j = c;
                while (i >= 0 && j < n)
                {
                    if (j < nums[i].size()) res.push_back(nums[i][j]);
                    --i;
                    ++j;
                }
            }
        }
        return res;
    }
};

int main()
{
    //vector<vector<int>> v({{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}});
    vector<vector<int>> v({{1,2,3,4,5,6}});
    Solution o;
    vector<int> res = o.findDiagonalOrder(v);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}