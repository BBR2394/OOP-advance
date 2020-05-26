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
	Token(std::string to);
	Token(std::string to, std::string prt);
	/* the goal to this constructyor is for save not to use it as token yet */
	Token(const Token &tkn);
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
	std::string _nonceStr;
	//if we want to save the token
	char *_CoinResult;

	void generateToken();
	void genTime();
	int my_strncpy(char *dest, char *src, int n);
	/* je vais la mettre en inline */
	void assembleToken();

public:
	void setTrigram(std::string);
	char * getTokenUC();
	int updateToken();
	std::string getToken() const;
	//we can add the result in order to saved it
	int addResult(char	*);
	char *getResultCoin() const;

};

std::ostream& operator<<(std::ostream&, Token const &);

#endif