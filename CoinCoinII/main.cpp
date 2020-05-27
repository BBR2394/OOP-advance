/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-26 20:12:07
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-27 12:23:27
*/

//#include <unistd.h>

#include <iostream>
#include <cstdlib>
#include <openssl/sha.h>
#include <vector>
#include <iomanip> 

class CheckOption
{
public:
	CheckOption() : _isOptZ(false), _isOptM(false), _isOptT(false), _isOptSave(false), _isOptOne(false), _trigramOption(""), _minimumVal(0) {};
	~CheckOption() {};

private:
	bool _isOptZ;
	bool _isOptM;
	bool _isOptT;
	bool _isOptSave;
	bool _isOptOne;
	std::string _trigramOption;
	int _minimumVal;
	int setOptTrigram(char *opt)
	{
			_trigramOption = opt;
	if (_trigramOption.size() != 3)
		throw std::string("invalid size for trigram : it must be Three character only\n-> an errore with the -t parameter");
	return 0;
	};
	bool setOptMinimum(char *opt)
	{
		try {
		_minimumVal = std::stoi(opt);
		return true;
		}
		catch(...)
		{
			std::cout << "Not a numbern for the minimum coin parameter" << std::endl;
			return false;
		}
		return true;
	};
	bool setOptSave(char *);

public:
	
	int checkOptions(int ac, char** av)
	{
			//std::cout << "dans check option" << std::endl;
	//std::cout << "ac : " << ac << std::endl;
	int i = 1;
	/*
	** j'avais fait un code extremement simpliste et basique pour l'option -z
	** c'est a refaire pour les autres options
	*/
	int c = 0;
	if (ac >= 2) {
		while (i < ac) {
			if (av[i][0] == '-' && av[i][1] == 'z' && av[i][2] == '\0')
				_isOptZ = true;
			if (av[i][0] == '-' && av[i][1] == '1' && av[i][2] == '\0')
				_isOptOne = true;
			if (av[i][0] == '-' && av[i][1] == 't' && av[i][2] == '\0')
				{
					if (i+1 >= ac)
						throw std::string("input for parameter is invalid");
					setOptTrigram(av[i+1]);
					_isOptT = true;
					i++;
				}
			if (av[i][0] == '-' && av[i][1] == 'm' && av[i][2] == '\0')
				{
					if (i+1 >= ac)
						throw std::string("input for parameter is invalid");
					if (setOptMinimum(av[i+1]) == false)
						throw std::string("-> an errore with the -m parameter");
					_isOptM = true;
					i++;
				}
			i++;
			//c ne sert a rien seulement quand j'aurais refait tout ca 
			c++;
		}
	}
	return 0;
	};
	bool getOptionZ() const
	{ return _isOptZ; };

	bool getOptionOne() const
	{ return _isOptOne; };
	bool getOptionT() const
	{ return _isOptT; };

	bool getOptionM() const
	{ return _isOptM; };

	bool getOptionSave() const { return _isOptSave;};
	std::string getTriOptionGiven() const { return _trigramOption; };
	int getMinimumOptionGiven() const { return _minimumVal; };
};

class MyPrinter
{
public:
	MyPrinter() {
		initColorPrintTag();
	};
	~MyPrinter() {};

private:
	std::vector<std::string> _colorPrintTag;

	void initColorPrintTag()
	{
		//reset
		_colorPrintTag.push_back("\x1B[0m");
		//couleur pour chaque coin
		_colorPrintTag.push_back("\x1B[31m");
		_colorPrintTag.push_back("\x1B[34m");
		_colorPrintTag.push_back("\x1B[95m");
		_colorPrintTag.push_back("\x1B[96m");
		_colorPrintTag.push_back("\x1B[33m");
		_colorPrintTag.push_back("\x1B[102m\x1B[94m");
		_colorPrintTag.push_back("\x1B[101m\x1B[93m");
		_colorPrintTag.push_back("\x1B[105m\x1B[94m\x1B[5m");
		_colorPrintTag.push_back("\x1B[44m\x1B[93m\x1B[5m");
		_colorPrintTag.push_back("\x1B[103m\x1B[94m\x1B[5m");
		_colorPrintTag.push_back("\x1B[102m\x1B[31m\x1B[5m");
		_colorPrintTag.push_back("\x1B[106m\x1B[35m\x1B[5m");
		//couleur du token
		_colorPrintTag.push_back("\x1b[25m\x1b[36m\x1b[104m");
		//couleur du coin
		_colorPrintTag.push_back("\x1b[25m\x1b[34m\x1b[43m");
	}

public:
	// void printResult(int level, unsigned char	*token, unsigned char	*coin)
	// {
	// 	std::cout << _colorPrintTag[level] << "un " << level << " c " << _colorPrintTag[13] << token  << " " << _colorPrintTag.back();
	// 	for (int i = 0; i < 20; i++)
	// 	{
	// 		std::cout << std::hex << (int)coin[i];
	// 	}
	// 	std::cout << _colorPrintTag[0] << std::endl;
	// };

	template<class typeA, class typeB, class typeC>
	void printResult(typeA level, typeB token, typeC coin)
	{
		std::cout << _colorPrintTag[level] << "un " << level << " c " << _colorPrintTag[13] << token  << " " << _colorPrintTag.back();
		for (int i = 0; i < 20; i++)
		{
			std::cout << std::setfill ('0') << std::setw (2) << std::hex << (int)coin[i];
		}
		std::cout << _colorPrintTag[0] << std::endl;
	};

};

class AMiner
{
public:
	virtual void Mine(const CheckOption &) = 0;
	virtual void BenchMiner() = 0;
};

class MinerOSSL : AMiner
{
public:
	MinerOSSL() {
		initToken();
	};
	MinerOSSL(std::string trigrame, std::string proto, std::string reserved) : 
	_trigram(trigrame), 
	_proto(proto), 
	_reserved(reserved) 
	{
		initToken();
	};
	~MinerOSSL() {};

private:
	//BBR ou BBE
	std::string _trigram;
	//CC1.0
	std::string _proto;
	//0F0F0F
	std::string _reserved;
	//trigram + proto + time when generated + reserved
	std::string _partUnchanged;
	//the final token send to the sha 1 function
	unsigned char _token[60];

	//resultat du sha one
	unsigned char	*_subcoin = NULL;

	MyPrinter _printer;
	//std::string _firstToken;

	void initToken()
	{
		for (int i = 0; i < 60; i++)
		{
			//66 = B in ascii
			_token[i] = 66;
		}
	};

public:
	void setToken(std::string trigrame, std::string proto, std::string reserved)
	{
		_trigram = trigrame; 
		_proto = proto; 
		_reserved = reserved;
	}

	void printToken()
	{
		std::cout << "\x1b[96mLe token : \x1b[101m\x1b[104m";
		for (int i = 0; i < 60; i++)
		{
			std::cout << _token[i];
		}
		std::cout << "\x1b[0m" << std::endl;
	}

	//i am not very sure for this one to set as inline. if it could help
	inline std::string generateTime()
	{
		time_t	theTime;
		std::string strTime;

		time(&theTime);
		strTime = std::to_string(theTime);
		//std::cout << "le temps est a : " << strTime << " et ca fait : " << strTime.size() << std::endl;
		return strTime;
	}

	inline int genRandNineFive()
	{
		return rand() % 95;
	}

	inline long genRandNineFiveLong()
	{
		return lrand48() % 95;
	}

	inline int genRandMacOS()
	{
		//std::cout << "dans le gen mac os " << std::endl;
		return random() % 95;
	}

	void generateToken()
	{
		unsigned char numRand = 0;
		#ifdef __APPLE__
		char *state;
		state = (char*)malloc(8*sizeof(char));
		initstate(128, state, 8);
		#else
		srand (time(NULL)*1000);
		#endif
		std::string strTm = this->generateTime();
		_partUnchanged = '-' + _trigram + '-' + _proto + '-' + strTm +'-' + _reserved;
		std::cout << "partie non changeante " << _partUnchanged << std::endl;
	
		for (int i = 0; i < 32; i++)
		{
			numRand = (genRandNineFive()) + 32;
			//std::cout << " i = " << i << "=" << numRand << std::endl;
			_token[i] = numRand;
		}
		int c = 0;
		for (int i = 32; i < 60; i++)
		{
			_token[i] = _partUnchanged[c++];
		}
		this->printToken();
	};

	void updateToken()
	{
		#if __APPLE__
		unsigned char numRand =  (genRandMacOS()) + 32;
		#else
		unsigned char numRand =  (genRandNineFive()) + 32;
		#endif
		//int posRand = rand() % 32;
		//std::cout << "pos rand " << posRand << "numrand =  " << numRand << " et le rand " << rand() << std::endl;
		
		//sleep(10);
		
		for (int i = 0; i < 32; i++)
		{
			numRand =  (rand() % 95) + 32;
			this->_token[i] = numRand;
		}
		//std::strncpy (this->_token, (char*)_nonce->getNonceUC(), 32)
		//this->printToken();
	}

	//function JustOne
	void updateJustOne()
	{
		unsigned char numRand =  (rand() % 95) + 32;
		int posRand = rand() % 32;
		//std::cout << std::dec << "pos rand " << posRand << " numrand =  " << (int)numRand << " et le rand " << rand() << std::endl;
		this->_token[posRand] = numRand;
		//this->printToken();
	}

	void printCoin()
	{
		std::cout << "\x1b[36mLe coin : \x1b[34m\x1b[43m";
		for (int i = 0; i < 20; i++)
		{
			std::cout << _token[i];
		}
		std::cout << "\x1b[0m" << std::endl;
	}

	int checkCoin(int min=1)
	{
		int nbC = 0;
		for (int i = 0; i < 32; i++)
		{
			if (_subcoin[i] == 204)
			{
				nbC += 2;
			}
			else if (_subcoin[i] > 191 && _subcoin[i] < 208)
			{
				//std::cout << "1C !" << std::endl;
				//this->printCoin();
				//std::cout << std::hex << (int)_subcoin[i] << std::endl;
				nbC += 1;
				break;
			}
			else 
				break;
		}
		if (nbC >= min)
		{
			_printer.printResult(nbC, _token, _subcoin);
		}
		return nbC;
	}

	void Mine(const CheckOption &opt)
	{
		int minimum = opt.getMinimumOptionGiven();
		std::cout << "dans le mine du MinerOSSL" << std::endl;
		
		while (true) {
			_subcoin = SHA1(_token, (size_t)60, _subcoin);
			this->checkCoin(minimum);
			this->updateToken();
			//this->updateJustOne();
		}
	};
	
	void printBenchMark(int elapsedTime)
	{
		float hourPrevition = 0.0;
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
		hourPrevition = ((float)elapsedTime*16.0*16.0*16.0*16.0)/60.0/60.0;
		std::cout << "10c (Blackstar)\t" << elapsedTime*16*16*16 << " s\t\t(" << hourPrevition << " h)" << std::endl;
	}

	void BenchMiner()
	{
		std::string currentTime = generateTime();
		int timeSecond = std::stoi(currentTime);
		int start = timeSecond;
		long individualCounter[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
		int rtrNbC = 0;
		std::cout << "\x1b[31mici je vais faire le bench : " << currentTime << " int : " << timeSecond << "\x1b[0m" << std::endl;
		int c = 0;
		while (individualCounter[6] <= 0 && start + 58 > timeSecond) {
			_subcoin = SHA1(_token, (size_t)60, _subcoin);
			this->updateToken();
			//this->updateJustOne();
			rtrNbC = this->checkCoin(42);
			individualCounter[rtrNbC] += 1;
			currentTime = generateTime();
			timeSecond = std::stoi(currentTime);
			c++;
		}
		std::cout << "i have compute : " << c << " tokens in : " << timeSecond - start << "seconde" << std::endl;
		this->printBenchMark(timeSecond - start);
		//this for is to print the individual counter
		// for (int i = 0; i < 12; i++)
		// {
		// 	std::cout << "nb c : " << i << " computed number : " << individualCounter[i] << std::endl;
		// }
	};

	//function JustOne
	void MineBis(const CheckOption &opt)
	{
		std::cout << "dans le  mine just one" << std::endl;
		int minimum = opt.getMinimumOptionGiven();
		std::cout << "dans le mine du MinerOSSL" << std::endl;
		
		while (true) {
			_subcoin = SHA1(_token, (size_t)60, _subcoin);
			this->checkCoin(minimum);
			//this->updateToken();
			this->updateJustOne();
		}
	};
	
	//function JustOne
	void BenchMinerBis()
	{
		std::cout << "dans le bench mine just one" << std::endl;
		std::string currentTime = generateTime();
		int timeSecond = std::stoi(currentTime);
		int start = timeSecond;
		std::cout << "\x1b[31mici je vais faire le bench : " << currentTime << " int : " << timeSecond << "\x1b[0m" << std::endl;
		int c = 0;
		while (start + 10 > timeSecond) {
			_subcoin = SHA1(_token, (size_t)60, _subcoin);
			//this->updateToken();
			this->updateJustOne();
			currentTime = generateTime();
			timeSecond = std::stoi(currentTime);
			c++;
		}
		std::cout << "i have compute : " << c << " tokens " << std::endl;
	};

};

int main(int ac, char **av)
{
	MinerOSSL *mm = new MinerOSSL();
	CheckOption chckOpt;

	std::cout << "here is where the magik happen !" << std::endl;
	try {
		chckOpt.checkOptions(ac, av);
	}
	catch(std::string r)
	{
		std::cout << r << std::endl;
		return -1;
	}
	if (chckOpt.getOptionT())
		mm->setToken(chckOpt.getTriOptionGiven(), "CC1.0", "0F0F0F");
	else
		mm->setToken("BBE", "CC1.0", "0F0F0F");
	mm->generateToken();
	if (chckOpt.getOptionZ())
		//ici l'option juste un
		if (chckOpt.getOptionOne())
			mm->BenchMinerBis();
		//sinon normal
		else 
			mm->BenchMiner();
	else
		if (chckOpt.getOptionOne())
			mm->MineBis(chckOpt);
		else
		mm->Mine(chckOpt);
	return 0;
}