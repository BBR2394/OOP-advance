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
	bool _save;

public:
	int getMiniToPrint() const;
	int getMinimumToSave() const;
	bool getIfSave() const;
	void setMinPrint(int mp);
	void setMinSave(int ms);
	//if we call setIfSave it set save to true
	void setIfSave();

};

#endif