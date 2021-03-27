// 1146. Snapshot Array

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SnapshotArray 
{
public:
    SnapshotArray(int length) 
    {
        arr.resize(length, 0);
    }
    
    void set(int index, int val) 
    {
        if (snapid)
        {
            int limit = indexToSnapid.count(index) ? indexToSnapid[index] : 0;
            for (int j = snapid - 1; j >= limit; --j)
            {
                if (!snapshots[j].count(index)) snapshots[j][index] = arr[index];
            }
        }
        
        indexToSnapid[index] = snapid;
        arr[index] = val;
    }
    
    int snap() 
    {
        snapshots.push_back(unordered_map<int, int>());
        return snapid++;
    }
    
    int get(int index, int snap_id) 
    {
        if (snapshots[snap_id].count(index)) return snapshots[snap_id][index];
        return arr[index];
    }
    
private:
    vector<int> arr;
    int snapid = 0;
    vector<unordered_map<int, int>> snapshots;
    unordered_map<int, int> indexToSnapid;
};


int main()
{
    return 0;
}