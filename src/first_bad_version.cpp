// 278. First Bad Version

#include <iostream>

using namespace std;

class Solution 
{
public:
    int firstBadVersion(int n) 
    {
        return binSearch(1, n);
    }
    
private:
    int binSearch(int low, int high)
    {
        if (low == high) return low;
        int mid = low + (high - low) / 2;
        if (isBadVersion(mid)) return binSearch(low, mid);
        else return binSearch(mid + 1, high);
    }
};

int main()
{
    return 0;
}