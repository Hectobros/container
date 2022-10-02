#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

namespace ft
{
template <class T>
class Node {
    public:
    T data;
    Node    *parent;
    Node    *left;
    Node    *right;
    int height;
	Node() {};
	Node(const T& value) : data(value), parent(NULL), left(NULL) ,right(NULL), height(1)
	{

	};
	~Node() {};
	operator Node<const T>() const {
		Node<const T>	ret;
		ret.data = reinterpret_cast<const T>(data);

		ret.parent = reinterpret_cast<Node<const T> *>(parent);
		ret.left = reinterpret_cast<Node<const T> *>(left);
		ret.right = reinterpret_cast<Node<const T> *>(right);
		return ret; 
	}
};
}

#endif