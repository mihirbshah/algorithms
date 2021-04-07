// 716. Max Stack

#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;


class MaxStack {
public:
    list<int> v;
    map<int, vector<list<int>::iterator>> mp;
    
    MaxStack() { 
    }
    
    void push(int x) {
        v.push_front(x);
        mp[x].push_back(v.begin());
    }
    
    int pop() {
        int x = *v.begin();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.pop_front();
        return x;
    }
    
    int top() {
        return *v.begin();
    }
    
    int peekMax() {
        return mp.rbegin()->first;
    }
    
    int popMax() {
        int x = mp.rbegin()->first;
        auto it = mp[x].back();
        mp[x].pop_back();
        if (mp[x].empty()) mp.erase(x);
        v.erase(it);
        return x;
    }
};

/*
struct CustomCompare
{
    bool operator()(const list<int>::iterator& it1, const list<int>::iterator& it2)
    {
        return *it1 < *it2 || (*it1 == *it2 && distance(it1, it2) > 0);
    }
};

class MaxStack 
{
public:
    MaxStack() 
    {           
    }
    
    void push(int x) 
    {
        //cout << "pushing " << x << "\n";
        stk.push_front(x);
        //for (auto e : stk) cout << e << "\n";
        //if (maxstk.empty() || x >= *maxstk.top()) maxstk.push(stk.begin());
        maxstk.push(stk.begin());
    }
    
    int pop() 
    {
        int ret = stk.front();
        if (maxstk.top() == stk.begin()) maxstk.pop();
        stk.pop_front();
        return ret;
    }
    
    int top() 
    {
        //cout << "top ... \n";
        //for (auto e : stk) cout << e << "\n";
        return stk.front();
    }
    
    int peekMax() 
    {
        return *maxstk.top();
    }
    
    int popMax() 
    {
        //cout << "popmax ... \n";
        //cout << "maxstk.size: " << maxstk.size() << "\n";
        //cout << "stk.size: " << stk.size() << "\n";
        auto it = maxstk.top();
        maxstk.pop();
        int ret = *it;
        //cout << "FIRST: " << (it == stk.begin() ? "true" : "false") << "\n";
        stk.erase(it);
        //cout << "stk.size: " << stk.size() << "\n";
        return ret;
    }
    
private:
    list<int> stk;
    priority_queue<list<int>::iterator, vector<list<int>::iterator>, CustomCompare> maxstk;
};
*/



int main()
{
    MaxStack* obj = new MaxStack();
    obj->push(5);
    obj->push(1);
    //obj->push(5);
    int ret;
    //ret = obj->top();
    //cout << "ret: " << ret << "\n";
    ret = obj->popMax();
    cout << "ret: " << ret << "\n";
    ret = obj->peekMax();
    cout << "ret: " << ret << "\n";
    /*ret = obj->top();
    cout << "ret: " << ret << "\n";
    ret = obj->peekMax();
    cout << "ret: " << ret << "\n";
    ret = obj->pop();
    cout << "ret: " << ret << "\n";
    ret = obj->top();
    cout << "ret: " << ret << "\n";*/
    return 0;
}