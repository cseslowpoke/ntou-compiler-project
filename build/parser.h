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

#ifndef YY_YY_USERS_DAIDAISO_PROJECT_NTOU_COMPILER_PROJECT_BUILD_PARSER_H_INCLUDED
# define YY_YY_USERS_DAIDAISO_PROJECT_NTOU_COMPILER_PROJECT_BUILD_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 43 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"

  #include "Context.hpp"
  #include "Type.hpp"
  #include "llvm/ADT/StringRef.h"
  #include "llvm/Support/raw_ostream.h"
  #include "llvm/Support/FormatVariadic.h"
  #include <cstdlib>
  #include <string>


  #define YY_DECL \
       int yylex(Context* ctx) 
   YY_DECL;

   void yyerror(Context* ctx, const char* message);

#line 66 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INTEGER_LITERAL = 258,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 259,           /* FLOAT_LITERAL  */
    ID = 260,                      /* ID  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    CHAR_LITERAL = 262,            /* CHAR_LITERAL  */
    KW_IF = 263,                   /* KW_IF  */
    KW_ELSE = 264,                 /* KW_ELSE  */
    KW_WHILE = 265,                /* KW_WHILE  */
    KW_RETURN = 266,               /* KW_RETURN  */
    KW_BREAK = 267,                /* KW_BREAK  */
    KW_CONTINUE = 268,             /* KW_CONTINUE  */
    KW_FOR = 269,                  /* KW_FOR  */
    KW_INT = 270,                  /* KW_INT  */
    KW_VOID = 271,                 /* KW_VOID  */
    KW_CHAR = 272,                 /* KW_CHAR  */
    KW_FLOAT = 273,                /* KW_FLOAT  */
    KW_TRUE = 274,                 /* KW_TRUE  */
    KW_FALSE = 275,                /* KW_FALSE  */
    COMMA = 276,                   /* COMMA  */
    SEMI = 277,                    /* SEMI  */
    COLON = 278,                   /* COLON  */
    L_PAREN = 279,                 /* L_PAREN  */
    R_PAREN = 280,                 /* R_PAREN  */
    L_BRACKET = 281,               /* L_BRACKET  */
    R_BRACKET = 282,               /* R_BRACKET  */
    ASSIGN = 283,                  /* ASSIGN  */
    OR = 284,                      /* OR  */
    AND = 285,                     /* AND  */
    NOT = 286,                     /* NOT  */
    LESS = 287,                    /* LESS  */
    LESS_OR_EQUAL = 288,           /* LESS_OR_EQUAL  */
    EQUAL = 289,                   /* EQUAL  */
    GREATER = 290,                 /* GREATER  */
    GREATER_OR_EQUAL = 291,        /* GREATER_OR_EQUAL  */
    NOT_EQUAL = 292,               /* NOT_EQUAL  */
    PLUS = 293,                    /* PLUS  */
    MINUS = 294,                   /* MINUS  */
    MULTIPLY = 295,                /* MULTIPLY  */
    DIVIDE = 296,                  /* DIVIDE  */
    MOD = 297,                     /* MOD  */
    UMINUS = 298                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 60 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"

    int integer_literal;
    float float_literal;
    std::string *string_literal;
    std::string *identifier;
    std::vector<std::unique_ptr<FunctionDecl>> *functions;
    FunctionDecl *function;
    std::vector<std::unique_ptr<DeclStmt>> *decls;
    DeclStmt *decl;
    std::vector<std::unique_ptr<VarDecl>> *vars;
    VarDecl *variable;
    std::vector<std::unique_ptr<AstNode>> *stmts;
    CompoundStmt *compound_stmt;
    AstNode *node;
    Type::Kind *type_kind;
    Type *type;
    Constant *constant;
    Expression *expr;
    std::vector<std::unique_ptr<Expression>> *exprs;
    // std::vector<std::unique_ptr<node>> nodes;

#line 148 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (Context *ctx);


#endif /* !YY_YY_USERS_DAIDAISO_PROJECT_NTOU_COMPILER_PROJECT_BUILD_PARSER_H_INCLUDED  */
