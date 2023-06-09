//
// Created by HP on 2023/3/29.
//

#include "LinkedList.h"
#include "LinkedList.cpp"
#include <iostream>


void testInsert( LinkedList<int> &linkedList ) {
	std::cout << "插入元素前" << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << "isEmpty: " << linkedList.isEmpty() << std::endl;
	linkedList.insert( 0, 1 );
	linkedList.insert( 0, 2 );
	linkedList.insertBack( 3 );
	linkedList.insertBefore( 4 );
	linkedList.insert( 1, 5 );
	linkedList.insertBack( 6 );
	std::cout << "插入元素后" << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << "isEmpty: " << linkedList.isEmpty() << std::endl;
	std::cout << linkedList << std::endl;
	std::cout << std::endl;
}


void testIndexOf( const LinkedList<int> &linkedList ) {
	std::cout << linkedList << std::endl;
	std::cout << "6 第一次出现的位置为：" << linkedList.indexOf( 6 ) << std::endl;
	std::cout << std::endl;
}


void testGet( const LinkedList<int> &linkedList ) {
	std::cout << linkedList << std::endl;
	std::cout << "索引为 3 的节点的值为：" << linkedList.get( 3 ) << std::endl;
	std::cout << std::endl;
}


void testErase( LinkedList<int> &linkedList ) {
	std::cout << "被删除元素为：" << linkedList.erase( 0 ) << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << std::endl;
}


void testClear( LinkedList<int> &linkedList ) {
	std::cout << "清空链表之前" << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << "isEmpty: " << linkedList.isEmpty() << std::endl;
	linkedList.clear();
	std::cout << "清空链表之后" << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << "isEmpty: " << linkedList.isEmpty() << std::endl;
	linkedList.insert( 0, 1 );
	linkedList.insertBack( 2 );
	linkedList.insertBefore( 3 );
	linkedList.insert( 1, 4 );
	std::cout << "插入几个元素之后" << std::endl;
	std::cout << linkedList << std::endl;
	std::cout << std::endl;
}


void testSet( LinkedList<int> &linkedList ) {
	try {
		linkedList.set( 3, 5 );
	} catch ( char const *e ) {
		std::cout << e << std::endl;
	}
	std::cout << std::endl;
}


void testLastIndexOf( LinkedList<int> &linkedList ) {
	linkedList.insertBack( 4 );
	std::cout << linkedList << std::endl;
	std::cout << "4 最后出现的位置为：" << linkedList.lastIndexOf( 4 ) << std::endl;
	std::cout << "6 最后出现的位置为：" << linkedList.lastIndexOf( 6 ) << std::endl;
	std::cout << std::endl;
}


void testEqual() {
	LinkedList<int> linkedList1;
	LinkedList<int> linkedList2;
	linkedList1.insertBefore( 1 );
	linkedList1.insertBefore( 2 );
	linkedList1.insertBefore( 3 );
	linkedList2.insertBefore( 1 );
	linkedList2.insertBefore( 2 );
	linkedList2.insertBefore( 3 );

	std::cout << "两个链表是否相等：" << ( linkedList1 == linkedList2 ) << std::endl;
	std::cout << "两个链表是否不等：" << ( linkedList1 != linkedList2 ) << std::endl;
	std::cout << std::endl;
}


void testIndex( LinkedList<int> &linkedList, int theIndex ) {
	std::cout << linkedList << std::endl;
	std::cout << linkedList[ theIndex ] << std::endl;
	linkedList[ theIndex ] = 6;
	std::cout << linkedList << std::endl;
	std::cout << std::endl;
}


void testRemoveRange( LinkedList<int> &linkedList, int begin, int end ) {
	std::cout << "删除前链表为: " << linkedList << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	linkedList.removeRange( begin, end );
	std::cout << "删除后链表为: " << linkedList << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << std::endl;
}


void testSwap( LinkedList<int> &linkedList, int index1, int index2 ) {
	linkedList.insertBack( 5 );
	linkedList.insertBefore( 1 );
	linkedList.insertBefore( 2 );
	std::cout << "交换索引为" << index1 << "与索引为" << index2 << "元素的位置" << std::endl;
	std::cout << "交换前的链表为：" << linkedList << std::endl;
	linkedList.swap( index1, index2 );
	std::cout << "交换后的链表为：" << linkedList << std::endl;
}


void testReverse( LinkedList<int> &theLinkedList ) {
	std::cout << std::endl;
	std::cout << "链表逆序前：" << theLinkedList << std::endl;
	theLinkedList.reverse();
	std::cout << "链表逆序后：" << theLinkedList << std::endl;
}


int main() {
	LinkedList<int> linkedList;

	testInsert( linkedList );
	testIndexOf( linkedList );
	testGet( linkedList );
	testErase( linkedList );
	testClear( linkedList );
	testSet( linkedList );
	testLastIndexOf( linkedList );
	testEqual();
	testIndex( linkedList, 4 );
	testRemoveRange( linkedList, 1, 3 );
	testSwap( linkedList, 0, 4 );
	testReverse( linkedList );
}