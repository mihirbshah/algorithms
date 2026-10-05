// 1287. Element Appearing More Than 25% In Sorted Array

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// For log(n) solution, refer https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/discuss/454060/Concise-O(logn)-solution-using-C%2B%2B-(beat-90)

class Solution 
{
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        const int minsize = floor(arr.size() * 0.25);
        int cnt = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (!i) ++cnt;
            else if (arr[i] == arr[i - 1]) ++cnt;
            else cnt = 1;
            
            if (cnt > minsize) return arr[i];
        }
        
        return -1;
    }
};

int main()
{
    return 0;
}