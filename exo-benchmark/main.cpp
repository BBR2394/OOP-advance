
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <chrono>



int main()
{
	std::vector<int> vect;
	std::list<int> lst;
	int limit = 1000000;
	std::chrono::time_point<std::chrono::system_clock> start, end, startlst, endlst, startpop, endpop, startlstpop, endlstpop;
	std::cout << "bonjour" << std::endl;

	start = std::chrono::system_clock::now();
	for (int i = 0; i < limit; i++)
	{
		vect.push_back(42);
	}
	end = std::chrono::system_clock::now();
	startlst = std::chrono::system_clock::now();

	for (int i = 0; i < limit; i++)
	{
		lst.push_back(42);
	}
	endlst = std::chrono::system_clock::now();


	using namespace std::chrono;
	milliseconds ms = duration_cast< milliseconds >(end-start);
	milliseconds mslst = duration_cast< milliseconds >(end-start);
	std::cout << "ms: " << ms.count() << "\nms list :" << mslst.count() << std::endl;


	startlstpop = std::chrono::system_clock::now();

	for (int i = 0; i < limit; i++)
	{
		lst.pop_front();
	}
	endlstpop = std::chrono::system_clock::now();
	startpop = std::chrono::system_clock::now();
	for (int i = 0; i < limit; i++)
	{
		vect.erase(vect.begin(), vect.begin()+1);
	}
	endpop = std::chrono::system_clock::now();


	milliseconds mspop = duration_cast< milliseconds >(endpop-startpop);
	milliseconds mslstpop = duration_cast< milliseconds >(endpop-startpop);
	std::cout << "ms: " << mspop.count() << "\nms list :" << mslstpop.count() << std::endl;
	return 0;
}