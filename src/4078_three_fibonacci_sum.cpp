#include <iostream>

using namespace std;

class Solution {
    bool isPerfectSquare(long long x) {
        if (x < 0) return false;
        long long sqrt_x = sqrt(x);
        return sqrt_x * sqrt_x == x;
    }

    bool isFibonacci(long long n) {
        return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
    } 
public:
    bool threeFibonacciSum(int n) {
        if (n % 2 != 0) return false; 
        return isFibonacci((long long)n / 2);
    }
};