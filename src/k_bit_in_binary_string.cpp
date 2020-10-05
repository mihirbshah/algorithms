#include <iostream>
#include <bitset>
#include <math.h>

using namespace std;

constexpr int MAXN = 20;

class Solution {
public:
    char findKthBit(int n, int k) {
        int i;
        bits[0] = 0;
        for (int c = 1; c <= n-1; ++c)
        {
            i = static_cast<int>(pow(2, c) - 2);
            bits[i+1] = 1;
            int m = i+2, n = 2 * i + 2, mid = i/2;
            for (int j = i; j >= mid; --j)
            {
                bits[m++] = not bits[j];
                if (n > m) bits[n--] = bits[j];
            }
        }
        
        //cout << "bits: " << bits.to_string() << "\n";
        
        return '0' + bits[k-1];
    }

private:
    bitset<MAXN> bits;
};

int main()
{
    Solution s;
    char res = s.findKthBit(2, 3);
    cout << "res: " << res << "\n";
    return 0;
}