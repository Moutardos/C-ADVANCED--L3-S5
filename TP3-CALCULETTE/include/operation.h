#ifndef OPERATION
#define OPERATION

#include "pile.h"

typedef enum operators{
	PLUS, MINUS,
	DIVIDE, MULTIPLY
}Operators;

int calcule(Pile* pile, Operators ope);

#endif