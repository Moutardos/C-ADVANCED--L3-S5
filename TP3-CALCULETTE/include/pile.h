#ifndef PILE

#define PILE


typedef struct element
{
    int valeur;
    struct element* suivant;
}Element;

typedef struct pile
{
    Element* premier;
}Pile;

Pile* initalise_pile();

int empile(Pile* pile, int token);

int pop(Pile *pile);

void affiche_pile(Pile* pile);

#endif