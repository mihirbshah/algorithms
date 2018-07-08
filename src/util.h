/*
 * util.h
 *
 *  Created on: Jun 2, 2018
 *      Author: mihir
 */

#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

template <class RandomIt>
void print_container(RandomIt begin, RandomIt end)
{
	typedef typename iterator_traits<RandomIt>::value_type i_type;
	if (begin == end) cout << "NULL";
	else copy(begin, end, ostream_iterator<i_type>(cout, " "));
}

template <class RandomIt>
string stringify_container(RandomIt begin, RandomIt end)
{
	// TODO replace this with something faster. stringstream is very slow
	stringstream s;
	typedef typename iterator_traits<RandomIt>::value_type i_type;
	if (begin == end) return "NULL";
	copy(begin, end, ostream_iterator<i_type>(s, " "));
	return s.str();
}



#endif /* SRC_UTIL_H_ */
