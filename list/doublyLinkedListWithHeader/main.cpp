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
	linkedList.insert( 0, 3 );
	linkedList.insert( 1, 4 );
	linkedList.insert( 3, 5 );
	std::cout << "插入后: " << std::endl;
	std::cout << linkedList << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << "is empty? " << linkedList.isEmpty() << std::endl;
}


void testClear( doublyLinkedList::DoublyLinkedList<int> &linkedList ) {
	std::cout << std::endl;
	std::cout << "清空前：" << linkedList << std::endl;
	linkedList.clear();
	std::cout << "清空后：" << linkedList << std::endl;
}


void testInsertFront( doublyLinkedList::DoublyLinkedList<int> &linkedList ) {
	std::cout << std::endl;
	std::cout << "插入前：" << linkedList << std::endl;

	linkedList.insertFront( 0 );
	linkedList.insertFront( 1 );
	linkedList.insertFront( 2 );
	linkedList.insertFront( 3 );
	linkedList.insertFront( 4 );

	std::cout << "插入后：" << linkedList << std::endl;
}


void testInsertBack( doublyLinkedList::DoublyLinkedList<int> &linkedList ) {
	std::cout << std::endl;
	std::cout << "插入前：" << linkedList << std::endl;

	linkedList.insertBack( 5 );
	linkedList.insertBack( 6 );
	linkedList.insertBack( 7 );
	linkedList.insertBack( 8 );
	linkedList.insertBack( 9 );

	std::cout << "插入后：" << linkedList << std::endl;
}


void testRemove( doublyLinkedList::DoublyLinkedList<int>& linkedList, const int theIndex ) {
	std::cout << std::endl;
	std::cout << "删除前：" <<std::endl;
	std::cout << linkedList << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << "删除索引为 " << theIndex << "处元素后: " << std::endl;
	std::cout << "被删除的元素为：" << linkedList.remove( theIndex ) << std::endl;
	std::cout << linkedList << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
}


void testRemoveRange( doublyLinkedList::DoublyLinkedList<int>& linkedList, int frontIndex, int backIndex) {
	std::cout << std::endl;
	std::cout << "删除前:\n" << linkedList << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	linkedList.remove( frontIndex, backIndex );
	std::cout << "删除[" << frontIndex << "," << backIndex << "]" << "之间的元素后:\n" << linkedList << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
}


int main() {
	doublyLinkedList::DoublyLinkedList<int> linkedList;

	testSize( linkedList );
	testIsEmpty( linkedList );
	testInsert( linkedList );
	testClear( linkedList );
	testInsertFront( linkedList );
	testInsertBack( linkedList );
	testRemove( linkedList, 0 );
	testRemoveRange( linkedList, 3, 6 );
}