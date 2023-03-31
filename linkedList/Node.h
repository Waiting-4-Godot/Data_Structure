//
// Created by HP on 2023/3/29.
//

#ifndef BLACKSKIN_MYCODE_NODE_H
#define BLACKSKIN_MYCODE_NODE_H

template<class AnyType>
class Node {
public:
    Node();
    explicit Node(const AnyType& element);
    Node(const AnyType& element, Node<AnyType>* next);


    AnyType element;
    Node<AnyType>* next;
};


#endif //BLACKSKIN_MYCODE_NODE_H
