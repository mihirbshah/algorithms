// 282. Expression Add Operators

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

const char NullOp = '\0';

class Solution 
{
public:
    vector<string> addOperators(string num, int target) 
    {
        string currExprStr;
        unordered_set<string> res;
        applyOp(res, target, num, 0, NullOp, currExprStr, -1);
        return vector<string>(res.begin(), res.end());
    }
    
private:
    bool isOp(char c)
    {
        return c == '+' || c == '-' || c == '*';
    }
    
    long str2val(const string& s, long start, long end)
    {
        long val = 0; 
        long power = 0;
        for (long i = end; i >= start; --i)
        {
            val += (char2val(s[i]) * pow(10, power));
            ++power;
        }
        return val;
    }
    
    long char2val(char c)
    {
        return c - '0';
    }
    
    long redoOp(long val1, long val2, char op)
    {
        switch (op)
        {
            case '+':
                return val1 + val2;
            case '-':
                return val1 - val2;
            case '*':
                return val1 * val2;
        }
        return -1;        
    }
    
    long undoRedoOp(long currVal, char oldOp, char newOp, long oldVal, long newVal)
    {
        switch (oldOp)
        {
            case '+':
                return newOp == NullOp ? currVal - oldVal + newVal : (currVal - oldVal) + redoOp(oldVal, newVal, newOp);
            case '-':
                return newOp == NullOp ? currVal + oldVal - newVal : (currVal + oldVal) - redoOp(oldVal, newVal, newOp);
            case '*':
                return newOp == NullOp ? (oldVal ? (currVal / oldVal) : 0) * newVal : (oldVal ? (currVal / oldVal) : 0) * redoOp(oldVal, newVal, newOp);
        }
        return -1;
    }
    
    long getLastOp(const string& expr, long pos)
    {
        long j = pos;
        for (; j >= 0; --j)
        {
            if (isOp(expr[j])) 
            {
                break;
            }
        }
        return j;
    }
    
    void applyOp(unordered_set<string>& res,
                 long target,
                 const string& num, 
                 long i, 
                 char op, 
                 string currExprStr, 
                 long currExprVal)
    {
        //cout << "i: " << i << ", target: " << target << ", currExprStr: " << currExprStr << ", currExprVal: " << currExprVal << "\n";
        if (i >= num.size())
        {
            if (currExprVal == target) res.insert(currExprStr);
            return; 
        }
        
        switch(op)
        {
            case NullOp:
                {
                    //cout << "== NullOp ==\n";
                    currExprStr += num[i];
                    const long n = currExprStr.size();
                    long j = getLastOp(currExprStr, n - 2);
                    long oldVal = str2val(currExprStr, j + 1, n - 2);
                    long newVal = str2val(currExprStr, j + 1, n - 1);
                    //cout << "currExprStr: " << currExprStr << ", j : " << j << ", oldVal: " << oldVal << ", newVal: " << newVal << "\n";
                    if (i && !oldVal) return;
                    
                    if (j > 0)
                        currExprVal = undoRedoOp(currExprVal, currExprStr[j], NullOp, oldVal, newVal);
                    else
                        currExprVal = newVal;
                }
                break;
            case '*':
                {
                    //cout << "== Mult ==\n";
                    currExprStr += '*';
                    currExprStr += num[i];
                    const long n = currExprStr.size();
                    long j = getLastOp(currExprStr, n - 3);
                    long oldVal = str2val(currExprStr, j + 1, n - 3);
                    long newVal = char2val(num[i]);
                    //cout << "currExprStr: " << currExprStr << ", j : " << j << ", oldVal: " << oldVal << ", newVal: " << newVal << "\n";
                    if (j > 0)
                        currExprVal = undoRedoOp(currExprVal, currExprStr[j], '*', oldVal, newVal);
                    else
                        currExprVal = currExprVal * newVal;
                }
                break;
            case '+':
                {
                    //cout << "== Add ==\n";
                    currExprStr += '+';
                    currExprStr += num[i];
                    currExprVal += char2val(num[i]);
                }
                break;
            case '-':
                {
                    //cout << "== Sub ==\n";
                    currExprStr += '-';
                    currExprStr += num[i];
                    currExprVal -= char2val(num[i]);                    
                }
                break;
        }
        applyOp(res, target, num, i + 1, NullOp, currExprStr, currExprVal);
        applyOp(res, target, num, i + 1, '*', currExprStr, currExprVal);
        applyOp(res, target, num, i + 1, '+', currExprStr, currExprVal);
        applyOp(res, target, num, i + 1, '-', currExprStr, currExprVal);
    }
};

int main()
{
    //string num = "123"; long target = 6;
    //string num = "232"; long target = 8;
    //string num = "105"; long target = 5;
    //string num = "00"; long target = 0;
    string num = "3456237490"; long target = 9191;
    
    Solution o;
    vector<string> res = o.addOperators(num, target);
    cout << "res: \n";
    for (const auto& s : res)
        cout << "\t" << s << "\n";
    return 0;
}