#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
Solution based on: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/discuss/635267/C%2B%2BJavaPython-Strict-O(Target)
*/

string largestNumber(vector<int>& cost, int target)
{
    // Since we want to attain the largest number, we need to define what we mean by largest number. 
    // x > y if x has more digits than y OR the digits from the left for 'x' are larger than digits from the left for 'y'
    // So in order to get our answer, we will first figure out the max number of digits that can be used to attain the 
    // 'target' weight
    // Then, we will start filling in digits from 9 to 1 (largest to smallest) in the order left -> right to make our
    // result as large as possible
    
    vector<int> dp(target+1, INT_MIN);
    dp[0] = 0;
    // For each possible weight from 1 to target, find the most digits that can be used to attain that weight.
    // To do this, for each weight 't', we iterate through all the digits 'd' to find the most digits that can be 
    // used to attain 't' using digits from 1 to 'd'
    for (int t = 1; t <= target; ++t)
    {
        for (int d = 0; d < 9; ++d)
        {
            // If cost[d] > t, then 'd' cannot be used to attain weight t
            // So, we do max(d[t], INT_MIN) which in effect is just d[t] since 
            // d[t] would never be smaller than INT_MIN
            
            // But if cost[d] <= t, then 'd' can be used to attain weight t
            // In this case, the most number of digits to attain 't' using digits
            // from 1 to d would be 1 (for the digit d) + dp[t - cost[d]] (assuming we)
            // included 'd', then the remaining weight left over is "t - cost[d]"
            // So dp[t - cost[d]] gives us the most number of digits that can be used to 
            // attain that leftover weight.
            // So basically we are saying that the best answer for the leftover weight + 1
            // would be the best answer for current digit
            dp[t] = max(dp[t], (cost[d] <= t) ? 1 + dp[t - cost[d]] : INT_MIN);
        }
    }
    
    // If target weight cannot be attained using >0 digits, then just return 0 as per problem spec
    if (dp[target] < 0) return "0";
    
    // Now that we know how many digits can be used to attain 'target' weight, start filling in the actual
    // digits from left -> right starting with the highest digit first (i.e. 9 to 1)
    string res;
    for (int d = 8; d >= 0; --d)
    {
        // If cost[d] > target, then it can never be used to attain target
        // If cost[d] <= target, then it is a potential candidate for the answer
        // However, we need to check if it is a part of the best solution.
        // To do this, we check if number of digits to attain the weight 'target - cost[d]' + 1
        // is the same as number of digits to attain the weight 'target'. If yes, then 'd' is a part
        // of the best answer.
        while (cost[d] <= target && dp[target] == 1 + dp[target - cost[d]])
        {
            res += '1' + d;
            target -= cost[d];
        }
    }
    
    return res;
}

int main()
{
    vector<int> v1 = {4,3,2,5,6,7,2,5,5}; int target1 = 9;
    string res = largestNumber(v1, target1);
    cout << "biggest number: " << res << "\n";
    return 0;
}