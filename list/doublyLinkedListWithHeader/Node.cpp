//
// Created by HP on 2023/4/4.
//

#include "Node.h"


// 构造函数
namespace doublyLinkedListNode {

template<class AnyType>
Node<AnyType>::Node( AnyType element ) {
	this->element = element;
}


template<class AnyType>
Node<AnyType>::Node( AnyType element, Node<AnyType> *previous, Node<AnyType> *next ) {
	this->element = element;
	this->previous = previous;
	this->next = next;
}

} // doublyLinkedListNode




