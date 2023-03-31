//
// Created by HP on 2023/3/29.
//

#include "LinkedList.h"
#include <iostream>


// 构造函数
template<class AnyType>
LinkedList<AnyType>::LinkedList() {
	listSize = 0;
	headNode = nullptr;
}


// 复制构造函数
template<class AnyType>
LinkedList<AnyType>::LinkedList( const LinkedList<AnyType> &theList ) {
	listSize = theList.listSize;

	// 链表 theList 为空
	if ( 0 == theList ) {
		headNode = nullptr;
		return;
	}

	// 链表 theList 非空
	Node<AnyType> *sourceNode = theList.headNode;
	headNode = new Node<AnyType>( sourceNode->element );
	sourceNode = sourceNode->next;
	Node<AnyType> *targetNode = headNode;

	while ( sourceNode != nullptr ) {
		targetNode->next = new Node<AnyType>( sourceNode->element );
		sourceNode = sourceNode->next;
		targetNode = targetNode->next;
	}

	targetNode->next = nullptr;
}


// 析构函数
template<class AnyType>
LinkedList<AnyType>::~LinkedList() {
	clear();
}


// 返回链表大小
template<class AnyType>
int LinkedList<AnyType>::size() const {
	return listSize;
}


// 返回链表是否为空
template<class AnyType>
bool LinkedList<AnyType>::isEmpty() const {
	return listSize == 0;
}


// 判断索引是否合法
template<class AnyType>
void LinkedList<AnyType>::checkIndex( int theIndex ) const {
	if ( theIndex < 0 || theIndex > listSize ) {
		throw "非法索引";
	}
}


// 在 theIndex 处插入值为 theElement 的节点
template<class AnyType>
void LinkedList<AnyType>::insert( int theIndex, const AnyType &theElement ) {
	checkIndex( theIndex );

	if ( theIndex == 0 ) {
		headNode = new Node<AnyType>( theElement, headNode );
	} else {
		Node<AnyType> *preNode = headNode;

		// 查找要插入节点的前一个节点
		for ( int i = 1; i < theIndex; ++i ) {
			preNode = preNode->next;
		}

		preNode->next = new Node<AnyType>( theElement, preNode->next );
	}
	listSize++;
}


// 在链表的头部插入节点
template<class AnyType>
void LinkedList<AnyType>::insertBefore( const AnyType &theElement ) {
	insert( 0, theElement );
}


// 在链表的尾部插入节点
template<class AnyType>
void LinkedList<AnyType>::insertBack( const AnyType &theElement ) {
	insert( listSize, theElement );
}


// 返回 theIndex 处节点的值
template<class AnyType>
AnyType LinkedList<AnyType>::get( int theIndex ) const {
	checkIndex( theIndex );

	Node<AnyType> *currentNode = headNode;

	for ( int i = 0; i < theIndex; ++i ) {
		currentNode = currentNode->next;
	}

	return currentNode->element;
}


// 返回第一次出现的值为 theElement 的节点的索引，若链表中不存在该节点则返回-1
template<class AnyType>
int LinkedList<AnyType>::indexOf( int theElement ) const {
	Node<AnyType> *currentNode = headNode;
	int index = 0;

	while ( currentNode->element != theElement && currentNode != nullptr ) {
		currentNode = currentNode->next;
		index++;
	}

	if ( currentNode != nullptr ) {
		return index;
	} else {
		return -1;
	}
}


template<class AnyType>
void LinkedList<AnyType>::output( std::ostream &out ) const {
	// 将链表放入输出流
	for ( Node<AnyType> *currentNode = headNode; currentNode != nullptr; currentNode = currentNode->next ) {
		out << currentNode->element << " ";
	}
}


template<class AnyType>
std::ostream &operator<<( std::ostream &out, const LinkedList<AnyType> &linkedList ) {
	linkedList.output( out );
	return out;
}


template<class AnyType>
void LinkedList<AnyType>::clear() {
	while ( headNode != nullptr ) {
		Node<AnyType> *currentNode = headNode->next;
		delete headNode;
		headNode = currentNode;
	}
	listSize = 0;
}


// 删除指定索引处节点，返回被删除节点中元素的值
template<class AnyType>
AnyType LinkedList<AnyType>::erase( int theIndex ) {
	checkIndex( theIndex );

	AnyType theElement = get( theIndex );
	Node<AnyType> *deleteNode;

	// 删除头节点
	if ( 0 == theIndex ) {
		deleteNode = headNode;
		headNode = headNode->next;
	} else {
		Node<AnyType> *preNode = headNode;

		for ( int i = 0; i < theIndex - 1; ++i ) {
			preNode = preNode->next;
		}
		deleteNode = preNode->next;
		preNode->next = preNode->next->next;
	}

	listSize--;
	delete deleteNode;

	return theElement;
}