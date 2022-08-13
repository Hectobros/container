#include "complements.hpp"
#include <vector>
#include <type_traits>
#include <new>
#include <iostream>
#include <string>
///-std=c++98
template<typename T,  std::enable_if_t<!std::is_integral<T>::value, bool> = true >
void    foo(T x)
{
    (void)x;
    std::cout << "hello world" << std::endl;
}

template<class T>
void    foo(int x)
{
    (void)x;
    T y = 0;
    y++;
    std::cout << "Absolute DARKNESS" << std::endl;
};

int main()
{
    std::vector<int> a(15,2);
    foo(2);
    return 0;
}