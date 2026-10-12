#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> result = {-1, -1};
        int product = std::numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != target - nums[i] && 
                numMap.find(target - nums[i]) != numMap.end()) {
                int currentProduct = nums[i] * (target - nums[i]);
                if (product == std::numeric_limits<int>::min() || currentProduct > product) {
                    product = currentProduct;
                    if (nums[i] > target - nums[i])
                        result = {i, numMap[target - nums[i]]};
                    else
                        result = {numMap[target - nums[i]], i};
                }
            }
            numMap[nums[i]] = i;
        }
        return result;
    }
};
