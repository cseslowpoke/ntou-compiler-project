%{
#include "AST/Ast.hpp"
#include "AST/AssignStmt.hpp"
#include "AST/BinaryOp.hpp"
#include "AST/BreakStmt.hpp"
#include "AST/CompoundStmt.hpp"
#include "AST/Constant.hpp"
#include "AST/ContinueStmt.hpp"
#include "AST/DeclStmt.hpp"
#include "AST/Expression.hpp"
#include "AST/ForStmt.hpp"
#include "AST/FuncDecl.hpp"
#include "AST/FuncInv.hpp"
#include "AST/IfStmt.hpp"
#include "AST/NullStmt.hpp"
#include "AST/Program.hpp"
#include "AST/ReturnStmt.hpp"
#include "AST/UnaryOp.hpp"
#include "AST/VarDecl.hpp"
#include "AST/VarRef.hpp"
#include "AST/WhileStmt.hpp"
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
    std::vector<std::shared_ptr<FuncDecl>> *functions;
    FuncDecl *function;
    std::vector<std::shared_ptr<DeclStmt>> *decls;
    DeclStmt *decl;
    std::vector<std::shared_ptr<VarDecl>> *vars;
    VarDecl *variable;
    std::vector<std::shared_ptr<AstNode>> *stmts;
    CompoundStmt *compound_stmt;
    AstNode *node;
    Type::Kind *type_kind;
    Type *type;
    Constant *constant;
    Expression *expr;
    std::vector<std::shared_ptr<Expression>> *exprs;
    VarRef *var_ref;
    FuncInv *func_inv;
    // std::vector<std::shared_ptr<node>> nodes;
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
%type <node> Jump
%type <node> If
%type <compound_stmt> ElseOrNot
%type <node> While
%type <node> For
%type <type> ArrDeclList
%type <type> ArrDecls
%type <type_kind> Type
%type <vars> IDs
%type <constant> Constant
%type <expr> Expression
%type <expr> ASSIGNorNot
%type <exprs> ArgumentList
%type <exprs> Arguments
%type <var_ref> VarRef
%type <func_inv> FuncInvocation

  /* Keywords */
%token KW_IF KW_ELSE KW_WHILE KW_RETURN KW_BREAK KW_CONTINUE KW_FOR
%token KW_INT KW_VOID KW_CHAR KW_FLOAT KW_TRUE KW_FALSE
  /* Delimiter */
%token COMMA SEMI COLON
%token L_PAREN R_PAREN
%token L_BRACKET R_BRACKET 
%token L_BRACE R_BRACE
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
        std::shared_ptr<std::vector<std::shared_ptr<FuncDecl>>> functions($1);
        ctx->root = std::make_shared<Program>(@1.first_line, @1.first_column, std::move(functions)); 
        // llvm::outs() << *(ctx->root->functions)[0]->getName();
    }
    ;

Functions:
    Function {
        $$ = new std::vector<std::shared_ptr<FuncDecl>>();
        std::shared_ptr<FuncDecl> func($1);
        $$->push_back(std::move(func));
    }
    |
    Functions Function {
        std::shared_ptr<FuncDecl> func($2);
        $1->push_back(std::move(func));
    }
    ;

Function:
    Type ID L_PAREN ParameterList R_PAREN CompoundStatement {
        // std::string name = ;
        std::shared_ptr<DeclStmt> p_decl($4);
        std::shared_ptr<CompoundStmt> p_comstmt($6);
        std::shared_ptr<Type> type = std::make_shared<Type>();
        type->setKind(*$1);
        $$ = new FuncDecl(
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
        std::shared_ptr<VarDecl> tmp($1);
        $$ = new DeclStmt(@1.first_line, @1.first_column);
        $$->addVarDecl(std::move(tmp));
    }
    |
    Parameters COMMA Parameter {
        std::shared_ptr<VarDecl> tmp($3);
        $$->addVarDecl(std::move(tmp));
    }
    ;

Parameter:
    Type ID ArrDeclList {
        $$ = new VarDecl(@1.first_line, @1.first_column, *$2);
        $3->setKind(*$1);
        $$->setType(std::move(std::shared_ptr<Type>($3)));
    }
    ;
VarRef:
    ID ArrDeclList {
        $$ = new VarRef(@1.first_line, @1.first_column, *$1, std::move(std::shared_ptr<Type>($2)));
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
        $$->addDimension($2);
    }
    |
    ArrDecls L_BRACKET INTEGER_LITERAL R_BRACKET {
        $$ = $1;
        $$->addDimension($3);
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
        $$ = new std::vector<std::shared_ptr<DeclStmt>>();
        std::shared_ptr<DeclStmt> decl($1);
        $$->push_back(std::move(decl));
    }
    |
    Declarations Declaration {
        std::shared_ptr<DeclStmt> decl($2);
        $1->push_back(std::move(decl));
    }
    ;

Declaration:
    Type IDs SEMI {
        $$ = new DeclStmt(@1.first_line, @1.first_column);
        for (auto &var: *$2) {
            std::shared_ptr<Type> &tp_ptr = var->getType();
            tp_ptr->setKind(*$1);
            $$->addVarDecl(std::move(var));
        }
    }
    ;

IDs:
    ID ArrDeclList ASSIGNorNot{
        $$ = new std::vector<std::shared_ptr<VarDecl>>;
        std::shared_ptr<Expression> expr($3);
        auto tmp = std::make_shared<VarDecl>(@1.first_line, @1.first_column, *$1, std::move(expr));
        std::shared_ptr<Type> tp($2);
        tmp->setType(std::move(tp));
        $$->push_back(std::move(tmp));
    }
    |
    IDs COMMA ID ArrDeclList {
        auto tmp = std::make_shared<VarDecl>(@3.first_line, @3.first_column, *$3);
        std::shared_ptr<Type> tp($4);
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
        std::shared_ptr<Constant::ValueType> value = std::make_shared<Constant::ValueType>($1);
        $$ = new Constant(@1.first_line, @1.first_column, std::move(value));
    }
    |
    FLOAT_LITERAL { 
        std::shared_ptr<Constant::ValueType> value =    std::make_shared<Constant::ValueType>($1);
        $$ = new Constant(@1.first_line, @1.first_column, std::move(value));
    }
    |
    STRING_LITERAL { 
        std::shared_ptr<Constant::ValueType> value =    std::make_shared<Constant::ValueType>(*$1);
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
        $$ = new std::vector<std::shared_ptr<AstNode>>;
        std::shared_ptr<AstNode> stmt($1);
        $$->push_back(std::move(stmt));
    }
    |
    Statements Statement {
        std::shared_ptr<AstNode> stmt($2);
        $$->push_back(std::move(stmt));
    }
;
Statement: 
    CompoundStatement {
        $$ = $1;
    }
    | 
    Simple{
        $$ = $1;
    }
    |
    Jump {
        $$ = $1;
    }
    | 
    If {
        $$ = $1;
    }
    | 
    While {
        $$ = $1;
    }
    | 
    For {
        $$ = $1;
    }
    ;

CompoundStatement: 
    L_BRACE DeclList StatementList R_BRACE {
        std::shared_ptr<std::vector<std::shared_ptr<DeclStmt>>> p_decls($2);
        std::shared_ptr<std::vector<std::shared_ptr<AstNode>>> p_stmts($3);
        $$ = new CompoundStmt(@1.first_line, @1.first_column, std::move(p_decls), std::move(p_stmts));
    }
    ;      

Simple: 
    VarRef ASSIGN Expression SEMI {
        std::shared_ptr<VarRef> var($1);
        std::shared_ptr<Expression> expr($3);
        $$ = new AssignStmt(@1.first_line, @1.first_column, std::move(var), std::move(expr));
    }
    |
    FuncInvocation SEMI {
        $$ = $1;
    }
    |
    SEMI {
        $$ = new NullStmt(@1.first_line, @1.first_column);
    }
    ;

Jump:
    KW_RETURN Expression SEMI {
        std::shared_ptr<Expression> expr($2);
        $$ = new ReturnStmt(@1.first_line, @1.first_column, std::move(expr));
    }
    | 
    KW_BREAK SEMI {
        $$ = new BreakStmt(@1.first_line, @1.first_column);
    }
    | 
    KW_CONTINUE SEMI {
        $$ = new ContinueStmt(@1.first_line, @1.first_column);
    }

If: 
    KW_IF L_PAREN Expression R_PAREN CompoundStatement ElseOrNot {
        std::shared_ptr<Expression> cond($3);
        std::shared_ptr<CompoundStmt> then_stmt($5);
        std::shared_ptr<CompoundStmt> else_stmt($6);
        $$ = new IfStmt(@1.first_line, @1.first_column, std::move(cond), std::move(then_stmt), std::move(else_stmt));
    }
    ;

ElseOrNot:
    KW_ELSE CompoundStatement {
        $$ = $2;
    }
    |
    Epsilon {
        $$ = nullptr;
    }

While: 
    KW_WHILE L_PAREN Expression R_PAREN CompoundStatement {
        std::shared_ptr<Expression> cond($3);
        std::shared_ptr<CompoundStmt> body($5);
        $$ = new WhileStmt(@1.first_line, @1.first_column, std::move(cond), std::move(body));
    }
    ;

For:
    KW_FOR L_PAREN Simple Expression SEMI  VarRef ASSIGN Expression  R_PAREN CompoundStatement {
        std::shared_ptr<AstNode> init($3);
        std::shared_ptr<Expression> cond($4);
        std::shared_ptr<VarRef> var($6);
        std::shared_ptr<Expression> expr($8);
        std::shared_ptr<AssignStmt> update = std::make_shared<AssignStmt>(@6.first_line, @6.first_column, std::move(var), std::move(expr));
        std::shared_ptr<CompoundStmt> body($10);
        $$ = new ForStmt(@1.first_line, @1.first_column, std::move(init), std::move(cond), std::move(update), std::move(body));
    }
    ;



  // Expression
FuncInvocation:
    ID L_PAREN ArgumentList R_PAREN {
        std::shared_ptr<std::vector<std::shared_ptr<Expression>> > args($3);
        $$ = new FuncInv(@1.first_line, @1.first_column, *$1, std::move(args));
    }
    
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
        $$ = new std::vector<std::shared_ptr<Expression>>;
        std::shared_ptr<Expression> expr($1);
        $$->push_back(std::move(expr));
    }
    |
    Arguments COMMA Expression {
        $$ = $1;
        std::shared_ptr<Expression> expr($3);
        $$->push_back(std::move(expr));
    }

Expression: 
    Constant {
        $$ = $1;   
    }
    |
    VarRef {
        $$ = $1;
    }
    |
    FuncInvocation {
        $$ = $1;
    }
    |
    Expression PLUS Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::ADD;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression MINUS Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::SUB;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression MULTIPLY Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::MUL;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression DIVIDE Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::DIV;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression MOD Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::MOD;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression LESS Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::LT;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression LESS_OR_EQUAL Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::LEQ;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression GREATER Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::GT;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression GREATER_OR_EQUAL Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::GEQ;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression EQUAL Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::EQ;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression NOT_EQUAL Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::NEQ;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression AND Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::AND;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    Expression OR Expression {
        std::shared_ptr<Expression> lhs($1);
        std::shared_ptr<Expression> rhs($3);
        BinaryOp::Op op = BinaryOp::Op::OR;
        $$ = new BinaryOp(@2.first_line, @2.first_column, op, std::move(lhs), std::move(rhs));
    }
    |
    NOT Expression {
        std::shared_ptr<Expression> rhs($2);
        UnaryOp::Op op = UnaryOp::Op::NOT;
        $$ = new UnaryOp(@1.first_line, @1.first_column, op, std::move(rhs));
    }
    |
    MINUS Expression %prec UMINUS {
        std::shared_ptr<Expression> rhs($2);
        UnaryOp::Op op = UnaryOp::Op::NEG;
        $$ = new UnaryOp(@1.first_line, @1.first_column, op, std::move(rhs));
    }
    |
    L_PAREN Expression R_PAREN {
        $$ = $2;
    }
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