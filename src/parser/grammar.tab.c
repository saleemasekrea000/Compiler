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
#line 1 "./parser/grammar.y"

#include <stdio.h>
#include <stdlib.h>
#include "parser.hpp"
#include "ast.hpp"
#include "../semantic/semantic.hpp"
#include "../codegen/codegen.hpp"
 
int yylex();
void yyerror(char *s);
int counter = 1;
int indent = 0;
AST_Node* root;
void print_indent() {
  for(int i = 0; i < indent; i++) printf("  ");
}

#line 89 "./parser/grammar.tab.c"

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
  YYSYMBOL_PRINT = 35,                     /* PRINT  */
  YYSYMBOL_LE_OP = 36,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 37,                     /* GE_OP  */
  YYSYMBOL_NE_OP = 38,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 39,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 40,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 41,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 42,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 43,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 44,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 45,                /* SUB_ASSIGN  */
  YYSYMBOL_ASSIGN_OP = 46,                 /* ASSIGN_OP  */
  YYSYMBOL_47_ = 47,                       /* '('  */
  YYSYMBOL_48_ = 48,                       /* ')'  */
  YYSYMBOL_49_ = 49,                       /* ':'  */
  YYSYMBOL_50_ = 50,                       /* ','  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '.'  */
  YYSYMBOL_53_ = 53,                       /* '*'  */
  YYSYMBOL_54_ = 54,                       /* '/'  */
  YYSYMBOL_55_ = 55,                       /* '%'  */
  YYSYMBOL_56_ = 56,                       /* '+'  */
  YYSYMBOL_57_ = 57,                       /* '-'  */
  YYSYMBOL_58_ = 58,                       /* '<'  */
  YYSYMBOL_59_ = 59,                       /* '>'  */
  YYSYMBOL_60_ = 60,                       /* '='  */
  YYSYMBOL_61_ = 61,                       /* '{'  */
  YYSYMBOL_62_ = 62,                       /* '}'  */
  YYSYMBOL_63_ = 63,                       /* '['  */
  YYSYMBOL_64_ = 64,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_declarations = 67,              /* declarations  */
  YYSYMBOL_routine_deceration = 68,        /* routine_deceration  */
  YYSYMBOL_parameters_list = 69,           /* parameters_list  */
  YYSYMBOL_parameter_decleration = 70,     /* parameter_decleration  */
  YYSYMBOL_simpleDeclaration = 71,         /* simpleDeclaration  */
  YYSYMBOL_variableDeclaration = 72,       /* variableDeclaration  */
  YYSYMBOL_identifier = 73,                /* identifier  */
  YYSYMBOL_type = 74,                      /* type  */
  YYSYMBOL_primary_expression = 75,        /* primary_expression  */
  YYSYMBOL_unary_op = 76,                  /* unary_op  */
  YYSYMBOL_int_exp = 77,                   /* int_exp  */
  YYSYMBOL_real_exp = 78,                  /* real_exp  */
  YYSYMBOL_boolean_exp = 79,               /* boolean_exp  */
  YYSYMBOL_primary = 80,                   /* primary  */
  YYSYMBOL_routine_call = 81,              /* routine_call  */
  YYSYMBOL_argument_expression_list = 82,  /* argument_expression_list  */
  YYSYMBOL_record_expession_access = 83,   /* record_expession_access  */
  YYSYMBOL_summand = 84,                   /* summand  */
  YYSYMBOL_factor = 85,                    /* factor  */
  YYSYMBOL_simple = 86,                    /* simple  */
  YYSYMBOL_relation = 87,                  /* relation  */
  YYSYMBOL_expression = 88,                /* expression  */
  YYSYMBOL_typeDecleration = 89,           /* typeDecleration  */
  YYSYMBOL_recordType = 90,                /* recordType  */
  YYSYMBOL_variableDeclerations = 91,      /* variableDeclerations  */
  YYSYMBOL_array_access_expression = 92,   /* array_access_expression  */
  YYSYMBOL_arrayType = 93,                 /* arrayType  */
  YYSYMBOL_dimensionList = 94,             /* dimensionList  */
  YYSYMBOL_statement = 95,                 /* statement  */
  YYSYMBOL_print_statement = 96,           /* print_statement  */
  YYSYMBOL_jumpStatement = 97,             /* jumpStatement  */
  YYSYMBOL_return_exp = 98,                /* return_exp  */
  YYSYMBOL_continue_exp = 99,              /* continue_exp  */
  YYSYMBOL_break_exp = 100,                /* break_exp  */
  YYSYMBOL_IfStatement = 101,              /* IfStatement  */
  YYSYMBOL_assign_expression = 102,        /* assign_expression  */
  YYSYMBOL_iteration_statement = 103,      /* iteration_statement  */
  YYSYMBOL_while_expression = 104,         /* while_expression  */
  YYSYMBOL_body = 105,                     /* body  */
  YYSYMBOL_for_expression = 106,           /* for_expression  */
  YYSYMBOL_range = 107                     /* range  */
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
#define YYLAST   455

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    61,    65,    69,    74,    80,    86,    95,
      99,   103,   108,   115,   119,   126,   132,   138,   145,   150,
     153,   156,   159,   163,   167,   175,   179,   183,   187,   192,
     198,   203,   208,   213,   219,   223,   227,   231,   238,   246,
     250,   254,   260,   265,   270,   275,   288,   292,   300,   304,
     310,   316,   325,   329,   335,   344,   348,   354,   360,   366,
     372,   378,   384,   390,   396,   402,   412,   416,   422,   428,
     438,   446,   453,   457,   463,   471,   479,   483,   491,   495,
     499,   503,   507,   511,   517,   523,   527,   531,   537,   540,
     546,   551,   557,   562,   571,   577,   582,   587,   592,   597,
     605,   609,   615,   622,   626,   630,   636,   644,   649
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
  "PRINT", "LE_OP", "GE_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "ASSIGN_OP",
  "'('", "')'", "':'", "','", "';'", "'.'", "'*'", "'/'", "'%'", "'+'",
  "'-'", "'<'", "'>'", "'='", "'{'", "'}'", "'['", "']'", "$accept",
  "program", "declarations", "routine_deceration", "parameters_list",
  "parameter_decleration", "simpleDeclaration", "variableDeclaration",
  "identifier", "type", "primary_expression", "unary_op", "int_exp",
  "real_exp", "boolean_exp", "primary", "routine_call",
  "argument_expression_list", "record_expession_access", "summand",
  "factor", "simple", "relation", "expression", "typeDecleration",
  "recordType", "variableDeclerations", "array_access_expression",
  "arrayType", "dimensionList", "statement", "print_statement",
  "jumpStatement", "return_exp", "continue_exp", "break_exp",
  "IfStatement", "assign_expression", "iteration_statement",
  "while_expression", "body", "for_expression", "range", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-104)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
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

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,  -104,  -104,     5,   169,   -19,    -2,  -100,
    -104,  -104,  -104,  -104,  -104,     0,     2,  -104,   -24,    20,
     -34,   363,     9,    -4,  -104,  -104,  -104,   -23,  -104,    31,
     180,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
    -103,  -104,  -104
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    19,   141,   142,   171,    21,    45,   151,
      23,    24,    25,    26,    27,    46,    47,   111,    30,    48,
      49,    50,    51,    52,    31,   152,   193,    32,   153,    71,
     172,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     140,    43,   101
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
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

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
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

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
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
#line 49 "./parser/grammar.y"
                 { 
      (yyval.node) = new None_Terminal_Node("PROGRAM"); 
      (yyval.node)->children.push_back((yyvsp[0].node)); 
      print_ast((yyval.node), 0,"output.txt");
      root = (yyval.node);

      Codegen codegen_llvm(root);
      codegen_llvm.start_llvm(root);
    }
#line 1392 "./parser/grammar.tab.c"
    break;

  case 3: /* declarations: declarations simpleDeclaration  */
#line 61 "./parser/grammar.y"
                                   {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1401 "./parser/grammar.tab.c"
    break;

  case 4: /* declarations: declarations statement  */
#line 65 "./parser/grammar.y"
                           {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1410 "./parser/grammar.tab.c"
    break;

  case 5: /* declarations: declarations routine_deceration  */
#line 69 "./parser/grammar.y"
                                    {
       (yyval.node) = (yyvsp[-1].node);
       (yyval.node)->children.push_back((yyvsp[0].node));
     }
#line 1419 "./parser/grammar.tab.c"
    break;

  case 6: /* declarations: %empty  */
#line 74 "./parser/grammar.y"
                {
      (yyval.node) = new None_Terminal_Node("DECLARATION"); 
    }
#line 1427 "./parser/grammar.tab.c"
    break;

  case 7: /* routine_deceration: ROUTINE identifier '(' parameters_list ')' IS body END  */
#line 80 "./parser/grammar.y"
                                                           {
      (yyval.node) = new None_Terminal_Node("ROUTINE_DECLERATION");
      (yyval.node)->children.push_back((yyvsp[-6].node));
      (yyval.node)->children.push_back((yyvsp[-4].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 1438 "./parser/grammar.tab.c"
    break;

  case 8: /* routine_deceration: ROUTINE identifier '(' parameters_list ')' ':' type IS body END  */
#line 86 "./parser/grammar.y"
                                                                    {
      (yyval.node) = new None_Terminal_Node("ROUTINE_DECLERATION");
      (yyval.node)->children.push_back((yyvsp[-8].node));
      (yyval.node)->children.push_back((yyvsp[-6].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
      (yyval.node)->children.push_back((yyvsp[-3].node));
   }
#line 1450 "./parser/grammar.tab.c"
    break;

  case 9: /* parameters_list: parameter_decleration  */
#line 95 "./parser/grammar.y"
                          {
      (yyval.node) = new None_Terminal_Node("PARAMETERS_EXPRESSION_LIST");
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1459 "./parser/grammar.tab.c"
    break;

  case 10: /* parameters_list: parameters_list ',' parameter_decleration  */
#line 99 "./parser/grammar.y"
                                             {
      (yyval.node) = (yyvsp[-2].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1468 "./parser/grammar.tab.c"
    break;

  case 11: /* parameters_list: %empty  */
#line 103 "./parser/grammar.y"
                {
      (yyval.node) = new None_Terminal_Node("PARAMETERS_EXPRESSION_LIST");
    }
#line 1476 "./parser/grammar.tab.c"
    break;

  case 12: /* parameter_decleration: identifier ':' type  */
#line 108 "./parser/grammar.y"
                           { 
      (yyval.node) = new None_Terminal_Node("PARAMETER_DECLERATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1486 "./parser/grammar.tab.c"
    break;

  case 13: /* simpleDeclaration: variableDeclaration  */
#line 115 "./parser/grammar.y"
                        { 
      (yyval.node) = new None_Terminal_Node("SIMPLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1495 "./parser/grammar.tab.c"
    break;

  case 14: /* simpleDeclaration: typeDecleration  */
#line 119 "./parser/grammar.y"
                   {
      (yyval.node) = new None_Terminal_Node("SIMPLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1504 "./parser/grammar.tab.c"
    break;

  case 15: /* variableDeclaration: VAR identifier IS expression ';'  */
#line 126 "./parser/grammar.y"
                                     { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back(new Type_Node("none"));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1515 "./parser/grammar.tab.c"
    break;

  case 16: /* variableDeclaration: VAR identifier ':' type IS expression ';'  */
#line 132 "./parser/grammar.y"
                                              { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[-5].node));
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1526 "./parser/grammar.tab.c"
    break;

  case 17: /* variableDeclaration: VAR identifier ':' type ';'  */
#line 138 "./parser/grammar.y"
                               { 
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATION");
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1536 "./parser/grammar.tab.c"
    break;

  case 18: /* identifier: IDENTIFIER  */
#line 145 "./parser/grammar.y"
           {
  (yyval.node) = new Identifier_Node(std::string((yyvsp[0].id_val)));
 }
#line 1544 "./parser/grammar.tab.c"
    break;

  case 19: /* type: INTEGER_LITERAL_KEYWORD  */
#line 150 "./parser/grammar.y"
                            {
    (yyval.node) = new Type_Node("integer");
  }
#line 1552 "./parser/grammar.tab.c"
    break;

  case 20: /* type: REAL_LITERAL_KEYWORD  */
#line 153 "./parser/grammar.y"
                         { 
    (yyval.node) = new Type_Node("real");
  }
#line 1560 "./parser/grammar.tab.c"
    break;

  case 21: /* type: BOOLEAN_LITERAL_KEYWORD  */
#line 156 "./parser/grammar.y"
                            {
    (yyval.node) = new Type_Node("boolean");
  }
#line 1568 "./parser/grammar.tab.c"
    break;

  case 22: /* type: identifier  */
#line 159 "./parser/grammar.y"
               {
      (yyval.node) = new Type_Node("identifier");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1577 "./parser/grammar.tab.c"
    break;

  case 23: /* type: recordType  */
#line 163 "./parser/grammar.y"
              {
      (yyval.node) = new Type_Node("recordType");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1586 "./parser/grammar.tab.c"
    break;

  case 24: /* type: arrayType  */
#line 167 "./parser/grammar.y"
             {
      (yyval.node) = new Type_Node("arrayType");
      (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1595 "./parser/grammar.tab.c"
    break;

  case 25: /* primary_expression: int_exp  */
#line 175 "./parser/grammar.y"
                 {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1604 "./parser/grammar.tab.c"
    break;

  case 26: /* primary_expression: real_exp  */
#line 179 "./parser/grammar.y"
            {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1613 "./parser/grammar.tab.c"
    break;

  case 27: /* primary_expression: boolean_exp  */
#line 183 "./parser/grammar.y"
               {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1622 "./parser/grammar.tab.c"
    break;

  case 28: /* primary_expression: unary_op primary  */
#line 187 "./parser/grammar.y"
                    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1632 "./parser/grammar.tab.c"
    break;

  case 29: /* primary_expression: identifier  */
#line 192 "./parser/grammar.y"
                    {
    (yyval.node) = new None_Terminal_Node("PRIMARY_EXPRESSION");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1641 "./parser/grammar.tab.c"
    break;

  case 30: /* unary_op: NOT  */
#line 198 "./parser/grammar.y"
      {
    (yyval.node) = new Operator("!");
   }
#line 1649 "./parser/grammar.tab.c"
    break;

  case 31: /* int_exp: INTEGER_LITERAL  */
#line 203 "./parser/grammar.y"
                   {
    (yyval.node) = new Integer_Node((yyvsp[0].int_val));
  }
#line 1657 "./parser/grammar.tab.c"
    break;

  case 32: /* real_exp: REAL_LITERAL  */
#line 208 "./parser/grammar.y"
                 {
    (yyval.node) = new Real_Node((yyvsp[0].real_val));
  }
#line 1665 "./parser/grammar.tab.c"
    break;

  case 33: /* boolean_exp: BOOLEAN_LITERAL  */
#line 213 "./parser/grammar.y"
                    {
    (yyval.node) = new Boolean_Node((yyvsp[0].bool_val));
  }
#line 1673 "./parser/grammar.tab.c"
    break;

  case 34: /* primary: primary_expression  */
#line 219 "./parser/grammar.y"
                            {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1682 "./parser/grammar.tab.c"
    break;

  case 35: /* primary: array_access_expression  */
#line 223 "./parser/grammar.y"
                           {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1691 "./parser/grammar.tab.c"
    break;

  case 36: /* primary: record_expession_access  */
#line 227 "./parser/grammar.y"
                           {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1700 "./parser/grammar.tab.c"
    break;

  case 37: /* primary: routine_call  */
#line 231 "./parser/grammar.y"
                {
    (yyval.node) = new None_Terminal_Node("PRIMARY_NODE");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 1709 "./parser/grammar.tab.c"
    break;

  case 38: /* routine_call: identifier '(' argument_expression_list ')'  */
#line 238 "./parser/grammar.y"
                                                {
      (yyval.node) = new None_Terminal_Node("Routine_Call");
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
    }
#line 1719 "./parser/grammar.tab.c"
    break;

  case 39: /* argument_expression_list: expression  */
#line 246 "./parser/grammar.y"
               {
      (yyval.node) = new None_Terminal_Node("Argument_Expression_List");
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1728 "./parser/grammar.tab.c"
    break;

  case 40: /* argument_expression_list: argument_expression_list ',' expression  */
#line 250 "./parser/grammar.y"
                                            {
      (yyval.node) = (yyvsp[-2].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 1737 "./parser/grammar.tab.c"
    break;

  case 41: /* argument_expression_list: %empty  */
#line 254 "./parser/grammar.y"
                {
      (yyval.node) = new None_Terminal_Node("Argument_Expression_List");
    }
#line 1745 "./parser/grammar.tab.c"
    break;

  case 42: /* record_expession_access: identifier '.' identifier  */
#line 260 "./parser/grammar.y"
                               {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1755 "./parser/grammar.tab.c"
    break;

  case 43: /* record_expession_access: array_access_expression '.' identifier  */
#line 265 "./parser/grammar.y"
                                             {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1765 "./parser/grammar.tab.c"
    break;

  case 44: /* record_expession_access: array_access_expression '.' record_expession_access  */
#line 270 "./parser/grammar.y"
                                                         {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1775 "./parser/grammar.tab.c"
    break;

  case 45: /* record_expession_access: identifier '.' record_expession_access  */
#line 275 "./parser/grammar.y"
                                             {
     (yyval.node) = new None_Terminal_Node("RECORD_ACCESS");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1785 "./parser/grammar.tab.c"
    break;

  case 46: /* summand: primary  */
#line 288 "./parser/grammar.y"
            {
      (yyval.node) = new None_Terminal_Node("SUMMAND");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1794 "./parser/grammar.tab.c"
    break;

  case 47: /* summand: '(' expression ')'  */
#line 292 "./parser/grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("SUMMAND");
      (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 1803 "./parser/grammar.tab.c"
    break;

  case 48: /* factor: summand  */
#line 300 "./parser/grammar.y"
            {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1812 "./parser/grammar.tab.c"
    break;

  case 49: /* factor: factor '*' summand  */
#line 304 "./parser/grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("*"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1823 "./parser/grammar.tab.c"
    break;

  case 50: /* factor: factor '/' summand  */
#line 310 "./parser/grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("/"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1834 "./parser/grammar.tab.c"
    break;

  case 51: /* factor: factor '%' summand  */
#line 316 "./parser/grammar.y"
                       {
      (yyval.node) = new None_Terminal_Node("FACTOR");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("%"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1845 "./parser/grammar.tab.c"
    break;

  case 52: /* simple: factor  */
#line 325 "./parser/grammar.y"
           {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1854 "./parser/grammar.tab.c"
    break;

  case 53: /* simple: simple '+' factor  */
#line 329 "./parser/grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("+"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1865 "./parser/grammar.tab.c"
    break;

  case 54: /* simple: simple '-' factor  */
#line 335 "./parser/grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("SIMPLE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("-"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1876 "./parser/grammar.tab.c"
    break;

  case 55: /* relation: simple  */
#line 344 "./parser/grammar.y"
           {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1885 "./parser/grammar.tab.c"
    break;

  case 56: /* relation: simple '<' simple  */
#line 348 "./parser/grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("<"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1896 "./parser/grammar.tab.c"
    break;

  case 57: /* relation: simple LE_OP simple  */
#line 354 "./parser/grammar.y"
                        {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("<="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1907 "./parser/grammar.tab.c"
    break;

  case 58: /* relation: simple '>' simple  */
#line 360 "./parser/grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator(">"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1918 "./parser/grammar.tab.c"
    break;

  case 59: /* relation: simple GE_OP simple  */
#line 366 "./parser/grammar.y"
                        {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator(">="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1929 "./parser/grammar.tab.c"
    break;

  case 60: /* relation: simple '=' simple  */
#line 372 "./parser/grammar.y"
                      {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1940 "./parser/grammar.tab.c"
    break;

  case 61: /* relation: simple SUB_ASSIGN simple  */
#line 378 "./parser/grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("-="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1951 "./parser/grammar.tab.c"
    break;

  case 62: /* relation: simple ADD_ASSIGN simple  */
#line 384 "./parser/grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("+="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1962 "./parser/grammar.tab.c"
    break;

  case 63: /* relation: simple MUL_ASSIGN simple  */
#line 390 "./parser/grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("*="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1973 "./parser/grammar.tab.c"
    break;

  case 64: /* relation: simple DIV_ASSIGN simple  */
#line 396 "./parser/grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("/="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1984 "./parser/grammar.tab.c"
    break;

  case 65: /* relation: simple MOD_ASSIGN simple  */
#line 402 "./parser/grammar.y"
                             {
      (yyval.node) = new None_Terminal_Node("RELATION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("%="));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 1995 "./parser/grammar.tab.c"
    break;

  case 66: /* expression: relation  */
#line 412 "./parser/grammar.y"
              {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2004 "./parser/grammar.tab.c"
    break;

  case 67: /* expression: relation AND relation  */
#line 416 "./parser/grammar.y"
                          {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("and"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2015 "./parser/grammar.tab.c"
    break;

  case 68: /* expression: relation OR relation  */
#line 422 "./parser/grammar.y"
                         {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("or"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2026 "./parser/grammar.tab.c"
    break;

  case 69: /* expression: relation XOR relation  */
#line 428 "./parser/grammar.y"
                          {
      (yyval.node) = new None_Terminal_Node("EXPRESSION");
      (yyval.node)->children.push_back((yyvsp[-2].node));
      (yyval.node)->children.push_back(new Operator("xor"));
      (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2037 "./parser/grammar.tab.c"
    break;

  case 70: /* typeDecleration: TYPE identifier IS type ';'  */
#line 438 "./parser/grammar.y"
                                 {
    (yyval.node) = new None_Terminal_Node("TYPE_DECLARATION");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 2047 "./parser/grammar.tab.c"
    break;

  case 71: /* recordType: RECORD '{' variableDeclerations '}' END  */
#line 446 "./parser/grammar.y"
                                             {
      (yyval.node) = new None_Terminal_Node("RECORD_TYPE");
      (yyval.node)->children.push_back((yyvsp[-2].node));
   }
#line 2056 "./parser/grammar.tab.c"
    break;

  case 72: /* variableDeclerations: variableDeclerations variableDeclaration  */
#line 453 "./parser/grammar.y"
                                             {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 2065 "./parser/grammar.tab.c"
    break;

  case 73: /* variableDeclerations: %empty  */
#line 457 "./parser/grammar.y"
                  {
      (yyval.node) = new None_Terminal_Node("VARIABLE_DECLARATIONS");
    }
#line 2073 "./parser/grammar.tab.c"
    break;

  case 74: /* array_access_expression: identifier dimensionList  */
#line 463 "./parser/grammar.y"
                             {
    (yyval.node) = new None_Terminal_Node("ARRAY_ACCESS");
    (yyval.node)->children.push_back((yyvsp[-1].node));
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2083 "./parser/grammar.tab.c"
    break;

  case 75: /* arrayType: ARRAY dimensionList type  */
#line 471 "./parser/grammar.y"
                               {
        (yyval.node) = new None_Terminal_Node("ARRAY_TYPE");
        (yyval.node)->children.push_back((yyvsp[-1].node)); 
        (yyval.node)->children.push_back((yyvsp[0].node)); 
    }
#line 2093 "./parser/grammar.tab.c"
    break;

  case 76: /* dimensionList: '[' expression ']'  */
#line 479 "./parser/grammar.y"
                         {
        (yyval.node) = new None_Terminal_Node("DIMENSION_LIST");
        (yyval.node)->children.push_back((yyvsp[-1].node)); 
    }
#line 2102 "./parser/grammar.tab.c"
    break;

  case 77: /* dimensionList: dimensionList '[' expression ']'  */
#line 483 "./parser/grammar.y"
                                       {
        (yyval.node) = (yyvsp[-3].node); 
        (yyval.node)->children.push_back((yyvsp[-1].node)); 
    }
#line 2111 "./parser/grammar.tab.c"
    break;

  case 78: /* statement: iteration_statement  */
#line 491 "./parser/grammar.y"
                      {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2120 "./parser/grammar.tab.c"
    break;

  case 79: /* statement: assign_expression  */
#line 495 "./parser/grammar.y"
                      {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2129 "./parser/grammar.tab.c"
    break;

  case 80: /* statement: IfStatement  */
#line 499 "./parser/grammar.y"
                {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2138 "./parser/grammar.tab.c"
    break;

  case 81: /* statement: jumpStatement  */
#line 503 "./parser/grammar.y"
                  {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2147 "./parser/grammar.tab.c"
    break;

  case 82: /* statement: routine_call ';'  */
#line 507 "./parser/grammar.y"
                      {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 2156 "./parser/grammar.tab.c"
    break;

  case 83: /* statement: print_statement ';'  */
#line 511 "./parser/grammar.y"
                        {
    (yyval.node) = new None_Terminal_Node("STATEMENT");
    (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 2165 "./parser/grammar.tab.c"
    break;

  case 84: /* print_statement: PRINT '(' expression ')'  */
#line 517 "./parser/grammar.y"
                             {
     (yyval.node) =  new None_Terminal_Node("PRINT_STATMENT");
     (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2174 "./parser/grammar.tab.c"
    break;

  case 85: /* jumpStatement: return_exp  */
#line 523 "./parser/grammar.y"
               {
    (yyval.node) = new None_Terminal_Node("JUMP_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2183 "./parser/grammar.tab.c"
    break;

  case 86: /* jumpStatement: continue_exp  */
#line 527 "./parser/grammar.y"
                 {
    (yyval.node) = new None_Terminal_Node("JUMP_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2192 "./parser/grammar.tab.c"
    break;

  case 87: /* jumpStatement: break_exp  */
#line 531 "./parser/grammar.y"
              {
    (yyval.node) = new None_Terminal_Node("JUMP_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2201 "./parser/grammar.tab.c"
    break;

  case 88: /* return_exp: RETURN ';'  */
#line 537 "./parser/grammar.y"
             {
   (yyval.node) = new None_Terminal_Node("RETURN_EX");
 }
#line 2209 "./parser/grammar.tab.c"
    break;

  case 89: /* return_exp: RETURN expression ';'  */
#line 540 "./parser/grammar.y"
                         {
     (yyval.node) = new None_Terminal_Node("RETURN_EX");
     (yyval.node)->children.push_back((yyvsp[-1].node));
 }
#line 2218 "./parser/grammar.tab.c"
    break;

  case 90: /* continue_exp: CONTINUE ';'  */
#line 546 "./parser/grammar.y"
               {
     (yyval.node) = new None_Terminal_Node("CONTINUE_EX");
 }
#line 2226 "./parser/grammar.tab.c"
    break;

  case 91: /* break_exp: BREAK ';'  */
#line 551 "./parser/grammar.y"
            {
     (yyval.node) = new None_Terminal_Node("BREAK_EX");
 }
#line 2234 "./parser/grammar.tab.c"
    break;

  case 92: /* IfStatement: IF expression THEN body END  */
#line 557 "./parser/grammar.y"
                                {
    (yyval.node) = new None_Terminal_Node("IF_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2244 "./parser/grammar.tab.c"
    break;

  case 93: /* IfStatement: IF expression THEN body ELSE body END  */
#line 562 "./parser/grammar.y"
                                          {
    (yyval.node) = new None_Terminal_Node("IF_STATEMENT_ELSE");
    (yyval.node)->children.push_back((yyvsp[-5].node));
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2255 "./parser/grammar.tab.c"
    break;

  case 94: /* assign_expression: primary ASSIGN_OP expression ';'  */
#line 571 "./parser/grammar.y"
                                    {
    (yyval.node) = new None_Terminal_Node("ASSIGN_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back(new Operator(":="));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2266 "./parser/grammar.tab.c"
    break;

  case 95: /* assign_expression: identifier SUB_ASSIGN expression ';'  */
#line 577 "./parser/grammar.y"
                                        {
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back(new Operator("-="));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2276 "./parser/grammar.tab.c"
    break;

  case 96: /* assign_expression: identifier ADD_ASSIGN expression ';'  */
#line 582 "./parser/grammar.y"
                                        {
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back(new Operator("+="));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2286 "./parser/grammar.tab.c"
    break;

  case 97: /* assign_expression: identifier MUL_ASSIGN expression ';'  */
#line 587 "./parser/grammar.y"
                                        {
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back(new Operator("*="));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2296 "./parser/grammar.tab.c"
    break;

  case 98: /* assign_expression: identifier DIV_ASSIGN expression ';'  */
#line 592 "./parser/grammar.y"
                                        {
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back(new Operator("/="));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2306 "./parser/grammar.tab.c"
    break;

  case 99: /* assign_expression: identifier MOD_ASSIGN expression ';'  */
#line 597 "./parser/grammar.y"
                                        {
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back(new Operator("%="));
    (yyval.node)->children.push_back((yyvsp[-1].node));
  }
#line 2316 "./parser/grammar.tab.c"
    break;

  case 100: /* iteration_statement: while_expression  */
#line 605 "./parser/grammar.y"
                          {
    (yyval.node) = new None_Terminal_Node("ITERATION_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2325 "./parser/grammar.tab.c"
    break;

  case 101: /* iteration_statement: for_expression  */
#line 609 "./parser/grammar.y"
                  {
    (yyval.node) = new None_Terminal_Node("ITERATION_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[0].node));
  }
#line 2334 "./parser/grammar.tab.c"
    break;

  case 102: /* while_expression: WHILE expression LOOP body END  */
#line 615 "./parser/grammar.y"
                                 {
    (yyval.node) = new None_Terminal_Node("WHILE_STATEMENT");
    (yyval.node)->children.push_back((yyvsp[-3].node));
    (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 2344 "./parser/grammar.tab.c"
    break;

  case 103: /* body: body simpleDeclaration  */
#line 622 "./parser/grammar.y"
                           {
      (yyval.node) = (yyvsp[-1].node);
      (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 2353 "./parser/grammar.tab.c"
    break;

  case 104: /* body: body statement  */
#line 626 "./parser/grammar.y"
                   {
       (yyval.node) = (yyvsp[-1].node);
       (yyval.node)->children.push_back((yyvsp[0].node));
    }
#line 2362 "./parser/grammar.tab.c"
    break;

  case 105: /* body: %empty  */
#line 630 "./parser/grammar.y"
                {
      (yyval.node) = new None_Terminal_Node("BODY"); 
    }
#line 2370 "./parser/grammar.tab.c"
    break;

  case 106: /* for_expression: FOR identifier range LOOP body END  */
#line 636 "./parser/grammar.y"
                                     {
      (yyval.node) = new None_Terminal_Node("FOR_STATEMENT");
      (yyval.node)->children.push_back((yyvsp[-4].node));
      (yyval.node)->children.push_back((yyvsp[-3].node));
      (yyval.node)->children.push_back((yyvsp[-1].node));
   }
#line 2381 "./parser/grammar.tab.c"
    break;

  case 107: /* range: IN expression RANGE expression  */
#line 644 "./parser/grammar.y"
                                  {
     (yyval.node) = new None_Terminal_Node("RANGE_EX");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2391 "./parser/grammar.tab.c"
    break;

  case 108: /* range: IN REVERSE expression RANGE expression  */
#line 649 "./parser/grammar.y"
                                           {
     (yyval.node) = new None_Terminal_Node("RANGE_REVERSE");
     (yyval.node)->children.push_back((yyvsp[-2].node));
     (yyval.node)->children.push_back((yyvsp[0].node));
   }
#line 2401 "./parser/grammar.tab.c"
    break;


#line 2405 "./parser/grammar.tab.c"

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

#line 656 "./parser/grammar.y"


void yyerror(char *s) {
  fprintf(stderr, "error: %s\n", s);
}
