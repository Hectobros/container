#ifndef MAP_HPP
#define MAP_HPP

#include "./utils/complements.hpp"
#include <functional>
#include "./iteratormap.hpp"
#include "./node.hpp"
#include "./utils/reverse_iterator.hpp"
#include "./const_iteratormap.hpp"
namespace ft
{

    template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef Alloc allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef Node<value_type> node;
        typedef node *nodePTR;
        typedef typename allocator_type::template rebind<node>::other allocator_node;
        class value_compare
        {
        public:
            Compare comp;
            value_compare(Compare c = key_compare()) : comp(c) {} // constructed with map's comparison object
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator()(const value_type &x, const value_type &y) const
            {
                return comp(x.first, y.first);
            }
        };
        typedef typename ft::biterator<value_type> iterator;
        typedef typename ft::const_biterator<value_type> const_iterator;
        typedef typename ft::reverse_iterator<iterator> reverse_iterator;
        typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef std::size_t size_type;

        // Constructor && Destructor
        explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _comp(comp), _size(0)
        {
            _root = NULL;
        };

        template <class InputIt>
        map(InputIt first, InputIt last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _alloc_node(allocator_node()), _comp(comp), _size(0)
        {
            _root = NULL;
            insert(first, last);
        };
        map(const value_type &v) : _alloc(allocator_type()), _alloc_node(allocator_node()), _comp(key_compare())
        {
            _root = insertNode(NULL, v);
            _size = 1;
        };

        map(const map &x) : _alloc(x._alloc), _alloc_node(x._alloc_node), _comp(x._comp), _size(0)
        {
            _root = NULL;
            insert(x.begin(), x.end());
        };

        ~map()
        {
            if (_root)
                _delete_tree();
        };

        map &operator=(const map &x)
        {
            if (_root)
                _delete_tree();
            _alloc = x._alloc;
            _alloc_node = x._alloc_node;
            _comp = x._comp;
            _size = 0;
            insert(x.begin(), x.end());
            return *this;
        };
        // DEBUG
        void print_max()
        {
            nodePTR temp = _root;
            while (temp)
            {
                temp = temp->right;
            }
        };

        // ITERATORS
        iterator begin()
        {
            return iterator(min(_root));
        }

        iterator end()
        {
            nodePTR temp = max(_root);
            if (temp)
                temp->p = 1;
            return iterator(temp);
        }

        const_iterator begin() const
        {
            return const_iterator(min(_root));
        }

        const_iterator end() const
        {
            nodePTR temp = max(_root);
            if (temp)
                temp->p = 1;
            return const_iterator(temp);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }
        // Capacity
        bool empty() const
        {
            if (_size == 0)
                return true;
            return false;
        };

        size_type size() const
        {
            return (_size);
        };

        size_type max_size() const
        {
            return (_alloc_node.max_size());
        };
        // Element acess
        T &at(const Key &key)
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return temp->data.second;
            else
                throw std::out_of_range("No matching key");
        };

        const T &at(const Key &key) const
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return temp->data.second;
            else
                throw std::out_of_range("No matching key");
        };

        T &operator[](const Key &key)
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return temp->data.second;
            else
                return insert(ft::make_pair(key, T())).first->second;
        };
        // Modifiers
        ft::pair<iterator, bool> insert(const value_type &value)
        {
            if (_find(value) != NULL)
                return (ft::make_pair(iterator(_find(value)), false));
            _root = insertNode(_root, value);
            if (_root->parent)
                _root->parent = NULL;
            redaronade(_root);
            return (ft::make_pair(iterator(_find(value)), true));
        };

        template <class InputIt>
        void insert(InputIt first, InputIt last)
        {
            while (first != last)
            {
                insert((*first));
                first++;
            }
        };

        iterator insert(iterator hint, const value_type &value)
        {

            (void)hint;
            insert(value);
            return (_find(value));
        };

        size_type erase(const Key &key)
        {
            if (_find(key) == NULL)
            {
                return 0;
            }
            else
            {
                deleteNode(_find(key)->data);
                _size--;
                return 1;
            }
            redaronade(_root);
        };

        void erase(iterator pos)
        {
            value_type t = _find(pos->first)->data;
            erase(t.first);
            redaronade(_root);
        };

        void erase(iterator first, iterator last)
        {
            size_t x = 0;
            size_t t = ft::distance(first,last);
            value_type tab[t];
            value_type tempd;
            while (first != last)
            {
                tab[x] = _find(first->first)->data;
                first++;
                x++;
            }
            x = 0;
            while(x < t)
            {
                tempd = tab[x];
                deleteNode(tempd);
                x++;
            }
            _size = _size - t;
            redaronade(_root);
        };

        void swap(map &other)
        {
            map temp;
            temp._alloc = _alloc;
            temp._alloc_node = _alloc_node;
            temp._comp = _comp;
            temp._root = _root;
            temp._size = _size;

            _alloc = other._alloc;
            _alloc_node = other._alloc_node;
            _comp = other._comp;
            _root = other._root;
            _size = other._size;

            other._alloc = temp._alloc;
            other._alloc_node = temp._alloc_node;
            other._comp = temp._comp;
            other._root = temp._root;
            other._size = temp._size;
        };

        void clear()
        {
            if (_root)
                _delete_tree();
            _size = 0;
        };
        // Lookup
        size_type count(const Key &key) const
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return 1;
            else
                return 0;
        };

        iterator find(const Key &key)
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return iterator(temp);
            else
                return end();
        };

        const_iterator find(const Key &key) const
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return const_iterator(temp);
            else
                return end();
        };

        iterator lower_bound(const Key &key)
        {
            iterator temp = begin();
            while (temp != end() && temp->first < key)
            {
                temp++;
            }
            return temp;
        };

        const_iterator lower_bound(const Key &key) const
        {
            const_iterator temp = begin();
            while (temp != end() && temp->first < key)
            {
                temp++;
            }
            return temp;
        };

        iterator upper_bound(const Key &key)
        {
            iterator temp = begin();
            while ((temp != end()) && (temp->first <= key))
            {
                temp++;
            }
            return temp;
        };

        const_iterator upper_bound(const Key &key) const
        {
            const_iterator temp = begin();
            while (temp != end() && temp->first <= key)
            {
                temp++;
            }
            return temp;
        };

        ft::pair<iterator, iterator> equal_range(const Key &key)
        {
            return ft::make_pair(lower_bound(key), upper_bound(key));
        };

        ft::pair<const_iterator, const_iterator> equal_range(const Key &key) const
        {
            return ft::make_pair(lower_bound(key), upper_bound(key));
        };
        // Observers
        key_compare key_comp() const
        {
            return _comp;
        };
        value_compare value_comp() const
        {
            return value_compare();
        };
        // Operation
        // Allocator
        allocator_type get_allocator() const
        {
            return _alloc;
        };

    private:
        allocator_type _alloc;
        allocator_node _alloc_node;
        key_compare _comp;
        nodePTR _root;
        size_type _size;

        // TREE
        int max(int a, int b)
        {
            return (a > b) ? a : b;
        }

        int height(nodePTR N)
        {
            if (N == NULL)
                return 0;
            return N->height;
        };

        nodePTR _find(const Key &key) const
        {
            nodePTR temp;
            if (_root == NULL)
                return NULL;
            temp = _root;
            while (temp->data.first != key)
            {
                if (_comp(temp->data.first, key))
                {
                    if (temp->right)
                        temp = temp->right;
                    else
                        return NULL;
                }
                else
                {
                    if (temp->left)
                        temp = temp->left;
                    else
                        return NULL;
                }
            }
            return temp;
        };

        nodePTR _find(const value_type &v) const
        {
            nodePTR temp;
            if (_root == NULL)
                return NULL;
            temp = _root;
            while (temp->data.first != v.first)
            {
                if (_comp(temp->data.first, v.first))
                {
                    if (temp->right)
                        temp = temp->right;
                    else
                        return NULL;
                }
                else
                {
                    if (temp->left)
                        temp = temp->left;
                    else
                        return NULL;
                }
            }
            return temp;
        };

        void filiation(nodePTR N)
        {
            if (N == NULL)
                return;
            if (N->right)
                N->right->parent = N;
            if (N->left)
                N->left->parent = N;
        }
        nodePTR newNode(value_type v)
        {
            nodePTR node = _alloc_node.allocate(1);
            _alloc_node.construct(node, v);
            /*node->data = v;
            node->left = NULL;
            node->right = NULL;
            node->parent = NULL;
            node->height = 1;*/
            _size++;
            return (node);
        };
        nodePTR rightRotate(nodePTR y)
        {
            nodePTR x = y->left;
            nodePTR T2 = x->right;
            x->right = y;
            y->left = T2;
            y->height = max(height(y->left), height(y->right)) + 1;
            x->height = max(height(x->left), height(x->right)) + 1;
            return x;
        };
        nodePTR leftRotate(nodePTR x)
        {
            nodePTR y = x->right;
            nodePTR T2 = y->left;
            y->left = x;
            x->right = T2;
            x->parent = y;
            x->height = max(height(x->left), height(x->right)) + 1;
            y->height = max(height(y->left), height(y->right)) + 1;
            return y;
        };
        int getBalanceFactor(nodePTR N)
        {
            if (N == NULL)
                return 0;
            return height(N->left) - height(N->right);
        };
        nodePTR nodeWithMimumValue(nodePTR node)
        {
            nodePTR current = node;
            while (current->left != NULL)
                current = current->left;
            return current;
        }

        nodePTR insertNode(nodePTR node, value_type v)
        {
            // Find the correct postion and insert the node

            if (node == NULL)
                return (newNode(v));
            if (_comp(v.first, node->data.first))
                node->left = insertNode(node->left, v);
            else if (_comp(node->data.first, v.first))
                node->right = insertNode(node->right, v);
            else
                return node;
            node->height = 1 + max(height(node->left), height(node->right));
            filiation(node);
            int balanceFactor = getBalanceFactor(node);
            if (balanceFactor > 1)
            {
                if (_comp(v.first, node->left->data.first))
                {
                    return rightRotate(node);
                }
                else if (_comp(node->left->data.first, v.first))
                {
                    node->left = leftRotate(node->left);
                    return rightRotate(node);
                }
            }
            if (balanceFactor < -1)
            {
                if (_comp(node->right->data.first, v.first))
                {
                    return leftRotate(node);
                }
                else if (_comp(v.first, node->right->data.first))
                {
                    node->right = rightRotate(node->right);
                    return leftRotate(node);
                }
            }
            return node;
        };
        nodePTR _deleteNode(nodePTR root, value_type v)
        {
            // Find the node and delete it
            if (root == NULL)
                return root;
            if (_comp(v.first, root->data.first))
                root->left = _deleteNode(root->left, v);
            else if (_comp(root->data.first, v.first))
                root->right = _deleteNode(root->right, v);
            else
            {
                if ((root->left == NULL) || (root->right == NULL))
                {
                    nodePTR temp = root->left ? root->left : root->right;
                    if (temp == NULL)
                    {
                        temp = root;
                        root = NULL;
                    }
                    else
                        *root = *temp;
                    if (temp != NULL)
                        _alloc_node.destroy(temp);
                    _alloc_node.deallocate(temp, 1);
                }
                else
                {
                    nodePTR temp = nodeWithMimumValue(root->right);
                    root->data = temp->data;
                    root->right = _deleteNode(root->right, temp->data);
                }
            }
            if (root == NULL)
                return root;
            // Update the balance factor of each node and
            // balance the tree
            root->height = 1 + max(height(root->left), height(root->right));
            filiation(root);
            int balanceFactor = getBalanceFactor(root);
            if (balanceFactor > 1)
            {
                if (getBalanceFactor(root->left) >= 0)
                {
                    return rightRotate(root);
                }
                else
                {
                    root->left = leftRotate(root->left);
                    return rightRotate(root);
                }
            }
            if (balanceFactor < -1)
            {
                if (getBalanceFactor(root->right) <= 0)
                {
                    return leftRotate(root);
                }
                else
                {
                    root->right = rightRotate(root->right);
                    return leftRotate(root);
                }
            }
            return root;
        }
        void _delete_tree()
        {
            while (_root)
            {
                _root = _deleteNode(_root, min(_root)->data);
            }
        };

        nodePTR _new_node(nodePTR dad, value_type v)
        {
            nodePTR n_node;
            n_node = _alloc_node.allocate(1);
            n_node->parent = dad;
            n_node->data = v;
            n_node->height = 0;
            n_node->p = 0;
            n_node->right = NULL;
            n_node->left = NULL;
            return (n_node);
        };
        void deleteNode(value_type v)
        {
            _root = _deleteNode(_root, v);
            if (_root && _root->parent)
                _root->parent = NULL;
        }
        void redaronade(nodePTR a)
        {
            if (!a)
            {
                return;
            }
            if (a->left)
            {
                a->left->parent = a;
                redaronade(a->left);
            }
            if (a->right)
            {
                a->right->parent = a;
                redaronade(a->right);
            }
        }
        nodePTR max(nodePTR x) const
        {
            while (x && x->right)
            {
                x = x->right;
            }
            return (x);
        }
        nodePTR min(nodePTR x) const
        {
            while (x && x->left)
            {
                x = x->left;
            }
            return (x);
        }
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator==(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        if (lhs.size() != rhs.size())
            return false;
        typename ft::map<Key, T, Compare, Alloc>::const_iterator lhsit = lhs.begin();
        typename ft::map<Key, T, Compare, Alloc>::const_iterator rhsit = rhs.begin();
        while (lhsit != lhs.end())
        {
            if (*lhsit != *rhsit)
                return false;
            lhsit++;
            rhsit++;
        }
        return true;
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator!=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(lhs == rhs));
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator<(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator<=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(rhs < lhs));
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator>(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
    };

    template <class Key, class T, class Compare, class Alloc>
    bool operator>=(const ft::map<Key, T, Compare, Alloc> &lhs, const ft::map<Key, T, Compare, Alloc> &rhs)
    {
        return (!(lhs < rhs));
    };

    template <class Key, class T, class Compare, class Alloc>
    void swap(ft::map<Key, T, Compare, Alloc> &x, ft::map<Key, T, Compare, Alloc> &y)
    {
        x.swap(y);
    };
}

#endif