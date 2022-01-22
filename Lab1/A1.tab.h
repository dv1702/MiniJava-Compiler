/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_A1_TAB_H_INCLUDED
# define YY_YY_A1_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DEFINE_EXPR = 258,
    DEFINE_EXPR_0 = 259,
    DEFINE_EXPR_1 = 260,
    DEFINE_EXPR_2 = 261,
    DEFINE_STMT = 262,
    DEFINE_STMT_0 = 263,
    DEFINE_STMT_1 = 264,
    DEFINE_STMT_2 = 265,
    LEFT_ROUND_BRACKET = 266,
    RIGHT_ROUND_BRACKET = 267,
    LEFT_SQR_BRACKET = 268,
    RIGHT_SQR_BRACKET = 269,
    LEFT_CURL_BRACKET = 270,
    RIGHT_CURL_BRACKET = 271,
    IDENTIFIER = 272,
    INTEGER_LITERAL = 273,
    TRUE = 274,
    FALSE = 275,
    THIS = 276,
    NEW = 277,
    INT = 278,
    NOT = 279,
    BOOLEAN = 280,
    OPERATOR = 281,
    DOT = 282,
    COMMA = 283,
    LENGTH = 284,
    SEMI_COLON = 285,
    ASSIGN = 286,
    IF = 287,
    ELSE = 288,
    WHILE = 289,
    RETURN = 290,
    SYSTEM_OUT_PRINTLN = 291,
    CLASS = 292,
    PUBLIC_STATIC_VOID_MAIN = 293,
    STRING = 294,
    PUBLIC = 295,
    EXTENDS = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 63 "A1.y"

    char *string;
    struct Node *node;
    struct List *list;

#line 105 "A1.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_A1_TAB_H_INCLUDED  */
