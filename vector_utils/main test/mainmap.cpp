#include "map.hpp"

int main()
{
    ft::node<int> a;
    ft::node<int>::iterator b;
    a.add_value(12);
    a.print_value();
    a.add(15);
    a.search(15);
    a.add(10);
    a.add(8);
    a.add(1);
    a.add(7);
    a.add(50);
    a.add(89);
    a.add(56);
    b = &a.min();
    a.max();
    b.print_value();
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    ++b;
    a.add(9999);
    b.print_value();
    --b;
    --b;
    --b;
    --b;
    --b;
    --b;
    --b;
    --b;
    std::cout << a.max().get_value() << std::endl;
    std::cout << a.min().get_value() << std::endl;
    return (0);
};