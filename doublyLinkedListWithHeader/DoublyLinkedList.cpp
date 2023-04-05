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


// 在索引 theIndex 处插入节点
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
			// 插入位置后没有节点
			headerNode->next = new doublyLinkedListNode::Node<AnyType>( theElement, nullptr, nullptr );
		}
	} else {
		// 在其他位置插入
		doublyLinkedListNode::Node<AnyType> *currentNode = headerNode;
		for ( int i = 0; i < theIndex; ++i ) {
			// 找到插入位置
			currentNode = currentNode->next;
		}
		currentNode->next = new doublyLinkedListNode::Node<AnyType>( theElement, currentNode, currentNode->next );
		currentNode->next->next->previous = currentNode->next;
	}

	listSize++;
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

} // doublyLinkedList