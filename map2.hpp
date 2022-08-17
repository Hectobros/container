#ifndef MAP2_HPP
#define MAP2_HPP

#include <iostream>
#include "./vector_utils/iterator_vector.hpp"

namespace ft{
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
class map
{
    public:
    typedef Key key_type;
    typedef T   mapped_type;
    typedef ft::pair<const key_type, mapped_type>   value_type;
    typedef Compare                                 key_compare;
    //value_compare;
    typedef Alloc                                   allocator_type;
    typedef typename allocator_type::reference      reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    /* iterator
    const_iterator
    reverse_iterator
    const_reverse_iterator*/
    typedef typename std::ptrdiff_t                     difference_type;
    typedef typename std::size_t                        size_type;

    map()
    {
        std::cout << "Hello World" << std::endl;
    };
};
}

#endif