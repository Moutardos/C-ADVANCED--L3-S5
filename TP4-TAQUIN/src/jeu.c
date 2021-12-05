#include "jeu.h"
#include "affichage.h"
#include "interact.h"
#include "menu.h"

int game(Plateau* p, const char* imagepath){
	int i;
	int clicx, clicy, action;
	MLV_Image* taquin[16];
	
	if (!load_images(imagepath,taquin))
		return 0;
	
	affiche_plateau(p, taquin);
	while (! is_it_over(p)) {

		
		/* Attend une action valide du joueur (ici un clic ou echap)*/
		while (! (action = wait_and_treat_event(&clicx, &clicy)) );


		if (action == 1){
			choose_carre(p, clicx, clicy);
			affiche_plateau(p, taquin);
		}
		else if (action == 2){ /* pause */
			if ((action = back_to_menu())) /* Si le joueur a choisis de revenir dans le menu principal ou d'arreter*/
				return action;
			affiche_plateau(p, taquin);

		}
	
	}
	return gameover();
}

int is_it_over(Plateau* p){
	int i, j;

	for (i = 0; i < NB_LIG; i++){
		for (j = 0; j < NB_LIG; j++){
			if (p->bloc[i][j].lig != i || p->bloc[i][j].col != j)
				return 0;
		}
	}


	return 1;
}