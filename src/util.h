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

template <class RandomIt>
void print_container(RandomIt begin, RandomIt end)
{
	typedef typename std::iterator_traits<RandomIt>::value_type i_type;
	if (begin == end) std::cout << "NULL";
	else std::copy(begin, end, std::ostream_iterator<i_type>(std::cout, " "));
}




#endif /* SRC_UTIL_H_ */
