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
	if ( theIndex < 0 || ( theIndex >= listSize && theIndex != 0 )) {
		throw "非法索引";
	}
}


// 在 theIndex 处插入值为 theElement 的节点
template<class AnyType>
void LinkedList<AnyType>::insert( int theIndex, const AnyType &theElement ) {
	//checkIndex( theIndex );

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
AnyType LinkedList<AnyType>::indexOf( AnyType theElement ) const {
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


// 返回指定元素最后一次出现的位置，若不存在返回-1
template<class AnyType>
AnyType LinkedList<AnyType>::lastIndexOf( AnyType theElement ) const {
	Node<AnyType> *currentNode = headNode;
	int index = -1;    // 最终返回的索引
	int temp = 0;        // 记录当前比较的节点的索引

	while ( currentNode != nullptr ) {
		if ( theElement == currentNode->element ) {
			index = temp;
		}
		currentNode = currentNode->next;
		temp++;
	}

	return index;
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


// 重载 == 运算符。两个链表相等，当且仅当两个链表长度相等且每个对应节点中元素相等
template<class AnyType>
bool LinkedList<AnyType>::operator==( LinkedList<AnyType> &theLinkedList ) {
	if ( this->size() != theLinkedList.size()) {
		return false;
	}

	Node<AnyType> *targetNode = theLinkedList.headNode;
	Node<AnyType> *currentNode = this->headNode;

	while ( currentNode != nullptr ) {
		if ( currentNode->element != targetNode->element ) {
			return false;
		}
		currentNode = currentNode->next;
		targetNode = targetNode->next;
	}

	return true;
}


template<class AnyType>
AnyType &LinkedList<AnyType>::operator[]( int theIndex ) {
	checkIndex( theIndex );

	Node<AnyType> *currentNode = headNode;
	for ( int i = 0; i < theIndex; ++i ) {
		currentNode = currentNode->next;
	}

	return currentNode->element;
}


template<class AnyType>
bool LinkedList<AnyType>::operator!=( LinkedList<AnyType> &theLinkedList ) {
	if ( this->size() != theLinkedList.size()) {
		return true;
	}

	bool isEqual = false;
	Node<AnyType> *sourceNode = this->headNode;
	Node<AnyType> *targetNode = theLinkedList.headNode;

	while ( sourceNode != nullptr ) {
		if ( sourceNode->element != targetNode->element ) {
			isEqual = true;
		}
		sourceNode = sourceNode->next;
		targetNode = targetNode->next;
	}

	return isEqual;
}


// 清空链表
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


// 将指定索引处节点的值修改为 theElement
template<class AnyType>
void LinkedList<AnyType>::set( int theIndex, const AnyType &theElement ) {
	checkIndex( theIndex );

	Node<AnyType> *currentNode = headNode;

	for ( int i = 0; i < theIndex; ++i ) {
		currentNode = currentNode->next;
	}

	currentNode->element = theElement;
}


// 删除指定区间内的所有节点，包括端点
template<class AnyType>
void LinkedList<AnyType>::removeRange( int begin, int end ) {
	checkIndex( begin );
	checkIndex( end );
	if ( begin > end ) {
		throw "begin should be bigger than end";
	}

	Node<AnyType> *currentNode = headNode;
	Node<AnyType> *beginNode = nullptr;                    // 要删除区间的开端节点
	Node<AnyType> *endNode = nullptr;                        // 要删除区间的末尾节点
	Node<AnyType> *previousBeginNode = nullptr;        // 开端节点的前一个节点
	Node<AnyType> *nextEndNode = nullptr;                // 末尾节点的后一个节点
	Node <AnyType> *deleteNode;

	for ( int i = 0; i <= end; ++i ) {
		// 找到要删除范围开端的前一个节点
		if ( begin != 0 && begin - 1 == i ) {
			previousBeginNode = currentNode;
		}

		if ( begin == i ) {
			beginNode = currentNode;
		}

		if ( end == i ) {
			endNode = currentNode;
		}
		currentNode = currentNode->next;
	}

	// 找到要删除范围末尾的下一个节点
	if ( end != listSize - 1 ) {
		nextEndNode = endNode->next;
	}

	if ( 0 == begin && listSize - 1 != end ) {
		headNode = nextEndNode;
	} else if ( 0 != begin && listSize - 1 == end ) {
		previousBeginNode->next = nullptr;
	} else if ( 0 != begin && listSize - 1 != end ) {
		previousBeginNode->next = nextEndNode;
	} else {
		clear();
		return ;
	}

	while ( beginNode != endNode ) {
		deleteNode = beginNode;
		beginNode = beginNode->next;
		delete deleteNode;
		listSize--;
	}
	deleteNode = beginNode;
	delete deleteNode;
	listSize--;
}


// 交换两个指定索引元素
template<class AnyType>
void LinkedList<AnyType>::swap( int theIndex1, int theIndex2 ) {
	checkIndex( theIndex1 );
	checkIndex( theIndex2 );
	if ( theIndex1 == theIndex2 ) {
		throw "theIndex1 should be different from theIndex2";
	}

	int theSmaller = theIndex1 < theIndex2 ? theIndex1 : theIndex2;
	int theBigger = theIndex1 > theIndex2 ? theIndex1 : theIndex2;
	Node<AnyType> *currentNode = headNode;
	Node<AnyType> *previousNode1 = nullptr;
	Node<AnyType> *previousNode2 = nullptr;
	Node<AnyType> *node1 = nullptr;
	Node<AnyType> *nextNode1 = nullptr;

	for ( int i = 0; i <= theBigger; ++i ) {
		if ( i == theSmaller - 1 ) {
			previousNode1 = currentNode;
		}

		if ( i == theSmaller ) {
			node1 = currentNode;
		}

		if ( i == theSmaller + 1 ) {
			nextNode1 = currentNode;
		}

		if ( i == theBigger - 1 ) {
			previousNode2 = currentNode;
		}
		currentNode = currentNode->next;
	}

	if ( 0 == theSmaller ) {
		// 当有节点为第一个节点时
		headNode = previousNode2->next;
		node1->next = previousNode2->next->next;
		previousNode2->next->next = nextNode1;
		previousNode2->next = node1;
	} else {
		node1->next = previousNode2->next->next;
		previousNode2->next->next = nextNode1;
		previousNode1->next = previousNode2->next;
		previousNode2->next = node1;
	}
}
