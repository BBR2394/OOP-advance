/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-15 16:20:13
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-22 16:31:58
*/

#include "SaveToken.hpp"

SaveToken::SaveToken()
{
	
}



SaveToken::~SaveToken()
{
	
}

void SaveToken::printToken()
{
	std::list<Token*>::iterator it = _tknSaved.begin();
	std::cout << "dans save token" << std::endl;
	while (it != _tknSaved.end())
	{
		std::cout << *(*it) << std::endl;
		std::cout << *(*it)->getResultCoin() << std::endl;
		it++;
	}
}

int SaveToken::addToken(Token *to, unsigned char *coin)
{
	Token *tmp = new Token(*to);
	tmp->addResult((char*)coin);
	_tknSaved.push_back(tmp);
	return 0;
}