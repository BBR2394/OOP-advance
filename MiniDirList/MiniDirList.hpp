#ifndef MINIDIRLIST_HPP_
# define MINIDIRLIST_HPP_

#include <iostream>
#include <string>

#include <boost/asio.hpp>

class MiniDirList
{
public:
	MiniDirList();
	~MiniDirList();

private:
	int _c;

public:
	int run();

};

#endif