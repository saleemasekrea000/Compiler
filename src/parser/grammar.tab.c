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
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* '['  */
  YYSYMBOL_52_ = 52,                       /* ']'  */
  YYSYMBOL_53_ = 53,                       /* '.'  */
  YYSYMBOL_54_ = 54,                       /* '+'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '*'  */
  YYSYMBOL_57_ = 57,                       /* '/'  */
  YYSYMBOL_58_ = 58,                       /* '%'  */
  YYSYMBOL_59_ = 59,                       /* '<'  */
  YYSYMBOL_60_ = 60,                       /* '>'  */
  YYSYMBOL_61_ = 61,                       /* '='  */
  YYSYMBOL_62_ = 62,                       /* '{'  */
  YYSYMBOL_63_ = 63,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_program = 65,                   /* program  */
  YYSYMBOL_declarations = 66,              /* declarations  */
  YYSYMBOL_routine_deceration = 67,        /* routine_deceration  */
  YYSYMBOL_parameters_list = 68,           /* parameters_list  */
  YYSYMBOL_parameter_decleration = 69,     /* parameter_decleration  */
  YYSYMBOL_simpleDeclaration = 70,         /* simpleDeclaration  */
  YYSYMBOL_variableDeclaration = 71,       /* variableDeclaration  */
  YYSYMBOL_identifier = 72,                /* identifier  */
  YYSYMBOL_type = 73,                      /* type  */
  YYSYMBOL_primary_expression = 74,        /* primary_expression  */
  YYSYMBOL_unary_op = 75,                  /* unary_op  */
  YYSYMBOL_int_exp = 76,                   /* int_exp  */
  YYSYMBOL_real_exp = 77,                  /* real_exp  */
  YYSYMBOL_boolean_exp = 78,               /* boolean_exp  */
  YYSYMBOL_primary = 79,                   /* primary  */
  YYSYMBOL_routine_call = 80,              /* routine_call  */
  YYSYMBOL_argument_expression_list = 81,  /* argument_expression_list  */
  YYSYMBOL_array_access_expression = 82,   /* array_access_expression  */
  YYSYMBOL_record_expession_access = 83,   /* record_expession_access  */
  YYSYMBOL_summand = 84,                   /* summand  */
  YYSYMBOL_factor = 85,                    /* factor  */
  YYSYMBOL_simple = 86,                    /* simple  */
  YYSYMBOL_relation = 87,                  /* relation  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_typeDecleration = 89,           /* typeDecleration  */
  YYSYMBOL_recordType = 90,                /* recordType  */
  YYSYMBOL_variableDeclerations = 91,      /* variableDeclerations  */
  YYSYMBOL_arrayType = 92,                 /* arrayType  */
  YYSYMBOL_statement = 93,                 /* statement  */
  YYSYMBOL_jumpStatement = 94,             /* jumpStatement  */
  YYSYMBOL_return_exp = 95,                /* return_exp  */
  YYSYMBOL_continue_exp = 96,              /* continue_exp  */
  YYSYMBOL_break_exp = 97,                 /* break_exp  */
  YYSYMBOL_IfStatement = 98,               /* IfStatement  */
  YYSYMBOL_assign_expression = 99,         /* assign_expression  */
  YYSYMBOL_iteration_statement = 100,      /* iteration_statement  */
  YYSYMBOL_while_expression = 101,         /* while_expression  */
  YYSYMBOL_body = 102,                     /* body  */
  YYSYMBOL_for_expression = 103,           /* for_expression  */
  YYSYMBOL_range = 104                     /* range  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   414

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  190

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
       2,     2,     2,     2,     2,     2,     2,    58,     2,     2,
      46,    47,    56,    54,    49,    55,    53,    57,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    50,
      59,    61,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    63,     2,     2,     2,     2,
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
       0,    45,    45,    53,    57,    61,    66,    72,    78,    87,
      91,    95,   100,   107,   111,   118,   124,   130,   137,   142,
     145,   148,   151,   155,   159,   167,   171,   175,   179,   184,
     190,   195,   200,   205,   211,   215,   219,   223,   230,   238,
     242,   246,   251,   257,   264,   269,   274,   279,   287,   291,
     299,   303,   309,   318,   322,   328,   334,   343,   347,   353,
     359,   365,   371,   377,   383,   389,   395,   401,   411,   415,
     421,   427,   437,   445,   452,   456,   462,   470,   474,   478,
     482,   486,   492,   496,   500,   506,   509,   515,   520,   526,
     531,   539,   546,   550,   556,   563,   567,   571,   577,   585,
     590
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
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "ASSIGN_OP", "'('", "')'",
  "':'", "','", "';'", "'['", "']'", "'.'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'<'", "'>'", "'='", "'{'", "'}'", "$accept", "program",
  "declarations", "routine_deceration", "parameters_list",
  "parameter_decleration", "simpleDeclaration", "variableDeclaration",
  "identifier", "type", "primary_expression", "unary_op", "int_exp",
  "real_exp", "boolean_exp", "primary", "routine_call",
  "argument_expression_list", "array_access_expression",
  "record_expession_access", "summand", "factor", "simple", "relation",
  "expression", "typeDecleration", "recordType", "variableDeclerations",
  "arrayType", "statement", "jumpStatement", "return_exp", "continue_exp",
  "break_exp", "IfStatement", "assign_expression", "iteration_statement",
  "while_expression", "body", "for_expression", "range", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -92,    23,   179,   -92,   -92,   -92,   -92,   -92,    37,    28,
      28,   -92,    28,    21,    28,    37,   -14,   -13,   -92,   -92,
     -92,    27,   -92,   106,   -92,   -92,   -92,     7,   -11,   -37,
      -9,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,    37,   -92,   -92,   -92,   -48,   340,    70,    16,
       4,     8,    32,   -92,     3,    54,    39,   -92,   -92,    37,
     106,    28,   -92,    37,   -92,   106,    28,    28,    41,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,   -92,    28,    37,
     134,    29,    47,   -92,   134,   -92,   -30,   -92,    18,   -92,
      45,    52,   -92,    17,    30,   -92,   -92,   -92,    34,    34,
      34,    34,    34,    34,    34,   -48,   -48,   -48,    34,    34,
      34,   -92,   -92,   -92,   211,   -27,   -92,    59,    63,   -92,
     -92,   -92,    56,    68,   -92,     5,   -92,   -92,    37,   109,
     -92,   -92,    97,   -92,    37,   -92,   -92,   -92,   -92,   -92,
     -92,    11,    28,   134,   -92,   -92,    37,    37,   -92,   115,
      37,   243,   -92,   -92,   -92,   -92,   134,   -92,   -92,    -6,
      82,    85,    37,   -92,   -92,   275,   307,   129,   130,   -92,
     134,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   339,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       6,     0,     2,     1,    18,    31,    32,    33,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,     5,     3,
      13,    29,    34,     0,    25,    26,    27,     0,    37,    35,
      36,    14,     4,    80,    82,    83,    84,    79,    78,    77,
      92,    93,     0,    48,    37,    50,    53,    57,    68,     0,
       0,     0,     0,    85,     0,     0,     0,    88,    87,    41,
       0,     0,    28,     0,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    11,     0,
       0,     0,     0,    86,     0,    97,     0,    39,     0,    44,
       0,     0,    45,    46,    47,    49,    51,    52,    59,    61,
      65,    66,    67,    64,    63,    54,    55,    56,    58,    60,
      62,    70,    69,    71,     0,     0,     9,     0,     0,    19,
      20,    21,     0,     0,    22,     0,    23,    24,     0,     0,
      97,    72,     0,    38,     0,    42,    91,    43,    94,    95,
      96,     0,     0,     0,    15,    75,     0,     0,    17,     0,
       0,     0,    89,    97,    40,    97,     0,    10,    12,     0,
       0,     0,     0,    99,    98,     0,     0,     0,     0,    74,
       0,    16,   100,    90,     7,    97,    73,    76,     0,     8
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -92,   -92,   -92,   -92,   -92,    -3,   136,   -28,    -1,   -84,
     -92,   -92,   -92,   -92,   -92,    -2,     0,   -92,    76,   -92,
     -41,    19,   331,    31,   -12,   -92,   -92,   -92,   -92,   148,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -91,   -92,
     -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    18,   125,   126,   149,    20,    21,   135,
      22,    23,    24,    25,    26,    43,    44,    96,    29,    30,
      45,    46,    47,    48,    49,    31,   136,   169,   137,   150,
      33,    34,    35,    36,    37,    38,    39,    40,   124,    41,
      92
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      27,    54,    28,    56,   142,    10,    69,    70,    50,    51,
     141,    52,   157,    55,    65,    89,    66,   143,   165,   144,
     151,    62,   152,     3,     4,     5,     6,     7,   106,   107,
      68,     4,     4,     5,     6,     7,    57,    58,    11,    64,
       4,     5,     6,     7,    67,    87,    11,    97,   138,   161,
      88,   100,    63,    93,    11,   158,    90,   178,    98,   166,
      99,    94,    91,   101,    95,   102,   103,    42,    60,   168,
     145,    53,   175,    59,   176,    42,   140,   128,    60,   139,
      61,    65,   177,    42,    84,    85,    86,   127,   105,   134,
      78,    79,    80,   134,   188,   146,   187,   115,   116,   117,
       4,     5,     6,     7,   147,     8,   162,   153,    10,     4,
       5,     6,     7,   154,    11,   121,   122,   123,   155,   156,
      12,    13,    27,    11,    28,    14,   159,   160,    15,   163,
      16,    17,   164,   172,   180,   181,   185,     4,    19,   186,
      27,   179,    28,   104,   170,   171,   129,   130,   173,   167,
      32,   127,   134,     0,   131,   132,   133,     0,     0,    27,
     182,    28,     0,     0,     0,   134,     0,     0,     0,     0,
       0,     0,     0,    27,    27,    28,    28,     0,     0,   134,
       0,     0,     4,     5,     6,     7,    27,     8,    28,     9,
      10,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,    14,     0,     0,
      15,     0,    16,    17,     4,     5,     6,     7,     0,     8,
     148,     0,    10,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,     0,    12,    13,     0,     0,     0,    14,
       0,     0,    15,     0,    16,    17,     4,     5,     6,     7,
       0,     8,   174,     0,    10,     0,     0,     0,     0,     0,
      11,     0,     0,     0,     0,     0,    12,    13,     0,     0,
       0,    14,     0,     0,    15,     0,    16,    17,     4,     5,
       6,     7,     0,     8,   183,     0,    10,     0,     0,     0,
       0,     0,    11,     0,     0,     0,     0,     0,    12,    13,
       0,     0,     0,    14,     0,     0,    15,     0,    16,    17,
       4,     5,     6,     7,     0,     8,   184,     0,    10,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      12,    13,     0,     0,     0,    14,     0,     0,    15,     0,
      16,    17,     4,     5,     6,     7,     0,     8,   189,     0,
      10,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,    12,    13,     0,     0,     0,    14,     0,     0,
      15,     0,    16,    17,     0,    71,    72,     0,     0,     0,
      73,    74,    75,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,    79,    80,    81,
      82,    83,   108,   109,   110,   111,   112,   113,   114,     0,
       0,     0,   118,   119,   120
};

static const yytype_int16 yycheck[] =
{
       2,    13,     2,    15,    95,    11,    54,    55,     9,    10,
      94,    12,     7,    14,    51,     7,    53,    47,     7,    49,
      47,    23,    49,     0,     3,     4,     5,     6,    69,    70,
      42,     3,     3,     4,     5,     6,    50,    50,    17,    50,
       3,     4,     5,     6,    53,    29,    17,    59,    19,   140,
      46,    63,    45,    50,    17,    50,    48,    63,    60,    48,
      61,     7,    30,    65,    25,    66,    67,    46,    51,   153,
      52,    50,   163,    46,   165,    46,    29,    89,    51,    91,
      53,    51,   166,    46,    14,    15,    16,    88,    47,    90,
      56,    57,    58,    94,   185,    50,   180,    78,    79,    80,
       3,     4,     5,     6,    52,     8,     9,    48,    11,     3,
       4,     5,     6,    50,    17,    84,    85,    86,    62,    51,
      23,    24,   124,    17,   124,    28,   138,    18,    31,    32,
      33,    34,   144,    18,    52,    50,     7,     3,     2,     9,
     142,   169,   142,    67,   156,   157,    12,    13,   160,   152,
       2,   152,   153,    -1,    20,    21,    22,    -1,    -1,   161,
     172,   161,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   175,   176,   175,   176,    -1,    -1,   180,
      -1,    -1,     3,     4,     5,     6,   188,     8,   188,    10,
      11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,
      31,    -1,    33,    34,     3,     4,     5,     6,    -1,     8,
       9,    -1,    11,    -1,    -1,    -1,    -1,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28,
      -1,    -1,    31,    -1,    33,    34,     3,     4,     5,     6,
      -1,     8,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,    -1,
      -1,    28,    -1,    -1,    31,    -1,    33,    34,     3,     4,
       5,     6,    -1,     8,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    28,    -1,    -1,    31,    -1,    33,    34,
       3,     4,     5,     6,    -1,     8,     9,    -1,    11,    -1,
      -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    28,    -1,    -1,    31,    -1,
      33,    34,     3,     4,     5,     6,    -1,     8,     9,    -1,
      11,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    28,    -1,    -1,
      31,    -1,    33,    34,    -1,    35,    36,    -1,    -1,    -1,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,
      60,    61,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    81,    82,    83
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    65,    66,     0,     3,     4,     5,     6,     8,    10,
      11,    17,    23,    24,    28,    31,    33,    34,    67,    70,
      71,    72,    74,    75,    76,    77,    78,    79,    80,    82,
      83,    89,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   103,    46,    79,    80,    84,    85,    86,    87,    88,
      72,    72,    72,    50,    88,    72,    88,    50,    50,    46,
      51,    53,    79,    45,    50,    51,    53,    53,    88,    54,
      55,    35,    36,    40,    41,    42,    43,    44,    56,    57,
      58,    59,    60,    61,    14,    15,    16,    29,    46,     7,
      48,    30,   104,    50,     7,    25,    81,    88,    79,    72,
      88,    79,    72,    72,    82,    47,    84,    84,    86,    86,
      86,    86,    86,    86,    86,    85,    85,    85,    86,    86,
      86,    87,    87,    87,   102,    68,    69,    72,    88,    12,
      13,    20,    21,    22,    72,    73,    90,    92,    19,    88,
      29,    73,   102,    47,    49,    52,    50,    52,     9,    70,
      93,    47,    49,    48,    50,    62,    51,     7,    50,    88,
      18,   102,     9,    32,    88,     7,    48,    69,    73,    91,
      88,    88,    18,    88,     9,   102,   102,    73,    63,    71,
      52,    50,    88,     9,     9,     7,     9,    73,   102,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    66,    66,    67,    67,    68,
      68,    68,    69,    70,    70,    71,    71,    71,    72,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      75,    76,    77,    78,    79,    79,    79,    79,    80,    81,
      81,    81,    82,    82,    83,    83,    83,    83,    84,    84,
      85,    85,    85,    86,    86,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    88,    88,
      88,    88,    89,    90,    91,    91,    92,    93,    93,    93,
      93,    93,    94,    94,    94,    95,    95,    96,    97,    98,
      98,    99,   100,   100,   101,   102,   102,   102,   103,   104,
     104
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     0,     8,    10,     1,
       3,     0,     3,     1,     1,     5,     7,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     0,     4,     4,     3,     3,     3,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     4,     5,     2,     0,     5,     1,     1,     1,
       1,     2,     1,     1,     1,     2,     3,     2,     2,     5,
       7,     4,     1,     1,     5,     2,     2,     0,     6,     4,
       5
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
#line 45 "grammar.y"
                 { 
      (yyval.node) = new None_Terminal_Node("PROGRAM"); 
      (yyval.node)->children.push_back((yyvsp[0].node)); 
      print_ast((yyval.node), 0);
    }
#line 1363 "grammar.tab.c"
    break;

  case 3: /* declarations: declarations simpleDeclaration  */
#line 53 "grammar.y"
                                   {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1372 "grammar.tab.c"
    break;

  case 4: /* declarations: declarations statement  */
#line 57 "grammar.y"
                           {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1381 "grammar.tab.c"
    break;

  case 5: /* declarations: declarations routine_deceration  */
#line 61 "grammar.y"
                                    {
       (yyval.node) = (yyvsp[-1].node);
       (yyval.node)->children.push_back((yyvsp[0].node));
     }
#line 1390 "grammar.tab.c"
    break;

  case 6: /* declarations: %empty  */
#line 66 "grammar.y"
                {
      (yyval.node) = new None_Terminal_Node("DECLARATION"); 
    }
#line 1398 "grammar.tab.c"
    break;

  case 7: /* routine_deceration: ROUTINE identifier '(' parameters_list ')' IS body END  */
#line 72 "grammar.y"
                                                           {
      (yyval.node) = new None_Terminal_Node("ROUTINE_DECLERATION");
      (yyval.node)->children.push_back((yyvsp[-6].node));
      (yyval.node)->children.push_back((yyvsp[-4].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 1409 "grammar.tab.c"
    break;

  case 8: /* routine_deceration: ROUTINE identifier '(' parameters_list ')' ':' type IS body END  */
#line 78 "grammar.y"
                                                                    {
      (yyval.node) = new None_Terminal_Node("ROUTINE_DECLERATION");
      (yyval.node)->children.push_back((yyvsp[-8].node));
      (yyval.node)->children.push_back((yyvsp[-6].node));
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 1421 "grammar.tab.c"
    break;

  case 9: /* parameters_list: parameter_decleration  */
#line 87 "grammar.y"
                          {
      (yyval.node) = new None_Terminal_Node("PARAMETERS_EXPRESSION_LIST");
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1430 "grammar.tab.c"
    break;

  case 10: /* parameters_list: parameters_list ',' parameter_decleration  */
#line 91 "grammar.y"
                                             {
      (yyval.node) = (yyvsp[-2].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1439 "grammar.tab.c"
    break;

  case 11: /* parameters_list: %empty  */
#line 95 "grammar.y"
                {
      (yyval.node) = new None_Terminal_Node("PARAMETERS_EXPRESSION_LIST");
    }
#line 1447 "grammar.tab.c"
    break;

  case 12: /* parameter_decleration: identifier ':' type  */
#line 100 "grammar.y"
                           { 
      (yyval.node) = new None_Terminal_Node("PARAMETER_DECLERATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1457 "grammar.tab.c"
    break;

  case 13: /* simpleDeclaration: variableDeclaration  */
#line 107 "grammar.y"
                        { 
      (yyval.node) = new None_Terminal_Node("SIMPLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1466 "grammar.tab.c"
    break;

  case 14: /* simpleDeclaration: typeDecleration  */
#line 111 "grammar.y"
                   {
      (yyval.node) = new None_Terminal_Node("SIMPLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1475 "grammar.tab.c"
    break;

  case 15: /* variableDeclaration: VAR identifier IS expression ';'  */
#line 118 "grammar.y"
                                     { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back(new Type_Node("none"));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1486 "grammar.tab.c"
    break;

  case 16: /* variableDeclaration: VAR identifier ':' type IS expression ';'  */
#line 124 "grammar.y"
                                              { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[-5].node));
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1497 "grammar.tab.c"
    break;

  case 17: /* variableDeclaration: VAR identifier ':' type ';'  */
#line 130 "grammar.y"
                               { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1507 "grammar.tab.c"
    break;

  case 18: /* identifier: IDENTIFIER  */
#line 137 "grammar.y"
           {
  (yyval.node) = new Identifier_Node(std::string((yyvsp[0].id_val)));
 }
#line 1515 "grammar.tab.c"
    break;

  case 19: /* type: INTEGER_LITERAL_KEYWORD  */
#line 142 "grammar.y"
                            {
    (yyval.node) = new Type_Node("integer");
  }
#line 1523 "grammar.tab.c"
    break;

  case 20: /* type: REAL_LITERAL_KEYWORD  */
#line 145 "grammar.y"
                         { 
    (yyval.node) = new Type_Node("real");
  }
#line 1531 "grammar.tab.c"
    break;

  case 21: /* type: BOOLEAN_LITERAL_KEYWORD  */
#line 148 "grammar.y"
                            {
    (yyval.node) = new Type_Node("boolean");
  }
#line 1539 "grammar.tab.c"
    break;

  case 22: /* type: identifier  */
#line 151 "grammar.y"
               {
      (yyval.node) = new Type_Node("identifier");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1548 "grammar.tab.c"
    break;

  case 23: /* type: recordType  */
#line 155 "grammar.y"
              {
      (yyval.node) = new Type_Node("recordType");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1557 "grammar.tab.c"
    break;

  case 24: /* type: arrayType  */
#line 159 "grammar.y"
             {
      (yyval.node) = new Type_Node("arrayType");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1566 "grammar.tab.c"
    break;

  case 25: /* primary_expression: int_exp  */
#line 167 "grammar.y"
                 {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1575 "grammar.tab.c"
    break;

  case 26: /* primary_expression: real_exp  */
#line 171 "grammar.y"
            {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1584 "grammar.tab.c"
    break;

  case 27: /* primary_expression: boolean_exp  */
#line 175 "grammar.y"
               {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1593 "grammar.tab.c"
    break;

  case 28: /* primary_expression: unary_op primary  */
#line 179 "grammar.y"
                    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1603 "grammar.tab.c"
    break;

  case 29: /* primary_expression: identifier  */
#line 184 "grammar.y"
                    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1612 "grammar.tab.c"
    break;

  case 30: /* unary_op: NOT  */
#line 190 "grammar.y"
      {
    (yyval.node) = new Operator("!");
   }
#line 1620 "grammar.tab.c"
    break;

  case 31: /* int_exp: INTEGER_LITERAL  */
#line 195 "grammar.y"
                   {
    (yyval.node) = new Integer_Node((yyvsp[0].int_val));
  }
#line 1628 "grammar.tab.c"
    break;

  case 32: /* real_exp: REAL_LITERAL  */
#line 200 "grammar.y"
                 {
    (yyval.node) = new Real_Node((yyvsp[0].real_val));
  }
#line 1636 "grammar.tab.c"
    break;

  case 33: /* boolean_exp: BOOLEAN_LITERAL  */
#line 205 "grammar.y"
                    {
    (yyval.node) = new Boolean_Node((yyvsp[0].bool_val));
  }
#line 1644 "grammar.tab.c"
    break;

  case 34: /* primary: primary_expression  */
#line 211 "grammar.y"
                            {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1653 "grammar.tab.c"
    break;

  case 35: /* primary: array_access_expression  */
#line 215 "grammar.y"
                           {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1662 "grammar.tab.c"
    break;

  case 36: /* primary: record_expession_access  */
#line 219 "grammar.y"
                           {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1671 "grammar.tab.c"
    break;

  case 37: /* primary: routine_call  */
#line 223 "grammar.y"
                {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1680 "grammar.tab.c"
    break;

  case 38: /* routine_call: identifier '(' argument_expression_list ')'  */
#line 230 "grammar.y"
                                                {
      (yyval.node) = new None_Terminal_Node("Routine_Call");
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1690 "grammar.tab.c"
    break;

  case 39: /* argument_expression_list: expression  */
#line 238 "grammar.y"
               {
      (yyval.node) = new None_Terminal_Node("Argument_Expression_List");
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1699 "grammar.tab.c"
    break;

  case 40: /* argument_expression_list: argument_expression_list ',' expression  */
#line 242 "grammar.y"
                                            {
      (yyval.node) = (yyvsp[-2].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1708 "grammar.tab.c"
    break;

  case 41: /* argument_expression_list: %empty  */
#line 246 "grammar.y"
                {
      (yyval.node) = new None_Terminal_Node("Argument_Expression_List");
    }
#line 1716 "grammar.tab.c"
    break;

  case 42: /* array_access_expression: identifier '[' primary ']'  */
#line 251 "grammar.y"
                               {
    (yyval.node) = new None_Terminal_Node("ARRAY_ACCESS");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));

  }
#line 1727 "grammar.tab.c"
    break;

  case 43: /* array_access_expression: array_access_expression '[' primary ']'  */
#line 257 "grammar.y"
                                            {
    (yyval.node) = new None_Terminal_Node("ARRAY_ACCESS");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 1737 "grammar.tab.c"
    break;

  case 44: /* record_expession_access: identifier '.' identifier  */
#line 264 "grammar.y"
                               {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1747 "grammar.tab.c"
    break;

  case 45: /* record_expession_access: array_access_expression '.' identifier  */
#line 269 "grammar.y"
                                            {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1757 "grammar.tab.c"
    break;

  case 46: /* record_expession_access: record_expession_access '.' identifier  */
#line 274 "grammar.y"
                                             {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1767 "grammar.tab.c"
    break;

  case 47: /* record_expession_access: record_expession_access '.' array_access_expression  */
#line 279 "grammar.y"
                                                         {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1777 "grammar.tab.c"
    break;

  case 48: /* summand: primary  */
#line 287 "grammar.y"
            {
      (yyval.node) = new None_Terminal_Node("SUMMAND");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1786 "grammar.tab.c"
    break;

  case 49: /* summand: '(' expression ')'  */
#line 291 "grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("SUMMAND");
      (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 1795 "grammar.tab.c"
    break;

  case 50: /* factor: summand  */
#line 299 "grammar.y"
            {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1804 "grammar.tab.c"
    break;

  case 51: /* factor: factor '+' summand  */
#line 303 "grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("+"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1815 "grammar.tab.c"
    break;

  case 52: /* factor: factor '-' summand  */
#line 309 "grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("-"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1826 "grammar.tab.c"
    break;

  case 53: /* simple: factor  */
#line 318 "grammar.y"
           {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1835 "grammar.tab.c"
    break;

  case 54: /* simple: simple '*' factor  */
#line 322 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("*"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1846 "grammar.tab.c"
    break;

  case 55: /* simple: simple '/' factor  */
#line 328 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("/"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1857 "grammar.tab.c"
    break;

  case 56: /* simple: simple '%' factor  */
#line 334 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("%"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1868 "grammar.tab.c"
    break;

  case 57: /* relation: simple  */
#line 343 "grammar.y"
           {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1877 "grammar.tab.c"
    break;

  case 58: /* relation: simple '<' simple  */
#line 347 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("<"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1888 "grammar.tab.c"
    break;

  case 59: /* relation: simple LE_OP simple  */
#line 353 "grammar.y"
                        {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("<="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1899 "grammar.tab.c"
    break;

  case 60: /* relation: simple '>' simple  */
#line 359 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator(">"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1910 "grammar.tab.c"
    break;

  case 61: /* relation: simple GE_OP simple  */
#line 365 "grammar.y"
                        {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator(">="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1921 "grammar.tab.c"
    break;

  case 62: /* relation: simple '=' simple  */
#line 371 "grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1932 "grammar.tab.c"
    break;

  case 63: /* relation: simple SUB_ASSIGN simple  */
#line 377 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("-="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1943 "grammar.tab.c"
    break;

  case 64: /* relation: simple ADD_ASSIGN simple  */
#line 383 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("+="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1954 "grammar.tab.c"
    break;

  case 65: /* relation: simple MUL_ASSIGN simple  */
#line 389 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("*="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1965 "grammar.tab.c"
    break;

  case 66: /* relation: simple DIV_ASSIGN simple  */
#line 395 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("/="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1976 "grammar.tab.c"
    break;

  case 67: /* relation: simple MOD_ASSIGN simple  */
#line 401 "grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("%="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1987 "grammar.tab.c"
    break;

  case 68: /* expression: relation  */
#line 411 "grammar.y"
              {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1996 "grammar.tab.c"
    break;

  case 69: /* expression: relation AND relation  */
#line 415 "grammar.y"
                          {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("and"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2007 "grammar.tab.c"
    break;

  case 70: /* expression: relation OR relation  */
#line 421 "grammar.y"
                         {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("or"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2018 "grammar.tab.c"
    break;

  case 71: /* expression: relation XOR relation  */
#line 427 "grammar.y"
                          {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("xor"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2029 "grammar.tab.c"
    break;

  case 72: /* typeDecleration: TYPE identifier IS type  */
#line 437 "grammar.y"
                             {
    (yyval.node) = new None_Terminal_Node("TYPE_DECLARATION");
    (yyval.node)->children.push_back((yyvsp[-2].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2039 "grammar.tab.c"
    break;

  case 73: /* recordType: RECORD '{' variableDeclerations '}' END  */
#line 445 "grammar.y"
                                             {
      (yyval.node) = new None_Terminal_Node("RECORD_TYPE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
   }
#line 2048 "grammar.tab.c"
    break;

  case 74: /* variableDeclerations: variableDeclerations variableDeclaration  */
#line 452 "grammar.y"
                                             {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 2057 "grammar.tab.c"
    break;

  case 75: /* variableDeclerations: %empty  */
#line 456 "grammar.y"
                  {
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATIONS");
    }
#line 2065 "grammar.tab.c"
    break;

  case 76: /* arrayType: ARRAY '[' expression ']' type  */
#line 462 "grammar.y"
                                   {
      (yyval.node) = new None_Terminal_Node("ARRAY_TYPE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2075 "grammar.tab.c"
    break;

  case 77: /* statement: iteration_statement  */
#line 470 "grammar.y"
                      {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2084 "grammar.tab.c"
    break;

  case 78: /* statement: assign_expression  */
#line 474 "grammar.y"
                      {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2093 "grammar.tab.c"
    break;

  case 79: /* statement: IfStatement  */
#line 478 "grammar.y"
                {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2102 "grammar.tab.c"
    break;

  case 80: /* statement: jumpStatement  */
#line 482 "grammar.y"
                  {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2111 "grammar.tab.c"
    break;

  case 81: /* statement: routine_call ';'  */
#line 486 "grammar.y"
                      {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 2120 "grammar.tab.c"
    break;

  case 82: /* jumpStatement: return_exp  */
#line 492 "grammar.y"
               {
    (yyval.node) = new None_Terminal_Node("JUMP_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2129 "grammar.tab.c"
    break;

  case 83: /* jumpStatement: continue_exp  */
#line 496 "grammar.y"
                 {
    (yyval.node) = new None_Terminal_Node("JUMP_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2138 "grammar.tab.c"
    break;

  case 84: /* jumpStatement: break_exp  */
#line 500 "grammar.y"
              {
    (yyval.node) = new None_Terminal_Node("JUMP_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2147 "grammar.tab.c"
    break;

  case 85: /* return_exp: RETURN ';'  */
#line 506 "grammar.y"
             {
   (yyval.node) = new None_Terminal_Node("RETURN_EX");
 }
#line 2155 "grammar.tab.c"
    break;

  case 86: /* return_exp: RETURN expression ';'  */
#line 509 "grammar.y"
                         {
     (yyval.node) = new None_Terminal_Node("RETURN_EX");
     (yyval.node)->children.push_back((yyvsp[-1].node));
 }
#line 2164 "grammar.tab.c"
    break;

  case 87: /* continue_exp: CONTINUE ';'  */
#line 515 "grammar.y"
               {
     (yyval.node) = new None_Terminal_Node("CONTINUE_EX");
 }
#line 2172 "grammar.tab.c"
    break;

  case 88: /* break_exp: BREAK ';'  */
#line 520 "grammar.y"
            {
     (yyval.node) = new None_Terminal_Node("BREAK_EX");
 }
#line 2180 "grammar.tab.c"
    break;

  case 89: /* IfStatement: IF expression THEN body END  */
#line 526 "grammar.y"
                                {
    (yyval.node) = new None_Terminal_Node("IF_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2190 "grammar.tab.c"
    break;

  case 90: /* IfStatement: IF expression THEN body ELSE body END  */
#line 531 "grammar.y"
                                          {
    (yyval.node) = new None_Terminal_Node("IF_STATEMENT_ELSE");
    (yyval.node)->children.push_back((yyvsp[-5].node));
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2201 "grammar.tab.c"
    break;

  case 91: /* assign_expression: primary ASSIGN_OP expression ';'  */
#line 539 "grammar.y"
                                    {
    (yyval.node) = new None_Terminal_Node("ASSIGN_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2211 "grammar.tab.c"
    break;

  case 92: /* iteration_statement: while_expression  */
#line 546 "grammar.y"
                          {
    (yyval.node) = new None_Terminal_Node("ITERATION_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2220 "grammar.tab.c"
    break;

  case 93: /* iteration_statement: for_expression  */
#line 550 "grammar.y"
                  {
    (yyval.node) = new None_Terminal_Node("ITERATION_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2229 "grammar.tab.c"
    break;

  case 94: /* while_expression: WHILE expression LOOP body END  */
#line 556 "grammar.y"
                                 {
    (yyval.node) = new None_Terminal_Node("WHILE_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 2239 "grammar.tab.c"
    break;

  case 95: /* body: body simpleDeclaration  */
#line 563 "grammar.y"
                           {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 2248 "grammar.tab.c"
    break;

  case 96: /* body: body statement  */
#line 567 "grammar.y"
                   {
       (yyval.node) = (yyvsp[-1].node);
       (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 2257 "grammar.tab.c"
    break;

  case 97: /* body: %empty  */
#line 571 "grammar.y"
                {
      (yyval.node) = new None_Terminal_Node("BODY"); 
    }
#line 2265 "grammar.tab.c"
    break;

  case 98: /* for_expression: FOR identifier range LOOP body END  */
#line 577 "grammar.y"
                                     {
      (yyval.node) = new None_Terminal_Node("FOR_STATEMENT");
      (yyval.node)->children.push_back((yyvsp[-4].node));
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 2276 "grammar.tab.c"
    break;

  case 99: /* range: IN expression RANGE expression  */
#line 585 "grammar.y"
                                  {
     (yyval.node) = new None_Terminal_Node("RANGE_EX");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2286 "grammar.tab.c"
    break;

  case 100: /* range: IN REVERSE expression RANGE expression  */
#line 590 "grammar.y"
                                           {
     (yyval.node) = new None_Terminal_Node("RANGE_REVERSE");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2296 "grammar.tab.c"
    break;


#line 2300 "grammar.tab.c"

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

#line 597 "grammar.y"


void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}
