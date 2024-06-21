#ifndef ADDFORK_H
#define ADDFORK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "DynamicTitles.h"
#include "AVL.h"

void verifyFork(char *arrayNconst[], TitleArray *titles, node *n, int size){
    for (int i = 0; i < size; i++){
        int response = search(n, arrayNconst[i]);
        if (response != -1){
            for (int j = 0; j < size; j++){
                if (j != i){
                    if (search(n, arrayNconst[j]) != -1)
                        addNeighbor(&titles->array[response], arrayNconst[j]);
                }
            }
        }
    }
}

void addFork(char localFile[], TitleArray *titles, node *n){
    FILE *file = fopen(localFile, "r");
    char buffer[200];

    if (file){
        fgets(buffer, sizeof(buffer), file);

        while (!feof(file)){
            if (fgets(buffer, sizeof(buffer), file)){
                char delim[] = "\t";

                char *token = strtok(buffer, delim);
                char *lastToken = token;
                while (token != NULL){
                    lastToken = token;
                    token = strtok(NULL, delim);
                }

                char delim2[] = ",";
                char *values[4];
                int i = 0;

                char *tokenVirgula = strtok(lastToken, delim2);
                while (tokenVirgula != NULL){
                    values[i] = tokenVirgula;
                    tokenVirgula = strtok(NULL, delim2);
                    i++;
                }
                verifyFork(values, titles, n, i);
            }
        }
        fclose(file);
    }
    else
        printf("Erro ao abrir o arquivo.\n");

    fclose(file);
}

#endif