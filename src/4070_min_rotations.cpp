#include <string>
#include <array>
#include <iostream>
using namespace std;

class Solution {
    array<int, 10> lower = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> upper = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    int minRotation(char src, char dst) {
        int big = max(src, dst) - '0'; 
        int small = min(src, dst) - '0';
        return min(big - small, upper[small] - lower[big]);
    }
public:
    int minRotations(string s) {
        string t = "0" + s;
        int rotations = 0;
        for (int i = 0; i < t.size() - 1; ++i) {
            rotations += minRotation(t[i], t[i + 1]);
        }
        return rotations;
    }
};