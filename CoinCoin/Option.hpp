#ifndef OPTION_HPP_
# define OPTION_HPP_

class Option
{
public:
	Option();
	Option(int minPrint, int minSave);
	~Option();

private:
	int _minimumToPrint;
	int _minimumToSave;

public:
	int getMiniToPrint() const;
	int getMinimumToSave() const;
	void setMinPrint(int mp);
	void setMinSave(int ms);

};

#endif