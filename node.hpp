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
};
}

#endif