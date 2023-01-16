//structure of a quadruplet

typedef struct quadrupletNode
{
    char operator[20];
    char operand1[255];
    char operand2[255];
    char result[255];

    int address;
    struct quadrupletNode *next;
} QUADRUPLETNODE;

typedef struct quadTable
{
    struct quadrupletNode *head;
    int size;
} QUADTABLE;


QUADTABLE* initialiserTQ();

void afficherTQ(QUADTABLE *TQ);
void supprimer_TQ(QUADTABLE *TQ);

QUADRUPLETNODE* creer_Q(char operator[], char* operand1, char* operand2, char* result, int address);
void afficher_Q(QUADRUPLETNODE* Q);
void inserer_TQ(QUADTABLE *TQ, QUADRUPLETNODE *Q);
QUADRUPLETNODE* rechercherTQ(QUADTABLE *TQ,  int address);