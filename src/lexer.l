%{
#include "parser.h"
#define YY_USER_ACTION \
    yylloc.first_line = line_num; \
    yylloc.first_column = col_num; \
    col_num += yyleng;
#define LIST_SOURCE appendToCurrentLine(yytext)
#define LIST_TOKEN(name)  do { \
    LIST_SOURCE; \
    if(ctx->dumpTokens) \
      llvm::outs() << llvm::formatv("<{0}>\n",name); \
  } while(0) 
#define LIST_LITERAL(name, literal)  \
  do { \
    LIST_SOURCE; \
    if(ctx->dumpTokens) \
      llvm::outs() << llvm::formatv("<{0}, {1}>\n",name, literal); \
  } while(0)
#define MAX_LINE_LENG               512
#define MAX_ID_LENG                 32


uint32_t line_num = 1;
uint32_t col_num = 1;
char current_line[MAX_LINE_LENG];


static char string_literal[MAX_LINE_LENG];
static char *current_line_ptr = current_line;

static void appendToCurrentLine(const char *yytext_ptr);

%}

integer 0|[1-9][0-9]*
float  {integer}\.(0|[0-9]*[1-9])?
nonzero_integer [1-9][0-9]*
nonzero_float ({nonzero_integer}\.(0|[0-9]*[1-9]))|(0\.([0-9]*[1-9]))


/* exclusive start condition */
%x CCOMMENT
/* %option reentrant */
%%

  /* keywords */
"int" {LIST_TOKEN("kw_int"); return KW_INT; }
"float" {LIST_TOKEN("kw_float"); return KW_FLOAT; }
"char" {LIST_TOKEN("kw_char"); return KW_CHAR; }
"void" {LIST_TOKEN("void"); return KW_VOID; }
"if" {LIST_TOKEN("if"); return KW_IF; }
"else" {LIST_TOKEN("else"); return KW_ELSE; }
"while" {LIST_TOKEN("while"); return KW_WHILE; }
"for" {LIST_TOKEN("for"); return KW_FOR; }
"return" {LIST_TOKEN("return"); return KW_RETURN; }
"break" {LIST_TOKEN("break"); return KW_BREAK; }
"continue" {LIST_TOKEN("continue"); return KW_CONTINUE; }
"true" {LIST_TOKEN("true"); return KW_TRUE; }
"false" {LIST_TOKEN("false"); return KW_FALSE; }

  /* Delimiter */
"," {LIST_TOKEN(","); return COMMA; }
";" {LIST_TOKEN(";"); return SEMI; }
":" {LIST_TOKEN(":"); return COLON; }
"(" {LIST_TOKEN("("); return L_PAREN; }
")" {LIST_TOKEN(")"); return R_PAREN; }
"[" {LIST_TOKEN("["); return L_BRACKET; }
"]" {LIST_TOKEN("]"); return R_BRACKET; }
"{" {LIST_TOKEN("{"); return L_BRACE; }
"}" {LIST_TOKEN("}"); return R_BRACE; }

    /* Operator */
"+"   {LIST_TOKEN("+"); return PLUS; }
"-"   {LIST_TOKEN("-");return MINUS; }
"*"   {LIST_TOKEN("*");  return MULTIPLY; }
"/"   {LIST_TOKEN("/");  return DIVIDE; }
"%" {LIST_TOKEN("%"); return MOD; }

"<"   {LIST_TOKEN("<"); return LESS; }
"<="  {LIST_TOKEN("<=");  return LESS_OR_EQUAL; }
"<>"  {LIST_TOKEN("<>"); return NOT_EQUAL; }
">="  {LIST_TOKEN(">=");  return GREATER_OR_EQUAL; }
">"   {LIST_TOKEN(">"); return GREATER; }
"=="   {LIST_TOKEN("=="); return EQUAL; }
"="  {LIST_TOKEN("="); return ASSIGN; }
"&&" {LIST_TOKEN("&&");  return AND; }
"||"  {LIST_TOKEN("||"); return OR; }
"!" {LIST_TOKEN("!");  return NOT; }
  /* Identifier */
[a-zA-Z_][a-zA-Z0-9_]* {
    LIST_LITERAL("id", yytext);
    char *tmp = strndup(yytext, MAX_ID_LENG);
    yylval.identifier = new std::string(tmp);
    free(tmp);
    // yylval.identifier = llvmstrndup(yytext, MAX_ID_LENG);
    return ID;
}

{integer}  {
  LIST_LITERAL("integer", yytext);
  yylval.integer_literal = atoi(yytext);
  return INTEGER_LITERAL; 
}

{float} {
  LIST_LITERAL("float", yytext);
  yylval.float_literal = atof(yytext);
  return FLOAT_LITERAL;
}

'([^'\\]|\\[abfnrtv\\'\"?0-7xuU]|\\x[0-9a-fA-F]+|\\u[0-9a-fA-F]{4}|\\U[0-9a-fA-F]{8})' {
  // todo
}

\"([^"\n]|\"\")*\" {
  char *yyt_ptr = yytext + 1;  // +1 for skipping the first double quote "
  char *str_ptr = string_literal;

  while (*yyt_ptr) {
      if (*yyt_ptr == '"') {
          // Handle the situation of two double quotes "" in string literal
          if (*(yyt_ptr + 1) == '"') {
              *str_ptr = *yyt_ptr;
              ++str_ptr;
              yyt_ptr += 2; // move to the next character of ""
          } else {
              ++yyt_ptr;
          }
      } else {  // normal character
          *str_ptr = *yyt_ptr;
          ++str_ptr;
          ++yyt_ptr;
      }
  }
  *str_ptr = '\0';
  LIST_LITERAL("string", string_literal);
  yylval.string_literal = new std::string(strndup(string_literal, MAX_LINE_LENG));
  return STRING_LITERAL;
}

[ \t]   { /* 忽略空白字元 */  }
<INITIAL,CCOMMENT>\n {
    ++line_num;
    col_num = 1;
    current_line[0] = '\0';
    current_line_ptr = current_line;
    // return '\n';
}


"/*"   { BEGIN(CCOMMENT); }
<CCOMMENT>"*/" { BEGIN(INITIAL); }
<CCOMMENT>. {}

  /* Catch the character which is not accepted by all rules above */
. {
  llvm::errs() << llvm::formatv("Error: unexpected character {0} at line {1}, column {2}\n", yytext, line_num, col_num);
    exit(1);
}

%%

static void appendToCurrentLine(const char *yytext_ptr) {
    while (*yytext_ptr) {
        *current_line_ptr = *yytext_ptr;
        ++current_line_ptr;
        ++yytext_ptr;
    }
    *current_line_ptr = '\0';
}

int yywrap() {
  return 1;
}
