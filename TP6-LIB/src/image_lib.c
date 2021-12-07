/* Loic Cozdenmat
   TP6C - Lib
*/

#include <math.h>
#include <stdlib.h>

#define IMAGE_SIZE 512
#define IMAGE_SIZE_X IMAGE_SIZE
#define IMAGE_SIZE_Y IMAGE_SIZE
#define PIXEL_SIZEOF 4

typedef unsigned char Img[IMAGE_SIZE_Y][IMAGE_SIZE_X][PIXEL_SIZEOF];

int max(unsigned char* array, int len){
	unsigned int i;
	unsigned char max = array[0];

	for (i = 1; i < len; i++){
		if (array[i] > max)
			max = array[i];
	}
	return max;

}
int min(unsigned char* array, int len){
	unsigned int i;
	unsigned char min = array[0];

	for (i = 1; i < len; i++){
		if (array[i] < min)
			min = array[i];
	}
	return min;

}

/* Niveaux de gris */
void niveaux_de_gris_moy(Img bitmap){
	unsigned int i, j;
	unsigned char value;

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++){
			value = (bitmap[j][i][0] + bitmap[j][i][1] + bitmap[j][i][2]) / 3;
			/* RGB dans l'ordre */
			bitmap[j][i][0] = value;
			bitmap[j][i][1] = value;
			bitmap[j][i][2] = value;
		}
}

void niveaux_de_gris_clarte(Img bitmap){
	unsigned int i,j;
	unsigned char value;

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++){
			value = (max(bitmap[j][i], PIXEL_SIZEOF - 1) + min(bitmap[j][i], PIXEL_SIZEOF - 1)) / 2;
			/* RGB dans l'ordre */
			bitmap[j][i][0] = value;
			bitmap[j][i][1] = value;
			bitmap[j][i][2] = value;
		}

}

void niveaux_de_gris_luminance(Img bitmap){
	unsigned int i,j;
	unsigned char value;

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++){
            value = (0.2126 * bitmap[j][i][0] + 0.7152 * bitmap[j][i][1]+0.0722 * bitmap[j][i][2]);
            /* RGB dans l'ordre */
            bitmap[j][i][0] = value;
            bitmap[j][i][1] = value;
            bitmap[j][i][2] = value; 
        }
}

/* Noir et blanc */
void seuillage_noir_blanc(Img bitmap){
	unsigned int i,j;
	unsigned char value;
    
    niveaux_de_gris_luminance(bitmap);

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++){
            if (bitmap[j][i][0] > 0.5)
                value = 1;
            else
            	value = 0;
            /* RGB dans l'ordre */
            bitmap[j][i][0] = value;
            bitmap[j][i][1] = value;
            bitmap[j][i][2] = value; 
		}
}


/*  Moyenne

	Stocke la nouvelle image (moyenne des deux) dans bitmapRes) */
void moyenne(Img bitmapRes, Img bitmap1, Img bitmap2){
	unsigned int i,j,k;
	unsigned char value;
    

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++)
			for(k = 0; k < PIXEL_SIZEOF; k++){
				value = (bitmap1[j][i][k] + bitmap2[j][i][k])/2;
				bitmapRes[j][i][k] = value;
			}
		
}

/** fonctions auxiliaire **/

int couleur_egal(unsigned char* couleur1, unsigned char* couleur2){
	unsigned int i;

	for (i = 0; i < 3; i++){
		if (!(couleur1[i] == couleur2[i]))
			return 0;
	}
	return 1;
}

void copie_couleur(unsigned char* dest, unsigned char* exped){
	unsigned int i;

	for (i = 0; i < 3; i++)
		dest[i] = exped[i];
}

void aux_remplacer_zone(Img bitmap, int i, int j, unsigned char* fill, unsigned char* newcouleur){

	if (couleur_egal(bitmap[j][i], fill)){

		copie_couleur(bitmap[j][i], newcouleur);

   		if (i > 0)
            aux_remplacer_zone(bitmap, i - 1, j, fill, newcouleur);
        if (j > 0)
            aux_remplacer_zone(bitmap, i, j - 1, fill, newcouleur);
        if (j < IMAGE_SIZE_Y - 1)
            aux_remplacer_zone(bitmap, i, j + 1, fill, newcouleur);
        if (i < IMAGE_SIZE_X - 1)
            aux_remplacer_zone(bitmap, i + 1, j, fill, newcouleur);
	}


}
/** **/

/* Zone contingüe */

void remplacer_zone(Img bitmap, int x, int y, unsigned char* newcouleur){
    unsigned char* c = 0;

    if (y < 0 || y >= IMAGE_SIZE_Y || x < 0 || x > IMAGE_SIZE_X){
    	return ;
    }
    
   	copie_couleur(c, bitmap[y][x]);

    if ( !(couleur_egal(newcouleur, c)) )
        aux_remplacer_zone(bitmap, x, y, c, newcouleur);

}

double new_pow(double value, int n){
	unsigned int count = n-1;
	double res = value;
	/* si n est pair, le pow est negatif */

    while(count){
    	res *= value;
    	count--;
    }
    return res;

}

/** Pow mauvais mais qui fait des trucs rigolos si utilise avec lumiere_millieu
double faux_pow(double value, int n){
	unsigned int count = n;
	double res = value;

    while(count){
    	res *= value;
    	count--;
    }
    return res;

}*/

/* Distance */

double distance(unsigned char* couleur1, unsigned char* couleur2) {
    return (sqrt(new_pow(abs((int) (couleur1[0] - couleur2[0])), 2) + new_pow(abs((int) (couleur1[1] - couleur2[1])), 2) + new_pow(abs((int) (couleur1[2] - couleur2[2])), 2)));
}

/** Autre **/ 

/*
void plus_firouge(Img bitmap){
	unsigned int i,j;
	unsigned char value;
    

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++){
		}
}*/


void degrade_rouge_bleu(Img bitmap){
    unsigned int i,j;
	float coef;

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++){
			coef = (i + j)/ 1024;
			bitmap[j][i][0] = (1 - coef) * bitmap[j][i][0];
			bitmap[j][i][1] = 0;
			bitmap[j][i][2] *= coef;
		}
}





void lumiere_milieu(Img bitmap){
	/* i et j ne doit pas etre unsigned car il va etre implique dans le calcul d'un nombre negatif */
	int i,j; 
	double coef;
    

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++){
            coef = new_pow(1 - ((new_pow(256 - i, 2) + new_pow(256 - j, 2)) / (2.0 * new_pow(256, 2))),10);	
            /* RGB dans l'ordre */
			bitmap[j][i][0] *= coef;
			bitmap[j][i][1] *= coef;
			bitmap[j][i][2] *= coef;

		}
}

void invert_color(Img bitmap){
  int i, j;

  for (i=0 ; i<IMAGE_SIZE_Y ; ++i){
    for (j=0 ; j<IMAGE_SIZE_X ; ++j){
      bitmap[i][j][0] = 255 - bitmap[i][j][0]; /* red */
      bitmap[i][j][1] = 255 - bitmap[i][j][1]; /* green */
      bitmap[i][j][2] = 255 - bitmap[i][j][2]; /* blue */
    }
  }
}


/* beaucoup de couleur ! */
void tres_vert(Img bitmap){
	unsigned int i,j;
	unsigned char value;
    

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++){
			value =  (3 + bitmap[j][i][1])/4;
			/* Vert */
			bitmap[j][i][1] = value;
		}
}

void plus_rouge(Img bitmap){
	unsigned int i,j;
	unsigned char value;
    

	for (j = 0; j < IMAGE_SIZE_Y; j++)
		for(i = 0; i < IMAGE_SIZE_X; i++){
			value = (1 + bitmap[j][i][0])/2;
			/* Rouge */
			bitmap[j][i][0] = value;
		}
}
/** **/
