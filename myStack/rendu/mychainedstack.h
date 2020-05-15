/*
* @Author: Baptiste
* @Date:   2020-04-15 09:27:28
* @Last Modified by:   Baptiste
* @Last Modified time: 2020-04-15 09:34:31
*/

#ifndef MYCHAINEDSTACK_H_
# define MYCHAINEDSTACK_H_

#include <iostream>

#include "mystack.h"

typedef struct s_mystack
{
	int value;
	s_mystack *next;
} t_mystack;

class Mychainedstack : public Mystack
{
public:
	Mychainedstack();
	~Mychainedstack();

private:
	int _c;
	t_mystack *_my_stack;

public:
	void push(int number);
    int pop(void);
	int operator%(int mod) const;
	void clear();
	int getSize() const;

};

std::ostream& operator<<(std::ostream&, Mychainedstack const &);


#endif