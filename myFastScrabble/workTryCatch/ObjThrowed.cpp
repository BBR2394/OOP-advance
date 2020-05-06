/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-05-06 10:31:08
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-05-06 10:37:38
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

};
