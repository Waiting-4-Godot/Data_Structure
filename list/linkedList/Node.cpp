//
// Created by HP on 2023/3/29.
//

#include "Node.h"


template<class AnyType>
Node<AnyType>::Node() = default;


template<class AnyType>
Node<AnyType>::Node( const AnyType &element ) {
    this->element = element;
}


template<class AnyType>
Node<AnyType>::Node( const AnyType &element, Node<AnyType> *next ) {
    this->element = element;
    this->next = next;
}
