// 1522. Diameter of N-Ary Tree

#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution 
{
public:
    int diameter(Node* root) 
    {
        int diam = 0;
        calcDiameter(root, diam);
        return diam;
    }
    
private:
    int calcDiameter(Node* node, int& maxd)
    {
        if (!node) return 0;
        const auto& children = node->children;
        vector<int> v(max(int(children.size()), 2), 0);
        for (int i = 0; i < children.size(); ++i)
        {
            v[i] = calcDiameter(children[i], maxd);
        }
        sort(v.begin(), v.end(), greater<int>());
        maxd = max(maxd, v[0] + v[1]);
        return v[0] + 1;
    }
};

int main()
{
    return 0;
}