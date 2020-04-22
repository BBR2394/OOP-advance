
#include "Nonce.h"

Nonce::Nonce()
{
	_sizeNonce = 32;
	_nonceUC = new unsigned char[32];
	srand (time(NULL));
}

Nonce::~Nonce()
{

}

//a ne pas laisser comme ca
int Nonce::genRand()
{
	int v1 = rand() % 95;
	// std::cout << "\x1B[43m\x1B[94mRandim number : " << "\x1B[0m\x1B[91m  " << std::hex << v1 << "\x1B[0m" << std::endl;
	return v1;	
}

int Nonce::generate()
{
	int randgenerated = 0;
	
	for (int i = 0; i < _sizeNonce; i++)
	{
		randgenerated = genRand()+32;
		_nonceUC[i] = (unsigned char)randgenerated;
		_nonce.push_back(randgenerated);
		_nonceStr.push_back(randgenerated);
	}
	// std::cout << "Apres la generation " << _nonceStr << std::endl;
	// for (int i = 0; i < _sizeNonce; i++)
	// {
	// 	std::cout << "un char : " << (char)_nonceUC[i] << std::endl;
	// }
	return 0;
}

std::string Nonce::getNonce() const
{
	// std::cout << "dans get nonce" << _nonceStr << std::endl;
	return _nonceStr;
}

unsigned char * Nonce::getNonceUC() 
{
	//std::cout << "dans get nonce" << _nonceStr << std::endl;
	return _nonceUC;
}

int Nonce::updateNonce()
{
	int randgenerated = 0;
	srand (time(NULL));
	for (int i = 0; i < _sizeNonce; i++)
	{
		randgenerated = genRand()+32;
		_nonceUC[i] = (unsigned char)randgenerated;
	}
	return 0;
}

int Nonce::genNonce()
{
	this->generate();
	return 0;
}