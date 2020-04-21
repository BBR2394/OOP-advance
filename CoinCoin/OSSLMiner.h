
#ifndef OSSLMINER_H_
# define OSSLMINER_H_

#include <vector>
#include <openssl/sha.h>

#include "AMiner.h"


class OSSLMiner : public AMiner
{
public:
	OSSLMiner();
	~OSSLMiner();

private:
	std::vector<unsigned char>	_nonce;
	std::string					_nonceStr;
	int 						_sizeNonce;

	int generateNonce();
	int init();
	int genRand();


public:
	void Mine(Token *);

};

#endif