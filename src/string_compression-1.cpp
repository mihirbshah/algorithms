// 443. String Compression

#include <iostream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;

class Solution
{
public:
    int compress(vector<char>& s)
    {
        const int n = s.size();
        if (n == 1) return 1;
        int pos = 0, i = 0, j = 0;
        while (j < n)
        {
            int cnt = 0;
            while (s[j] == s[i])
            {
                ++j; 
                ++cnt;
                if (j >= n) 
                {
                    //--j;
                    break;
                }
            }
            cout << "i: " << i << ", j: " << j << ", pos: " << pos << ", cnt: " << cnt << "\n";
            s[pos++] = s[i];
            if (cnt > 1)
            {
                string rle = to_string(cnt);
                for (int k = 0; k < rle.size(); ++k) s[pos++] = rle[k];
            }
            i = j;
            //if (j == n - 1) break;
        }
        cout << "i: " << i << ", j: " << j << ", pos: " << pos << "\n";
        return pos;
    }
};

int main()
{
    vector<char> s({'a','a','b','b','c','c','c'});
    Solution o;
    int res = o.compress(s);
    cout << "res: " << res << "\n";
    cout << "s: " << stringify_container(s.begin(), s.end()) << "\n";
    return 0;
}