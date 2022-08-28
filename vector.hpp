#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "./utils/iterator_traits.hpp"
#include "./vector_utils/iterator_vector.hpp"
#include "./utils/reverse_iterator.hpp"
/// HEADERS TESTER
#include <limits>
#include <algorithm>

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
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(n) , _size(n) , _tab(NULL)
            {
                if(_capacity > max_size())
                    throw std::length_error ("Too big to allocate");
                _tab = _alloc.allocate(_capacity);
                for (size_type x = 0; x < n; x++)
                    _alloc.construct(_tab + x, val);
            };

            template <typename InputIterator>
            vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc) , _capacity(0), _size(0), _tab(NULL)
            {
                insert(begin(), first, last);
            };
            
            vector (const vector& x) : _alloc(x._alloc), _capacity(0),_size(0), _tab(NULL)
            {
                assign(x.begin(),x.end());
            }

            ~vector()
            {
                clear();
                if(_tab != NULL)
                    _alloc.deallocate(_tab, _capacity);
            };
            vector& operator=( const vector& other )
            {
                _alloc = other.get_allocator();
                assign(other.begin(),other.end());
                return *this;
            };
            void assign( size_type count, const T& value )
            {
                clear();
                insert(begin(), count, value);
            };
            template< class InputIt >
            void assign( InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last)
            {
                clear();
                insert(begin(), first, last);
            };
            
            allocator_type get_allocator() const
            {
                return (_alloc);
            };



            ///Element Access
            
            reference at( size_type pos )
            {
                if (pos >= size())
                    throw std::out_of_range("Pos is too big");
                return(_tab[pos]);
            };
            const_reference at( size_type pos ) const
            {
                if (pos >= size())
                    throw std::out_of_range("Pos is too big");
                return(_tab[pos]);
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
                    if (_tab != NULL)
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
                if (count == 0)
                    return;
                size_type x = 0;
                size_type distf = ft::distance(pos, end());
                size_type distd = ft::distance(begin(), pos);
                if  (count + _size > _capacity)
                    reserve(_akinator(_size ,count + _size ));
                for (reverse_iterator c = rbegin();  x < distf; x++)
                {
                    _alloc.construct(_tab + ft::distance(begin(), c.base() - 1) + count, *c);
                    _alloc.destroy((c.base() - 1).get_tab());
                    c++;
                }
                for (x = 0 ;x < count; x++)
                    _alloc.construct(_tab + distd + x, value);
                _size = count + _size;
            };

            template< class InputIt>
            void insert( iterator pos, InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value , InputIt>::type last)
            {
                if (first == last)
                    return;
                size_type distd = ft::distance(begin(), pos);
                for(size_type x = 0; first != last ; x++)
                {
                    insert(begin() + distd + x, *first);
                    first++;
                }
            };

            iterator erase( iterator pos )
            {
                iterator posd = pos;
                for(; posd + 1 != end();posd++)
                {
                    *posd= *(posd + 1);
                }
                if (posd != end())
                {
                    _alloc.destroy(posd.get_tab());
                    _size--;
                }
                return (pos);
            };
            iterator erase( iterator first, iterator last )
            {
                size_type distancedeb = ft::distance(begin(), first);
                size_type setback = 0;
                if (first == last)
                    return last;
                if (last >= end())
                {
                    for (size_type x = 0;first < last; first++)
                    {
                        _alloc.destroy(_tab + distancedeb + x);
                        _size--;
                        x++;
                    }
                    return(end());
                }
                else
                {
                    for (; first < last; first++)
                        setback++;
                    for (size_type y = 0; y < setback; y++)
                        _alloc.destroy(_tab + distancedeb + y);
                    for (size_type start = distancedeb ; start < _size; start++)
                    {
                        if (start >= distancedeb + setback)
                            _alloc.destroy(_tab + start);
                        if (start + setback < _size)
                            _alloc.construct(_tab + start, *(_tab + start + setback));
                    }
                    _size = _size - setback;
                    return (begin() + distancedeb);
                }
            };

            void pop_back()
            {
                erase(end() - 1);
            };

            void push_back( const T& value )
            {
                insert(end(), value);
            };

            void resize( size_type count, T value = T())
            {
                if (count < _size)
                {
                    erase(begin() + count, end());
                }
                else if (count > _size)
                {
                    insert(end(), count - _size, value);
                }
            };
            void swap( vector& other )
            {
                allocator_type  temp_alloc;
                size_type       temp_capacity;
                size_type       temp_size;
                pointer         temp_tab;

                temp_size = other._size;
                temp_alloc = other._alloc;
                temp_tab = other._tab;
                temp_capacity = other._capacity;
                other._alloc = _alloc;
                other._capacity = _capacity;
                other._size = _size;
                other._tab = _tab;
                _alloc = temp_alloc;
                _capacity = temp_capacity;
                _size = temp_size;
                _tab = temp_tab;
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
            pointer         _tab;
            size_type   _akinator(size_type _cap, size_type new_s)
            {
                if (_cap == 0)
                    _cap  = 1;
                while (_cap < new_s)
                    _cap = _cap * 2;
                if (_cap >= max_size() && new_s <= max_size())
                    _cap = max_size();
                return (_cap);
            }
    };

    template <class T, class Alloc>
    void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
    {
        x.swap(y);
    };

    template< class T, class Alloc >
    bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
    {
        typename ft::vector<T,Alloc>::const_iterator first1 = lhs.begin();
        typename ft::vector<T,Alloc>::const_iterator last1 = lhs.end();
        typename ft::vector<T,Alloc>::const_iterator first2 = rhs.begin();
        typename ft::vector<T,Alloc>::const_iterator last2 = rhs.end();

        while(first1 != last1)
        {
            if(first2 == last2 || *first1 != *first2)
                return false;
            first1++;
            first2++;
        }
        return (last2 == first2);
    };

    template< class T, class Alloc >
    bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
    {
        return(!(lhs == rhs));
    };

    template< class T, class Alloc >
    bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    };

    template< class T, class Alloc >
    bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
    {
        return (((lhs < rhs) || (lhs == rhs)));
    };

    template< class T, class Alloc >
    bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
    {
        return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    };

    template< class T, class Alloc >
    bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
    {
        return (((lhs > rhs) || (lhs == rhs)));
    }; 
}
#endif