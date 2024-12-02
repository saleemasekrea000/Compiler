/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INTEGER_LITERAL = 259,
     REAL_LITERAL = 260,
     BOOLEAN_LITERAL = 261,
     IS = 262,
     WHILE = 263,
     END = 264,
     ROUTINE = 265,
     VAR = 266,
     INTEGER_LITERAL_KEYWORD = 267,
     REAL_LITERAL_KEYWORD = 268,
     OR = 269,
     AND = 270,
     XOR = 271,
     NOT = 272,
     RANGE = 273,
     REVERSE = 274,
     BOOLEAN_LITERAL_KEYWORD = 275,
     RECORD = 276,
     ARRAY = 277,
     FOR = 278,
     RETURN = 279,
     THEN = 280,
     TRUE = 281,
     FALSE = 282,
     TYPE = 283,
     LOOP = 284,
     IN = 285,
     IF = 286,
     ELSE = 287,
     BREAK = 288,
     CONTINUE = 289,
     PRINT = 290,
     LE_OP = 291,
     GE_OP = 292,
     NE_OP = 293,
     AND_OP = 294,
     OR_OP = 295,
     MUL_ASSIGN = 296,
     DIV_ASSIGN = 297,
     MOD_ASSIGN = 298,
     ADD_ASSIGN = 299,
     SUB_ASSIGN = 300,
     ASSIGN_OP = 301
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INTEGER_LITERAL 259
#define REAL_LITERAL 260
#define BOOLEAN_LITERAL 261
#define IS 262
#define WHILE 263
#define END 264
#define ROUTINE 265
#define VAR 266
#define INTEGER_LITERAL_KEYWORD 267
#define REAL_LITERAL_KEYWORD 268
#define OR 269
#define AND 270
#define XOR 271
#define NOT 272
#define RANGE 273
#define REVERSE 274
#define BOOLEAN_LITERAL_KEYWORD 275
#define RECORD 276
#define ARRAY 277
#define FOR 278
#define RETURN 279
#define THEN 280
#define TRUE 281
#define FALSE 282
#define TYPE 283
#define LOOP 284
#define IN 285
#define IF 286
#define ELSE 287
#define BREAK 288
#define CONTINUE 289
#define PRINT 290
#define LE_OP 291
#define GE_OP 292
#define NE_OP 293
#define AND_OP 294
#define OR_OP 295
#define MUL_ASSIGN 296
#define DIV_ASSIGN 297
#define MOD_ASSIGN 298
#define ADD_ASSIGN 299
#define SUB_ASSIGN 300
#define ASSIGN_OP 301




/* Copy the first part of user declarations.  */
#line 1 "./parser/grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include "parser.hpp"
#include "ast.hpp"
#include "../semantic/semantic.hpp"
#include "../codegen/codegen.hpp"
 
extern int yylex():
void yyerror(char *s);
int counter = 1;
int indent = 0;
AST_Node* root;
void print_indent() {
  for(int i = 0; i < indent; i++) printf("  ");
}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "./parser/grammar.y"
{
  char *id_val;
  int int_val;
  double real_val;
  bool bool_val;
  char *op_val;
  char *keyword_val;
  AST_Node* node; 
  char * type_name;

}
/* Line 193 of yacc.c.  */
#line 218 "./parser/grammar.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 231 "./parser/grammar.tab.c"

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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   455

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNRULES -- Number of states.  */
#define YYNSTATES  212

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    55,     2,     2,
      47,    48,    53,    56,    50,    57,    52,    54,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    49,    51,
      58,    60,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,    62,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    15,    24,    35,
      37,    41,    42,    46,    48,    50,    56,    64,    70,    72,
      74,    76,    78,    80,    82,    84,    86,    88,    90,    93,
      95,    97,    99,   101,   103,   105,   107,   109,   111,   116,
     118,   122,   123,   127,   131,   135,   139,   141,   145,   147,
     151,   155,   159,   161,   165,   169,   171,   175,   179,   183,
     187,   191,   195,   199,   203,   207,   211,   213,   217,   221,
     225,   231,   237,   240,   241,   244,   248,   252,   257,   259,
     261,   263,   265,   268,   271,   276,   278,   280,   282,   285,
     289,   292,   295,   301,   309,   314,   319,   324,   329,   334,
     339,   341,   343,   349,   352,   355,   356,   363,   368
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    67,    -1,    67,    71,    -1,    67,    95,
      -1,    67,    68,    -1,    -1,    10,    73,    47,    69,    48,
       7,   105,     9,    -1,    10,    73,    47,    69,    48,    49,
      74,     7,   105,     9,    -1,    70,    -1,    69,    50,    70,
      -1,    -1,    73,    49,    74,    -1,    72,    -1,    89,    -1,
      11,    73,     7,    88,    51,    -1,    11,    73,    49,    74,
       7,    88,    51,    -1,    11,    73,    49,    74,    51,    -1,
       3,    -1,    12,    -1,    13,    -1,    20,    -1,    73,    -1,
      90,    -1,    93,    -1,    77,    -1,    78,    -1,    79,    -1,
      76,    80,    -1,    73,    -1,    17,    -1,     4,    -1,     5,
      -1,     6,    -1,    75,    -1,    92,    -1,    83,    -1,    81,
      -1,    73,    47,    82,    48,    -1,    88,    -1,    82,    50,
      88,    -1,    -1,    73,    52,    73,    -1,    92,    52,    73,
      -1,    92,    52,    83,    -1,    73,    52,    83,    -1,    80,
      -1,    47,    88,    48,    -1,    84,    -1,    85,    53,    84,
      -1,    85,    54,    84,    -1,    85,    55,    84,    -1,    85,
      -1,    86,    56,    85,    -1,    86,    57,    85,    -1,    86,
      -1,    86,    58,    86,    -1,    86,    36,    86,    -1,    86,
      59,    86,    -1,    86,    37,    86,    -1,    86,    60,    86,
      -1,    86,    45,    86,    -1,    86,    44,    86,    -1,    86,
      41,    86,    -1,    86,    42,    86,    -1,    86,    43,    86,
      -1,    87,    -1,    87,    15,    87,    -1,    87,    14,    87,
      -1,    87,    16,    87,    -1,    28,    73,     7,    74,    51,
      -1,    21,    61,    91,    62,     9,    -1,    91,    72,    -1,
      -1,    73,    94,    -1,    22,    94,    74,    -1,    63,    88,
      64,    -1,    94,    63,    88,    64,    -1,   103,    -1,   102,
      -1,   101,    -1,    97,    -1,    81,    51,    -1,    96,    51,
      -1,    35,    47,    88,    48,    -1,    98,    -1,    99,    -1,
     100,    -1,    24,    51,    -1,    24,    88,    51,    -1,    34,
      51,    -1,    33,    51,    -1,    31,    88,    25,   105,     9,
      -1,    31,    88,    25,   105,    32,   105,     9,    -1,    80,
      46,    88,    51,    -1,    73,    45,    88,    51,    -1,    73,
      44,    88,    51,    -1,    73,    41,    88,    51,    -1,    73,
      42,    88,    51,    -1,    73,    43,    88,    51,    -1,   104,
      -1,   106,    -1,     8,    88,    29,   105,     9,    -1,   105,
      71,    -1,   105,    95,    -1,    -1,    23,    73,   107,    29,
     105,     9,    -1,    30,    88,    18,    88,    -1,    30,    19,
      88,    18,    88,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    65,    69,    73,    78,    84,    90,    99,
     103,   107,   112,   119,   123,   130,   136,   142,   149,   154,
     157,   160,   163,   167,   171,   179,   183,   187,   191,   196,
     202,   207,   212,   217,   223,   227,   231,   235,   242,   250,
     254,   258,   264,   269,   274,   279,   292,   296,   304,   308,
     314,   320,   329,   333,   339,   348,   352,   358,   364,   370,
     376,   382,   388,   394,   400,   406,   416,   420,   426,   432,
     442,   450,   457,   461,   467,   475,   483,   487,   495,   499,
     503,   507,   511,   515,   521,   527,   531,   535,   541,   544,
     550,   555,   561,   566,   575,   581,   586,   591,   596,   601,
     609,   613,   619,   626,   630,   634,   640,   648,   653
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INTEGER_LITERAL",
  "REAL_LITERAL", "BOOLEAN_LITERAL", "IS", "WHILE", "END", "ROUTINE",
  "VAR", "INTEGER_LITERAL_KEYWORD", "REAL_LITERAL_KEYWORD", "OR", "AND",
  "XOR", "NOT", "RANGE", "REVERSE", "BOOLEAN_LITERAL_KEYWORD", "RECORD",
  "ARRAY", "FOR", "RETURN", "THEN", "TRUE", "FALSE", "TYPE", "LOOP", "IN",
  "IF", "ELSE", "BREAK", "CONTINUE", "PRINT", "LE_OP", "GE_OP", "NE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "ASSIGN_OP", "'('", "')'", "':'", "','",
  "';'", "'.'", "'*'", "'/'", "'%'", "'+'", "'-'", "'<'", "'>'", "'='",
  "'{'", "'}'", "'['", "']'", "$accept", "program", "declarations",
  "routine_deceration", "parameters_list", "parameter_decleration",
  "simpleDeclaration", "variableDeclaration", "identifier", "type",
  "primary_expression", "unary_op", "int_exp", "real_exp", "boolean_exp",
  "primary", "routine_call", "argument_expression_list",
  "record_expession_access", "summand", "factor", "simple", "relation",
  "expression", "typeDecleration", "recordType", "variableDeclerations",
  "array_access_expression", "arrayType", "dimensionList", "statement",
  "print_statement", "jumpStatement", "return_exp", "continue_exp",
  "break_exp", "IfStatement", "assign_expression", "iteration_statement",
  "while_expression", "body", "for_expression", "range", 0
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
     295,   296,   297,   298,   299,   300,   301,    40,    41,    58,
      44,    59,    46,    42,    47,    37,    43,    45,    60,    62,
      61,   123,   125,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    68,    68,    69,
      69,    69,    70,    71,    71,    72,    72,    72,    73,    74,
      74,    74,    74,    74,    74,    75,    75,    75,    75,    75,
      76,    77,    78,    79,    80,    80,    80,    80,    81,    82,
      82,    82,    83,    83,    83,    83,    84,    84,    85,    85,
      85,    85,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      89,    90,    91,    91,    92,    93,    94,    94,    95,    95,
      95,    95,    95,    95,    96,    97,    97,    97,    98,    98,
      99,   100,   101,   101,   102,   102,   102,   102,   102,   102,
     103,   103,   104,   105,   105,   105,   106,   107,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     8,    10,     1,
       3,     0,     3,     1,     1,     5,     7,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     0,     3,     3,     3,     3,     1,     3,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       5,     5,     2,     0,     2,     3,     3,     4,     1,     1,
       1,     1,     2,     2,     4,     1,     1,     1,     2,     3,
       2,     2,     5,     7,     4,     4,     4,     4,     4,     4,
       1,     1,     5,     2,     2,     0,     6,     4,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     2,     1,    18,    31,    32,    33,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     0,     5,
       3,    13,    29,    34,     0,    25,    26,    27,     0,    37,
      36,    14,    35,     4,     0,    81,    85,    86,    87,    80,
      79,    78,   100,   101,     0,    29,    46,    37,    48,    52,
      55,    66,     0,     0,     0,     0,    88,     0,     0,     0,
      91,    90,     0,     0,     0,     0,     0,     0,    41,     0,
       0,    74,    28,     0,    82,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,    11,     0,     0,
       0,     0,    89,     0,   105,     0,     0,     0,     0,     0,
       0,     0,    39,    42,    45,     0,     0,     0,     0,    43,
      44,    47,    49,    50,    51,    57,    59,    63,    64,    65,
      62,    61,    53,    54,    56,    58,    60,    68,    67,    69,
       0,     0,     9,     0,     0,    19,    20,    21,     0,     0,
      22,     0,    23,    24,     0,     0,   105,     0,     0,    84,
      97,    98,    99,    96,    95,    38,     0,    76,     0,    94,
     102,   103,   104,     0,     0,     0,    15,    73,     0,     0,
      17,     0,     0,     0,    70,    92,   105,    40,    77,   105,
       0,    10,    12,     0,    75,     0,     0,   107,   106,     0,
       0,     0,     0,    72,    16,   108,    93,     7,   105,    71,
       0,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    19,   141,   142,   171,    21,    45,   151,
      23,    24,    25,    26,    27,    46,    47,   111,    30,    48,
      49,    50,    51,    52,    31,   152,   193,    32,   153,    71,
     172,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     140,    43,   101
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -104
static const yytype_int16 yypact[] =
{
    -104,    14,   243,  -104,  -104,  -104,  -104,  -104,   104,    19,
      19,  -104,    19,    33,    19,   104,    -9,    -7,    21,  -104,
    -104,  -104,   102,  -104,   119,  -104,  -104,  -104,     1,    23,
    -104,  -104,    -3,  -104,    34,  -104,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,   104,   -32,  -104,  -104,  -104,   -36,
      75,    73,    62,    45,    -1,    63,  -104,    55,   107,    90,
    -104,  -104,   104,   104,   104,   104,   104,   104,   104,    19,
     104,    64,  -104,   104,  -104,    19,  -104,    78,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,  -104,    19,   104,   174,
      24,    99,  -104,   174,  -104,    81,    79,    86,    88,    97,
     101,    22,  -104,   -31,  -104,    -3,    77,   104,   106,   -31,
    -104,  -104,  -104,  -104,  -104,    25,    25,    25,    25,    25,
      25,    25,   -36,   -36,    25,    25,    25,  -104,  -104,  -104,
     276,    29,  -104,   110,   112,  -104,  -104,  -104,    92,    98,
    -104,     6,  -104,  -104,   104,   137,  -104,   113,   210,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,   104,  -104,   103,  -104,
    -104,  -104,  -104,    16,    19,   174,  -104,  -104,    13,   104,
    -104,   148,   104,   309,  -104,  -104,  -104,  -104,  -104,  -104,
     174,  -104,  -104,    -6,  -104,   117,   104,  -104,  -104,   342,
     375,   162,   161,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
     408,  -104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,  -104,  -104,     5,   169,   -19,    -2,  -100,
    -104,  -104,  -104,  -104,  -104,     0,     2,  -104,   -24,    20,
     -34,   363,     9,    -4,  -104,  -104,  -104,   -23,  -104,    31,
     180,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -103,  -104,  -104
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      22,   158,    28,   157,    29,    10,    98,    53,    54,    57,
      55,    59,    58,   179,     3,    68,     4,    78,    79,    80,
      69,    69,     4,   189,    72,   145,   146,     4,     5,     6,
       7,    70,    70,   147,   148,   149,     4,     5,     6,     7,
      77,    11,    60,   154,    61,   114,   115,    73,    99,    75,
      11,   120,   115,   183,   132,   133,   202,   180,   105,   106,
     107,   108,   109,   110,   112,   190,   116,   113,    62,   118,
     165,    44,   166,   119,    74,   192,   117,   173,   194,   174,
      44,    88,    89,   199,    56,    76,   200,    93,    94,    95,
     201,    96,    97,   100,   144,   143,   155,   150,   122,   123,
     124,   150,   137,   138,   139,   210,   102,     4,     5,     6,
       7,    81,    82,   168,   103,   104,    83,    84,    85,    86,
      87,    11,     4,     5,     6,     7,   121,   117,   156,   159,
     160,    88,    89,    90,    91,    92,    11,   161,    22,   162,
      28,   167,    29,    63,    64,    65,    66,    67,   163,    68,
     181,    44,   164,   177,    69,   182,    22,   169,    28,   175,
      29,    70,   187,   176,   184,    70,   196,   188,   204,   208,
     209,    20,   143,   150,   203,   195,   150,     4,   197,   191,
     178,    22,    33,    28,     0,    29,   145,   146,   150,     0,
       0,     0,   205,     0,   147,   148,   149,    22,    22,    28,
      28,    29,    29,     0,     0,     0,     0,     0,    22,     0,
      28,     0,    29,     4,     5,     6,     7,     0,     8,   185,
       0,    10,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,    12,    13,     0,     0,     0,    14,     0,
       0,    15,   186,    16,    17,    18,     4,     5,     6,     7,
       0,     8,     0,     9,    10,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,    14,     0,     0,    15,     0,    16,    17,    18,     4,
       5,     6,     7,     0,     8,   170,     0,    10,     0,     0,
       0,     0,     0,    11,     0,     0,     0,     0,     0,    12,
      13,     0,     0,     0,    14,     0,     0,    15,     0,    16,
      17,    18,     4,     5,     6,     7,     0,     8,   198,     0,
      10,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,    14,     0,     0,
      15,     0,    16,    17,    18,     4,     5,     6,     7,     0,
       8,   206,     0,    10,     0,     0,     0,     0,     0,    11,
       0,     0,     0,     0,     0,    12,    13,     0,     0,     0,
      14,     0,     0,    15,     0,    16,    17,    18,     4,     5,
       6,     7,     0,     8,   207,     0,    10,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,    12,    13,
       0,     0,     0,    14,     0,     0,    15,     0,    16,    17,
      18,     4,     5,     6,     7,     0,     8,   211,     0,    10,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,    12,    13,     0,     0,     0,    14,     0,     0,    15,
       0,    16,    17,    18,   125,   126,   127,   128,   129,   130,
     131,     0,     0,   134,   135,   136
};

static const yytype_int16 yycheck[] =
{
       2,   104,     2,   103,     2,    11,     7,     9,    10,    13,
      12,    15,    14,     7,     0,    47,     3,    53,    54,    55,
      52,    52,     3,     7,    24,    12,    13,     3,     4,     5,
       6,    63,    63,    20,    21,    22,     3,     4,     5,     6,
      44,    17,    51,    19,    51,    69,    69,    46,    49,    52,
      17,    75,    75,   156,    88,    89,    62,    51,    62,    63,
      64,    65,    66,    67,    68,    49,    70,    69,    47,    73,
      48,    47,    50,    75,    51,   175,    63,    48,   178,    50,
      47,    56,    57,   186,    51,    51,   189,    14,    15,    16,
     190,    29,    47,    30,    98,    97,   100,    99,    78,    79,
      80,   103,    93,    94,    95,   208,    51,     3,     4,     5,
       6,    36,    37,   117,     7,    25,    41,    42,    43,    44,
      45,    17,     3,     4,     5,     6,    48,    63,    29,    48,
      51,    56,    57,    58,    59,    60,    17,    51,   140,    51,
     140,    64,   140,    41,    42,    43,    44,    45,    51,    47,
     154,    47,    51,    61,    52,    18,   158,    51,   158,    49,
     158,    63,   166,    51,    51,    63,    18,    64,    51,     7,
       9,     2,   174,   175,   193,   179,   178,     3,   182,   174,
     149,   183,     2,   183,    -1,   183,    12,    13,   190,    -1,
      -1,    -1,   196,    -1,    20,    21,    22,   199,   200,   199,
     200,   199,   200,    -1,    -1,    -1,    -1,    -1,   210,    -1,
     210,    -1,   210,     3,     4,     5,     6,    -1,     8,     9,
      -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,    -1,
      -1,    31,    32,    33,    34,    35,     3,     4,     5,     6,
      -1,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    28,    -1,    -1,    31,    -1,    33,    34,    35,     3,
       4,     5,     6,    -1,     8,     9,    -1,    11,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    -1,    28,    -1,    -1,    31,    -1,    33,
      34,    35,     3,     4,     5,     6,    -1,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,
      31,    -1,    33,    34,    35,     3,     4,     5,     6,    -1,
       8,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,
      28,    -1,    -1,    31,    -1,    33,    34,    35,     3,     4,
       5,     6,    -1,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    28,    -1,    -1,    31,    -1,    33,    34,
      35,     3,     4,     5,     6,    -1,     8,     9,    -1,    11,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,
      -1,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,    31,
      -1,    33,    34,    35,    81,    82,    83,    84,    85,    86,
      87,    -1,    -1,    90,    91,    92
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,     3,     4,     5,     6,     8,    10,
      11,    17,    23,    24,    28,    31,    33,    34,    35,    68,
      71,    72,    73,    75,    76,    77,    78,    79,    80,    81,
      83,    89,    92,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   106,    47,    73,    80,    81,    84,    85,
      86,    87,    88,    73,    73,    73,    51,    88,    73,    88,
      51,    51,    47,    41,    42,    43,    44,    45,    47,    52,
      63,    94,    80,    46,    51,    52,    51,    88,    53,    54,
      55,    36,    37,    41,    42,    43,    44,    45,    56,    57,
      58,    59,    60,    14,    15,    16,    29,    47,     7,    49,
      30,   107,    51,     7,    25,    88,    88,    88,    88,    88,
      88,    82,    88,    73,    83,    92,    88,    63,    88,    73,
      83,    48,    84,    84,    84,    86,    86,    86,    86,    86,
      86,    86,    85,    85,    86,    86,    86,    87,    87,    87,
     105,    69,    70,    73,    88,    12,    13,    20,    21,    22,
      73,    74,    90,    93,    19,    88,    29,    74,   105,    48,
      51,    51,    51,    51,    51,    48,    50,    64,    88,    51,
       9,    71,    95,    48,    50,    49,    51,    61,    94,     7,
      51,    88,    18,   105,    51,     9,    32,    88,    64,     7,
      49,    70,    74,    91,    74,    88,    18,    88,     9,   105,
     105,    74,    62,    72,    51,    88,     9,     9,     7,     9,
     105,     9
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 49 "./parser/grammar.y"
    { 
      (yyval.node) = new None_Terminal_Node("PROGRAM"); 
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node)); 
      print_ast((yyval.node), 0,"output.txt");
      root = (yyval.node);
      /* Semantic_Analysis semanticAnalysis($$);
      semanticAnalysis.Semantic_Analysis_Checks($$);
      semanticAnalysis.optimize($$);
      print_ast($$, 0,"optimize.txt"); */
      Codegen codegen_llvm((yyval.node));
      codegen_llvm.start_llvm((yyval.node));

    ;}
    break;

  case 3:
#line 65 "./parser/grammar.y"
    {
      (yyval.node) = (yyvsp[(1) - (2)].node);
      (yyval.node)->children.push_back((yyvsp[(2) - (2)].node));
    ;}
    break;

  case 4:
#line 69 "./parser/grammar.y"
    {
      (yyval.node) = (yyvsp[(1) - (2)].node);
      (yyval.node)->children.push_back((yyvsp[(2) - (2)].node));
    ;}
    break;

  case 5:
#line 73 "./parser/grammar.y"
    {
       (yyval.node) = (yyvsp[(1) - (2)].node);
       (yyval.node)->children.push_back((yyvsp[(2) - (2)].node));
     ;}
    break;

  case 6:
#line 78 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("DECLARATION"); 
    ;}
    break;

  case 7:
#line 84 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("ROUTINE_DECLERATION");
      (yyval.node)->children.push_back((yyvsp[(2) - (8)].node));
      (yyval.node)->children.push_back((yyvsp[(4) - (8)].node));
      (yyval.node)->children.push_back((yyvsp[(7) - (8)].node));
   ;}
    break;

  case 8:
#line 90 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("ROUTINE_DECLERATION");
      (yyval.node)->children.push_back((yyvsp[(2) - (10)].node));
      (yyval.node)->children.push_back((yyvsp[(4) - (10)].node));
      (yyval.node)->children.push_back((yyvsp[(9) - (10)].node));
      (yyval.node)->children.push_back((yyvsp[(7) - (10)].node));
   ;}
    break;

  case 9:
#line 99 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("PARAMETERS_EXPRESSION_LIST");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
    ;}
    break;

  case 10:
#line 103 "./parser/grammar.y"
    {
      (yyval.node) = (yyvsp[(1) - (3)].node);
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
    ;}
    break;

  case 11:
#line 107 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("PARAMETERS_EXPRESSION_LIST");
    ;}
    break;

  case 12:
#line 112 "./parser/grammar.y"
    { 
      (yyval.node) = new None_Terminal_Node("PARAMETER_DECLERATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
    ;}
    break;

  case 13:
#line 119 "./parser/grammar.y"
    { 
      (yyval.node) = new None_Terminal_Node("SIMPLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
    ;}
    break;

  case 14:
#line 123 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("SIMPLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 15:
#line 130 "./parser/grammar.y"
    { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[(2) - (5)].node));
      (yyval.node)->children.push_back(new Type_Node("none"));
      (yyval.node)->children.push_back((yyvsp[(4) - (5)].node));
    ;}
    break;

  case 16:
#line 136 "./parser/grammar.y"
    { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[(2) - (7)].node));
      (yyval.node)->children.push_back((yyvsp[(4) - (7)].node));
      (yyval.node)->children.push_back((yyvsp[(6) - (7)].node));
    ;}
    break;

  case 17:
#line 142 "./parser/grammar.y"
    { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[(2) - (5)].node));
      (yyval.node)->children.push_back((yyvsp[(4) - (5)].node));
    ;}
    break;

  case 18:
#line 149 "./parser/grammar.y"
    {
  (yyval.node) = new Identifier_Node(std::string((yyvsp[(1) - (1)].id_val)));
 ;}
    break;

  case 19:
#line 154 "./parser/grammar.y"
    {
    (yyval.node) = new Type_Node("integer");
  ;}
    break;

  case 20:
#line 157 "./parser/grammar.y"
    { 
    (yyval.node) = new Type_Node("real");
  ;}
    break;

  case 21:
#line 160 "./parser/grammar.y"
    {
    (yyval.node) = new Type_Node("boolean");
  ;}
    break;

  case 22:
#line 163 "./parser/grammar.y"
    {
      (yyval.node) = new Type_Node("identifier");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 23:
#line 167 "./parser/grammar.y"
    {
      (yyval.node) = new Type_Node("recordType");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 24:
#line 171 "./parser/grammar.y"
    {
      (yyval.node) = new Type_Node("arrayType");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 25:
#line 179 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 26:
#line 183 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 27:
#line 187 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 28:
#line 191 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[(1) - (2)].node));
    (yyval.node)->children.push_back((yyvsp[(2) - (2)].node));
  ;}
    break;

  case 29:
#line 196 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 30:
#line 202 "./parser/grammar.y"
    {
    (yyval.node) = new Operator("!");
   ;}
    break;

  case 31:
#line 207 "./parser/grammar.y"
    {
    (yyval.node) = new Integer_Node((yyvsp[(1) - (1)].int_val));
  ;}
    break;

  case 32:
#line 212 "./parser/grammar.y"
    {
    (yyval.node) = new Real_Node((yyvsp[(1) - (1)].real_val));
  ;}
    break;

  case 33:
#line 217 "./parser/grammar.y"
    {
    (yyval.node) = new Boolean_Node((yyvsp[(1) - (1)].bool_val));
  ;}
    break;

  case 34:
#line 223 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 35:
#line 227 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 36:
#line 231 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 37:
#line 235 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 38:
#line 242 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("Routine_Call");
      (yyval.node)->children.push_back((yyvsp[(1) - (4)].node));
      (yyval.node)->children.push_back((yyvsp[(3) - (4)].node));
    ;}
    break;

  case 39:
#line 250 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("Argument_Expression_List");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
    ;}
    break;

  case 40:
#line 254 "./parser/grammar.y"
    {
      (yyval.node) = (yyvsp[(1) - (3)].node);
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
    ;}
    break;

  case 41:
#line 258 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("Argument_Expression_List");
    ;}
    break;

  case 42:
#line 264 "./parser/grammar.y"
    {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
     (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 43:
#line 269 "./parser/grammar.y"
    {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
     (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 44:
#line 274 "./parser/grammar.y"
    {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
     (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 45:
#line 279 "./parser/grammar.y"
    {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
     (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 46:
#line 292 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("SUMMAND");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
   ;}
    break;

  case 47:
#line 296 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("SUMMAND");
      (yyval.node)->children.push_back((yyvsp[(2) - (3)].node));
   ;}
    break;

  case 48:
#line 304 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
   ;}
    break;

  case 49:
#line 308 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("*"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 50:
#line 314 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("/"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 51:
#line 320 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("%"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 52:
#line 329 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
   ;}
    break;

  case 53:
#line 333 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("+"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 54:
#line 339 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("-"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 55:
#line 348 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
   ;}
    break;

  case 56:
#line 352 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("<"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 57:
#line 358 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("<="));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 58:
#line 364 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator(">"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 59:
#line 370 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator(">="));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 60:
#line 376 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("="));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 61:
#line 382 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("-="));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 62:
#line 388 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("+="));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 63:
#line 394 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("*="));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 64:
#line 400 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("/="));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 65:
#line 406 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("%="));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 66:
#line 416 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
   ;}
    break;

  case 67:
#line 420 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("and"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 68:
#line 426 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("or"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 69:
#line 432 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[(1) - (3)].node));
      (yyval.node)->children.push_back(new Operator("xor"));
      (yyval.node)->children.push_back((yyvsp[(3) - (3)].node));
   ;}
    break;

  case 70:
#line 442 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("TYPE_DECLARATION");
    (yyval.node)->children.push_back((yyvsp[(2) - (5)].node));
    (yyval.node)->children.push_back((yyvsp[(4) - (5)].node));
   ;}
    break;

  case 71:
#line 450 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("RECORD_TYPE");
      (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
   ;}
    break;

  case 72:
#line 457 "./parser/grammar.y"
    {
      (yyval.node) = (yyvsp[(1) - (2)].node);
      (yyval.node)->children.push_back((yyvsp[(2) - (2)].node));
    ;}
    break;

  case 73:
#line 461 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATIONS");
    ;}
    break;

  case 74:
#line 467 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("ARRAY_ACCESS");
    (yyval.node)->children.push_back((yyvsp[(1) - (2)].node));
    (yyval.node)->children.push_back((yyvsp[(2) - (2)].node));
  ;}
    break;

  case 75:
#line 475 "./parser/grammar.y"
    {
        (yyval.node) = new None_Terminal_Node("ARRAY_TYPE");
        (yyval.node)->children.push_back((yyvsp[(2) - (3)].node)); 
        (yyval.node)->children.push_back((yyvsp[(3) - (3)].node)); 
    ;}
    break;

  case 76:
#line 483 "./parser/grammar.y"
    {
        (yyval.node) = new None_Terminal_Node("DIMENSION_LIST");
        (yyval.node)->children.push_back((yyvsp[(2) - (3)].node)); 
    ;}
    break;

  case 77:
#line 487 "./parser/grammar.y"
    {
        (yyval.node) = (yyvsp[(1) - (4)].node); 
        (yyval.node)->children.push_back((yyvsp[(3) - (4)].node)); 
    ;}
    break;

  case 78:
#line 495 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
   ;}
    break;

  case 79:
#line 499 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
   ;}
    break;

  case 80:
#line 503 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
   ;}
    break;

  case 81:
#line 507 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
   ;}
    break;

  case 82:
#line 511 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (2)].node));
   ;}
    break;

  case 83:
#line 515 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (2)].node));
   ;}
    break;

  case 84:
#line 521 "./parser/grammar.y"
    {
     (yyval.node) =  new None_Terminal_Node("PRINT_STATMENT");
     (yyval.node)->children.push_back((yyvsp[(3) - (4)].node));
  ;}
    break;

  case 85:
#line 527 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("JUMP_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 86:
#line 531 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("JUMP_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 87:
#line 535 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("JUMP_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 88:
#line 541 "./parser/grammar.y"
    {
   (yyval.node) = new None_Terminal_Node("RETURN_EX");
 ;}
    break;

  case 89:
#line 544 "./parser/grammar.y"
    {
     (yyval.node) = new None_Terminal_Node("RETURN_EX");
     (yyval.node)->children.push_back((yyvsp[(2) - (3)].node));
 ;}
    break;

  case 90:
#line 550 "./parser/grammar.y"
    {
     (yyval.node) = new None_Terminal_Node("CONTINUE_EX");
 ;}
    break;

  case 91:
#line 555 "./parser/grammar.y"
    {
     (yyval.node) = new None_Terminal_Node("BREAK_EX");
 ;}
    break;

  case 92:
#line 561 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("IF_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(2) - (5)].node));
    (yyval.node)->children.push_back((yyvsp[(4) - (5)].node));
  ;}
    break;

  case 93:
#line 566 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("IF_STATEMENT_ELSE");
    (yyval.node)->children.push_back((yyvsp[(2) - (7)].node));
    (yyval.node)->children.push_back((yyvsp[(4) - (7)].node));
    (yyval.node)->children.push_back((yyvsp[(6) - (7)].node));
  ;}
    break;

  case 94:
#line 575 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("ASSIGN_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (4)].node));
    (yyval.node)->children.push_back(new Operator(":="));
    (yyval.node)->children.push_back((yyvsp[(3) - (4)].node));
  ;}
    break;

  case 95:
#line 581 "./parser/grammar.y"
    {
    (yyval.node)->children.push_back((yyvsp[(1) - (4)].node));
    (yyval.node)->children.push_back(new Operator("-="));
    (yyval.node)->children.push_back((yyvsp[(3) - (4)].node));
  ;}
    break;

  case 96:
#line 586 "./parser/grammar.y"
    {
    (yyval.node)->children.push_back((yyvsp[(1) - (4)].node));
    (yyval.node)->children.push_back(new Operator("+="));
    (yyval.node)->children.push_back((yyvsp[(3) - (4)].node));
  ;}
    break;

  case 97:
#line 591 "./parser/grammar.y"
    {
    (yyval.node)->children.push_back((yyvsp[(1) - (4)].node));
    (yyval.node)->children.push_back(new Operator("*="));
    (yyval.node)->children.push_back((yyvsp[(3) - (4)].node));
  ;}
    break;

  case 98:
#line 596 "./parser/grammar.y"
    {
    (yyval.node)->children.push_back((yyvsp[(1) - (4)].node));
    (yyval.node)->children.push_back(new Operator("/="));
    (yyval.node)->children.push_back((yyvsp[(3) - (4)].node));
  ;}
    break;

  case 99:
#line 601 "./parser/grammar.y"
    {
    (yyval.node)->children.push_back((yyvsp[(1) - (4)].node));
    (yyval.node)->children.push_back(new Operator("%="));
    (yyval.node)->children.push_back((yyvsp[(3) - (4)].node));
  ;}
    break;

  case 100:
#line 609 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("ITERATION_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 101:
#line 613 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("ITERATION_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(1) - (1)].node));
  ;}
    break;

  case 102:
#line 619 "./parser/grammar.y"
    {
    (yyval.node) = new None_Terminal_Node("WHILE_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[(2) - (5)].node));
    (yyval.node)->children.push_back((yyvsp[(4) - (5)].node));
   ;}
    break;

  case 103:
#line 626 "./parser/grammar.y"
    {
      (yyval.node) = (yyvsp[(1) - (2)].node);
      (yyval.node)->children.push_back((yyvsp[(2) - (2)].node));
    ;}
    break;

  case 104:
#line 630 "./parser/grammar.y"
    {
       (yyval.node) = (yyvsp[(1) - (2)].node);
       (yyval.node)->children.push_back((yyvsp[(2) - (2)].node));
    ;}
    break;

  case 105:
#line 634 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("BODY"); 
    ;}
    break;

  case 106:
#line 640 "./parser/grammar.y"
    {
      (yyval.node) = new None_Terminal_Node("FOR_STATEMENT");
      (yyval.node)->children.push_back((yyvsp[(2) - (6)].node));
      (yyval.node)->children.push_back((yyvsp[(3) - (6)].node));
      (yyval.node)->children.push_back((yyvsp[(5) - (6)].node));
   ;}
    break;

  case 107:
#line 648 "./parser/grammar.y"
    {
     (yyval.node) = new None_Terminal_Node("RANGE_EX");
     (yyval.node)->children.push_back((yyvsp[(2) - (4)].node));
     (yyval.node)->children.push_back((yyvsp[(4) - (4)].node));
   ;}
    break;

  case 108:
#line 653 "./parser/grammar.y"
    {
     (yyval.node) = new None_Terminal_Node("RANGE_REVERSE");
     (yyval.node)->children.push_back((yyvsp[(3) - (5)].node));
     (yyval.node)->children.push_back((yyvsp[(5) - (5)].node));
   ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2597 "./parser/grammar.tab.c"
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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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


#line 660 "./parser/grammar.y"


void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}
