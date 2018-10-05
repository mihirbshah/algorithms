/*
 * palindromic_substrings.cpp
 *
 *  Created on: Jul 24, 2018
 *      Author: mihir
 */


#include <vector>
#include <string>
#include "util.h"

using namespace std;

// ==================================================
// Lexicographic order based subset generation
// ==================================================

class lex_subsets
{
public:
	typedef string set_type;
	typedef vector<int> internal_set_type;
	typedef vector<lex_subsets::set_type> subset_type;

	lex_subsets(const set_type& l_);

	const subset_type& generate_subsets();
	void print_subset(const vector<set_type>& subsets_);
private:
	void forward();
	void backward();
	set_type apply_mask(const internal_set_type& mask_);

	set_type _l;
	internal_set_type _a;
	subset_type _subsets;
};

lex_subsets::lex_subsets(const set_type& l_) :
	_l(l_),
	_a(internal_set_type(l_.size() + 1, 0))
{
}

const lex_subsets::subset_type& lex_subsets::generate_subsets()
{
	size_t n = _a.size() - 1;
	_subsets.push_back(apply_mask(_a));
	//print_container(_a.begin() + 1, _a.end());
	while(_a[1] != n)
	{
		forward();
		backward();
	}
	return _subsets;
}

void lex_subsets::forward()
{
	size_t n = _a.size() - 1;

	for (size_t i = 1; i <= n; ++i)
	{
		while (i <= n && _a[i] != 0) ++i;
		if (_a[i-1] != n)
		{
			_a[i] = _a[i-1] + 1;
			_subsets.push_back(apply_mask(_a));
			//print_container(next(_a.begin(), 1), _a.end());
		}
		else break;
	}
}

void lex_subsets::backward()
{
	size_t n = _a.size() - 1;

	for (size_t i = n; i >= 1; --i)
	{
		while (i >= 1 && _a[i] == 0) --i;
		if (_a[i-1] != n && i-1 >= 1)
		{
			_a[i] = 0;
			++_a[i-1];
			_subsets.push_back(apply_mask(_a));
			//print_container(next(_a.begin(), 1), _a.end());
		}
		else break;
	}
}

lex_subsets::set_type lex_subsets::apply_mask(const internal_set_type& mask_)
{
	set_type l;
	for (auto i : mask_)
		if (i) l += (_l[i-1]);
	return l;
}

void lex_subsets::print_subset(const vector<set_type>& subsets_)
{
	cout << "total subsets: " << _subsets.size() << "\n";
	for (auto s : _subsets)
		cout << s << "\n";
}

vector<string> subsets;
void suffix(string::iterator sbegin, string::iterator send)
{
	if (sbegin + 1 == send)
	{
		subsets.push_back(string(1, *sbegin));
		//cout << "Called with " << *sbegin << "\n";
		//cout << string(1, *sbegin) << "\n";
		//cout << "subsets: " << stringify_container(subsets.begin(), subsets.end()) << "\n";
		//cout << "--\n";
		return;
	}

	suffix(sbegin + 1, send);
	//cout << "Called with " << *sbegin << "\n";
	/*cout << "subsets: " << stringify_container(subsets.begin(), subsets.end()) << "\n";
	cout << "subsets.size: " << subsets.size() << ", last elem: " << *subsets.rend() << "\n";
	for (auto it = subsets.begin(); it != subsets.end(); ++it)
	{
		cout << "elem: " << *it << "\n";
	}*/
	vector<string> sets;
	for (auto suf : subsets)
	{
		//cout << "suf: " << suf << "\n";
		sets.push_back((*sbegin) + suf);
		//cout << (*sbegin) + suf << "\n";
	}
	sets.push_back(string(1, *sbegin));
	//cout << string(1, *sbegin) << "\n";
	subsets.insert(subsets.end(), sets.begin(), sets.end());
	//cout << "subsets: " << stringify_container(subsets.begin(), subsets.end()) << "\n";
	//cout << "--\n";
}

void subset(string s)
{
	string::iterator sbegin = s.begin();
	string::iterator send = s.end();
	suffix(sbegin, send);
	for (auto s : subsets)
	{
		cout << s << "\n";
	}
}

/*
int main()
{
	//lex_subsets::set_type v = "abba";
	//lex_subsets l(v);
	//lex_subsets::subset_type subsets = l.generate_subsets();
	//l.print_subset(subsets);

	subset("aaa");
}*/
