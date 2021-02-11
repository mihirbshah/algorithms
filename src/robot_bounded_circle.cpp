// 1041. Robot Bounded In Circle

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Works for 108/110 test cases. 
// For better solutiuon refer to this https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC%2B%2BPython-Let-Chopper-Help-Explain
/*
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, i = 0;
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
        for (char & ins : instructions)
            if (ins == 'R')
                i = (i + 1) % 4;
            else if (ins == 'L')
                i = (i + 3) % 4;
            else
                x += d[i][0], y += d[i][1];
        return x == 0 && y == 0 || i > 0;
    }
*/

class Solution 
{
public:
    Solution() : xy(make_pair(0,0)), dir('N')
    {
    }
    
    bool isRobotBounded(string instructions) 
    {
        unordered_map<string, int> xyCnt;
        const int N = 1000 / instructions.size();
        for (int i = 0; i < N; ++i)
        {
            for (char c : instructions)
            {
                if (c == 'G') updateXY();
                else calcDir(c);
                const string k = to_string(xy.first) + to_string(xy.second);
                ++xyCnt[k];
                //cout << "Inst: " << c << ", k : " << k << ", cnt: " << xyCnt[k] << "\n";
                if (xyCnt[k] > 10) return true;
            }
        }
        return false;
    }
    
private:
    void calcDir(char inst)
    {
        if (dir == 'N')
        {
            if (inst == 'L') dir = 'W';
            else if (inst == 'R') dir = 'E';
        }
        else if (dir == 'S')
        {
            if (inst == 'L') dir = 'E';
            else if (inst == 'R') dir = 'W';
        }
        else if (dir == 'W')
        {
            if (inst == 'L') dir = 'S';
            else if (inst == 'R') dir = 'N';
        }
        else if (dir == 'E')
        {
            if (inst == 'L') dir = 'N';
            else if (inst == 'R') dir = 'S';
        }
    }
    
    void updateXY()
    {
        if (dir == 'N')
        {
            ++xy.second;
        }
        else if (dir == 'S')
        {
            --xy.second;
        }
        else if (dir == 'W')
        {
            --xy.first;
        }
        else if (dir == 'E')
        {
            ++xy.first;
        }
    }
    
    pair<int, int> xy;
    char dir;
};

int main()
{
    string s = "GL";
    Solution o;
    bool res = o.isRobotBounded(s);
    cout << "res: " << (res ? "true" : "false") << "\n";
    return 0;
}