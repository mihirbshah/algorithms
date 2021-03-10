// 1233. Remove Sub-Folders from the Filesystem

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include "util.h"

using namespace std;

class Solution 
{
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(folder.begin(), folder.end());
        unordered_set<string> dirs;
        for (auto f : folder)
        {
            if (!parentPresent(f, dirs)) dirs.insert(f);
        }
        return vector<string>(dirs.begin(), dirs.end());
    }
    
private:
    bool parentPresent(const string& dir, const unordered_set<string>& dirs)
    {
        const int n = dir.size();
        for (int i = 1; i < n; ++i)
        {
            if (dir[i] != '/') continue;
            string parent = dir.substr(0, i);
            if (dirs.count(parent)) return true;
        }
        return false;
    }
};

int main()
{
    vector<string> dirs({"/ah/al/am","/ah/al"});
    Solution o;
    vector<string> res = o.removeSubfolders(dirs);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}