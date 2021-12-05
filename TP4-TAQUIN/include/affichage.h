#ifndef AFFICHAGE
#define AFFICHAGE

#include <MLV/MLV_all.h>
#include "plateau.h"
#define W 1280
#define H 924
#define RESOLUTION 720
#define CASE 179
#define TEXTBOXH 50
#define TEXTBOXW 300

#define DEBUTX W/2 - RESOLUTION/2
#define DEBUTY H/2 - RESOLUTION/2 	/* Fait en sorte que l'image est centree (que le millieu de du taquin soit le millieu de l'image) */


/* Initialise les parametres graphique de MLV
*/
void init_mlv();

/* Prend l'image dans le path, et la divise en 9 MLV_Image stockées dans image_carres
*/
int load_images(const char* path, MLV_Image** image_carres);

/* Affiche les carres dans la position qui est stockee dans plateau.
   Exemple : la case 0,0 de plateau->bloc pointe vers un carre 3,3 : on met la premiere case dans 
   le dernier emplacement 
*/
void affiche_plateau(Plateau* p,MLV_Image** taquin);

void draw_textbox(const char* text, int x, int y);
#endif