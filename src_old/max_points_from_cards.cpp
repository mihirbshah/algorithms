#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int maxScore(vector<int>& cardPoints, int k)
{
  /*
  int left = accumulate(cardPoints.begin(), cardPoints.begin()+k, 0);
  int right = 0, res = left, n = cardPoints.size();
  for (int i = 0; i < k; ++i)
  {
    left -= cardPoints[k - 1 - i];
    right += cardPoints[n - 1 - i];
    res = max(res, left + right);
  }

  return res;
  */

    int res = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
    int l = k - 1, r = cardPoints.size() - 1, lsum = res, rsum = 0;
    while (l >= 0)
    {
        lsum -= cardPoints[l--];
        rsum += cardPoints[r--];
        res = max(res, lsum + rsum);
    }
    return res;
}

int main()
{
  vector<int> v1 = {9,7,5,3,4,5,100,7,9}; int k1 = 3;
  int res = maxScore(v1, k1);
  cout << "res: " << res << "\n";
  return 0;
}
