#ifndef MYMINER_H_
# define MYMINER_H_

#include "AMiner.h"
#include "OSSLMiner.h"
#include "FakeMiner.h"
#include "Token.h"
#include "CheckOption.h"

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
	int mine(const CheckOption &);
	int getC() const;


};

#endif