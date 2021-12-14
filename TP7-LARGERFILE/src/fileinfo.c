#include "fileinfo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int add_file(Fileinfo* tab_files, int* len, const char* path, long int size){
	if (*len < MAXFILES){
		tab_files[*len].size = size;
		strcpy(tab_files[*len].path, path);
		/* Erreur lors de l'assignement du path */
		if (!strcmp(path, tab_files[*len].path))
			return 1;
		*len += 1;
	}
	else{
		if (tab_files[*len - 1].size < size){
			tab_files[*len - 1].size = size;
			free(tab_files[*len - 1].path);
			strcpy(tab_files[*len].path, path);
			/* Erreur lors de l'assignement du path */
			if (!strcmp(path, tab_files[*len].path))
				return 1;
		}

	}
	qsort(tab_files, *len, sizeof(Fileinfo), file_cmp);
	return 0;
}

int     file_size_cmp(const void *a, const void *b){
    return (((Fileinfo*) a)->size < ((Fileinfo*) b)->size);
}
