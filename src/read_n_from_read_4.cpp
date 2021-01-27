// 158. Read N Characters Given Read4 II - Call multiple times

#include <iostream>
#include <queue>

using namespace std;

int read4(char *buf4);

class Solution 
{
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char* buf, int n) 
    {
        const int qn = readFromQueue(buf, n);
        if (qn == n) return qn;
        int delta = n - qn;
        const int read4calls = ceil(delta / 4.0);
        int read4chars = 0;
        char buf4[4];
        for (int i = 0; i < read4calls; ++i)
        {
            read4chars = read4(buf4);
            if (!read4chars) break;
            if (read4chars <= delta)
            {
                for (int j = 0; j < read4chars; ++j) *buf++ = buf4[j];
                delta -= read4chars;
            }
            else
            {
                for (int j = 0; j < delta; ++j) *buf++ = buf4[j];
                for (int j = 0; j < read4chars - delta; ++j) leftover.push(buf4[delta + j]);
                delta = 0;
            }
        }
        return n - delta;
    }
    
private:
    int readFromQueue(char*& buf, int n)
    {
        const int qsize = leftover.size();
        int qn = qsize >= n ? n : qsize;
        
        char c;
        for (int i = 0; i < qn; ++i)
        {
            *buf++ = leftover.front();
            leftover.pop();
        }
        
        return qn;
    }
    
    queue<char> leftover;
};

int main()
{
    return 0;
}