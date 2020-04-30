#ifndef TOKEN_H_
# define TOKEN_H_

#include <string>
#include <cstring>
#include <iostream>

#include "Nonce.h"
#include "Time.h"

class Token
{
public:
	Token();
	Token(std::string to, std::string prt);	
	~Token();

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
	//std::string _nonce;

	void generateToken();
	void genTime();
	int my_strncpy(char *dest, char *src, int n);


public:
	void setTrigram(std::string);
	char * getTokenUC();
	int updateToken();
	std::string getToken() const;

};

std::ostream& operator<<(std::ostream&, Token const &);

#endif