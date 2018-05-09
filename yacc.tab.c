
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
nodeType* conFloat(double value);
nodeType *conInt(int value);
nodeType* conString(char* value);
int defSym(char* name, int type, bool isVar, bool isInitialized);
int getIndex(char* varName);
nodeType *id(int index);
void freeNode(nodeType *p);
extern int ex(nodeType *p);
extern int exMain(nodeType *p);
int yylex(void);

void yyerror(char *s);
symbolEntry* sym[MAXNUMOFSYMS];                    /* symbol table */
int nextSymNum = 0;
int yydebug=1;
bool hasNoErrors = True;


/* Line 189 of yacc.c  */
#line 102 "yacc.tab.c"

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
     IFX = 279,
     ELSE = 280,
     NE = 281,
     EQ = 282,
     LE = 283,
     GE = 284
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 31 "yacc.y"

    double fValue;              /* Floating deciamal value */
    int iValue;                 /* integer value */
    char* sValue;              /* String value */
    char* varName;             /* variable Name */
    nodeType *nPtr;             /* node pointer */



/* Line 214 of yacc.c  */
#line 177 "yacc.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 189 "yacc.tab.c"

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
#define YYLAST   233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNRULES -- Number of states.  */
#define YYNSTATES  140

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,     2,
      42,    40,    34,    32,     2,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      27,    41,    26,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,    37,    39,     2,     2,     2,     2,
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
      25,    28,    29,    30,    31
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    12,    15,    18,    21,
      24,    33,    42,    51,    58,    65,    72,    81,    90,    99,
     101,   105,   110,   116,   125,   133,   139,   145,   153,   157,
     159,   162,   165,   171,   175,   180,   182,   185,   189,   193,
     197,   201,   205,   209,   213,   215,   219,   223,   225,   227,
     229,   231,   235,   239,   243,   247
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      45,     0,    -1,    46,    -1,    46,    48,    -1,    46,    47,
      -1,    -1,     1,    38,    -1,     1,    39,    -1,     1,    40,
      -1,     1,     9,    -1,    16,     6,    17,    20,    18,    41,
      55,    38,    -1,    16,     6,    17,    21,    18,    41,    55,
      38,    -1,    16,     6,    17,    22,    18,    41,    55,    38,
      -1,    16,     6,    17,    20,    18,    38,    -1,    16,     6,
      17,    21,    18,    38,    -1,    16,     6,    17,    22,    18,
      38,    -1,    16,     6,    17,    20,    19,    41,    55,    38,
      -1,    16,     6,    17,    21,    19,    41,    55,    38,    -1,
      16,     6,    17,    22,    19,    41,    55,    38,    -1,    38,
      -1,    15,    55,    38,    -1,     6,    41,    55,    38,    -1,
       7,    42,    54,    40,    48,    -1,     8,    42,    48,    54,
      38,    48,    40,    48,    -1,     9,    48,    10,    42,    54,
      40,    38,    -1,    11,    42,    55,    40,    51,    -1,    14,
      42,    54,    40,    48,    -1,    14,    42,    54,    40,    48,
      25,    48,    -1,    43,    49,    39,    -1,    48,    -1,    49,
      48,    -1,    13,    48,    -1,    12,    42,    55,    40,    48,
      -1,    43,    52,    39,    -1,    43,    52,    50,    39,    -1,
      51,    -1,    52,    51,    -1,    55,    27,    55,    -1,    55,
      26,    55,    -1,    55,    31,    55,    -1,    55,    30,    55,
      -1,    55,    28,    55,    -1,    55,    29,    55,    -1,    42,
      54,    40,    -1,    53,    -1,    54,    37,    53,    -1,    54,
      36,    53,    -1,     3,    -1,     4,    -1,     5,    -1,     6,
      -1,    55,    32,    55,    -1,    55,    33,    55,    -1,    55,
      34,    55,    -1,    55,    35,    55,    -1,    42,    55,    40,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    61,    62,    63,    67,    68,    69,    70,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    96,
      97,   101,   105,   106,   107,   111,   112,   117,   118,   119,
     120,   121,   122,   123,   127,   128,   129,   132,   133,   134,
     135,   136,   137,   138,   139,   140
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
  "STRING", "FUN", "IFX", "ELSE", "'>'", "'<'", "NE", "EQ", "LE", "GE",
  "'+'", "'-'", "'*'", "'/'", "'&'", "'|'", "';'", "'}'", "')'", "'='",
  "'('", "'{'", "$accept", "program", "function", "err_stmt", "stmt",
  "stmt_list", "defult_stmt", "case_stmt", "case_list", "logic_expr",
  "logic_list", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    62,    60,   281,   282,
     283,   284,    43,    45,    42,    47,    38,   124,    59,   125,
      41,    61,    40,   123
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    44,    45,    46,    46,    46,    47,    47,    47,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    49,
      49,    50,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    55,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     2,     2,     2,     2,
       8,     8,     8,     6,     6,     6,     8,     8,     8,     1,
       3,     4,     5,     8,     7,     5,     5,     7,     3,     1,
       2,     2,     5,     3,     4,     1,     2,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     4,     3,     9,     6,     7,
       8,     0,     0,     0,     0,     0,     0,    47,    48,    49,
      50,     0,     0,     0,    29,     0,     0,     0,    44,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,    28,    30,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,    51,    52,    53,    54,     0,     0,     0,    43,    46,
      45,    22,    38,    37,    41,    42,    40,    39,     0,     0,
       0,     0,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,     0,     0,    13,     0,     0,    14,
       0,     0,    15,     0,     0,     0,    24,     0,     0,    33,
       0,    36,    27,     0,     0,     0,     0,     0,     0,    23,
       0,    31,    34,    10,    16,    11,    17,    12,    18,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    15,    16,    35,   120,    92,   104,    38,
      39,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -81
static const yytype_int16 yypact[] =
{
     -81,    13,    85,   -81,    10,   -24,   -17,    -7,   118,    -3,
       1,    -1,    46,   -81,   118,   -81,   -81,   -81,   -81,   -81,
     -81,    -1,     4,   118,    37,    -1,     4,   -81,   -81,   -81,
     -81,    -1,   -12,    40,   -81,    97,   140,     4,   -81,     0,
     136,     4,    23,    41,    22,    55,    -1,    -1,    -1,    -1,
     -81,     9,   -81,   -81,   -81,    42,   115,     4,     4,   118,
      -1,    -1,    -1,    -1,    -1,    -1,   101,     4,     2,   118,
     -81,    49,    49,   -81,   -81,   112,   139,   158,   -81,   -81,
     -81,   -81,   194,   194,   194,   194,   194,   194,   118,   185,
      35,     2,   -81,    73,    25,    61,    78,   149,   192,   150,
     120,   159,    -1,   -81,    21,   118,   -81,    -1,    -1,   -81,
      -1,    -1,   -81,    -1,    -1,   118,   -81,   119,   118,   -81,
     165,   -81,   -81,   147,   154,   161,   168,   175,   182,   -81,
     118,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,   -81,    -8,   -81,   -81,   -80,   -81,   126,
     -25,     7
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -3
static const yytype_int16 yytable[] =
{
      24,    44,    27,    28,    29,    30,    34,    27,    28,    29,
      30,   103,    55,     3,    90,    41,    66,    21,    32,    17,
      46,    47,    48,    49,   121,    22,    50,    53,    36,    75,
      76,    77,    43,    90,   118,    23,    57,    58,    45,    25,
      59,    31,    89,    26,    56,    91,    37,    42,    18,    19,
      20,    81,    33,    71,    72,    73,    74,    51,    57,    58,
     119,    93,    69,   106,    91,    67,   107,    82,    83,    84,
      85,    86,    87,    46,    47,    48,    49,   102,    57,    58,
     100,    68,    78,    48,    49,    -2,     4,    46,    47,    48,
      49,     5,     6,     7,     8,    70,     9,   122,   105,    10,
      11,    12,   108,     5,     6,     7,     8,   129,     9,   117,
     131,    10,    11,    12,   123,   124,   109,   125,   126,   110,
     127,   128,   139,    13,     5,     6,     7,     8,    14,     9,
      94,    95,    10,    11,    12,    13,    52,    57,    58,    88,
      14,    60,    61,    62,    63,    64,    65,    46,    47,    48,
      49,    46,    47,    48,    49,    70,    13,    96,    97,   130,
     115,    14,    60,    61,    62,    63,    64,    65,    46,    47,
      48,    49,    46,    47,    48,    49,    98,    99,    54,    46,
      47,    48,    49,    79,    80,   133,    46,    47,    48,    49,
     111,   114,   134,    46,    47,    48,    49,   116,     0,   135,
      46,    47,    48,    49,   132,     0,   136,    46,    47,    48,
      49,     0,     0,   137,    46,    47,    48,    49,     0,     0,
     138,    57,    58,     0,     0,   101,    46,    47,    48,    49,
     112,     0,     0,   113
};

static const yytype_int16 yycheck[] =
{
       8,    26,     3,     4,     5,     6,    14,     3,     4,     5,
       6,    91,    37,     0,    12,    23,    41,    41,    11,     9,
      32,    33,    34,    35,   104,    42,    38,    35,    21,    20,
      21,    22,    25,    12,    13,    42,    36,    37,    31,    42,
      40,    42,    67,    42,    37,    43,    42,    10,    38,    39,
      40,    59,     6,    46,    47,    48,    49,    17,    36,    37,
      39,    69,    40,    38,    43,    42,    41,    60,    61,    62,
      63,    64,    65,    32,    33,    34,    35,    42,    36,    37,
      88,    40,    40,    34,    35,     0,     1,    32,    33,    34,
      35,     6,     7,     8,     9,    40,    11,   105,    25,    14,
      15,    16,    41,     6,     7,     8,     9,   115,    11,   102,
     118,    14,    15,    16,   107,   108,    38,   110,   111,    41,
     113,   114,   130,    38,     6,     7,     8,     9,    43,    11,
      18,    19,    14,    15,    16,    38,    39,    36,    37,    38,
      43,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    32,    33,    34,    35,    40,    38,    18,    19,    40,
      40,    43,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    32,    33,    34,    35,    18,    19,    38,    32,
      33,    34,    35,    57,    58,    38,    32,    33,    34,    35,
      41,    41,    38,    32,    33,    34,    35,    38,    -1,    38,
      32,    33,    34,    35,    39,    -1,    38,    32,    33,    34,
      35,    -1,    -1,    38,    32,    33,    34,    35,    -1,    -1,
      38,    36,    37,    -1,    -1,    40,    32,    33,    34,    35,
      38,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    45,    46,     0,     1,     6,     7,     8,     9,    11,
      14,    15,    16,    38,    43,    47,    48,     9,    38,    39,
      40,    41,    42,    42,    48,    42,    42,     3,     4,     5,
       6,    42,    55,     6,    48,    49,    55,    42,    53,    54,
      55,    48,    10,    55,    54,    55,    32,    33,    34,    35,
      38,    17,    39,    48,    38,    54,    55,    36,    37,    40,
      26,    27,    28,    29,    30,    31,    54,    42,    40,    40,
      40,    55,    55,    55,    55,    20,    21,    22,    40,    53,
      53,    48,    55,    55,    55,    55,    55,    55,    38,    54,
      12,    43,    51,    48,    18,    19,    18,    19,    18,    19,
      48,    40,    42,    51,    52,    25,    38,    41,    41,    38,
      41,    41,    38,    41,    41,    40,    38,    55,    13,    39,
      50,    51,    48,    55,    55,    55,    55,    55,    55,    48,
      40,    48,    39,    38,    38,    38,    38,    38,    38,    48
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
#line 57 "yacc.y"
    { exMain((yyvsp[(1) - (1)].nPtr)); freeNode((yyvsp[(1) - (1)].nPtr)); exit(0); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 61 "yacc.y"
    { (yyval.nPtr) = opr(FUN, 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 62 "yacc.y"
    {;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 67 "yacc.y"
    { hasNoErrors = False; ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 68 "yacc.y"
    { hasNoErrors = False; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 69 "yacc.y"
    { hasNoErrors = False; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 70 "yacc.y"
    { hasNoErrors = False; ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 74 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 0, True, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 75 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 1, True, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 76 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 2, True, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 77 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 1, id(defSym((yyvsp[(2) - (6)].varName), 0, True, False))); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 78 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 1, id(defSym((yyvsp[(2) - (6)].varName), 1, True, False))); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 79 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 1, id(defSym((yyvsp[(2) - (6)].varName), 2, True, False))); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 80 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 0, False, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 81 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 1, False, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 82 "yacc.y"
    { (yyval.nPtr) = opr(DEF, 2, id(defSym((yyvsp[(2) - (8)].varName), 2, False, True)), (yyvsp[(7) - (8)].nPtr)); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 83 "yacc.y"
    { (yyval.nPtr) = opr(';', 2, NULL, NULL); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 84 "yacc.y"
    { (yyval.nPtr) = opr(PRINT, 1, (yyvsp[(2) - (3)].nPtr)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 85 "yacc.y"
    { (yyval.nPtr) = opr('=', 2, id(getIndex((yyvsp[(1) - (4)].varName))), (yyvsp[(3) - (4)].nPtr)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 86 "yacc.y"
    { (yyval.nPtr) = opr(WHILE, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 87 "yacc.y"
    { (yyval.nPtr) = opr(FOR, 4, (yyvsp[(3) - (8)].nPtr), (yyvsp[(4) - (8)].nPtr), (yyvsp[(6) - (8)].nPtr), (yyvsp[(8) - (8)].nPtr)); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 88 "yacc.y"
    { (yyval.nPtr) = opr(REPEAT, 2, (yyvsp[(5) - (7)].nPtr), (yyvsp[(2) - (7)].nPtr)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 89 "yacc.y"
    { (yyval.nPtr) = opr(SWITCH, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 90 "yacc.y"
    { (yyval.nPtr) = opr(IF, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 91 "yacc.y"
    { (yyval.nPtr) = opr(IF, 3, (yyvsp[(3) - (7)].nPtr), (yyvsp[(5) - (7)].nPtr), (yyvsp[(7) - (7)].nPtr)); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 92 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 96 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 97 "yacc.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 101 "yacc.y"
    { (yyval.nPtr) = opr(DEFAULT, 1, (yyvsp[(2) - (2)].nPtr)) ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 105 "yacc.y"
    { (yyval.nPtr) = opr(CASE, 2, (yyvsp[(3) - (5)].nPtr), (yyvsp[(5) - (5)].nPtr)); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 106 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 107 "yacc.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(2) - (4)].nPtr), (yyvsp[(3) - (4)].nPtr)) ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 111 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr) ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 112 "yacc.y"
    { (yyval.nPtr) = opr(';', 2, (yyvsp[(1) - (2)].nPtr), (yyvsp[(2) - (2)].nPtr)) ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 117 "yacc.y"
    { (yyval.nPtr) = opr('<', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 118 "yacc.y"
    { (yyval.nPtr) = opr('>', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 119 "yacc.y"
    { (yyval.nPtr) = opr(GE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 120 "yacc.y"
    { (yyval.nPtr) = opr(LE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 121 "yacc.y"
    { (yyval.nPtr) = opr(NE, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 122 "yacc.y"
    { (yyval.nPtr) = opr(EQ, 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 123 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr) ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 127 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(1) - (1)].nPtr) ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 128 "yacc.y"
    { (yyval.nPtr) = opr('|', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 129 "yacc.y"
    { (yyval.nPtr) = opr('&', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 132 "yacc.y"
    { (yyval.nPtr) = conInt((yyvsp[(1) - (1)].iValue)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 133 "yacc.y"
    { (yyval.nPtr) = conFloat((yyvsp[(1) - (1)].fValue)); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 134 "yacc.y"
    { (yyval.nPtr) = conString((yyvsp[(1) - (1)].sValue)); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 135 "yacc.y"
    { (yyval.nPtr) = id(getIndex((yyvsp[(1) - (1)].varName))); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 136 "yacc.y"
    { (yyval.nPtr) = opr('+', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 137 "yacc.y"
    { (yyval.nPtr) = opr('-', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 138 "yacc.y"
    { (yyval.nPtr) = opr('*', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 139 "yacc.y"
    { (yyval.nPtr) = opr('/', 2, (yyvsp[(1) - (3)].nPtr), (yyvsp[(3) - (3)].nPtr)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 140 "yacc.y"
    { (yyval.nPtr) = (yyvsp[(2) - (3)].nPtr); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1882 "yacc.tab.c"
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
#line 143 "yacc.y"


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
    sym[nextSymNum] = s;
    //printf("Defined Symbol %s of type %d at index %d", s->name, s->type, s->index);
    nextSymNum++;
    return s->index;
}

int getIndex(char* varName){
    char* temp = truncStringAtSpace(varName);
    int i = 0;
    while(i < nextSymNum){
        if(strcmp(sym[i]->name, temp) == 0){
            //printf("Got %s ", temp);
            //printf("Found %s ", sym[i]->name);
            return sym[i]->index;
        }
        i++;
    }
    //printf("Symbol %s not Found\n", varName);
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
    //LHS and RHS of binary arithmetic and logical operators can't be strings and must be initialized
    if(oper == '*' || oper == '/' || oper == '+' || oper == '-' ||
    oper == '<' || oper == '>' || oper == GE || oper == LE || oper == EQ || oper == NE ||
    oper == '&' || oper == '|'){
        if((p->opr.op[0]->type == typeStringCon) || (p->opr.op[1]->type == typeStringCon) ||
        (p->opr.op[0]->type == typeId && getIdType(p->opr.op[0]) == 2) ||
        (p->opr.op[1]->type == typeId && getIdType(p->opr.op[1]) == 2)){
            if(oper == LE || oper == EQ || oper == NE || oper == GE){
                char* op = ">=";
                if(oper == LE)
                    op = "<=";
                else if(oper == EQ)
                    op = "==";
                else if(oper == NE)
                    op = "!=";
                printf("line %d: Operator '%s' can't have string on any of its sides\n", yylineno+1, op);
            }else
                printf("line %d: Operator '%c' can't have string on any of its sides\n", yylineno+1, oper);
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
        //Constant variables, constant numbers (1, 5.32) and qouteStrings can't be used on LHS
        if((p->opr.op[0]->type == typeId && isIdVar(p->opr.op[0]) == False) ||
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
    }
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
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    checkImproperUsage(oper, nops, p);
    if(oper == '='){
        // LHS is now initialized
        if(p->opr.op[0]->type == typeId)
            sym[p->opr.op[0]->id.i]->isInitialized = True;
    }
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    printf("line %d: %s\n", yylineno+1, s);
}

/*int ex(nodeType * p){
    printf("Called");
}*/

int main(void) {
    yyparse();
    return 0;
}
