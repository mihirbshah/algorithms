/*
 * subset.h
 *
 *  Created on: Jan 15, 2018
 *      Author: mihir
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>
#include <math.h>

namespace subset
{
	template <class RandomIt>
	void print_container(RandomIt begin, RandomIt end)
	{
		typedef typename std::iterator_traits<RandomIt>::value_type i_type;
		std::cout << "\n";
		if (begin == end) std::cout << "NULL";
		else std::copy(begin, end, std::ostream_iterator<i_type>(std::cout, " "));
	}
};

using namespace subset;

// ==================================================
// Lexicographic order based subset generation
// ==================================================

class lex_subset
{
public:
	typedef std::vector<std::string> set_type;
	typedef std::vector<int> internal_set_type;
	typedef std::vector<lex_subset::set_type> subset_type;

	lex_subset(const set_type& l_);

	const subset_type& generate_subsets();
	void print_subset(const std::vector<set_type>& subsets_);
private:
	void forward();
	void backward();
	set_type apply_mask(const internal_set_type& mask_);

	set_type _l;
	internal_set_type _a;
	subset_type _subsets;
};

lex_subset::lex_subset(const set_type& l_) :
	_l(l_),
	_a(internal_set_type(l_.size() + 1, 0))
{
}

const lex_subset::subset_type& lex_subset::generate_subsets()
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

void lex_subset::forward()
{
	size_t n = _a.size() - 1;

	for (size_t i = 1; i <= n; ++i)
	{
		while (i <= n && _a[i] != 0) ++i;
		if (_a[i-1] != n)
		{
			_a[i] = _a[i-1] + 1;
			_subsets.push_back(apply_mask(_a));
			//print_container(std::next(_a.begin(), 1), _a.end());
		}
		else break;
	}
}

void lex_subset::backward()
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
			//print_container(std::next(_a.begin(), 1), _a.end());
		}
		else break;
	}
}

lex_subset::set_type lex_subset::apply_mask(const internal_set_type& mask_)
{
	set_type l;
	for (auto i : mask_)
		if (i) l.push_back(_l[i-1]);
	return l;
}

void lex_subset::print_subset(const std::vector<set_type>& subsets_)
{
	for (auto s : _subsets)
		print_container(s.begin(), s.end());
}

// ==================================================
// Gray Code based subset generation
// ==================================================

class gray_subset
{
public:
	typedef unsigned long long int_64;
	typedef std::vector<std::string> set_type;
	typedef std::vector<lex_subset::set_type> subset_type;
	typedef std::vector<int_64> int_64_vector;

	gray_subset(const set_type& l_);

	const subset_type& generate_subsets();
	void print_subset(const std::vector<set_type>& subsets_);

	//TODO Implement rank/unrank

private:
	void gen_gray_code(size_t n);
	void setup_lookup_table();
	bool bit_test(int_64 x, size_t pos);
	set_type apply_mask(int_64 code_, size_t n);

	int_64 _lookup[64];
	set_type _l;
	int_64_vector _gray_codes;
	subset_type _subsets;
};

gray_subset::gray_subset(const set_type& l_) : _l(l_)
{
	setup_lookup_table();
}

const gray_subset::subset_type& gray_subset::generate_subsets()
{
	size_t n = _l.size();
	gen_gray_code(n);
	for (auto code : _gray_codes)
	{
		_subsets.push_back(apply_mask(code, n));
	}

	return _subsets;
}

void gray_subset::print_subset(const std::vector<set_type>& subsets_)
{
	for (auto s : _subsets)
		print_container(s.begin(), s.end());
}

void gray_subset::gen_gray_code(size_t n)
{
    int_64 range = pow(2, n);
	int_64 msb_mask = _lookup[63]; // 0x8000000000000000
	int_64 neg_msb_mask = ~msb_mask; // 0x7fffffffffffffff

	for (int_64 i = 0ULL; i < range; ++i)
	{
		// Gray code can be obtained from binary code by following these steps:
		// MSB of Gray code is the same as MSB of binary code
		// For all other bits, gray_bit(i) = bin_bit(i) XOR bin_bit(i-1)

		// Save MSB for later
		int_64 msb = (i & msb_mask);
		// Calculate XOR of each bit with its parent. Parent bits are obtained using right-shift(1)
		int_64 self_xor = i ^ (i >> 1);
		// Turn off MSB from the result obtained in previous step
		int_64 rest = (self_xor & neg_msb_mask);
		// now OR the result from previous step with MSB to get gray code
		int_64 gray_code = msb | rest;
		_gray_codes.push_back(gray_code);
	}
}

void gray_subset::setup_lookup_table()
{
	for (int i = 0; i < 64; ++i)
		_lookup[i] = 1ULL << i;
}

bool gray_subset::bit_test(int_64 x, size_t pos)
{
	return x & _lookup[pos];
}

gray_subset::set_type gray_subset::apply_mask(int_64 code_, size_t n)
{
	set_type v;
	for (size_t i = 0; i < n; ++i)
		if (bit_test(code_, i)) v.push_back(_l[i]);
	return v;
}


// ==================================================
// Binary counting based subset generation
// ==================================================

class bin_subset
{
public:
	typedef unsigned long long int_64;
	typedef std::vector<std::string> set_type;
	typedef std::vector<lex_subset::set_type> subset_type;

	bin_subset(const set_type& l_);

	const subset_type& generate_subsets();
	void print_subset(const std::vector<set_type>& subsets_);
	size_t rank(const set_type& s_);
	set_type unrank(int_64 code_);

private:
	void setup_lookup_table();
	bool bit_test(int_64 x, size_t pos);
	int_64 bit_set(int_64 x, size_t pos);
	set_type apply_mask(int_64 code_, size_t n);

	int_64 _lookup[64];
	set_type _l;
	subset_type _subsets;
};

bin_subset::bin_subset(const set_type& l_) : _l(l_)
{
	setup_lookup_table();
}

const bin_subset::subset_type& bin_subset::generate_subsets()
{
	size_t n = _l.size();
    int_64 range = pow(2, n);

	for (int_64 i = 0ULL; i < range; ++i)
	{
		_subsets.push_back(apply_mask(i, n));
	}

	return _subsets;
}

void bin_subset::print_subset(const std::vector<set_type>& subsets_)
{
	for (auto s : _subsets)
		print_container(s.begin(), s.end());
}

void bin_subset::setup_lookup_table()
{
	for (int i = 0; i < 64; ++i)
		_lookup[i] = 1ULL << i;
}

bool bin_subset::bit_test(int_64 x, size_t pos)
{
	return x & _lookup[pos];
}

bin_subset::int_64 bin_subset::bit_set(int_64 x, size_t pos)
{
	return x | _lookup[pos];
}

bin_subset::set_type bin_subset::apply_mask(int_64 code_, size_t n)
{
	set_type v;
	for (size_t i = 0; i < n; ++i)
		if (bit_test(code_, i)) v.push_back(_l[i]);
	return v;
}

bin_subset::set_type bin_subset::unrank(int_64 code_)
{
	return apply_mask(code_, _l.size());
}

size_t bin_subset::rank(const set_type& s_)
{
	int_64 rnk = 0ULL;
	for (auto e : s_)
	{
		auto it = std::find(_l.begin(), _l.end(), e);
		if (_l.end() != it)
		{
			auto index = std::distance(_l.begin(), it);
			rnk = bit_set(rnk, index);
		}
	}
	return rnk;
}
