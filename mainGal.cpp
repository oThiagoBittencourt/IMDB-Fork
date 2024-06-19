#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "AVL/avl.cpp"

struct node_movie;
typedef struct node_movie node_movie;
struct movie;
typedef struct movie movie;

struct node_movie{
    struct movie *movie;   // Ponteiro para o filme vizinho
    struct node_movie *next;     // Ponteiro para o próximo nó na lista
};

struct movie{
    char nconst[20];
	char name[20];
	node_movie *neighbors;
};

int main(){
	AVL avl;

	// Adiciona alguns filmes
	movie m1;
	strcpy(m1.nconst, "tt9916590");
	strcpy(m1.name, "Matrix");
	m1.neighbors = NULL;

	movie m2;
	strcpy(m2.nconst, "tt9917590");
	strcpy(m2.name, "Minions");
	m2.neighbors = NULL;

	movie m3;
	strcpy(m3.nconst, "tt9936590");
	strcpy(m3.name, "Filme generico 1 - O inicio");
	m3.neighbors = NULL;
	
	movie m4;
	strcpy(m4.nconst, "tt993s6590");
	strcpy(m4.name, "Matrix");
	m4.neighbors = NULL;
	
	// Inserindo os valores na árvore
	avl.insert(&avl.n, m3.nconst, 3);
	avl.insert(&avl.n, m2.nconst, 2);
	avl.insert(&avl.n, m1.nconst, 7);
	avl.insert(&avl.n, m4.nconst, 3);

	// Fazendo busca | a busca retorna o indice do vetor
	int a  = avl.search(avl.n, "tt9936590");
	if (a >= 0){
		printf("Index: %d\n", a);
	} else{
		printf("Filme não existe na árvore.");
	}
	return 0;
}