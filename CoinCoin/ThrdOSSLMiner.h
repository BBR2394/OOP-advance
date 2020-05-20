
#ifndef THRDOSSMINER_H_
# define THRDOSSMINER_H_

#include "AMiner.h"
#include "Token.h"

class ThrdOSSLMiner : public AMiner
{
public:
	ThrdOSSLMiner();
	~ThrdOSSLMiner();


private:
	unsigned char* 	subcoin;
	int 			_id;

	void printCoin(int rank,  bool print, int minimumToPrint);

public:
	void Mine(Token *, const Option &);
	void BenchMiner(Token *);
};

#endif