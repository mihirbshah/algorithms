// 1213. Intersection of Three Sorted Arrays

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) 
    {
        const int l = arr1.size(), m = arr2.size(), n = arr3.size();
        const int s = min(l, min(m, n));
        vector<int> res;
        for (int i = 0, j = 0, k = 0; i < s && j < s && k < s;)
        {
            if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) res.push_back(arr1[i]);
            
            const int smallest = min(arr1[i], min(arr2[j], arr3[k]));
            if (smallest == arr1[i]) ++i;
            if (smallest == arr2[j]) ++j;
            if (smallest == arr3[k]) ++k;
        }            
        return res;
    }
};

int main()
{
    return 0;
}