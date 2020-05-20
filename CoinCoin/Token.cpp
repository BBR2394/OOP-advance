
#include "Token.h"

Token::Token()
{
	_triOwn = "BBR";
	_proto = "CC1.0";
	this->genTime();
	_reserved = "0F0F0F";
	this->generateToken();
}

Token::Token(std::string to) : _triOwn(to)
{
	_proto = "CC1.0";
	this->genTime();
	_reserved = "0F0F0F";
	this->generateToken();
}

Token::Token(std::string to, std::string prt) : _triOwn(to), _proto(prt)
{
	this->genTime();
	_reserved = "0F0F0F";
	this->generateToken();
}

/* the goal to this constructyor is for save not to use it as token yet */
Token::Token(const Token &tkn)
{
	_triOwn = tkn._triOwn;
	_proto = tkn._proto;
	_reserved = tkn._reserved;
	_token = tkn._token;
	_nonce = NULL;
	_nonceStr = tkn._nonce->getNonce();
}

Token::~Token()
{
	
}

void Token::genTime()
{
	Time tm;
	_time = tm.getTime();
	_strTime = std::to_string(_time);
	std::cout << "le temps est a : " << _strTime << " et ca fait : " << _strTime.size() << std::endl;
}

void Token::setTrigram(std::string newTriOwn)
{
	_triOwn = newTriOwn;
}

void Token::generateToken()
{
	_partUnchange = '-' + _triOwn + '-' + _proto + '-' + _strTime + '-' + _reserved;
	this->_token_c_str = new char [61];

	//je fais ca mais ca marche sans
	this->_token_c_str[60] = '\0';

	_nonce = new Nonce;
	_nonce->genNonce();
	std::cout << "la je genere le token " << std::endl;
	_token = _nonce->getNonce() + _partUnchange;
	std::cout << "generation final du token : " << _nonce->getNonce().c_str() << std::endl;
	std::strncpy (this->_token_c_str, _nonce->getNonce().c_str(), _nonce->getNonce().size());
	std::cout << "1>" << this->_token_c_str << "***" << std::endl;
	std::strncpy (&_token_c_str[32], _partUnchange.c_str(), _partUnchange.size());
	//je suis maintenant sur d'avoir mon token en char * corect
	std::cout << "2>" << this->_token_c_str << "***" << std::endl;
}

char * Token::getTokenUC()
{
	// std::cout << "dans le get token unsigned char" << std::endl;
	// std::cout << "***" << this->_token_c_str << "***" << std::endl;
	
	// for (int i = 0; i < 60; i++)
	// {
	// 	std::cout << _token_c_str[i] << std::endl;
	// }
	return this->_token_c_str;
}

int Token::my_strncpy(char *dest, char *src, int n)
{
	int c = 0;

	while (c < n){
		dest[c] = src[c];
		c++;
	}
	return c;
}

int Token::updateToken()
{
	_nonce->updateNonce();

	_token = _nonce->getNonce() + _partUnchange;

	//std::cout << "mise a jour du token" << _token << std::endl;

	/* 
	*j'ai créé mon propre my strncpy comme un tek 1 car je dois mal manipuler ma variable entre 
	*le char* et le U char * il y a un probleme avec le \0 
	*/
	//std::strcpy (this->_token_c_str, (char*)_nonce->getNonceUC());
	//my_strncpy(this->_token_c_str, (char*)_nonce->getNonceUC(), 32);
	std::strncpy (this->_token_c_str, (char*)_nonce->getNonceUC(), 32);

	//std::cout << "+++" << this->_token_c_str << "+++" << std::endl;

	/*etant donnée que j'utilise le meme pointeur et donc la meme variable, la partie "non changeante" est toujours la */
	//std::strcpy (&_token_c_str[32], _partUnchange.c_str());

	//je suis maintenant sur d'avoir mon token en char * corect
	//std::cout << "42>" << this->_token_c_str << "+++" << std::endl;
	return 0;
}

std::string Token::getToken() const
{
	return _token;
}

std::ostream & operator<<(std::ostream & os, Token const & tkn)
{
	os << "\x1B[36mThe final token is : \x1B[37m\x1B[43m";
	os << tkn.getToken() << "\x1B[0m" << std::endl;
	return os;
}