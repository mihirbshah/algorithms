#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

// https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/

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

    /*
    Since we are only handling 1 person at a time, between 2 successive transitions, only 1 bit can change. So consider one such possible transition for e.g. 000 -> 001 -> 011 -> 111

mask[000]: no. of ways to assign hats where no one is assigned
mask[001]: no. of ways to assign hats where only 1st person is assigned
mask[011]: no. of ways to assign hats where only 1st and 2nd persons are assigned
mask[111]: no. of ways to assign hats where all 3 people are assigned

The main idea here is that while processing hat 'i', we have already processed hats 0 to 'i-1'. 
Thus, while processing hat 'i', we already know the no. of ways to assign hats 0 to 'i-1' to all the people. 
Since we are deriving the answer for hat 'i' based on the answer for hats 0 to 'i-1' we implicitly ensure that no two people will wear the same hat at the same time. 
This is why we first have the outermost for loop over all the hats.

Now, while handling hat 'i' and transitioning from 011 -> 111, we need to assign hat 'i' to the 3rd person. 
Since mask[011] represents the no. of ways to assign hats 0 to 'i-1' to 1st and 2nd persons, we can simply assign hat 'i' to the 3rd person for each of those ways
to move from 011 -> 111. This is why we do: masks[j | (1 << p)] += masks[j];

As you can see, it is important to first use the old value of mask[011] to update mask[111] before updating mask[011] to its new value representing hats 0 to 'i'. 
If we do the reverse i.e. first update mask[011] for hat 'i' and then use its value to update mask[111] then we'd be double counting the value of mask[011] while processing mask[111] for hat 'i'. 
This is the reason why we need to iterate through the masks in reverse order from 111 -> 011 -> 001 -> 000 for the above example.
*/
    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> h2p(40);
        const int n(hats.size()), mod(1e9 + 7);
        const int maxHats = 40;
		
        vector<int> masks(1 << n);
        masks[0] = 1;
        
        for (int i = 0; i < n; ++i)
            for (const int& h: hats[i])
                h2p[h - 1].emplace_back(i);

        for (int i = 0; i < maxHats; ++i) 
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
  //vector<vector<int>> hats = {{1,2,3}, {1,2,3}, {1,3,4}};
  vector<vector<int>> hats = {{1,2,3}, {1,2}};
  Solution s;
  int ways = s.numberWays(hats);
  cout << "ways: " << ways << "\n";
  return 0;
}
