#include <iostream>
#include <deque>
#include <vector>
#include "util.h"

using namespace std;

/*
   This solution has been taken from here: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

   We use a deque to store the max element for each window and also potential candidates that
   can become max elements for future windows. For e.g. when processing window 1, we will store
   the max element in window 1 at deque.front(). And then it is possible that other elements in 
   window 1 that are smaller than max could end up being the max element for window 2. So we still
   need to store these as well in deque. 

   However, if we find an element that is >= current elements in deque for window 1, then we should 
   discard all such elements stored in the deque for window 1 since this new element is more recent
   than those elements. 
   
   Note that we store the indices for the elements in deque, not the element itself. This allows us
   to generalize the solution for other data types.
*/
vector<int> slidingWindowMax(const vector<int>& arr, int windowSize)
{
  deque<int> dq; 
  vector<int> max;

  for (int i = 0; i < arr.size(); ++i)
  {  
    // We calculate max for each window after we are done processing all elements for that window. 
    // So don't try to find the max until the first 'windowSize' elements have been processed.
    if (i >= windowSize && !dq.empty())
    {   
      max.emplace_back(arr[dq.front()]);
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
    while(!dq.empty() && arr[i] >= arr[dq.back()])
    {   
      dq.pop_back();
    }   

    // Insert a[i] in the queue. 
    // Note that this indicates that every element will go in the queue exactly once. 
    // If it is larger than existing elements in the queue, we discard those existing elements before inserting this one.
    // If it is smaller than existing elements in the queue, then it can be a candidate to become the max element
    // for a future window. Thus we insert it in the queue. 
    dq.push_back(i);
  }   

  max.emplace_back(arr[dq.front()]);
  return max;
}

int main()
{
	vector<int> v = {12, 1, 78, 90, 57,89, 56};
	int k = 3;
	vector<int> res = slidingWindowMax(v, k);
        cout << "maximums: " << stringify_container(res.begin(), res.end()) << "\n";
	return 0;
}
