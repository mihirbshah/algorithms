// 1052. Grumpy Bookstore Owner

#include <iostream>
#include <vector>
#include <utility>
#include "util.h"

using namespace std;

class Solution 
{
public:
    /*
    int maxSatisfied(vector<int>& cs, vector<int>& grumpy, int X) 
    {
        auto satisfied = 0, m_add_satisfied = 0, add_satisfied = 0;
        for (auto i = 0; i < cs.size(); ++i) 
        {
            satisfied += grumpy[i] ? 0 : cs[i];
            add_satisfied += grumpy[i] ? cs[i] : 0;
            if (i >= X) add_satisfied -= grumpy[i - X] ? cs[i - X] : 0;
            m_add_satisfied = max(m_add_satisfied, add_satisfied);
        }
        return satisfied + m_add_satisfied;
    }
    */
    int maxSatisfied(vector<int>& cs, vector<int>& grumpy, int X) 
    {
        const int n = cs.size();
        vector<int> s1(n + 1, 0), s2(n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            s1[i + 1] = s1[i] + (grumpy[i] ? 0 : cs[i]);
            s2[i + 1] = s2[i] + cs[i];
        }
                
        int res = INT_MIN;
        for (int l = 1; l <= n - X + 1; ++l)
        {
            int r = l + X - 1;
            const int satisfiedCustToLeftOfWindow = s1[l - 1];
            const int satisfiedCustToRightOfWindow = s1[n] - s1[r];
            const int satisfiedCustomersInWindow = s2[r] - s2[l - 1];
            res = max(res,  satisfiedCustToLeftOfWindow + satisfiedCustToRightOfWindow + satisfiedCustomersInWindow);
        }
        return res;
    }
};

int main()
{
    vector<int> customers({1,0,1,2,1,1,7,5}), grumpy({0,1,0,1,0,1,0,1}); int X = 3;
    Solution o;
    int res = o.maxSatisfied(customers, grumpy, X);
    cout << "res: " << res << "\n";
    return 0;
}