// 1010. Pairs of Songs With Total Durations Divisible by 60

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        unordered_map<int, int> cnt;
        int res = 0;
        for (int t : time)
        {
            /*
            If t % 60 != 0, then we need to pair t with another number N such that
            N % 60 = 60 - (t % 60)
            
            If t % 60 == 0, then we need to pait t with another number N such that
            N % 60 = 0
            
            So, the equation 60 - (t % 60) can be either non-zero or zero. 
            We can account for both cases by doing another  %60 i.e. 
            (60 - (t % 60)) % 60
            */
            res += cnt[(60 - (t % 60)) % 60];
            ++cnt[t % 60];
        }
        return res;
    }
};

int main()
{
    //vector<int> time({60,60,60});
    vector<int> time({30,20,150,100,40});
    Solution o;
    int res = o.numPairsDivisibleBy60(time);
    cout << "res: " << res << "\n";
    return 0;
}