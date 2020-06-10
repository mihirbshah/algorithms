#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

class Solution {
public:
    int numberWaysDP(vector<vector<int>>& hats) {
        vector<vector<int>> h2p(40 + 1);
        const int n(hats.size()), mod(1e9 + 7);
		
		// masks range from 00...0 to 11...1 (n-digit binary number)
		// i-th digit represents whether i-th person has already had a hat
		// Base case: no one has a hat at first
        vector<int> masks(1 << n);
        masks[0] = 1;

        vector<vector<int>> dp;
        for (int i = 0; i <= 40; ++i)
        {
          vector<int> v(1 << n, 0);
          v[0] = 1;
          dp.push_back(v);
        }
        
		// re-organize, hats -> h2p
        for (int i = 0; i < n; ++i)
            for (const int& h: hats[i])
                h2p[h+1].emplace_back(i);


        for (int i = 1; i <= 40; ++i) {                    // hats
            cout << "== hat number: " << i << " == \n";
            for (int j = (1 << n) - 1; j >= 0; --j) {     // masks
                cout << "\t** mask index: " << j << " **\n";
                for (const int& p: h2p[i]) {          // h2p
					// if the current state j implies that p-th person hasn't had a hat yet
					// we can give the i-th hat to that person, and update the state
                    if ((j & (1 << p)) == 0) {
                        dp[i][j | (1 << p)] += dp[i-1][j];
                        dp[i][j | (1 << p)] %= mod;
                    }
                    cout << "\t\t person: " << p << ", mask: " << stringify_container(dp[i].begin(), dp[i].end()) << "\n";
                }
            }
        }
        // return the state that each person has a hat
        return dp[n][(1 << n) - 1];
    }

/*    int numberWaysRev(vector<vector<int>>& hats) {
        const int n = 40, mod(1e9 + 7);
        vector<int> masks(1 << n);
        masks[0] = 1;
        
        for (int i = 0; i < hats.size(); ++i) {                    
            //cout << "== person number: " << i << " == \n";
            for (long long j = (1 << n) - 1; j >= 0; --j) {  
                //cout << "\t** mask index: " << j << " **\n";
                for (const int& h: hats[i]) {         
                    if ((j & (1 << h)) == 0) {
                        masks[j | (1 << h)] += masks[j];
                        masks[j | (1 << h)] %= mod;
                    }
                    //cout << "\t\t hat: " << h << ", mask: " << stringify_container(masks.begin(), masks.end()) << "\n";
                }
            }
        }
        return masks[(1 << n) - 1];
    }
*/
    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> h2p(40);
        const int n(hats.size()), mod(1e9 + 7);
		
        vector<int> masks(1 << n);
        masks[0] = 1;
        
        for (int i = 0; i < n; ++i)
            for (const int& h: hats[i])
                h2p[h - 1].emplace_back(i);

        for (int i = 0; i < 40; ++i) 
        {                    
            cout << "== hat number: " << i << " == \n";
            for (int j = (1 << n) - 1; j >= 0; --j) 
            {     
                cout << "\t** mask index: " << j << " **\n";
                for (const int& p: h2p[i]) 
                {          
                    if ((j & (1 << p)) == 0) 
                    {
                        masks[j | (1 << p)] += masks[j];
                        masks[j | (1 << p)] %= mod;
                    }
                    cout << "\t\t person: " << p << ", mask: " << stringify_container(masks.begin(), masks.end()) << "\n";
                }
            }
        }
        return masks[(1 << n) - 1];
    }
};

int main()
{
  vector<vector<int>> hats = {{1,2,3}, {1,2,3}, {1,3,4}};
  Solution s;
  int ways = s.numberWays(hats);
  cout << "ways: " << ways << "\n";
  return 0;
}
