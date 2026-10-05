// 146. LRU Cache

#include <iostream>
#include <unordered_map>
#include <queue>
#include <chrono>

using namespace std;

/*
class LRUCache 
{
public:
    LRUCache(int capacity) : n(capacity)
    {
    }
    
    int get(int key) 
    {
        int val = -1;
        if (cache.count(key)) 
        {
            val = cache[key];
            keyTime[key] = chrono::system_clock::now();
        }
        return val;
    }
    
    void put(int key, int value) 
    {
        auto comp = [&](int a, int b){ return keyTime[a] < keyTime[b]; };
        using PQueue1 = priority_queue<int, vector<int>, decltype(comp)>;
        static PQueue1 pq(comp);
        
        if (cache.size() < n || (cache.size() == n && cache.count(key)))
        {
            cache[key] = value;
            if (!cache.count(key)) pq.push(key);
            keyTime[key] = chrono::system_clock::now();
        }
        else
        {
            int eraseKey = pq.top();
            pq.pop();
            cache.erase(key);
            keyTime.erase(key);
            cache[key] = value;
            pq.push(key);
            keyTime[key] = chrono::system_clock::now();
        }
    }
    
private:
    unordered_map<int, chrono::system_clock::time_point> keyTime;
    //bool comp(int a, int b) { return keyTime[a] < keyTime[b]; }
    //using PQueue = priority_queue<int, vector<int>, bool(*)(int, int)>;
    //PQueue pq;
    unordered_map<int, int> cache;
    int n;
    
};
*/

// Solution copied from https://leetcode.com/problems/lru-cache/discuss/45976/C%2B%2B11-code-74ms-Hash-table-%2B-List
class LRUCache
{
private:
    int size;
    list<int> lru;                              // MRU ... LRU
    unordered_map<int, list<int>::iterator> mp; // key -> iterator
    unordered_map<int, int> kv;                 // key -> value

public:
    LRUCache(int capacity) : size(capacity) {}
    
    int get(int key) 
    {
        if (kv.count(key) == 0) return -1;
        updateLRU(key);
        return kv[key];
    }
    
    void put(int key, int value) 
    {
        if (kv.size() == size && kv.count(key) == 0) evict();
        updateLRU(key);
        kv[key] = value;
    }
    
    void updateLRU(int key) 
    {
        if (kv.count(key)) lru.erase(mp[key]);
        lru.push_front(key);
        mp[key] = lru.begin();
    }
    
    void evict() 
    {
        mp.erase(lru.back());
        kv.erase(lru.back());
        lru.pop_back();
    }    
};

int main()
{
    return 0;
}