
#ifndef AMINER_H_
# define AMINER_H_

#include "Token.h"
#include "Option.hpp"

class AMiner
{
public:
	virtual void Mine(Token *, const Option &) = 0;
	virtual void BenchMiner(Token *) = 0;
};

#endif