
#ifndef AMINER_H_
# define AMINER_H_



class AMiner
{
public:
	virtual void Mine(const CheckOption &) = 0;
	virtual void BenchMiner() = 0;
};

#endif