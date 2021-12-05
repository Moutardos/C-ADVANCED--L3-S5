#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "traitement.h"
#include <string.h>

char* str = NULL;

int get_token(){
	int token;
	if (str == NULL){
		str = readline("give me something to work with. /h for help\n");
		token = strtok(str, " /t/n");
	}
	else
		token = strtok(NULL, " /t/n");


	printf("%s", token);

	return token;

}

