// 50. Pow(x, n)

#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution 
{
public:
    double myPowIterative(double x, int n) 
    {
        if (n == 0) return 1;
        if (n < 0)
        {
            n = abs(n);
            x = 1 / x;
        }

        double res = 1;
        while (n > 0)
        {
            if (n & 1) res *= x;
            n >>= 1;
            x *= x;
        }
        
        return res;
    }
    
    double myPowRecurse(double x, int n)
    {
        if (n == 0) return 1;
        if (n < 0)
        {
            n = abs(n);
            x = 1 / x;
        }
        double res = myPowRecurse(x * x, n >> 1);
        return n & 1 ? x * res : res;
    }    
};

int main()
{
    //double x = 2.0; int n = 10;
    //double x = 2.1; int n = 3;
    double x = 2.0; int n = -2;
    Solution o;
    double res = o.myPow(x, n);
    cout << "res: " << res << "\n";
    return 0;
}