//
// Created by HP on 2023/3/29.
//

#include "LinkedList.h"
#include "LinkedList.cpp"
#include <iostream>


int main() {
	LinkedList<int> linkedList;
	linkedList.insert( 0, 1 );
	linkedList.insert( 0, 2 );
	linkedList.insertBack( 3 );
	linkedList.insertBefore( 4 );
	linkedList.insert( 1, 5 );
	linkedList.insertBack( 6 );
	std::cout << "size = " << linkedList.size() << std::endl;
	std::cout << "isEmpty: " << linkedList.isEmpty() << std::endl;
	std::cout << linkedList << std::endl;
	std::cout << "所查找元素的索引为: " << linkedList.indexOf( 6 ) << std::endl;
	std::cout << "索引为 3 的节点的值为：" << linkedList.get( 3 ) << std::endl;
	std::cout << "被删除元素为：" << linkedList.erase( 0 ) << std::endl;
	std::cout << "size = " << linkedList.size() << std::endl;
	linkedList.clear();
	linkedList.insert(0, 1);
	linkedList.insertBack(2);
	linkedList.insertBefore(3);
	linkedList.insert(1, 4);
	std::cout << linkedList << std::endl;
	std::cout << linkedList.size() << std::endl;
	try {
		linkedList.set(4, 5);
	} catch (char const* e) {
		std::cout << e << std::endl;
	}

	std::cout << linkedList << std::endl;
}