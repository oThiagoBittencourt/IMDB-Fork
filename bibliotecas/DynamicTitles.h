#ifndef DYNAMICTITLES_H
#define DYNAMICTITLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n_node {
    char tconst[10];
    struct n_node *nextTitle;
} n_node;

typedef struct {
    char tconst[10];
    char titleType[10];
    char originalTitle[500];
    n_node *neighbors;
} Title;

typedef struct {
    Title *array;
    size_t used;
    size_t size;
} TitleArray;

void initArray(TitleArray *a, size_t initialSize) {
    a->array = (Title *)malloc(initialSize * sizeof(Title));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(TitleArray *a, Title title) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (Title *)realloc(a->array, a->size * sizeof(Title));
    }
    a->array[a->used++] = title;
}

void freeArray(TitleArray *a) {
    for (size_t i = 0; i < a->used; i++) {
        n_node *current = a->array[i].neighbors;
        while (current != NULL) {
            n_node *next = current->nextTitle;
            free(current);
            current = next;
        }
    }
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->size = 0;
}

void printTitle(Title title) {
    printf("tconst: %s\n", title.tconst);
    printf("Title Type: %s\n", title.titleType);
    printf("Original Title: %s\n", title.originalTitle);
    
    printf("Neighbors:\n");
    n_node *neighbor = title.neighbors;
    while (neighbor != NULL) {
        printf("\t%s\n", neighbor->tconst);
        neighbor = neighbor->nextTitle;
    }
}

void addNeighbor(Title *title, const char *neighborTconst) {
    n_node *current = title->neighbors;
    while (current != NULL) {
        if (strncmp(current->tconst, neighborTconst, 10) == 0) {
            return;
        }
        current = current->nextTitle;
    }

    n_node *newNode = (n_node *)malloc(sizeof(n_node));
    if (newNode == NULL) {
        fprintf(stderr, "Failed to allocate memory for new neighbor node\n");
        return;
    }

    strncpy(newNode->tconst, neighborTconst, 10);
    newNode->tconst[9] = '\0';
    newNode->nextTitle = NULL;

    newNode->nextTitle = title->neighbors;
    title->neighbors = newNode;
}

#endif