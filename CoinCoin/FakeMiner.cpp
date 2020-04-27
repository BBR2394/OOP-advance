
#include "FakeMiner.h"

FakeMiner::FakeMiner()
{
	
}

FakeMiner::~FakeMiner()
{
	
}

void FakeMiner::BenchMiner(Token *)
{
	std::cout << "nothin done here yet" << std::endl;
}

void FakeMiner::Mine(Token *)
{
	unsigned char	ibuf[] = "Hell";
	unsigned char bogdanCoin[] = "i%u@>^J;\\%-k5T|v,w1Tp7=,=e|~`>a!-BCO-CC1.0-1587572545-0f0f0f";
	unsigned char *shaBogdan = NULL;
	char 			*basic_str = NULL;

	basic_str = new char[20];

	std::cout << "bogdan token : " << std::endl;
	for (int i = 0; i < 59; i++)
	{
		std::cout << std::hex << (int)bogdanCoin[i];
		std::cout << '-';
	}
	std::cout << std::endl;

	shaBogdan = SHA1(bogdanCoin, (size_t)60, shaBogdan);

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