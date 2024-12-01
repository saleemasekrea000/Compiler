/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER_LITERAL = 259,         /* INTEGER_LITERAL  */
    REAL_LITERAL = 260,            /* REAL_LITERAL  */
    BOOLEAN_LITERAL = 261,         /* BOOLEAN_LITERAL  */
    IS = 262,                      /* IS  */
    WHILE = 263,                   /* WHILE  */
    END = 264,                     /* END  */
    ROUTINE = 265,                 /* ROUTINE  */
    VAR = 266,                     /* VAR  */
    INTEGER_LITERAL_KEYWORD = 267, /* INTEGER_LITERAL_KEYWORD  */
    REAL_LITERAL_KEYWORD = 268,    /* REAL_LITERAL_KEYWORD  */
    OR = 269,                      /* OR  */
    AND = 270,                     /* AND  */
    XOR = 271,                     /* XOR  */
    NOT = 272,                     /* NOT  */
    RANGE = 273,                   /* RANGE  */
    REVERSE = 274,                 /* REVERSE  */
    BOOLEAN_LITERAL_KEYWORD = 275, /* BOOLEAN_LITERAL_KEYWORD  */
    RECORD = 276,                  /* RECORD  */
    ARRAY = 277,                   /* ARRAY  */
    FOR = 278,                     /* FOR  */
    RETURN = 279,                  /* RETURN  */
    THEN = 280,                    /* THEN  */
    TRUE = 281,                    /* TRUE  */
    FALSE = 282,                   /* FALSE  */
    TYPE = 283,                    /* TYPE  */
    LOOP = 284,                    /* LOOP  */
    IN = 285,                      /* IN  */
    IF = 286,                      /* IF  */
    ELSE = 287,                    /* ELSE  */
    BREAK = 288,                   /* BREAK  */
    CONTINUE = 289,                /* CONTINUE  */
    PRINT = 290,                   /* PRINT  */
    LE_OP = 291,                   /* LE_OP  */
    GE_OP = 292,                   /* GE_OP  */
    NE_OP = 293,                   /* NE_OP  */
    AND_OP = 294,                  /* AND_OP  */
    OR_OP = 295,                   /* OR_OP  */
    MUL_ASSIGN = 296,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 297,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 298,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 299,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 300,              /* SUB_ASSIGN  */
    ASSIGN_OP = 301                /* ASSIGN_OP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "grammar.y"

  char *id_val;
  int int_val;
  double real_val;
  bool bool_val;
  char *op_val;
  char *keyword_val;
  AST_Node* node; 
  char * type_name;


#line 122 "grammar.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
