// 1668. Maximum Repeating Substring

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count=0;
        string temp=word;
        while(sequence.find(temp)!=string::npos)
        {
            count++;
            temp+=word;
        }
        return count;
    }
};

int main()
{
    string sequence = "ababc", word = "ab";
    Solution o;
    int res = o.maxRepeating(sequence, word);
    cout << "res: " << res << "\n";
    return 0;
}