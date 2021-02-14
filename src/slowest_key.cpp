// 1629. Slowest Key

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) 
    {
        char res = keysPressed[0];
        int maxTime = releaseTimes[0];
        for (int i = 1; i < keysPressed.size(); ++i)
        {
            const int n = releaseTimes[i] - releaseTimes[i - 1];
            if (n < maxTime) continue;
            if (n > maxTime)
            {
                maxTime = n;
                res = keysPressed[i];
            }
            else if (n == maxTime && keysPressed[i] > res)
            {
                res = keysPressed[i];
            }
        }
        return res;
    }
};

int main()
{
    //vector<int> t({9,29,49,50}); string s = "cbcd";
    vector<int> t({12,23,36,46,62}); string s = "spuda";
    Solution o;
    char res = o.slowestKey(t, s);
    cout << "res: " << res << "\n";
    return 0;
}