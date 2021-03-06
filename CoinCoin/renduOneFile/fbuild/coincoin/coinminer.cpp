/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-27 14:05:00
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-03 00:20:11
*/

#include <cstring>
#include <iostream>
#include <string>
#include <vector>

#include <ctime>
#include <sys/time.h>

#include <openssl/sha.h>

class Time
{
public:
	Time(){
		init();
	};
	~Time(){};

private:
	time_t	_time;
	struct timeval _tv;

public:
	void init()
	{
		time(&_time);
		gettimeofday(&_tv, NULL);
	};
	void update()
	{
		this->init();
	};
	void printTimeHuman()
	{
		std::cout << "it is " << ctime(&_time);
	};
	void printTimeHuman(const time_t theTime)
	{
		std::cout << "it is " << ctime(&theTime);
	};
	int getTime()
	{
		return _time;
	};
	int getTimeMS()
	{
		return _tv.tv_usec;
	};
	const time_t getCurentTime()
	{
	time(&_time);
		return _time;
	};
};

class CheckOption
{
public:
	CheckOption() : _isOptZ(false), _isOptM(false), _isOptT(false)
	{};
	~CheckOption() {};

private:
	bool _isOptZ;
	bool _isOptM;
	bool _isOptT;
public:
	int checkOptions(int ac, char** av)
	{
		if (ac >= 2) {
		for (int i = 1; i < ac; i++) {
			if (av[i][0] == '-' && av[i][1] == 'z' && av[i][2] == '\0')
				_isOptZ = true;
		}
	}
	return 0;
	};
	bool getOptionZ() const
	{
		return _isOptZ;
	};

};


class Nonce
{
public:
	Nonce()
	{
		_sizeNonce = 32;
		_nonceUC = new unsigned char[32];
		srand (time(NULL)*1000);
	};
	~Nonce(){};

private:
	std::vector<unsigned char>	_nonce;
	unsigned char				*_nonceUC;
	std::string					_nonceStr;
	int 						_sizeNonce;
	Time						_time;
	int genRand()
	{
		int v1 = rand() % 95;
		return v1;
	};
	int generate()
	{
		int randgenerated = 0;
	
		for (int i = 0; i < _sizeNonce; i++)
		{
			randgenerated = genRand()+32;
			_nonceUC[i] = (unsigned char)randgenerated;
			_nonce.push_back(randgenerated);
			_nonceStr.push_back(randgenerated);
		}
		return 0;
	};

public:
	int genNonce()
	{
		this->generate();
		return 0;
	}
	int updateNonce()
	{
		int randgenerated = 0;
		for (int i = 0; i < _sizeNonce; i++)
		{
			randgenerated = genRand()+32;
			_nonceUC[i] = (unsigned char)randgenerated;
		}
		return 0;
	};
	std::string getNonce() const
	{
		return _nonceStr;
	};
	unsigned char * getNonceUC()
	{
		return _nonceUC;
	};
};

class Token
{
public:
	Token(){
			_triOwn = "BBR";
		_proto = "CC1.0";
		this->genTime();
		_reserved = "0F0F0F";
		this->generateToken();
	};
	Token(std::string to, std::string prt)
	{
		this->genTime();
		_reserved = "0F0F0F";
		this->generateToken();
	};
	~Token(){};

private:
	std::string _triOwn;
	std::string _proto;
	std::string _reserved;
	std::string _partUnchange;
	std::string _token;
	Nonce		*_nonce;
	char		*_token_c_str;
	unsigned char *_tokenUC;

	int			_time;
	std::string _strTime;

	void generateToken()
	{
		_partUnchange = '-' + _triOwn + '-' + _proto + '-' + _strTime + '-' + _reserved;
		this->_token_c_str = new char [61];

		//je fais ca mais ca marche sans
		this->_token_c_str[60] = '\0';

		_nonce = new Nonce;
		_nonce->genNonce();
		_token = _nonce->getNonce() + _partUnchange;
		std::strcpy (this->_token_c_str, _nonce->getNonce().c_str());
		std::strcpy (&_token_c_str[32], _partUnchange.c_str());
	};
	void genTime(){
		Time tm;
		_time = tm.getTime();
		_strTime = std::to_string(_time);
	};

public:
	void setTrigram(std::string newTriOwn){
		_triOwn = newTriOwn;
	};
	char * getTokenUC()
	{
		return this->_token_c_str;
	};
	int updateToken()
	{
		_nonce->updateNonce();
		_token = _nonce->getNonce() + _partUnchange;
		std::strcpy (this->_token_c_str, (char*)_nonce->getNonceUC());
		std::strcpy (&_token_c_str[32], _partUnchange.c_str());
		return 0;
	};
	std::string getToken() const
	{
		return _token;
	};
};

class AMiner
{
public:
	virtual void Mine(Token *) = 0;
	virtual void BenchMiner(Token *) = 0;
};

class OSSLMiner : public AMiner
{
public:
	OSSLMiner(){};
	~OSSLMiner(){};

private:
	/*
	** cette fonction est un peu imposante mais elle ne sert juste que pour de l'affichage surtout
	** et pour savoir qu'elle coin c'est 
	*/
	int isGoodCoin(unsigned char* subcoin, int rank,  bool print, int minimumToPrint)
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
								std::cout <<"\x1B[106m\x1B[35m\x1B[5mUn 12 c !\x1B[0m";
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
	};
	void printCoin(unsigned char* subcoin, int rank)
	{
		std::cout << " resultat de mon sha 1 n°" << std::dec << rank << ":->";
		for (int i = 0; i < 20; i++)
		{
			std::cout << std::hex << (int)subcoin[i];
			std::cout << '-';
		}
		std::cout << std::endl;
	};
	void printBenchmark(int typeCoin, int elapsedTime) const
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
	};
public:
	void Mine(Token *to)
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
		int 			minToPrint = 6;

		while (true)
		{
			subcoin = SHA1((unsigned char*)to->getTokenUC(), (size_t)60, subcoin);
			ret = this->isGoodCoin(subcoin, i, true, minToPrint);
			if (ret > 0)
				individualCounter[ret-1] += 1;
			if (ret >= minToPrint)
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
	};
	void BenchMiner(Token *to)
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
		/* 
		** ca c'est un compteur general pour chaque piece 
		*/
		// for (int i = 0; i < 12; i++)
 	// 	{
 	// 		std::cout << std::dec << "il y a eu " << individualCounter[i] << " pour un token de " << i+1 << " c " << std::endl;
 	// 	}
 		//ret a la place de 6 sinon
		printBenchmark(6, tm.getCurentTime() - beginTime);
		//printBenchmarkMoyenne(timeToWork, individualCounter);
		
		/* compteur generale du nombre de token traité */
		//std::cout << "i have compute : " << counterTotalWorked << " token " << std::endl;
	};
};




class MyMiner
{
public:
	MyMiner(){};
	~MyMiner(){};

private:
	AMiner *_miner;
	Token *_tkn;

public:
	int mine(const CheckOption &opt)
	{
		_tkn = new Token("BBR", "CC1.0");
		_miner = new OSSLMiner();

		_tkn->getTokenUC();
		if (opt.getOptionZ() == true) {
			_miner->BenchMiner(_tkn);
		}
		else {
			_miner->Mine(_tkn);
		}
	
		delete _tkn;
		return 0;

	};


};

int main(int ac, char **av)
{
	MyMiner mm;
	CheckOption chckOpt;

	//std::cout << "here is where the magik happen !" << std::endl;
	chckOpt.checkOptions(ac, av);

	mm.mine(chckOpt);
}