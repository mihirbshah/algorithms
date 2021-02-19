// 1429. First Unique Number


#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

/*
class FirstUnique {
public:
    queue<int> qu;                     // To keep the order of elements maintained
    unordered_map<int, int> freq;      // To keep the frequency of each element
    FirstUnique(vector<int>& nums) {
        freq.clear();
        while(!qu.empty()) qu.pop();
        for (auto num: nums) qu.push(num), freq[num]++;
    }
    
    int showFirstUnique() {
        while(!qu.empty() && freq[qu.front()] > 1){
            qu.pop();
        }
        if(qu.empty()) return -1;
        else return qu.front();
    }
    
    void add(int value) {
        qu.push(value);
        freq[value]++;
    }
};
*/

class FirstUnique 
{
public:
    FirstUnique(vector<int>& nums) 
    {
        for (auto n : nums) add(n);
    }
    
    int showFirstUnique() 
    {
        return unique.empty() ? -1 : unique.front();
    }
    
    void add(int value)
    {
        if (!cnt.count(value))
        {
            unique.push_back(value);
            cnt[value] = 1;
            auto it = unique.end();
            iterMap[value] = --it;
        }
        else
        {
            if (iterMap[value] != unique.end()) unique.erase(iterMap[value]);
            iterMap[value] = unique.end();
            ++cnt[value];
        }
    }
    
private:
    unordered_map<int, list<int>::iterator> iterMap;
    unordered_map<int, int> cnt;
    list<int> unique;
};


int main()
{
    vector<int> v({7,7,7,7,7,7});
    FirstUnique* obj = new FirstUnique(v);
    int res = obj->showFirstUnique();
    cout << "res: " << res << "\n";
    return 0;
}