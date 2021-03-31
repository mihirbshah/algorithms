// 767. Reorganize String

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
class Solution 
{
public:
    string reorganizeString(string str) 
    {
        unordered_map<char, int> cnt;
        for (auto c: str) ++cnt[c];
        vector<pair<char, int>> vcnt;
        for (auto& p : cnt) vcnt.push_back(p);
        sort(vcnt.begin(), vcnt.end(), [&](pair<char, int>& p1, pair<char, int>& p2){ return p1.second > p2.second; });
        
        const int n = vcnt.size();
        string res;
        
        if (n == 1) 
        {
            if (vcnt[0].second == 1) res += vcnt[0].first;
            return res;
        }
        
        int l = 0, s = 1;
        while (l < n && s < n)
        {
            cout << "l: " << l << ", cnt[l]: " << vcnt[l].second << ", s: " << s << ", cnt[s]: " << vcnt[s].second << "\n";
            
            int limit = vcnt[s].second;
            for (int k = 0; k < limit; ++k)
            {
                res += vcnt[l].first;
                res += vcnt[s].first;
                --vcnt[l].second;
                --vcnt[s].second;
            }
            
            if (s > l)
            {
                if (!vcnt[s].second) ++s;
                if (!vcnt[l].second) l = s + 1;
            }
            else if (l > s)
            {
                if (!vcnt[l].second) ++l;
                if (!vcnt[s].second) s = l + 1;                
            }
            
            
            if (l >= n)
            {
                if (s >= n) return res;
                if (vcnt[s].second > 1) return "";
                if (vcnt[s].second == 1) res += vcnt[s].first;
                return res;
            }
            
            if (s >= n)
            {
                if (l >= n) return res;
                if (vcnt[l].second > 1) return "";
                if (vcnt[l].second == 1) res += vcnt[l].first;
                return res;
            }

            if (vcnt[l].second < vcnt[s].second)
            {
                swap(l, s);
            }
            cout << "res: " << res << "\n";
        }
        
        return "";
    }
};
*/

class Solution 
{
public:
string reorganizeString(string S) {
	vector<int> cnt(26);
	int mostFreq = 0, i = 0;

	for(char c : S)
		if(++cnt[c - 'a'] > cnt[mostFreq])
			mostFreq = (c - 'a');

	if(2 * cnt[mostFreq] - 1 > S.size()) return "";

	while(cnt[mostFreq]) {
		S[i] = ('a' + mostFreq);
		i += 2;
		cnt[mostFreq]--;
	}

	for(int j = 0; j < 26; j++) {
		while(cnt[j]) {
			if(i >= S.size()) i = 1;
			S[i] = ('a' + j);
			cnt[j]--;
			i += 2;
		}
	}

	return S;
}
};


int main()
{
    string s = "bfrbs";
    Solution o;
    string res = o.reorganizeString(s);
    cout << "res: " << res << "\n";
    return 0;
}