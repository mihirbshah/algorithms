// 1428. Leftmost Column with at Least a One

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class BinaryMatrix
{
public:
    BinaryMatrix(const vector<vector<int>> mat) : _mat(mat) {}
    int get(int row, int col)
    {
        return _mat[row][col];
    }
    
    vector<int> dimensions()
    {
        int r = _mat.size(), c = _mat[0].size();
        vector<int> v({r, c});
        return v;
    }
    
private:
    vector<vector<int>> _mat;
};

class Solution 
{
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) 
    {
        const vector<int> dimensions = binaryMatrix.dimensions();
        const int rows = dimensions[0], cols = dimensions[1];
        int leftmost = cols; 
        int temp = -1;
        for (int i = 0; i < rows; ++i)
        {
            int left = 0;
            temp = binSearch(binaryMatrix, i, 0, leftmost);
            leftmost = temp == -1 && i < rows - 1 ? cols : temp;
            cout << "temp: " << temp << ", leftmost: " << leftmost << "\n";
        }
        return leftmost;
    }
    
private:
    int binSearch(BinaryMatrix& binMat, int row, int start, int end)
    {
        cout << "start: " << start << ", end: " << end << "\n";
        if (start >= end)
        {
            cout << "[1] i: " << row << ", j: " << end << "\n";
            if (binMat.get(row, end)) return end;
            else return -1;
        }
        const int mid = start + (end - start) / 2;
        cout << "[2] i: " << row << ", j: " << mid << "\n";
        int pos = binMat.get(row, mid);
        if (pos)
        {
            //int prevPos = binMat.get(row, mid);
            //if (!prevPos) return pos;
            return binSearch(binMat, row, start, mid);
        }
        else
        {
            return binSearch(binMat, row, mid + 1, end);
        }
    }
};

int main()
{
    BinaryMatrix bmat({{0,0}, {1,1}});
    Solution o;
    int res = o.leftMostColumnWithOne(bmat);
    cout << "res: " << res << "\n";
    return 0;
}