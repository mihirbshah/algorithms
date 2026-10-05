#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int boundedSquareSumPairs(vector<int> a, vector<int> b, int lower, int upper)
    {
        const int m = a.size(), n = b.size();
        if (m > n) return boundedSquareSumPairs(b, a, lower, upper);
        
        for (auto& na : a) na = na * na;
        sort(a.begin(), a.end());
        
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (b[i] * b[i] > upper) continue;
            auto ub = upper_bound(a.begin(), a.end(), upper - b[i] * b[i]);
            auto lb = lower_bound(a.begin(), a.end(), lower - b[i] * b[i]);
            res += (ub - lb);
        }
        
        return res;
    }
};

int main()
{
    Solution o;
    vector<int> a = {3, -1, 9};
    vector<int> b = {4, 5, -2};
    int res = o.boundedSquareSumPairs(a, b, 7, 99);
    cout << "res: " << res << "\n";
    return 0;
}