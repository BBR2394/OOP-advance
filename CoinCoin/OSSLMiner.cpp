
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
							return 11;
						}
						//10
						std::cout << "\x1B[103m\x1B[94m\x1B[5mUn 10 c !\x1B[0m";
						this->printCoin(subcoin, rank);
						return 10;
					}
					else if (subcoin[4] > 191 && subcoin[4] < 208)
					{
						//9
						std::cout << "\x1B[44m\x1B[93m\x1B[5mUn 09 c !\x1B[0m";
						this->printCoin(subcoin, rank);
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
				//std::cout << "\x1B[33mUn 05 c !\x1B[0m";
				//this->printCoin(subcoin, rank);
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
	int 			ret = 0;
	shaOne = new unsigned char[20];
	basic_str = new char[20];
	Time 			tm;
	time_t 			beginTime = tm.getCurentTime();
	int 			timeToWork = beginTime + 600;
	int 			i = 0;
	long			counter = 0;
	long			individualCounter[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
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

	//for (long j = beginTime; j < 10000000000; j++)
	//10000000
	while (counter < 100000000)
	{
		subcoin = SHA1((unsigned char*)to->getTokenUC(), (size_t)60, subcoin);
		ret = this->isGoodCoin(subcoin, i);
		if (ret > 0)
			individualCounter[ret-1] += 1;
		if (ret > 5)
		{
			std::cout << "token corespondant : " << to->getTokenUC();
			std::cout << " elapse time : " << tm.getCurentTime() - beginTime << " seconds " << std::endl;
			i += 1;
		}
		counter += 1;
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

	for (int i = 0; i < 12; i++)
	{
		std::cout << std::dec << "il y a eu " << individualCounter[i] << " pour un token de " << i+1 << " c " << std::endl;
	}
}