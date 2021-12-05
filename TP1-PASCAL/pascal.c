#include <stdlib.h>
#include <stdio.h>


/* Prend deux entiers p,n et renvoie la valeur p parmis n
   Complexite : O(n^2) 
*/
int binomial(int n, int p){
	if ( (n == p) || (p == 0))
        return 1;
    if (n > 0 && p > 0 && p < n)
        return (binomial(n - 1, p) + binomial(n - 1, p - 1));
    return 0;
}



/* Prend deux entiers p,n et renvoie la valeur p parmis n.
	Utilise l'allocation de memoire.
   Complexite : O(n^2) 
*/
int binomial_tab(int n, int p){
	int *tab, i, res, j;

	if (n < 0 || p > n || p < 0)
		return 0;
	tab = (int*) malloc(sizeof(int) * (n + 1));
	if (tab == NULL)
		return -1; /* Erreur d'allocution */

	/* Initalisation du tableau */
	for(i = 0; i <= n; i++)
		tab[i] = 1;
	for (i = 0; i < n; i++){
		for (j = i; j > 0; j--)
			tab[j] += tab[j - 1];
	}
	res = tab[p];
	free(tab);
	return res;


}

int main(void){
	printf("9 parmis 11 = %d",binomial_tab(11,9));
	return 0;
}
