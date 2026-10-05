// 1027. Longest Arithmetic Subsequence

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Solution passes all tests but gets TLE'ed
class Solution 
{
public:
    int longestArithSeqLength(vector<int>& A) 
    {
        const int n = A.size();
        vector<unordered_map<int, int>> dp(n, unordered_map<int, int>());
        int res = INT_MIN;
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                const int diff = A[j] - A[i];
                dp[i][diff] = max(dp[i][diff], dp[j].count(diff) ? dp[j][diff] + 1 : 2);
                res = max(res, dp[i][diff]);
            }
        }
        
        return res;
    }
};

int main()
{
    vector<int> A({44,46,22,68,45,66,43,9,37,30,50,67,32,47,44,11,15,4,11,6,20,64,54,54,61,63,23,43,3,12,51,61,16,57,14,12,55,17,18,25,19,28,45,56,29,39,52,8,1,21,17,21,23,70,51,61,21,52,25,28});
    Solution o;
    int res = o.longestArithSeqLength(A);
    cout << "res: " << res << "\n";
    return 0;
}