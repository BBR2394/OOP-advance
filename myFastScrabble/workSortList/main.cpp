
#include <iostream>
#include <list>
#include <string>
#include <algorithm>

char set_lower_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}

bool my_comparaison_function(const std::string& first, const std::string& second)
{
	int i = 0;
	char a = 0;
	char b = 0;
	while (i < first.length() && i < second.length())
	{
		a = set_lower_case(first[i]);
		b = set_lower_case(second[i]);
		if (a < b)
			return true;
		else if (a > b)
			return false;
		i++;
	}
	return first.length() < second.length();
}

int main()
{
	std::list<std::string> lst;
	
	//levantin
	//nivelant
	lst.push_front("Valentin");
	lst.push_front("levantin");
	lst.push_front("nivelant");
	
	
	//std::sort(lst.begin(), lst.end());
	lst.sort(my_comparaison_function);

	std::cout << lst.front() << std::endl;
	lst.pop_front();
	std::cout << lst.front() << std::endl;
	lst.pop_front();
	std::cout << lst.front() << std::endl;
	lst.pop_front();
	return 0;
}