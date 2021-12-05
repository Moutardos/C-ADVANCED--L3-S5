#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "affichage.h"
#include "test.h"
#include "plateau.h"
#include "interact.h"
#include "jeu.h"
#include "menu.h"
int test(){
	if (!test_plateau() || !test_graph()){
		return 0;
	}

	return 1;
}

int test_plateau(){
	int len;
	Plateau* p;
	pt_Carre res[4];
	p = initialisation_plateau();
	len  = carre_abletomove(p,res);

	if (res[0]->lig != 3 && res[0]->col != 2){
		printf("DEBUG :\nERROR ON PLATEAU.C | carre_abletomove()\nres[0]\n)");
		free_abletomove(res, len);
		free(p);
		return 0;
	}
	else if (res[1]->lig != 2 && res[1]->col != 3){
		printf("DEBUG :\nERROR ON PLATEAU.C | carre_abletomove(\nres[3]\n)");
		free(p);	
		free_abletomove(res, len);
		return 0;
	}
	deplace_carre_dans_vide(p,*res[1]);
	free_abletomove(res, len);
	if (p->vide.lig != 2 && p->vide.col != 3){
		printf("DEBUG :\nERROR ON PLATEAU.C |\ndeplace_carre_dans_vide()\n)");
		free(p);
		return 0;
	}
	free(p);
	return 1;
}

int test_graph(){
	int i, j, n;
	int touche;
	MLV_Image* taquin[16];
	Plateau* p= initialisation_plateau();

	init_mlv();

	if (!load_images("image/chat.jpg",taquin))
		return 0;

	for(i = 0; i < 3; i++){
		shuffle(p,120);
		affiche_plateau(p, taquin);
		back_to_menu();
	}
	MLV_free_window("Taquin");

	return 1;

}

int test_jeu(){

	Plateau* p= initialisation_plateau();
	init_mlv();

	shuffle(p, 120);
	game(p,"image/chat.jpg");
		MLV_free_window("Taquin");

	return 1;
}