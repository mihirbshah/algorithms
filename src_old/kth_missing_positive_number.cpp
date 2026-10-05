// 1539. Kth Missing Positive Number

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int prev = 0, missing = 0;
        for (auto n : arr)
        {
            missing += n - prev - 1;
            cout << "n: " << n << ", missing: " << missing << "\n";
            if (missing >= k) return n - (missing - k + 1);
            prev = n;
        }
        return arr[arr.size() - 1] + (k - missing);
    }
};

int main()
{
    vector<int> v({5,6,7,8,9}); int k = 9;
    Solution o;
    int res = o.findKthPositive(v, k);
    cout << "res: " << res << "\n";
    return 0;
}