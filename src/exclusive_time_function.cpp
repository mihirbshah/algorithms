// 636. Exclusive Time of Functions


#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <stdio.h>
#include <sstream>

#include "util.h"

using namespace std;

struct Func
{
    int id;
    int start;
    int halt;
    Func(int id_, int start_) : id(id_), start(start_), halt(-1) {}
};

enum Op{Start, End};

struct Log
{
    int id;
    Op op;
    int tm;
};

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<Func> fstack;
        vector<int> res(n, 0);
        int lastStop = -1;
        
        for (const auto& log : logs)
        {
            const Log& l = getLog(log);
            //cout << "Read log: " << l.id << ", " << (l.op == End ? "End" : "Start") << ", " << l.tm << "\n";
            if (l.op == Start)
            {
                if (fstack.size() && fstack.top().halt == -1) fstack.top().halt = l.tm - 1;
                fstack.push(Func(l.id, l.tm));
            }
            else
            {
                Func f = fstack.top();
                fstack.pop();
                if (f.halt == -1)
                {
                    res[f.id] += l.tm - f.start + 1;
                }
                else
                {
                    cout << "halt: " << f.halt << "\n";
                    res[f.id] += ((f.halt - f.start + 1) + (l.tm - lastStop));
                }
                
                lastStop = l.tm;
            }
            cout << "lastStop: " << lastStop << ", res: " << stringify_container(res.begin(), res.end()) << "\n";
        }
        
        return res;
    }
    
private:
    Log getLog(const string& log)
    {
        Log l;
        
        stringstream ss(log);
        string s;
        vector<string> v;
        while (getline(ss, s, ':'))
        {
            v.push_back(s);
        }
        
        //cout << "Parse log: " << stringify_container(v.begin(), v.end()) << "\n";
        l.id = atoi(v[0].c_str());
        l.op = v[1] == "start" ? Start : End;
        l.tm = atoi(v[2].c_str());
        return l;
    }
    
};

int main()
{
    //int n = 2; vector<string> logs({"0:start:0","1:start:2","1:end:5","0:end:6"});
    //int n = 1; vector<string> logs({"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"});
    //int n = 2; vector<string> logs({"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"});
    int n = 2; vector<string> logs({"0:start:0","0:start:2","0:end:5","1:start:7","1:end:7","0:end:8"});
    Solution o;
    vector<int> res = o.exclusiveTime(n, logs);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}