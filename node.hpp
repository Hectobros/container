#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

namespace ft
{
template<typename T>
class node {
public:
    typedef  T     val;
    typedef  ft::node<T> nod;
    nod    *parent;
    nod    *lchild;
    nod    *rchild;
    T               value;
    int     type;
    node() : parent(NULL), lchild(NULL), rchild(NULL), value(val());
    node(val x, nod dad, int type_spec) : value(x), parent(dad), type(type_spec) {};
    ~node(){};
};

template<typename T, class alloc = std::allocator<T> >
class tree {
    public:
    typedef ft::node<T> node;
    typedef alloc       allocator_type;       
    tree(const allocator_type& alloc = allocator_type()) : root(NULL), _alloc(alloc);
    tree(node *r) : root(r), _alloc(alloc) 
    private:
    node    *_root;
    alloc   _alloc;
};




}

#endif