#ifndef JEU
#define JEU

#include "plateau.h"

/* Signale la fin de partie si tout les carres sont a leur places */
int is_it_over(Plateau* p);

/* Lance la partie avec l'état du plateau indiqué dans p*/
int game(Plateau* p, const char* imagepath);


#endif