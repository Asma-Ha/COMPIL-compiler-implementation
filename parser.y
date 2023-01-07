%{
#include <stdio.h>
#include <stdlib.h>
extern FILE *yyin;
int yylex();
int yyerror(const char *s);

%}


%union {
    double real;
    int integer;
    char *string;
    char type[255];
}

%token KEY
%token PROGKEY
%token SECTDEFKEY
%token CURLYSTART
%token CURLYEND
%token TYPES
%token MODELS
%token MAIN
%token END
%token IDENTIFIER
%token ENDPROG
%token FUNKEY
%token ASSIGN
%token KEYVAR
%token KEYCONST
%token KEYIF
%token KEYELSE
%token KEYTHEN
%token TYPEINT TYPEREAL TYPEBOOL TYPESTR
%token TWODOTS
%token  DECINT DECREAL DECBOOL DECSTR
%token COMMA
%token RETURNKEY
%token BRACKETSTART
%token BRACKETEND
%token PARENTESESTART PARENTESEEND
%token AND OR NOT
%token PLUS MINUS MULT DIV
%token SUP SUPEQ INF INFEQ EQ NEQ

%left PLUS MINUS
%left MULT DIV
%left NEG

%start program


%%

program : 
    header
    SECTDEFKEY MODELS CURLYSTART functions CURLYEND END
    SECTDEFKEY MAIN CURLYSTART ins_seq CURLYEND END
    KEY ENDPROG {printf("u got it right\n");}
    ;

header :  
    KEY PROGKEY IDENTIFIER
    ;

ins_seq : 
    | instruction ins_seq
    ;

functions : 
    FUNKEY IDENTIFIER PARENTESESTART parameters PARENTESEEND TWODOTS returntype CURLYSTART ins_seq CURLYEND
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
    KEYVAR IDENTIFIER TWODOTS dectype END
    | KEYVAR IDENTIFIER TWODOTS dectype ASSIGN EXP END 
    | KEYVAR IDENTIFIER CURLYSTART dectype CURLYEND BRACKETSTART EXP BRACKETEND END
    | KEYVAR IDENTIFIER CURLYSTART dectype CURLYEND BRACKETSTART EXP BRACKETEND ASSIGN BRACKETSTART types BRACKETEND END

    ;

constdeclaration : 
    KEYCONST IDENTIFIER TWODOTS dectype ASSIGN EXP END 
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
     IDENTIFIER PARENTESESTART arguments PARENTESEEND /* function call */
     | AEXP
    ;

AEXP : 
    TERM 
    | AEXP PLUS AEXP
    | AEXP MINUS AEXP
    | AEXP DIV AEXP
    | AEXP MULT AEXP
    | PARENTESESTART AEXP PARENTESEEND
    | MINUS AEXP %prec NEG
    ;

listelement :
    IDENTIFIER BRACKETSTART EXP BRACKETEND
    ;

dectype : 
    DECBOOL
    | DECINT
    | DECREAL
    | DECSTR
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
    yyin = fopen("test_expressions.txt", "r");
    yyparse();
    fclose(yyin);
    return 0;
}