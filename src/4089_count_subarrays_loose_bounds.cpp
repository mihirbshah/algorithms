#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int beg = 0;
        int end = 0;
        long long result = 0;
        while (beg < nums.size() && end < nums.size()) {
            if (nums[beg] < minK || nums[beg] > maxK) {
                ++beg;
                end = beg;
                continue;
            }

            while (nums[end] >= minK && nums[end] <= maxK && end < nums.size()) {
                ++end;
            }
            int numElems = end - beg;
            result += (long long)numElems * (numElems + 1) / 2;
            beg = end;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1};
    int minK = 1;
    int maxK = 1;
    cout << s.countSubarrays(nums, minK, maxK) << endl;
    return 0;
}