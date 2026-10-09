#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// O(n^2) 
// class Solution {
//     static bool intersects(const vector<int>& a, const vector<int>& b) {
//         return max(a[0], b[0]) <= min(a[1], b[1]);
//     }

// public:
//     int countIntersectingIntervals(vector<vector<int>>& intervals) {
//         int count = 0;
//         for (int i = 0; i < intervals.size(); ++i) {
//             for (int j = i + 1; j < intervals.size(); ++j) {
//                 if (intersects(intervals[i], intervals[j])) {
//                     ++count;
//                 }
//             }
//         }
//         return count;
//     }
// };

// O(n log n) solution using a min-heap to track active intervals
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        // sort intervals by their starting point
        std::sort(intervals.begin(), intervals.end());

        // use a min-heap to keep track of the ending points of active intervals
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        int count = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            // remove active intervals from the heap that STRICTLY end before the current interval starts
            while (!minHeap.empty() && minHeap.top() < intervals[i][0]) {
                minHeap.pop();
            }
            // all remaining intervals in the heap intersect with the current interval
            count += minHeap.size();
            // add the current interval end point to the heap of active intervals for the future intersections
            minHeap.push(intervals[i][1]);
        }
        return count;
    }
};