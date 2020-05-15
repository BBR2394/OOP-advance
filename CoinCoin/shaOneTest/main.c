/*
* @Author: Baptiste Bertrand-Rapello
* @Date:   2020-04-22 22:02:47
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-24 18:45:30
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <openssl/sha.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	int c = 0;
	while (str[c] != '\0')
	{
		my_putchar(str[c]);
		c++;
	}
}


int main()
{
	unsigned char ibuf[] = "Hello";
	unsigned char *shaOne = NULL;
	unsigned char *shaBogdan = NULL;
	unsigned char bogdanToken[] = "i%u@>^J;\\%-k5T|v,w1Tp7=,=e|~`>a!-BCO-CC1.0-1587572545-0f0f0f";

	printf("token de bogdan\n");
	for (int i = 0; i < 60; i++)
	{
		printf("%c", bogdanToken[i]);
	}
	printf("\n");
	// bogdanToken[0] = 105; //i
	// bogdanToken[1] = 37; //%
	// bogdanToken[2] = 117; //u
	// bogdanToken[3] = 64; //@
	// bogdanToken[4] = 62; //>
	// bogdanToken[5] = 94; //^
	// //bogdanToken[6] = ; //J
	// //bogdanToken[7] = ; //;
	// bogdanToken[8] = 92; // 
	// bogdanToken[9] = 37; //%
	// bogdanToken[10] = 45; //-
	// //bogdanToken[11] = ; //k
	// //bogdanToken[12] = ; //5
	// //bogdanToken[13] = ; //T
	// bogdanToken[14] = 124; //|
	// //bogdanToken[15] = ; //v
	// bogdanToken[16] = 44; //,
	// //bogdanToken[17] = ; //w
	// //bogdanToken[18] = ; //1
	// //bogdanToken[19] = ; //T
	// //bogdanToken[20] = ; //p
	// //bogdanToken[21] = ; //7
	// //bogdanToken[22] = ; //=
	// bogdanToken[23] = 44; //,
	// //bogdanToken[24] = ; //
	// //bogdanToken[25] = ; //
	// //bogdanToken[26] = ; //
	// bogdanToken[27] = 124; //|
	// bogdanToken[28] = 126; //~
	// bogdanToken[29] = 96; //`
	// bogdanToken[30] = 62; //>
	// //bogdanToken[31] = ; //a
	//bogdanToken[32] = ; //!

	my_putstr("bonjour\n");

	char data[] = "Hello, world!";
	size_t length = strlen(data);

	unsigned char hash[SHA_DIGEST_LENGTH];
	SHA1(data, length, hash);

	//shaOne = malloc(20 * sizeof(unsigned char));

	shaOne = SHA1("Hello", (size_t)5, shaOne);
	shaBogdan = SHA1(bogdanToken, (size_t)60, shaBogdan);

	printf("%d\n%x\n", shaOne[0], shaOne[0]);
	printf("%d\n%x\n", hash[0], hash[0]);
	printf("%d\n%x\n", shaBogdan[0], shaBogdan[0]);

	printf("sha de bogdan\n");
	for (int i = 0; i < 20; i++)
	{
		printf("%x-", shaBogdan[i]);
	}
	printf("\n");

	return 0;
}