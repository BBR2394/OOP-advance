
#include "ThrdOSSLMiner.h"

ThrdOSSLMiner::ThrdOSSLMiner() : _id(0)
{
}

ThrdOSSLMiner::~ThrdOSSLMiner()
{
	
}

void *start_thread(void *data)
{

}

void ThrdOSSLMiner::BenchMiner(Token *to)
{
	std::cout << "ici c'est le becnh mine" << std::endl;
}

void ThrdOSSLMiner::Mine(Token *to)
{
	int th = 1;
	std::cout << "ici c'est le mine" << std::endl;
	
}
