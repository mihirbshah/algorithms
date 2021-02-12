// 588. Design In-Memory File System

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "util.h"

using namespace std;

// Partially working solution with some bugs. For more complete solution using Trie, refer this -
// https://leetcode.com/problems/design-in-memory-file-system/discuss/103329/C%2B%2B-Trie-Solution
struct Node
{
    string name;
    bool isdir = true;
    string contents;
};

class FileSystem 
{
public:
    FileSystem() 
    {
        fs["/"] = {};
    }
    
    vector<string> ls(string path) 
    {
        vector<string> names = tokenize(path);
        const int n = names.size();
        if (!fs.count(names[n - 1])) return {};
        vector<string> res;
        int i = 0;
        for (auto ptr : fs[names[n - 1]])
        {
            if (names[n - 1] == ptr->name && !i) 
            {
                ++i;
                continue;
            }
            res.push_back(ptr->name);
        }
        sort(res.begin(), res.end());
        return res;
    }
    
    void mkdir(string path) 
    {
        vector<string> names = tokenize(path);
        for (int i = 0; i < names.size(); ++i)
        {
            if (fs.count(names[i])) continue;
            Node* ptr = new Node();
            ptr->name = names[i];
            fs[names[i]] = {ptr};
            fs[names[i - 1]].push_back(ptr);
        }        
    }
    
    void addContentToFile(string path, string content) 
    {
        vector<string> names = tokenize(path);
        const int n = names.size();
        if (fs.count(names[n - 1]))
        {
            Node* ptr = *(fs[names[n - 1]].begin());
            ptr->contents += content;
        }
        else
        {
            Node* ptr = new Node();
            ptr->name = names[n - 1];
            ptr->contents = content;
            ptr->isdir = false;
            fs[names[n - 1]] = {ptr};
            fs[names[n - 2]].push_back(ptr);
        }
    }
    
    string readContentFromFile(string path) 
    {   
        vector<string> names = tokenize(path);
        const int n = names.size();
        if (fs.count(names[n - 1]))
        {
            Node* ptr = *(fs[names[n - 1]].begin());
            return ptr->contents;
        }
        return "";
    }
    
private:
    vector<string> tokenize(const string& path)
    {
        if (path == "/") return {"/"};
        int prev = 1, i = 1;
        vector<string> res;
        res.push_back("/");
        for (; i < path.size(); ++i)
        {
            if (path[i] != '/') continue;
            res.push_back(path.substr(prev, i - prev));  
            prev = i + 1;
        }
        res.push_back(path.substr(prev, i - prev));
        
        return res;
    }
    
    unordered_map<string, vector<Node*>> fs;
};


int main()
{
    FileSystem* obj = new FileSystem();
    vector<string> res;
    res = obj->ls("/");
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    obj->mkdir("/a/b/c");
    obj->addContentToFile("/a/b/c/d", "hello");
    res = obj->ls("/");
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    res = obj->ls("/");
    cout << "content: " << obj->readContentFromFile("/a/b/c/d") << "\n";
    return 0;
}