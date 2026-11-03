#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// O(n log n) using full sort to find the median 
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int moves = 0;
        for (int num : nums) {
            moves += abs(num - median);
        }
        return moves;
    }
};