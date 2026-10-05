// 1710. Maximum Units on a Truck

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        vector<int> unitBoxes(1001, 0);
        for (const auto bt : boxTypes)
            unitBoxes[bt[1]] += bt[0];
        
        int res = 0;
        for (int i = unitBoxes.size() - 1; i >= 0 && truckSize; --i)
        {
            if (unitBoxes[i] && unitBoxes[i] <= truckSize)
            {
                res += (i * unitBoxes[i]);
                truckSize -= unitBoxes[i];
            }
            else if (truckSize && unitBoxes[i] > truckSize)
            {
                res += (i * truckSize);
                truckSize = 0;
            }
        }
        return res;
    }
};

int main()
{
    //vector<vector<int>> boxTypes = {{1,3},{2,2},{3,1}}; int truckSize = 4;
    vector<vector<int>> boxTypes = {{5,10},{2,5},{4,7},{3,9}}; int truckSize = 10;
    
    Solution o;
    int res = o.maximumUnits(boxTypes, truckSize);
    cout << "res: " << res << "\n";
    return 0;
}