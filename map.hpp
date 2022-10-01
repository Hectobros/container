#ifndef MAP_HPP
#define MAP_HPP

#include "./utils/complements.hpp"
#include <functional>
#include "./iteratormap.hpp"
#include "./node.hpp"
#include "./utils/reverse_iterator.hpp"
namespace ft{

template < class Key, class T,class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
class map{
    public:
        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef ft::pair<key_type, mapped_type>             value_type;
        typedef Compare                                     key_compare;
        typedef Alloc                                       allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef Node<value_type>                   node;
        typedef node                                        *nodePTR;
        typedef typename allocator_type::template rebind<node>::other allocator_node;
        class value_compare : ft::binary_function<value_type, value_type, bool>
        {
        public:
            bool operator()(
                const value_type& left,
                const value_type& right) const
            {
                return (comp(left.first, right.first));
            }

        protected:
            value_compare(const key_compare& c) : comp (c) { }
            key_compare comp;
        };
        typedef typename ft::biterator<value_type>                    iterator;
        typedef typename ft::biterator<const value_type>              const_iterator;
        typedef typename ft::reverse_iterator<iterator>				  reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> 		  const_reverse_iterator;
        typedef std::ptrdiff_t                              difference_type;
        typedef std::size_t                                 size_type;
        
		//Constructor && Destructor
        explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :  _alloc(alloc) , _comp(comp) ,_size(0)
		{
            _root = NULL;
        };
        map(const value_type &v) : _alloc(allocator_type()), _alloc_node(allocator_node()) , _comp(key_compare()){
            _root = insertNode(NULL, v);
            _size = 1;
        };
        ~map()
        {
            if (_root)
                _delete_tree();
        };
		//DEBUG
        void    print_max()
        {
            nodePTR temp = _root;
            while(temp)
            {
                temp = temp->right;
            }
        };


		//ITERATORS
        iterator begin()
        {
            return iterator(min(_root), NULL, NULL);
        }

		iterator end()
        {
            return iterator(NULL, max(_root), NULL);
        }

		const_iterator begin() const
		{
            return const_iterator(min(_root), NULL, NULL);
		}

		const_iterator end() const
		{
            return const_iterator(NULL, max(_root), NULL);
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
		//Capacity
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
            return(_alloc_node.max_size());
        };
		//Element acess
        T& at( const Key& key )
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return temp->data.second;
            else
                throw std::out_of_range("No matching key");
        };

        const T& at( const Key& key ) const
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return temp->data.second;
            else
                throw std::out_of_range("No matching key");
        };

        T& operator[]( const Key& key )
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return temp->data.second;
            else
                return insert(ft::make_pair(key, T())).first->second;
        };
		//Modifiers
        void    insert(value_type v)
        {
            _root = insertNode(_root, v);
            if (_root->parent)
                _root->parent = NULL;
			redaronade(_root);
        };

        void clear()
        {
            if (_root)
                _delete_tree();
            _size = 0;
        };
        //Lookup
        size_type count( const Key& key ) const
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return 1;
            else
                return 0;
        };

        iterator find( const Key& key )
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return iterator(temp, NULL, NULL);
            else
                return end();
        };

        const_iterator find( const Key& key ) const
        {
            nodePTR temp;
            temp = _find(key);
            if (temp)
                return const_iterator(temp, NULL, NULL);
            else
                return end();
        };
		//Observers
        key_compare key_comp() const
        {
            return _comp;
        };
        value_compare value_comp() const
        {
            return value_compare();
        };
		//Operation
		//Allocator
		allocator_type get_allocator() const
		{
			return _alloc;
		};

    private:
        allocator_type      _alloc;
        allocator_node      _alloc_node;
        key_compare         _comp;  
        nodePTR            _root;
        size_type          _size;




        //TREE 
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

        nodePTR _find(const Key& key)
        {
            nodePTR temp;
            if (_root == NULL)
                return NULL;
            temp = _root;
            while(temp->data.first != key)
            {
                if (_comp(temp->data.first, key))
                {
                    if(temp->right)
                        temp = temp->right;
                    else
                        return NULL;
                }
                else
                {
                    if(temp->left)
                        temp = temp->left;
                    else
                        return NULL;
                }
            }
            return temp;
        }
        void filiation(nodePTR N)
        {
            if (N == NULL)
                return;
            if (N->right)
                N->right->parent = N;
            if (N->left)
                N->left->parent = N;        
        }
        nodePTR newNode(value_type v) {
            nodePTR node = _alloc_node.allocate(1);
            node->data = v;
            node->left = NULL;
            node->right = NULL;
            node->parent = NULL;
            node->height = 1;
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
        nodePTR leftRotate(nodePTR x) {
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
        nodePTR nodeWithMimumValue(nodePTR node) {
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
            if (_comp(v.first  , node->data.first))
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
                else if (_comp(v.first , node->right->data.first))
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
            if (_comp(v.first , root->data.first))
                root->left = _deleteNode(root->left, v);
            else if (_comp(root->data.first, v.first))
                root->right = _deleteNode(root->right, v);
            else 
            {
                _size--;
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
            if (balanceFactor > 1) {
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
            if (balanceFactor < -1) {
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
		void    _delete_tree()
        {
            while(_root)
            {
                _root = _deleteNode(_root, min(_root)->data);
            }
        };

        nodePTR    _new_node(nodePTR dad, value_type v)
        {
            nodePTR n_node;
            n_node = _alloc_node.allocate(1);
            n_node->parent = dad;
            n_node->data = v;
            n_node->height = 0;
            n_node->right = NULL;
            n_node->left = NULL;
            return (n_node);
        };
        void    deleteNode(value_type v)
        {
            _root = _deleteNode(_root, v);
            if (_root && _root->parent)
                _root->parent = NULL;
        }
		void	redaronade(nodePTR a)
		{
			if(a->left)
			{
				a->left->parent = a;
				redaronade(a->left);
			}
			if(a->right)
			{
				a->right->parent = a;
				redaronade(a->right);
			}
		}
		nodePTR max(nodePTR x) const
        {
            while(x && x->right)
            {
                x = x->right;
            }
            return (x);
        }
        nodePTR min(nodePTR x) const
        {
            while(x && x->left)
            {
                x = x->left;
            }
            return (x);
        }

    };
}

#endif