#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

class Solution
{
public:
    void delMinPeak(vector<int> v)
    {
        list<int> l;
        for (auto i : v) l.push_back(i);
        const int n = v.size();
        if (!n) return;
        if (n == 1) return;
        
        using LIterator = list<int>::iterator;
        auto comp = [&](const LIterator& p1, const LIterator& p2) { return *p1 > *p2; };
        priority_queue<LIterator, vector<LIterator>, decltype(comp)> pq(comp);
        
        auto it = l.begin();
        for (int i = 0; i < n; ++i)
        {
            if ((i == 0 && v[i] > v[i + 1]) ||
                (i == n - 1 && v[i] > v[i - 1]) || 
                (i > 0 && i < n - 1 && v[i] > v[i - 1] && v[i] > v[i + 1])) 
            {
                pq.push(it);
            }
            ++it;
        }
        
        vector<int> res;
        while (!pq.empty())
        {
            auto peak = pq.top();
            pq.pop();
            cout << *peak << "\n";
            res.push_back(*peak);
            
            // before we delete peak, capture its position in the list 
            // and the iterators before/after peak. 
            bool first = peak == l.begin();
            bool last = peak == prev(l.end());
            auto previt = !first ? prev(peak) : l.end();
            auto nextit = !last ? next(peak) : l.end();
            
            l.erase(peak);
            
            // If list only contains 1 element, then simply push that element as it's the only peak
            if (l.size() == 1) pq.push(l.begin());
            // Check the element before the deleted element if it's not the first element in the list
            if (!first && checkPeak(l, previt)) pq.push(previt);            
            // Check the element after the deleted element if it's not the last element in the list
            if (!last && checkPeak(l, nextit)) pq.push(nextit);
        }
    }
    
private:
    bool checkPeak(const list<int>& l, list<int>::iterator it)
    {
        if (it == l.begin()) 
        {
            return *it > *next(it);
        }
        else if (it == prev(l.end()))
        {
            return *it > *prev(it);
        }
        else
        {
            return *it > *next(it) && *it > *prev(it);
        }
        return false;
    }
};

int main()
{
    Solution o;
    vector<int> v = {2,7,8,5,1,6,3,9,4};
    o.delMinPeak(v);
    return 0;
}