/*
 * heap.h
 *
 *  Created on: Jun 2, 2018
 *      Author: mihir
 */

#ifndef SRC_HEAP_H_
#define SRC_HEAP_H_

#include <vector>
#include <math.h>
#include <algorithm>
#include "util.h"

class heap
{
public:
	void push(int elem_);
	int pop();
	void make_heap(std::initializer_list<int> data_);
	void print() const;

private:
	int parent(size_t pos_) const;
	int lchild(size_t pos_) const;
	int rchild(size_t pos_) const;
	void bubble_up(size_t pos_);
	void bubble_down(size_t pos_);

	std::vector<int> _pQueue;
};

int heap::parent(size_t pos_) const
{
	if (0 == pos_) return -1;
	return 0 == pos_ % 2? (pos_ / 2) - 1 : floor(pos_ / 2);
}

int heap::lchild(size_t pos_) const
{
	size_t lpos = 2 * pos_ + 1;
	return lpos >= _pQueue.size() ? -1 : lpos;
}

int heap::rchild(size_t pos_) const
{
	size_t rpos = 2 * pos_ + 2;
	return rpos >= _pQueue.size() ? -1 : rpos;
}

void heap::print() const
{
	std::cout << "heap: ";
	print_container(_pQueue.begin(), _pQueue.end());
}

void heap::bubble_up(size_t pos_)
{
	if (0 == pos_) return;

	while (_pQueue[pos_] < _pQueue[parent(pos_)])
	{
		std::swap(_pQueue[pos_], _pQueue[parent(pos_)]);
		bubble_up(parent(pos_));
	}
}

void heap::bubble_down(size_t pos_)
{
	size_t lpos = lchild(pos_);
	size_t rpos = rchild(pos_);
	if (-1 ==  lpos && -1 == rpos) return;
	if (_pQueue[pos_] > _pQueue[lpos] || _pQueue[pos_] > _pQueue[rpos])
	{
		size_t swap_pos = _pQueue[lpos] <= _pQueue[rpos] ? lpos : rpos;
		std::swap(_pQueue[pos_], _pQueue[swap_pos]);
		bubble_down(swap_pos);
	}
}

void heap::push(int elem_)
{
	_pQueue.push_back(elem_);
	bubble_up(_pQueue.size() - 1);
}

void heap::make_heap(std::initializer_list<int> data_)
{
	for (auto e : data_) push(e);
}

int heap::pop()
{
	int top = _pQueue.front();
	_pQueue[0] = _pQueue.back();
	_pQueue.pop_back();
	bubble_down(0);
	return top;
}

#endif /* SRC_HEAP_H_ */
