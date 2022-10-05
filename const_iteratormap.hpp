#ifndef CONST_BITERATORMAP_HPP
#define CONST_BITERATORMAP_HPP
#include "node.hpp"
#include "./utils/iterator_traits.hpp"
#include "./utils/complements.hpp"
#include "iteratormap.hpp"


namespace ft
{
    template <typename T>
    class biterator;
    template <typename T>
    class const_biterator : public ft::biterator<T>
    {
        public:
            typedef T		value_type;
            typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
            typedef const value_type*          pointer;
            typedef const value_type&		    reference;
            typedef typename std::bidirectional_iterator_tag			iterator_category;
			const_biterator() : biterator<T>() {};
			const_biterator(Node<T>* n) : biterator<T>(n){};
			const_biterator(const biterator<T> &n) : biterator<T>(n){};
			~const_biterator(){};
            pointer		operator->() const
            {
                return (&(this->node->data));
            };
            reference		operator*() const
		    {
			    return (this->node->data);
		    };/*
            T*		operator->()
            {
                return (&(this->node->data));
            };
            T&		operator*()
		    {
			    return (this->node->data);
		    };*/
    };
};


#endif