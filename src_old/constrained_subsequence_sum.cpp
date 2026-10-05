#include <deque>
#include <iostream>
#include "util.h"
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

/*int constrainedSubsetSum(vector<int>& A, int k) 
{
  cout << "Input: " << stringify_container(A.begin(), A.end()) << "\n";
  deque<int> q;
  int res = A[0];
  for (int i = 0; i < A.size(); ++i) 
  {
    cout << "Pre: i: " << i << ", A[i]: " << A[i] << ", res: " << res << ", q: " << stringify_container(q.begin(), q.end()) << "\n";
    A[i] += q.size() ? q.front() : 0;
    res = max(res, A[i]);
    while (q.size() && A[i] > q.back())
    {
      q.pop_back();
    }

    if (A[i] > 0)
    {
      q.push_back(A[i]);
    }

    if (i >= k && q.size() && q.front() == A[i - k])
    {
      q.pop_front();
    }
    cout << "Post: i: " << i << ", A[i]: " << A[i] << ", res: " << res << ", q: " << stringify_container(q.begin(), q.end()) << "\n";
  }
  return res;
}

int constrainedSubsetSum1(vector<int>& A, int k)
{
  vector<int> dp(A.size(), INT_MIN);
  cout << "Pre dp: " << stringify_container(dp.begin(), dp.end()) << "\n";
  for (int i = 0; i < A.size(); ++i)
  {
    int maxsum = 0;
    for (int j = 1; (j <= k) && (i - j >= 0); ++j)
    {
      maxsum = max(maxsum, dp[i-j]);
    }
    dp[i] = A[i] + maxsum;
  }
  cout << "Post dp: " << stringify_container(dp.begin(), dp.end()) << "\n";
  return *max_element(dp.begin(), dp.end());
}
*/

    int constrainedSubsetSum(vector<int>& A, int k) {
        deque<int> q;
        vector<int> dp(A.size(), 0);
        int res = A[0];
            cout << "A: " << stringify_container(A.begin(), A.end()) << "\n";
            cout << "q: " << stringify_container(q.begin(), q.end()) << "\n";
        for (int i = 0; i < A.size(); ++i) {
            A[i] += q.size() ? q.front() : 0;
            res = max(res, A[i]);
            while (q.size() && A[i] > q.back())
                q.pop_back();
            if (A[i] > 0)
                q.push_back(A[i]);
            if (i >= k && q.size() && q.front() == A[i - k])
                q.pop_front();
            cout << "A: " << stringify_container(A.begin(), A.end()) << "\n";
            cout << "q: " << stringify_container(q.begin(), q.end()) << "\n";
        }
        return res;
    }

int constrainedSubsetSum1(const vector<int>& arr, int windowSize)
{
  deque<int> dq; 
  vector<int> dp(arr);

  for (int i = 0; i < dp.size(); ++i)
  {  
    // We calculate max for each window after we are done processing all elements for that window. 
    // So don't try to find the max until the first 'windowSize' elements have been processed.
    if (!dq.empty())
    {
      dp[i] += max(dp[dq.front()], 0);
    }

    // Before processing the next window elements, remove all the elements from deque that belong to the previous window. 
    // While processing each window, its elements are inserted from the back of the queue. So the front of
    // the queue will hold the oldest elements in the window and the back will hold the most recent elements
    // in the window. That is why we pop from front here.
    while(!dq.empty() && dq.front() <= i-windowSize)
    {   
      dq.pop_front();
    }   

    // Discard all elements in the queue for the current window that are smaller than a[i]
    // The reasoning for this is explained above.
    while(!dq.empty() && dp[i] >= dp[dq.back()])
    {   
      dq.pop_back();
    }   

    // Insert a[i] in the queue. 
    // Note that this indicates that every element will go in the queue exactly once. 
    // If it is larger than existing elements in the queue, we discard those existing elements before inserting this one.
    // If it is smaller than existing elements in the queue, then it can be a candidate to become the max element
    // for a future window. Thus we insert it in the queue. 
    dq.push_back(i);
    cout << "dq: " << stringify_container(dq.begin(), dq.end()) << "\n";  
    cout << "dp: " << stringify_container(dp.begin(), dp.end()) << "\n";  
  }   
  
  return *max_element(dp.begin(), dp.end());
}

int main()
{
  vector<int> v1 = {10,2,-10,5,20}; int k1 = 2;
  vector<int> v2 = {-1,-2,-3}; int k2 = 1;
  vector<int> v3 = {10,-2,-10,-5,1}; int k3 = 2;
  vector<int> v4 = {-5266,4019,7336,-3681,-5767}; int k4 = 2;
  vector<int> v5 = {1,-3,9,1,-7,6,8}; int k5 = 2;
  int res = constrainedSubsetSum1(v5, k5);
  cout << "result: " << res << "\n";
  return 0;
}
