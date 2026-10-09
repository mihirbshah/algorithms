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
// Intuition
// Process the intervals from left to right by sorting them according to their starting points. When an interval begins, it intersects every previously processed interval that has not ended before its start.

// A min-heap can store the endpoints of these active intervals. Before processing a new interval, remove every ending point that is strictly smaller than the new start. We use < start, not <= start, because closed intervals that share an endpoint still intersect.

// Approach
// Sort the intervals by their starting points.

// Maintain a min-heap containing the endpoints of active intervals.

// For each interval [start, end]:

// Remove every active interval whose end is less than start.
// Every interval remaining in the heap intersects the current interval, so add the heap size to the answer.
// Add the current interval's end to the heap.
// Return the accumulated number of pairs.

// Each pair is counted exactly once when the second interval in the sorted order is processed.
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        // sort intervals by their starting point
        std::sort(intervals.begin(), intervals.end());

        // use a min-heap to keep track of the ending points of active intervals
        std::priority_queue<int, std::vector<int>, std::greater<int>> activeIntervals;
        int count = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            // remove active intervals from the heap that STRICTLY end before the current interval starts
            while (!activeIntervals.empty() && activeIntervals.top() < intervals[i][0]) {
                activeIntervals.pop();
            }
            // all remaining intervals in the heap intersect with the current interval
            count += activeIntervals.size();
            // add the current interval end point to the heap of active intervals for the future intersections
            activeIntervals.push(intervals[i][1]);
        }
        return count;
    }
};