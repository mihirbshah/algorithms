// 295. Find Median from Data Stream

#include <iostream>
#include <queue>
#include <functional>

using namespace std;

/*
My solution was to partition the input into N fixed size partitions and use a 
vector<map<int>> where,
v[0] is 1st partition (first x numbers), v[1] is second partition (second x numbers) etc.
where x could be 100000
Given a number num, it's partition can be determined in O(1) as (num / x) {for now assume num is +ve}
And insertion into that partition takes max O(log(100000)) i.e. constant.
Now, we can also maintain  a total count of numbers so far as C.

To find a median, we need C/2th number is C is odd or mean(C-1/2th, C+1/2th) number. 
Now, we need to traverse each partition starting with 0 to find which one would contain our median. This would be O(N) 
where N is number os partitions. 
And finally get the median from that partition in max O(log(100000)) i.e. constant.

So addNum would take O(1) and findMedian would take O(N)
*/

// Solution copied from https://leetcode.com/problems/find-median-from-data-stream/discuss/74163/My-C%2B%2B-priority_queue-based-solution-(140-ms)
class MedianFinder 
{
public:
    void addNum(int num) 
    {
        if (firstq.empty() || firstq.top() > num) firstq.push(num);
        else secondq.push(num);
        
        const int m = firstq.size(), n = secondq.size();
        if (m - n > 1)
        {
            secondq.push(firstq.top());
            firstq.pop();
        }
        else if (n - m > 1)
        {
            firstq.push(secondq.top());
            secondq.pop();
        }
    }
    
    double findMedian() 
    {   
        const int m = firstq.size(), n = secondq.size();
        if (m == n) return (firstq.top() + secondq.top()) / 2.0;
        else if (m > n) return firstq.top();
        else return secondq.top();
    }
    
private:
    priority_queue<int, vector<int>, std::less_equal<int>> firstq;
    priority_queue<int, vector<int>, std::greater<int>> secondq;
};


int main()
{
    return 0;
}