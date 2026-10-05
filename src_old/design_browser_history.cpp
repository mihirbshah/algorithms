// 1472. Design Browser History

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class BrowserHistory 
{
public:
    BrowserHistory(string homepage)
    {
        hist.push_back(homepage);
        ++curr;
    }
    
    void visit(string url) 
    {
        for (int i = hist.size() - 1; i > curr; --i) hist.pop_back();        
        hist.push_back(url);
        curr = hist.size() - 1;
    }
    
    string back(int steps) 
    {
        curr = max(curr - steps, 0);
        return hist[curr];
    }
    
    string forward(int steps) 
    {
        const int n = hist.size() - 1;
        curr = min(curr + steps, n);
        return hist[curr];
    }
    
private:
    vector<string> hist;
    int curr = -1;
};


int main()
{
    return 0;
}