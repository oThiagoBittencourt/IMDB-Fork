#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bibliotecas/DynamicTitles.h"
#include "bibliotecas/AVL.h"

void copy_to_buffer(char *dest, const char *src, size_t buffer_size) {
    strncpy(dest, src, buffer_size - 1);
    dest[buffer_size - 1] = '\0';
}

void readTSVFile(char localFile[], TitleArray *titles) {
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
                if(strcmp(tempTitle.titleType, "movie") == 0)
                    insertArray(titles, tempTitle);
            }
        }
        fclose(file);
    } else {
        printf("Erro ao abrir o arquivo.\n");
    }
}

int main() {
    TitleArray titles;
    node * n = NULL;

    initArray(&titles, 10);

    readTSVFile("TSV/title.basics.tsv", &titles);

    printf("Terminou");

    for (size_t i = 0; i < titles.used; i++) {
        Title currentTitle = titles.array[i];
        if (strcmp(currentTitle.tconst, "tt0091295") == 0){
            printf("%d", i);
            break;
        }
        insert(&n, &currentTitle, i);
    }
    
    printf("Terminou2");

    int response = search(n, "tt0000502");
    printf("Resposta: %d", response);

    freeArray(&titles);

    return 0;
}

// tt0091295