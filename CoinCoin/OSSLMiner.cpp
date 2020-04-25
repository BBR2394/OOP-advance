
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

int OSSLMiner::isGoodCoin(unsigned char* subcoin, int rank)
{
	if (subcoin[0] == 204){
		if (subcoin[1] == 204){
			if (subcoin[2] == 204) {
				if (subcoin[3] == 204){
					if (subcoin[4] == 204) {
						if (subcoin[5] == 204)
						{
							//12
							std::cout << "\x1B[106m\x1B[35m\x1B[5mUn 12 c !\x1B[0m";
							this->printCoin(subcoin, rank);
							return 12;
						}
						else if (subcoin[5] > 191 && subcoin[5] < 208) {
							//11
							std::cout << "\x1B[102m\x1B[31m\x1B[5mUn 11 c !\x1B[0m";
							this->printCoin(subcoin, rank);
							usleep(10000);
							return 11;
						}
						//10
						std::cout << "\x1B[103m\x1B[94m\x1B[5mUn 10 c !\x1B[0m";
						this->printCoin(subcoin, rank);
						usleep(10000);
						return 10;
					}
					else if (subcoin[4] > 191 && subcoin[4] < 208)
					{
						//9
						std::cout << "\x1B[44m\x1B[93m\x1B[5mUn 09 c !\x1B[0m";
						this->printCoin(subcoin, rank);
						usleep(10000);
						return 9;
					}
					//8
					std::cout << "\x1B[105m\x1B[94m\x1B[5mUn 08 c !\x1B[0m";
					this->printCoin(subcoin, rank);
					return 8;
				}
				else if (subcoin[3] > 191 && subcoin[3] < 208){
					//7
					std::cout << "\x1B[101m\x1B[93mUn 07 c !\x1B[0m";
					this->printCoin(subcoin, rank);
					return 7;
				}
				//6
				std::cout << "\x1B[102m\x1B[94mUn 06 c !\x1B[0m";
				this->printCoin(subcoin, rank);
				return 6;
			}
			else if (subcoin[2] > 191 && subcoin[2] < 208){
				//5
				std::cout << "\x1B[33mUn 05 c !\x1B[0m";
				this->printCoin(subcoin, rank);
				return 5;
			}
			//4
			//std::cout << "\x1B[96mUn 04 c !\x1B[0m";
			//this->printCoin(subcoin, rank);
			return 4;
		}
		else if (subcoin[1] > 191 && subcoin[1] < 208)
		{
			//3
			//std::cout << "\x1B[95mUn 03 c !\x1B[0m";
			//this->printCoin(subcoin, rank);
			return 3;
		}
		// 2
		//std::cout << "\x1B[34mUn 02 c !\x1B[0m";
		//this->printCoin(subcoin, rank);
		return 2;
	}
	else if (subcoin[0] > 191 && subcoin[0] < 208)
	{
		// 1
		//std::cout << "\x1B[31mUn 01 c !\x1B[0m";
		//this->printCoin(subcoin, rank);
		return 1;
	}
	return 0;
}

void OSSLMiner::printCoin(unsigned char* subcoin, int rank)
{
	std::cout << " resultat de mon sha 1 n°" << std::dec << rank << ":->";
	for (int i = 0; i < 20; i++)
	{
		std::cout << std::hex << (int)subcoin[i];
		std::cout << '-';
	}
	std::cout << std::endl;
}

void OSSLMiner::Mine(Token * to)
{
	unsigned char	ibuf[] = "Hello";
	unsigned char	*shaOne = NULL;
	char 			*basic_str = NULL;
	unsigned char	*subcoin = NULL;

	shaOne = new unsigned char[20];
	basic_str = new char[20];

	//a garder car ca marche 
	//ca donne bien f7 ...
	//comme la commande echo -n 'Hello' | shasum -a 1
	shaOne = SHA1(ibuf, (size_t)5, shaOne);

	std::cout << "resultat du sha 1:\n->";
	for (int i = 0; i < 20; i++)
	{
		std::cout << std::hex << (int)shaOne[i];
		std::cout << '-';
	}
	std::cout << std::endl;

	for (int j = 0; j < 100000000; j++)
	{
		subcoin = SHA1((unsigned char*)to->getTokenUC(), (size_t)60, subcoin);
		this->isGoodCoin(subcoin, j);

		/*subcoin[0] = 10;
		subcoin[1] = 10;
		subcoin[2] = 10;
		subcoin[3] = 10;
		subcoin[4] = 10;
		subcoin[5] = 10;
		subcoin[6] = 10;
		this->printCoin(subcoin, j);
		this->isGoodCoin(subcoin, j);
		subcoin[0] = 192;
		this->isGoodCoin(subcoin, j);
		subcoin[0] = 204;
		this->isGoodCoin(subcoin, j);
		subcoin[1] = 192;
		this->isGoodCoin(subcoin, j);
		subcoin[1] = 204;
		this->isGoodCoin(subcoin, j);
		subcoin[2] = 192;
		this->isGoodCoin(subcoin, j);
		subcoin[2] = 204;
		this->isGoodCoin(subcoin, j);
		subcoin[3] = 207;
		this->isGoodCoin(subcoin, j);
		subcoin[3] = 204;
		this->isGoodCoin(subcoin, j);
		subcoin[4] = 192;
		this->isGoodCoin(subcoin, j);
		subcoin[4] = 204;
		this->isGoodCoin(subcoin, j);
		subcoin[5] = 192;
		this->isGoodCoin(subcoin, j);
		subcoin[5] = 204;
		this->isGoodCoin(subcoin, j);*/
		
		to->updateToken();
	}
}