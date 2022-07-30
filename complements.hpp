#ifndef COMPLEMENTS_HPP
#define COMPLEMENTS_HPP
#include "iterator_traits.hpp"
#include "iterator_vector.hpp"

namespace ft
{
template<class random_acces_iterator>
typename iterator_traits<random_acces_iterator>::difference_type distance (random_acces_iterator first, random_acces_iterator last)
{
    typename iterator_traits<random_acces_iterator>::difference_type x = 0;
    for(; first != last; x++)
    {
        first++;
    }
    return x;
};
}
#endif