// 937. Reorder Data in Log Files

#include <iostream>
#include <vector>
#include <string>
#include <ctype.h>
#include <algorithm>  
#include <set>
#include "util.h"

using namespace std;

class Solution 
{
public:
    struct Log
    {
        string id, data, origLog;
        Log(string log) : origLog(log)
        {
            auto pos = log.find_first_of(" ");
            if (pos != string::npos)
            {
                id = log.substr(0, pos);
                data = log.substr(pos + 1, log.size() - pos);
            }
        }
        bool isDigitLog() { return isdigit(data[0]); }
    };
    
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        auto comp = [](const Log& l1, const Log& l2){
            if (l1.data != l2.data)
                return lexicographical_compare(l1.data.begin(), l1.data.end(), l2.data.begin(), l2.data.end());
            else
                return lexicographical_compare(l1.id.begin(), l1.id.end(), l2.id.begin(), l2.id.end());
            };
        
        vector<Log> dLog;
        set<Log, decltype(comp)> lLog(comp);
        
        for (const auto l : logs)
        {
            Log log(l);
            if (log.isDigitLog()) dLog.push_back(log);
            else lLog.insert(log);
        }
        
        vector<string> res;
        for (auto l : lLog) res.push_back(l.origLog);
        for (auto l : dLog) res.push_back(l.origLog);
        
        return res;
    }
};

int main()
{
    //vector<string> log({"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"});
    vector<string> log({"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"});
    Solution o;
    vector<string> res = o.reorderLogFiles(log);
    print_container(res.begin(), res.end());
    return 0;
}