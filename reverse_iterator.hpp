#ifndef REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"
#include <iostream>

namespace ft{
template < typename T >
class reverse_iterator
{

    public:
        typedef T                                                  iterator_type;
        typedef typename ft::iterator_traits<T>::value_type        value_type;
        typedef typename ft::iterator_traits<T>::difference_type   difference_type;
        typedef typename ft::iterator_traits<T>::pointer           pointer;
        typedef typename ft::iterator_traits<T>::reference         reference;
        typedef typename ft::iterator_traits<T>::iterator_category iterator_category;

        //constructors
        reverse_iterator(iterator_type iter) : current(iter){};
        reverse_iterator(): current(NULL){};

        template< class U >
        reverse_iterator( const reverse_iterator<U>& other ) : current(other.base()++){};

        operator reverse_iterator<random_acces_iterator<const value_type> > () const
        {
            return(reverse_iterator<random_acces_iterator<const value_type> >(current));
        }

        template< class U >
        reverse_iterator& operator=( const reverse_iterator<U>& other )
        {
            current = other.base();
            current++;
            return *this;
        };
        ///Base
        iterator_type base() const
        {
            return (current - 1);
        }
        ///Accessor
        reference operator *() const
        {
            return *(base());
        };
        pointer operator->() const {
            return &(operator*());
        }
        reference operator[](int x) const
        {
            return (*(current - x- 1));
        };
        ///Members function
        reverse_iterator operator+(difference_type n) const
        {
            reverse_iterator tmp = *this;
            tmp.current -= n;
            return tmp;
        };
        reverse_iterator& operator++()
        {
            current--;
            return *this;
        };
        reverse_iterator operator++(int)
        {
            reverse_iterator tmp = *this;
            ++(*this);
            return tmp;
        };
        reverse_iterator& operator+=(const int n)
        {
            current -= n;
            return *this;
        };
        reverse_iterator operator-(int n)
        {
            reverse_iterator tmp = *this;
            tmp.current = tmp.current + n;
            return tmp;
        };
        difference_type operator-(const reverse_iterator<T> &rhs) const
        {
            difference_type x = 0;
            if (current > rhs.current)
                x = ft::distance(rhs, *this);
            else
                x = ft::distance(*this, rhs) * -1;
            return x;
        }
        reverse_iterator& operator--()
        {
            current++;
            return *this;
        };

        reverse_iterator operator--(int)
        {
            reverse_iterator tmp(*this);
            --(*this);
            return tmp;
        };
        
        reverse_iterator& operator-=(const int n)
        {
            current += n;
            return *this;
        };
        protected:
            iterator_type current;
};

/// Non member Reverse iterators functions
/*
template< class Iterator >
typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs,const reverse_iterator<Iterator>& rhs )
{
    std::cout <<"banger" << std::endl;
    return(rhs.base() - lhs.base());
};

template <class Iterator>
reverse_iterator<Iterator> operator+ ( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
{
    std::cout << "YOOOOOOOOOOO" << std::endl;
    return(reverse_iterator<Iterator>(rev_it.base() - n +5000));
};*/

template< class Iterator1, class Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{
    return(lhs.base() == rhs.base());
};

template< class Iterator1, class Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{
    return(lhs.base() != rhs.base());
};
template< class Iterator1, class Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{
    return(lhs.base() > rhs.base());
};
template< class Iterator1, class Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{
    return(lhs.base() >= rhs.base());
};

template< class Iterator1, class Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{
    return(lhs.base() < rhs.base());
};
template< class Iterator1, class Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{
    return(lhs.base() <= rhs.base());
};
};
#endif