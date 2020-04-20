
#include <iostream>
#include <stdlib.h>  
#include <time.h>

#include "mychainedstack.h"

int main()
{
	srand (time(NULL));
	int secret = rand();
	double c = 0;
	std::cout << "here is where the magik happen ! : "  << secret << "  " << rand() % 100 + 1 << "   " << time(NULL) << "rand = " << rand() << std::endl;

	Mychainedstack _mystack;

	_mystack.push(42);

	std::cout << "my stack fait:\n" << _mystack << std::endl;	

	std::cout << "operator %" << _mystack % 4 << std::endl;
	_mystack.push(42);
	std::cout << "operator %" << _mystack % 4 << std::endl;
	_mystack.push(42);
	std::cout << "operator %" << _mystack % 4 << std::endl;
	_mystack.push(42);
	std::cout << "operator %" << _mystack % 4 << std::endl;
	_mystack.push(42);
	std::cout << "operator %" << _mystack % 4 << std::endl;
	_mystack.push(42);
	std::cout << "operator %" << _mystack % 4 << std::endl;
	_mystack.push(42);
	std::cout << "operator %" << _mystack % 4 << std::endl;
	_mystack.push(42);
	std::cout << "operator %" << _mystack % 4 << std::endl;
	_mystack.push(42);

	_mystack.pop();

	std::cout << "my stack fait:\n" << _mystack << std::endl;	
	std::cout << "et si j'essaye de pop :" << _mystack.pop() << std::endl;
	while (c < 1000)
	{
		//_mystack.push(rand() % 100 + 1);
		_mystack.push(c);
		c++;
	}

	std::cout << "my stack fait:\n" << _mystack << std::endl;	
	std::cout << _mystack.pop() << std::endl;
	std::cout << _mystack.pop() << std::endl;
	std::cout << _mystack.pop() << std::endl;
	_mystack.push(42);
	_mystack.push(43);
	_mystack.push(44);
	_mystack.push(45);
	std::cout << _mystack.pop() << std::endl;
	std::cout << _mystack.pop() << std::endl;
	std::cout << _mystack.pop() << std::endl;

	while (c > 0)
	{
		_mystack.pop();
		c--;
	}
	_mystack.clear();
	std::cout << _mystack.pop() << std::endl;


	// while (c < 10000000)
	// {
	// 	_mystack.push(rand() % 100 + 1);
	// 	c++;
	// 	if (c == 1000000)
	// 		std::cout << "1 000 000 atteint" << std::endl;
	// 	if (c == 5000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 6000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 7000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 9000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 10000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 10000000)
	// 		std::cout << "1 000 000 atteint" << std::endl;
	// 	if (c == 50000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 60000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 70000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 90000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 100000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// }
	// std::cout << "my stack fait:\n" << _mystack << std::endl;	
	// while (c > 0)
	// {
	// 	_mystack.pop();
	// 	c--;
	// 	if (c == 1000000)
	// 		std::cout << "1 000 000 atteint" << std::endl;
	// 	if (c == 5000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 6000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 7000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 9000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 10000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 10000000)
	// 		std::cout << "1 000 000 atteint" << std::endl;
	// 	if (c == 50000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 60000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 70000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 90000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// 	if (c == 100000000)
	// 		std::cout << "5000000 atteint" << std::endl;
	// }

}