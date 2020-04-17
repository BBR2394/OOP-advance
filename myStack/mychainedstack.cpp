/*
* @Author: Baptiste
* @Date:   2020-04-15 09:38:18
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-17 14:45:59
*/

#include "mychainedstack.h"

Mychainedstack::Mychainedstack() : _my_stack(NULL), _c(0)
{
	std::cout << "Mychainedstack created" << std::endl;
}

Mychainedstack::~Mychainedstack() 
{
	std::cout << "dans le deconstructeur je free all" << std::endl;
	clear();

}

//LIFO
void Mychainedstack::push(int number)
{
	t_mystack *temp = new t_mystack;
	// std::cout << "dans push de Mychainedstack : " << "je vais ppush : " << number << std::endl;
	if (temp != NULL) {
		temp->value = number;

	// std::cout << "dans le maillon : " << temp->value << std::endl;

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
	// std::cout << "dans l'un des methode de Mychainedstack" << std::endl;
	tempNum = _my_stack->value;
	_my_stack = _my_stack->next;

	_c -= 1;
	delete temp;
	return tempNum;
}

int Mychainedstack::operator%(int mod) const
{
	int res = 0;
	std::cout << "dans l'un des methode de Mychainedstack" << std::endl;
	if (_my_stack != NULL) {
		res = _my_stack->value % mod;
	}
	std::cout << res << std::endl;
	return res;
}

int Mychainedstack::getSize() const
{
	return _c;
}

void Mychainedstack::clear()
{
	std::cout << "dans l'un des methode de Mychainedstack" << std::endl;
	t_mystack *temp = NULL;
	while (_my_stack != NULL)
	{
		temp = _my_stack;
		_my_stack = _my_stack->next;
		delete temp;
		_c -= 1;
	}
	std::cout << "c = " << _c << std::endl;
	std::cout << "i have cleared the stack" << std::endl;
}

std::ostream & operator<<(std::ostream & os, Mychainedstack const & stck)
{
	os << "\x1B[36mThere are in the stack : \x1B[0m\n";
	os << stck.getSize() << " elements";
	return os;
}