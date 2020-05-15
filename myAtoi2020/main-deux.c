/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-09 20:07:57
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-14 16:01:40
*/

#include <stdlib.h>
#include <stdio.h>


int myatoibase(const char *nptr, const int base) ;

int test_my_atoi()
{
	if (myatoibase("42", 10) != 42)
		return -1;
	if (myatoibase("a", 16) != 10)
		return -2;
	if (myatoibase("12", 10) != 12)
		return -3;
	if (myatoibase("-12", 10) != -12)
		return -4;
	if (myatoibase("!", 37) != 36)
		return -5;
	if (myatoibase("!", 42) != -2)
		return -6;
	if (myatoibase("+", 42) != -2)
		return -7;
	if (myatoibase("a", 13) != 10)
		return -8;
	if (myatoibase("b", 13) != 11)
		return -9;
	if (myatoibase("c", 13) != 12)
		return -10;
	if (myatoibase("-c", 13) != -12)
		return -11;
	if (myatoibase("-aac", 13) != -1832)
		return -11;
	if (myatoibase("f", 16) != 15)
		return -11;
	if (myatoibase("f", 10) != -1)
		return -12;
	if (myatoibase(0, 10) != 0)
		return -13;
	if (myatoibase("z", 35) != 35)
		return -13;
	if (myatoibase("zf2345", 35) != 1860864570)
		return -14;
	if (myatoibase("zf2345*", 35) != -1)
		return -15;
	if (myatoibase("--4", 10) != -1)
		return -16;
	if (myatoibase("101010", 2) != 42)
		return -42;
	return 0;

}

int main(int ac, char **av)
{
	printf("Atoi res : %d\n", myatoibase("42", 10));
	printf("Atoi res : %d\n", myatoibase("101010", 2));
	printf("Atoi res : %d\n", myatoibase("", 1));
	//printf("my strlen %d\n", my_strlen("hello\0"));
	//printf("is encode corect ? : %d\n", get_encode('q', "0123456789abcdefghijklmnopqrstuvwxyz!"));
	//printf("is encode corect ? : %d\n", get_encode('+', "0123456789abcdefghijklmnopqrstuvwxyz!"));
	
	printf("Resultats des test : %d\n", test_my_atoi());

	printf("Resultat si chaine vide : %d\n, ", myatoibase("", 10));

	printf("Resultats du null : %d\n", myatoibase(NULL, 10));
	printf("Resultats du vers grand nombre : %d\n", myatoibase("z", 36));
	printf("Resultats du vers grand nombre : %d\n", myatoibase("zz", 36));
	printf("Resultats du vers grand nombre : %d\n", myatoibase("zzz", 36));
	printf("Resultats du vers grand nombre : %d\n", myatoibase("zzzz", 36));
	printf("Resultats du vers grand nombre : %d\n", myatoibase("zzzzz", 36));
	printf("Resultats du vers grand nombre : %d\n", myatoibase("zzzzzz", 36));
	printf("Resultats du vers grand nombre NEGATIF : %d\n", myatoibase("-z", 36));
	printf("Resultats du vers grand nombre NEGATIF : %d\n", myatoibase("-zz", 36));
	printf("Resultats du vers grand nombre NEGATIF : %d\n", myatoibase("-zzz", 36));
	printf("Resultats du vers grand nombre NEGATIF : %d\n", myatoibase("-zzzz", 36));
	printf("Resultats du vers grand nombre NEGATIF : %d\n", myatoibase("-zzzzz", 36));
	printf("Resultats du vers grand nombre NEGATIF : %d\n", myatoibase("-zzzzzz", 36));
	return (0);
}