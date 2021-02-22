// 1360. Number of Days Between Two Dates

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution 
{
public:
    int daysBetweenDates(string date1, string date2) 
    {
        return abs(daysFromEpoch(date1) - daysFromEpoch(date2));
    }
    
private:
    vector<int> parseDate(const string s)
    {
        vector<int> res;
        res.push_back(stoi(s.substr(0, 4)));
        res.push_back(stoi(s.substr(5, 2)));
        res.push_back(stoi(s.substr(8, 2)));
        return res;
    }
    
    int daysFromEpoch(string s)
    {
        vector<int> ymd = parseDate(s);
        
        int d = 0;
        for (int i = ymd[0] - 1; i >= 1970; --i)
        {
            if (isLeap(i)) d += 366;
            else d += 365;
        }
        
        bool isleap = isLeap(ymd[0]);
        for (int i = ymd[1] - 1; i >= 1; --i)
        {
            d += days[i];
            if (isleap && i == 2) d += 1;
        }
        
        d += ymd[2];
        
        return d;
    }
    
    bool isLeap(int y)
    {
        return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
    }
    
    vector<int> days = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

int main()
{
    return 0;
}