#ifndef ITERATOR_VECTOR
#define ITERATOR_VECTOR

#include "iterator_traits.hpp"
#include "complements.hpp"
#include <iostream>

namespace ft{

template < typename T >
class random_acces_iterator
{

    public:
        typedef typename ft::iterator_traits<T*>::value_type        value_type;
        typedef typename ft::iterator_traits<T*>::difference_type   difference_type;
        typedef typename ft::iterator_traits<T*>::pointer           pointer;
        typedef typename ft::iterator_traits<T*>::reference         reference;
        typedef typename ft::random_access_iterator_tag iterator_category;

        //constructors
        random_acces_iterator(const pointer _ptr) : _tab(_ptr){};
        random_acces_iterator(): _tab(NULL){};
        random_acces_iterator(const random_acces_iterator& rhs) : _tab(rhs._tab){};
        operator random_acces_iterator<const T>() const
        {
            return(random_acces_iterator<const T>(_tab));
        }
        random_acces_iterator& operator=(const random_acces_iterator& rhs)
        {
            _tab = rhs._tab;
            return *this;
        };
        ///Accessor
        reference operator *()
        {
            return *(_tab);
        };
        pointer operator->() const
        {
            return _tab; 
        };
        value_type operator[](int x)
        {
            return (*(_tab + x));
        };
        ///Operators
        //Incrementors
        random_acces_iterator& operator++()
        {
            _tab++;
            return *this;
        };
        random_acces_iterator operator++(int)
        {
            random_acces_iterator tmp = *this;
            _tab++;
            return tmp;
        };
        ///Decrementors
        random_acces_iterator& operator--()
        {
            _tab--;
            return *this;
        };
        random_acces_iterator operator--(int)
        {
            random_acces_iterator tmp = *this;
            _tab--;
            return tmp;
        };
        ///Arithmetic operators
        random_acces_iterator operator+(int n)
        {
            random_acces_iterator tmp = *this;
            tmp._tab = tmp._tab + n;
            return tmp;
        };
        random_acces_iterator operator-(int n) const
        {
            random_acces_iterator tmp = *this;
            tmp._tab = tmp._tab - n;
            return tmp;
        };
        difference_type operator-(const random_acces_iterator &rhs) const
        {
            difference_type x = 0;
            if (_tab > rhs._tab)
                x = ft::distance(rhs, *this);
            else
                x = ft::distance(*this, rhs) * -1;
            return x;
        }
        ///compound assignement operators
        random_acces_iterator& operator+=(const int n)
        {
            _tab = _tab + n;
            return *this;
        };
        random_acces_iterator& operator-=(const int n)
        {
            _tab = _tab - n;
            return *this;
        };
        pointer get_tab() const
        {
            return (_tab);
        }
        private:
            pointer _tab;
};

template < typename random_acces_iterator >
random_acces_iterator operator+(int n, random_acces_iterator& rhs)
{
    return random_acces_iterator(rhs) + n;
};

//comparators
template <class Iter1, class Iter2>
bool operator==(ft::random_acces_iterator<Iter1> const &lhs, ft::random_acces_iterator<Iter2> const &rhs )
{
    return lhs.get_tab() == rhs.get_tab();
};
template <class Iter1, class Iter2>
bool operator!=(ft::random_acces_iterator<Iter1> const &lhs, ft::random_acces_iterator<Iter2> const &rhs )
{
    return lhs.get_tab() != rhs.get_tab();
};
template <class Iter1, class Iter2>
bool operator<(ft::random_acces_iterator<Iter1> const &lhs, ft::random_acces_iterator<Iter2> const &rhs )
{
    return lhs.get_tab() < rhs.get_tab();
};
template <class Iter1, class Iter2>
bool operator>(ft::random_acces_iterator<Iter1> const &lhs, ft::random_acces_iterator<Iter2> const &rhs )
{
    return lhs.get_tab() > rhs.get_tab();
};
template <class Iter1, class Iter2>
bool operator>=(ft::random_acces_iterator<Iter1> const &lhs, ft::random_acces_iterator<Iter2> const &rhs )
{
    return lhs.get_tab() >= rhs.get_tab();
};
template <class Iter1, class Iter2>
bool operator<=(ft::random_acces_iterator<Iter1> const &lhs, ft::random_acces_iterator<Iter2> const &rhs )
{
    return lhs.get_tab() <= rhs.get_tab();
};

};
#endif