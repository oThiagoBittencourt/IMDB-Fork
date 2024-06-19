#ifndef DynamicActors_h
#define DynamicActors_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node;
struct node_movie;
struct movie;
typedef struct node node;
typedef struct node_movie node_movie;
typedef struct movie movie;

struct node{
    char tconst[20];
    int index;
    int level;
    node * left;
    node * right; 
};

struct node_movie{
    struct movie *movie;   // Ponteiro para o filme vizinho
    struct node_movie *next;     // Ponteiro para o próximo nó na lista
};

struct movie{
    char nconst[20];
	char name[20];
	node_movie *neighbors;
};
//////////////////////////////////////////////////

int get_weight(node * n){
    if(!n){
        return 0;
    }
    int const left_level  = n->left  ? n->left->level  : -1;
    int const right_level = n->right ? n->right->level : -1;
    return right_level - left_level;
}

void update_level(node * n){
    if(n){
        int const left_level  = n->left  ? n->left->level  : -1;
        int const right_level = n->right ? n->right->level : -1;
        int const max_level = left_level > right_level ? left_level : right_level;
        n->level = max_level + 1;
    }
}

//////////////////////////////////////////////////

node * rotate_left(node *, int);
node * rotate_right(node *, int);

node *rotate_left(node * n, int weight){
    if(!n){
        return NULL;
    }
    
    int const right_weight = get_weight(n->right);
    
    if((weight < 0 && right_weight > 0) || (weight > 0 && right_weight < 0)){
        n->right = rotate_right(n->right, right_weight);
    }
    
    node * temp = n->right;
    n->right = temp->left;
    temp->left = n; 
    
    update_level(temp->left);
    update_level(temp);
    
    return temp;
}

node *rotate_right(node * n, int weight)
{
    if(!n){
        return NULL;
    }
    
    int const left_weight = get_weight(n->left);
    
    if((weight < 0 && left_weight > 0) || (weight > 0 && left_weight < 0)){
        n->left = rotate_left(n->left, left_weight);
    }
    
    node * temp = n->left;
    n->left = temp->right;
    temp->right = n;
    
    update_level(temp->right);
    update_level(temp);
    
    return temp;
}

void balance(node ** n){
    if(*n){
        int const weight = get_weight(*n);
        if(weight > 1){
            *n = rotate_left(*n, weight);
        }
        else if(weight < -1){
            *n = rotate_right(*n, weight);
        }
        else{
            update_level(*n);
        }
    }
}

void insert_node(node ** n, node * m){
    if(!m){
        return;
    }
    
    if(!*n){
        *n = m;
        return;
    }
    m->index = m->index+1;
    int result = strcmp(m->tconst, (*n)->tconst);
    if(result == 0){
        return;
    }else if(result < 0){
        return insert_node(&(*n)->left, m);
    }else {
        return insert_node(&(*n)->right, m);
    }
    balance(n);
}

//////////////////////////////////////////////////

void destruct(node * n){
    if(n){
        destruct(n->left);
        destruct(n->right);
        free(n);
    }
}

int search(node * n, const char tconst[]){
    if(!n){
        return -1;
    }

    int result = strcmp(tconst, n->tconst);
    if(result == 0){
        return n->index;
    }else if(result < 0){
        return search(n->left, tconst);
    }else{
        return search(n->right, tconst);
    }
}

void insert(node ** n, movie * title){
    node * m = (node *) malloc(sizeof(node));
    if(m){
        strcpy(m->tconst, title->nconst);
        m->index = 0;
        m->level = 0;
        m->left  = NULL;
        m->right = NULL;
        printf("%s\n", m->tconst);
    }
    insert_node(n, m);
}

#endif