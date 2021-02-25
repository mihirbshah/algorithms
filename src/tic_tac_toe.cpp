// 1275. Find Winner on a Tic Tac Toe Game

#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

class Solution 
{
public:
    string tictactoe(vector<vector<int>>& moves) 
    {
        vector<int> acnt(8, 0), bcnt(8, 0);
        const int n = moves.size();
        for (int i = 0; i < n; ++i)
        {
            //cout << "i: " << i << " | ";
            if (i % 2)
            {
                // b moves
                updateCnt(bcnt, moves[i]);
                if (won(bcnt)) return "B";
            }
            else
            {
                // a moves
                updateCnt(acnt, moves[i]);
                if (won(acnt)) return "A";
            }
        }
        
        if (n == 9) return "Draw";
        return "Pending";
    }
    
private:
    void updateCnt(vector<int>& cnt, vector<int> move)
    {
        ++cnt[move[0]];
        ++cnt[3 + move[1]];
        if (move[0] == move[1])
        {
            ++cnt[6]; 
            if (move[0] == 1) ++cnt[7];
        }
        if ((move[0] == move[1] + 2) || (move[1] == move[0] + 2)) ++cnt[7];
    }
    
    bool won(const vector<int>& cnt)
    {
        //cout << stringify_container(cnt.begin(), cnt.end()) << "\n";
        for (int i = 0; i < 8; ++i) 
        {
            if (cnt[i] == 3) return true;
        }
        return false;
    }
};

int main()
{
    //vector<vector<int>> moves({{0,0},{2,0},{1,1},{2,1},{2,2}});
    //vector<vector<int>> moves({{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}});
    vector<vector<int>> moves({{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}});
    
    Solution o;
    string res = o.tictactoe(moves);
    cout << "res: " << res << "\n";
    return 0;
}