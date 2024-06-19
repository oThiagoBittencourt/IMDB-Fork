#ifndef DYNAMICTITLES_H
#define DYNAMICTITLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tconst[10];
    char titleType[10];
    char originalTitle[500];
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
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->size = 0;
}

void printTitle(Title title) {
    printf("tconst: %s\n", title.tconst);
    printf("Title Type: %s\n", title.titleType);
    printf("Original Title: %s\n", title.originalTitle);
}

#endif