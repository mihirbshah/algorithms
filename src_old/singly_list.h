/*
 * SinglyList.h
 *
 *  Created on: Jan 23, 2018
 *      Author: mihir
 */

#pragma once

template <class T>
class SinglyList
{
private:
	struct SubNode;
	struct Node
	{
		typedef Node* HeadNodePtr;
		SubNode* _next;
		Node() : _next(nullptr) {}
	};

	struct SubNode : public Node
	{
		typedef SubNode* NodePtr;
		T _value;
	};

public:
	typedef typename SubNode::NodePtr NodePtr;
	typedef typename Node::HeadNodePtr HeadNodePtr;
	using UnaryPredicate = std::function<bool(NodePtr)>;

	SinglyList()
	{
		_head = new Node();
	}

	~SinglyList()
	{
		clear();
	}

	// element access
	const T& front() const { return _head->_next->_value; }
	HeadNodePtr head() const { return _head; }
	void print() const;

	// capacity
	bool empty() const { return _head->_next == nullptr; }

	// modifiers
	NodePtr insert_after(const T& elem_, NodePtr pos_);
	NodePtr insert_after(const T& elem_, HeadNodePtr pos_);
	NodePtr insert_front(const T& elem_);
	NodePtr insert_back(const T& elem_);
	void erase_if(UnaryPredicate pred);
	void clear();
	void reverse();
	void sort() { /*TODO Implement this method*/ }

private:
	NodePtr _reverse(NodePtr node_);

	HeadNodePtr _head;
};

template<class T>
void SinglyList<T>::print() const
{
	if (empty())
	{
		std::cout << "EMPTY\n";
		return;
	}
	NodePtr node = head()->_next;
	while (node)
	{
		std::cout << node->_value << ", ";
		node = node->_next;
	}
	std::cout << "\n";
}

template <class T>
typename SinglyList<T>::NodePtr SinglyList<T>::insert_after(const T& elem_, NodePtr pos_)
{
	NodePtr node = new SubNode();
	node->_value = elem_;
	node->_next = pos_->_next;
	pos_->_next = node;
	return node;
}

template <class T>
typename SinglyList<T>::NodePtr SinglyList<T>::insert_after(const T& elem_, HeadNodePtr pos_)
{
	NodePtr node = new SubNode();
	node->_value = elem_;
	node->_next = pos_->_next;
	pos_->_next = node;
	return node;
}

template <class T>
typename SinglyList<T>::NodePtr SinglyList<T>::insert_front(const T& elem_)
{
	return insert_after(elem_, head());
}

template <class T>
typename SinglyList<T>::NodePtr SinglyList<T>::insert_back(const T& elem_)
{
	if (empty())
	{
		return insert_front(elem_);
	}

	NodePtr curr = head()->_next;
	while (curr->_next) curr = curr->_next;
	return insert_after(elem_, curr);
}

template <class T>
void SinglyList<T>::erase_if(UnaryPredicate pred_)
{
	HeadNodePtr curr = head();
	while (curr)
	{
		if (pred_(curr->_next))
		{
			NodePtr toDelete = curr->_next;
			curr->_next = curr->_next->_next;
			delete toDelete;
		}
		curr = curr->_next;
	}
}

template<class T>
void SinglyList<T>::clear()
{
	NodePtr node = nullptr;
	while (node = head()->_next)
	{
		head()->_next = node->_next;
		delete node;
	}
}

template <class T>
void SinglyList<T>::reverse()
{
	if (empty()) return;
	NodePtr node = _reverse(head()->_next);
	node->_next = nullptr;
}

template <class T>
typename SinglyList<T>::NodePtr SinglyList<T>::_reverse(NodePtr node_)
{
	if (node_->_next)
	{
	  NodePtr newParent = _reverse(node_->_next);
	  newParent->_next = node_;
	}
	else
		head()->_next = node_;
	return node_;
}
