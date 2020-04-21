
#include "OSSLMiner.h"

OSSLMiner::OSSLMiner()
{
	// _sizeNonce = 32;
	// this->init();
}

OSSLMiner::~OSSLMiner()
{
	
}

//a ne pas laisser comme ca
/*
int OSSLMiner::genRand()
{
	int v1 = rand() % 95;
	std::cout << "\x1B[43m\x1B[94mRandim number : " << "\x1B[0m\x1B[91m  " << std::hex << v1 << "\x1B[0m" << std::endl;
	return v1;	
}

int OSSLMiner::generateNonce()
{
	int randgenerated = 0;
	srand (time(NULL));
	for (int i = 0; i < _sizeNonce; i++)
	{
		randgenerated = genRand()+32;
		_nonce.push_back(randgenerated);
		_nonceStr.push_back(randgenerated);
	}
	return 0;
}
*/

/*
int OSSLMiner::init()
{
	int temp = 0;
	this->generateNonce();
	std::cout << "after generation : " << _nonceStr << std::endl;
	_nonceStr.pop_back();
	_nonceStr.push_back(genRand()+32);
	std::cout << "after generation : " << _nonceStr << std::endl;
	for (int i = 0; i < 10; i++)
	{
		temp = _nonceStr.back();
		_nonceStr.pop_back();
		_nonceStr.push_back(temp+1);
		if (temp > 126)
			temp = 32;
		std::cout << "after generation : " << _nonceStr << std::endl;
	}

	return 0;
}*/

void OSSLMiner::Mine(Token * to)
{
	unsigned char ibuf[] = "Hello";
	unsigned char *shaOne = NULL;

	shaOne = new unsigned char[60];

	std::cout << "au debut du miner : " << to->getToken() << std::endl;
	std::cout << "au debut du miner : " << to->getTokenUC() <<  "FIN" <<std::endl;
	//shaOne = SHA1(ibuf, (size_t)5, shaOne);
	shaOne = SHA1((unsigned char *)to->getTokenUC(), (size_t)60, shaOne);
	
	std::cout << "resultat du sha 1";

	for (int i = 0; i < 20; i++)
	{
		std::cout << std::hex << (int)shaOne[i];
	}

	//a boucler
	while (shaOne[0] != 99) 
	{
		to->updateToken();
		std::cout << "au milieux du miner : " << to->getTokenUC() <<  "FIN" <<std::endl;
		shaOne = SHA1((unsigned char *)to->getTokenUC(), (size_t)60, shaOne);
		for (int i = 0; i < 20; i++)
		{
			std::cout << std::hex << (int)shaOne[i];
		}
	}

	std::cout << std::endl;
}