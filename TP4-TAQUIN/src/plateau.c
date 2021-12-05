#include "plateau.h"
#include <stdlib.h>
#include <assert.h>
 
Carre create_carre(int i, int j){
	Carre new_carre;
	new_carre.lig = i;
	new_carre.col = j;
	return new_carre;
}

Plateau* initialisation_plateau(){
	int i, j;
	Plateau* P = malloc(sizeof(Plateau));

	if (NULL == P)
		return NULL;
	

	for (i = 0; i < NB_LIG; i++){
		for (j = 0; j < NB_COL; j++){
			((P->bloc)[i][j]) = create_carre(i,j);
		}
	}
	P->vide = create_carre(NB_LIG -1, NB_COL -1);
	return P;
}

int carre_abletomove(Plateau* p, pt_Carre* carre_tomove){
	int coordi, coordj, i;
	int addi =1, addj = 0, sign = 1, nb_carre = 0;
	assert(NULL != carre_tomove);
	/* Verfication si les voisins de vide sont légaux */

	for (i = 0; i < 4; i++)
	{
		addi ^= 1;
		addj ^= 1;
		if (i == 2)
			sign = -1;

		coordi = p->vide.lig + addi * sign;
		coordj = p->vide.col + addj * sign;

		if (position_islegal(coordi, coordj)){
			carre_tomove[nb_carre] = (pt_Carre) malloc(sizeof(Carre));
			*carre_tomove[nb_carre] = create_carre(coordi, coordj);

		    nb_carre++;

		}
	}
	/* Renvoie le nombre de carre qui sont capable de bouger */
	return nb_carre;
}

int carre_dans_abletomove(Carre carre, pt_Carre* carre_tomove, int len){
	int i;
	for (i = 0; i < len; i++){
		if (carre.col == carre_tomove[i]->col && carre.lig == carre_tomove[i]->lig)
			return 1;
	}
	return 0;
}

void deplace_carre_dans_vide(Plateau* p, Carre carre){
	p->bloc[p->vide.lig][p->vide.col] = p->bloc[carre.lig][carre.col];
	Carre tmp = create_carre(carre.lig, carre.col);
	p->bloc[carre.lig][carre.col] = create_carre(3,3);
	p->vide = tmp;
}


int position_islegal(int lig, int col){
	return lig >= 0 && col >= 0 && lig < NB_LIG && col < NB_COL;
}

void free_abletomove(pt_Carre* carre_tomove, int len){
	int i;
	if (NULL == carre_tomove)
		return;
	for (i = 0; i < len; i++)
		free(carre_tomove[i]);
}

void shuffle(Plateau* p, int n){
	int i;
	int len;
	int depl;
	pt_Carre move_legal[4];

	srand(time(NULL));

	for (i = 0; i < n; i++){
		len = carre_abletomove(p, move_legal);
		depl = rand() % len;
		deplace_carre_dans_vide(p, *move_legal[depl]); 
		free_abletomove(move_legal,len);
	}
}
int carre_to_number(Carre carre){
	return carre.lig*4 + carre.col ;
}


/* Fonctions debug */
void affiche_carre(Carre carre){
	printf("%d  %d\n",carre.lig, carre.col);
}

void affiche_plateau_text(Plateau* p){
	int i, j, touche;

	for(i = 0; i < 4;i++){
		for (j = 0; j < 4; j++){
			printf("%d ", carre_to_number(p->bloc[i][j]));
		}
		printf("\n");
	}
	for(i = 0; i < 4;i++){
		for (j = 0; j < 4; j++){
			printf("%d -> %d",carre_to_number(create_carre(i,j)),carre_to_number(p->bloc[i][j]));
			if (p->vide.lig == i && p->vide.col == j){
				printf("  VIDE");
			}
			printf("\n");
		}
	}


}
