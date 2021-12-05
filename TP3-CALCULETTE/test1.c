#include <stdio.h>
#include <stdlib.h>
int foo(){
	char* end;
	int value;
	char* chaine = "+";
	value = strtol("+",&end,10);
	if (end == chaine)
		return chaine[0];
	else
		return  value;


}
 int main(int argc, char const *argv[])

{
	char test = '+';
	int test2 = (int) test;
	char test3 = (char) test2;
	char resfoo = foo();
	if (resfoo == '+')
		printf("ca marche ptn"); 
	else
		printf("%c\n", resfoo);
	return 0;
}