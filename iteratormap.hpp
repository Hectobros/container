#ifndef BITERATORMAP_HPP
#define BITERATORMAP_HPP
#include "node.hpp"

namespace ft
{
    template <typename T>
    class biterator
    {
        private:
            T *node;
            T *nplus;
            T *nmoins;
        public:
        biterator(T *n) : node(n), nplus(NULL), nmoins(NULL) {};
        biterator() : node(NULL){};
        biterator& operator=(biterator rhs)
        {
            rhs.print_value();
            node = rhs.node;
            nplus = rhs.nplus;
            nmoins = rhs.nmoins;
            return *this;
        };
        biterator& operator++()
        {
            if(node)
            {
                if (node->right)
                {
                    node = node->right;
                    while (node->left)
                    {
                        node = node->left;
                    }
                }
                else
                {
                    while (node->parent && node->parent->right == node)
                    {
                        node = node->parent;
                    }
                    if (node->parent ==  NULL)
                    {
                        while (node->right)
                        {
                            node = node->right;
                        }
                        nplus = node;
                        node = NULL;
                    }
                    else
                        node = node->parent;
                }
            }
            else if (nmoins)
            {
                node = nmoins;
                nmoins = NULL;
            }
            print_value();
            return *this;
        };
        biterator& operator--()
        {
            if(node)
            {
                if (node->left)
                {
                    node = node->left;
                    while (node->right)
                    {
                        node = node->right;
                    }
                }
                else
                {
                    while (node->parent && node->parent->left == node)
                    {
                        node = node->parent;
                    }
                    if (node->parent ==  NULL)
                    {
                        while (node->left)
                        {
                            node = node->left;
                        }
                        nmoins = node;
                        node = NULL;
                    }
                    else
                        node = node->parent;
                }
            }
            else if (nplus)
            {
                node = nplus;
                nplus = NULL;
            }
            print_value();
            return *this;
        };
        void print_value()
        {
            if (node)
                std::cout << "Rank : " << node->data.first << std::endl;
        }
    };
};


#endif