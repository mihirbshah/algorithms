// 1460. Make Two Arrays Equal by Reversing Sub-arrays

#include <iostream>
#include <vector>
#include <unordered_multiset>

using namespace std;

class Solution 
{
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) 
    {
        return unordered_multiset<int>(target.begin(), target.end()) == 
        unordered_multiset<int>(arr.begin(), arr.end());
    }
};

int main()
{
    return 0;
}