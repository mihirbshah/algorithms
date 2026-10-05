#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#include "tree_util.h"
#include "util.h"

using namespace std;

/*
https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
*/

/*
Mihir's solution - this approach works but its not neat
namespace
{
    using TreeNode = TreeUtils::TreeNode;
    int null = numeric_limits<int>::lowest();
}

class Solution
{
public:
    TreeNode* recoverFromPreorder(string s)
    {
        if (s.empty()) return nullptr;
        
        // i = index of iteration through s
        // ci = index of current node in vector tree
        // cl = level of current node
        // ni = index of new node in vector tree
        // nl = level of new node
        // nv = new node's value
        // n = size of input tree string
        // maxLevel = max no. of levels in the tree - helps to find effective size of vector tree
        int i = 0, ci = 0, cl = 0, ni = -1, nl = -1, nv = -1;
        const int n = s.size();
        int maxLevel = 0;
        vector<int> tree(1000, null);
        while (s[i] != '-') ++i;
        tree[0] = stoi(s.substr(0, i));
        --i;
        cout << "input: " << s << "\n";
        while (i < n)
        {
            if (i == n-1) break;
            cout << "Calling getNextNodeAndLevel -- i: " << i << ", ci: " << ci << ", cl: " << cl << ", ni: " << ni << ", nl: " << nl << ", nv: " << nv << "\n";
            getNextNodeAndLevel(s, i, nl, nv);
            if (nl == cl + 1)
            {
                // left child of curr node
                ni = 2 * ci + 1;
            }
            else if (nl == cl)
            {
                // right sibling of curr node
                ni = 2 * (ci / 2) + 2;
            }
            else if (nl < cl)
            {
                // right child of grandparent of curr node at level nl - 1
                int pi = ci, pl = cl;
                while (pl > nl - 1)
                {
                    pi = (pi - 1) / 2;
                    --pl;
                }
                ni = 2 * pi + 2;
            }
            else
            {
                // nl > cl + 1
                cout << "Error  nl: " << nl << ", cl: " << cl << "\n";
                return nullptr;
            }
            tree[ni] = nv;
            ci = ni;
            cl = nl;
            maxLevel = max(maxLevel, nl);
        }
        
        const int treeVecSize = pow(2, 1 + maxLevel) - 1;
        cout << "treeVecSize: " << treeVecSize << "\n";
        cout << "tree: " << stringify_container(tree.begin(), tree.begin() + treeVecSize) << "\n";
        return nullptr;
    }
    
private:
    void getNextNodeAndLevel(const string& s, int& i, int& nl, int& nv) const
    {
        nl = 0;
        while (s[++i] == '-') ++nl;
        const int numStart = i++;
        while (s[i] >= '0' && s[i] <= '9') ++i;
        const int numEnd = --i;
        nv = stoi(s.substr(numStart, numEnd - numStart + 1));
    }
};
*/

class Solution 
{
public:
    TreeNode* recoverFromPreorder(string s_)
    {
        i = 0;
        s = s_;
        return preOrder(0);
    }

private:
    // depth = the current tree depth that we are processing
    // j = index of the first digit from current
    // i = index of the first hyphen from current
    TreeNode* preOrder(int depth)
    {
        int j = s.find_first_of("0123456789", i); 
        if(j - i != depth) return nullptr;
        
        i = s.find_first_of("-", j);
        int val = stoi(s.substr(j, i - j));
        
        TreeNode* root=new TreeNode(val);
        root->left = preOrder(depth + 1);
        root->right = preOrder(depth + 1);
        return root;
    } 
    
    std::string s;
    int i; 
};


int main()
{
    Solution o;
    //const string treestr = "1-2--3---4-5--6---7";
    //const string treestr = "1-2--3--4-5--6--7";
    const string treestr = "1-401--349---90--88";
    o.recoverFromPreorder(treestr);
    return 0;
}
