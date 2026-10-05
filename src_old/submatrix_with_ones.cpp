#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;

void print(const Matrix& mat)
{
  for (const auto& v : mat)
  {
    for (auto e : v)
    {
      cout << e << " ";
    }
    cout << "\n";
  }
}

class Solution
{
    public:
    int numSubmat(Matrix& mat)
    {
        Matrix dp(vector(1+mat.size(), vector(1+mat[0].size(), 0)));
        int res = 0;
        int rows = mat.size(), cols = mat[0].size();
        
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + mat[i][j];
            }
        }
                
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                for (int k = i; k < rows; ++k)
                {
                    for (int l = j; l < cols; ++l)
                    {
                        res += ((1+k-i) * (1+l-j)) == (dp[k+1][l+1] - dp[k+1][j] - dp[i][l+1] + dp[i][j]);
                        //cout << "i: " << i << ", j: " << j << ", k: " << k << ", l: " << l << ", res: " << res << "\n";
                    }
                }
            }
        }
        
        return res;
    }
};

int main()
{
    //Matrix m = {{1,0,1}, {1,1,0}, {1,1,0}};
    //Matrix m = {{0,1,1,0}, {0,1,1,1}, {1,1,1,0}};
    //Matrix m = {{1,1,1,1,1,1}};
    Matrix m = {{1,0,1}, {0,1,0}, {1,0,1}};
    Solution o;
    int res = o.numSubmat(m);
    cout << "res: " << res << "\n";
    return 0;
}