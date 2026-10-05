// 1515. Best Position for a Service Centre

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution 
{
public:
    double getMinDistSum(vector<vector<int>>& positions) 
    {
        const int n = positions.size();
        if (n == 1) return 0;
        
        /*vector<int> x, y;
        for (auto p : positions)
        {
            x.push_back(p[0]);
            y.push_back(p[1]);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        */
        vector<double> start(2, 0);
        /*if (n % 2)
        {
            start[0] = x[n / 2];
            start[1] = y[n / 2];
        }
        else
        {
            start[0] = (x[n / 2] + x[n / 2 - 1]) / 2;
            start[1] = (y[n / 2] + y[n / 2 - 1]) / 2;
        }*/
        
        double steps = 100, epsilon = 1e-6;
        //double total = totalDist(positions, start);
        double total = DBL_MAX;
        while (steps > epsilon)
        {
            bool found = false;
            for (auto d : dir)
            {
                vector<double> nstart = {start[0] + steps * d[0], start[1] + steps * d[1]};
                double ntotal = totalDist(positions, nstart);
                if (ntotal < total)
                {
                    total = ntotal;
                    start = nstart;
                    found = true;
                    break;
                }
            }
            
            if (!found)
            {
                steps /= 10;
            }
        }
        
        return total;
    }
    
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    double dist(const vector<int>& a, const vector<double>& b)
    {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }
    
    double totalDist(vector<vector<int>>& positions, const vector<double>& a)
    {
        auto total = 0.0;
        for (auto p : positions)
        {
            total += dist(p, a);
        }
        return total;
    }
};

int main()
{
    return 0;
}