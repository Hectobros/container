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
        //typedef XXXX                                      value_compare;
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
            _root = _alloc_node.allocate(1);
            _root->data = v;
            _root->height = 0;
            _root->left = NULL;
            _root->right = NULL;
            _root->parent = NULL;
        }

        void    insert(const value_type &value)
        {
            insert(value, _root);
        }
        void    insert(const value_type &value, nodePTR t)
        {
            if (_comp(value.first, t->data.first))
            {
                if (t->left == NULL)
                {
                    
                    t->left = _alloc_node.allocate(1);
                    t->left->parent = t;
                    t->left->data = value;
                    t->left->height = 1;
                    t->left->right = NULL;
                    t->left->left = NULL;
                }
                else
                    insert(value, t->left);
            }
            else
            {
                if (t->right == NULL)
                {
                    t->right = _alloc_node.allocate(1);
                    t->right->parent = t;
                    t->right->data = value;
                    t->right->height = 1;
                    t->right->left = NULL;
                    t->right->right = NULL;
                }
                else
                    insert(value, t->right);
            }
        };
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
            if (t->right == NULL)
                std::cout << t->data.second << std::endl << "DAD : " << t->parent->data.second <<std::endl;
            else
                print_max(t->right);
        }
    private:
        allocator_type      _alloc;
        allocator_node      _alloc_node;
        key_compare         _comp;  
        nodePTR            _root;      
};
}