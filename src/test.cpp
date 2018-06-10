/*
 * test.cpp
 *
 *  Created on: Jun 2, 2018
 *      Author: mihir
 */

#include <iostream>
#include "heap.h"

int main()
{
	heap h;
	h.make_heap({30, 20, 10, 45});
	h.print();
	std::cout << "\ntop: " << h.pop() << "\n";
	h.print();

	return 0;
}


