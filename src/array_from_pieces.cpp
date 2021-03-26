// 1640. Check Array Formation Through Concatenation

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, int> ps;
        for (int i = 0; i < pieces.size(); ++i)
            ps[pieces[i][0]] = i;

        for (int i = 0; i < arr.size(); ) {
            int p = ps.count(arr[i]) ? ps[arr[i]] : -1, j = 0;
            if (p == -1)
                return false;
            while (j < pieces[p].size())
                if (arr[i++] != pieces[p][j++])
                    return false;
        }
        return true;
    }
};

int main()
{
    return 0;
}