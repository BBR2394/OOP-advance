
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

int OSSLMiner::isGoodCoin(unsigned char* subcoin, int rank, bool print, int minimumToPrint)
{
	if (subcoin[0] == 204){
		if (subcoin[1] == 204){
			if (subcoin[2] == 204) {
				if (subcoin[3] == 204){
					if (subcoin[4] == 204) {
						if (subcoin[5] == 204)
						{
							//12
							if (print == true && minimumToPrint <= 12) {
								std::cout << "\x1B[106m\x1B[35m\x1B[5mUn 12 c !\x1B[0m";
								this->printCoin(subcoin, rank);
							}
							return 12;
						}
						else if (subcoin[5] > 191 && subcoin[5] < 208) {
							//11
							if (print == true && minimumToPrint <= 11) {
								std::cout << "\x1B[102m\x1B[31m\x1B[5mUn 11 c !\x1B[0m";
								this->printCoin(subcoin, rank);
							}
							return 11;
						}
						//10
						if (print == true && minimumToPrint <= 10) {
							std::cout << "\x1B[103m\x1B[94m\x1B[5mUn 10 c !\x1B[0m";
							this->printCoin(subcoin, rank);
						}
						return 10;
					}
					else if (subcoin[4] > 191 && subcoin[4] < 208)
					{
						//9
						if (print == true && minimumToPrint <= 9) {
							std::cout << "\x1B[44m\x1B[93m\x1B[5mUn 09 c !\x1B[0m";
							this->printCoin(subcoin, rank);
						}
						return 9;
					}
					//8
					if (print == true && minimumToPrint <= 8) {
						std::cout << "\x1B[105m\x1B[94m\x1B[5mUn 08 c !\x1B[0m";
						this->printCoin(subcoin, rank);
					}
					return 8;
				}
				else if (subcoin[3] > 191 && subcoin[3] < 208){
					//7
					if (print == true && minimumToPrint <= 7) {
						std::cout << "\x1B[101m\x1B[93mUn 07 c !\x1B[0m";
						this->printCoin(subcoin, rank);
					}
					return 7;
				}
				//6
				if (print == true && minimumToPrint <= 6) {
					std::cout << "\x1B[102m\x1B[94mUn 06 c !\x1B[0m";
					this->printCoin(subcoin, rank);
				}
				return 6;
			}
			else if (subcoin[2] > 191 && subcoin[2] < 208){
				//5
				if (print == true && minimumToPrint <= 5) {
					std::cout << "\x1B[33mUn 05 c !\x1B[0m";
					this->printCoin(subcoin, rank);
				}
				return 5;
			}
			//4
			if (print == true && minimumToPrint <= 4) {
				std::cout << "\x1B[96mUn 04 c !\x1B[0m";
				this->printCoin(subcoin, rank);
			}
			return 4;
		}
		else if (subcoin[1] > 191 && subcoin[1] < 208)
		{
			//3
			if (print == true && minimumToPrint <= 3) {
				std::cout << "\x1B[95mUn 03 c !\x1B[0m";
				this->printCoin(subcoin, rank);
			}
			return 3;
		}
		// 2
		if (print == true && minimumToPrint <= 2) {
			std::cout << "\x1B[34mUn 02 c !\x1B[0m";
			this->printCoin(subcoin, rank);
		}
		return 2;
	}
	else if (subcoin[0] > 191 && subcoin[0] < 208)
	{
		// 1
		if (print == true && minimumToPrint <= 1) {
			std::cout << "\x1B[31mUn 01 c !\x1B[0m";
			this->printCoin(subcoin, rank);
		}
		return 1;
	}
	return 0;
}
//il faut que je recupere ici le token pour l'afficher :-/ 
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

void OSSLMiner::printBenchmark(int typeCoin, int elapsedTime) const
{
	float hourPrevition = 0.0;
	if (typeCoin == 6)
	{
		std::cout << "6c (subcoin) mined in " << elapsedTime << " s\n*** Mining projections ***\n";
		hourPrevition = (float)elapsedTime / 60.0 / 60.0;
		std::cout.precision(2);
		std::cout << "6c (subcoin)\t" << elapsedTime << " s\t\t(" << std::fixed << hourPrevition << " h)\n";
		hourPrevition = ((float)elapsedTime*16.0) /60.0/60.0;
		std::cout << "7c (coin)\t" << elapsedTime*16 << " s\t\t(" << hourPrevition << " h)\n";
		hourPrevition = ((float)elapsedTime*16.0*16.0)/60.0/60.0;
		std::cout << "8c (hexcoin)\t" << elapsedTime*16*16 << " s\t\t(" << hourPrevition << " h)\n";
		hourPrevition = ((float)elapsedTime*16.0*16.0*16.0)/60.0/60.0;
		std::cout << "9c (arkenston)\t" << elapsedTime*16*16*16 << " s\t\t(" << hourPrevition << " h)" << std::endl;
	}
}

void OSSLMiner::BenchMiner(Token * to) //rajouter la duration non ?
{
	unsigned char	*subcoin = NULL;
	int 			ret = 0;
	Time 			tm;
	time_t 			beginTime = tm.getCurentTime();
	//58 seconde de travail
	int 			timeToWork = beginTime + 58;
	long			individualCounter[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	int 			counterTotalWorked = 0;

	std::cout << "Starting benchmark..." << std::endl;
	while (tm.getCurentTime() < timeToWork)
	{
		subcoin = SHA1((unsigned char*)to->getTokenUC(), (size_t)60, subcoin);
		ret = this->isGoodCoin(subcoin, 0, false, 0);
		if (ret > 0)
			individualCounter[ret-1] += 1;
		tm.update();
		if (ret == 6)
			break;
		to->updateToken();
		counterTotalWorked++;
	}
	if (ret != 6) {
		std::cout << "an errore occured, please re run the benchmark" << std::endl;
	}
	printBenchmark(ret, tm.getCurentTime() - beginTime);
	//std::cout << "i have compute : " << counterTotalWorked << " token " << std::endl;
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

	while (counter < 10000000000)
	{
		subcoin = SHA1((unsigned char*)to->getTokenUC(), (size_t)60, subcoin);
		ret = this->isGoodCoin(subcoin, i, true, 6);
		if (ret > 0)
			individualCounter[ret-1] += 1;
		if (ret > 5)
		{
			std::cout << "token corespondant : " << to->getTokenUC();
			std::cout << " elapse time : " << tm.getCurentTime() - beginTime << " seconds " << std::endl;
			i += 1;
		}
		counter += 1;
		to->updateToken();
	}

	for (int i = 0; i < 12; i++)
	{
		std::cout << std::dec << "il y a eu " << individualCounter[i] << " pour un token de " << i+1 << " c " << std::endl;
	}
}