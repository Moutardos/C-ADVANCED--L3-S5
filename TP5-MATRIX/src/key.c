#include "key.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



int generate_cle_generation(Bitkey* B, int d){
	int i;
	Bitkey* lstB;

	if (d == 0){
		return randomize_bitkey(B);
	}

	lstB = malloc(sizeof(Bitkey) * 8);

	if(NULL == lstB)
		return 1;

	for (i = 0; i < 8; i++){
		generate_cle_generation(&lstB[i], d-1);
	}
	
	qsort(lstB, 8, sizeof(Bitkey), cmpfunc);


	heritage_trois(B, lstB[0], lstB[1], lstB[2]);
	free(lstB);

	return 0;

}

int randomize_bitkey(Bitkey* B){
	int i;
	
	for (i = 0; i < NB_OCT; i++){

		B->values[i] = (rand() % 256);
	}

	return 0;
}

int heritage_trois(Bitkey* B, Bitkey k1, Bitkey k2, Bitkey k3){
	int i, j;
	int res;

	if (NULL == B)
		return 1;

	for (i = 0; i < NB_OCT; i++){
	/*	affiche_byte(k1.values[i]); printf("+\n");
		affiche_byte(k2.values[i]); printf("+\n");
		affiche_byte(k3.values[i]);
	*/
		for (j = 0; j < 8; j++){
			res = get_k_bit(k1.values[i], j) + get_k_bit(k2.values[i], j) + get_k_bit(k3.values[i], j);
			if (res >= 2)
				set_bit(&(B->values[i]), j);
			else
				unset_bit(&(B->values[i]), j);
		}
	/*printf("=\n");; 		affiche_byte(B->values[i]); 
	*/
	}
	return 0;
}

int cmpfunc (const void * a, const void * b) {
   float k1fit = fitness_key((Bitkey *) a);
   float k2fit = fitness_key((Bitkey *) b);

   return ((int) k2fit - k1fit);


}
int get_k_bit(uint8_t byte, int k){
	assert(k < 8);
	return (byte >>  k) & 1;
}

void set_bit(uint8_t * byte, int k){
	assert(k < 8);
	*byte = (*byte) | (1 << k);
}
void unset_bit(uint8_t * byte, int k){
	assert(k < 8);
	*byte = (*byte) & ~(1 << k);
}

void affiche_fitness(Bitkey* key){
	printf("Cette cle a une afinite de : %f\n", fitness_key(key));
}

void affiche_byte(uint8_t byte){
	int i;
	for (i = 0; i < 8; ++i)
	{
		printf("%hu ", get_k_bit(byte, i));
	}
	printf("\n");
}