#include <stdio.h>
int main( int argc,char* argv[]){

    /* DECLARATION */
    FILE* fres,* f1,* f2;
    FILE* farr[2];
    char c;
    unsigned int i;

    /** L'executable + les deux filenames **/
    if (argc != 3 ){
        printf("Please put the name of the 2 files you want to concatenate\n");
        return 1;
    }

    f1 = fopen(argv[1],"r");
    f2 = fopen(argv[2],"r"); 

    if (f1 == NULL || f2 == NULL){
        fprintf(stderr, "Couldn't open one of the file, sorry");
        return 1;
    }
    fres = fopen("result","w");
    if (fres == NULL){
        fprintf(stderr, "Error with the file creation for the result, sorry");
        return 2;
    }

    farr[0] = f1;
    farr[1] = f2;
    for (i = 0; i < 2; i++){
        while ((c = fgetc(farr[i])) != EOF){
            if (printf("%c", c) != 1){
                fprintf(stderr, "Erreur lors de l'affichage du caractere dans fichier %d",i);
            }
            fprintf(fres, "%c",c);
        } 
    }
    return 0;
}
