#include <stdio.h>

int base10(char number_in_base_2[]);
//The function is declared in base10.asm
//Multiple numbers in base 2 are read from the keyboard. Display these numbers in the base 16.

int main()
{
	char number_in_base_2[65];
	while (1 > 0)
    {
		printf("! we assume that the strings read from keyboard are correct!(we do not validate)\n");
		scanf("%s", number_in_base_2);//here we read the string
		int a = base10(number_in_base_2);//we convert the number in base 10 using asm module
		printf("%x\n", a);//we print the number n hexa
	}
    return 0;
}
