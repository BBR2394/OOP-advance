
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

void MyMiner::setOption(const CheckOption &chckOpt)
{
	if (chckOpt.getOptionM()){
		_opt.setMinPrint(chckOpt.getMinimumOptionGiven());
		_opt.setMinSave(chckOpt.getMinimumOptionGiven());
		std::cout << "minimum to print and save : " << _opt.getMiniToPrint() << " " << _opt.getMinimumToSave() << std::endl;
	}
}

int MyMiner::mine(const CheckOption &opt)
{
	std::cout << "here i will start to mine" << std::endl;
	_tkn = new Token("BBR", "CC1.0");
	//_miner = new ThrdOSSLMiner();
	_miner = new OSSLMiner();
	//FakeMiner *fkminer = new FakeMiner();
	this->setOption(opt);
	std::cout << "le token tu my miner\n" << *_tkn << "et le CheckOption : " << opt.getOptionZ() << std::endl;
	_tkn->getTokenUC();
	if (opt.getOptionZ() == true) {
		_miner->BenchMiner(_tkn);
	}
	else {
		if (opt.getOptionT() == true) {
			delete _tkn;
			_tkn = new Token(opt.getTriOptionGiven(), "CC1.0");
			std::cout << "le token avec le trigrame special : " << opt.getTriOptionGiven() << *_tkn << std::endl;
		}
		_miner->Mine(_tkn, _opt);
	}
	//fkminer->Mine(_tkn);
	
	delete _tkn;
	return 0;
}