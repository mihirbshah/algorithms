// 273. Integer to English Words

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    Solution()
    {
        numMap["0"] = "Zero";
        numMap["1"] = "One";
        numMap["2"] = "Two";
        numMap["3"] = "Three";
        numMap["4"] = "Four";
        numMap["5"] = "Five";
        numMap["6"] = "Six";
        numMap["7"] = "Seven";
        numMap["8"] = "Eight";
        numMap["9"] = "Nine";
        numMap["10"] = "Ten";
        numMap["11"] = "Eleven";
        numMap["12"] = "Twelve";
        numMap["13"] = "Thirteen";
        numMap["14"] = "Fourteen";
        numMap["15"] = "Fifteen";
        numMap["16"] = "Sixteen";
        numMap["17"] = "Seventeen";
        numMap["18"] = "Eighteen";
        numMap["19"] = "Nineteen";
        numMap["20"] = "Twenty";
        numMap["30"] = "Thirty";
        numMap["40"] = "Forty";
        numMap["50"] = "Fifty";
        numMap["60"] = "Sixty";
        numMap["70"] = "Seventy";
        numMap["80"] = "Eighty";
        numMap["90"] = "Ninety";
    }
    
    string numberToWords(int num) 
    {
        return trim(numToStr(to_string(num)));
    }
    
private:
    
    string ltrim(const string& s)
    {
        size_t start = s.find_first_not_of(WHITESPACE);
        return (start == string::npos) ? "" : s.substr(start);
    }

    string rtrim(const string& s)
    {
        size_t end = s.find_last_not_of(WHITESPACE);
        return (end == string::npos) ? "" : s.substr(0, end + 1);
    }

    string trim(const string& s)
    {
        return rtrim(ltrim(s));
    }
    
    string numToStr(const string& str)
    {
        string s = str;
        if (str.size() > 1)
        {
            size_t start = s.find_first_not_of("0");
            s = (start == string::npos) ? "" : str.substr(start);
        }
        const int n = s.size();
        switch(n)
        {
            case 1:
                return trim(numMap[s]);
            case 2:
                if (numMap.count(s)) return trim(numMap[s]);
                else return trim(numMap[s.substr(0, 1) + "0"] + " " + numToStr(s.substr(1, 1)));
            case 3:
                if (numMap.count(s)) return trim(numMap[s]);
                else return trim(numMap[s.substr(0, 1)] + " Hundred " + numToStr(s.substr(1, 2)));
            case 4:
                if (numMap.count(s)) return trim(numMap[s]);
                else return trim(numMap[s.substr(0, 1)] + " Thousand " + numToStr(s.substr(1, 3)));
            case 5:
                if (numMap.count(s)) return trim(numMap[s]);
                else return trim(numToStr(s.substr(0, 2)) + " Thousand " + numToStr(s.substr(2, 3)));
            case 6:
                if (numMap.count(s)) return trim(numMap[s]);
                else return trim(numToStr(s.substr(0, 3)) + " Thousand " + numToStr(s.substr(3, 3)));
            case 7:
                if (numMap.count(s)) return trim(numMap[s]);
                else return trim(numMap[s.substr(0, 1)] + " Million " + numToStr(s.substr(1, 6)));
            case 8:
                if (numMap.count(s)) return trim(numMap[s]);
                else return trim(numToStr(s.substr(0, 2)) + " Million " + numToStr(s.substr(2, 6)));
            case 9:
                if (numMap.count(s)) return trim(numMap[s]);
                else return trim(numToStr(s.substr(0, 3)) + " Million " + numToStr(s.substr(3, 6)));
            case 10:
                if (numMap.count(s)) return trim(numMap[s]);
                else return trim(numMap[s.substr(0, 1)] + " Billion " + numToStr(s.substr(1, 9)));
            default:
                break;
        }
        return "";
    }
    
    const string WHITESPACE = " \n\r\t\f\v";
    unordered_map<string, string> numMap;
};

int main()
{
    //int n = 123;
    //int n = 12345;
    //int n = 1234567;
    int n = 100000;
    Solution o;
    string res = o.numberToWords(n);
    cout << "input: " << n << ", res: " << res << "\n";
    return 0;
}