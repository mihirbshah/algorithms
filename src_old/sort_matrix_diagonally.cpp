// 1329. Sort the Matrix Diagonally

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution 
{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        const int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; ++i)
        {
            int r = i, c = 0;
            vector<int> v;
            while (r < m && c < n)
            {
                v.push_back(mat[r++][c++]);
            }
            sort(v.begin(), v.end());
            r = i, c = 0;
            int j = 0;
            while (r < m && c < n) mat[r++][c++] = v[j++];
        }
        
        for (int i = 0; i < n; ++i)
        {
            int r = 0, c = i;
            vector<int> v;
            while (r < m && c < n)
            {
                v.push_back(mat[r++][c++]);
            }
            sort(v.begin(), v.end());
            r = 0, c = i;
            int j = 0;
            while (r < m && c < n) mat[r++][c++] = v[j++];
        }
        
        return mat;
    }
};

int main()
{
    return 0;
}