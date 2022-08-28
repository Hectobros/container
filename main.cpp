#include <iostream>
#include "map3.hpp"



int main()
{
    std::cout << "Hi" << std::endl;
    ft::map<int, int>b (ft::make_pair(-1,2));
    for (int x = 0; x < 1000 ;x++)
        b.insert(ft::make_pair(x,x * 10));
    b.print_max();
}