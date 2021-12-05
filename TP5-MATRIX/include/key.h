#ifndef KEY
#define KEY

#include "code.h"



int generate_cle_generation(Bitkey* B, int d);

/* Initialise les valeurs de la cles avec des octets aleatoire
*/
int randomize_bitkey(Bitkey* B);



/* fonction debug, print la fitness de la cle
*/
void affiche_fitness(Bitkey* key);

/* Fait un enfant des trois cles en programation genetique
*/
int heritage_trois(Bitkey* B, Bitkey k1, Bitkey k2, Bitkey k3);

/* Donne la valeur du kieme bit
*/
int get_k_bit(uint8_t byte, int k);

/* Modifie le kieme bit en 1
*/
void set_bit(uint8_t * byte, int k);

/* Modifie le kieme bit en 0
*/
void unset_bit(uint8_t * byte, int k);

/* fonction debug, print l'octet
*/
void affiche_byte(uint8_t byte);

/* fonction annexe pour qsort, permettant de trier une liste de key selon
   la fitness
*/
int cmpfunc (const void * a, const void * b);
#endif