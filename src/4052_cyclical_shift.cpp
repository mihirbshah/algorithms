#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<int> temp(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int newCol = (j - rowShift[i] + n) % n;
                temp[newCol] = grid[i][j];
            }
            grid[i] = temp;
        }

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                int newRow = (i - colShift[j] + n) % n;
                temp[newRow] = grid[i][j];
            }
            for (int i = 0; i < n; ++i) {
                grid[i][j] = temp[i];
            }
        }
        return grid;
    }
};

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution solution;
    // Test: Input: n = 2, grid = [[1,2],[3,4]], rowShift = [1,0], colShift = [0,1]
    int n = 2;
    vector<vector<int>> grid = {{1, 2}, {3, 4}};
    vector<int> rowShift = {1, 0};
    vector<int> colShift = {0, 1};
    vector<vector<int>> result = solution.cyclicShift(n, grid, rowShift, colShift);
    
    // Print the result
    printGrid(result);

    return 0;
}