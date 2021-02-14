// 1648. Sell Diminishing-Valued Colored Balls

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// solution gets TLE'ed
class Solution 
{
public:
    int maxProfit(vector<int>& inventory, int orders) 
    {
        const unsigned long MOD = 1e9 + 7;
        priority_queue<int> bq(inventory.begin(), inventory.end());
        unsigned long val = 0;
        while (orders && !bq.empty())
        {
            int n = bq.top();
            bq.pop();
            if (!bq.empty())
            {
                /*while (orders && (n >= bq.top()))
                {
                    val += (n % MOD);
                    --n; 
                    --orders;
                }
                if (n) bq.push(n);*/
                int take = n - bq.top() + 1;
                if (take > orders)
                {
                    val += ((((n * (n + 1ul)) / 2ul) - (((n - orders) * (n - orders + 1ul)) / 2ul)) % MOD);
                    orders = 0;      
                }
                else
                {
                    val += ((((n * (n + 1ul)) / 2ul) - (((n - take) * (n - take + 1ul)) / 2ul)) % MOD);
                    orders -= take;        
                }
                if (n - take) bq.push(n - take);
            }
            else
            {
                if (n > orders)
                {
                    val += ((((n * (n + 1ul)) / 2ul) - (((n - orders) * (n - orders + 1ul)) / 2ul)) % MOD);
                    orders = 0;
                }
                else
                {
                    val += (((orders * (orders + 1ul)) / 2ul) % MOD);
                    orders -= n;
                }
            }            
        }
        return val;
    }
};

int main()
{
    vector<int> inv({2,5}); int orders = 4;
    //vector<int> inv({3,5}); int orders = 6;
    //vector<int> inv({2,8,4,10,6}); int orders = 20;
    //vector<int> inv({1000000000}); int orders = 1000000000;
    Solution o;
    int res = o.maxProfit(inv, orders);
    cout << "res: " << res << "\n";
    return 0;
}