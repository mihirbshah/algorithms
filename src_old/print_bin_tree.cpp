// 655. Print Binary Tree

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
// PArtially working BFS
class Solution 
{
public:
    vector<vector<string>> printTree(TreeNode* root) 
    {
        vector<vector<string>> res;
        int h = height(root);
        int sz = pow(2, h) - 1;        
        queue<TreeNode*> q;
        q.push(root);
        int prevOffset = sz, nextOffset = sz / 2;
        int hcnt = 0;
        while (!q.empty())
        {
            if (++hcnt > h) break;
            queue<TreeNode*> tq;
            vector<string> u(sz, "");
            int pos = nextOffset;
            while (!q.empty())
            {
                auto e = q.front();
                q.pop();
                if (e) u[pos] = to_string(e->val);
                pos += prevOffset + 1;
                if (!e) continue;
                tq.push(e->left ? e->left : nullptr);
                tq.push(e->right ? e->right : nullptr);
            }
            prevOffset = nextOffset;
            nextOffset /= 2;
            res.push_back(u);
            q.swap(tq);
        }
        
        return res;
    }
    
private:
    int height(TreeNode* node)
    {
        if (!node) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};
*/

class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int c = pow(2, h) - 1;
        vector<vector<string>> ans(h, vector<string>(c));
        dfs(root, 0, c-1, 0, ans);
        return ans;
    }
private:
    int height(TreeNode* root) {
        if (root == NULL) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void dfs(TreeNode* root, int l, int r, int h, vector<vector<string>>& ans) {
        if (root == NULL) return;
        if (l > r) return;
        int mid = (l + r) / 2;
        ans[h][mid] = to_string(root->val);
        dfs(root->left, l, mid-1, h+1, ans);
        dfs(root->right, mid+1, r, h+1, ans);
    }
};


int main()
{
    return 0;
}