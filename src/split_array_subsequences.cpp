// 659. Split Array into Consecutive Subsequences

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>


using namespace std;

class Solution 
{
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int, multiset<int>> seq;
        const int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            int newSeqSize = 1;
            if (seq.count(nums[i] - 1) && seq[nums[i] - 1].size())
            {
                auto& mset = seq[nums[i] - 1];
                newSeqSize = 1 + *mset.begin();
                mset.erase(mset.begin());
            }
            
            if (seq.count(nums[i]))
            {
                auto& tmset = seq[nums[i]];
                tmset.insert(newSeqSize);
            }
            else
            {                    
                seq[nums[i]] = multiset<int>({newSeqSize});
            }
        }
        
        for (auto& [k, mset] : seq)
        {
            for (auto e : mset)
            {
                if (e < 3) return false;
            }
        }
        
        return true;
    }
};


int main()
{
    vector<int> nums({1,2,3,3,4,4,5,5});
    Solution o;
    bool res = o.isPossible(nums);
    cout << "res: " << (res ? "true" : "false") << "\n";
    return 0;
}