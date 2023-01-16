%{
#include "TableSymboles.h"
#include "quadruplet.h"
#include <stdio.h>
#include <stdlib.h>
int yylex();
extern FILE *yyin;

int yyerror(const char *s);

SYMTABLE *TS;
QUADTABLE *TQ;
QUADRUPLETNODE* quad;
int quadCounter = 0;
%}

%union {

    char *value;  //used to get values of terminals and expressions 
    NODESYMTABLE *id; //used to get value of identifiers
    char *type; //To determine the types of expressions
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
%token KEYFUN
token KEYARRAY
%token ASSIGN
%token KEYVAR
%token KEYCONST
%token KEYIF
%token KEYELSE
%token KEYTHEN
%token <value>TYPEINT <value>TYPEREAL <value>TYPEBOOL <value>TYPESTR
%token TWODOTS
%token <type>DECINT 
%token <type>DECREAL 
%token <type>DECBOOL 
%token <type>DECSTR
%token COMMA
%token RETURNKEY
%token BRACKETSTART
%token BRACKETEND
%token PARENTESESTART PARENTESEEND
%token AND OR NOT
%token PLUS MINUS MULT DIV
%token SUP SUPEQ INF INFEQ EQ NEQ
%type <type>dectype
%type <value>EXP
%type <value>EXPS
%type <id>variable
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
    {TS = initialiserTS(); TQ = initialiserTQ();}
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
    | condition 
    | return 
    | funcall
    ;

return : 
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
        setType(TS, $2, $4); 
        setTokenType(TS, $2, 1); 


        quad = creer_Q("DEC", $2 , "","" , quadCounter++);
        inserer_TQ(TQ, quad);

        }

    | KEYVAR IDENTIFIER TWODOTS dectype ASSIGN EXP END {
        setTokenType(TS, $2, 1);

        //quad creation
        //all values are represented by a char => convert to string 
        quad = creer_Q("DEC", $2 , "","" , quadCounter++);
        inserer_TQ(TQ, quad);

        /*char buffer[20];
        itoa($6, buffer, 10);*/
        printf("VALLLLL %s", $6);
        quad = creer_Q("=", $6, "", $2, quadCounter++);
        inserer_TQ(TQ, quad);

        setValue(TS, $2, $6);
       
        }

    | KEYARRAY IDENTIFIER CURLYSTART dectype CURLYEND BRACKETSTART EXP BRACKETEND END {
        setType(TS, $2, $4); 
        setTokenType(TS, $2, 3); 
        char length[10];
        sprintf(length, "%d", $7);
        setValue(TS, $2, length); //store the array length in value

        //quad
         quad = creer_Q("BOUNDS", "1", length, "", quadCounter++);
         inserer_TQ(TQ, quad);
         quad = creer_Q("ADEC", $2, "", "", quadCounter++);
         inserer_TQ(TQ, quad);



        }

    | KEYARRAY IDENTIFIER CURLYSTART dectype CURLYEND BRACKETSTART EXP BRACKETEND ASSIGN BRACKETSTART EXPS BRACKETEND END //array 
     {
        setTokenType(TS, $2, 3);
        char length[10];
        sprintf(length, "%d", $7);
        setValue(TS, $2, length);


        //store values in arrayContent

         quad = creer_Q("BOUNDS", "1", length, "", quadCounter++);
         inserer_TQ(TQ, quad);
         quad = creer_Q("ADEC", $2, "", "", quadCounter++);
         inserer_TQ(TQ, quad);
         //quadruplet de l'initialisation d'un tableau

         quad = creer_Q("=", "list of elements", "", $2, quadCounter++);
         inserer_TQ(TQ, quad);
        }
    ;

EXPS : 
    EXP | EXPS COMMA EXP
    ;


constdeclaration : 
    KEYCONST IDENTIFIER TWODOTS dectype ASSIGN EXP END {
        setTokenType(TS, $2, 0);

        quad = creer_Q("DEC", $2 , "","" , quadCounter++);
        inserer_TQ(TQ, quad);

        char buffer[20];
        itoa($6, buffer, 10);
        quad = creer_Q("=", buffer, "", $2, quadCounter++);
        inserer_TQ(TQ, quad);

        }
    ;

assignment : 
    variable ASSIGN EXP END 
    {
        char buffer[20];
        itoa($3, buffer, 10);
        quad = creer_Q("=", buffer, "", $1, quadCounter++);
        inserer_TQ(TQ, quad);}
    ;

condition : 
    KEYIF PARENTESESTART EXP PARENTESEEND KEYTHEN CURLYSTART ins_seq CURLYEND
    | KEYIF PARENTESESTART EXP PARENTESEEND KEYTHEN CURLYSTART ins_seq CURLYEND KEYELSE CURLYSTART ins_seq CURLYEND
    ;


EXP : 
    TYPEINT {printf(" VALUE : %s\n", $1); $$ = $1;}
    | EXP EQ EXP
     /*| IDENTIFIER PARENTESESTART arguments PARENTESEEND //function call
     | EXP PLUS EXP | EXP MINUS EXP
     | EXP DIV EXP | EXP MULT EXP
     | MINUS EXP %prec NEG
     | EXP SUP EXP
     | EXP SUPEQ EXP
     | EXP INF EXP
     | EXP INFEQ EXP
     | EXP EQ EXP
     | EXP NEQ EXP
     | EXP AND EXP
     | EXP OR EXP 
     | NOT EXP
     | PARENTESESTART EXP PARENTESEEND*/

    ;
    variable :
    IDENTIFIER | IDENTIFIER BRACKETSTART EXP BRACKETEND {
        char buffer[20];
        itoa($3, buffer, 10);
        quad = creer_Q("ARRAY_ELMT", $1, buffer, "", quadCounter++);
        inserer_TQ(TQ, quad);
    };
    

dectype : 
    DECBOOL {$$ = yylval.type;}
    | DECINT {$$ = yylval.type;}
    | DECREAL {$$ = yylval.type;}
    | DECSTR {$$ = yylval.type;}
    ;

%%
int yyerror(const char *s) {
  printf("%s\n",s);
}

int main(int argc, char *argv[]) {
    yyin = fopen("testQD.txt", "r");
    yyparse();
    fclose(yyin);
    return 0;
}