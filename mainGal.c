#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibliotecas/AVL.h"

// struct node_movie;
// struct movie;
// typedef struct node_movie node_movie;
// typedef struct movie movie;

// struct node_movie{
//     struct movie *movie;   // Ponteiro para o filme vizinho
//     struct node_movie *next;     // Ponteiro para o próximo nó na lista
// };

// struct movie{
//     char nconst[20];
// 	char name[20];
// 	node_movie *neighbors;
// };


/////////////////////////////////////////////////////

int main(){
	node * n = NULL;

	movie * m1 = (movie *)malloc(sizeof(movie)); // Allocate memory
	strcpy(m1->nconst, "tt9916590");
	strcpy(m1->name, "Matrix");
	m1->neighbors = NULL;

	movie * m2 = (movie *)malloc(sizeof(movie)); // Allocate memory
	strcpy(m2->nconst, "tt9917590");
	strcpy(m2->name, "Minions");
	m2->neighbors = NULL;

	movie * m3 = (movie *)malloc(sizeof(movie)); // Allocate memory
	strcpy(m3->nconst, "tt9936590");
	strcpy(m3->name, "Filme generico 1");
	m3->neighbors = NULL;

	movie * m4 = (movie *)malloc(sizeof(movie)); // Allocate memory
	strcpy(m4->nconst, "tt99386590");
	strcpy(m4->name, "Filme generico 2");
	m4->neighbors = NULL;

	insert(&n, m1);
	insert(&n, m2);
	insert(&n, m3);
	insert(&n, m4);

	// Fazendo busca | a busca retorna o indice do vetor
	int a  = search(n, "tt9916590");
	int b  = search(n, "tt9917590");
	int c  = search(n, "tt9936590");
	int d  = search(n, "tt99386590");

	printf("Index: %d\n", a);
	printf("Index: %d\n", b);
	printf("Index: %d\n", c);
	printf("Index: %d\n", d);
	int f  = search(n, "tt9917590");
	printf("Index: %d\n", f);

	return 0;
}