#ifndef MYMINER_H_
# define MYMINER_H_

#include "AMiner.h"
#include "Token.h"

class MyMiner
{
public:
	MyMiner();
	~MyMiner();

private:
	int _c;
	AMiner *_miner;
	Token *_tkn;

public:
	int mine();
	int getC() const;


};

#endif