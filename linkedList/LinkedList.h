//
// Created by HP on 2023/3/29.
//

#ifndef BLACKSKIN_MYCODE_LINKEDLIST_H
#define BLACKSKIN_MYCODE_LINKEDLIST_H

#include "Node.h"
#include "Node.cpp"
#include <iostream>


template<class AnyType>
class LinkedList {
public:
	LinkedList();
	LinkedList( const LinkedList<AnyType> & );
	~LinkedList();

	void clear();
	bool isEmpty() const;
	int size() const;
	void insert( int theIndex, const AnyType &theElement );
	void insertBefore( const AnyType &theElement );
	void insertBack( const AnyType &theElement );
	AnyType get( int theIndex ) const;
	void set( int theIndex, const AnyType &theElement );
	AnyType indexOf( AnyType theElement ) const;
	AnyType lastIndexOf( AnyType theElement ) const;
	void output( std::ostream &out ) const;
	AnyType erase( int theIndex );
	void removeRange( int begin, int end );
	bool operator==( LinkedList<AnyType> &theLinkedList );
	bool operator!=( LinkedList<AnyType> &theLinkedList );
	AnyType &operator[]( int theIndex );


private:
	int listSize;
	Node<AnyType> *headNode;

	void checkIndex( int theIndex ) const;
};


#endif //BLACKSKIN_MYCODE_LINKEDLIST_H
