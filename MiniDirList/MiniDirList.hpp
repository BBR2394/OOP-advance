#ifndef MINIDIRLIST_HPP_
# define MINIDIRLIST_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <boost/asio.hpp>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

class MiniDirList
{
public:
	MiniDirList();
	~MiniDirList();

private:
	int _c;
	std::string _fileList;

public:
	int run();
	int listFile();
	int listFileTD();


};

#endif