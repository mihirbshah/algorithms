#include <vector>
#include <iostream>
using namespace std;

class Solution {
    bool sameSquare(vector<int>& source, vector<int>& target) {
        return source[0] == target[0] && source[1] == target[1];
    }

    bool isDiagonal(vector<int>& source, vector<int>& target) {
        return abs(source[0] - target[0]) == abs(source[1] - target[1]);
    }

    bool isSameRowOrColumn(vector<int>& source, vector<int>& target) {
        return source[0] == target[0] || source[1] == target[1];
    }
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
        if (sameSquare(source, target)) {
            return 0;
        }

        if (isSameRowOrColumn(source, target) || isDiagonal(source, target)) {
            return 1;
        }
        
        return 2;
    }
};

int main() {
    Solution solution;
    // case 1:
    vector<int> source = {0, 0};
    vector<int> target = {1, 1};
    cout << "Min Queen moves from (" 
         << source[0] << ", " << source[1] 
         << ") to (" << target[0] << ", " 
         << target[1] << ") is: " 
         << solution.minQueenMoves(source, target) << endl;

    // case 2:
    source = {0, 0};
    target = {0, 1};
    cout << "Min Queen moves from (" 
         << source[0] << ", " << source[1] 
         << ") to (" << target[0] << ", " 
         << target[1] << ") is: " 
         << solution.minQueenMoves(source, target) << endl;

    // case 3:
    source = {0, 0};
    target = {1, 2};
    cout << "Min Queen moves from (" 
         << source[0] << ", " << source[1] 
         << ") to (" << target[0] << ", " 
         << target[1] << ") is: " 
         << solution.minQueenMoves(source, target) << endl;
    return 0;
}