
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "definitions.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType *functionsOpr(nodeType* preFuns, nodeType* newFun);
nodeType* conFloat(double value);
nodeType *conInt(int value);
nodeType* conString(char* value);
int defSym(char* name, int type, bool isVar, bool isInitialized);
int getIndex(char* varName);
nodeType *id(int index);
void freeNode(nodeType *p);
//extern int ex(nodeType *p);
extern int exMain(nodeType *p);
extern FILE *yyin;
int yylex(void);

void yyerror(char *s);

int nextSymNum = 0;
int yydebug=1;
bool hasNoErrors = True;

symbolEntry* sym[MAXNUMOFSYMS];                    /* symbol table */


/* Line 189 of yacc.c  */
#line 106 "yacc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INTNUM = 258,
     FLOATNUM = 259,
     QUOTESTRING = 260,
     IDENTIFIER = 261,
     WHILE = 262,
     FOR = 263,
     REPEAT = 264,
     UNTIL = 265,
     SWITCH = 266,
     CASE = 267,
     DEFAULT = 268,
     IF = 269,
     PRINT = 270,
     DEF = 271,
     AS = 272,
     VAR = 273,
     CONST = 274,
     INT = 275,
     FLOAT = 276,
     STRING = 277,
     FUN = 278,
     BODY = 279,
     FUNCTIONS = 280,
     CALL = 281,
     IFX = 282,
     ELSE = 283,
     NE = 284,
     EQ = 285,
     LE = 286,
     GE = 287
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 35 "yacc.y"

    double fValue;              /* Floating deciamal value */
    int iValue;                 /* integer value */
    char* sValue;              /* String value */
    char* varName;             /* variable Name */
    nodeType *nPtr;             /* node pointer */



/* Line 214 of yacc.c  */
#line 184 "yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 196 "yacc.tab.c"

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
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  151

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,     2,
      46,    44,    37,    35,     2,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      30,    45,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    40,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    17,    20,    23,    24,
      27,    30,    33,    36,    45,    54,    63,    70,    77,    84,
      93,   102,   111,   113,   117,   122,   128,   137,   145,   151,
     157,   165,   169,   173,   175,   178,   181,   187,   191,   196,
     198,   201,   205,   209,   213,   217,   221,   225,   229,   231,
     235,   239,   241,   243,   245,   247,   251,   255,   259,   263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    -1,    49,    50,    -1,    -1,    16,
       6,    17,    23,    41,    51,    42,    -1,    51,    53,    -1,
      51,    52,    -1,    -1,     1,    43,    -1,     1,    42,    -1,
       1,    44,    -1,     1,     9,    -1,    16,     6,    17,    20,
      18,    45,    60,    43,    -1,    16,     6,    17,    21,    18,
      45,    60,    43,    -1,    16,     6,    17,    22,    18,    45,
      60,    43,    -1,    16,     6,    17,    20,    18,    43,    -1,
      16,     6,    17,    21,    18,    43,    -1,    16,     6,    17,
      22,    18,    43,    -1,    16,     6,    17,    20,    19,    45,
      60,    43,    -1,    16,     6,    17,    21,    19,    45,    60,
      43,    -1,    16,     6,    17,    22,    19,    45,    60,    43,
      -1,    43,    -1,    15,    60,    43,    -1,     6,    45,    60,
      43,    -1,     7,    46,    59,    44,    53,    -1,     8,    46,
      53,    59,    43,    53,    44,    53,    -1,     9,    53,    10,
      46,    59,    44,    43,    -1,    11,    46,    60,    44,    56,
      -1,    14,    46,    59,    44,    53,    -1,    14,    46,    59,
      44,    53,    28,    53,    -1,    41,    54,    42,    -1,    26,
       6,    43,    -1,    53,    -1,    54,    53,    -1,    13,    53,
      -1,    12,    46,    60,    44,    53,    -1,    41,    57,    42,
      -1,    41,    57,    55,    42,    -1,    56,    -1,    57,    56,
      -1,    60,    30,    60,    -1,    60,    29,    60,    -1,    60,
      34,    60,    -1,    60,    33,    60,    -1,    60,    31,    60,
      -1,    60,    32,    60,    -1,    46,    59,    44,    -1,    58,
      -1,    59,    40,    58,    -1,    59,    39,    58,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,    60,    35,    60,
      -1,    60,    36,    60,    -1,    60,    37,    60,    -1,    60,
      38,    60,    -1,    46,    60,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    64,    66,    69,    72,    73,    74,    78,
      79,    80,    81,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   108,   109,   113,   117,   118,   119,   123,
     124,   129,   130,   131,   132,   133,   134,   135,   139,   140,
     141,   144,   145,   146,   147,   148,   149,   150,   151,   152
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTNUM", "FLOATNUM", "QUOTESTRING",
  "IDENTIFIER", "WHILE", "FOR", "REPEAT", "UNTIL", "SWITCH", "CASE",
  "DEFAULT", "IF", "PRINT", "DEF", "AS", "VAR", "CONST", "INT", "FLOAT",
  "STRING", "FUN", "BODY", "FUNCTIONS", "CALL", "IFX", "ELSE", "'>'",
  "'<'", "NE", "EQ", "LE", "GE", "'+'", "'-'", "'*'", "'/'", "'&'", "'|'",
  "'{'", "'}'", "';'", "')'", "'='", "'('", "$accept", "program",
  "functions", "function", "fun_body", "err_stmt", "stmt", "stmt_list",
  "defult_stmt", "case_stmt", "case_list", "logic_expr", "logic_list",
  "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    62,
      60,   284,   285,   286,   287,    43,    45,    42,    47,    38,
     124,   123,   125,    59,    41,    61,    40
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    51,    51,    51,    52,
      52,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    60,    60
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     7,     2,     2,     0,     2,
       2,     2,     2,     8,     8,     8,     6,     6,     6,     8,
       8,     8,     1,     3,     4,     5,     8,     7,     5,     5,
       7,     3,     3,     1,     2,     2,     5,     3,     4,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     3,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,    22,     7,     6,    12,    10,     9,    11,
       0,     0,     0,     0,     0,     0,    51,    52,    53,    54,
       0,     0,     0,     0,    33,     0,     0,     0,    48,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,    32,    31,    34,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    55,    56,    57,    58,     0,     0,     0,    47,
      50,    49,    25,    42,    41,    45,    46,    44,    43,     0,
       0,     0,     0,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,     0,     0,    16,     0,     0,
      17,     0,     0,    18,     0,     0,     0,    27,     0,     0,
      37,     0,    40,    30,     0,     0,     0,     0,     0,     0,
      26,     0,    35,    38,    13,    19,    14,    20,    15,    21,
      36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,    10,    24,    25,    45,   131,   103,
     115,    48,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int16 yypact[] =
{
     -89,    12,    10,   -89,    16,   -89,    17,    22,     8,   -89,
      89,    -4,     9,    24,    46,   140,    53,    56,    -2,    52,
     104,   140,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
      -2,     5,   140,   113,    -2,     5,   -89,   -89,   -89,   -89,
      -2,   162,   112,   102,   -89,   127,   166,     5,   -89,   -24,
     158,     5,    91,    45,   -16,    50,    -2,    -2,    -2,    -2,
     -89,    51,   -89,   -89,   -89,   -89,     2,   142,     5,     5,
     140,    -2,    -2,    -2,    -2,    -2,    -2,    -8,     5,    -5,
     140,   -89,    26,    26,   -89,   -89,    94,    99,   101,   -89,
     -89,   -89,   -89,    31,    31,    31,    31,    31,    31,   140,
      13,    98,    -5,   -89,   122,    48,   107,    63,   117,    64,
     118,   120,   114,    -2,   -89,     6,   140,   -89,    -2,    -2,
     -89,    -2,    -2,   -89,    -2,    -2,   140,   -89,   123,   140,
     -89,   143,   -89,   -89,   175,   179,   188,   192,   201,   205,
     -89,   140,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,   -89,   -89,   -89,   -15,   -89,   -89,   -88,
     -89,    71,   -22,     3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,    36,    37,    38,    39,    26,    44,   101,    36,    37,
      38,    39,     3,    54,   114,    68,    69,    51,   101,   129,
      70,    41,     6,    68,    69,    66,     4,   132,    80,    77,
      64,    68,    69,    46,     7,    99,   102,    53,    27,    28,
      29,    68,    69,    55,    40,     8,    89,   102,   130,     9,
      67,    47,    68,    69,    30,    92,   100,   112,    42,    82,
      83,    84,    85,    58,    59,   104,    56,    57,    58,    59,
      31,    86,    87,    88,    93,    94,    95,    96,    97,    98,
      56,    57,    58,    59,   111,    56,    57,    58,    59,    79,
      11,   117,    32,   118,    81,    12,    13,    14,    15,    34,
      16,   133,    35,    17,    18,    19,   120,   123,   121,   124,
      43,   140,   105,   106,   142,    20,   128,   107,   108,   109,
     110,   134,   135,    52,   136,   137,   150,   138,   139,    61,
      21,    22,    23,    12,    13,    14,    15,    78,    16,    90,
      91,    17,    18,    19,   113,    62,    12,    13,    14,    15,
     116,    16,   119,    20,    17,    18,    19,   127,    56,    57,
      58,    59,   122,   125,   126,     0,    20,   141,    21,    63,
      23,    71,    72,    73,    74,    75,    76,    56,    57,    58,
      59,    21,     0,    23,     0,   143,    81,    71,    72,    73,
      74,    75,    76,    56,    57,    58,    59,    56,    57,    58,
      59,    56,    57,    58,    59,    60,     0,     0,     0,    65,
      56,    57,    58,    59,    56,    57,    58,    59,   144,     0,
       0,     0,   145,    56,    57,    58,    59,    56,    57,    58,
      59,   146,     0,     0,     0,   147,    56,    57,    58,    59,
      56,    57,    58,    59,   148,     0,     0,     0,   149
};

static const yytype_int16 yycheck[] =
{
      15,     3,     4,     5,     6,     9,    21,    12,     3,     4,
       5,     6,     0,    35,   102,    39,    40,    32,    12,    13,
      44,    18,     6,    39,    40,    47,    16,   115,    44,    51,
      45,    39,    40,    30,    17,    43,    41,    34,    42,    43,
      44,    39,    40,    40,    46,    23,    44,    41,    42,    41,
      47,    46,    39,    40,    45,    70,    78,    44,     6,    56,
      57,    58,    59,    37,    38,    80,    35,    36,    37,    38,
      46,    20,    21,    22,    71,    72,    73,    74,    75,    76,
      35,    36,    37,    38,    99,    35,    36,    37,    38,    44,
       1,    43,    46,    45,    44,     6,     7,     8,     9,    46,
      11,   116,    46,    14,    15,    16,    43,    43,    45,    45,
       6,   126,    18,    19,   129,    26,   113,    18,    19,    18,
      19,   118,   119,    10,   121,   122,   141,   124,   125,    17,
      41,    42,    43,     6,     7,     8,     9,    46,    11,    68,
      69,    14,    15,    16,    46,    43,     6,     7,     8,     9,
      28,    11,    45,    26,    14,    15,    16,    43,    35,    36,
      37,    38,    45,    45,    44,    -1,    26,    44,    41,    42,
      43,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    41,    -1,    43,    -1,    42,    44,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    35,    36,    37,
      38,    35,    36,    37,    38,    43,    -1,    -1,    -1,    43,
      35,    36,    37,    38,    35,    36,    37,    38,    43,    -1,
      -1,    -1,    43,    35,    36,    37,    38,    35,    36,    37,
      38,    43,    -1,    -1,    -1,    43,    35,    36,    37,    38,
      35,    36,    37,    38,    43,    -1,    -1,    -1,    43
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    48,    49,     0,    16,    50,     6,    17,    23,    41,
      51,     1,     6,     7,     8,     9,    11,    14,    15,    16,
      26,    41,    42,    43,    52,    53,     9,    42,    43,    44,
      45,    46,    46,    53,    46,    46,     3,     4,     5,     6,
      46,    60,     6,     6,    53,    54,    60,    46,    58,    59,
      60,    53,    10,    60,    59,    60,    35,    36,    37,    38,
      43,    17,    43,    42,    53,    43,    59,    60,    39,    40,
      44,    29,    30,    31,    32,    33,    34,    59,    46,    44,
      44,    44,    60,    60,    60,    60,    20,    21,    22,    44,
      58,    58,    53,    60,    60,    60,    60,    60,    60,    43,
      59,    12,    41,    56,    53,    18,    19,    18,    19,    18,
      19,    53,    44,    46,    56,    57,    28,    43,    45,    45,
      43,    45,    45,    43,    45,    45,    44,    43,    60,    13,
      42,    55,    56,    53,    60,    60,    60,    60,    60,    60,
      53,    44,    53,    42,    43,    43,    43,    43,    43,    43,
      53
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

/* Prevent warnings from -Wmissing-prototypes.  */
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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

/* Line 1455 of yacc.c  */
#line 61 "yacc.y"
    { exMain((yyvsp[(1) - (1)].nPtr)); freeNode((yyvsp[(1) - (1)].nPtr)); exit(0); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 64 "yacc.y"
    { if((yyvsp[(1) - (2)].nPtr) != NULL) (yyval.nPtr) = functionsOpr((yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr));
                                  else (yyval.nPtr) = opr(FUNCTIONS, 1, (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 66 "yacc.y"
    {(yyval.nPtr) = NULL;;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 69 "yacc.y"
    {(yyval.nPtr) = opr(FUN, 2, id(defSym((yyvsp[(2) - (7)].varName), 3, False, True)), (yyvsp[(6) - (7)].nPtr));;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 72 "yacc.y"
    { if((yyvsp[(1) - (2)].nPtr) != NULL) (yyval.nPtr) = opr(BODY, 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); else  (yyval.nPtr) = opr(BODY, 1, (yyvsp[(2) - (2)].nPtr));;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 73 "yacc.y"
    {;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 74 "yacc.y"
    {(yyval.nPtr) = NULL;;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 78 "yacc.y"
    { hasNoErrors = False; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 79 "yacc.y"
    { hasNoErrors = False; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 80 "yacc.y"
    { hasNoErrors = False; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 81 "yacc.y"
    { hasNoErrors = False; ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 85 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 0, True, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 86 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 1, True, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 87 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 2, True, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 88 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 1, id(defSym((yyvsp[(2) - (6)].varName), 0, True, False))); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 89 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 1, id(defSym((yyvsp[(2) - (6)].varName), 1, True, False))); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 90 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 1, id(defSym((yyvsp[(2) - (6)].varName), 2, True, False))); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 91 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 0, False, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 92 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 1, False, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 93 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 2, False, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 94 "yacc.y"
    { (yyval.nPtr) = opr(';', 2, NULL, NULL); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 95 "yacc.y"
    { (yyval.nPtr) = opr(PRINT, 1, (yyvsp[(2) - (3)].nPtr)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 96 "yacc.y"
    { (yyval.nPtr) = opr('=', 2, id(getIndex((yyvsp[(1) - (4)].varName))), (yyvsp[(3) - (4)].nPtr)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 97 "yacc.y"
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 98 "yacc.y"
    { (yyval.nPtr) = opr(FOR, 4, (yyvsp[(3) - (8)].nPtr), (yyvsp[(4) - (8)].nPtr), (yyvsp[(6) - (8)].nPtr), (yyvsp[(8) - (8)].nPtr)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 99 "yacc.y"
    { (yyval.nPtr) = opr(REPEAT, 2, (yyvsp[(5) - (7)].nPtr), (yyvsp[(2) - (7)].nPtr)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 100 "yacc.y"
    { (yyval.nPtr) = opr(SWITCH, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 101 "yacc.y"
    { (yyval.nPtr) = opr(IF, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 102 "yacc.y"
    { (yyval.nPtr) = opr(IF, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 103 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 104 "yacc.y"
    { (yyval.nPtr) = opr(CALL, 1, id(getIndex((yyvsp[(2) - (3)].varName)))); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 108 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 109 "yacc.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 113 "yacc.y"
    { (yyval.nPtr) = opr(DEFAULT, 1, (yyvsp[(2) - (2)].nPtr)) ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 117 "yacc.y"
    { (yyval.nPtr) = opr(CASE, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 118 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 119 "yacc.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(2) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr)) ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 123 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr) ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 124 "yacc.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)) ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 129 "yacc.y"
    { (yyval.nPtr) = opr('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 130 "yacc.y"
    { (yyval.nPtr) = opr('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 131 "yacc.y"
    { (yyval.nPtr) = opr(GE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 132 "yacc.y"
    { (yyval.nPtr) = opr(LE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 133 "yacc.y"
    { (yyval.nPtr) = opr(NE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 134 "yacc.y"
    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 135 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr) ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 139 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr) ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 140 "yacc.y"
    { (yyval.nPtr) = opr('|', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 141 "yacc.y"
    { (yyval.nPtr) = opr('&', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 144 "yacc.y"
    { (yyval.nPtr) = conInt((yyvsp[(1) - (1)].iValue)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 145 "yacc.y"
    { (yyval.nPtr) = conFloat((yyvsp[(1) - (1)].fValue)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 146 "yacc.y"
    { (yyval.nPtr) = conString((yyvsp[(1) - (1)].sValue)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 147 "yacc.y"
    { (yyval.nPtr) = id(getIndex((yyvsp[(1) - (1)].varName))); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 148 "yacc.y"
    { (yyval.nPtr) = opr('+', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 149 "yacc.y"
    { (yyval.nPtr) = opr('-', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 150 "yacc.y"
    { (yyval.nPtr) = opr('*', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 151 "yacc.y"
    { (yyval.nPtr) = opr('/', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 152 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1935 "yacc.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



/* Line 1675 of yacc.c  */
#line 155 "yacc.y"


nodeType* conFloat(double value){
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeFloatCon;
    p->con.fValue = value;

    return p;
} 

nodeType *conInt(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeIntCon;
    p->con.iValue = value;
    //printf("Constant integer = %d", p->con.iValue);
    return p;
}

nodeType* conString(char* value){
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeStringCon;
    p->con.sValue = value;

    return p;
}

char* truncStringAtSpace(char* varChar){
    char* endOfFirst = strchr(varChar, ' ');
    if(endOfFirst == NULL)
        return varChar;
    size_t lengthOfFirst = endOfFirst - varChar;
    char* temp = (char*)malloc((lengthOfFirst + 1) * sizeof(char));
    strncpy(temp, varChar, lengthOfFirst);
    temp[lengthOfFirst] = '\0';
    return temp;
}

int defSym(char* name, int type, bool isVar, bool isInitialized){
    name = truncStringAtSpace(name);
    if(getIndex(name) != -1){
        printf("line %d: Multiple Definition of variable %s\n", yylineno+1, name);
        hasNoErrors = False;
        return -1;
    }
    symbolEntry *s = NULL;
    if(nextSymNum < MAXNUMOFSYMS)
        s = malloc(sizeof(symbolEntry));
    if(s == NULL)
        yyerror("out of memory");
    s->name = name;
    s->index = nextSymNum;
    s->type = type;
    s->isVar = isVar;
    s->isInitialized = isInitialized;
    s->isUsed = False;
    sym[nextSymNum] = s;
    //fprintf(stderr, "Defined Symbol %s of type %d at index %d\n", s->name, s->type, s->index);
    nextSymNum++;
    return s->index;
}

int getIndex(char* varName){
    // getIndex is used to use the variable, so if it's called then "isUsed" can be used as True
    char* temp = truncStringAtSpace(varName);
    int i = 0;
    while(i < nextSymNum){
        if(strcmp(sym[i]->name, temp) == 0){
            sym[i]->isUsed = True;
            //fprintf(stderr, "Symbol %s Found at index %d\n", varName, i);
            return sym[i]->index; 
        }
        i++;
    }
    //fprintf(stderr, "Symbol %s not Found\n", varName);
    return -1;
}

nodeType *id(int index) {
    if(index == -1)
        return NULL;
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = index;
    return p;
}

int getIdType(nodeType* p){
    return sym[p->id.i]->type;
}

bool isIdVar(nodeType* p){
   return sym[p->id.i]->isVar; 
}

bool isIdInitialized(nodeType* p){
   return sym[p->id.i]->isInitialized; 
}

char* getIdName(nodeType* p){
   return sym[p->id.i]->name; 
}


void checkImproperUsage(int oper, int nops, nodeType *p){
    //LHS and RHS of binary arithmetic and logical operators can't be strings nor functions and must be initialized
    if(oper == '*' || oper == '/' || oper == '+' || oper == '-' ||
    oper == '<' || oper == '>' || oper == GE || oper == LE || oper == EQ || oper == NE ||
    oper == '&' || oper == '|'){
        if((p->opr.op[0]->type == typeStringCon) || (p->opr.op[1]->type == typeStringCon) ||
        (p->opr.op[0]->type == typeId && getIdType(p->opr.op[0]) > 1) ||
        (p->opr.op[1]->type == typeId && getIdType(p->opr.op[1]) > 1)) {
            if(oper == LE || oper == EQ || oper == NE || oper == GE){
                char* op = ">=";
                if(oper == LE)
                    op = "<=";
                else if(oper == EQ)
                    op = "==";
                else if(oper == NE)
                    op = "!=";
                printf("line %d: Operator '%s' can't have string nor functions on any of its sides\n", yylineno+1, op);
            }else
                printf("line %d: Operator '%c' can't have string nor functions on any of its sides\n", yylineno+1, oper);
            hasNoErrors = False;
        }else if((p->opr.op[0]->type == typeId && isIdInitialized(p->opr.op[0]) == False) ||
        (p->opr.op[1]->type == typeId && isIdInitialized(p->opr.op[1]) == False)){
            if(oper == LE || oper == EQ || oper == NE || oper == GE){
                char* op = ">=";
                if(oper == LE)
                    op = "<=";
                else if(oper == EQ)
                    op = "==";
                else if(oper == NE)
                    op = "!=";
                printf("line %d: Operator '%s' both sides must be initialized\n", yylineno+1, op);
            }else
                printf("line %d: Operator '%c' both sides must be initialized\n", yylineno+1, oper);
            hasNoErrors = False;
        }
    }else if(oper == '='){
        // Can't have a function on any of its sides
        if((p->opr.op[0]->type == typeId && getIdType(p->opr.op[0]) == 3) ||
            (p->opr.op[1]->type == typeId && getIdType(p->opr.op[1]) == 3)){
                printf("line %d: Functions can't be on LHS nor RHS of '=' operator\n", yylineno+1);
                hasNoErrors = False;
            }
        //Constant variables, constant numbers (1, 5.32) qouteStrings, and functions can't be used on LHS
        if((p->opr.op[0]->type == typeId && getIdType(p->opr.op[0]) == 3) ||
        p->opr.op[0]->type == typeStringCon || p->opr.op[0]->type == typeIntCon ||
        p->opr.op[0]->type == typeFloatCon){
            printf("line %d: LHS of '=' must be a variable\n", yylineno+1);
            hasNoErrors = False;
        }else{
            if(getIdType(p->opr.op[0]) == 2){
                // Check if LHS (which is for sure a variable) is string then RHS is also a string
                if(p->opr.op[1]->type != typeStringCon &&
                (p->opr.op[1]->type != typeId || getIdType(p->opr.op[1]) != 2)){
                    printf("line %d: LHS is string, but RHS is not a string\n", yylineno+1);
                    hasNoErrors = False;
                }
            }else if(p->opr.op[1]->type == typeStringCon ||
                (p->opr.op[1]->type == typeId && getIdType(p->opr.op[1]) == 2)){
                // Check if LHS (which is for sure a variable) is not string then RHS can't be a string
                    printf("line %d: LHS is not string, but RHS is a string\n", yylineno+1);
                    hasNoErrors = False;
                }
        }
        // RHS must be initialized
        if(p->opr.op[1]->type == typeId && isIdInitialized(p->opr.op[1]) == False){
            printf("line %d: RHS of operator '=' must be initialized\n", yylineno+1);
            hasNoErrors = False;
        }
    }else if(oper == PRINT){
        // Can't have a function as argument
        if((p->opr.op[0]->type == typeId && getIdType(p->opr.op[0]) == 3)){
            printf("line %d: Functions can't be an argument for 'PRINT' operator\n", yylineno+1);
            hasNoErrors = False;
        }
        // Argument must be initialized if Variable
        else if(p->opr.op[0]->type == typeId && isIdInitialized(p->opr.op[0]) == False){
            printf("line %d: Argument of operator 'PRINT' must be initialized\n", yylineno+1);
            hasNoErrors = False;
        }
    }else if(oper == CALL){
        // Must be a function
        if(p->opr.op[0]->type != typeId || getIdType(p->opr.op[0]) != 3){
            printf("line %d: Argument of operator 'CALL' must be function name\n", yylineno+1);
            hasNoErrors = False;
        }
    }
}

bool checkIfAllDefined(int oper, int nops, nodeType* p){
    bool Ok = True;
    int i;
    if(oper != FUN && oper != BODY){
        for (i = 0; i < nops; i++){
            if(p->opr.op[i] == NULL){
                if(oper == LE || oper == EQ || oper == NE || oper == GE || oper == PRINT){
                    char* op = ">=";
                    if(oper == LE)
                        op = "<=";
                    else if(oper == EQ)
                        op = "==";
                    else if(oper == NE)
                        op = "!=";
                    else if(oper == PRINT)
                        op = "Print";
                    printf("line %d: Operator '%s' has undefined variable on one/both of its sides\n", yylineno+1, op);
                }else if(oper == '*' || oper == '/' || oper == '+' || oper == '-' || oper == '<' || oper == '>' || oper == '&' || oper == '|' || oper == '=' || oper == PRINT)
                    printf("line %d: Operator '%c' has undefined variable on one/both of its sides\n", yylineno+1, oper);
                hasNoErrors = False;
                Ok = False;
            }
        }
    }
    return Ok;
}

int getNodeLevel(nodeType* p){
    if(p->type == typeIntCon ||
     (p->type == typeId && getIdType(p) == 0) ||
     (p->type == typeOpr && p->opr.nodeLevel == 0))
        return 0;

    if(p->type == typeFloatCon ||
     (p->type == typeId && getIdType(p) == 1) ||
     (p->type == typeOpr && p->opr.nodeLevel == 1))
        return 1;

    return 2;
}

nodeType *functionsOpr(nodeType* preFuns, nodeType* newFun){
    nodeType *p;
    int i;
    int nops = 1;
    nops = preFuns->opr.nops + 1;
    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");
    /* copy information */
    p->opr.oper = FUNCTIONS;
    p->opr.nops = nops;
    for (i = 0; i < nops-1; i++)
        p->opr.op[i] = preFuns->opr.op[i];
    p->opr.op[nops-1] = newFun;
    //fprintf(stderr, "YACC %d\n", p->opr.nops);
    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");
    /* copy information */
    p->type = typeOpr;
    p->opr.nodeLevel = 2; // initially

    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    if(oper != FUNCTIONS && oper != FUN && oper != BODY && checkIfAllDefined(oper, nops, p) == True){
        checkImproperUsage(oper, nops, p);
        if(oper == '*' || oper == '/' || oper == '+' || oper == '-' ||
            oper == '>' || oper == '<' || oper == GE || oper == LE || oper == EQ || oper == NE){
            p->opr.nodeLevel = 0;
            if(getNodeLevel(p->opr.op[0]) == 1 || getNodeLevel(p->opr.op[1]) == 1)
                p->opr.nodeLevel = 1;
        }
        else if(oper == '='){
            // LHS is now initialized
            if(p->opr.op[0]->type == typeId)
                sym[p->opr.op[0]->id.i]->isInitialized = True;
        }
    }
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            if(p->opr.op[i])
                freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    printf("line %d: %s\n", yylineno+1, s);
}

int main(void) {
    // open a file handle to a particular file:
    /*yyin = fopen("input.txt", "r");
    // make sure it is valid:
    if (!yyin) {
        fprintf(stderr, "I can't open input.txt!\n");
        return -1;
    }*/
    
    // parse through the input until there is no more:
    yyparse();
    return 0;
}
