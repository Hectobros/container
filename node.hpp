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
	Node(const Node& rhs) : data(rhs.data), parent(rhs.parent), left(rhs.left) ,right(rhs.right), height(1)
	{
	}
	operator Node<const T>()  {
		return(Node<const T>(data));
		/*ret.data = reinterpret_cast<const T>(data);

		ret.parent = reinterpret_cast<Node<const T> *>(parent);
		ret.left = reinterpret_cast<Node<const T> *>(left);
		ret.right = reinterpret_cast<Node<const T> *>(right);
		ret.height = height;
		return ret; */
	}
};
}

#endif