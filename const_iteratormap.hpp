#ifndef CONST_BITERATORMAP_HPP
#define CONST_BITERATORMAP_HPP
#include "node.hpp"
#include "./utils/iterator_traits.hpp"
#include "./utils/complements.hpp"
#include "iteratormap.hpp"

namespace ft
{
    template <typename T>
    class const_biterator : public ft::biterator<T>
    {
        public:
			const_biterator() : biterator<T>() {};
			const_biterator(Node<T>* n) : biterator<T>(n){};
			const_biterator(const biterator<T> &n) : biterator<T>(n){};
			~const_biterator(){};
    };
};


#endif