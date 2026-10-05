//953. Verifying an Alien Dictionary


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        populatePositions(order);
        bool res = true;
        const int wordsLen = words.size();
        for (int i = 0; i < wordsLen - 1; ++i)
        {
            res &= lexCompare(words[i], words[i+1]);
        }
        return res;
    }
private:
    void populatePositions(const string& order)
    {
        int p = 0;
        for (const auto c : order) _pos[c] = p++;
    }
    
    bool lexCompare(const string& first, const string& second)
    {
        const int firstLen = first.size();
        const int secondLen = second.size();
        const int smallerLen = firstLen < secondLen ? firstLen : secondLen;
        for (int i = 0; i < smallerLen; ++i)
        {
            if (_pos[first[i]] > _pos[second[i]]) return false;
            else if (_pos[first[i]] < _pos[second[i]]) return true;
        }
        return firstLen > secondLen ? false : true;
    }
    
    unordered_map<char, int> _pos;
};

int main()
{
    Solution o;
    //vector<string> words = {"hello","leetcode"}; 
    //string order = "hlabcdefgijkmnopqrstuvwxyz";
    //vector<string> words = {"word","world","row"}; 
    //string order = "worldabcefghijkmnpqstuvxyz";
    vector<string> words = {"apple","app"}; 
    string order = "abcdefghijklmnopqrstuvwxyz";

    cout << "res: " << o.isAlienSorted(words, order) << "\n";
    return 0;
}