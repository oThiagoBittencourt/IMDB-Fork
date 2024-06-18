#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bibliotecas/DynamicTitles.h"

void readTSVFile(char localFile[], TitleArray *titles) {

    FILE *file = fopen(localFile, "r");
    char buffer[255];

    if(file){

        int repeticoes = 0;
        fgets(buffer, sizeof(buffer), file);

        while(repeticoes < 10){ // while(!feof(file))
            if(fgets(buffer, sizeof(buffer), file))
                printf("%s", buffer);
            repeticoes++;
        }
    }

    fclose(file);
}

int main() {
    TitleArray titles;
    initArray(&titles, 10);
    
    readTSVFile("TSV/title.basics.tsv", &titles);

    return 0;
}