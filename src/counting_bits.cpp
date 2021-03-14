// 338. Counting Bits

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> countBits(int num) 
    {
        vector<int> dp(max(num + 1, 8), 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;
        dp[4] = 1;
        dp[5] = 2;
        dp[6] = 2;
        dp[7] = 3;
        
        if (num <= 7) return vector<int>(dp.begin(), dp.begin() + num + 1);
        int n = 8, exp = 3;
        while (n <= num)
        {
            const int end = pow(2, exp++);
            for (int begin = 0; begin < end; ++begin)
            {
                if (n > num) break;
                dp[n++] = 1 + dp[begin];
            }
        }
        
        return vector<int>(dp.begin(), dp.begin() + num + 1);
    }
};

int main()
{
    return 0;
}