// 1361. Validate Binary Tree Nodes

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution 
{
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (leftChild[i] != -1) ++indegree[leftChild[i]];
            if (rightChild[i] != -1) ++indegree[rightChild[i]];
        }
        
        int root = -1;
        for (int i = 0; i < n; ++i)
        {
            if (!indegree[i])
            {
                if (root != -1) return false;
                root = i;
            }
        }
        
        if (root == -1) return false;
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            if (visited[n]) return false;
            visited[n] = true;
            if (leftChild[n] != -1) q.push(leftChild[n]);
            if (rightChild[n] != -1) q.push(rightChild[n]);
        }
        
        for (auto e : visited)
        {
            if (!e) return false;
        }
        
        return true;
    }
};

int main()
{
    int n = 4; 
    vector<int> l({1,0,3,-1}), r({-1,-1,-1,-1});
    Solution o;
    bool res = o.validateBinaryTreeNodes(n, l, r);
    cout << "res: " << res << "\n";
    return 0;
}