// 1379. Find a Corresponding Node of a Binary Tree in a Clone of That Tree

#include <iostream>
#include <queue>

using namespace std;

class Solution 
{
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
        queue<TreeNode*> oq, cq;
        oq.push(original);
        cq.push(cloned);
        
        while (!oq.empty() && !cq.empty())
        {
            TreeNode* onode = oq.front();
            TreeNode* cnode = cq.front();
            oq.pop();
            cq.pop();
            if (&(*onode) == &(*target)) return cnode;
            if (onode->left)
            {
                oq.push(onode->left);
                cq.push(cnode->left);
            }
            if (onode->right)
            {
                oq.push(onode->right);
                cq.push(cnode->right);
            }      
        }
        
        return nullptr;
    }
};

int main()
{
    return 0;
}