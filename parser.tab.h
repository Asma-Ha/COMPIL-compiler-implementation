/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KEY = 258,
     PROGKEY = 259,
     SECTDEFKEY = 260,
     CURLYSTART = 261,
     CURLYEND = 262,
     TYPES = 263,
     MODELS = 264,
     MAIN = 265,
     END = 266,
     IDENTIFIER = 267,
     ENDPROG = 268,
     FUNKEY = 269,
     ASSIGN = 270,
     KEYVAR = 271,
     KEYCONST = 272,
     KEYIF = 273,
     KEYELSE = 274,
     KEYTHEN = 275,
     TYPEINT = 276,
     TYPEREAL = 277,
     TYPEBOOL = 278,
     TYPESTR = 279,
     TWODOTS = 280,
     DECINT = 281,
     DECREAL = 282,
     DECBOOL = 283,
     DECSTR = 284,
     COMMA = 285,
     RETURNKEY = 286,
     BRACKETSTART = 287,
     BRACKETEND = 288,
     PARENTESESTART = 289,
     PARENTESEEND = 290,
     AND = 291,
     OR = 292,
     NOT = 293,
     PLUS = 294,
     MINUS = 295,
     MULT = 296,
     DIV = 297,
     SUP = 298,
     SUPEQ = 299,
     INF = 300,
     INFEQ = 301,
     EQ = 302,
     NEQ = 303,
     NEG = 304
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 11 "parser.y"

    double real;
    int integer;
    char *string;
    char type[255];


/* Line 2058 of yacc.c  */
#line 114 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
