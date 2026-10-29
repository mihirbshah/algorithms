#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace {
    vector<int> nodeColors; 
    unordered_map<int, vector<int>> graph;
    vector<bool> visited;
};

class Solution {
    void initNodeColors(const string& colors) {
        nodeColors.resize(colors.length());
        for (int i = 0; i < colors.length(); ++i) {
            char c = colors[i];
            if (c == 'R')
                nodeColors[i] = 0;
            else if (c == 'B')
                nodeColors[i] = 1;
            else
                nodeColors[i] = 2;
        }

        // for (int i = 0; i < nodeColors.size(); ++i) {
        //     cout << "Node " << i << " has color " << nodeColors[i] << endl;
        // }
    }

    void initGraph(vector<vector<int>>& edges) {
        graph.clear();
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }

    void resetVisited(const string& colors) {
        visited.assign(colors.length(), false);
    }

    bool checkColor(vector<int>& src, vector<int>& dst, int color) {
        for (int i = 0; i < src.size(); ++i) {
            if (nodeColors[src[i]] != color) {
                return false;
            }

            visited[src[i]] = true;

            for (int j = 0; j < graph[src[i]].size(); ++j) {
                if (visited[graph[src[i]][j]]) continue;
                dst.push_back(graph[src[i]][j]);
            }
        }
        vector<int> nextDst;
        int nextColor = (color + 1) % 3;
        return dst.empty() ? true : checkColor(dst, nextDst, nextColor);
    }

    int probeRoot(string& colors) {
        for (int i = 0; i < nodeColors.size(); ++i) {
            // cout << "Checking node " << i << endl;
            resetVisited(colors);
            if (graph[i].size() > 2) {
                continue; // cannot be root if degree > 2 since root has no parent
            }

            vector<int> src = {i};
            vector<int> dst = {};
            int color = nodeColors[i];
            if (checkColor(src, dst, color)) {
                return i;
            }
        }

        return -1;
    }

public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        initNodeColors(colors);
        initGraph(edges);
        return probeRoot(colors);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{3, 1}, {3, 2}, {1, 4}, {2, 0}};
    string colors = "BRRWB";
    cout << sol.findColoredRoot(edges, colors) << endl;
    return 0;
}