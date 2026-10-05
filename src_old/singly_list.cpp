/*
 * singly_list.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: mihir
 */

#include <iostream>
#include "singly_list.h"

namespace
{
	typedef SinglyList<int>::NodePtr NodePtr;
	typedef SinglyList<int>::HeadNodePtr HeadNodePtr;

	bool last_node(NodePtr node)
	{
		return node && node->_next == nullptr;
	}

	bool is_3(NodePtr node)
	{
		return node && node->_value == 3;
	}
};
/*
int main()
{
	typedef SinglyList<int>::NodePtr NodePtr;
	SinglyList<int> intList;
	NodePtr node1 = intList.insert_after(3, intList.head());
	node1 = intList.insert_after(33, node1);
	node1 = intList.insert_front(2);
	node1 = intList.insert_front(3);
	node1 = intList.insert_back(333);
	intList.print();

	intList.reverse();
	intList.print();

	intList.erase_if(last_node);
	intList.print();

	intList.erase_if(is_3);
	intList.print();

	auto first_node = [&intList](NodePtr node) -> bool { return node && intList.head()->_next == node; };
	intList.erase_if(first_node);
	intList.print();

	intList.erase_if(first_node);
	intList.print();
	intList.erase_if(is_3);
	intList.print();

	intList.clear();
	intList.print();

	return 0;
}
*/


