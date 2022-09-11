#include "./vector_utils/iterator_vector.hpp"
#include <iostream>

int main()
{
    {
        ft::pair<int, int>a(10, 150);
        ft::pair<int, int>b(1, 15);
        a = b;
        b.first = 888;
        std::cout << "hello world " << a.first << " " << a.second <<std::endl;
        std::cout << "A == B " << std::boolalpha << (a == b) << std::endl;
        std::cout << "A != B " << std::boolalpha << (a != b) << std::endl;
        std::cout << "A > B " << std::boolalpha << (a < b) << std::endl;
        std::cout << "B > A " << std::boolalpha << (b < a) << std::endl;
        std::cout << "A >= B " << std::boolalpha << (a <= b) << std::endl;
        std::cout << "B >= A " << std::boolalpha << (b <= a) << std::endl;  
        a = b;
        std::cout << "A == B " << std::boolalpha << (a == b) << std::endl;
        std::cout << "A != B " << std::boolalpha << (a != b) << std::endl;
        std::cout << "A > B " << std::boolalpha << (a < b) << std::endl;
        std::cout << "B > A " << std::boolalpha << (b < a) << std::endl;
        std::cout << "A >= B " << std::boolalpha << (a <= b) << std::endl;
        std::cout << "B >= A " << std::boolalpha << (b <= a) << std::endl;  
    }
    {
        std::cout << "TRUE VERSION" << std::endl;
        std::pair<int, int>a(10, 150);
        std::pair<int, int>b(1, 15);
        a = b;
        b.first = 888;
        std::cout << "hello world " << a.first << " " << a.second <<std::endl;
        std::cout << "A == B " << std::boolalpha << (a == b) << std::endl;
        std::cout << "A != B " << std::boolalpha << (a != b) << std::endl;
        std::cout << "A > B " << std::boolalpha << (a < b) << std::endl;
        std::cout << "B > A " << std::boolalpha << (b < a) << std::endl;
        std::cout << "A >= B " << std::boolalpha << (a <= b) << std::endl;
        std::cout << "B >= A " << std::boolalpha << (b <= a) << std::endl;  
        a = b;
        std::cout << "A == B " << std::boolalpha << (a == b) << std::endl;
        std::cout << "A != B " << std::boolalpha << (a != b) << std::endl;
        std::cout << "A > B " << std::boolalpha << (a < b) << std::endl;
        std::cout << "B > A " << std::boolalpha << (b < a) << std::endl;
        std::cout << "A >= B " << std::boolalpha << (a <= b) << std::endl;
        std::cout << "B >= A " << std::boolalpha << (b <= a) << std::endl;  
    }
}