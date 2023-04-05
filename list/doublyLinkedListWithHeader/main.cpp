//
// Created by HP on 2023/4/5.
//

#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"

#include <iostream>


void testSize( const doublyLinkedList::DoublyLinkedList<int> &linkedList ) {
	std::cout << "size = " << linkedList.size() << std::endl;
}


void testIsEmpty( const doublyLinkedList::DoublyLinkedList<int> &linkedList ) {
	std::cout << "is empty? " << linkedList.isEmpty() << std::endl;
}


void testInsert( doublyLinkedList::DoublyLinkedList<int> &linkedList ) {
	std::cout << std::endl;
	std::cout << "插入前: " << std::endl;
	std::cout << linkedList << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << "is empty? " << linkedList.isEmpty() << std::endl;
	linkedList.insert( 0, 1 );
	linkedList.insert( 0, 2 );
	linkedList.insert( 0 , 3 );
	linkedList.insert( 1, 4 );
	linkedList.insert( 4, 5 );
	std::cout << "插入后: " << std::endl;
	std::cout << linkedList << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << "is empty? " << linkedList.isEmpty() << std::endl;
}


int main() {
	doublyLinkedList::DoublyLinkedList<int> linkedList;

	testSize( linkedList );
	testIsEmpty( linkedList );
	testInsert( linkedList );
}