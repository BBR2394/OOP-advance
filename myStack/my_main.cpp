
#include <iostream>
#include <stdlib.h>  
#include <time.h>

#include "mychainedstack.h"

int main()
{
	srand (time(NULL));
	int secret = rand();
	int c = 0;
	std::cout << "here is where the magik happen ! : "  << secret << "  " << rand() % 100 + 1 << "   " << time(NULL) << std::endl;

	Mychainedstack _mystack;

	_mystack.push(42);

	std::cout << "my stack fait:\n" << _mystack << std::endl;	

	std::cout << "operator %" << _mystack % 2 << std::endl;
	std::cout << "operator %" << _mystack % 3 << std::endl;
	std::cout << "operator %" << _mystack % 4 << std::endl;
	std::cout << "operator %" << _mystack % 5 << std::endl;
	std::cout << "operator %" << _mystack % 6 << std::endl;
	std::cout << "operator %" << _mystack % 7 << std::endl;
	std::cout << "operator %" << _mystack % 8 << std::endl;
	std::cout << "operator %" << _mystack % 9 << std::endl;

	_mystack.pop();

	std::cout << "my stack fait:\n" << _mystack << std::endl;	
	std::cout << "et si j'essaye de pop :" << _mystack.pop() << std::endl;
	while (c < 1000)
	{
		_mystack.push(rand() % 100 + 1);
		c++;
	}

	std::cout << "my stack fait:\n" << _mystack << std::endl;	

	while (c > 0)
	{
		_mystack.pop();
		c--;
	}

}