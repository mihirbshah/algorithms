// 706. Design HashMap

#include <iostream>
#include <vector>
#include <utility>
#include <list>

using namespace std;

class MyHashMap 
{
public:
    /** Initialize your data structure here. */
    MyHashMap()
    {    
        hash.resize(bucketSize);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) 
    {
        int bucket = key % bucketSize;
        for (auto& p : hash[bucket])
        {
            if (p.first == key) 
            {
                p.second = value;
                return;
            }
        }
        
        hash[bucket].emplace_back(key, value);
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) 
    {
        int bucket = key % bucketSize;
        for (const auto& p : hash[bucket])
        {
            if (p.first == key) return p.second;
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) 
    {
        int bucket = key % bucketSize;
        auto& chain = hash[bucket];
        for (auto it = chain.begin(); it != chain.end(); ++it)
        {
            if (it->first == key) 
            {
                chain.erase(it);
                return;
            }
        }
    }
    
private:
    int bucketSize = 1000;
    vector<list<pair<int, int>>> hash;
};


int main()
{
    return 0;
}