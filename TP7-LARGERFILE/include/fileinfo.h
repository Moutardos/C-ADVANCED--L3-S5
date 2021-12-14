#ifndef FILEINFO
#define FILEINFO

#define MAXFILES 10

/* Stucture contenant les informations du fichier */
typedef struct  fileinfo{
    long int    size;
    char        *path;
}Fileinfo;



/*  Fonction utiliser par qsort pour trier par taille  */
int file_cmp(const void *a, const void *b);

/* Désalloue la mémoire accordés au files dans le tableau */
void free_files(Fileinfo* tab_files, int len);

/* Print les fichiers dans le tableau*/
void affiche_files(Fileinfo* tab_files, int len);

/* Ajoute un fichier dans le tableau, retourne 0 si il n'y a pas eu d'erreur*/
int add_file(Fileinfo* tab_files, int* len, const char* path, long int size);



#endif