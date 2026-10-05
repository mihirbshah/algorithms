// 1335. Minimum Difficulty of a Job Schedule

#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) 
    {
        const int n = jobDifficulty.size();
        if (n < d) return -1;
        vector<vector<int>> memo(n, vector<int>(d + 1, -1));
        return minDifficultyDay(jobDifficulty, d, 0, memo);
    }
    
private:
    int minDifficultyDay(const vector<int>& jobDifficulty, int d, int index, vector<vector<int>> memo)
    {
        const int n = jobDifficulty.size();
        if (index >= n && !d) return 0;
        if (!d || index >= n) return INT_MAX;
        if (memo[index][d] != -1) return memo[index][d];
        
        int currDifficulty = 0, minDifficulty = INT_MAX;
        for (int i = index; i < n; ++i)
        {
            currDifficulty = max(currDifficulty, jobDifficulty[i]);
            int nextDifficulty = minDifficultyDay(jobDifficulty, d - 1, i + 1, memo);
            if (nextDifficulty != INT_MAX)
            {
                minDifficulty = min(minDifficulty, currDifficulty + nextDifficulty);
            }
        }
            
        return memo[index][d] = minDifficulty;
    }
};

int main()
{
    //vector<int> jd({6,5,4,3,2,1}); int d = 2;
    //vector<int> jd({9,9,9}); int d = 4;
    //vector<int> jd({1,1,1}); int d = 3;
    //vector<int> jd({7,1,7,1,7,1}); int d = 3;
    vector<int> jd({11,111,22,222,33,333,44,444}); int d = 6;
    Solution o;
    int res = o.minDifficulty(jd, d);
    cout << "res: " << res << "\n";
    return 0;
}