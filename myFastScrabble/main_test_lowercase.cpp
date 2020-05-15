
#include <iostream>

char setLowerCase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}

int main()
{
	std::cout << "test :" << std::endl;
	std::cout << setLowerCase('a') << std::endl;
	std::cout << setLowerCase('z') << std::endl;
	std::cout << setLowerCase('A') << std::endl;
	std::cout << setLowerCase('Z') << std::endl;
	std::cout << setLowerCase('1') << std::endl;
	std::cout << setLowerCase('2') << std::endl;
	std::cout << setLowerCase('*') << std::endl;

}