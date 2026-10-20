#include <iostream>>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> numState;
        int prev = -1;
        for (const auto& num : nums) {
            if (numState.find(num) == numState.end()) {
                numState[num] = 1;
            }
            else {
                if (prev == num) {
                    continue;
                }
                else {
                    numState[num] = 2;
                }
            }
            prev = num;
        }

        int cnt = 0;
        for (const auto& pair : numState) {
            if (pair.second == 1) {
                cnt++;
            }
        }
        return cnt;
    }
}; 