#include "vector.hpp"
#include "iterator_vector.hpp"
#include "complements.hpp"
#include "iterator_traits.hpp"
#include <iterator>
#include <vector>
#include <list>

int main()
{
    ft::vector<int>a(10, 2);
    ft::vector<int>::iterator b = a.begin();
    std::cout << "Empty? " << (a.empty()) << std::endl;
    std::cout << "Size: " << a.size() << std::endl;
    std::cout << "Max_size " << a.max_size() << std::endl;
    std::cout << "Capacity " << a.capacity() << std::endl;
    b = a.insert(a.end() ,12);
    a.at(8) = 150;
    std::cout << "Capacity " << *b << std::endl;
    std::cout << "At 11:" << (a.at(8) + 12) << std::endl;
    std::cout << "At 0:" << a.at(0) << std::endl;
    std::cout << "[] 7 :" << a[7] << std::endl;
    std::cout << "[] 1: " << a[1] << std::endl;
    std::cout << "Front: " << a.front() << std::endl;
    std::cout << "Back: " << a.back() << std::endl;
    std::cout << "Data: " << *a.data() << std::endl;
    std::cout << "hey " << *(a.end() - 1) << std::endl;
    (void)b;
}