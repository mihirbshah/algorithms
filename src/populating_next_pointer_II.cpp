// 117. Populating Next Right Pointers in Each Node II

#include <iostream>



class Solution 
{
public:
    Node* connect(Node* root) 
    {
        Node *now, *tail, *head;

        now = root;
        head = tail = nullptr;
        while(now)
        {
            if (now->left)
            {
                if (tail) 
                {
                    tail->next = now->left;
                    tail = tail->next;
                }
                else 
                {
                    head = now->left;
                    tail = now->left;
                }
            }
            
            if (now->right)
            {
                if (tail) 
                {
                    tail->next = now->right;
                    tail = tail->next;
                }
                else 
                {
                    head = now->right;
                    tail = now->right;
                }
            }
            
            now = now->next;
            
            if(!now)
            {
                now = head;
                head = nullptr;
                tail = nullptr;
            }
        }
        
        return root;
    }
};
