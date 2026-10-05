// 1244. Design A Leaderboard

#include <iostream>
#include <unordered_map>
#include <set>
#include <utility>

using namespace std;

class Leaderboard 
{
public:
    Leaderboard() 
    {
    }
    
    void addScore(int playerId, int score) 
    {
        topk.erase({scores[playerId], playerId});
        scores[playerId] += score;
        topk.insert({scores[playerId], playerId});
    }
    
    int top(int K) 
    {
        int sum = 0;
        auto it = topk.rbegin();
        auto m = min(K, int(topk.size()));
        while (m)
        {
            sum += it->first;
            ++it;
            --m;
        }
        return sum;
    }
    
    void reset(int playerId) 
    {
        topk.erase({scores[playerId], playerId});
        scores[playerId] = 0;
        topk.insert({scores[playerId], playerId});
    }
    
private:    
    unordered_map<int, int> scores;
    set<pair<int, int>> topk;
};


int main()
{
    return 0;
}