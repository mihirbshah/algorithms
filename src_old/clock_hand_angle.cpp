// 1344. Angle Between Hands of a Clock

#include <iostream>

using namespace std;

class Solution 
{
public:
    double angleClock(int hour, int minutes) 
    {
        double hangle = (hour % 12) * 30 + (minutes) * 0.5;
        double mangle = minutes * 6;
        double diff = abs(mangle - hangle);
        cout << "hangle: " << hangle << ", mangle: " << mangle << "\n";
        return diff > 180 ? 360 - diff : diff;
    }
};

int main()
{
    int h = 1, m = 57;
    Solution o;
    double res = o.angleClock(h, m);
    cout << "res: " << res << "\n";
    return 0;
}