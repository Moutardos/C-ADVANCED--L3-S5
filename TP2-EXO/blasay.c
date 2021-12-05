/***************************************************************
* L2INFO | G1 TP2 C  | blasay                                  *        
* Par Loïc Cozdenmat | loic.cozdenmat@edu.univ-eiffel.fr       *
*                                                              *
* Crée le               : 12/10/2021 18:33                     *
****************************************************************/


#include <stdio.h>

void print_espace(int n){
    int i;
    for(i = 0; i < n; i ++)
        printf(" ");
}

int print_bulle(int nb_mots,char const *mots[]){
    int i, len = 0;

    print_espace(9);
    for (i = 1; i < nb_mots; i++)
       len += printf("%s ", mots[i] );
   printf("\n");
   print_espace(8);
    for (i = 0; i < len; i++){
        if (i == len/2)
            printf("v");
        else
            printf("-");
    }
    printf("\n");
    return len;
}

void print_kermit(int len_bulle){
    printf(" (+)(+)");
    print_espace(len_bulle/2);
    printf("/\n/      \\ - \n\\ -==- / \n \\    /\n<\\/\\/\\/> \n/      \\\n");

}
int main(int argc, char const *argv[]){
    int len;
    len = print_bulle(argc, argv);
    print_kermit(len);
    return 0;
}
/* 
         test1234
        ----v----   8 espace avant le debut
 (+)(+)    /               
/      \ - 
\ -==- / 
 \    / 
<\/\/\/> 
/      \
copyright : http://www.kermitinspiration.com/KermitPics/kermit_ascii.txt
*/