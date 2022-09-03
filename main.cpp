#include <iostream>
#include "map3.hpp"



int main()
{
    std::cout << "Hi" << std::endl;
    ft::map<int, int>b (ft::make_pair(100,2));
    b.insert(ft::make_pair(50, -1));
    b.insert(ft::make_pair(75, -2));
    b.insert(ft::make_pair(150, 3));
    b.insert(ft::make_pair(125, 4));
    std::cout << "tout a marche " << std::endl;
    b.print_max();
}