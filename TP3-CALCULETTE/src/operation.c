#include "operation.h"

int calcule(Pile* pile, Operators ope){
	int rvalue = pop(pile);
	int lvalue = pop(pile);

	switch(ope){
		case PLUS: return lvalue + rvalue;
		case MINUS: return lvalue + rvalue;
		case DIVIDE: return lvalue / rvalue;
		case MULTIPLY: return lvalue * rvalue;
	}
}