#ifndef DynamicActors_h
#define DynamicActors_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char tconst[10];
    char titleType[10];
    char originalTitle[50];
} Title;

typedef struct {
    Title *array;
    size_t used;
    size_t size;
} TitleArray;

// Inicializa o vetor dinâmico
void initArray(TitleArray *a, size_t initialSize) {
    a->array = (Title *)malloc(initialSize * sizeof(Title));
    a->used = 0;
    a->size = initialSize;
}

// Insere um novo título no vetor dinâmico
void insertArray(TitleArray *a, Title title) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (Title *)realloc(a->array, a->size * sizeof(Title));
    }
    a->array[a->used++] = title;
}

// Libera a memória alocada para o vetor dinâmico
void freeArray(TitleArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = 0;
    a->size = 0;
}

// Função para exibir informações de um título
void printTitle(Title title) {
    printf("tconst: %s\n", title.tconst);
    printf("Title Type: %s\n", title.titleType);
    printf("Original Title: %s\n", title.originalTitle);
}

#endif