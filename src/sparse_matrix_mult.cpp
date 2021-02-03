// 311. Sparse Matrix Multiplication

#include <iostream>
#include <vector>
#include <unordered_set>
#include "util.h"

using namespace std;
using Matrix = vector<vector<int>>;

class Solution 
{
public:    
    Matrix multiply(Matrix& a, Matrix& b) 
    {
        vector<unordered_set<int>> notNullB;
        const int r1 = a.size(), c1 = a[0].size(), r2 = b.size(), c2 = b[0].size();
        for (int j = 0; j < c2; ++j)
        {
            unordered_set<int> s({});
            for (int i = 0; i < r2; ++i)
            {
                if (b[i][j]) s.insert(i);
            }
            notNullB.push_back(s);
        }
        
        Matrix res(r1, vector<int>(c2, 0));
        
        for (int i = 0; i < r1; ++i)
        {
            for (int j = 0; j < c2; ++j)
            {
                for (auto k : notNullB[j])
                    res[i][j] += a[i][k] * b[k][j];
            }
        }
        
        return res;;
    }
};

int main()
{
    Matrix a({{1,0,0},{-1,0,3}}), b({{7,0,0},{0,0,0},{0,0,1}});
    Solution o;
    Matrix res = o.multiply(a, b);
    for (auto v : res)
    {
        cout << stringify_container(v.begin(), v.end()) << "\n";
    }
    return 0;
}