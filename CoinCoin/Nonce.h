
#ifndef NONCE_H_
# define NONCE_H_

#include <string>
#include <vector>
#include <iostream>

class Nonce
{
public:
	Nonce();
	~Nonce();

private:
	std::vector<unsigned char>	_nonce;
	unsigned char				*_nonceUC;
	std::string					_nonceStr;
	int 						_sizeNonce;

	int genRand();
	int generate();

public:
	int genNonce();
	int updateNonce();
	std::string getNonce() const;
	unsigned char * getNonceUC();
};

#endif