%{
#include "AST/Ast.hpp"
#include "AST/BreakStmt.hpp"
#include "AST/CompoundStmt.hpp"
#include "AST/Constant.hpp"
#include "AST/ContinueStmt.hpp"
#include "AST/DeclStmt.hpp"
#include "AST/Expression.hpp"
#include "AST/Function.hpp"
#include "AST/Program.hpp"
#include "AST/ReturnStmt.hpp"
#include "AST/VarDecl.hpp"
#include "AST/Constant.hpp"
#include "visitor/AstDumper.hpp"
#include "Type.hpp"
#include "Context.hpp"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/FormatVariadic.h"
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <memory>
#define YYLTYPE yyltype


typedef struct YYLTYPE {
    uint32_t first_line;
    uint32_t first_column;
    uint32_t last_line;
    uint32_t last_column;
} yyltype;


extern uint32_t line_num;   /* declared in scanner.l */
extern char current_line[]; /* declared in scanner.l */
extern char *yytext;        /* declared by lex */
static void yyerror(Context *ctx, const char *msg);
extern int yylex_destroy(Context *ctx);
%}

%code requires {
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
}

%union {
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
}

%token <integer_literal> INTEGER_LITERAL
%token <float_literal> FLOAT_LITERAL
%token <identifier> ID
%token <string_literal> STRING_LITERAL
%token CHAR_LITERAL // todo

  /* Rule type */
%type <functions> Functions
%type <function> Function
%type <decl> ParameterList
%type <decl> Parameters
%type <variable> Parameter
%type <compound_stmt> CompoundStatement
%type <decl> Declaration
%type <decls> Declarations
%type <decls> DeclList
%type <stmts> StatementList
%type <stmts> Statements
%type <node> Statement
%type <node> Simple
%type <node> If
%type <node> While
%type <node> For
%type <node> Return
%type <node> Break
%type <node> Continue
%type <type> ArrDeclList
%type <type> ArrDecls
%type <type_kind> Type
%type <vars> IDs
%type <constant> Constant
%type <expr> Expression
%type <expr> ASSIGNorNot
%type <exprs> ArgumentList
%type <exprs> Arguments


  /* Keywords */
%token KW_IF KW_ELSE KW_WHILE KW_RETURN KW_BREAK KW_CONTINUE KW_FOR
%token KW_INT KW_VOID KW_CHAR KW_FLOAT KW_TRUE KW_FALSE
  /* Delimiter */
%token COMMA SEMI COLON
%token L_PAREN R_PAREN
%token L_BRACKET R_BRACKET 
  /* Precedence rules */
%right ASSIGN
%left OR
%left AND
%right NOT
%left LESS LESS_OR_EQUAL EQUAL GREATER GREATER_OR_EQUAL NOT_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MOD
%right UMINUS


/* %define api.pure full */
%locations
%parse-param {Context *ctx}
%lex-param {Context *ctx}

%%
program: 
    Functions {
        std::unique_ptr<std::vector<std::unique_ptr<FunctionDecl>>> functions($1);
        ctx->root = std::make_unique<Program>(@1.first_line, @1.first_column, std::move(functions)); 
        // llvm::outs() << *(ctx->root->functions)[0]->getName();
    }
    ;

Functions:
    Function {
        $$ = new std::vector<std::unique_ptr<FunctionDecl>>();
        std::unique_ptr<FunctionDecl> func($1);
        $$->push_back(std::move(func));
    }
    |
    Functions Function {
        std::unique_ptr<FunctionDecl> func($2);
        $1->push_back(std::move(func));
    }
    ;

Function:
    Type ID L_PAREN ParameterList R_PAREN CompoundStatement {
        // std::string name = ;
        std::unique_ptr<DeclStmt> p_decl($4);
        std::unique_ptr<CompoundStmt> p_comstmt($6);
        std::unique_ptr<Type> type = std::make_unique<Type>();
        type->setKind(*$1);
        $$ = new FunctionDecl(
            @1.first_line, @1.first_column,
            *$2, std::move(p_decl), std::move(p_comstmt),
            std::move(type));
        // llvm::errs() << "Function: " << $$->getName() << '\n';
    }
    ;

ParameterList:
    Epsilon {
        $$ = nullptr;
    }
    | 
    Parameters {
        $$ = $1;
    }
    ;

Parameters:
    Parameter {
        std::unique_ptr<VarDecl> tmp($1);
        $$ = new DeclStmt(@1.first_line, @1.first_column);
        $$->addVarDecl(std::move(tmp));
    }
    |
    Parameters COMMA Parameter {
        std::unique_ptr<VarDecl> tmp($3);
        $$->addVarDecl(std::move(tmp));
    }
    ;

Parameter:
    Type ID ArrDeclList {
        $$ = new VarDecl(@1.first_line, @1.first_column, *$2);
        $3->setKind(*$1);
        $$->setType(std::move(std::unique_ptr<Type>($3)));
    }
    ;

ArrDeclList:
    Epsilon {
        $$ = new Type();
    }
    |
    ArrDecls {
        $$ = $1;
    }



ArrDecls:
    L_BRACKET INTEGER_LITERAL R_BRACKET {
        $$ = new Type();
    }
    |
    ArrDecls L_BRACKET INTEGER_LITERAL R_BRACKET {
        $1->addDimension($3);
        $$ = $1;
    }
    ;

DeclList:
    Epsilon {
        $$ = nullptr;
    }
    | 
    Declarations {
        $$ = $1;
    }
    ;

Declarations:
    Declaration {
        $$ = new std::vector<std::unique_ptr<DeclStmt>>();
        std::unique_ptr<DeclStmt> decl($1);
        $$->push_back(std::move(decl));
    }
    |
    Declarations Declaration {
        std::unique_ptr<DeclStmt> decl($2);
        $1->push_back(std::move(decl));
    }
    ;

Declaration:
    Type IDs SEMI {
        $$ = new DeclStmt(@1.first_line, @1.first_column);
        for (auto &var: *$2) {
            std::unique_ptr<Type> &tp_ptr = var->getType();
            tp_ptr->setKind(*$1);
            $$->addVarDecl(std::move(var));
        }
    }
    ;

IDs:
    ID ArrDeclList ASSIGNorNot{
        $$ = new std::vector<std::unique_ptr<VarDecl>>;
        std::unique_ptr<Expression> expr($3);
        auto tmp = std::make_unique<VarDecl>(@1.first_line, @1.first_column, *$1, std::move(expr));
        std::unique_ptr<Type> tp($2);
        tmp->setType(std::move(tp));
        $$->push_back(std::move(tmp));
    }
    |
    IDs COMMA ID ArrDeclList {
        auto tmp = std::make_unique<VarDecl>(@3.first_line, @3.first_column, *$3);
        std::unique_ptr<Type> tp($4);
        tmp->setType(std::move(tp));
        $$->push_back(std::move(tmp));
    }
    ;

ASSIGNorNot: // todo
    Epsilon {
        $$ = nullptr;
    }
    |
    ASSIGN Expression {
        $$ = $2;
    }

Type:
    KW_INT {
        $$ = new Type::Kind(Type::Kind::INT);
    }
    | 
    KW_VOID {
        $$ = new Type::Kind(Type::Kind::VOID);
    }
    | 
    KW_CHAR {
        $$ = new Type::Kind(Type::Kind::CHAR);
    }
    | 
    KW_FLOAT {
        $$ = new Type::Kind(Type::Kind::FLOAT);
    }
    ;

Constant:
    INTEGER_LITERAL {
        std::unique_ptr<Constant::ValueType> value = std::make_unique<Constant::ValueType>($1);
        $$ = new Constant(@1.first_line, @1.first_column, std::move(value));
    }
    |
    FLOAT_LITERAL { 
        std::unique_ptr<Constant::ValueType> value =    std::make_unique<Constant::ValueType>($1);
        $$ = new Constant(@1.first_line, @1.first_column, std::move(value));
    }
    |
    STRING_LITERAL { 
        std::unique_ptr<Constant::ValueType> value =    std::make_unique<Constant::ValueType>(*$1);
        $$ = new Constant(@1.first_line, @1.first_column, std::move(value));
    }
    ;

  //Statements
StatementList: 
    Epsilon {
        $$ = nullptr;
    }
    | 
    Statements {
        $$ = $1;
    }
;
Statements:
    Statement {
        $$ = new std::vector<std::unique_ptr<AstNode>>;
        std::unique_ptr<AstNode> stmt($1);
        $$->push_back(std::move(stmt));
    }
    |
    Statements Statement {
        std::unique_ptr<AstNode> stmt($2);
        $$->push_back(std::move(stmt));
    }
;
Statement: 
    CompoundStatement {
        $$ = $1;
    }
    | 
    Simple {
        $$ = $1;
    }
    | 
    If
    | 
    While
    | 
    For
    ;

CompoundStatement: 
    L_PAREN DeclList StatementList R_PAREN {
        std::unique_ptr<std::vector<std::unique_ptr<DeclStmt>>> p_decls($2);
        std::unique_ptr<std::vector<std::unique_ptr<AstNode>>> p_stmts($3);
        $$ = new CompoundStmt(@1.first_line, @1.first_column, std::move(p_decls), std::move(p_stmts));
    }
    ;      

Simple: 
    ID ASSIGN Expression SEMI
    | 
    Return {
        $$ = $1;
    }
    | 
    Break {
        $$ = $1;
    }
    | 
    Continue {
        $$ = $1;
    }
    |
    SEMI {
        $$ = new NullStmt(@1.first_line, @1.first_column);
    }
    ;
    


If: 
    KW_IF L_PAREN Expression R_PAREN CompoundStatement ElseOrNot
    ;

ElseOrNot:
    KW_ELSE CompoundStatement
    |
    Epsilon

While: 
    KW_WHILE L_PAREN Expression R_PAREN CompoundStatement
    ;

For:
    KW_FOR L_PAREN Simple Expression SEMI Simple R_PAREN CompoundStatement
    ;

Return:
    KW_RETURN Expression SEMI {
        std::unique_ptr<Expression> expr($2);
        $$ = new ReturnStmt(@1.first_line, @1.first_column, std::move(expr));
    }
    ;
    
Break:
    KW_BREAK SEMI {
        $$ = new BreakStmt(@1.first_line, @1.first_column);
    }
    ;
    
Continue:
    KW_CONTINUE SEMI {
        $$ = new ContinueStmt(@1.first_line, @1.first_column);
    }
    ;

  // Expression
FuncInvocation:
    ID L_PAREN ArgumentList R_PAREN
    
ArgumentList:
    Epsilon {
        $$ = nullptr;
    }
    |
    Arguments {
        $$ = $1;
    }

Arguments:
    Expression {
        $$ = new std::vector<std::unique_ptr<Expression>>;
        std::unique_ptr<Expression> expr($1);
        $$->push_back(std::move(expr));
    }
    |
    Arguments COMMA Expression {
        $$ = $1;
        std::unique_ptr<Expression> expr($3);
        $$->push_back(std::move(expr));
    }

Expression: 
    Constant {
        $$ = $1;   
    }
    |
    ID ArrDeclList
    |
    FuncInvocation
    |
    Expression PLUS Expression
    |
    Expression MINUS Expression
    |
    Expression MULTIPLY Expression
    |
    Expression DIVIDE Expression
    |
    Expression MOD Expression
    |
    Expression LESS Expression
    |
    Expression LESS_OR_EQUAL Expression
    |
    Expression GREATER Expression
    |
    Expression GREATER_OR_EQUAL Expression
    |
    Expression EQUAL Expression
    |
    Expression NOT_EQUAL Expression
    |
    Expression AND Expression
    |
    Expression OR Expression
    |
    NOT Expression
    |
    MINUS Expression %prec UMINUS
    |
    L_PAREN Expression R_PAREN
    ;

    /*
       misc
            */
Epsilon:
;
%%

void yyerror(Context *ctx, const char *msg) {
    llvm::errs() << llvm::formatv("\n|-----------------------------------------------------------------"
                                  "---------\n"
                                  "| Error found in Line #{0}: {1}\n"
                                  "|\n"
                                  "| Unmatched token: {2}\n"
                                  "|-----------------------------------------------------------------"
                                  "---------\n",
                                  line_num, current_line, yytext);
    /* fprintf(stderr,
            "\n"
            "|-----------------------------------------------------------------"
            "---------\n"
            "| Error found in Line #%d: %s\n"
            "|\n"
            "| Unmatched token: %s\n"
            "|-----------------------------------------------------------------"
            "---------\n",
            line_num, current_line, yytext); */
    exit(-1);
}