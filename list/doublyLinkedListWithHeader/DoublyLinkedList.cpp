//
// Created by HP on 2023/4/4.
//

#include "DoublyLinkedList.h"


namespace doublyLinkedList {

// 构造函数
template<class AnyType>
DoublyLinkedList<AnyType>::DoublyLinkedList() {
	headerNode = new doublyLinkedListNode::Node<AnyType>;
	headerNode->element = -1;
	headerNode->previous = nullptr;
	headerNode->next = headerNode;
	listSize = 0;
}


// 复制构造函数
template<class AnyType>
DoublyLinkedList<AnyType>::DoublyLinkedList( DoublyLinkedList<AnyType> &theList ) {
	listSize = theList.listSize;

	// 链表 theList 为空
	if ( 0 == listSize ) {
		return;
	}

	// 链表 theList 非空，复制第一个节点
	doublyLinkedListNode::Node<AnyType> *sourceNode = theList.headerNode->next;
	doublyLinkedListNode::Node<AnyType> *targetNode = headerNode;
	targetNode->next = new doublyLinkedListNode::Node<AnyType>( sourceNode->element, nullptr, sourceNode->next );
	sourceNode = sourceNode->next;
	targetNode = targetNode->next;

	// 复制剩余节点
	while ( sourceNode != nullptr ) {
		targetNode->next = new doublyLinkedListNode::Node<AnyType>(
				sourceNode->element,
				targetNode,
				sourceNode->next );
		sourceNode = sourceNode->next;
		targetNode = targetNode->next;
	}
	targetNode->next = nullptr;
}


// 析构函数
template<class AnyType>
DoublyLinkedList<AnyType>::~DoublyLinkedList() {
	clear();
}


// 清空链表
template<class AnyType>
void DoublyLinkedList<AnyType>::clear() {

	while ( headerNode->next != headerNode ) {
		doublyLinkedListNode::Node<AnyType> *currentNode = headerNode->next;

		if ( headerNode->next->next != nullptr ) {
			headerNode->next = headerNode->next->next;
			headerNode->next->previous = nullptr;
		} else {
			headerNode->next = headerNode;
		}
		delete currentNode;
	}
	listSize = 0;
}


// 检查索引是否在[0, listSize - 1]范围内
template<class AnyType>
void DoublyLinkedList<AnyType>::checkIndex( int theIndex ) const {
	if ( theIndex < 0 || theIndex > listSize ) {
		throw "非法索引";
	}
}


// 返回指定索引处的节点, 若链表中没有除头节点以外的节点则返回头节点
template<class AnyType>
doublyLinkedListNode::Node<AnyType>* DoublyLinkedList<AnyType>::getNode( int theIndex ) {
	doublyLinkedListNode::Node<AnyType> *currentNode = headerNode->next;

	for ( int i = 0; i < theIndex; ++i ) {
		currentNode = currentNode->next;
	}

	return currentNode;
}


// 返回链表长度
template<class AnyType>
int DoublyLinkedList<AnyType>::size() const {
	return listSize;
}


// 链表是否为空。非空返回0，空返回1
template<class AnyType>
bool DoublyLinkedList<AnyType>::isEmpty() const {
	return listSize == 0;
}


// 将链表放入输出流
template<class AnyType>
void DoublyLinkedList<AnyType>::output( std::ostream &out ) const {
	doublyLinkedListNode::Node<AnyType> *currentNode = headerNode->next;

	while ( currentNode != nullptr && currentNode != headerNode ) {
		out << currentNode->element << " ";
		currentNode = currentNode->next;
	}
}


// 重载 << 运算符
template<class AnyType>
std::ostream& operator<<( std::ostream &out, const doublyLinkedList::DoublyLinkedList<AnyType> &linkedList ) {
	linkedList.output( out );
	return out;
}


// 在指定的索引 theIndex 处插入节点
template<class AnyType>
void DoublyLinkedList<AnyType>::insert( const int theIndex, const AnyType theElement ) {
	checkIndex( theIndex );

	if ( 0 == theIndex ) {
		// 在索引为 0 处插入节点
		if ( 0 != listSize ) {
			/*
			 * 插入位置后有节点
			 * 创建一个节点，节点中元素为 theElement, previous 指向空，next 指向头节点的下一个节点。
			 * 并使头节点的 next 指向该新节点
			 */
			headerNode->next = new doublyLinkedListNode::Node<AnyType>( theElement, nullptr, headerNode->next );
			// 使原索引为0的节点的 previous 指向现索引为0的节点
			headerNode->next->next->previous = headerNode->next;
		} else {
			// 插入位置后没有节点(该节点为第一个节点)
			headerNode->next = new doublyLinkedListNode::Node<AnyType>( theElement, nullptr, nullptr );
		}
	} else {
		// 在其他位置插入
		doublyLinkedListNode::Node<AnyType> *currentNode = getNode( theIndex );
		currentNode->next = new doublyLinkedListNode::Node<AnyType>( theElement, currentNode, currentNode->next );
		if ( (listSize - 1) != theIndex ) {
			/*
			 * 在插入位置后面还有节点
			 * 此时该节点的 previous 还指向 currentNode，需要修改其指向，将其指向插入的节点
			 */
			currentNode->next->next->previous = currentNode->next;
		}
	}

	listSize++;
}


// 在链表头部 进行插入
template<class AnyType>
void DoublyLinkedList<AnyType>::insertFront( const AnyType theElement ) {
	insert( 0, theElement );
}


// 在链表尾部进行插入
template<class AnyType>
void DoublyLinkedList<AnyType>::insertBack( const AnyType theElement ) {
	insert( listSize - 1, theElement );
}


// 删除指定索引处节点
template<class AnyType>
AnyType DoublyLinkedList<AnyType>::remove( int theIndex ) {
	checkIndex( theIndex );

	doublyLinkedListNode::Node<AnyType> *deleteNode = getNode( theIndex );
	AnyType deleteElement = deleteNode->element;

	if ( 0 == theIndex ) {
		// 删除的为第一个节点
		headerNode->next = deleteNode->next;
		deleteNode->next->previous = nullptr;
	} else if (( listSize - 1 ) == theIndex) {
		// 删除的为最后一个节点
		deleteNode->previous->next = nullptr;
	} else {
		// 删除的节点为中间节点
		deleteNode->previous->next = deleteNode->next;
		deleteNode->next->previous = deleteNode->previous;
	}
	delete deleteNode;
	listSize--;

	return deleteElement;
}


// 删除指定索引 [theFront, theBack] 范围内的所有节点
template<class AnyType>
void DoublyLinkedList<AnyType>::remove( int theFront, int theBack ) {
	if ( theFront > theBack ) {
		throw "theFront must be bigger than theBack";
	}
	checkIndex( theFront );
	checkIndex( theBack );

	if ( 0 == theFront && listSize - 1 == theBack ) {
		clear();
	} else if ( theFront == theBack ) {
		remove( theFront );
	} else {
		doublyLinkedListNode::Node<AnyType> *frontNode = getNode( theFront );
		doublyLinkedListNode::Node<AnyType> *backNode = getNode( theBack );
		doublyLinkedListNode::Node<AnyType> *currentNode = frontNode;
		doublyLinkedListNode::Node<AnyType> *deleteNode = currentNode;

		while ( currentNode != backNode ) {
			currentNode->previous->next = currentNode->next;
			currentNode->next->previous = currentNode->previous;
			currentNode = currentNode->next;
			delete deleteNode;
			deleteNode = currentNode;
		}
		currentNode->previous->next = currentNode->next;
		currentNode->next->previous = currentNode->previous;
		delete deleteNode;

		listSize = listSize - theBack + theFront - 1;
	}
}

} // doublyLinkedList