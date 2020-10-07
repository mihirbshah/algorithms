#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include "util.h"

/*
https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
Minor bug in code due to which all testcases dont pass
*/

using namespace std;

struct Event
{
    Event(int num_, int start_, int end_) : num(num_), start(start_), end(end_), visited(false) {}
    int num;
    int start, end;
    bool visited;
    int numDays() const { return end - start + 1; }
};

namespace
{
    using EventPtr = shared_ptr<Event>;
    using List2D = vector<vector<int>>;
    bool Compare(const EventPtr& e1, const EventPtr& e2) { return e1->start > e2->start && e1->end > e2->end; }
    using EventQueue = priority_queue<EventPtr, vector<EventPtr>, decltype(&Compare)>;
    using DayEventMap = unordered_map<int, EventQueue>;
}

class Solution
{
public:
    int maxEvents(List2D& events)
    {
        populateDayEvents(events);
        printDayEvents();
        int res = 0;
        for (int i = 0; i < dayEvents.size(); ++i)
        {
            int e = -1;
            EventQueue q = dayEvents[i];
            while (!q.empty())
            {
                if (q.top()->visited) q.pop();
                else 
                {
                    e = q.top()->num;
                    q.top()->visited = true;
                    break;
                }
            }
            res += (e != -1);
        }
        
        return res;
    }
    
private:
    void printDayEvents() const
    {
        for (const auto& de : dayEvents)
        {
            cout << de.first << " => ";
            EventQueue q = de.second;
            const int n = q.size();
            for (int i = 0; i < n; ++i) 
            {
                cout << q.top()->num << ", ";
                q.pop();
            }
            cout << "\n";
        }
    }
    void populateDayEvents(const List2D& events)
    {
        for (int i = 0; i < events.size(); ++i)
        {
            const int start = events[i][0], end = events[i][1];
            EventPtr eptr(new Event(i, start, end));
            
            for (int j = start; j <= end; ++j)
            {
                if (!dayEvents[j].empty()) 
                {
                    dayEvents[j].push(eptr);
                }
                else
                {
                    EventQueue q = EventQueue(Compare);
                    q.push(eptr);
                    dayEvents[j] = q;
                }
            }            
        }
    }
    
    DayEventMap dayEvents;
};

int main()
{
    Solution o;
    //List2D events = {{1,2},{2,3},{3,4},{1,2}};
    List2D events = {{1,2},{1,2},{3,3},{1,5},{1,5}};
    //List2D events = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
    //List2D events = {{1,3},{1,3},{1,3},{3,4}};
    int res = o.maxEvents(events);
    cout << "res: " << res << "\n";
    return 0;
}