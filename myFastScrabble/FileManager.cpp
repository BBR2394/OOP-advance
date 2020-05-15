
#include <iostream>
#include <fstream>

class FileManager
{
public:
	FileManager(){};
	~FileManager(){};

private:
	ifstream _myfile;

public:
	int openFile(std::string filename)
	{
		_myfile.open(filename);
		return 0;
	}

	std::string readLine()
	{
		return _myfile.getline();
	}

	void closeFile()
	{
		_myfile.close();
	}

};