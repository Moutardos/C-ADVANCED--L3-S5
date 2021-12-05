#ifndef INTERACT
#define INTERACT

#include "plateau.h"

int choose_carre(Plateau* p, int clicx, int clicy);
int wait_and_treat_event(int* clicx, int* clicy);
int coord_dans_plateau(int x, int y);
Carre coord_to_carre(int x,int y);


#endif