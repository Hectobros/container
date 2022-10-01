#include <iostream>
#include "map4.hpp"
#include <map>
#include <utility>

int main()
{
    {
		ft::map<int, int>b;
		std::cout << "Hi" << std::endl;
		for(int x = 0; x < 5; x++)
			b.insert(ft::pair<int, int>(x, x*-1));
		std::cout << "tout a marche " << std::endl;
		ft::map<int, int>::iterator f;
		ft::map<int, int>::const_iterator p;
		f = b.begin();
		p = b.cbegin();
		for(int x = 0; x < 2; x++)
		{
			std::cout << f->first << " " << p->first << std::endl;
			f++;
			p++;
		}
		f = b.end();
		p = b.cend();
		for(int x = 0; x < 2; x++)
		{
			f--;
			p--;
			std::cout << f->first << " " << p->first << std::endl;
		}
	}
	{
		std::map<int, int>b;
		std::cout << "Hi" << std::endl;
		for(int x = 0; x < 5; x++)
			b.insert(std::pair<int, int>(x, x*-1));
		std::cout << "tout a marche " << std::endl;
		std::map<int, int>::iterator f;
		std::map<int, int>::const_iterator p;
		f = b.begin();
		p = b.begin();
		for(int x = 0; x < 2; x++)
		{
			std::cout << f->first << " " << p->first << std::endl;
			f++;
			p++;
		}
		f = b.end();
		p = b.end();
		for(int x = 0; x < 2; x++)
		{
			f--;
			p--;
			std::cout << f->first << " " << p->first << std::endl;
		}
	}
	
	{
		std::map<int, int>b;
		std::cout << "Hi" << std::endl;
		for(int x = 0; x < 5; x++)
			b.insert(std::pair<int, int>(x, x*-1));
		std::cout << "tout a marche " << std::endl;
		std::map<int, int>::reverse_iterator f;
		std::map<int, int>::const_reverse_iterator p;
		f = b.rbegin();
		p = b.rbegin();
		for(int x = 0; x < 2; x++)
		{
			std::cout << f->first << " " << p->first << std::endl;
			f++;
			p++;
		}
		f = b.rend();
		p = b.rend();
		for(int x = 0; x < 2; x++)
		{
			f--;
			p--;
			std::cout << f->first << " " << p->first << std::endl;
		}
	}

	{
		ft::map<int, int>b;
		std::cout << "Hi" << std::endl;
		for(int x = 0; x < 5; x++)
			b.insert(ft::pair<int, int>(x, x*-1));
		std::cout << "tout a marche " << std::endl;
		ft::map<int, int>::reverse_iterator f;
		ft::map<int, int>::const_reverse_iterator p;
		f = b.rbegin();
		p = b.crbegin();
		for(int x = 0; x < 2; x++)
		{
			
			f++;
			p++;
			std::cout << f->first << " " << p->first << std::endl;
		}
		f = b.rend();
		p = b.crend();
		for(int x = 0; x < 2; x++)
		{
			std::cout << f->first << " " << p->first << std::endl;
			f--;
			p--;
		}
	}
}