// 843. Guess the Word

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    void findSecretWord(vector<string>& wordlist, Master& master) 
    {
        int x = 0;
        for (int i = 0; i < 10; ++i)
        {
            string guessWord = wordlist[getNextGuessPosition_minimax(wordlist)];
            x = master.guess(guessWord);
            if (x == 6) return;
            vector<string> wordlist2;
            for (const auto& w : wordlist)
            {
                if (match(guessWord, w) == x) wordlist2.push_back(w);
            }
            wordlist.swap(wordlist2);
        }
    }
    
private:
    int getNextGuessPosition_random(const vector<string>& wordlist)
    {
        return rand() % wordlist.size();
    }
    
    int getNextGuessPosition_minimax(const vector<string>& wordlist)
    {
        unordered_map<string, int> zeroCount;
        for (const auto w1 : wordlist)
        {
            for (const auto& w2 : wordlist)
            {
                zeroCount[w1] += !match(w1, w2);
            }
        }
        
        int currMin = INT_MAX;
        int pos = -1;
        for (int i = 0; i < wordlist.size(); ++i)
        {
            if (zeroCount[wordlist[i]] < currMin) 
            {
                pos = i;
                currMin = zeroCount[wordlist[i]];
            }
        }
        
        return pos;
    }
    
    int match(const string& w1, const string& w2)
    {
        int c = 0;
        for (int i = 0; i < w1.size(); ++i) c += (w1[i] == w2[i]);
        return c;
    }
};

int main()
{
    return 0;
}