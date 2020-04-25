
#include "MyMiner.h"

MyMiner::MyMiner() : _c(42)
{
	
}

MyMiner::~MyMiner()
{
	
}

int	MyMiner::getC() const
{
	return _c;
}

int MyMiner::mine()
{
	std::cout << "here i will start to mine" << std::endl;
	_tkn = new Token("BBR", "CC1.0");
	_miner = new OSSLMiner();
	//FakeMiner *fkminer = new FakeMiner();

	std::cout << "le token tu my miner\n" << *_tkn << std::endl;
	_tkn->getTokenUC();
	_miner->Mine(_tkn);
	//fkminer->Mine(_tkn);
	
	return 0;
}