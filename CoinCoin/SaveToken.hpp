#ifndef SAVETOKEN_HPP_
# define SAVETOKEN_HPP_

#include <list>
#include "Token.h"

class SaveToken
{
public:
	SaveToken();
	~SaveToken();

private:
	std::list<Token*> _tknSaved;

public:
	int addToken(Token *to, unsigned char *coin);
	void printToken();

};

#endif