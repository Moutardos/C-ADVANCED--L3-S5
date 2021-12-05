#ifndef PLATEAU
#define PLATEAU
#define NB_COL 4
#define NB_LIG 4


typedef struct carre{
	int lig; /* ligne originale dans l'image */
	int col;
}Carre, *pt_Carre;

typedef struct plateau {
	Carre bloc[NB_COL][NB_LIG];
	Carre vide;
}Plateau;

/* Initialise le plateau de longueur et hauteur 4 (à free avant de terminer le prog!)
*/
Plateau* initialisation_plateau();

/* Renvoie un carré de position i,j
*/
Carre create_carre(int i, int j);

/* Insère dans carre_tomove (Un tableau qui pointe vers 4 carrés) les carrés qui sont capable de
   se déplacer dans la case qui est actuellement vide dans le plateau p (sinon insère NULL).
   [0] case à gauche de la case vide
   [1]      à droite
   [2]      en bas
   [3]      en haut
*/
int carre_abletomove(Plateau* p, pt_Carre* carre_tomove);

/* Renvoie true (1) si la case est comprise dans les limites du taquin, false (0) sinon
*/

int carre_dans_abletomove(Carre carre, pt_Carre* carre_tomove, int len);

void free_abletomove(pt_Carre* carre_tomove, int len);

int position_islegal(int lig, int col);

void deplace_carre_dans_vide(Plateau* p,Carre carre);


void shuffle(Plateau* p, int n);
int carre_to_number(Carre carre);
void affiche_plateau_text(Plateau* p);
#endif