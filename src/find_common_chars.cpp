// 1002. Find Common Characters

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    vector<string> commonChars(vector<string>& A) 
    {
        vector<int> master(26, INT_MAX);
        for (const auto& s : A)
        {
            vector<int> local(26, 0);
            for (int i = 0; i < s.size(); ++i) ++local[s[i] - 'a'];
            for (int i = 0; i < 26; ++i) master[i] = min(master[i], local[i]);
        }
        vector<string> res;
        for (int i = 0; i < 26; ++i)
        {
            while (master[i])
            {
                res.push_back(string(1, i + 'a'));
                --master[i];
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}