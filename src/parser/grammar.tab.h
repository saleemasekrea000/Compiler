/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 153 "./parser/grammar.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

