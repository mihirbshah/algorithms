// 981. Time Based Key-Value Store

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

class TimeMap 
{
public:
    
    TimeMap() 
    {
    }
    
    void set(string key, string value, int timestamp) 
    {
        times[key].push_back(timestamp);
        values[key].push_back(value);
    }
    
    string get(string key, int timestamp) 
    {
        if (!times[key].size()) return "";
        auto it = lower_bound(times[key].begin(), times[key].end(), timestamp);
        if (it == times[key].end()) return *values[key].rbegin();
        if (*it != timestamp)
        {
            if (it == times[key].begin()) return "";
            --it;
        }
        return *(values[key].begin() + (distance(times[key].begin(), it)));
    }
    
private:
    unordered_map<string, vector<string>> values;
    unordered_map<string, vector<int>> times;
};


int main()
{
    TimeMap m;
    m.set("foo", "bar", 2);
    string res = m.get("foo", 1);
    cout << "res: " << res << "\n";
    res = m.get("foo", 3);
    cout << "res: " << res << "\n";
    m.set("foo", "bar2", 4);
    res = m.get("foo", 4);
    cout << "res: " << res << "\n";
    res = m.get("foo", 5);
    cout << "res: " << res << "\n";
    return 0;
}