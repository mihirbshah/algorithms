#include <iostream>
#include <vector>
#include <string>
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/stone-game-iii/

Let dp[i] be the best net value we can get by considering elements from i to end
For a given position 'i', Alice can select i, i/i+1, i/i+1/i+2 elements
a. If she selects 'i' element, then the net value she can attain is: A[i] - dp[i+1]
b. If she selects 'i/i+1' elements, then the net value she can attain is: (A[i] + A[i+1]) - dp[i+2]
c. If she selects 'i/i+1/i+2' elements, then the net value she can attain is: (A[i] + A[i+1] + A[i+2]) - dp[i+3]
She will chose the option that will yield the highest net value for her i.e. max (a., b., c.)
If we continue doing this from end until first element, then dp[0] will give the final net value Alice
can attain while considering elements from 0 - n.
If this net result is >0, Alice wins, <0, Bob wins, =0, Tie. 
*/

/*
Note on Top down v/s Bottonm up

This problem also illustrates Top down and Bottom up approaches clearly. 
In both approaches, we will break a problem into sub problems, find the answer to the subproblems,
and then use that to formulate the answer for the main problem.

In Top down, we will break a problem into subproblems for whom we do not have an answer yet.
We will successively break into subproblems until we reach a problem size that cannot be 
broken further. At that point, we determine its answer and then accumulate subproblem answers
to find the answer for its mian problem. 
For e.g. in above problem, if we start with 1st element, then the subproblem is 2nd - nth element

In Bottom up, we will break a problem into subproblems for whom we already know the answer. 
And we progressively increase the problem size by adding onto the subproblem to get a bigger
sized problem and then finding its solution by using the solution of the subproblem.
For e.g. in above problem, if we start from the end, we already know the answer for one element
And we keep adding one element at a time to this subproblem and find the answer for the bigger problem. 
*/
string stoneGameIII(vector<int>& A) 
{
    int n = A.size();
    vector<int> dp(n, INT_MIN);
        
    for (int i = n - 1; i >= 0; --i) 
    {
        int take = 0;
        for (int k = 0; k < 3 && i + k < n; ++k) 
        {
            take += A[i + k];
            dp[i] = max(dp[i], take - (i + k + 1 < n ? dp[i + k + 1] : 0));
        }
    }
        
    return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");    
}

string _stoneGameIII(vector<int>& A) 
{
    cout << "Input: " << stringify_container(A.begin(), A.end()) << "\n";
    vector<int> dp(4);
    for (int i = A.size() - 1; i >= 0; --i) 
    {
        cout << "i: " << i << ", [Pre] dp: " << stringify_container(dp.begin(), dp.end()) << "\n";
        dp[i % 4] = INT_MIN;
        int take = 0;
        for (int k = 0; k < 3 && i + k < A.size(); ++k)
        {
            take += A[i + k];
            dp[i % 4] = max(dp[i % 4], take - dp[(i + k + 1) % 4]);
        }
        cout << "i: " << i << ", [Post] dp: " << stringify_container(dp.begin(), dp.end()) << "\n";
    } 
    
    return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob"); 
}

int main()
{
    vector<int> v2 = {1,2,3,7};
    vector<int> v1 = {1,2,3,-1,-2,-3,7};
    
    string res = stoneGameIII(v1);
    cout << "result: " << res << "\n";
    return 0;
}