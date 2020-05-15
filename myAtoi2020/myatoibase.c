/*
* @Author: Baptiste
* @Date:   2020-04-06 14:19:28
* @Last Modified by:   Baptiste Bertrand-Rapello
* @Last Modified time: 2020-04-14 13:31:41
*/

int my_strlen_const(const char *str)
{
	int c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return c;
}

int get_encode(char the_char, const char *code)
{
	int c = 0;
	while (code[c] != '\0' && the_char != code[c])
	{
		c++;
	}
	if (code[c] == '\0')
		return (-1);
	return c;
}

int power_base(int power, int base)
{
	int c = 1;
	int ten = 1;
	while (c < power)
	{
		ten *= base;
		c++;
	}
	return ten;
}

int check_is_negative(const char *nptr)
{
	if (nptr[0] == '-')
		return 1;
	return 0;
}

int myatoibase(const char *nptr, const int base) 
{
	if (nptr == 0)
		return 0;
	int size = my_strlen_const(nptr);
	int c = 0;
	int char_code = 0;
	int res = 0;
	int is_neg = check_is_negative(nptr);
	if (base < 2 || base > 37)
		return -2;
	if (is_neg == 1)
		c++;
	while(nptr[c] != '\0')
	{
		char_code = get_encode(nptr[c], "0123456789abcdefghijklmnopqrstuvwxyz!");
		if (char_code == -1 || char_code > base)
			return -1;
		res = (char_code * power_base(size-c, base)) + res;
		c += 1;
	}
	if (is_neg == 1)
		res *= -1;
	printf("*>le Resultat est : %d\n", res);
	return res;
}
