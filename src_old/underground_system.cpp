// 1396. Design Underground System

#include <iostream>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;

class UndergroundSystem 
{
public:
    UndergroundSystem() 
    {
    }
    
    void checkIn(int id, string stationName, int t) 
    {
        in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) 
    {
        string sourceStation;
        double startTime = 0;
        if (in.count(id))
        {
            sourceStation = in[id].first;
            startTime = in[id].second;
            in.erase(id);
        }
        else
        {
            return;
        }
        
        double sum = t - startTime, cnt = 1;
        if (!times.count(sourceStation))
        {
            unordered_map<string, pair<double, double>> m;
            m[stationName] = {sum, cnt};
            times[sourceStation] = m;
        }
        else
        {
            auto& stationEntry = times[sourceStation];
            if (!stationEntry.count(stationName))
            {
                stationEntry[stationName] = {sum, cnt};
            }
            else
            {
                stationEntry[stationName].first += sum;
                stationEntry[stationName].second += cnt;
            }
        }
    }
    
    double getAverageTime(string startStation, string endStation) 
    {
        double res = 0;
        if (times.count(startStation))
        {
            if (times[startStation].count(endStation))
            {
                res = times[startStation][endStation].first / times[startStation][endStation].second;
            }
        }
        
        return res;
    }
    
private:
    unordered_map<int, pair<string, int>> in;
    unordered_map<string, unordered_map<string, pair<double, double>>> times;
};


int main()
{
    return 0;
}