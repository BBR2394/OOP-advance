
#include <string>
#include <deque>

class DicoManager
{
public:
	DicoManager()
	{

	};
	~DicoManager()
	{

	};

private:
	std::deque<std::string> mydico;

public:
	int addWord(std::string newWord)
	{
		mydico.push_back(newWord);
		return 0;
	};
	

};