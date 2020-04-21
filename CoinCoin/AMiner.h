
#ifndef AMINER_H_
# define AMINER_H_

#include "Token.h"

class AMiner
{
public:
	virtual void Mine(Token *) = 0;	
};

#endif