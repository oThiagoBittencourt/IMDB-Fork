#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bibliotecas/DynamicTitles.h"

void readTSVFile(char localFile[], TitleArray *titles) {
    FILE *file = fopen(localFile, "r");
    char buffer[255];

    if(file) {
        int repeticoes = 0;
        const char delim[] = "\t";

        fgets(buffer, sizeof(buffer), file);

        while(repeticoes < 50) { // while(!feof(file))
            if(fgets(buffer, sizeof(buffer), file)) {
                Title tempTitle;
                char *token = strtok(buffer, delim);

                int i = 0;
                while (i < 3) {
                    switch(i) {
                        case 0:
                            strcpy(tempTitle.tconst, token);
                            break;
                        case 1:
                            strcpy(tempTitle.titleType, token);
                            break;
                        case 2:
                            strcpy(tempTitle.originalTitle, token);
                            break;
                    }
                    token = strtok(NULL, delim);
                    i++;
                }
                insertArray(titles, tempTitle);

                repeticoes++;
            }
        }
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

int main() {
    TitleArray titles;
    initArray(&titles, 10);

    readTSVFile("TSV/title.basics.tsv", &titles);

    for (size_t i = 0; i < titles.used; i++) {
        printTitle(titles.array[i]);
    }

    freeArray(&titles);
    return 0;
}