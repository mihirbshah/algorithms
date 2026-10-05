// 380. Insert Delete GetRandom O(1)

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet 
{
public:
    /** Initialize your data structure here. */
    RandomizedSet() 
    {    
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) 
    {    
        if (elems.count(val)) return false;
        unique.push_back(val);
        elems[val] = unique.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) 
    { 
        if (!elems.count(val)) return false;
        unique[elems[val]] = unique.back(); 
        elems[unique.back()] = elems[val];
        unique.pop_back();
        elems.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() 
    {
        const int offset = rand() % unique.size();
        return unique[offset];
    }
    
private:
    vector<int> unique;
    unordered_map<int, int> elems;
};


int main()
{
    return 0;
}