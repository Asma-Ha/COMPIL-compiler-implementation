//this is only to test quad fucntions and all 

#include <stdio.h>
#include <stdlib.h>
#include "quadruplet.h"

int main() {
    /* TQ works 
    QUADTABLE *T = initialiserTQ();
    QUADRUPLETNODE *Q1 = creer_Q("+", "t1", "t2", "R1", 1);
    inserer_TQ(T, Q1);
    afficherTQ(T);
    */


   /* PQ*/
   QUADPILE *P = initialiserP();
   QUADRUPLETNODE *Q1 = creer_Q("+", "t1", "t2", "R1", 1);
   QUADRUPLETNODE *Q2 = creer_Q("-", "R1", "t2", "R2", 2);

   push(P, Q1);
   push(P, Q2);

    printf("\nAffichage P before popping \n");
   afficherP(P);

   QUADRUPLETNODE *Q = pop(P);
   Q = pop(P);
   printf("\nAffichage P after popping \n");
   afficherP(P);

    Q = pop(P);
    return 0;
}