/*
* @Author: Baptiste
* @Date:   2020-04-15 09:38:18
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-21 00:13:10
*/

#include "mychainedstack.h"

Mychainedstack::Mychainedstack() : _c(0), _my_stack(NULL)
{
}

Mychainedstack::~Mychainedstack() 
{
	clear();
}

//LIFO
void Mychainedstack::push(int number)
{
	t_mystack *temp = NULL;
	try {
		temp = new t_mystack;
	}
	catch (const std::bad_alloc& e) {
		std::cout << "error alloc" << std::endl;
	}
	if (temp != NULL) {
		temp->value = number;
		temp->next = _my_stack;
		_my_stack = temp;
		_c += 1;
	}
}

int Mychainedstack::pop(void)
{
	int tempNum = 0;
	t_mystack *temp = _my_stack;
	if (_my_stack == NULL)
		return -16380;
	tempNum = _my_stack->value;
	_my_stack = _my_stack->next;

	_c -= 1;
	delete temp;
	return tempNum;
}

int Mychainedstack::operator%(int mod) const
{
	int res = 0;
	if (_my_stack != NULL) {
		res = _c % mod;
	}
	if (res < 2)
		return -65530;
	return res;
}

int Mychainedstack::getSize() const
{
	return _c;
}

void Mychainedstack::clear()
{
	t_mystack *temp = NULL;
	while (_my_stack != NULL)
	{
		temp = _my_stack;
		_my_stack = _my_stack->next;
		delete temp;
		_c -= 1;
	}
}

std::ostream & operator<<(std::ostream & os, Mychainedstack const & stck)
{
	os << "\x1B[36mThere are in the stack : \x1B[0m\n";
	os << stck.getSize() << " elements";
	return os;
}