#ifndef BITERATORMAP_HPP
#define BITERATORMAP_HPP
#include "node.hpp"
#include "./utils/iterator_traits.hpp"
#include "./utils/complements.hpp"

namespace ft
{
    template <typename T>
    class biterator
    {
        public:
        typedef typename ft::iterator_traits<T*>::value_type		value_type;
		typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
		typedef typename ft::iterator_traits<T*>::pointer			pointer;
		typedef typename ft::iterator_traits<T*>::reference			reference;
		typedef typename std::bidirectional_iterator_tag			iterator_category;

        biterator(Node<T> * n) : node(n)
        {
            if (node == NULL)
            {
                nplus = node;
                node = NULL;
                nmoins = NULL;
            }
            else
            {
                nmoins = NULL;
                nplus = NULL;
            }
        };
        //biterator( const_node_type * n, const_node_type * np,const_node_type * nm) : node(n), nplus(np), nmoins(nm) {};
        biterator() : node(NULL){};
		~biterator() 
		{
		};
         biterator(const biterator &rhs)
        {
            *this = rhs;
        };
        biterator& operator=(const biterator &rhs)
        {
            //rhs.print_value();
            node = rhs.node;
            nplus = rhs.nplus;
            nmoins = rhs.nmoins;
            return *this;
        };

        biterator& operator++()
        {
            if(node)
            {
                if (node->right)
                {
                    node = node->right;
                    while (node->left)
                    {
                        node = node->left;
                    }
                }
                else
                {
                    while (node->parent && node->parent->right == node)
                    {
                        node = node->parent;
                    }
                    if (node->parent ==  NULL)
                    {
                        while (node->right)
                        {
                            node = node->right;
                        }
                        nplus = node;
                        node = NULL;
                    }
                    else
                        node = node->parent;
                }
            }
            else if (nmoins)
            {
                node = nmoins;
                nmoins = NULL;
            }
            //print_value();
            return *this;
        };

		biterator operator++(int)
		{
			biterator temp = *this;
			operator++();
			return temp;
		};

        biterator& operator--()
        {
            if(node)
            {
				//presentezvous(node);
                if (node->left)
                {
                    node = node->left;
                    while (node->right)
                    {
                        node = node->right;
                    }
                }
                else
                {
                    while (node->parent && node->parent->left == node)
                    {
						//std::cout << "Je suis fils de gauche donc je suis rentré" << std::endl;
                        node = node->parent;
                    }
                    if (node->parent ==  NULL)
                    {
                        while (node->left)
                        {
                            node = node->left;
                        }
                        nmoins = node;
                        node = NULL;
                    }
                    else
                        node = node->parent;
                }
            }
            else if (nplus)
            {
                node = nplus;
                nplus = NULL;
            }
            //print_value();
            return *this;
        };

		biterator operator--(int)
		{
			biterator temp = *this;
			operator--();
			return temp;
		};

		reference	operator*()
		{
			return node->data;
		};

		pointer		operator->()
		{
			return (&(node->data));
		};

		bool		operator== (const biterator & rhs) const {
			return node == rhs.node;
		}
		bool		operator!= (const biterator & rhs) const {
			return node != rhs.node;
		}

/// débug
		void	presentezvous(T *n) const
		{
			if(n)
			{
				std::cout << "Je suis :" << n->data.first << std::endl;
				if (n->left)
					std::cout << "Mon enfant gauche est " << n->left->data.first << std::endl;
				else
					std::cout << "Je n'ai pas d'enfant à gauche "<< std::endl;
				if (n->right)
					std::cout << "Mon enfant droite est " << n->right->data.first << std::endl;
				else
					std::cout << "Je n'ai pas d'enfant à droite "<< std::endl;
				if (n->parent)
				{
					std::cout << "Mon enfant parent est " << n->parent->data.first << std::endl;
					if (n == n->parent->right)
						std::cout << "Je suis fils de droite" << std::endl;
					else
						std::cout << "Je suis fils de gauche" << std::endl;
				}
				else
					std::cout << "Je n'ai pas d'enfant à parent "<< std::endl;
			}
			else
			{
				std::cout << "Je n'existe pas" << std::endl;
			}
		};

        void print_value() const
        {
            if (node)
                std::cout << "Rank : " << node->data.first << std::endl;
        };
		protected:
            Node<T> * node;
            Node<T> * nplus;
            Node<T> * nmoins;
    };
};


#endif