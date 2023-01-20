%{
#include "TableSymboles.h"
#include "quadruplet.h"
#include "helperSemantic.h"
#include <stdio.h>
#include <stdlib.h>
int yylex();
extern FILE *yyin;
int yyerror(const char *s);

SYMTABLE *TS;
QUADTABLE *TQ;
QUADPILE *P;

int execute = 1; 
QUADRUPLETNODE* quad;
int quadCounter = 0;
%}

%union {
    char *value;
    char *id;
    int type;
    struct {
        char* value;
        char* id;
        int type;
    } compose;

    
}


%token KEY
%token PROGKEY
%token SECTDEFKEY
%token CURLYSTART
%token CURLYEND
%token MODELS
%token MAIN
%token END

%token <id>IDENTIFIER
%token ENDPROG
%token <type>KEYFUN
token <type>KEYARRAY
%token ASSIGN
%token <type>KEYVAR
%token <type>KEYCONST
%token KEYIF
%token KEYELSE
%token KEYTHEN
%token <value>TYPEINT <value>TYPEREAL <value>TYPEBOOL <value>TYPESTR
%token TWODOTS
%token DECINT 
%token DECREAL 
%token DECBOOL 
%token DECSTR
%token COMMA
%token RETURNKEY
%token BRACKETSTART
%token BRACKETEND
%token PARENTESESTART PARENTESEEND
%token AND OR NOT
%token PLUS MINUS MULT DIV
%token SUP SUPEQ INF INFEQ EQ NEQ
%type <type>dectype
%type <compose>type
%type <compose>TERM
%type <compose>Variable
%type <compose>listelement
%type <compose>EXP
%left OR
%left AND
%left NOT
%left SUP SUPEQ INF INFEQ
%left EQ NEQ
%left PLUS MINUS
%left MULT DIV
%left NEG
%start program


%%

program : 
    {TS = initialiserTS(); TQ = initialiserTQ(); P = initialiserP();}
    header
    SECTDEFKEY MODELS CURLYSTART functions CURLYEND END 
    SECTDEFKEY MAIN CURLYSTART ins_seq CURLYEND END 
    KEY ENDPROG {printf("u got it right\n"); afficherTS(TS); afficherTQ(TQ);}
    ;

header :  
    KEY PROGKEY IDENTIFIER
    ;

ins_seq : 
    | instruction ins_seq
    ;

functions : 
    KEYFUN IDENTIFIER PARENTESESTART parameters PARENTESEEND TWODOTS returntype CURLYSTART ins_seq CURLYEND
    |
    ;

parameters : 
    IDENTIFIER 
    | parameters COMMA IDENTIFIER
    |
    ;

returntype : 
    DECBOOL 
    | DECINT
    | DECREAL
    | DECSTR
    ;

instruction : 
    declaration 
    | assignment 
    | ifstatemnt
    | returnn 
    | funcall
    ;

returnn : 
    RETURNKEY PARENTESESTART EXP PARENTESEEND END
    ;

funcall : 
    IDENTIFIER PARENTESESTART arguments PARENTESEEND END
    ;

arguments : 
    EXP
    | arguments COMMA EXP
    |
    ;


declaration : 
    vardeclaration 
    | constdeclaration
    ;

vardeclaration :
    KEYVAR IDENTIFIER TWODOTS dectype END {
        quad = creer_Q("DEC", $2 , "","" , quadCounter++);
        inserer_TQ(TQ, quad);
        if(execute) {
            setType(TS, $2, $4); setTokenType(TS, $2, $1);
            }
        }
        
    | KEYVAR IDENTIFIER TWODOTS dectype ASSIGN EXP END {
        quad = creer_Q("DEC", $2 , "", "", quadCounter++);
        inserer_TQ(TQ, quad);
        quad = creer_Q("=", $6.value, "", $2, quadCounter++);
        inserer_TQ(TQ, quad);
       //printf("id = %s, exptype =  %d \n", $2, $6.type);
       if(execute) {
        if($4 == $6.type || $4 == REAL && isNumeric($6.type)) { 
            //if type is the same of if we're assigning a numeric expression (int or real) to real
            setTokenType(TS, $2, $1);
            setType(TS, $2, $4);
            setValue(TS, $2, $6.value);

        } else {printf("incompatible type\n"); yyerror('c');}
       }
        //printf("after id = %s, exptype =  %d \n", $2, $6.type);
        }
    | KEYARRAY IDENTIFIER CURLYSTART dectype CURLYEND BRACKETSTART EXP BRACKETEND END {setType(TS, $2, $4); setTokenType(TS, $2, $1);}//array 
    | KEYARRAY IDENTIFIER CURLYSTART dectype CURLYEND BRACKETSTART EXP BRACKETEND ASSIGN BRACKETSTART types BRACKETEND END  {setTokenType(TS, $2, $1);}//array

    ;

constdeclaration : 
    KEYCONST IDENTIFIER TWODOTS dectype ASSIGN EXP END {setTokenType(TS, $2, $1);}
    ;

assignment : 
    IDENTIFIER ASSIGN EXP END {
        //printf("\n execute %d \n", execute);
        quad = creer_Q("=", $3.value, "", $1, quadCounter++);
        inserer_TQ(TQ, quad);
        if(execute) {
            NODESYMTABLE *node = rechercher(TS, $1);
            if(node == NULL) {
            printf("girl u cant assign to a non declared variable\n"); yyerror('c');
            }
            if((node->info.Type == $3.type || node->info.Type == REAL && isNumeric($3.type)) && node->info.TokenType == VAR) {
                //if type is the same of if we're assigning a numeric expression (int or real) to real
                setValue(TS, $1, $3.value);
            } else {
                printf("incompatible type\n"); yyerror('c');}
            }
    }


    /*| listelement ASSIGN EXP END /* assign to list element */
    ;

ifstatemnt : 

    first_part KEYTHEN CURLYSTART ins_seq CURLYEND {
        //mise a jour d'adresses
        printf("\nIM HERE\n");
        quad = pop(P);
        afficherQ(quad);
        updateEtiq(quad, quadCounter);
         execute = 1; //get out
    }

    | first_part second_part KEYELSE CURLYSTART ins_seq CURLYEND {
        quad = pop(P);
        afficherQ(quad);
        updateEtiq(quad, quadCounter);
        execute = 1; //get out
    }
    ;

first_part : 
    KEYIF PARENTESESTART EXP PARENTESEEND {
        if($3.type == BOOL) {
            //make quadruplet for thing 
            quad = creer_Q("BZ", "etiq", "", $3.value, quadCounter++);
            inserer_TQ(TQ, quad);
            push(P, quad);
            if(strcmp($3.value, "false") == 0){

            printf("false baby\n");
                //if the condition is false => skip instruction set
                execute = 0;
            }
        }
        else {
            printf("incompatible type\n"); yyerror('c');
        }
    }
    ;
 second_part :
    KEYTHEN CURLYSTART ins_seq CURLYEND {
        quad = pop(P);
        afficherQ(quad);
        updateEtiq(quad, quadCounter+1);
        //branchement vers fin
        quad = creer_Q("BR", "etiq", "", "", quadCounter++);
        inserer_TQ(TQ, quad);
        push(P, quad);
        printf("1. EXCEE  %d \n", execute);
        if(execute == 0) {
            //ins1 was skipped 
            execute = 1;
            
        } else {
            //ins1 was executed => dont execute else 
            execute = 0;
        }
        
    }
    ;


EXP : 
     TERM {
        strcpy($$.value, $1.value);
        $$.type = $1.type;

        }
     //| IDENTIFIER PARENTESESTART arguments PARENTESEEND 
     
     | EXP PLUS EXP {
        printf("\ntypes %s %s \n \n ", $1.value, $3.value);
        if(isNumeric($1.type) && isNumeric($3.type)) {
            
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            float val = val1 + val2;
            char result[255];

            if(ceilf(val) == val){
                itoa((int)(val), result, 10);
                $$.type = INT;
            } else {
                sprintf(result, "%.2f", val);
                $$.type = REAL;
            }
            quad = creer_Q("+", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
     | EXP MINUS EXP {
        printf("types %d %d \n \n ", $1.type, $3.type);
        if(isNumeric($1.type) && isNumeric($3.type)) {
            
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            float val = val1 - val2;
            char result[255];

            if(ceilf(val) == val){
                itoa((int)val, result, 10);
                $$.type = INT;
            } else {
                sprintf(result, "%.2f", val);
                $$.type = REAL;
            }
            quad = creer_Q("-", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }

     }
     | EXP DIV EXP {
        printf("types %d %d \n \n ", $1.type, $3.type);
        if(isNumeric($1.type) && isNumeric($3.type)) {
            
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            float val = val1 / val2;
            char result[255];

            if(ceilf(val) == val){
                itoa((int)(val), result, 10);
                $$.type = INT;
            } else {
                sprintf(result, "%.2f", val);
                $$.type = REAL;
            }
            quad = creer_Q("%", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
     
     | EXP MULT EXP {
        //printf("types %d %d \n \n ", $1.type, $3.type);
        if(isNumeric($1.type) && isNumeric($3.type)) {
            
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            float val = val1 * val2;
            char result[255];

            if(ceilf(val) == val){
                itoa((int)(val), result, 10);
                $$.type = INT;
            } else {
                sprintf(result, "%.2f", val);
                $$.type = REAL;
            }
            quad = creer_Q("*", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
     /*| MINUS EXP %prec NEG {
        printf("we here\n");
        if($2.type == 2) {
            //Convert to int, sum, covert back to string 
            int val1 = atoi($2.value);
            char result[255];
            itoa(val1 + 6, result, 10);
            printf("welp %s", result);
            strcpy($$.value, -6); 
        } else if ($2.type == 4) {
            float val1 = atof($2.value);
            char result[255];
            sprintf(result, "%.2f", val1);
             strcpy($$.value, result);
        }
        else {printf("erreur semantique : cant negate a non numeric value\n"); yyerror('c');}
     }*/
     | EXP SUP EXP {
        if(isNumeric($1.type) && isNumeric($3.type)) {
            //printf("\nHOUNA \n");
            $$.type = BOOL;
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            char result[255];

            if(val1 > val2) {
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }

            quad = creer_Q(">", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
     | EXP SUPEQ EXP {
        if(isNumeric($1.type) && isNumeric($3.type)) {
            $$.type = BOOL;
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            char result[255];
            if(val1 >= val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q(">=", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
     
     | EXP INF EXP {
        if(isNumeric($1.type) && isNumeric($3.type)) {
            $$.type = BOOL;
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            char result[255];
            if(val1 < val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q("<", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
     | EXP INFEQ EXP {
        if(isNumeric($1.type) && isNumeric($3.type)) {
            $$.type = BOOL;
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            char result[255];
            if(val1 <= val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q("<=", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
     | EXP EQ EXP{
        if(isNumeric($1.type) && isNumeric($3.type)) {
            $$.type = BOOL;
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            char result[255];
            if(val1 == val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q("==", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
     | EXP NEQ EXP {
        if(isNumeric($1.type) && isNumeric($3.type)) {
            $$.type = BOOL;
            float val1 = atof($1.value);
            float val2 = atof($3.value);
            char result[255];
            if(val1 != val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q("!=", $1.value, $3.value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy($$.value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
     /*| EXP AND EXP
     | EXP OR EXP 
     | NOT EXP*/
     | PARENTESESTART EXP PARENTESEEND {
        $$.value = $2.value;
        $$.type = $2.type;
     }
    ;
listelement :
    IDENTIFIER BRACKETSTART EXP BRACKETEND {
        NODESYMTABLE *node = rechercher(TS, $1);
        strcpy($$.type, node->info.Type);
        }
    ;

dectype : 
    DECBOOL {$$ = yylval.type;}
    | DECINT {$$ = yylval.type;}
    | DECREAL {$$ = yylval.type;}
    | DECSTR {$$ = yylval.type;}
    ;

type : 
    TYPEINT {$$.value = yylval.value; $$.type = INT;}
    | TYPEBOOL {$$.value = yylval.value; $$.type = BOOL;}
    | TYPEREAL {$$.value = yylval.value; $$.type = REAL;}
    | TYPESTR {$$.value = yylval.value; $$.type = STR;}
    ;
types : 
    type
    | types COMMA type
    |
    ;

TERM : 
    Variable {
        printf("hello");
        strcpy($$.value, $1.value);
        $$.type =  $1.type;
        }
    | type { strcpy($$.value, $1.value); $$.type = $1.type;}

    ;
Variable : 
    IDENTIFIER {
    NODESYMTABLE *node = rechercher(TS, $1);
    strcpy($$.value, node->info.Value);
    $$.type =  node->info.Type;
    }
    | listelement {strcpy($$.value, $1.value);}
%%
int yyerror(const char *s) {
  printf("error %s\n",s);
}

int main(int argc, char *argv[]) {
    yyin = fopen("testQD.txt", "r");
    yyparse();
    fclose(yyin);
    return 0;
}