#include <iostream>
#include <vector>
#include <utility>

using namespace std;

/*
https://leetcode.com/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/

Brute force way is to find all possible combinations of sums and then pick the kth lowest sum. 
This can be done by taking 2 rows at a time, and summing every element of row-1 with every element of row-2,
and store the result in res.
Now, repeat the same steps with res (as row-1) and row-3 (as row-2). This way, continue till the last row. 

Optimization:
At every step, once we calculate res, we only need the lowest min(k, res.size()) number of elements from it 
for the next iteration. This way we can prune the element space to keep it in check. 

The reason why this is true is because, let's say we have 2 sets (x1, x2, x3) and (y1, y2, y3).
And we have to find the 2nd lowest pairwise sum for each pair (x,y).
Then, we can simply pick the top 2 lowest numbers from set-1 and then sum them with all numbers from set-2.
*/
class Solution
{
public:
    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        /*
        vector<int> row = mat[0];
        for (int i = 1; i < mat.size(); ++i)
        {
            vector<int> nr;
            for (int j = 0; j < mat[i].size(); ++j)
            {
                for (auto n : row)
                {
                    nr.push_back(n + mat[i][j]);
                }
            }
            sort(nr.begin(), nr.end());
            nr.resize(min(k, static_cast<int>(nr.size())));
            row = move(nr);
        }
        return row.back();
        */
        vector<int> cols(mat.size(), 0);
        int sum = 0;
        for (int i = 0; i < cols.size(); ++i) sum += mat[i][cols[i]];
        int res = 0;
        func(mat, cols, sum, k - 1, res);
        return res;
    }
    
private:
    void func(vector<vector<int>>& mat, vector<int>& cols, int sum, int k, int& res)
    {
        if (k == 1) 
        {
            res = sum;
            return;
        }
        
        int rsum = INT_MAX, index = -1;
        for (int i = 0; i < cols.size(); ++i)
        {
            int nsum = sum;
            nsum -= mat[i][cols[i]];
            nsum += mat[i][cols[i] + 1];
            if (nsum < rsum)
            {
                rsum = nsum;
                index = i;
            }
        }
        
        ++cols[index];
        func(mat, cols, rsum, k - 1, res);
    }
};

int main()
{
    Solution o;
    vector<vector<int>> v1 = {{1,3,11}, {2,4,6}}; int k1 = 5;
    int res = o.kthSmallest(v1, k1);
    cout << "res: " << res << "\n";
    return 0;
}