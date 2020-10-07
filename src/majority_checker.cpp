#include <iostream>
#include <vector>

using namespace std;

namespace
{
    using List1D = vector<int>;
    using List2D = vector<vector<int>>;
    const int MAX_ELEMENT_VAL = 20000;
}

class MajorityChecker 
{
public:
    MajorityChecker(List1D& arr) 
    {
        List1D runningCounts(MAX_ELEMENT_VAL, 0);
        // dummy row with all 0's to simply code later
        _prefixCounts.push_back(runningCounts);
        
        for (int i = 1; i <= arr.size(); ++i)
        {
            ++runningCounts[arr[i-1]];
            _prefixCounts.push_back(runningCounts);
        }
    }
    
    int query(int left, int right, int threshold) 
    {
        /*for (int i = 0; i <= 6; ++i)
        {
            for (int j = 0; j <= 6; ++j)
            {
                cout << _prefixCounts[i][j] << ", ";
            }
            cout << "\n";
        }*/
        
        // C++2x but O(n) space
        List1D subarrCounts(MAX_ELEMENT_VAL, 0);
        std::transform(_prefixCounts[right+1].begin(), 
                       _prefixCounts[right+1].end(), 
                       _prefixCounts[left].begin(), 
                       subarrCounts.begin(), 
                       std::minus<int>());        
        auto it = find_if(subarrCounts.begin(), subarrCounts.end(), [&](int e){ return e >= threshold; });
        return it == subarrCounts.end() ? -1 : distance(subarrCounts.begin(), it);
        
        /* C++98 but O(1) space
        const List1D& rList = _prefixCounts[right+1], lList = _prefixCounts[left];
        for (int i = 0; i < MAX_ELEMENT_VAL; ++i)
        {
            if (rList[i] - lList[i] >= threshold) return i;
        }
        return -1;
        */
    }
    
private:
    List2D _prefixCounts;
};

int main()
{
    List1D v = {1,1,2,2,1,1};
    MajorityChecker o(v);
    int res = o.query(2,3,2);
    cout << "res: " << res << "\n";
    return 0;
}