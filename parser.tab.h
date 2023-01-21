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
     MODELS = 263,
     MAIN = 264,
     END = 265,
     KEYFOR = 266,
     IDENTIFIER = 267,
     ENDPROG = 268,
     KEYARRAY = 269,
     ASSIGN = 270,
     KEYVAR = 271,
     KEYCONST = 272,
     KEYIF = 273,
     KEYELSE = 274,
     KEYTHEN = 275,
     KEYWHILE = 276,
     KEYDO = 277,
     TYPEINT = 278,
     TYPEREAL = 279,
     TYPEBOOL = 280,
     TYPESTR = 281,
     TWODOTS = 282,
     DECINT = 283,
     DECREAL = 284,
     DECBOOL = 285,
     DECSTR = 286,
     COMMA = 287,
     RETURNKEY = 288,
     BRACKETSTART = 289,
     BRACKETEND = 290,
     PARENTESESTART = 291,
     PARENTESEEND = 292,
     AND = 293,
     OR = 294,
     NOT = 295,
     PLUS = 296,
     MINUS = 297,
     MULT = 298,
     DIV = 299,
     SUP = 300,
     SUPEQ = 301,
     INF = 302,
     INFEQ = 303,
     EQ = 304,
     NEQ = 305
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 22 "parser.y"

    char *value;
    char *id;
    int type;
    struct {
        char* value;
        char* id;
        int type;
    } compose;




/* Line 2058 of yacc.c  */
#line 121 "parser.tab.h"
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
