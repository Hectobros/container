#ifndef ITERATORMAP_HPP
#define ITERATORMAP_HPP
#include "map.hpp"

namespace ft
{
    template <typename T>
    class biterator
    {
        private:
        T *node;
        public:
        biterator(T *n) : node(n) {};
        biterator() : node(NULL){};
        biterator& operator=(biterator rhs)
        {
            rhs.print_value();
            node = rhs.node;
            return *this;
        };
        void operator++()
        {
            if(node->get_type() != -2)
            {
                node = node->get_next();
                std::cout << "LA NODE EST " << node->get_value() << " et sont pere est " <<node->get_parent() << "Et son addresse" << &node <<std::endl;

            }
        };
        void operator--()
        {
            if(node->get_type() != -3)
                node = node->get_prev();
            std::cout << "LA NODE EST " << node->get_value() << std::endl;
        };
        void print_value()
        {
            std::cout << "VALUE : " << node->get_value() << std::endl;
        }
    };
};


#endif