#ifndef WRITEDOTFILE_H
#define WRITEDOTFILE_H

#include <stdio.h>

#include "DynamicTitles.h"
#include "AVL.h"

void writeDotFile(char fileName[], TitleArray *titles, node *n) {
    FILE* file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "graph G {concentrate=true\n");

    for (size_t i = 0; i < titles->used; i++) {
        Title tempTitle = titles->array[i];
        fprintf(file, "\t%s -- {", tempTitle.originalTitle);
        n_node *neighbor = tempTitle.neighbors;
        while (neighbor != NULL) {
            int response = search(n, neighbor->tconst);
            Title tempNeighbour = titles->array[response];
            fprintf(file, "%s", tempNeighbour.originalTitle);
            neighbor = neighbor->nextTitle;
            if (neighbor != NULL)
                fprintf(file, ",");
        }
        fprintf(file, "}\n");
    }

    fprintf(file, "}\n");

    fclose(file);
}

#endif