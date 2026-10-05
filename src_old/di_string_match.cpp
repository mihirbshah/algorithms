// 942. DI String Match

#include <iostream>
#include <string>
#include <vector>

class Solution 
{
public:
    vector<int> diStringMatch(string S) 
    {
        int i = 0, j = S.size();
        vector<int> res;
        for (auto c : S) res.push_back(c == 'I' ?  i++ : j--);
        res.push_back(S[S.size() - 1] == 'I' ? res.back() + 1 : res.back() - 1);
        return res;
    }
};

int main()
{
    return 0;
}