// 50. Pow(x, n)

#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution 
{
public:
    double myPow(double x, int n) 
    {
        if (!n) return 1;
        if (!x) return 0;
        if (x == 1.0) return 1;
        double res = powRecurse(x, abs(n));
        return n > 0 ? res : 1 / res;
    }
    
private:
    double powRecurse(double x, int n)
    {
        /*
        // recursive
        if (n == 1) return x;
        
        if (n % 2)
        {
            // odd
            double res = powRecurse(x, (n - 1) / 2);
            return x * res * res;
        }
        else
        {
            // even
            double res = powRecurse(x, n / 2);
            return res * res;
        }
        */
        
        if (n == 1) return x;
        double res = x;
        int i = 2;
        for (; i < n; i *= 2)
        {
            res *= res;
            //cout << "i: " << i << ", temp: " << res << "\n";
        }
        i /= 2;
        
        return n - i > 0 ? res * powRecurse(x, n - i) : res;
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