/***************************************************************
* L2INFO | G1 TP2 C  | Exo1                                    *        
* Par Loïc Cozdenmat | loic.cozdenmat@edu.univ-eiffel.fr       *
*                                                              *
* Crée le               : 5/10/2021 16:53                      *
****************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/* Affiche les nombres entre n et m si ils respectent la propriété rigolote
*/
int affiche_rigolote(int n, int m){
    int i, chiffre, sum;
    for (i = n; i <= m; i++){
        
        sum = 0;
        chiffre = i;

        while(chiffre){
            sum += pow(chiffre%10,3);
            chiffre /= 10;
            if (sum > i)
                break;

        }
        if (sum == i){
            printf("%d fonctionne !!!!!!\n",sum);
        }

    }

    return 1;
}
int main(int argc, char const *argv[])
{
    affiche_rigolote(0,500);
    return 0;
}
