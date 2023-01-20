/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "parser.y"

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

/* Line 371 of yacc.c  */
#line 87 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
     IDENTIFIER = 266,
     ENDPROG = 267,
     KEYFUN = 268,
     KEYARRAY = 269,
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
/* Line 387 of yacc.c  */
#line 20 "parser.y"

    char *value;
    char *id;
    int type;
    struct {
        char* value;
        char* id;
        int type;
    } compose;

    


/* Line 387 of yacc.c  */
#line 193 "parser.tab.c"
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

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 221 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNRULES -- Number of states.  */
#define YYNSTATES  153

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    21,    25,    26,    29,    40,    41,
      43,    47,    48,    50,    52,    54,    56,    58,    60,    62,
      64,    66,    72,    78,    80,    84,    85,    87,    89,    95,
     103,   113,   127,   135,   140,   146,   153,   158,   163,   165,
     169,   173,   177,   181,   185,   189,   193,   197,   201,   205,
     209,   213,   217,   222,   224,   226,   228,   230,   232,   234,
     236,   238,   240,   244,   245,   247,   249,   251
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      51,     0,    -1,    -1,    52,    53,     5,     8,     6,    55,
       7,    10,     5,     9,     6,    54,     7,    10,     3,    12,
      -1,     3,     4,    11,    -1,    -1,    58,    54,    -1,    13,
      11,    34,    56,    35,    25,    57,     6,    54,     7,    -1,
      -1,    11,    -1,    56,    30,    11,    -1,    -1,    28,    -1,
      26,    -1,    27,    -1,    29,    -1,    62,    -1,    65,    -1,
      66,    -1,    59,    -1,    60,    -1,    31,    34,    69,    35,
      10,    -1,    11,    34,    61,    35,    10,    -1,    69,    -1,
      61,    30,    69,    -1,    -1,    63,    -1,    64,    -1,    16,
      11,    25,    71,    10,    -1,    16,    11,    25,    71,    15,
      69,    10,    -1,    14,    11,     6,    71,     7,    32,    69,
      33,    10,    -1,    14,    11,     6,    71,     7,    32,    69,
      33,    15,    32,    73,    33,    10,    -1,    17,    11,    25,
      71,    15,    69,    10,    -1,    11,    15,    69,    10,    -1,
      67,    20,     6,    54,     7,    -1,    67,    68,    19,     6,
      54,     7,    -1,    18,    34,    69,    35,    -1,    20,     6,
      54,     7,    -1,    74,    -1,    69,    39,    69,    -1,    69,
      40,    69,    -1,    69,    42,    69,    -1,    69,    41,    69,
      -1,    69,    43,    69,    -1,    69,    44,    69,    -1,    69,
      45,    69,    -1,    69,    46,    69,    -1,    69,    47,    69,
      -1,    69,    48,    69,    -1,    69,    37,    69,    -1,    69,
      36,    69,    -1,    34,    69,    35,    -1,    11,    32,    69,
      33,    -1,    28,    -1,    26,    -1,    27,    -1,    29,    -1,
      21,    -1,    23,    -1,    22,    -1,    24,    -1,    72,    -1,
      73,    30,    72,    -1,    -1,    75,    -1,    72,    -1,    11,
      -1,    70,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    87,    87,    87,    95,    98,    99,   103,   104,   108,
     109,   110,   114,   115,   116,   117,   121,   122,   123,   124,
     125,   129,   133,   137,   138,   139,   144,   145,   149,   157,
     174,   175,   180,   184,   208,   217,   226,   245,   268,   275,
     299,   324,   349,   390,   412,   433,   453,   473,   493,   514,
     579,   646,   652,   659,   660,   661,   662,   666,   667,   668,
     669,   672,   673,   674,   678,   683,   687,   692
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KEY", "PROGKEY", "SECTDEFKEY",
  "CURLYSTART", "CURLYEND", "MODELS", "MAIN", "END", "IDENTIFIER",
  "ENDPROG", "KEYFUN", "KEYARRAY", "ASSIGN", "KEYVAR", "KEYCONST", "KEYIF",
  "KEYELSE", "KEYTHEN", "TYPEINT", "TYPEREAL", "TYPEBOOL", "TYPESTR",
  "TWODOTS", "DECINT", "DECREAL", "DECBOOL", "DECSTR", "COMMA",
  "RETURNKEY", "BRACKETSTART", "BRACKETEND", "PARENTESESTART",
  "PARENTESEEND", "AND", "OR", "NOT", "PLUS", "MINUS", "MULT", "DIV",
  "SUP", "SUPEQ", "INF", "INFEQ", "EQ", "NEQ", "NEG", "$accept", "program",
  "$@1", "header", "ins_seq", "functions", "parameters", "returntype",
  "instruction", "returnn", "funcall", "arguments", "declaration",
  "vardeclaration", "constdeclaration", "assignment", "ifstatemnt",
  "first_part", "second_part", "EXP", "listelement", "dectype", "type",
  "types", "TERM", "Variable", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    51,    53,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    57,    57,    58,    58,    58,    58,
      58,    59,    60,    61,    61,    61,    62,    62,    63,    63,
      63,    63,    64,    65,    66,    66,    67,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    71,    71,    71,    71,    72,    72,    72,
      72,    73,    73,    73,    74,    74,    75,    75
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,    16,     3,     0,     2,    10,     0,     1,
       3,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     5,     1,     3,     0,     1,     1,     5,     7,
       9,    13,     7,     4,     5,     6,     4,     4,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     0,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,     4,     0,
       8,     0,     0,     0,     0,    11,     0,     9,     0,     0,
       0,     0,     0,    10,     0,     5,    13,    14,    12,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     5,    19,
      20,    16,    26,    27,    17,    18,     0,     5,     0,    25,
       0,     0,     0,     0,     0,     0,     6,     0,     0,     0,
      66,    57,    59,    58,    60,     0,     0,    67,    65,    38,
      64,     0,    23,     0,     0,     0,     0,     0,     0,     5,
       0,     7,     0,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      55,    53,    56,     0,     0,     0,    36,     0,     0,     0,
       5,     0,    51,    50,    49,    39,    40,    42,    41,    43,
      44,    45,    46,    47,    48,    24,    22,     0,    28,     0,
       0,    21,     3,    34,     0,    52,     0,     0,     0,    35,
       0,    29,    32,     0,    30,     0,    63,    61,     0,     0,
       0,    62,    31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    37,    12,    18,    30,    38,    39,
      40,    71,    41,    42,    43,    44,    45,    46,    58,    66,
      67,   103,    68,   148,    69,    70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -50
static const yytype_int16 yypact[] =
{
     -50,     9,    14,   -50,    26,    29,    79,    95,   -50,   109,
     118,   121,   128,   115,   153,   166,   185,   -50,   -27,   193,
     219,   178,   225,   -50,   188,     4,   -50,   -50,   -50,   -50,
     226,    -9,   222,   223,   224,   202,   203,   231,     4,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   220,     4,   -10,   -10,
     233,   216,   217,   -10,   -10,   234,   -50,   237,   227,   238,
     215,   -50,   -50,   -50,   -50,   -10,    13,   -50,   -50,   -50,
     -50,    -4,   152,   192,   192,   192,   111,   125,   245,     4,
     243,   -50,   -10,   139,   -50,   -10,   -10,   -10,   -10,   -10,
     -10,   -10,   -10,   -10,   -10,   -10,   -10,   -10,   240,   -50,
     -50,   -50,   -50,   244,    -8,   239,   -50,   242,   241,   248,
       4,    81,   -50,    24,   165,   -13,   -13,   -50,   -50,    37,
      37,    37,    37,   183,   183,   152,   -50,   228,   -50,   -10,
     -10,   -50,   -50,   246,   249,   -50,   -10,    52,    65,   -50,
      97,   -50,   -50,    17,   -50,   229,   205,   -50,    53,   205,
     247,   -50,   -50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -50,   -50,   -50,   -50,   -28,   -50,   -50,   -50,   -50,   -50,
     -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -50,   -49,
     -50,    -1,   -30,   -50,   -50,   -50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -38
static const yytype_int16 yytable[] =
{
      72,    60,   128,    20,    76,    77,    48,   129,    21,     3,
      56,    61,    62,    63,    64,    31,    83,     4,    32,    59,
      33,    34,    35,    84,    65,    49,    97,   144,    89,    90,
       6,    98,   145,   111,     7,    36,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    85,
      86,   109,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   141,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,   104,   105,   142,    87,    88,    89,    90,
     137,   138,   134,   149,    95,    96,   150,   140,    85,    86,
       8,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    85,    86,     9,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   135,    10,   147,    85,    86,   151,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     143,    11,    13,    85,    86,    14,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,   106,    85,    86,    15,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     107,    85,    86,    16,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   112,    85,    86,    17,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    85,    86,
      19,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    85,    22,    24,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    26,    27,    28,    29,    99,   100,
     101,   102,    87,    88,    89,    90,    61,    62,    63,    64,
      23,    25,    47,    50,    51,    52,    53,    54,    55,    73,
      57,    74,    75,    79,    78,    81,    80,    82,   108,   110,
     126,   127,   131,   132,   130,   133,   139,   152,     0,     0,
     136,   146,     0,     0,     0,   -37
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-50)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      49,    11,    10,    30,    53,    54,    15,    15,    35,     0,
      38,    21,    22,    23,    24,    11,    65,     3,    14,    47,
      16,    17,    18,    10,    34,    34,    30,    10,    41,    42,
       4,    35,    15,    82,     5,    31,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    36,
      37,    79,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    10,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    74,    75,    10,    39,    40,    41,    42,
     129,   130,   110,    30,    47,    48,    33,   136,    36,    37,
      11,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    36,    37,     8,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    33,     6,   146,    36,    37,   149,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      33,    13,    11,    36,    37,     7,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    35,    36,    37,    34,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      35,    36,    37,    10,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    35,    36,    37,    11,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    36,    37,
       5,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    36,     9,    25,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    26,    27,    28,    29,    26,    27,
      28,    29,    39,    40,    41,    42,    21,    22,    23,    24,
      11,     6,     6,    11,    11,    11,    34,    34,     7,     6,
      20,    25,    25,     6,    10,     7,    19,    32,     3,     6,
      10,     7,    10,    12,    15,     7,     7,    10,    -1,    -1,
      32,    32,    -1,    -1,    -1,    19
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,    52,     0,     3,    53,     4,     5,    11,     8,
       6,    13,    55,    11,     7,    34,    10,    11,    56,     5,
      30,    35,     9,    11,    25,     6,    26,    27,    28,    29,
      57,    11,    14,    16,    17,    18,    31,    54,    58,    59,
      60,    62,    63,    64,    65,    66,    67,     6,    15,    34,
      11,    11,    11,    34,    34,     7,    54,    20,    68,    54,
      11,    21,    22,    23,    24,    34,    69,    70,    72,    74,
      75,    61,    69,     6,    25,    25,    69,    69,    10,     6,
      19,     7,    32,    69,    10,    36,    37,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    30,    35,    26,
      27,    28,    29,    71,    71,    71,    35,    35,     3,    54,
       6,    69,    35,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    10,     7,    10,    15,
      15,    10,    12,     7,    54,    33,    32,    69,    69,     7,
      69,    10,    10,    33,    10,    15,    32,    72,    73,    30,
      33,    72,    10
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 87 "parser.y"
    {TS = initialiserTS(); TQ = initialiserTQ(); P = initialiserP();}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 91 "parser.y"
    {printf("u got it right\n"); afficherTS(TS); afficherTQ(TQ);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 149 "parser.y"
    {
        quad = creer_Q("DEC", (yyvsp[(2) - (5)].id) , "","" , quadCounter++);
        inserer_TQ(TQ, quad);
        if(execute) {
            setType(TS, (yyvsp[(2) - (5)].id), (yyvsp[(4) - (5)].type)); setTokenType(TS, (yyvsp[(2) - (5)].id), (yyvsp[(1) - (5)].type));
            }
        }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {
        quad = creer_Q("DEC", (yyvsp[(2) - (7)].id) , "", "", quadCounter++);
        inserer_TQ(TQ, quad);
        quad = creer_Q("=", (yyvsp[(6) - (7)].compose).value, "", (yyvsp[(2) - (7)].id), quadCounter++);
        inserer_TQ(TQ, quad);
       //printf("id = %s, exptype =  %d \n", $2, $6.type);
       if(execute) {
        if((yyvsp[(4) - (7)].type) == (yyvsp[(6) - (7)].compose).type || (yyvsp[(4) - (7)].type) == REAL && isNumeric((yyvsp[(6) - (7)].compose).type)) { 
            //if type is the same of if we're assigning a numeric expression (int or real) to real
            setTokenType(TS, (yyvsp[(2) - (7)].id), (yyvsp[(1) - (7)].type));
            setType(TS, (yyvsp[(2) - (7)].id), (yyvsp[(4) - (7)].type));
            setValue(TS, (yyvsp[(2) - (7)].id), (yyvsp[(6) - (7)].compose).value);

        } else {printf("incompatible type\n"); yyerror('c');}
       }
        //printf("after id = %s, exptype =  %d \n", $2, $6.type);
        }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    {setType(TS, (yyvsp[(2) - (9)].id), (yyvsp[(4) - (9)].type)); setTokenType(TS, (yyvsp[(2) - (9)].id), (yyvsp[(1) - (9)].type));}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    {setTokenType(TS, (yyvsp[(2) - (13)].id), (yyvsp[(1) - (13)].type));}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    {setTokenType(TS, (yyvsp[(2) - (7)].id), (yyvsp[(1) - (7)].type));}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 184 "parser.y"
    {
        //printf("\n execute %d \n", execute);
        quad = creer_Q("=", (yyvsp[(3) - (4)].compose).value, "", (yyvsp[(1) - (4)].id), quadCounter++);
        inserer_TQ(TQ, quad);
        if(execute) {
            NODESYMTABLE *node = rechercher(TS, (yyvsp[(1) - (4)].id));
            if(node == NULL) {
            printf("girl u cant assign to a non declared variable\n"); yyerror('c');
            }
            if((node->info.Type == (yyvsp[(3) - (4)].compose).type || node->info.Type == REAL && isNumeric((yyvsp[(3) - (4)].compose).type)) && node->info.TokenType == VAR) {
                //if type is the same of if we're assigning a numeric expression (int or real) to real
                setValue(TS, (yyvsp[(1) - (4)].id), (yyvsp[(3) - (4)].compose).value);
            } else {
                printf("incompatible type\n"); yyerror('c');}
            }
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 208 "parser.y"
    {
        //mise a jour d'adresses
        printf("\nIM HERE\n");
        quad = pop(P);
        afficherQ(quad);
        updateEtiq(quad, quadCounter);
         execute = 1; //get out
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    {
        quad = pop(P);
        afficherQ(quad);
        updateEtiq(quad, quadCounter);
        execute = 1; //get out
    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 226 "parser.y"
    {
        if((yyvsp[(3) - (4)].compose).type == BOOL) {
            //make quadruplet for thing 
            quad = creer_Q("BZ", "etiq", "", (yyvsp[(3) - (4)].compose).value, quadCounter++);
            inserer_TQ(TQ, quad);
            push(P, quad);
            if(strcmp((yyvsp[(3) - (4)].compose).value, "false") == 0){

            printf("false baby\n");
                //if the condition is false => skip instruction set
                execute = 0;
            }
        }
        else {
            printf("incompatible type\n"); yyerror('c');
        }
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 245 "parser.y"
    {
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
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 268 "parser.y"
    {
        strcpy((yyval.compose).value, (yyvsp[(1) - (1)].compose).value);
        (yyval.compose).type = (yyvsp[(1) - (1)].compose).type;

        }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 275 "parser.y"
    {
        printf("\ntypes %s %s \n \n ", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value);
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            float val = val1 + val2;
            char result[255];

            if(ceilf(val) == val){
                itoa((int)(val), result, 10);
                (yyval.compose).type = INT;
            } else {
                sprintf(result, "%.2f", val);
                (yyval.compose).type = REAL;
            }
            quad = creer_Q("+", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 299 "parser.y"
    {
        printf("types %d %d \n \n ", (yyvsp[(1) - (3)].compose).type, (yyvsp[(3) - (3)].compose).type);
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            float val = val1 - val2;
            char result[255];

            if(ceilf(val) == val){
                itoa((int)val, result, 10);
                (yyval.compose).type = INT;
            } else {
                sprintf(result, "%.2f", val);
                (yyval.compose).type = REAL;
            }
            quad = creer_Q("-", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }

     }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 324 "parser.y"
    {
        printf("types %d %d \n \n ", (yyvsp[(1) - (3)].compose).type, (yyvsp[(3) - (3)].compose).type);
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            float val = val1 / val2;
            char result[255];

            if(ceilf(val) == val){
                itoa((int)(val), result, 10);
                (yyval.compose).type = INT;
            } else {
                sprintf(result, "%.2f", val);
                (yyval.compose).type = REAL;
            }
            quad = creer_Q("%", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 349 "parser.y"
    {
        //printf("types %d %d \n \n ", $1.type, $3.type);
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            float val = val1 * val2;
            char result[255];

            if(ceilf(val) == val){
                itoa((int)(val), result, 10);
                (yyval.compose).type = INT;
            } else {
                sprintf(result, "%.2f", val);
                (yyval.compose).type = REAL;
            }
            quad = creer_Q("*", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 390 "parser.y"
    {
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            //printf("\nHOUNA \n");
            (yyval.compose).type = BOOL;
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            char result[255];

            if(val1 > val2) {
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }

            quad = creer_Q(">", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 412 "parser.y"
    {
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            (yyval.compose).type = BOOL;
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            char result[255];
            if(val1 >= val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q(">=", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 433 "parser.y"
    {
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            (yyval.compose).type = BOOL;
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            char result[255];
            if(val1 < val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q("<", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 453 "parser.y"
    {
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            (yyval.compose).type = BOOL;
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            char result[255];
            if(val1 <= val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q("<=", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 473 "parser.y"
    {
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            (yyval.compose).type = BOOL;
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            char result[255];
            if(val1 == val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q("==", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 493 "parser.y"
    {
        if(isNumeric((yyvsp[(1) - (3)].compose).type) && isNumeric((yyvsp[(3) - (3)].compose).type)) {
            (yyval.compose).type = BOOL;
            float val1 = atof((yyvsp[(1) - (3)].compose).value);
            float val2 = atof((yyvsp[(3) - (3)].compose).value);
            char result[255];
            if(val1 != val2) {
                //expression is true
                strcpy(result, "true");
            } else {
                strcpy(result, "false");
            }
            quad = creer_Q("!=", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);
            strcpy((yyval.compose).value, result);
        } else {
            printf("Erreur Semantique : Type incompatible\n");
            yyerror('c');
        }
     }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 514 "parser.y"
    {
        printf("\nI am an OR condition\n");
        char result[255];
        //Check first expression before or
        if(strcmp((yyvsp[(1) - (3)].compose).value, "true") == 0){
            
            printf("\nThe first condition has a value of\n");
            printf((yyvsp[(1) - (3)].compose).value);
            printf("\nWhole condition\n");
            strcpy(result, "true");

            quad = creer_Q("||", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);

            strcpy((yyval.compose).value, result);
            printf("\n %s",(yyval.compose).value);
            printf("\n------------------------\n");
        }
        else if (strcmp((yyvsp[(1) - (3)].compose).value, "false") == 0)
        {
            printf("\nThe first condition has a value of\n");
            printf((yyvsp[(1) - (3)].compose).value);

            //Check second expression after or when the first value is false
            if(strcmp((yyvsp[(3) - (3)].compose).value, "true") == 0){
            
                printf("\nThe second condition has a value of\n");
                printf((yyvsp[(3) - (3)].compose).value);
                printf("\nWhole condition\n");
                strcpy(result, "true");

                quad = creer_Q("||", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
                inserer_TQ(TQ, quad);

                strcpy((yyval.compose).value, result);
                printf("\n %s",(yyval.compose).value);
                printf("\n------------------------\n");
            }
            else if (strcmp((yyvsp[(3) - (3)].compose).value, "false") == 0)
            {
                printf("\nThe second condition has a value of\n");
                printf((yyvsp[(3) - (3)].compose).value);
                printf("\nWhole condition\n");
                strcpy(result, "false");

                quad = creer_Q("||", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
                inserer_TQ(TQ, quad);

                strcpy((yyval.compose).value, result);
                printf("\n %s",(yyval.compose).value);
            }
            else
            {
                printf("\nError, the condition should be a boolean expression\n");
                yyerror('c');
            }
        }
        else 
        {
            printf("\nError, the condition should be a boolean expression\n");
            yyerror('c');
        }

     }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 579 "parser.y"
    {
        printf("\nI am an AND condition\n");
        char result[255];

        //Check first expression before and
        if(strcmp((yyvsp[(1) - (3)].compose).value, "false") == 0){
            
            printf("\nThe first condition has a value of\n");
            printf((yyvsp[(1) - (3)].compose).value);
            printf("\nWhole condition\n");
            strcpy(result, "false");

            quad = creer_Q("&&", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
            inserer_TQ(TQ, quad);

            strcpy((yyval.compose).value, result);
            printf("\n %s",(yyval.compose).value);
            printf("\n------------------------\n");
        }
        else if (strcmp((yyvsp[(1) - (3)].compose).value, "true") == 0)
        {
            printf("\nThe first condition has a value of\n");
            printf((yyvsp[(1) - (3)].compose).value);

            //Check second expression after and when the first value is true
            if(strcmp((yyvsp[(3) - (3)].compose).value, "true") == 0){
            
                printf("\nThe second condition has a value of\n");
                printf((yyvsp[(3) - (3)].compose).value);
                printf("\nWhole condition\n");
                strcpy(result, "true");

                quad = creer_Q("&&", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
                inserer_TQ(TQ, quad);

                strcpy((yyval.compose).value, result);
                printf("\n %s",(yyval.compose).value);
                printf("\n------------------------\n");
            }
            else if (strcmp((yyvsp[(3) - (3)].compose).value, "false") == 0)
            {
                printf("\nThe second condition has a value of\n");
                printf((yyvsp[(3) - (3)].compose).value);
                printf("\nWhole condition\n");
                strcpy(result, "false");

                quad = creer_Q("&&", (yyvsp[(1) - (3)].compose).value, (yyvsp[(3) - (3)].compose).value, result, quadCounter++);
                inserer_TQ(TQ, quad);

                strcpy((yyval.compose).value, result);
                printf("\n %s",(yyval.compose).value);
                printf("\n------------------------\n");
            }
            else
            {
                printf("\nError, the condition should be a boolean expression\n");
                yyerror('c');
            }
        }
        else 
        {
            printf("\nError, the condition should be a boolean expression\n");
            yyerror('c');
        }

     }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 646 "parser.y"
    {
        (yyval.compose).value = (yyvsp[(2) - (3)].compose).value;
        (yyval.compose).type = (yyvsp[(2) - (3)].compose).type;
     }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 652 "parser.y"
    {
        NODESYMTABLE *node = rechercher(TS, (yyvsp[(1) - (4)].id));
        strcpy((yyval.compose).type, node->info.Type);
        }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 659 "parser.y"
    {(yyval.type) = yylval.type;}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 660 "parser.y"
    {(yyval.type) = yylval.type;}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 661 "parser.y"
    {(yyval.type) = yylval.type;}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 662 "parser.y"
    {(yyval.type) = yylval.type;}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 666 "parser.y"
    {(yyval.compose).value = yylval.value; (yyval.compose).type = INT;}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 667 "parser.y"
    {(yyval.compose).value = yylval.value; (yyval.compose).type = BOOL;}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 668 "parser.y"
    {(yyval.compose).value = yylval.value; (yyval.compose).type = REAL;}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 669 "parser.y"
    {(yyval.compose).value = yylval.value; (yyval.compose).type = STR;}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 678 "parser.y"
    {
        printf("hello");
        strcpy((yyval.compose).value, (yyvsp[(1) - (1)].compose).value);
        (yyval.compose).type =  (yyvsp[(1) - (1)].compose).type;
        }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 683 "parser.y"
    { strcpy((yyval.compose).value, (yyvsp[(1) - (1)].compose).value); (yyval.compose).type = (yyvsp[(1) - (1)].compose).type;}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 687 "parser.y"
    {
    NODESYMTABLE *node = rechercher(TS, (yyvsp[(1) - (1)].id));
    strcpy((yyval.compose).value, node->info.Value);
    (yyval.compose).type =  node->info.Type;
    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 692 "parser.y"
    {strcpy((yyval.compose).value, (yyvsp[(1) - (1)].compose).value);}
    break;


/* Line 1792 of yacc.c  */
#line 2238 "parser.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 693 "parser.y"

int yyerror(const char *s) {
  printf("error %s\n",s);
}

int main(int argc, char *argv[]) {
    yyin = fopen("testQD.txt", "r");
    yyparse();
    fclose(yyin);
    return 0;
}