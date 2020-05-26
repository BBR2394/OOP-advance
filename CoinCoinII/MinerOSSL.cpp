/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-26 20:23:19
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-26 20:42:11
*/

class MinerOSSL : AMiner
{
public:
	MinerOSSL::MinerOSSL() {
		initToken();
	}
	MinerOSSL::MinerOSSL(std::string trigrame, std::string proto, std::string reserved) : 
	_trigram(trigrame), 
	_proto(proto), 
	_reserved(reserved) 
	{
		initToken();
	};
	MinerOSSL::~MinerOSSL() {};

private:
	std::string _trigram;
	std::string _proto;
	std::string _reserved;
	unsigned char _token[60];
	std::string _firstToken;

	void initToken()
	{
		for (int i = 0; i < 60; i++)
		{
			//66 = B in ascii
			_token = 66;
		}
	};

public:
	int setToken(std::string trigrame, std::string proto, std::string reserved)
	{
		_trigram = trigrame; 
		_proto = proto; 
		_reserved = reserved;
	}
	void generateToken()
	{

	};

	void Mine(const CheckOption &)
	{
		std::cout << "dans le mine du MinerOSSL" << std::endl;

	};
	
	void BenchMiner()
	{
	};
};