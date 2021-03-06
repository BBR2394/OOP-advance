
#ifndef OSSLMINER_H_
# define OSSLMINER_H_

#include <cstring>
#include <iostream>
#include <vector>
#include <openssl/sha.h>

#include "AMiner.h"
#include "SaveToken.hpp"

class OSSLMiner : public AMiner
{
public:
	OSSLMiner();
	~OSSLMiner();

private:
	// std::vector<unsigned char>	_nonce;
	// std::string					_nonceStr;
	// int 						_sizeNonce;

	// int generateNonce();
	SaveToken _saver;
	int init();
	int genRand();
	int isGoodCoin(unsigned char* subcoin, int rank,  bool print, int minimumToPrint);
	void printCoin(unsigned char* subcoin, int rank);
	void printBenchmark(int typeCoin, int elapsedTime) const;
	void printBenchmarkMoyenne(int, long*);
public:
	void Mine(Token *, const Option &);
	void BenchMiner(Token *);
};

#endif