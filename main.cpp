#include "vector.hpp"
#include "iterator_vector.hpp"
#include "complements.hpp"
#include "iterator_traits.hpp"
#include <iterator>
#include <vector>
#include <list>

int main()
{   /*std::cout << "ITERATORS TESTERS" << std::endl;
    {
        std::cout << "ft::vector: " << std::endl;
        ft::vector<int> a(15, 2);
        a.printvect();
        ft::vector<int>::iterator g;
        ft::vector<int>::iterator d;
        g = a.begin();
        d = a.end();
        std::cout << "Test Iterators Operators" << std::endl;
        std::cout << "True = " << true << " False = " << false << std::endl;
        std::cout << "iterator - iterator: "<< a.begin() - a.end() << std::endl;
        std::cout << "It != It " << (g!=d) << std::endl;
        std::cout << "It == It " << (g==d) << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "++g " << *(++g) << std::endl;
        std::cout << "g++ " << *(g++) << std::endl;
        std::cout << "*g++ " << *g++ << std::endl;
        std::cout << "--g " << *(--g) << std::endl;
        std::cout << "g-- " << *(g--) << std::endl;
        std::cout << "*g-- " << *g-- << std::endl;
        std::cout << "2 + g " << *(2+g) << std::endl;
        std::cout << "g + 2 " << *(g+2) << std::endl;
        g = g + 4;
        std::cout << "g - 2 " << *(g - 2) << std::endl;
        std::cout << "g += 2 " << *(g+=2) << std::endl;
        std::cout << "g -= 2 " << *(g -= 2) << std::endl;
        std::cout << "g < d " << (g< d) << std::endl;
        std::cout << "g <= d " << (g<= d) << std::endl;
        std::cout << "g > d " << (g> d) << std::endl;
        std::cout << "g >= d " << (g>= d) << std::endl;
    }
    {
        ft::vector<int> a(15, 2);
        a.printvect();
        ft::vector<int>::const_iterator g(a.begin());
        ft::vector<int>::const_iterator d(a.end());
        std::cout << "Test CONST Iterators Operators" << std::endl;
        std::cout << "True = " << true << " False = " << false << std::endl;
        std::cout << "iterator - iterator: "<< a.begin() - a.end() << std::endl;
        std::cout << "It != It " << (g!=d) << std::endl;
        std::cout << "It == It " << (g==d) << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "++g " << *(++g) << std::endl;
        std::cout << "g++ " << *(g++) << std::endl;
        std::cout << "*g++ " << *g++ << std::endl;
        std::cout << "--g " << *(--g) << std::endl;
        std::cout << "g-- " << *(g--) << std::endl;
        std::cout << "*g-- " << *g-- << std::endl;
        std::cout << "2 + g " << *(2+g) << std::endl;
        std::cout << "g + 2 " << *(g+2) << std::endl;
        g = g + 4;
        std::cout << "g - 2 " << *(g - 2) << std::endl;
        std::cout << "g += 2 " << *(g+=2) << std::endl;
        std::cout << "g -= 2 " << *(g -= 2) << std::endl;
        std::cout << "g < d " << (g< d) << std::endl;
        std::cout << "g <= d " << (g<= d) << std::endl;
        std::cout << "g > d " << (g> d) << std::endl;
        std::cout << "g >= d " << (g>= d) << std::endl;
        
        //std::cout << "begin - end" << (a.begin() - a.end()) << std::endl;
    }
    {
        ft::vector<int> a(15, 2);
        a.printvect();
        ft::vector<int>::reverse_iterator d(a.rend());
        ft::vector<int>::reverse_iterator g(a.rbegin());
        std::cout << "Test Reverse Iterators Operators" << std::endl;
        std::cout << "True = " << true << " False = " << false << std::endl;
        std::cout << "iterator - iterator: "<< a.begin() - a.end() << std::endl;
        std::cout << "It != It " << (g!=d) << std::endl;
        std::cout << "It == It " << (g==d) << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "++g " << *(++g) << std::endl;
        std::cout << "g++ " << *(g++) << std::endl;
        std::cout << "*g++ " << *g++ << std::endl;
        std::cout << "--g " << *(--g) << std::endl;
        std::cout << "g-- " << *(g--) << std::endl;
        std::cout << "*g-- " << *g-- << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "2 + g " << *(2+g) << std::endl;
        std::cout << "g + 2 " << *(g+2) << std::endl;
        g = g + 4;
        std::cout << "g - 2 " << *(g - 2) << std::endl;
        std::cout << "g += 2 " << *(g+=2) << std::endl;
        std::cout << "g -= 2 " << *(g -= 2) << std::endl;
        std::cout << "g < d " << (g< d) << std::endl;
        std::cout << "g <= d " << (g<= d) << std::endl;
        std::cout << "g > d " << (g> d) << std::endl;
        std::cout << "g >= d " << (g>= d) << std::endl;
        
        //std::cout << "begin - end" << (a.begin() - a.end()) << std::endl;
    }
    {
        ft::vector<int> a(15, 2);
        a.printvect();
        ft::vector<int>::const_reverse_iterator d(a.rend());
        ft::vector<int>::const_reverse_iterator g(a.rbegin());
        std::cout << "Test Reverse Iterators Operators" << std::endl;
        std::cout << "True = " << true << " False = " << false << std::endl;
        std::cout << "iterator - iterator: "<< a.begin() - a.end() << std::endl;
        std::cout << "It != It " << (g!=d) << std::endl;
        std::cout << "It == It " << (g==d) << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "++g " << *(++g) << std::endl;
        std::cout << "g++ " << *(g++) << std::endl;
        std::cout << "*g++ " << *g++ << std::endl;
        std::cout << "--g " << *(--g) << std::endl;
        std::cout << "g-- " << *(g--) << std::endl;
        std::cout << "*g-- " << *g-- << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "2 + g " << *(2+g) << std::endl;
        std::cout << "g + 2 " << *(g+2) << std::endl;
        g = g + 4;
        std::cout << "g - 2 " << *(g - 2) << std::endl;
        std::cout << "g += 2 " << *(g+=2) << std::endl;
        std::cout << "g -= 2 " << *(g -= 2) << std::endl;
        std::cout << "g < d " << (g< d) << std::endl;
        std::cout << "g <= d " << (g<= d) << std::endl;
        std::cout << "g > d " << (g> d) << std::endl;
        std::cout << "g >= d " << (g>= d) << std::endl;
        
        //std::cout << "begin - end" << (a.begin() - a.end()) << std::endl;
    }
    {
        std::cout << "std::vector:" << std::endl;
        std::vector<int>a;
        std::vector<int>::iterator g;
        std::vector<int>::iterator d;
        int x = 2;
        while (x < 17)
        {
            a.push_back(x);
            x++;
        }
        g = a.begin();
        d = a.end();
        std::cout << "Mon vect contient " << std::endl;
        while (g != d)
        {
            std::cout << *g << " ";
            g++; 
        }
        g = a.begin();
        std::cout <<std::endl;
        std::cout << "Test Iterators Operators" << std::endl;
        std::cout << "True = " << true << " False = " << false << std::endl;
        std::cout << "iterator - iterator: "<< a.begin() - a.end() << std::endl;
        std::cout << "It != It " << (g!=d) << std::endl;
        std::cout << "It == It " << (g==d) << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "++g " << *(++g) << std::endl;
        std::cout << "g++ " << *(g++) << std::endl;
        std::cout << "*g++ " << *g++ << std::endl;
        std::cout << "--g " << *(--g) << std::endl;
        std::cout << "g-- " << *(g--) << std::endl;
        std::cout << "*g-- " << *g-- << std::endl;
        std::cout << "2 + g " << *(2+g) << std::endl;
        std::cout << "g + 2 " << *(g+2) << std::endl;
        g = g + 4;
        std::cout << "g - 2 " << *(g - 2) << std::endl;
        std::cout << "g += 2 " << *(g+=2) << std::endl;
        std::cout << "g -= 2 " << *(g -= 2) << std::endl;
        std::cout << "g < d " << (g< d) << std::endl;
        std::cout << "g <= d " << (g<= d) << std::endl;
        std::cout << "g > d " << (g> d) << std::endl;
        std::cout << "g >= d " << (g>= d) << std::endl;
        
    }
    {
        std::cout << "std::vector:" << std::endl;
        std::vector<int>a;
        std::vector<int>::iterator p;
        std::vector<int>::iterator o;
        int x = 2;
        while (x < 17)
        {
            a.push_back(x);
            x++;
        }
        p = a.begin();
        o = a.end();
        std::cout << "Mon vect contient " << std::endl;
        while (p != o)
        {
            std::cout << *p << " ";
            p++; 
        }
        std::vector<int>::reverse_iterator d(a.rend());
        std::vector<int>::reverse_iterator g(a.rbegin());
        std::cout << "Test Reverse Vect Iterators Operators" << std::endl;
        std::cout << "True = " << true << " False = " << false << std::endl;
        std::cout << "iterator - iterator: "<< a.begin() - a.end() << std::endl;
        std::cout << "It != It " << (g!=d) << std::endl;
        std::cout << "It == It " << (g==d) << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "++g " << *(++g) << std::endl;
        std::cout << "g++ " << *(g++) << std::endl;
        std::cout << "*g++ " << *g++ << std::endl;
        std::cout << "--g " << *(--g) << std::endl;
        std::cout << "g-- " << *(g--) << std::endl;
        std::cout << "*g-- " << *g-- << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "2 + g " << *(2+g) << std::endl;
        std::cout << "g + 2 " << *(g+2) << std::endl;
        g = g + 4;
        std::cout << "g - 2 " << *(g - 2) << std::endl;
        std::cout << "g += 2 " << *(g+=2) << std::endl;
        std::cout << "g -= 2 " << *(g -= 2) << std::endl;
        std::cout << "g < d " << (g< d) << std::endl;
        std::cout << "g <= d " << (g<= d) << std::endl;
        std::cout << "g > d " << (g> d) << std::endl;
        std::cout << "g >= d " << (g>= d) << std::endl;
        
        //std::cout << "begin - end" << (a.begin() - a.end()) << std::endl;
    }
    {
        std::cout << "std::vector:" << std::endl;
        std::vector<int>a;
        std::vector<int>::iterator p;
        std::vector<int>::iterator o;
        int x = 2;
        while (x < 17)
        {
            a.push_back(x);
            x++;
        }
        p = a.begin();
        o = a.end();
        std::cout << "Mon vect contient " << std::endl;
        while (p != o)
        {
            std::cout << *p << " ";
            p++; 
        }
        std::vector<int>::const_reverse_iterator d(a.rend());
        std::vector<int>::const_reverse_iterator g(a.rbegin());
        std::cout << "Test Reverse Vect Iterators Operators" << std::endl;
        std::cout << "True = " << true << " False = " << false << std::endl;
        std::cout << "iterator - iterator: "<< a.begin() - a.end() << std::endl;
        std::cout << "It != It " << (g!=d) << std::endl;
        std::cout << "It == It " << (g==d) << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "++g " << *(++g) << std::endl;
        std::cout << "g++ " << *(g++) << std::endl;
        std::cout << "*g++ " << *g++ << std::endl;
        std::cout << "--g " << *(--g) << std::endl;
        std::cout << "g-- " << *(g--) << std::endl;
        std::cout << "*g-- " << *g-- << std::endl;
        std::cout << "*It " << *g << std::endl;
        std::cout << "2 + g " << *(2+g) << std::endl;
        std::cout << "g + 2 " << *(g+2) << std::endl;
        g = g + 4;
        std::cout << "g - 2 " << *(g - 2) << std::endl;
        std::cout << "g += 2 " << *(g+=2) << std::endl;
        std::cout << "g -= 2 " << *(g -= 2) << std::endl;
        std::cout << "g < d " << (g< d) << std::endl;
        std::cout << "g <= d " << (g<= d) << std::endl;
        std::cout << "g > d " << (g> d) << std::endl;
        std::cout << "g >= d " << (g>= d) << std::endl;
        
        //std::cout << "begin - end" << (a.begin() - a.end()) << std::endl;
    }*/
    std::cout << "Capacity tester"<< std::endl;
    {
        std::cout << "----------REAL VECTOR-------------"<< std::endl;
        std::vector<int> a(10, 2);
        std::vector<int>::iterator b;
        b = a.begin();
        std::cout << "Mon vector contient: ";
        for (std::vector<int>::iterator c = a.end(); b != c ; b++ )
            std::cout << *b << " " ;
        std::cout << std::endl;
        std::cout << "Empty? " << (a.empty()) << std::endl;
        std::cout << "Size: " << a.size() << std::endl;
        std::cout << "Max_size " << a.max_size() << std::endl;
        std::cout << "Capacity " << a.capacity() << std::endl;
        std::cout << "Capacity " << a.capacity() << std::endl;
        b = a.insert(a.end() ,12);
        std::cout << "Capacity " << *b << std::endl;
        std::cout << "Mon vector contient: ";
        b = a.begin();
        for (std::vector<int>::iterator c = a.end(); b != c ; b++ )
            std::cout << *b << " " ;
        std::cout << std::endl;
    }
    {
        std::cout << "----------FT VECTOR-------------"<< std::endl;
        ft::vector<int> a(10, 2);
        ft::vector<int> w(5, 5);
        ft::vector<int>::iterator b;
        a.printvect();
        std::cout << "Empty? " << (a.empty()) << std::endl;
        std::cout << "Size: " << a.size() << std::endl;
        std::cout << "Max_size " << a.max_size() << std::endl;
        std::cout << "Capacity " << a.capacity() << std::endl;
        std::cout << "Capacity " << a.capacity() << std::endl;
        b = a.insert(a.end() ,12);
        std::cout << "Capacity " << *b << std::endl;
        a.insert(a.begin(), w.begin(), w.end());
        a.printvect();
    }
}