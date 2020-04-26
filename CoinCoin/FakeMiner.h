
#ifndef FAKEMINER_H_
# define FAKEMINER_H_

#include <openssl/sha.h>
#include "AMiner.h"

class FakeMiner : public AMiner
{
public:
	FakeMiner();
	~FakeMiner();

private:
	int init();

public:
	void Mine(Token *);
};

#endif