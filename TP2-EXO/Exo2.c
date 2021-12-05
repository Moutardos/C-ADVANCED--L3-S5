/***************************************************************
* L2INFO | G1 TP2 C  | Exo2                                    *        
* Par Loïc Cozdenmat | loic.cozdenmat@edu.univ-eiffel.fr       *
*                                                              *
* Crée le               : 12/10/2021 18:13                     *
****************************************************************/



#include <stdio.h>


/* Valeur stationaire around 15.403683 */
void affiche_suite_float(int n){
    float result = 0;
    int i;
    for (i = 1; i <= n; i++){
        result+= (float) 1/i;
        if (i%1000 == 0)
            printf("%d : %f\n",i,result );
    }
}


void affiche_suite_double(int n){
    double result = 0;
    int i;
    for (i = 1; i <= n; i++){
        result+= (double) 1/i;
        if (i%500 == 0)
            printf("%d : %f\n",i,result );
    }
}
int main(int argc, char const *argv[]){
    printf("Bonsoir, on va afficher tout ca en float\n");
    affiche_suite_float(10000000);
    printf("Maintenant, en double\n");
    affiche_suite_double(1000000000);
    return 0;
}
