/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-27 14:08:44
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-27 14:12:38
*/

#include <iostream>

class Test
{
public:
	Test() : _c(42)
	{
		std::cout << "dans le constructeur " << std::endl;
	};
	~Test()
	{
		std::cout << "dans le deconstructeur " << std::endl;
	};

private:
	int _c;

public:
	int getInt() const
	{
		return _c;
	};
	void setInt(int niouC)
	{
		_c = niouC;
	}
};

int main()
{
	Test ts;

	std::cout << "le c du test est = " << ts.getInt() << std::endl;
	ts.setInt(36);
	std::cout << "le c du test est = " << ts.getInt() << std::endl;
	return 0;
}