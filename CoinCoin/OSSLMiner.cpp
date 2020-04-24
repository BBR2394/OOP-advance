
#include <unistd.h>

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

// void OSSLMiner::Mine(Token * to)
// {
// 	unsigned char ibuf[] = "Hell\0";
// 	unsigned char *shaOne = NULL;

// 	shaOne = new unsigned char[60];

// 	std::cout << "au debut du miner : " << to->getToken() << std::endl;
// 	std::cout << "au debut du miner : " << to->getTokenUC() <<  "FIN" <<std::endl;
// 	shaOne = SHA1(ibuf, (size_t)4, shaOne);
// 	// shaOne = SHA1((unsigned char *)to->getTokenUC(), (size_t)60, shaOne);
	
// 	std::cout << "resultat du sha 1";

// 	for (int i = 0; i < 20; i++)
// 	{
// 		std::cout << std::hex << (int)shaOne[i];
// 	}

// 	//a boucler
// 	// while (shaOne[0] != 99) 
// 	// {
// 	// 	usleep(1000000);
// 	// 	to->updateToken();
// 	// 	std::cout << "au milieux du miner : " << to->getTokenUC() <<  "FIN" <<std::endl;
// 	// 	shaOne = SHA1((unsigned char *)to->getTokenUC(), (size_t)60, shaOne);
// 	// 	for (int i = 0; i < 20; i++)
// 	// 	{
// 	// 		std::cout << std::hex << (int)shaOne[i];
// 	// 		// std::cout << std::hex << (char)shaOne[i];
// 	// 	}
// 	// 	std::cout << std::endl;
// 	// }

// 	std::cout << std::endl;
// }

void OSSLMiner::Mine(Token * to)
{
	unsigned char ibuf[] = "Hell";
	unsigned char *shaOne = NULL;
	unsigned char *shaBogdan = NULL;
	unsigned char bogdanCoin[] = "i%u@>^J;\%-k5T|v,w1Tp7=,=e|~`>a!-BCO-CC1.0-1587572545-0f0f0f";
	char *basic_str = NULL;

	shaOne = new unsigned char[20];
	basic_str = new char[20];

	std::cout << "bogdan token : " << std::endl;
	for (int i = 0; i < 59; i++)
	{
		std::cout << std::hex << (int)bogdanCoin[i];
		std::cout << '-';
	}
	std::cout << std::endl;

	shaOne = SHA1(ibuf, (size_t)4, shaOne);
	shaBogdan = SHA1(bogdanCoin, (size_t)60, shaBogdan);

	std::cout << "resultat du sha 1:\n->";

	for (int i = 0; i < 20; i++)
	{
		std::cout << std::hex << (int)shaOne[i];
		std::cout << '-';
	}
	std::cout << std::endl;

	std::strcpy (basic_str, (char*)shaBogdan);

	std::cout << "resultat du bogdan coin sh 1:\n->";

	for (int i = 0; i < 20; i++)
	{
		std::cout  << (int)shaBogdan[i];
		//std::cout  << (int)basic_str[i];
		std::cout << '-';
	}
	std::cout << std::endl;

}