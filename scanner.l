%{
    /*definition section */
    #include "parser.tab.h"
    #include <stdio.h>
    #include "TableSymboles.c"
    SYMTABLE *TS; 
    int yyerror(const char *s);
    int cptLigne;
%}

%option noyywrap 

blank [ \t]+
MAJ [A-Z]
MIN [a-z]
DIGIT [0-9]
EOL [\n]
TYPES types
MODELS models
MAIN main

BOOL "true"|"false"
STRING \".*\"

%x comment 


%%
"#" return (KEY);
"program" return (PROGKEY);
"def" return (SECTDEFKEY);
"end" return (ENDPROG);
"{" return (CURLYSTART);
"}" return (CURLYEND);
"(" return (PARENTESESTART);
")" return (PARENTESEEND);
"[" return (BRACKETSTART);
"]" return (BRACKETEND);
"+" return (PLUS);
"-" return (MINUS);
"*" return (MULT);
"%" return (DIV);
">" return (SUP);
">=" return (SUPEQ);
"<" return (INF);
"<=" return (INFEQ);
"==" return (EQ);
"!=" return (NEQ);
"∧" return (AND);
"∨" return (OR);
"!" return(NOT);

"$" {BEGIN(comment); /*start comment state*/}
<comment>"$" {BEGIN(INITIAL); /*when finding a $ => go back to regular state*/}
<comment>\n {/* do nothing */}
<comment>. {/* do nothing */}
{TYPES} return (TYPES);
{MODELS} return (MODELS);
{MAIN} return (MAIN);
{blank}  { /* ignore whitespace */ }
";" return (END);
{EOL} { cptLigne++; /* ignore lines */ };
"var" return (KEYVAR);
"const" return (KEYCONST);
"if" return (KEYIF);
"then" return (KEYTHEN);
"else" return (KEYELSE);
":" return (TWODOTS);
"=" return (ASSIGN);
"fun" return (FUNKEY);
"," return (COMMA);
"return" return (RETURNKEY);

"str" {
    //declarative keyword : str
    strcpy(yylval.type, "str");
    return (DECSTR);
    }

"int" {
    strcpy(yylval.type, "int");
    return (DECINT);
}
"bool" {
    strcpy(yylval.type, "bool");
    return (DECBOOL);
}

"real" {
    strcpy(yylval.type, "real");
    return (DECREAL);
}


{DIGIT}+ {
    yylval.integer = atoi(yytext);
    return (TYPEINT);
}

{DIGIT}+("."{DIGIT}*) {
    yylval.real = strtod(yytext, NULL);
    return (TYPEREAL);
    }
{BOOL} return (TYPEBOOL);
{STRING} {
    yylval.string = yytext;
    return (TYPESTR);
    }

{MIN}({MIN}*{MAJ}*{DIGIT}*)* {
    TS = inserer(TS, yytext, "id");
    return (IDENTIFIER);
}


. {
    fprintf(stderr,"\tERREUR : a la ligne %d. Il s'agit de %s et comporte %d lettre(s)\n",cptLigne,yytext,yyleng);
}

%%
