// 1628. Design an Expression Tree With Evaluate Function

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

int add(int a, int b) {return a + b;}
int sub(int a, int b) {return a - b;}
int mul(int a, int b) {return a * b;}
int divi(int a, int b) {return a / b;}

class BinOp
{
public:
    BinOp()
    {
        opmap['+'] = &add;
        //opmap['-'] = &sub;
        opmap['*'] = &mul;
        opmap['/'] = &divi;
    }
    
    void registerOp(char op, int (*func)(int, int))
    {
        opmap[op] = func;
    }
    
    int eval(char op, int left, int right)
    {
        return (opmap[op])(left, right);
    }
    
private:
     unordered_map<char, int(*)(int, int)> opmap;
};

class Node 
{
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
    virtual BinOp& getBinOp() = 0;
    string s;
    Node* left = nullptr;
    Node* right = nullptr;
};

class ChildNode : public Node
{
public:
    int evaluate() const
    {
        return postfix(this);
    }
    
    virtual ~ChildNode() {}
    
    ChildNode()
    {
        bop = new BinOp();
    }
    
    BinOp& getBinOp() { return *bop; }
    
private:
    int postfix(const Node* ptr) const
    {
        if (!ptr->left && !ptr->right) return stoi(ptr->s);
        int left = postfix(ptr->left);
        int right = postfix(ptr->right);
        return eval(ptr->s, left, right);
    }
    
    int eval(string op, int left, int right) const
    {
        return bop->eval(op[0], left, right);
    }
    
    BinOp* bop;
};

class TreeBuilder 
{
public:
    Node* buildTree(vector<string>& postfix) 
    {
        stack<Node*> stk;
        for (const auto& s : postfix)
        {
            Node* ptr = new ChildNode();
            ptr->s = s;

            if (isNum(s))
            {
                stk.push(ptr);
            }
            else
            {
                ptr->right = stk.top();
                stk.pop();
                ptr->left = stk.top();
                stk.pop();
                stk.push(ptr);
            }
        }
        return stk.top();
    }
    
private:
    bool isNum(const string& s)
    {
        for (auto c : s)
            if (!isdigit(c)) return false;
        return true;
    }
};


int main()
{
    vector<string> e({"4","5","7","2","+","-","*"});
    TreeBuilder o;
    Node* node = o.buildTree(e);
    (node->getBinOp()).registerOp('-', &sub);
    int res = node->evaluate();
    cout << "res: " << res << "\n";
    return 0;
}