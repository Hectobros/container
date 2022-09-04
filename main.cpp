#include <iostream>
#include "map4.hpp"
#include <map>
#include <utility>

int main()
{
    
    ft::map<int, int>b;
    std::cout << "Hi" << std::endl;
    for(int x = 0; x < 15000; x++)
        b.insert(ft::make_pair<int, int>(x, x*-1));
    b.deleteNode(ft::make_pair<int, int>(150,0));
    std::cout << "tout a marche " << std::endl;

    b.print_max();
}