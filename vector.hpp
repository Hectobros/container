#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "iterator_traits.hpp"
#include "iterator_vector.hpp"
#include "reverse_iterator.hpp"

namespace ft {
    template < class T, class Allocator = std::allocator<T> >
    class vector
    {
        public:
            ///Member type
            typedef T                                              value_type;
            typedef Allocator                                      allocator_type;
            typedef typename allocator_type::reference             reference;
            typedef typename allocator_type::const_reference       const_reference;
            typedef typename allocator_type::pointer               pointer;
            typedef typename allocator_type::const_pointer         const_pointer;
            typedef typename ft::random_acces_iterator<T>          iterator;
            typedef typename ft::random_acces_iterator<const T>    const_iterator;
            typedef typename ft::reverse_iterator<iterator>        reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator>  const_reverse_iterator;// dinguerie dans l'overload du +
            typedef typename std::ptrdiff_t                        difference_type;
            typedef typename std::size_t                           size_type;
            
            ///Member functions



            ///Constructors
            explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0), _tab(NULL)
            {
            };
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n) , _size(n)
            {
                _tab = _alloc.allocate(_capacity);
                for (size_type x = 0; x < n; x++)
                    _alloc.construct(_tab + x, val);
            };/*
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
            vector (const vector& x) Need insert avec Iterators (enable if)
            {
            };
            vector& operator=( const vector& other );
            void assign( size_type count, const T& value );///Need clear
            template< class InputIt >
            void assign( InputIt first, InputIt last );
            */
            allocator_type get_allocator() const
            {
                return (_alloc);
            };



            ///Element Access
            reference at( size_type pos )
            {
                if (pos > size())
                    throw std::out_of_range("Pos is too big");
                return(*(_tab + pos));
            };
            const_reference at( size_type pos ) const
            {
                if (pos > size())
                    throw std::out_of_range("Pos is too big");
                return(*(_tab + pos));
            };
            reference operator[]( size_type pos )
            {
                return(*(_tab + pos));
            };
            const_reference operator[]( size_type pos ) const
            {
                return(*(_tab + pos));
            };
            reference front()
            {
                return(*(_tab));
            };
            const_reference front() const
            {
                return(*(_tab));
            };
            reference back()
            {
                return(*(_tab + _size - 1));
            };
            const_reference back() const
            {
                return(*(_tab + _size - 1));
            };
            T* data()
            {
                return (_tab);
            };
            const T* data() const
            {
                return (_tab);
            };



            ///iterator functions
            iterator begin()
            {
                return iterator(_tab);
            };
            const_iterator begin() const
            {
                return const_iterator(_tab);
            };
            iterator end()
            {
                return iterator(_tab + _size);
            };
            const_iterator end() const
            {
                return const_iterator(_tab + _size);
            };
            reverse_iterator rbegin()
            {
                return reverse_iterator(_tab + _size);
            };
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(_tab + _size);
            };
            reverse_iterator rend()
            {
                return reverse_iterator(_tab);
            };
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(_tab);
            };



            ///Capacity
            bool empty() const
            {
                return (_size == 0);
            };
            size_type size() const
            {
                return (_size);
            };
            size_type max_size() const
            {
                return (_alloc.max_size());
            };
            void reserve( size_type new_cap )
            {
                pointer new_tab;
                if (new_cap > max_size())
                    throw std::length_error("Error capacity");
                else if (new_cap < _capacity)
                    return;
                else
                {
                    new_tab = _alloc.allocate(new_cap);
                    for(size_type x = 0; x < _size; x++)
                    {
                        _alloc.construct(new_tab + x, *(_tab + x));
                        _alloc.destroy(_tab + x);
                    }
                    _alloc.deallocate(_tab, _capacity);
                    _tab = new_tab;
                    _capacity = new_cap;
                }
            };
            size_type capacity() const
            {
                return (_capacity);
            };



            ///Modifiers
            void clear()
            {
                for (size_type x = 0 ; x < _size ; x++)
                    _alloc.destroy(_tab + x);
                _size = 0;
            };
            iterator insert( iterator pos, const T& value )
            {
                size_type distd = ft::distance(begin(), pos);
                insert(pos, 1, value);
                return (begin() + distd);
            };
            void insert( iterator pos, size_type count, const T& value )
            {
                size_type x = 0;
                size_type distf = ft::distance(pos, end());
                size_type distd = ft::distance(begin(), pos);
                if  (count + _size > _capacity)
                    reserve(count + _size + 10);
                for (reverse_iterator c = rbegin();  x < distf; x++)
                {
                    _alloc.construct(_tab + ft::distance(begin(), c.base()) + count, *c);
                    _alloc.destroy(c.base().get_tab());
                    c++;
                }
                for (x = 0 ;x < count; x++)
                    _alloc.construct(_tab + distd + x, value);
                _size = count + _size;
            };/*
            template< class InputIt >
            void insert( iterator pos, InputIt first, InputIt last )
            {
                if (first == last)
                {
                    insert(pos, *first);
                    return;
                }
                size_type distd = ft::distance(begin(), pos);
                size_type distp = ft::distance(first, last);
                reserve(_size + distp);
                pos = begin() + distd;
                for(size_type x = 0; x < distp ; x++)
                {
                    insert(pos, *first);
                    first++;
                }
            }
            iterator erase( iterator pos )
            {
            };*/
            iterator erase( iterator first, iterator last )
            {
                size_type setback = distance(first, last);
                if (setback == 0)
                    return last;
                if (last >= end())
                {
                    for (;first < last; first++)
                    {
                        _alloc.destroy(first.get_tab());
                        _size--;
                    }
                    return(end());
                }
                else
                {
                    for (; first < last; first++)
                        _alloc.destroy(first.get_tab());
                    for (; first < end(); first++)
                        _alloc.construct((first - setback).get_tab(), *first);
                    _size = _size - setback;
                    return (last - setback);
                }
            };
            ///Debug function
            void printvect( void )
            {
                std::cout << "Mon vector contient: ";
                for (size_type x = 0; x < _size; x++)
                    std::cout << _tab[x] << " ";
                std::cout << std::endl;
            } 
        private:
            allocator_type  _alloc;
            size_type       _capacity;
            size_type       _size;
            pointer         _tab;/*
            size_type   _akinator(size_type _cap, size_type new_s)
            {
                while (_cap < new_s)
                    _cap = _cap * 2;
                return (_cap);
            }*/
    };
};
#endif