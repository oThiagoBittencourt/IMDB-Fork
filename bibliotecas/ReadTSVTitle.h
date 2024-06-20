#ifndef READTSVTITLE_H
#define READTSVTITLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicTitles.h"

void readTSVTitle(char localFile[], TitleArray *titles) {
    FILE *file = fopen(localFile, "r");
    char buffer[900];

    if(file) {
        const char delim[] = "\t";

        fgets(buffer, sizeof(buffer), file);

        while(!feof(file)) {
            if(fgets(buffer, sizeof(buffer), file)) {
                Title tempTitle;
                char *token = strtok(buffer, delim);

                int i = 0;
                while (i < 4) {
                    switch(i) {
                        case 0:
                            strcpy(tempTitle.tconst, token);
                            break;
                        case 1:
                            strcpy(tempTitle.titleType, token);
                            break;
                        case 3:
                            strcpy(tempTitle.originalTitle, token);
                            break;
                    }
                    token = strtok(NULL, delim);
                    i++;
                }
                if(strcmp(tempTitle.titleType, "movie") == 0){
                    tempTitle.neighbors = NULL;
                    insertArray(titles, tempTitle);
                }
            }
        }
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

#endif