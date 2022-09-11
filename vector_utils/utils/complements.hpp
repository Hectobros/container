#ifndef COMPLEMENTS_HPP
#define COMPLEMENTS_HPP
#include <iostream>
#include "iterator_traits.hpp"
//#include "../vector_utils/iterator_vector.hpp"


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

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
    while (first1!=last1)
    {
        if (first2==last2 || *first2<*first1)
            return false;
        else if (*first1<*first2)
            return true;
        ++first1;
        ++first2;
    }
    return (first2!=last2);
};


template<bool b, typename T = void>
struct enable_if {
    typedef T type;
    static const int soluce = 1;
};

template<typename T>
struct enable_if<false, T> {};

template <class T, T v>
struct integral_constant {
  static const T value = v;
  typedef T value_type;
  typedef integral_constant<T,v> type;
};

typedef integral_constant<bool, true>     true_type;
typedef integral_constant<bool, false>    false_type;

template<typename>
struct is_integral : public false_type { };

template<>
struct is_integral<bool> : public true_type { };

template<>
struct is_integral<char> : public true_type { };

template<>
struct is_integral<wchar_t> : public true_type { };

template<>
struct is_integral<signed char> : public true_type { };

template<>
struct is_integral<short int> : public true_type { };

template<>
struct is_integral<int> : public true_type { };

template<>
struct is_integral<long int> : public true_type { };

template<>
struct is_integral<long long int> : public true_type { };

template<>
struct is_integral<unsigned char> : public true_type { };

template<>
struct is_integral<unsigned short int> : public true_type { };

template<>
struct is_integral<unsigned int> : public true_type { };

template<>
struct is_integral<unsigned long int> : public true_type { };

template<>
struct is_integral<unsigned long long int> : public true_type { };

template <class T1, class T2>
struct pair
{
    typedef T1  first_type;
    typedef T2  second_type;

    first_type  first;
    second_type second;
    pair() : first(first_type()), second(second_type()) {};

    template<class U, class V>
    pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {};

    pair (const first_type& a, const second_type& b) : first(a), second(b){};
    pair& operator= (const pair& pr)
    {
        first = pr.first;
        second = pr.second;
        return *this;
    };
    ~pair(){};
};

template< class T1, class T2 >
ft::pair<T1,T2> make_pair( T1 t, T2 u )
{
    return ft::pair<T1, T2>(t, u);
};

template< class T1, class T2 >
bool operator==( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
    return(lhs.first == rhs.first && lhs.second == rhs.second);
};

template< class T1, class T2 >
bool operator!=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
    return(!(lhs == rhs));
};

template< class T1, class T2 >
bool operator<( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
    if (lhs.first > rhs.first)
        return (false);
    if ((lhs.second > rhs.second) || lhs == rhs)
        return (false);
    return true;
};

template< class T1, class T2 >
bool operator<=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
    if (lhs.first > rhs.first)
        return (false);
    if ((lhs.second > rhs.second))
        return (false);
    return true;
};

template< class T1, class T2 >
bool operator>( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
    if (lhs.first < rhs.first)
        return (false);
    if ((lhs.second < rhs.second) || lhs == rhs)
        return (false);
    return true;
};

template< class T1, class T2 >
bool operator>=( const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs )
{
    if (lhs.first < rhs.first)
        return (false);
    if ((lhs.second < rhs.second))
        return (false);
    return true;
};

template <class Arg1, class Arg2, class Result>
  struct binary_function {
    typedef Arg1 first_argument_type;
    typedef Arg2 second_argument_type;
    typedef Result result_type;
};

template <class T> struct less : binary_function <T,T,bool> {
  bool operator() (const T& x, const T& y) const {return x<y;}
};

}
#endif