//
// Created by HP on 2023/4/4.
//

#include "DoublyLinkedList.h"


namespace doublyLinkedList {

// 构造函数
template<class AnyType>
DoublyLinkedList<AnyType>::DoublyLinkedList() {
	headerNode = new doublyLinkedListNode::Node<AnyType>;
	headerNode->previous = nullptr;
	headerNode->next = headerNode;
	listSize = 0;
}


// 复制构造函数
template<class AnyType>
DoublyLinkedList<AnyType>::DoublyLinkedList( DoublyLinkedList<AnyType> &theList ) {

}


// 析构函数
template<class AnyType>
DoublyLinkedList<AnyType>::~DoublyLinkedList() {
	clear();
}


// 检查索引是否在[0, listSize - 1]范围内
template<class AnyType>
void DoublyLinkedList<AnyType>::checkIndex( int theIndex ) const {
	if ( theIndex < 0 || theIndex >= listSize ) {
		throw "非法索引";
	}
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

} // doublyLinkedList