#include "TableSymboles.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Fonction d'initialisation d'une TS
SYMTABLE *initialiserTS(){
    SYMTABLE *symboleTable = malloc(sizeof(SYMTABLE));
    symboleTable->head = NULL;
    symboleTable->size = 0;
    printf("initialisaiton done\n");
    return symboleTable;
}


//Fonction de recherche 
NODESYMTABLE *rechercher(SYMTABLE *TS, char nom[]){
    NODESYMTABLE *n = TS->head;
    while (n != NULL) {
        if(strcmp(n->info.Token, nom) == 0) {
            return n;
        } else {
            n = n->next;
        }
    }
}


//Fonction d'insertion
NODESYMTABLE *inserer(SYMTABLE *TS, char nom[]){
    NODESYMTABLE *node = malloc(sizeof(NODESYMTABLE));
    strcpy(node->info.Token, nom);
    node->info.Type = -1;
    node->info.TokenType = -1;
    node->next = TS->head;
    TS->head = node;
    TS->size++;
    return node;
}


//Fonction de suppression de la TS 
int supprimerTS(SYMTABLE *TS){
    NODESYMTABLE *node = TS->head, *tmp;
    while(node != NULL) {
        tmp = node;
        free(node);
        node = tmp->next;
    }
    free(TS);
}


//Affichage 
void afficherTS(SYMTABLE *TS) {
    printf("\n \nTable des symboles \n \n");
    NODESYMTABLE *n = TS->head;
    int i = 0;
    while(n != NULL) {
        printf("(%d) %s : %d %d ", i, n->info.Token, n->info.Type, n->info.TokenType);
        printf("\n");
        i++;
        n = n->next;
    }
    printf("\n\n");
}

//get the array of values of an array
ARRAYCONTENT *accessArray(SYMTABLE *TS, char nomArray[]){
    NODESYMTABLE *node = rechercher(TS, nomArray);
    return node->info.arraycontent;
    
}

void setType(SYMTABLE *TS, char name[], int type){
    NODESYMTABLE *TOKEN = rechercher(TS, name);
    if(TOKEN != NULL){
        TOKEN->info.Type = type;
    }
    return;
}


/*void setType(NODESYMTABLE **TOKEN, int type){
    if(*TOKEN != NULL){
        (*TOKEN)->info.Type = type;
        printf("done here");
        
    }
    return;
}*/


void setTokenType(SYMTABLE *TS, char name[], int TokenType){
    NODESYMTABLE *TOKEN = rechercher(TS, name);
    if(TOKEN != NULL){
        TOKEN->info.TokenType = TokenType;
    }
    return;
}