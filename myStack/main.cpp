#include <iostream>
#include "mychainedstack.h"
using namespace std;

// Main de test simple
int main()
{
	// Banner
 	cout << "Mychainedstack - test" << endl;

	// Instanciation de la classe dérivée
	Mychainedstack _cs;

	// Reference à la baseclass (polymorphisme)
	Mystack& cs = _cs; 
	
	// Push
	cs.push(1);
	cs.push(2);
	cs.push(3);

	// Pop
	int p;
	p = cs.pop();
	p = cs.pop();
	cout << p << endl;	

	// Opérateur %
	int q;
	q = cs % 2;
	cout << "q = " << q << endl;

	// Clear
	cs.clear();

  	return 0;
}
