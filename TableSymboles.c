#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct NodeInfo
{
    char Nom[255];
    char Type[255]; //A revoir 
    int size;
    int ligneDeclaration; 
    int address; 
} NODEINFO;

//Structure d'une entrée 
typedef struct NodeSymTable
{
    struct NodeInfo info;
    struct NodeSymTable *next;
} NODESYMTABLE;

//Structure d'une table des Symboles 
typedef struct SymTable
{
    struct NodeSymTable *head;
    struct NodeSymTable *tail;
    int size;
} SYMTABLE;


//Fonction de recherche 
NODESYMTABLE *rechercher(SYMTABLE *TS, char nom[]) {
    if(TS == NULL) {
        return NULL;
    }
    NODESYMTABLE *n = TS->head;
    while (n != NULL) {
        if(strcmp(n->info.Nom, nom) == 0) {
            return n;
        } else {
            n = n->next;
        }
    }
}

//Fonction de suppression d'un noeud
SYMTABLE* supprimer(SYMTABLE *TS, char nom[]) {
    NODESYMTABLE *n = rechercher(TS, nom);
    if(n == NULL) {
        printf("ERROR, cant find node \n");
        return TS;
    }
    NODESYMTABLE *head = TS->head;

    if(n == head) {
        TS->head = head->next;
        free(n);
        return TS;
    }

    else {
        NODESYMTABLE *tmp = head;
        while(tmp != NULL) 
        {
            if (tmp->next == n) {
                tmp->next = n->next;
                free(n);
                return TS;
            }
            else {
                tmp = tmp->next;
            }
        }
    }
}


//Fonction d'initialisation d'une TS
SYMTABLE *InitialiserTS(){
    struct SymTable *symboleTable = malloc(sizeof(SYMTABLE));
    symboleTable->head = NULL;
    symboleTable->tail = NULL;
    symboleTable->size = 0;
    //printf("initialisaiton done\n");
    return symboleTable;
}


//Fonction d'insertion
SYMTABLE *inserer(SYMTABLE *TS, char nom[], char type[]){
    if(TS == NULL) {
        TS = InitialiserTS();
        //printf("hello new token :) \n");
        NODESYMTABLE *head = malloc(sizeof(NODESYMTABLE));
        strcpy(head->info.Nom, nom);
        strcpy(head->info.Type, type);
        TS->head = head;
        TS->tail = head;
        TS->size = 1;
        return TS;
    }
    else {
        //printf("another token :) \n");
        NODESYMTABLE *node = malloc(sizeof(NODESYMTABLE));
        strcpy(node->info.Nom, nom);
        strcpy(node->info.Type, type);
        TS->tail->next = node;
        TS->tail = node;
        TS->size++;
        return TS;
    }
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
    NODESYMTABLE *n = TS->head;
    int i = 0;
    while(n != NULL) {
        printf("%s (%d) => ", n->info.Nom, i);
        i++;
        n = n->next;
    }
    printf("\n");
}