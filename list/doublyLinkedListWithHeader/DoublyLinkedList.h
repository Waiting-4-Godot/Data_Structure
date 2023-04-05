//
// Created by HP on 2023/4/4.
//

#ifndef BLACKSKIN_MYCODE_DOUBLYLINKEDLIST_H
#define BLACKSKIN_MYCODE_DOUBLYLINKEDLIST_H

#include <ostream>
#include "Node.h"
#include "Node.cpp"

namespace doublyLinkedList {

template<class AnyType>
class DoublyLinkedList {
public:
	// 构造函数、复制构造函数、析构函数
	DoublyLinkedList();
	DoublyLinkedList( DoublyLinkedList<AnyType> &theList );
	~DoublyLinkedList();

	// 其他成员函数
	void clear();
	int size() const;
	bool isEmpty() const;
	void insert( int theIndex, AnyType theElement );
	void output( std::ostream &out ) const;

private:
	void checkIndex( int theIndex ) const;

	doublyLinkedListNode::Node<AnyType> *headerNode;
	int listSize;
};


} // doublyLinkedList

#endif //BLACKSKIN_MYCODE_DOUBLYLINKEDLIST_H
