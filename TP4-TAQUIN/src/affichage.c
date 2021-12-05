#include "affichage.h"


/* On stock le background ici pour eviter de le load a chaque fois ou le trimballer dans les autres fonctions */
MLV_Image* background;

void init_mlv(){
	int x,y; 
	MLV_create_window("Taquin", "Taquin", W, H);
	background = MLV_load_image("image/bg.png");
}
void free_mlv(){
	MLV_free_window("Taquin");
}

int load_images(const char* path, MLV_Image** image_carres){
	MLV_Image* fullimage = MLV_load_image(path);
	int i, j, n = 0;

	if( ! fullimage ){
    	fprintf(stderr, "It was impossible to load the file %s.\n",path);
        return 0;
    }

	MLV_resize_image(fullimage,RESOLUTION,RESOLUTION );
	MLV_draw_filled_rectangle_on_image(3*(CASE+1), 3*(CASE+1), CASE, CASE, MLV_COLOR_BLACK, fullimage);
	for(i = 0; i < 4; i++){
	    for(j = 0; j < 4; j++){
	    	image_carres[n] = MLV_copy_partial_image( fullimage,j*(CASE+1), i*(CASE+1), CASE, CASE);
	    	n++;
	    }
	}
	return 1;
    }

void affiche_plateau(Plateau* p, MLV_Image** taquin){
	int i,  j, touche;
	int n = 0;
	MLV_clear_window(MLV_COLOR_BLACK);

	/* bg */
	MLV_draw_image(background, 0, 0);

 

	for(i = 0; i < 4;i++){
		for (j = 0; j < 4; j++){
			n = carre_to_number(p->bloc[i][j]);
			MLV_draw_image(taquin[n],DEBUTX +j*(CASE+1), DEBUTY + i*(CASE+1));
			MLV_actualise_window();
	
	

		}
	}
}

void draw_textbox(const char* text, int x, int y){
	MLV_draw_filled_rectangle(x,y,TEXTBOXW,TEXTBOXH,MLV_COLOR_WHITE);
	MLV_draw_text(x + TEXTBOXW/2 - strlen(text), y + TEXTBOXH/2, text, MLV_COLOR_BLACK);
	MLV_actualise_window();
}