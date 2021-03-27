// 1281. Subtract the Product and Sum of Digits of an Integer

#include <iostream>

using namespace std;

class Solution 
{
public:
    int subtractProductAndSum(int n) 
    {
        int product = 1, sum = 0;
        while (n)
        {
            int d = n % 10;
            n /= 10;
            product *= d; sum += d;
        }
        return product - sum;
    }
};

int main()
{
    return 0;
}