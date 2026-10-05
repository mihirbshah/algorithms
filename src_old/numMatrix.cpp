#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> IntVector;
typedef vector<IntVector> Matrix;

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

class NumMatrix
{
  public:
    NumMatrix(const Matrix& mat)
    {
      for (int i = 0; i < 1+mat.size(); ++i)
      {
        IntVector v(1+mat[0].size(), 0);
        dp.push_back(v);
      }

      for (int i = 0; i < mat.size(); ++i)
      {
        for (int j = 0; j < mat[0].size(); ++j)
        {
          dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + mat[i][j];
        }
      }
    }

    int sumRegion(int r1, int c1, int r2, int c2)
    {
      return dp[r2+1][c2+1] - dp[r2+1][c1] - dp[r1][c2+1] + dp[r1][c1];
    }

  private:
    Matrix dp;
};

int main()
{
  Matrix matrix = {{1,2}, {3,4}};
  NumMatrix* m = new NumMatrix(matrix);
  cout << "result: " << m->sumRegion(0,0,1,1) << "\n";
  return 0;
}
