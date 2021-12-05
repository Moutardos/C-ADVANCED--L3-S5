#include "test.h"
#include "operation.h"
#include "pile.h"
#include <stddef.h>
#include <stdio.h>

int test(){
    if (!test_pile())
        return 0;
    if (!test_operation())
    	return 0;
    return 1;
}

int test_pile(){

	Pile* pile = initalise_pile();
	empile(pile,1);
	empile(pile,5);

	if (pile->premier->valeur != 5){
		printf("ERROR TEST PILE: EMPILE WRONG VALUE\n");
		return 0;
	}

	empile(pile,1434);

	if (pop(pile) != 1434){
		printf("ERROR TEST PILE: POP RETURN WRONG VALUE\n");
		return 0;
	}

	return 1;
}
int test_operation(){
	Pile* pile = initalise_pile();
	int total = 0;

	empile(pile,1);
	empile(pile,5);
	total += calcule(pile,PLUS);
	empile(pile,25);
	empile(pile,5);
	total += calcule(pile,DIVIDE);
	empile(pile,25);
	empile(pile,4);
	total += calcule(pile,MULTIPLY);

	if (total != 111){
		printf("ERROR TEST OPERATION: WRONG VALUE WHILE CALCULATING\n");
		return 0;
	}


}