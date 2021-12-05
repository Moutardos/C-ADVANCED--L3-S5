#include "pile.h"
#include <stdlib.h>
#include <stdio.h>


Pile* initalise_pile(){
	Pile* new_pile = malloc(sizeof(Pile*));
	return new_pile;
}

int empile(Pile* pile, int token){
	Element *nouveau = malloc(sizeof(Element*));
	if (nouveau == NULL)
		return 0;
	nouveau->valeur = token;
	nouveau->suivant = pile->premier;
	pile->premier = nouveau;

	return 1;
}

int pop(Pile *pile){

	Element* to_remove;
	int removed;

	if (pile == NULL)
		return 0; /* a voir */

	to_remove = pile->premier;
	removed = to_remove->valeur;

	if (to_remove != NULL)
		pile->premier = pile->premier->suivant;

	removed = to_remove->valeur;
	free(to_remove);
	return removed;
}


void affiche_pile(Pile *pile){
	int etape = 0;
	Element* etape_actuel = pile->premier;

	while(etape_actuel != NULL){
		printf("Etape %d : Valeur : %d\n",etape,etape_actuel->valeur);
		etape++;
		etape_actuel = etape_actuel->suivant;
	}
}