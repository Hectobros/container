#include <iostream>
#include "map3.hpp"
#include <map>
#include <utility>

int main()
/*{
    std::cout << "Hi" << std::endl;
    std::map<int, int>b;
    for(int x = 1; x < 100000; x++)
        b.insert(std::pair<int, int>(x, x*-1));
    std::cout << "tout a marche " << std::endl;
    //b.print_max();
}
*/
{
    std::cout << "Hi" << std::endl;
    ft::map<int, int>b (ft::make_pair(0,0));
    for(int x = 1; x < 100000; x++)
        b.insert(ft::make_pair(x, x*-1));
    std::cout << "tout a marche " << std::endl;
    b.print_max();
}