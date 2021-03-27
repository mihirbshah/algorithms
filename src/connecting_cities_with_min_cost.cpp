// 1135. Connecting Cities With Minimum Cost

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/*
// partially working solution
class Solution 
{
public:
    int minimumCost(int N, vector<vector<int>>& connections) 
    {
        auto comp = [&](const vector<int>& v1, const vector<int>& v2){ return v1[2] > v2[2]; };
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
        for (auto c : connections)
        {
            pq.push(c);
        }
        
        int cost = 0;
        //unordered_set<int> connected;
        vector<int> conn(N + 1, -1);
        int pos = 0;
        while (!pq.empty())
        {
            auto v = pq.top();
            auto s = v[0], t = v[1], c = v[2];
            pq.pop();
            
            if (conn[s] != -1 && conn[t] != -1 && conn[s] == conn[t]) continue;
            
            if (conn[s] == -1 && conn[t] == -1)
            {
                conn[s] = conn[t] = pos++;
            }
            else if (conn[s] == -1 && conn[t] != -1)
            {
                conn[s] = conn[t];
            }
            else if (conn[s] != -1 && conn[t] == -1)
            {
                conn[t] = conn[s];
            }
            else
            {
                conn[s] = conn[t] = min(conn[s], conn[t]);
            }
            //if (connected.count(s) && connected.count(t)) continue;
            cost += c;
            cout << "conn[" << s << "]: " << conn[s] << ", conn[" << t << "]: " << conn[t] << ", cost: " << cost << "\n";
            //connected.insert(s);
            //connected.insert(t);
            //if (connected.size() == N) return cost;
        }
        
        for (int i = 1; i <= N; ++i)
        {
            if (conn[i]) return -1;
        }
        
        return cost;
    }
};
*/

class UnionFind
{
public:
    UnionFind(int n)
    {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }
    
    void join(int a, int b)
    {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
        {
            parent[pa] = pb;
        }
    }
    
    int find(int a)
    {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    
    bool connected(int a, int b)
    {
        return find(a) == find(b);
    }
    
private:
    vector<int> parent;
};

class Solution 
{
public:
    int minimumCost(int N, vector<vector<int>>& connections) 
    {
        UnionFind dsu(N);
        auto comp = [&](const vector<int>& v1, const vector<int>& v2){ return v1[2] < v2[2]; };
        sort(connections.begin(), connections.end(), comp);
        int cost = 0;
        for (auto c : connections)
        {
            if (dsu.connected(c[0], c[1])) continue;
            dsu.join(c[0], c[1]);
            cost += c[2];
        }
        
        for (int i = 1; i < N; ++i)
        {
            if (dsu.find(i) != dsu.find(i + 1)) return -1;
        }
        
        return cost;
    }
};

int main()
{
    vector<vector<int>> connections({{2,1,87129},{3,1,14707},{4,2,34505},{5,1,71766},{6,5,2615},{7,2,37352}}); int N = 7;
    Solution o;
    int res = o.minimumCost(N, connections);
    cout << "res: " << res << "\n";
    return 0;
}