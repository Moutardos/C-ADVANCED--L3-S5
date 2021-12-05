/***************************************************************
* L2INFO | G1 TP2 C    | Exo3 Mirroir                          *        
* Par Loïc Cozdenmat | loic.cozdenmat@edu.univ-eiffel.fr       *
*                                                              *
* Crée le               : 05/10/2021 13:47                     *
****************************************************************/


#include <stdio.h>
#include <stdlib.h>

#include <string.h>

void miroir(char* str){
	char tmp;
	int i, j;

	for(i = 0, j = strlen(str) - 1;i < j; i++, j--){
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}



int main(int argc, char const *argv[])
{
	int i;
	char* cpy = NULL;
	for (i = 1; i < argc; i++){

		cpy = (char *) malloc(sizeof(char) * strlen(argv[i]));
		if (cpy == NULL){
			printf("ERREUR D'ALLOCUTION");
			break;
		}
		strcpy(cpy, argv[i]);

		miroir(cpy);
		printf("%s\n", cpy);
		free(cpy);
	}
	return 0;
}
