#include <stdlib.h>
#include "quadruplet.h"
#include <stdio.h>
#include <string.h>


QUADTABLE* initialiserTQ(){
    QUADTABLE *quadTable = malloc(sizeof(QUADTABLE));
    quadTable->head = NULL;
    quadTable->size = 0;
    printf("initialisaiton done\n");
    return quadTable;
}

QUADRUPLETNODE* creer_Q(char operator[], char* operand1, char* operand2, char* result, int address){
    QUADRUPLETNODE *quadruplet = malloc(sizeof(QUADRUPLETNODE));
    quadruplet->address = address;
    strcpy(quadruplet->operator, operator);
    strcpy(quadruplet->operand1, operand1);
    strcpy(quadruplet->operand2, operand2);
    strcpy(quadruplet->result, result);
    
    return quadruplet;
}

void afficherQ(QUADRUPLETNODE* Q){
    printf("%d : Quadruplet(%s, %s, %s, %s)\n", Q->address, Q->operator, Q->operand1, Q->operand2, Q->result);
    return;
}

void inserer_TQ(QUADTABLE *TQ, QUADRUPLETNODE *Q){
    Q->next = TQ->head;
    TQ->head = Q;
    return;
}

void afficherTQ(QUADTABLE *TQ){
    printf("Table Quadruplets : \n");
    QUADRUPLETNODE *quad = TQ->head;
    while(quad != NULL){
        afficherQ(quad);
        quad = quad->next;
    }
    return;
}

QUADRUPLETNODE* rechercherTQ(QUADTABLE *TQ,  int address){
    QUADRUPLETNODE *quad = TQ->head;
    while(quad != NULL){
        if (quad->address == address){
            return quad;
        } else {
            quad = quad->next;
        }
    }
    return NULL;
}
