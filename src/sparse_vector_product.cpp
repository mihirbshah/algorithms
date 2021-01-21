// 1570. Dot Product of Two Sparse Vectors


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SparseVector 
{
public:
    SparseVector(vector<int> &nums) 
    {
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i])
            {
                vecmap[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) 
    {
        int product = 0;
        for (const auto& [key, val] : vecmap)
        {
            if (vec.vecmap.count(key)) product += vec.vecmap[key] * val;
        }
        return product;
    }
    
    unordered_map<int, int> vecmap;
};

int main()
{
    vector<int> nums1({1,0,0,2,3});
    vector<int> nums2({0,3,0,4,0});
    SparseVector v1(nums1);
    SparseVector v2(nums2);
    int res = v1.dotProduct(v2);
    cout << "res: " << res << "\n";
    return 0;
}