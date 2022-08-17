#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include "iteratormap.hpp"

namespace ft
{
template<typename T>
class node {
    private:
    node *parent;
    node *lchild;
    node *rchild;
    T     value;
    int   type;
    public:
    typedef ft::biterator<node>    iterator;
    node() : parent (NULL), lchild (NULL), rchild(NULL) , value(0), type(-1) {}; 
    node(T x, node *father, int t) : parent(father), lchild(NULL), rchild(NULL), value(x), type(t){};
    ~node() {};
    node *get_parent()
    {
        return parent;
    }
    void search(T x)
    {
        if (x < value)
            lchild->search(x);
        else if (x > value)
            rchild->search(x);
        else
            std::cout << "I FOUND THE NODE : " << value << std::endl;
    }
    void add(T x)
    {
        if (x < value)
        {
            if (!lchild)
            {
                if(type == -3)
                {
                    value = x;
                    type = 0;
                }
                else
                    add_lchild(new node(x, this, 0));
            }
            else
                lchild->add(x);
        }
        else if (x > value)
        {
            if (!rchild)
            {
                if(type == -2)
                {
                    value = x;
                    type = 1;
                }
                else
                    add_rchild(new node(x, this, 1));
            }
            else
                rchild->add(x);
        }
        else
            std::cout << "Error" << std::endl;
    }
    void add_value(T x)
    {
        value = x;
    };
    void add_parent(node *x)
    {
        parent = x;
    };
    void add_lchild(node *x)
    {
        lchild = x;
    };
    void add_rchild(node *x)
    {
        rchild = x;
    };
    void print_value() {
        std::cout << "Hey the value is : " << value << std::endl;
    };
    T   get_value()
    {
        return value;
    }
    node& min()
    {
        node *temp;
        if (lchild)
        {
            temp = lchild;
            while (temp->lchild && temp->lchild->type != -3)
                temp = temp->lchild;
            return *temp;
        }
        return *this;
    };
    node& max()
    {
        node *temp;
        if (rchild)
        {
            temp = rchild;
            while (temp->rchild && temp->rchild->type != -2)
                temp = temp->rchild;
            return *temp;
        }
        return *this;
    };
    int get_type()
    {
        return type;
    };
    iterator begin()
    {
        return (iterator(&min()));
    };
    node*    get_next()
    {
        if(rchild)
        {
            return(&rchild->min());
        }
        else if (this->type == 0 || this->type == -3)
        {
            return (parent);
        }
        else if (this->type == 1)
        {
            node *temp;
            temp = this;
            while (temp->type == 1)
                temp = temp->parent;
            if (temp->type == -1)
            {
                add_rchild(new node(0,&(temp->max()),-2));
                return (rchild);
            }
            return (temp->parent);
        }
        return (new node());
    };
    node*    get_prev()
    {
        if(lchild)
        {
            return(&lchild->max());
        }
        else if (this->type == 1 || this->type == -2)
        {
            return(parent);
        }
        else if (this->type == 0)
        {
            node *temp;
            temp = this;
            while (temp->type == 0)
                temp = temp->parent;
            if (temp->type == -1)
            {
                add_lchild(new node(0,&temp->min(),-3));
                return (lchild);
            }
            return (temp->parent);
        }
        return (new node());
    };
};
}
#endif