// 945. Minimum Increment to Make Array Unique

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*class Solution 
{
public:
    int minIncrementForUnique(vector<int>& A) 
    {
        unordered_map<int, int> cnt;
        for (const auto& n : A) ++cnt[n];
        int res = 0;
        for (auto [k, v] : cnt)
        {
            if (v == 1) continue;
            while (v > 1)
            {
                int m = k;
                while (cnt.count(m))
                {
                    ++m;
                    ++res;
                }
                cnt[m] = 1;
                --v;
            }
        }
        return res;
    }
};
*/
// Copied from https://leetcode.com/problems/minimum-increment-to-make-array-unique/discuss/197713/C%2B%2B-concise-solution-O(nlogn)-complexity-with-explanation-and-example-step-by-step
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int s = A.size();
        int res=0;
        if (s<2)  return 0;
        sort(A.begin(),A.end());        
        for (int i=1; i<s; ++i) {
            if (A[i]<=A[i-1]){
                res+=A[i-1]+1 -A[i];
                A[i]= A[i-1]+1;
            }
        }
        return res;
    }
};


int main()
{
    return 0;
}