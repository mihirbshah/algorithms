// 957. Prison Cells After N Days

#include <iostream>
#include <bitset>
#include <vector>
#include "util.h"
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Not working
// Refer to https://leetcode.com/problems/prison-cells-after-n-days/discuss/717989/Three-Solutions-with-Detailed-Explanation for working solution
class Solution 
{
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) 
    {
        bitset<8> bits, tbits;
        unordered_map<string, int> seen;
        
        for (int i = 0; i < 8; ++i) bits[i] = cells[i];
        if (N)
        {
            seen[bits.to_string()] = 0;
            tbits = bits;
            bits[0] = 0; bits[7] = 0;
            string s = bits.to_string();
            reverse(s.begin(), s.end());
            cout << "d: 0, bits: " << s << "\n";
        }
        
        bool found = false;
        int d = 0;
        for (; d < N; ++d)
        {
            for (int i = 1; i < 7; ++i) bits[i] = tbits[i-1] ^ tbits[i+1];
            tbits = bits;
            if (seen.count(bits.to_string()))
            {
                //d = 0;
                //d = int(N / (seen[bits.to_string()] + 1)) * (seen[bits.to_string()] + 1);
                found = true;
                for (int i = 0; i < 8; ++i) cells[i] = bits[i] ? 1 : 0;
                break;
            }
            string s = bits.to_string();
            reverse(s.begin(), s.end());
            cout << "d: " << d + 1 << ", bits: " << s << "\n";

            seen[bits.to_string()] = d + 1;
        }
        
        if (found) return prisonAfterNDays(cells, N % d);
        
        for (int i = 0; i < 8; ++i) cells[i] = bits[i] ? 1 : 0;
        
        return cells;
    }    
};

int main()
{
    vector<int> v({1,0,0,1,0,0,1,0}); int N = 1000000000;
    //vector<int> v({0,1,0,1,1,0,0,1}); int N = 7;
    Solution o;
    vector<int> res = o.prisonAfterNDays(v, N);
    print_container(res.begin(), res.end());
    return 0;
}