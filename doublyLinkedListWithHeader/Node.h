//
// Created by HP on 2023/4/4.
//

#ifndef BLACKSKIN_MYCODE_NODE_H
#define BLACKSKIN_MYCODE_NODE_H

namespace doublyLinkedListNode {

template<class AnyType>
class Node {
public:
	Node() = default;
	explicit Node( AnyType element );
	Node( AnyType element, Node<AnyType> *previous, Node<AnyType> *next );

private:
	AnyType element;
	Node *previous;
	Node *next;
};

}// doublyLinkedList


#endif //BLACKSKIN_MYCODE_NODE_H
