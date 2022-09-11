#include "./utils/complements.hpp"
#include <functional>

namespace ft{

template <class T>
class Node {
    public:
    T data;
    Node *parent;
    Node *left;
    Node *right;
    int height;
};

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
        /*typedef XXXX  iterator;
        typedef XXX     const_iterator;
        typedef XXX     reverse_iterator;
        typedef XXX     const_reverse_iterator*/
        typedef std::ptrdiff_t                              difference_type;
        typedef std::size_t                                 size_type;
        
        map() : _alloc(allocator_type()), _alloc_node(allocator_node()){
            std::cout << "HEY DON T USE THAT" << std::endl;
        }
        map(const value_type &v) : _alloc(allocator_type()), _alloc_node(allocator_node()) , _comp(key_compare()){
            _root = _new_node(NULL, v);
        }

        ~map()
        {
            _delete_tree();
        }
        void    insert(const value_type &value)
        {
            if (_root)
                insert(value, _root);
            else
                _root = _new_node(NULL, value);
        }

        void    insert(const value_type &value, nodePTR t)
        {
            if (_comp(value.first, t->data.first))
            {
                if (t->left == NULL)
                {
                    
                    t->left = _new_node(t, value);
                    _adjust(t->left);
                    _rebalance(t->left);
                }
                else
                    insert(value, t->left);
            }
            else
            {
                if (t->right == NULL)
                {
                    t->right = _new_node(t, value);
                    _adjust(t->right);
                    _rebalance(t->right);
                }
                else
                    insert(value, t->right);
            }
        };

        //debug
        void    print_less()
        {
            print_less(_root);
        }
        void    print_less(const nodePTR t)
        {
            if (t->left == NULL)
                std::cout << t->data.second << std::endl;
            else
                print_less(t->left);
        }
        void    print_max()
        {
            print_max(_root);
        }
        void    print_max(const nodePTR t)
        {
            if (!t->right)
            {
                std::cout << "ROOT: " << _root->height << std::endl;
                std::cout << t->data.second << std::endl;
            }
            else
            {
                std::cout << t->data.first << std::endl;
                print_max(t->right);
            }
        }
        //getmin
        nodePTR _get_min(nodePTR p)
        {
            if (!p->left && !p->right)
                return p;
            else if (!p->left && p->right)
                return(_get_min(p->right));
            else
                return(_get_min(p->left));
        }
        nodePTR _get_max(nodePTR p)
        {
            if (!p->left && !p->right)
                return p;
            else if (p->left && !p->right)
                return(_get_max(p->left));
            else
                return(_get_max(p->right));
        }
        void    _delete_tree()
        {
            while(_root)
            {
                _de
            }
        }

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

        void    _left_rotate(nodePTR x)
        {
            std::cout << "Left rotate value" << x->data.first << std::endl;
            nodePTR y = x->right;
            if (y->left)
                x->right = y->left;
            else
                x->right = NULL;
            if (!x->parent)
            {
                std::cout << "3" << std::endl;
                _root = y;
            }
            else if (x->parent->right == x)
            {
                std::cout << "1" << std::endl;
                x->parent->right = y;
            }
            else
            {
                std::cout << "2" << std::endl;
                x->parent->left = y;
            }
            y->parent = x->parent;
            x->parent = y;
            y->left = x;
            if (y == _root)
                y->parent = NULL;
        };

        void    _right_rotate(nodePTR x)
        {
            nodePTR y = x->left;
            if (y->right)
                x->left = y->right;
            else
                x->left = NULL;
            if (!x->parent)
                _root = y;
            else if (x->parent->right == x)
                x->parent->right = y;
            else
                x->parent->left = y;
            y->parent = x->parent;
            x->parent = y;
            y->right = x;
            if (y == _root)
                y->parent = NULL;
            x->height = 
        };

        void _left_right(nodePTR x)
        {
            nodePTR dad;
            dad = x->parent;
            _left_rotate(x);
            _right_rotate(dad);
        };
        void _right_left(nodePTR x)
        {
            nodePTR dad;
            dad = x->parent;
            _right_rotate(x);
            _left_rotate(dad);
        };
        void    _rebalance(nodePTR x)
        {
            nodePTR papy;

            if (x->parent && x->parent->parent)
            {
                std::cout << "x value:" <<x->data.first << std::endl;
                papy = x->parent->parent;
                std::cout << "papy : " <<papy->height << "papy value : " <<papy->data.first<< std::endl;
                if (papy->height > 1)
                {
                    std::cout << "in supp out" << papy->left->data.first<< std::endl;
                    if (_comp(x->data.first , papy->left->data.first))
                        _right_rotate(papy);
                    else
                        _left_right(x->parent);
                    _counter_adjust(papy->parent);
                }
                else if (papy->height < -1)
                {
                    std::cout << "in under out" << std::endl;
                    if(_comp(papy->right->data.first, x->data.first))
                    {
                        _left_rotate(papy);
                        std::cout << "left rotate" << std::endl;
                    }
                    else
                        _right_left(x->parent);
                    _counter_adjust(papy->parent);
                }
                _rebalance(x->parent);
            }
            std::cout <<  "hello" << std::endl;
            return;
        };

        void    _counter_adjust(nodePTR t)
        {
            if(t->parent)
            {
                if(t->parent->left == t)
                    t->parent->height --;
                else if(t->parent->right == t)
                    t->parent->height ++;
                _counter_adjust(t->parent);
            }
            return;
        };

        void    _adjust(nodePTR t)
        {
            if(t->parent)
            {
                if(t->parent->left == t)
                    t->parent->height ++;
                else if(t->parent->right == t)
                    t->parent->height --;
                _adjust(t->parent);
            }
            return;
        }

    private:
        allocator_type      _alloc;
        allocator_node      _alloc_node;
        key_compare         _comp;  
        nodePTR            _root;      
};
}