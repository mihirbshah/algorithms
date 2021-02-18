// 1650. Lowest Common Ancestor of a Binary Tree III

#include <iostream>

using namespace std;

class Solution 
{
public:
    Node* lowestCommonAncestor(Node* p, Node * q) 
    {
        int pdist = getRootDist(p), qdist = getRootDist(q);
        if (qdist > pdist)
        {
            for (int j = 0; j < qdist - pdist; ++j) q = q->parent;
            if (q->val == p->val) return q;
        }
        else if (pdist > qdist)
        {
            for (int j = 0; j < pdist - qdist; ++j) p = p->parent;
            if (q->val == p->val) return q;
        }
        while (q->val != p->val)
        {
            q = q->parent;
            p = p->parent;
        }
        
        return p;
    }
    
private:
    int getRootDist(Node* ptr)
    {
        int dist = 0;
        while (!ptr->parent) 
        {
            ptr = ptr->parent;
            ++dist;
        } 
        return dist;
    }
};

int main()
{
    return 0;
}