#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int countRotations(string s, int k) {
        unordered_set<int> repetitionPositions; 
        for (int i = 0; i < s.length() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                repetitionPositions.insert(i);
            }
        }

        int baseScore = repetitionPositions.size();
        int deltaScoreFromSameEndPoints = s[0] == s[s.length() - 1] ? 1 : 0;

        // debug
        cout << "Repetition positions: ";
        for (const auto& pos : repetitionPositions) {
            cout << pos << " ";
        }
        cout << endl;
        cout << "Base score: " << baseScore << endl;
        cout << "Delta score from same end points: " << deltaScoreFromSameEndPoints << endl;

        vector<int> scores(s.length()-1, 0);
        scores[0] = baseScore;
        for (int i = 1; i < s.length(); ++i) {
            scores[i] = (repetitionPositions.count(i-1) ? baseScore - 1 : baseScore) + deltaScoreFromSameEndPoints; 
            // debug 
            cout << "Score at position " << i << ": " << scores[i] << endl;
        }

        int numKScores = 0;
        for (int i = 0; i < scores.size(); ++i) {
            // debug 
            cout << "Checking score at position " << i << ": " << scores[i] << endl;
            if (scores[i] == k) {
                ++numKScores;
            }
        }
        return numKScores;
    }
};

int main() {
    Solution sol;
    string s = "aab";
    int k = 1;
    cout << sol.countRotations(s, k) << endl;
    return 0;
}