// 1314. Matrix Block Sum

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

class Solution 
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) 
    {
        const int m = mat.size(), n = mat[0].size(), window = 2 * K + 1;
        _m = m; _n = n;
        vector<vector<int>> ps(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // ps[i,j] = ps[i - 1][j] + ps[i][j - 1] - ps[i -1][j - 1] + m[i][j]
                const int e1 = rowValid(i - 1) && colValid(j) ? ps[i - 1][j] : 0;
                const int e2 = rowValid(i) && colValid(j - 1) ? ps[i][j - 1] : 0;
                const int e3 = rowValid(i - 1) && colValid(j - 1) ? ps[i - 1][j - 1] : 0;
                const int e4 = mat[i][j];
                ps[i][j] = e1 + e2 - e3 + e4;
            }
        }
        
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                const int rl = max(0, i - K), ru = min(m - 1, i + K), cl = max(0, j - K), cu = min(n - 1, j + K);
                const int e1 = rowValid(ru) && colValid(cu) ? ps[ru][cu] : 0;
                const int e2 = rowValid(ru) && colValid(cl - 1) ? ps[ru][cl - 1] : 0;
                const int e3 = rowValid(rl - 1) && colValid(cu) ? ps[rl - 1][cu] : 0;
                const int e4 = rowValid(rl - 1) && colValid(cl - 1) ? ps[rl - 1][cl - 1] : 0;
                res[i][j] = e1 - e2 - e3 + e4;
            }
        }
        
        return res;
    }
    
private:
    bool rowValid(int r) { return r >= 0 && r < _m; }
    bool colValid(int c) { return c >= 0 && c < _n; }
    int _m, _n;
};

int main()
{
    vector<vector<int>> mat({{1,2,3},{4,5,6},{7,8,9}}); int K = 2;
    Solution o;
    vector<vector<int>> res = o.matrixBlockSum(mat, K);
    for (auto v : res)
    {
        print_container(v.begin(), v.end());
        cout << "\n";
    }
    return 0;
}