#include "test.h"
#include "jeu.h"
#include "menu.h"
#include "affichage.h"
int main(int argc, char* argv[]){
	Plateau* p = initialisation_plateau();
	/*if( !test()){
		return 1;
	}*/
	init_mlv();
	shuffle(p,120);
	game(p,"image/dog.png");
	MLV_free_window("Taquin");
	return 0;
}
