#include <iostream>
#include <vector>

using namespace std;

int maxOnes(vector<int>& v, int k)
{
  vector<int> zeros = {-1};
  for (int i = 0; i < v.size(); ++i)
  {
    if (!v[i]) zeros.push_back(i);
  }
  zeros.push_back(v.size());
  /*for (auto e : zeros)
  {
    cout << e << " ";
  }

  cout << "\n\n";*/

  if (zeros.size() == 2) return v.size();
  if (zeros.size() - 2 < k) k = zeros.size() - 2;

  int maxlenold = -1;
  int limit = ((zeros.size() - 2) - k) + 1;
  for (int i = 1; i <= limit; ++i)
  {
    int maxlennew = zeros[i+k] - zeros[i-1] - 1;
    if (maxlennew > maxlenold) maxlenold = maxlennew;
  }

  return maxlenold;
}
/*
int main()
{
  //vector<int> ip = {1,1,1,0,0,0,1,1,1,1,0}; int k = 2;
  //vector<int> ip = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}; int k = 3;
  //vector<int> ip = {1,0,1,1}; int k = 2;
  //vector<int> ip = {0,0,0,0,0}; int k = 3;
  vector<int> ip = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; int k = 6;
  cout << "max len: " << maxOnes(ip, k) << "\n";
  return 0;
}
*/
