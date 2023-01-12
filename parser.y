%{
#include "TableSymboles.h"
#include <stdio.h>
#include <stdlib.h>
int yylex();
extern FILE *yyin;
int yyerror(const char *s);

SYMTABLE *TS;
%}

%union {
    double real;
    int integer;
    int boolean;
    NODESYMTABLE *id;
    char *string;
    int type;
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
%token <type>ENDPROG
%token <type>KEYFUN
token KEYARRAY
%token ASSIGN
%token <type>KEYVAR
%token <type>KEYCONST
%token KEYIF
%token KEYELSE
%token KEYTHEN
%token TYPEINT TYPEREAL TYPEBOOL TYPESTR
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
    {TS = initialiserTS();}
    header
    SECTDEFKEY MODELS CURLYSTART functions CURLYEND END
    SECTDEFKEY MAIN CURLYSTART ins_seq CURLYEND END
    KEY ENDPROG {printf("u got it right\n"); afficherTS(TS); }
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
    KEYVAR IDENTIFIER TWODOTS dectype END {setType(TS, $2->info.Token, $4); setTokenType(TS, $2->info.Token, $1);}
    | KEYVAR IDENTIFIER TWODOTS dectype ASSIGN EXP END {setTokenType(TS, $2->info.Token, $1);}
    | KEYARRAY IDENTIFIER CURLYSTART dectype CURLYEND BRACKETSTART EXP BRACKETEND END {setType(TS, $2->info.Token, $4); setTokenType(TS, $2->info.Token, $1);}//array 
    | KEYARRAY IDENTIFIER CURLYSTART dectype CURLYEND BRACKETSTART EXP BRACKETEND ASSIGN BRACKETSTART types BRACKETEND END  {setTokenType(TS, $2->info.Token, $1);}//array

    ;

constdeclaration : 
    KEYCONST IDENTIFIER TWODOTS dectype ASSIGN EXP END {setTokenType(TS, $2->info.Token, $1);}
    ;

assignment : 
    IDENTIFIER ASSIGN EXP END 
    | listelement ASSIGN EXP END /* assign to list element */
    ;

condition : 
    KEYIF PARENTESESTART EXP PARENTESEEND KEYTHEN CURLYSTART ins_seq CURLYEND
    | KEYIF PARENTESESTART EXP PARENTESEEND KEYTHEN CURLYSTART ins_seq CURLYEND KEYELSE CURLYSTART ins_seq CURLYEND
    ;

EXP : 
     TERM
     | IDENTIFIER PARENTESESTART arguments PARENTESEEND /* function call */
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
     | PARENTESESTART EXP PARENTESEEND
    ;
listelement :
    IDENTIFIER BRACKETSTART EXP BRACKETEND
    ;

dectype : 
    DECBOOL {$$ = yylval.type;}
    | DECINT {$$ = yylval.type;}
    | DECREAL {$$ = yylval.type;}
    | DECSTR {$$ = yylval.type;}
    ;

type : 
    TYPEBOOL 
    | TYPEINT
    | TYPEREAL
    | TYPESTR
    ;

types : 
    type
    | types COMMA type
    |
    ;

TERM : 
    IDENTIFIER
    | type 
    | listelement
    ;
%%
int yyerror(const char *s) {
  printf("%s\n",s);
}

int main(int argc, char *argv[]) {
    yyin = fopen("testTS.txt", "r");
    yyparse();
    fclose(yyin);
    return 0;
}