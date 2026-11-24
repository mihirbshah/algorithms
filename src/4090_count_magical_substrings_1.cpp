#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {    
private:
    void removeChar(unordered_map<char, int>& charCount, char c) {
        if (charCount.find(c) != charCount.end()) {
            --charCount[c];
            if (charCount[c] <= 0) {
                charCount.erase(c);
            }
        }
    }

    void populateDistinctChars(const string& s) {
        distinctCharsArray.assign(s.length(), vector<int>(s.length(), 0));
        
        unordered_map<char, int> charCount;
        for (char c : s) {
            ++charCount[c];
        }

        for (int i = 0; i < s.length(); ++i) {
            auto tempCharCount = charCount; 
            for (int j = s.length() - 1; j >= i; --j) {
                auto val = tempCharCount.size();
                distinctCharsArray[i][j] = val;
                removeChar(tempCharCount, s[j]);
            }
            removeChar(charCount, s[i]);
        }
    }

    // o(n^2) solution
    // this function is copied from https://leetcode.com/problems/count-magical-substring-pairs-i/solutions/8586882/easy-intuition-very-easy-solution-by-abh-nabw/
    int getMagicalPairsCount(const string& s) {
        int n = s.length();
        int ans = 0;
        for(int j = 0; j < n - 1; j++){
            vector<int>leftFre(27,0);
            vector<int>rightFre(27,0);

            for(int i = 0; i <= j; i++){
                leftFre[distinctCharsArray[i][j]]++;
            }

            for(int k = j + 1; k < n; k++){
                rightFre[distinctCharsArray[j + 1][k]]++;
            }

            for(int d = 1; d <= 26; d++){
                ans += leftFre[d] * rightFre[d];
            }
        }
        return ans;
    }

    // o(n^3) solution
    int getMagicalPairsCount_old(const string& s) {
        int n = s.length();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int k = j+1; k < n; ++k) {
                    if (distinctCharsArray[i][j] > 0 && 
                        distinctCharsArray[i][j] == distinctCharsArray[j+1][k]) {
                        // Count this as a magical pair
                        ++count;
                    }
                }
            }
        }
        return count;
    }

    vector<vector<int>> distinctCharsArray;

public:
    int countMagicalPairs(string s) {
        populateDistinctChars(s);
        return getMagicalPairsCount(s);
    }
};

int main() {
    Solution sol;
    string s = "abcac";
    cout << sol.countMagicalPairs(s) << endl;
    return 0;
}