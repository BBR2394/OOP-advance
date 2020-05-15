/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-06 10:30:47
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-06 10:39:21
*/

#include <iostream>

class ObjThrowed
{
public:
	ObjThrowed(int v): _c(v) 
	{};
	~ObjThrowed()
	{};

private:
	int _c;
public:
	void rien()
	{
		std::cout << "rien ^^" << std::endl;
	};
	int getValue() const
	{
		return _c;
	};

};

int aFunction()
{
	throw ObjThrowed(42);
}

int main()
{
	std::cout << "here is where the magik happen" << std::endl;
	try{
		std::cout << "la je vais try" << std::endl;
		aFunction();
	}
	catch(int th)
	{
		std::cout << "j'ai recu une exception ! : " << th << std::endl;
	}
	catch(ObjThrowed obj)
	{
		std::cout << "j'ai recu une autre exception : " << obj.getValue() << std::endl;
		 obj.rien();
	}
	return 0;
}