/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include "lexer_2.hpp"
#include "ast.hpp"

void yyerror(char *s);
int counter = 1;
int indent = 0;
void print_indent() {
  for(int i = 0; i < indent; i++) printf("  ");
}

#line 85 "grammar.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "grammar.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 4,            /* INTEGER_LITERAL  */
  YYSYMBOL_REAL_LITERAL = 5,               /* REAL_LITERAL  */
  YYSYMBOL_BOOLEAN_LITERAL = 6,            /* BOOLEAN_LITERAL  */
  YYSYMBOL_IS = 7,                         /* IS  */
  YYSYMBOL_WHILE = 8,                      /* WHILE  */
  YYSYMBOL_END = 9,                        /* END  */
  YYSYMBOL_ROUTINE = 10,                   /* ROUTINE  */
  YYSYMBOL_VAR = 11,                       /* VAR  */
  YYSYMBOL_INTEGER_LITERAL_KEYWORD = 12,   /* INTEGER_LITERAL_KEYWORD  */
  YYSYMBOL_REAL_LITERAL_KEYWORD = 13,      /* REAL_LITERAL_KEYWORD  */
  YYSYMBOL_OR = 14,                        /* OR  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_XOR = 16,                       /* XOR  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_RANGE = 18,                     /* RANGE  */
  YYSYMBOL_REVERSE = 19,                   /* REVERSE  */
  YYSYMBOL_BOOLEAN_LITERAL_KEYWORD = 20,   /* BOOLEAN_LITERAL_KEYWORD  */
  YYSYMBOL_RECORD = 21,                    /* RECORD  */
  YYSYMBOL_ARRAY = 22,                     /* ARRAY  */
  YYSYMBOL_FOR = 23,                       /* FOR  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_THEN = 25,                      /* THEN  */
  YYSYMBOL_TRUE = 26,                      /* TRUE  */
  YYSYMBOL_FALSE = 27,                     /* FALSE  */
  YYSYMBOL_TYPE = 28,                      /* TYPE  */
  YYSYMBOL_LOOP = 29,                      /* LOOP  */
  YYSYMBOL_IN = 30,                        /* IN  */
  YYSYMBOL_IF = 31,                        /* IF  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_BREAK = 33,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 34,                  /* CONTINUE  */
  YYSYMBOL_LE_OP = 35,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 36,                     /* GE_OP  */
  YYSYMBOL_NE_OP = 37,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 38,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 39,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 40,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 41,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 42,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 43,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 44,                /* SUB_ASSIGN  */
  YYSYMBOL_ASSIGN_OP = 45,                 /* ASSIGN_OP  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* ':'  */
  YYSYMBOL_48_ = 48,                       /* '['  */
  YYSYMBOL_49_ = 49,                       /* ']'  */
  YYSYMBOL_50_ = 50,                       /* '.'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '+'  */
  YYSYMBOL_54_ = 54,                       /* '-'  */
  YYSYMBOL_55_ = 55,                       /* '*'  */
  YYSYMBOL_56_ = 56,                       /* '/'  */
  YYSYMBOL_57_ = 57,                       /* '%'  */
  YYSYMBOL_58_ = 58,                       /* '<'  */
  YYSYMBOL_59_ = 59,                       /* '>'  */
  YYSYMBOL_60_ = 60,                       /* '='  */
  YYSYMBOL_61_ = 61,                       /* '{'  */
  YYSYMBOL_62_ = 62,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 63,                  /* $accept  */
  YYSYMBOL_program = 64,                   /* program  */
  YYSYMBOL_declarations = 65,              /* declarations  */
  YYSYMBOL_simpleDeclaration = 66,         /* simpleDeclaration  */
  YYSYMBOL_variableDeclaration = 67,       /* variableDeclaration  */
  YYSYMBOL_identifier = 68,                /* identifier  */
  YYSYMBOL_type = 69,                      /* type  */
  YYSYMBOL_primary_expression = 70,        /* primary_expression  */
  YYSYMBOL_unary_op = 71,                  /* unary_op  */
  YYSYMBOL_int_exp = 72,                   /* int_exp  */
  YYSYMBOL_real_exp = 73,                  /* real_exp  */
  YYSYMBOL_boolean_exp = 74,               /* boolean_exp  */
  YYSYMBOL_primary = 75,                   /* primary  */
  YYSYMBOL_array_access_expression = 76,   /* array_access_expression  */
  YYSYMBOL_record_expession_access = 77,   /* record_expession_access  */
  YYSYMBOL_summand = 78,                   /* summand  */
  YYSYMBOL_factor = 79,                    /* factor  */
  YYSYMBOL_simple = 80,                    /* simple  */
  YYSYMBOL_relation = 81,                  /* relation  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_typeDecleration = 83,           /* typeDecleration  */
  YYSYMBOL_recordType = 84,                /* recordType  */
  YYSYMBOL_variableDeclerations = 85,      /* variableDeclerations  */
  YYSYMBOL_arrayType = 86                  /* arrayType  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    57,     2,     2,
      51,    52,    55,    53,     2,    54,    50,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    46,
      58,    60,    59,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
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
      45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    51,    63,    69,    73,    80,    86,    92,
      99,   104,   107,   110,   113,   117,   121,   129,   133,   137,
     141,   146,   152,   157,   162,   167,   173,   177,   181,   189,
     195,   202,   207,   212,   217,   225,   229,   237,   241,   247,
     256,   260,   266,   272,   281,   285,   291,   297,   303,   309,
     315,   321,   327,   333,   339,   349,   353,   359,   365,   375,
     383,   390,   394,   400
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER_LITERAL", "REAL_LITERAL", "BOOLEAN_LITERAL", "IS", "WHILE",
  "END", "ROUTINE", "VAR", "INTEGER_LITERAL_KEYWORD",
  "REAL_LITERAL_KEYWORD", "OR", "AND", "XOR", "NOT", "RANGE", "REVERSE",
  "BOOLEAN_LITERAL_KEYWORD", "RECORD", "ARRAY", "FOR", "RETURN", "THEN",
  "TRUE", "FALSE", "TYPE", "LOOP", "IN", "IF", "ELSE", "BREAK", "CONTINUE",
  "LE_OP", "GE_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "ASSIGN_OP", "';'", "':'",
  "'['", "']'", "'.'", "'('", "')'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'<'", "'>'", "'='", "'{'", "'}'", "$accept", "program", "declarations",
  "simpleDeclaration", "variableDeclaration", "identifier", "type",
  "primary_expression", "unary_op", "int_exp", "real_exp", "boolean_exp",
  "primary", "array_access_expression", "record_expession_access",
  "summand", "factor", "simple", "relation", "expression",
  "typeDecleration", "recordType", "variableDeclerations", "arrayType", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -36,     7,     6,   -36,    23,    23,   -36,   -36,   -36,   -36,
      -3,    44,     8,    40,    40,   -36,   -36,   -36,   -36,     8,
     -21,   -36,    60,   -36,   -36,   -36,   -36,   -18,    -9,   -36,
     -35,   -20,    34,   -13,   -36,   -36,   -36,    -7,    10,   -36,
       1,   -36,   -36,   -36,    41,    60,    23,   -36,    60,    23,
      23,     8,     8,     8,     8,     8,     8,     8,     8,     8,
       8,     8,     8,     8,     8,     8,     8,     8,     8,   -36,
     -36,     8,     8,   -36,   -36,    18,   -36,    27,   -36,    47,
      48,   -36,   -36,    26,    26,    26,    26,    26,    26,    26,
     -35,   -35,   -35,    26,    26,    26,   -36,   -36,   -36,    -5,
      43,    29,   -36,   -36,    88,   -36,    40,   -36,   -36,   -36
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     3,     5,     6,    10,
       0,     0,     0,     0,     0,    23,    24,    25,    22,     0,
      21,    26,     0,    17,    18,    19,    35,    27,    28,    37,
      40,    44,    55,     0,    11,    12,    13,     0,     0,    14,
       0,    15,    16,    59,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     7,
      62,     0,     0,     9,    36,     0,    31,     0,    32,    33,
      34,    38,    39,    46,    48,    52,    53,    54,    51,    50,
      41,    42,    43,    45,    47,    49,    57,    56,    58,     0,
       0,     0,    29,    30,     0,    61,     0,     8,    60,    63
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -36,   -36,   -36,   -36,    -1,    -4,   -12,   -36,   -36,   -36,
     -36,   -36,   -17,    49,   -36,    39,    24,    15,    21,   -16,
     -36,   -36,   -36,   -36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     6,     7,    20,    40,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
       8,    41,    99,    42
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      10,    11,    43,    44,    12,    47,     4,     3,    72,    39,
      39,     9,    15,    16,    17,    53,    54,     4,    51,    52,
      55,    56,    57,    58,    59,    18,     9,    45,    75,    46,
      48,    77,    49,    69,     5,    60,    61,    62,    63,    64,
      65,    50,    76,     9,    13,    78,    79,    73,    66,    67,
      68,    14,    34,    35,    70,   100,   101,   104,    71,    19,
      36,    37,    38,     9,    15,    16,    17,   102,    83,    84,
      85,    86,    87,    88,    89,   107,   103,    18,    93,    94,
      95,    60,    61,    62,    90,    91,    92,    96,    97,    98,
      81,    82,   106,    74,   109,    45,    48,   108,   105,    80,
       0,     0,    39
};

static const yytype_int8 yycheck[] =
{
       4,     5,    14,    19,     7,    22,    11,     0,     7,    13,
      14,     3,     4,     5,     6,    35,    36,    11,    53,    54,
      40,    41,    42,    43,    44,    17,     3,    48,    45,    50,
      48,    48,    50,    46,    28,    55,    56,    57,    58,    59,
      60,    50,    46,     3,    47,    49,    50,    46,    14,    15,
      16,     7,    12,    13,    61,    71,    72,    62,    48,    51,
      20,    21,    22,     3,     4,     5,     6,    49,    53,    54,
      55,    56,    57,    58,    59,    46,    49,    17,    63,    64,
      65,    55,    56,    57,    60,    61,    62,    66,    67,    68,
      51,    52,    49,    52,   106,    48,    48,     9,    99,    50,
      -1,    -1,   106
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    64,    65,     0,    11,    28,    66,    67,    83,     3,
      68,    68,     7,    47,     7,     4,     5,     6,    17,    51,
      68,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    12,    13,    20,    21,    22,    68,
      69,    84,    86,    69,    82,    48,    50,    75,    48,    50,
      50,    53,    54,    35,    36,    40,    41,    42,    43,    44,
      55,    56,    57,    58,    59,    60,    14,    15,    16,    46,
      61,    48,     7,    46,    52,    75,    68,    75,    68,    68,
      76,    78,    78,    80,    80,    80,    80,    80,    80,    80,
      79,    79,    79,    80,    80,    80,    81,    81,    81,    85,
      82,    82,    49,    49,    62,    67,    49,    46,     9,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    67,    67,    67,
      68,    69,    69,    69,    69,    69,    69,    70,    70,    70,
      70,    70,    71,    72,    73,    74,    75,    75,    75,    76,
      76,    77,    77,    77,    77,    78,    78,    79,    79,    79,
      80,    80,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    82,    82,    82,    82,    83,
      84,    85,    85,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     5,     7,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     3,     3,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     3,     4,
       5,     2,     0,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declarations  */
#line 43 "grammar.y"
                 { 
      (yyval.node) = new None_Terminal_Node("PROGRAM"); 
      (yyval.node)->children.push_back((yyvsp[0].node)); 
      print_ast((yyval.node), 0);
    }
#line 1238 "grammar.tab.c"
    break;

  case 3: /* declarations: declarations simpleDeclaration  */
#line 51 "grammar.y"
                                   {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1247 "grammar.tab.c"
    break;

  case 4: /* declarations: %empty  */
#line 63 "grammar.y"
                {
      (yyval.node) = new None_Terminal_Node("DECLARATION"); 
    }
#line 1255 "grammar.tab.c"
    break;

  case 5: /* simpleDeclaration: variableDeclaration  */
#line 69 "grammar.y"
                        { 
      (yyval.node) = new None_Terminal_Node("SIMPLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1264 "grammar.tab.c"
    break;

  case 6: /* simpleDeclaration: typeDecleration  */
#line 73 "grammar.y"
                   {
      (yyval.node) = new None_Terminal_Node("SIMPLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1273 "grammar.tab.c"
    break;

  case 7: /* variableDeclaration: VAR identifier IS expression ';'  */
#line 80 "grammar.y"
                                     { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back(new Type_Node("none"));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1284 "grammar.tab.c"
    break;

  case 8: /* variableDeclaration: VAR identifier ':' type IS expression ';'  */
#line 86 "grammar.y"
                                              { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[-5].node));
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1295 "grammar.tab.c"
    break;

  case 9: /* variableDeclaration: VAR identifier ':' type ';'  */
#line 92 "grammar.y"
                               { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1305 "grammar.tab.c"
    break;

  case 10: /* identifier: IDENTIFIER  */
#line 99 "grammar.y"
           {
  (yyval.node) = new Identifier_Node(std::string((yyvsp[0].id_val)));
 }
#line 1313 "grammar.tab.c"
    break;

  case 11: /* type: INTEGER_LITERAL_KEYWORD  */
#line 104 "grammar.y"
                            {
    (yyval.node) = new Type_Node("integer");
  }
#line 1321 "grammar.tab.c"
    break;

  case 12: /* type: REAL_LITERAL_KEYWORD  */
#line 107 "grammar.y"
                         { 
    (yyval.node) = new Type_Node("real");
  }
#line 1329 "grammar.tab.c"
    break;

  case 13: /* type: BOOLEAN_LITERAL_KEYWORD  */
#line 110 "grammar.y"
                            {
    (yyval.node) = new Type_Node("boolean");
  }
#line 1337 "grammar.tab.c"
    break;

  case 14: /* type: identifier  */
#line 113 "grammar.y"
               {
      (yyval.node) = new Type_Node("identifier");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1346 "grammar.tab.c"
    break;

  case 15: /* type: recordType  */
#line 117 "grammar.y"
              {
      (yyval.node) = new Type_Node("recordType");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1355 "grammar.tab.c"
    break;

  case 16: /* type: arrayType  */
#line 121 "grammar.y"
             {
      (yyval.node) = new Type_Node("arrayType");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1364 "grammar.tab.c"
    break;

  case 17: /* primary_expression: int_exp  */
#line 129 "grammar.y"
                 {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1373 "grammar.tab.c"
    break;

  case 18: /* primary_expression: real_exp  */
#line 133 "grammar.y"
            {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1382 "grammar.tab.c"
    break;

  case 19: /* primary_expression: boolean_exp  */
#line 137 "grammar.y"
               {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1391 "grammar.tab.c"
    break;

  case 20: /* primary_expression: unary_op primary  */
#line 141 "grammar.y"
                    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1401 "grammar.tab.c"
    break;

  case 21: /* primary_expression: identifier  */
#line 146 "grammar.y"
                    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1410 "grammar.tab.c"
    break;

  case 22: /* unary_op: NOT  */
#line 152 "grammar.y"
      {
    (yyval.node) = new Operator("!");
   }
#line 1418 "grammar.tab.c"
    break;

  case 23: /* int_exp: INTEGER_LITERAL  */
#line 157 "grammar.y"
                   {
    (yyval.node) = new Integer_Node((yyvsp[0].int_val));
  }
#line 1426 "grammar.tab.c"
    break;

  case 24: /* real_exp: REAL_LITERAL  */
#line 162 "grammar.y"
                 {
    (yyval.node) = new Real_Node((yyvsp[0].real_val));
  }
#line 1434 "grammar.tab.c"
    break;

  case 25: /* boolean_exp: BOOLEAN_LITERAL  */
#line 167 "grammar.y"
                    {
    (yyval.node) = new Boolean_Node((yyvsp[0].bool_val));
  }
#line 1442 "grammar.tab.c"
    break;

  case 26: /* primary: primary_expression  */
#line 173 "grammar.y"
                            {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1451 "grammar.tab.c"
    break;

  case 27: /* primary: array_access_expression  */
#line 177 "grammar.y"
                           {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1460 "grammar.tab.c"
    break;

  case 28: /* primary: record_expession_access  */
#line 181 "grammar.y"
                           {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1469 "grammar.tab.c"
    break;

  case 29: /* array_access_expression: identifier '[' primary ']'  */
#line 189 "grammar.y"
                               {
    (yyval.node) = new None_Terminal_Node("ARRAY_ACCESS");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));

  }
#line 1480 "grammar.tab.c"
    break;

  case 30: /* array_access_expression: array_access_expression '[' primary ']'  */
#line 195 "grammar.y"
                                            {
    (yyval.node) = new None_Terminal_Node("ARRAY_ACCESS");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 1490 "grammar.tab.c"
    break;

  case 31: /* record_expession_access: identifier '.' identifier  */
#line 202 "grammar.y"
                               {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1500 "grammar.tab.c"
    break;

  case 32: /* record_expession_access: array_access_expression '.' identifier  */
#line 207 "grammar.y"
                                            {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1510 "grammar.tab.c"
    break;

  case 33: /* record_expession_access: record_expession_access '.' identifier  */
#line 212 "grammar.y"
                                             {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1520 "grammar.tab.c"
    break;

  case 34: /* record_expession_access: record_expession_access '.' array_access_expression  */
#line 217 "grammar.y"
                                                         {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1530 "grammar.tab.c"
    break;

  case 35: /* summand: primary  */
#line 225 "grammar.y"
            {
      (yyval.node) = new None_Terminal_Node("SUMMAND");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1539 "grammar.tab.c"
    break;

  case 36: /* summand: '(' expression ')'  */
#line 229 "grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("SUMMAND");
      (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 1548 "grammar.tab.c"
    break;

  case 37: /* factor: summand  */
#line 237 "grammar.y"
            {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1557 "grammar.tab.c"
    break;

  case 38: /* factor: factor '+' summand  */
#line 241 "grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("+"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1568 "grammar.tab.c"
    break;

  case 39: /* factor: factor '-' summand  */
#line 247 "grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("-"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1579 "grammar.tab.c"
    break;

  case 40: /* simple: factor  */
#line 256 "grammar.y"
           {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1588 "grammar.tab.c"
    break;

  case 41: /* simple: simple '*' factor  */
#line 260 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("*"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1599 "grammar.tab.c"
    break;

  case 42: /* simple: simple '/' factor  */
#line 266 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("/"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1610 "grammar.tab.c"
    break;

  case 43: /* simple: simple '%' factor  */
#line 272 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("%"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1621 "grammar.tab.c"
    break;

  case 44: /* relation: simple  */
#line 281 "grammar.y"
           {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1630 "grammar.tab.c"
    break;

  case 45: /* relation: simple '<' simple  */
#line 285 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("<"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1641 "grammar.tab.c"
    break;

  case 46: /* relation: simple LE_OP simple  */
#line 291 "grammar.y"
                        {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("<="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1652 "grammar.tab.c"
    break;

  case 47: /* relation: simple '>' simple  */
#line 297 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator(">"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1663 "grammar.tab.c"
    break;

  case 48: /* relation: simple GE_OP simple  */
#line 303 "grammar.y"
                        {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator(">="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1674 "grammar.tab.c"
    break;

  case 49: /* relation: simple '=' simple  */
#line 309 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1685 "grammar.tab.c"
    break;

  case 50: /* relation: simple SUB_ASSIGN simple  */
#line 315 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("-="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1696 "grammar.tab.c"
    break;

  case 51: /* relation: simple ADD_ASSIGN simple  */
#line 321 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("+="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1707 "grammar.tab.c"
    break;

  case 52: /* relation: simple MUL_ASSIGN simple  */
#line 327 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("*="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1718 "grammar.tab.c"
    break;

  case 53: /* relation: simple DIV_ASSIGN simple  */
#line 333 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("/="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1729 "grammar.tab.c"
    break;

  case 54: /* relation: simple MOD_ASSIGN simple  */
#line 339 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("%="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1740 "grammar.tab.c"
    break;

  case 55: /* expression: relation  */
#line 349 "grammar.y"
              {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1749 "grammar.tab.c"
    break;

  case 56: /* expression: relation AND relation  */
#line 353 "grammar.y"
                          {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("and"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1760 "grammar.tab.c"
    break;

  case 57: /* expression: relation OR relation  */
#line 359 "grammar.y"
                         {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("or"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1771 "grammar.tab.c"
    break;

  case 58: /* expression: relation XOR relation  */
#line 365 "grammar.y"
                          {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("xor"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1782 "grammar.tab.c"
    break;

  case 59: /* typeDecleration: TYPE identifier IS type  */
#line 375 "grammar.y"
                             {
    (yyval.node) = new None_Terminal_Node("TYPE_DECLARATION");
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1792 "grammar.tab.c"
    break;

  case 60: /* recordType: RECORD '{' variableDeclerations '}' END  */
#line 383 "grammar.y"
                                             {
      (yyval.node) = new None_Terminal_Node("RECORD_TYPE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
   }
#line 1801 "grammar.tab.c"
    break;

  case 61: /* variableDeclerations: variableDeclerations variableDeclaration  */
#line 390 "grammar.y"
                                             {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1810 "grammar.tab.c"
    break;

  case 62: /* variableDeclerations: %empty  */
#line 394 "grammar.y"
                  {
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATIONS");
    }
#line 1818 "grammar.tab.c"
    break;

  case 63: /* arrayType: ARRAY '[' expression ']' type  */
#line 400 "grammar.y"
                                   {
      (yyval.node) = new None_Terminal_Node("ARRAY_TYPE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1828 "grammar.tab.c"
    break;


#line 1832 "grammar.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 433 "grammar.y"


void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}
