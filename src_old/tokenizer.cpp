#include <iostream>
#include <string>
#include <vector>
#include "util.h"

using namespace std;

namespace
{
    using SList = vector<string>;
}

bool legitimateComma(const string& s, int pos)
{
    return s[pos] == ',' && (!pos || s[pos-1] != '\\');
}

bool endOfString(const string& s, int pos)
{
    return s[pos] == '\0';
}

SList tokenizeLine(const string& s)
{
    SList slist;
    const int len = s.size();
    int prev = 0;
    for (int i = 0; i <= len; ++i)
    {
        if (legitimateComma(s, i) || endOfString(s, i))
        {
            if (prev > i - 1)
            {
                slist.push_back("");
            }
            else
            {
                slist.push_back(s.substr(prev, i - prev));
            }
            prev = i + 1;
        }
    }
    return slist;
}

int main()
{
    string s1 = ",abc,def,efg";
    string s2 = "ab\\,c,def,efg";
    string s3 = "ab\\,";
    string s4 = "";
    string s5 = ",,,\\\\,,a";
    SList res = tokenizeLine(s5);
    cout << "res: " << stringify_container(res.begin(), res.end()) << "\n";
    return 0;
}
