/*
 * subset.cpp
 *
 *  Created on: Jan 15, 2018
 *      Author: mihir
 */

#include "subset.h"

using namespace subset;

int main()
{
	std::vector<std::string> v1({"life", "universe", "everything"});
	std::vector<std::string> v2({"1", "2", "3"});
	std::cout << "\n\nSubset generation in Lexicographic order: ";
	lex_subset ls(v2);
	ls.print_subset(ls.generate_subsets());

	std::cout << "\n\nSubset generation in Gray Code order: ";
	gray_subset gs(v2);
	gs.print_subset(gs.generate_subsets());

	std::cout << "\n\nSubset generation in Binary Counting order: ";
	bin_subset bs(v2);
	bs.print_subset(bs.generate_subsets());
	std::cout << "\n rank of (1,3): " << bs.rank({"1", "3"}) << "\n";
	std::vector<std::string> v_unrank = bs.unrank(5);
	std::cout << "\n unrank of 5: ";
	print_container(v_unrank.begin(), v_unrank.end());

	return 0;
}
