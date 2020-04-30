
#ifndef NONCE_H_
# define NONCE_H_

#include <string>
#include <vector>
#include <iostream>

#include "Time.h"

/*
note a moi meme
je fais de la merde quand je met a jour le nonce,
je met a jour seulement le _nonceUC
et pas le _nonceStr*/
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
	Time						_time;
	int genRand();
	int generate();

public:
	int genNonce();
	int updateNonce();
	std::string getNonce() const;
	unsigned char * getNonceUC();
};

#endif