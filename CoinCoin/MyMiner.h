#ifndef MYMINER_H_
# define MYMINER_H_

#include "AMiner.h"
#include "OSSLMiner.h"
#include "FakeMiner.h"
#include "ThrdOSSLMiner.h"
#include "Token.h"
#include "CheckOption.h"
#include "Option.hpp"

class MyMiner
{
public:
	MyMiner();
	~MyMiner();

private:
	int _c;
	AMiner *_miner;
	Token *_tkn;
	Option _opt;
	void setOption(const CheckOption &);

public:
	int mine(const CheckOption &);
	int getC() const;


};

#endif