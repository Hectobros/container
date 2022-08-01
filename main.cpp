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
        std::vector<int> w(5, 5);
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
        a.at(8) = 150;
        a[7] = 99;
        std::cout << "Capacity " << *b << std::endl;
        std::cout << "At 11:" << (a.at(8) + 12) << std::endl;
        std::cout << "At 0:" << a.at(0) << std::endl;
        std::cout << "[] 7 :" << a[7] << std::endl;
        std::cout << "[] 1: " << a[1] << std::endl;
        std::cout << "Front: " << a.front() << std::endl;
        std::cout << "Back: " << a.back() << std::endl;
        std::cout << "Data: " << *a.data() << std::endl;
        std::cout << "-------TchouTchou eraser-----" << std::endl;
        std::cout << "Erase "<< *a.erase(a.end() - 9) << std::endl;
        std::cout << "Size: " << a.size() << std::endl;
        std::cout << "Empty? " << (a.empty()) << std::endl;
        a.pop_back();
        a.pop_back();
        a.pop_back();
        a.pop_back();
        a.pop_back();
        a.swap(w);
        a.insert(a.begin() + 2, w.begin(), w.end());
        std::cout << "Mon vector contient: ";
        b = a.begin();
        for (std::vector<int>::iterator c = a.end(); b != c ; b++ )
            std::cout << *b << " " ;
        std::cout << std::endl;
        std::vector<int> p(6,6);
        std::vector<int> j(6,6);
        std::cout << "True :" << true << " False: " << false << std::endl;
        std::cout << "SAME?? " << (p == j) << std::endl;
        std::cout << "NOT SAME?? " << (p != j) << std::endl;
        std::cout << "INEFRIOR " << (p < j) << std::endl;
        std::cout << "INEFRIOR EGAL" << (p <= j) << std::endl;
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
        a.at(8) = 150;
        a[7] = 99;
        std::cout << "Capacity " << *b << std::endl;
        std::cout << "At 11 :" << a.at(8) << std::endl;
        std::cout << "At 0: " << a.at(0) << std::endl;
        std::cout << "[] 7 :" << a[7] << std::endl;
        std::cout << "[] 1: " << a[1] << std::endl;
        std::cout << "Front: " << a.front() << std::endl;
        std::cout << "Back: " << a.back() << std::endl;
        std::cout << "Data: " << *a.data() << std::endl;
        std::cout << "Size: " << a.size() << std::endl;
        std::cout << "Empty? " << (a.empty()) << std::endl;
        std::cout << "-------TchouTchou eraser-----" << std::endl;
        std::cout << "Erase "<< *a.erase(a.end() - 9) << std::endl;
        std::cout << "Size: " << a.size() << std::endl;
        std::cout << "Empty? " << (a.empty()) << std::endl;
        a.pop_back();
        a.pop_back();
        a.pop_back();
        a.pop_back();
        a.pop_back();
        a.swap(w);
        a.insert(a.begin() + 2, w.begin(), w.end());
        a.printvect();
        ft::vector<int>g(a.begin(),a.end());
        g.printvect();
        a = w;
        a.printvect();
        ft::vector<int> p(6,6);
        ft::vector<int> j(6,6);
        std::cout << "True :" << true << " False: " << false << std::endl;
        std::cout << "SAME?? " << (p == j) << std::endl;
        std::cout << "NOT SAME?? " << (p != j) << std::endl;
        std::cout << "INEFRIOR " << (p < j) << std::endl;
        std::cout << "INEFRIOR EGAL" << (p <= j) << std::endl;
    }
}