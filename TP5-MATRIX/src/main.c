/********************************************
 * Cozdenmat Loïc | L3 IGM ProgC            *
 *                                          *
 ********************************************/


#include <stdio.h>
#include <stdlib.h>
#include "code.h"
#include "key.h"
int main() {
    int i = 0;
    Bitkey B;
    srand(time(NULL));

    do
    {   printf("generation %d\n", i);
        if (generate_cle_generation(&B, i))
            return 1;
        printf("%2f\n", fitness_key(&B));
        enter_the_matrix(&B);
        i++;
    } while (fitness_key(&B) < 100);

    affiche_fitness(&B);
    return 0;
}
