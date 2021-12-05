/***************************************************************
 * L2INFO | G1 TP3 PROGC | "Calculette" | main.c               *        
 * Par Loïc Cozdenmat | loic.cozdenmat@etud.univ-eiffel.fr     *
 *                                                             *
 * Crée le               : 19/10/2021 10:00                    *
 *                                                             *
 ***************************************************************
*/

#include "test.h"
#include "traitement.h"
 #include <stdio.h>

int main(int argc, char* arg[]){

	if(!test()){
		printf("ERREUR TEST");
		return 1;
	}
	return 0;
}