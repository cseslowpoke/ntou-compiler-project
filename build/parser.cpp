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
#line 1 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"

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

#line 113 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"

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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER_LITERAL = 3,            /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 4,              /* FLOAT_LITERAL  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 7,               /* CHAR_LITERAL  */
  YYSYMBOL_KW_IF = 8,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 9,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 10,                  /* KW_WHILE  */
  YYSYMBOL_KW_RETURN = 11,                 /* KW_RETURN  */
  YYSYMBOL_KW_BREAK = 12,                  /* KW_BREAK  */
  YYSYMBOL_KW_CONTINUE = 13,               /* KW_CONTINUE  */
  YYSYMBOL_KW_FOR = 14,                    /* KW_FOR  */
  YYSYMBOL_KW_INT = 15,                    /* KW_INT  */
  YYSYMBOL_KW_VOID = 16,                   /* KW_VOID  */
  YYSYMBOL_KW_CHAR = 17,                   /* KW_CHAR  */
  YYSYMBOL_KW_FLOAT = 18,                  /* KW_FLOAT  */
  YYSYMBOL_KW_TRUE = 19,                   /* KW_TRUE  */
  YYSYMBOL_KW_FALSE = 20,                  /* KW_FALSE  */
  YYSYMBOL_COMMA = 21,                     /* COMMA  */
  YYSYMBOL_SEMI = 22,                      /* SEMI  */
  YYSYMBOL_COLON = 23,                     /* COLON  */
  YYSYMBOL_L_PAREN = 24,                   /* L_PAREN  */
  YYSYMBOL_R_PAREN = 25,                   /* R_PAREN  */
  YYSYMBOL_L_BRACKET = 26,                 /* L_BRACKET  */
  YYSYMBOL_R_BRACKET = 27,                 /* R_BRACKET  */
  YYSYMBOL_ASSIGN = 28,                    /* ASSIGN  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_AND = 30,                       /* AND  */
  YYSYMBOL_NOT = 31,                       /* NOT  */
  YYSYMBOL_LESS = 32,                      /* LESS  */
  YYSYMBOL_LESS_OR_EQUAL = 33,             /* LESS_OR_EQUAL  */
  YYSYMBOL_EQUAL = 34,                     /* EQUAL  */
  YYSYMBOL_GREATER = 35,                   /* GREATER  */
  YYSYMBOL_GREATER_OR_EQUAL = 36,          /* GREATER_OR_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 37,                 /* NOT_EQUAL  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 40,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 41,                    /* DIVIDE  */
  YYSYMBOL_MOD = 42,                       /* MOD  */
  YYSYMBOL_UMINUS = 43,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_Functions = 46,                 /* Functions  */
  YYSYMBOL_Function = 47,                  /* Function  */
  YYSYMBOL_ParameterList = 48,             /* ParameterList  */
  YYSYMBOL_Parameters = 49,                /* Parameters  */
  YYSYMBOL_Parameter = 50,                 /* Parameter  */
  YYSYMBOL_ArrDeclList = 51,               /* ArrDeclList  */
  YYSYMBOL_ArrDecls = 52,                  /* ArrDecls  */
  YYSYMBOL_DeclList = 53,                  /* DeclList  */
  YYSYMBOL_Declarations = 54,              /* Declarations  */
  YYSYMBOL_Declaration = 55,               /* Declaration  */
  YYSYMBOL_IDs = 56,                       /* IDs  */
  YYSYMBOL_ASSIGNorNot = 57,               /* ASSIGNorNot  */
  YYSYMBOL_Type = 58,                      /* Type  */
  YYSYMBOL_Constant = 59,                  /* Constant  */
  YYSYMBOL_StatementList = 60,             /* StatementList  */
  YYSYMBOL_Statements = 61,                /* Statements  */
  YYSYMBOL_Statement = 62,                 /* Statement  */
  YYSYMBOL_CompoundStatement = 63,         /* CompoundStatement  */
  YYSYMBOL_Simple = 64,                    /* Simple  */
  YYSYMBOL_If = 65,                        /* If  */
  YYSYMBOL_ElseOrNot = 66,                 /* ElseOrNot  */
  YYSYMBOL_While = 67,                     /* While  */
  YYSYMBOL_For = 68,                       /* For  */
  YYSYMBOL_Return = 69,                    /* Return  */
  YYSYMBOL_Break = 70,                     /* Break  */
  YYSYMBOL_Continue = 71,                  /* Continue  */
  YYSYMBOL_FuncInvocation = 72,            /* FuncInvocation  */
  YYSYMBOL_ArgumentList = 73,              /* ArgumentList  */
  YYSYMBOL_Arguments = 74,                 /* Arguments  */
  YYSYMBOL_Expression = 75,                /* Expression  */
  YYSYMBOL_Epsilon = 76                    /* Epsilon  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   144,   144,   152,   158,   165,   180,   184,   190,   196,
     203,   211,   215,   222,   226,   233,   237,   243,   249,   256,
     267,   276,   285,   289,   294,   298,   302,   306,   312,   317,
     322,   330,   334,   339,   345,   351,   355,   359,   361,   363,
     367,   375,   377,   381,   385,   389,   397,   401,   403,   406,
     410,   414,   421,   427,   434,   437,   441,   446,   452,   459,
     463,   465,   467,   469,   471,   473,   475,   477,   479,   481,
     483,   485,   487,   489,   491,   493,   495,   497,   503
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
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER_LITERAL",
  "FLOAT_LITERAL", "ID", "STRING_LITERAL", "CHAR_LITERAL", "KW_IF",
  "KW_ELSE", "KW_WHILE", "KW_RETURN", "KW_BREAK", "KW_CONTINUE", "KW_FOR",
  "KW_INT", "KW_VOID", "KW_CHAR", "KW_FLOAT", "KW_TRUE", "KW_FALSE",
  "COMMA", "SEMI", "COLON", "L_PAREN", "R_PAREN", "L_BRACKET", "R_BRACKET",
  "ASSIGN", "OR", "AND", "NOT", "LESS", "LESS_OR_EQUAL", "EQUAL",
  "GREATER", "GREATER_OR_EQUAL", "NOT_EQUAL", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "MOD", "UMINUS", "$accept", "program", "Functions", "Function",
  "ParameterList", "Parameters", "Parameter", "ArrDeclList", "ArrDecls",
  "DeclList", "Declarations", "Declaration", "IDs", "ASSIGNorNot", "Type",
  "Constant", "StatementList", "Statements", "Statement",
  "CompoundStatement", "Simple", "If", "ElseOrNot", "While", "For",
  "Return", "Break", "Continue", "FuncInvocation", "ArgumentList",
  "Arguments", "Expression", "Epsilon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     134,   -74,   -74,   -74,   -74,     3,   134,   -74,     9,   -74,
     -74,    -9,   134,    25,    13,   -74,    51,   -74,    33,   134,
      34,   134,   -74,   -74,    62,   -74,    43,   -74,   133,   134,
     -74,    68,   -74,    48,    73,    75,    53,    76,    27,    93,
      94,    97,   -74,    98,   133,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,    34,   -13,   -74,    91,
      27,    27,    27,   -74,   -74,    44,   -74,    27,    27,    27,
     -74,   -74,    49,   -74,   -74,    50,   -74,   -74,   111,   114,
     -74,   -74,    72,   129,   147,    27,   -74,   165,   -14,   -74,
     -74,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    27,   -74,   -74,    34,   -74,
      33,    33,   115,   121,   194,   -74,   -74,   207,   -14,    57,
      57,    57,    57,    57,    57,    12,    12,   -74,   -74,   -74,
      95,   194,   -74,   139,   -74,   -74,    27,    50,    33,   -74,
     -74,   194,   128,   -74,    33,   -74
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    24,    25,    26,    27,     0,     2,     3,     0,     1,
       4,     0,    78,     0,     7,     8,     0,     6,     0,     0,
      78,    78,     5,     9,     0,    10,    12,    11,    78,    16,
      17,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,    32,    33,    35,    36,    37,    38,
      39,    42,    43,    44,    31,    18,    78,     0,    13,     0,
       0,     0,     0,    28,    29,    78,    30,     0,     0,     0,
      59,    61,     0,    52,    53,     0,    40,    34,    78,     0,
      19,    14,     0,     0,     0,    78,    60,     0,    75,    76,
      51,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    22,    78,    41,
       0,     0,     0,    56,    57,    55,    77,    74,    73,    67,
      68,    71,    69,    70,    72,    62,    63,    64,    65,    66,
       0,    23,    21,    78,    49,    54,     0,     0,     0,    46,
      48,    58,     0,    47,     0,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   150,   -74,   -74,   141,   -49,   -74,   -74,
     -74,   144,   -74,   -74,   196,   -74,   -74,   -74,   130,   -18,
     -73,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -56,   -11
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     5,     6,     7,    13,    14,    15,    25,    26,    28,
      29,    30,    57,   106,     8,    70,    43,    44,    45,    46,
      47,    48,   139,    49,    50,    51,    52,    53,    71,   112,
     113,    72,    27
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      22,    17,   104,     9,    82,    83,    84,    78,    79,    80,
      32,    87,    88,    89,    11,    12,    86,    54,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   114,
      63,    64,    65,    66,    19,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
      18,    67,   101,   102,   103,    35,    20,    21,    68,   132,
      24,    38,    39,    40,   142,    33,    69,   107,    85,    34,
      24,    90,    42,    56,   115,    58,    59,    61,    91,    92,
     141,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   133,   134,   109,    99,   100,   101,   102,   103,
      62,    91,    92,    60,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,    73,    74,   137,    81,   108,
     143,    75,   140,    76,    91,    92,   145,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    35,   105,
     135,    36,   136,    37,    38,    39,    40,    41,   138,     1,
       2,     3,     4,   144,   110,    42,    10,    21,    91,    92,
      23,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   111,    55,    77,     0,    91,    92,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     116,     0,     0,     0,    91,    92,     0,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    16,     0,
       0,     0,     0,     0,     0,    16,     0,    31,     0,     0,
       0,     0,     0,    91,    92,    31,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,    92,     0,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103
};

static const yytype_int16 yycheck[] =
{
      18,    12,    75,     0,    60,    61,    62,    56,    21,    22,
      21,    67,    68,    69,     5,    24,    65,    28,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    85,
       3,     4,     5,     6,    21,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      25,    24,    40,    41,    42,     5,     5,    24,    31,   108,
      26,    11,    12,    13,   137,     3,    39,    78,    24,    26,
      26,    22,    22,     5,    85,    27,     3,    24,    29,    30,
     136,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,   110,   111,    22,    38,    39,    40,    41,    42,
      24,    29,    30,    28,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    22,    22,    22,    27,     5,
     138,    24,   133,    25,    29,    30,   144,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     5,    28,
      25,     8,    21,    10,    11,    12,    13,    14,     9,    15,
      16,    17,    18,    25,    25,    22,     6,    24,    29,    30,
      19,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    25,    29,    44,    -1,    29,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      25,    -1,    -1,    -1,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    29,    30,    29,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    30,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    16,    17,    18,    45,    46,    47,    58,     0,
      47,     5,    24,    48,    49,    50,    58,    76,    25,    21,
       5,    24,    63,    50,    26,    51,    52,    76,    53,    54,
      55,    58,    76,     3,    26,     5,     8,    10,    11,    12,
      13,    14,    22,    60,    61,    62,    63,    64,    65,    67,
      68,    69,    70,    71,    76,    55,     5,    56,    27,     3,
      28,    24,    24,     3,     4,     5,     6,    24,    31,    39,
      59,    72,    75,    22,    22,    24,    25,    62,    51,    21,
      22,    27,    75,    75,    75,    24,    51,    75,    75,    75,
      22,    29,    30,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    64,    28,    57,    76,     5,    22,
      25,    25,    73,    74,    75,    76,    25,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    51,    63,    63,    25,    21,    22,     9,    66,
      76,    75,    64,    63,    25,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    48,    48,    49,    49,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    62,
      63,    64,    64,    64,    64,    64,    65,    66,    66,    67,
      68,    69,    70,    71,    72,    73,    73,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     6,     1,     1,     1,     3,
       3,     1,     1,     3,     4,     1,     1,     1,     2,     3,
       3,     4,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       4,     4,     1,     1,     1,     1,     6,     2,     1,     5,
       8,     3,     2,     2,     4,     1,     1,     1,     3,     1,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     3,     0
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
        yyerror (ctx, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, ctx); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Context *ctx)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (ctx);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, Context *ctx)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, ctx);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, Context *ctx)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), ctx);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, ctx); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, Context *ctx)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (ctx);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (Context *ctx)
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (ctx);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: Functions  */
#line 144 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
              {
        std::unique_ptr<std::vector<std::unique_ptr<FunctionDecl>>> functions((yyvsp[0].functions));
        ctx->root = std::make_unique<Program>((yylsp[0]).first_line, (yylsp[0]).first_column, std::move(functions)); 
        // llvm::outs() << *(ctx->root->functions)[0]->getName();
    }
#line 1417 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 3: /* Functions: Function  */
#line 152 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
             {
        (yyval.functions) = new std::vector<std::unique_ptr<FunctionDecl>>();
        std::unique_ptr<FunctionDecl> func((yyvsp[0].function));
        (yyval.functions)->push_back(std::move(func));
    }
#line 1427 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 4: /* Functions: Functions Function  */
#line 158 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                       {
        std::unique_ptr<FunctionDecl> func((yyvsp[0].function));
        (yyvsp[-1].functions)->push_back(std::move(func));
    }
#line 1436 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 5: /* Function: Type ID L_PAREN ParameterList R_PAREN CompoundStatement  */
#line 165 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                                                            {
        // std::string name = ;
        std::unique_ptr<DeclStmt> p_decl((yyvsp[-2].decl));
        std::unique_ptr<CompoundStmt> p_comstmt((yyvsp[0].compound_stmt));
        std::unique_ptr<Type> type = std::make_unique<Type>();
        type->setKind(*(yyvsp[-5].type_kind));
        (yyval.function) = new FunctionDecl(
            (yylsp[-5]).first_line, (yylsp[-5]).first_column,
            *(yyvsp[-4].identifier), std::move(p_decl), std::move(p_comstmt),
            std::move(type));
        // llvm::errs() << "Function: " << $$->getName() << '\n';
    }
#line 1453 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 6: /* ParameterList: Epsilon  */
#line 180 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
            {
        (yyval.decl) = nullptr;
    }
#line 1461 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 7: /* ParameterList: Parameters  */
#line 184 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
               {
        (yyval.decl) = (yyvsp[0].decl);
    }
#line 1469 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 8: /* Parameters: Parameter  */
#line 190 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
              {
        std::unique_ptr<VarDecl> tmp((yyvsp[0].variable));
        (yyval.decl) = new DeclStmt((yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.decl)->addVarDecl(std::move(tmp));
    }
#line 1479 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 9: /* Parameters: Parameters COMMA Parameter  */
#line 196 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                               {
        std::unique_ptr<VarDecl> tmp((yyvsp[0].variable));
        (yyval.decl)->addVarDecl(std::move(tmp));
    }
#line 1488 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 10: /* Parameter: Type ID ArrDeclList  */
#line 203 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                        {
        (yyval.variable) = new VarDecl((yylsp[-2]).first_line, (yylsp[-2]).first_column, *(yyvsp[-1].identifier));
        (yyvsp[0].type)->setKind(*(yyvsp[-2].type_kind));
        (yyval.variable)->setType(std::move(std::unique_ptr<Type>((yyvsp[0].type))));
    }
#line 1498 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 11: /* ArrDeclList: Epsilon  */
#line 211 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
            {
        (yyval.type) = new Type();
    }
#line 1506 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 12: /* ArrDeclList: ArrDecls  */
#line 215 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
             {
        (yyval.type) = (yyvsp[0].type);
    }
#line 1514 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 13: /* ArrDecls: L_BRACKET INTEGER_LITERAL R_BRACKET  */
#line 222 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                                        {
        (yyval.type) = new Type();
    }
#line 1522 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 14: /* ArrDecls: ArrDecls L_BRACKET INTEGER_LITERAL R_BRACKET  */
#line 226 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                                                 {
        (yyvsp[-3].type)->addDimension((yyvsp[-1].integer_literal));
        (yyval.type) = (yyvsp[-3].type);
    }
#line 1531 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 15: /* DeclList: Epsilon  */
#line 233 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
            {
        (yyval.decls) = nullptr;
    }
#line 1539 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 16: /* DeclList: Declarations  */
#line 237 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                 {
        (yyval.decls) = (yyvsp[0].decls);
    }
#line 1547 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 17: /* Declarations: Declaration  */
#line 243 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                {
        (yyval.decls) = new std::vector<std::unique_ptr<DeclStmt>>();
        std::unique_ptr<DeclStmt> decl((yyvsp[0].decl));
        (yyval.decls)->push_back(std::move(decl));
    }
#line 1557 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 18: /* Declarations: Declarations Declaration  */
#line 249 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                             {
        std::unique_ptr<DeclStmt> decl((yyvsp[0].decl));
        (yyvsp[-1].decls)->push_back(std::move(decl));
    }
#line 1566 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 19: /* Declaration: Type IDs SEMI  */
#line 256 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                  {
        (yyval.decl) = new DeclStmt((yylsp[-2]).first_line, (yylsp[-2]).first_column);
        for (auto &var: *(yyvsp[-1].vars)) {
            std::unique_ptr<Type> &tp_ptr = var->getType();
            tp_ptr->setKind(*(yyvsp[-2].type_kind));
            (yyval.decl)->addVarDecl(std::move(var));
        }
    }
#line 1579 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 20: /* IDs: ID ArrDeclList ASSIGNorNot  */
#line 267 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                              {
        (yyval.vars) = new std::vector<std::unique_ptr<VarDecl>>;
        std::unique_ptr<Expression> expr((yyvsp[0].expr));
        auto tmp = std::make_unique<VarDecl>((yylsp[-2]).first_line, (yylsp[-2]).first_column, *(yyvsp[-2].identifier), std::move(expr));
        std::unique_ptr<Type> tp((yyvsp[-1].type));
        tmp->setType(std::move(tp));
        (yyval.vars)->push_back(std::move(tmp));
    }
#line 1592 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 21: /* IDs: IDs COMMA ID ArrDeclList  */
#line 276 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                             {
        auto tmp = std::make_unique<VarDecl>((yylsp[-1]).first_line, (yylsp[-1]).first_column, *(yyvsp[-1].identifier));
        std::unique_ptr<Type> tp((yyvsp[0].type));
        tmp->setType(std::move(tp));
        (yyval.vars)->push_back(std::move(tmp));
    }
#line 1603 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 22: /* ASSIGNorNot: Epsilon  */
#line 285 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
            {
        (yyval.expr) = nullptr;
    }
#line 1611 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 23: /* ASSIGNorNot: ASSIGN Expression  */
#line 289 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                      {
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1619 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 24: /* Type: KW_INT  */
#line 294 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
           {
        (yyval.type_kind) = new Type::Kind(Type::Kind::INT);
    }
#line 1627 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 25: /* Type: KW_VOID  */
#line 298 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
            {
        (yyval.type_kind) = new Type::Kind(Type::Kind::VOID);
    }
#line 1635 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 26: /* Type: KW_CHAR  */
#line 302 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
            {
        (yyval.type_kind) = new Type::Kind(Type::Kind::CHAR);
    }
#line 1643 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 27: /* Type: KW_FLOAT  */
#line 306 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
             {
        (yyval.type_kind) = new Type::Kind(Type::Kind::FLOAT);
    }
#line 1651 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 28: /* Constant: INTEGER_LITERAL  */
#line 312 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                    {
        std::unique_ptr<Constant::ValueType> value = std::make_unique<Constant::ValueType>((yyvsp[0].integer_literal));
        (yyval.constant) = new Constant((yylsp[0]).first_line, (yylsp[0]).first_column, std::move(value));
    }
#line 1660 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 29: /* Constant: FLOAT_LITERAL  */
#line 317 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                  { 
        std::unique_ptr<Constant::ValueType> value =    std::make_unique<Constant::ValueType>((yyvsp[0].float_literal));
        (yyval.constant) = new Constant((yylsp[0]).first_line, (yylsp[0]).first_column, std::move(value));
    }
#line 1669 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 30: /* Constant: STRING_LITERAL  */
#line 322 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                   { 
        std::unique_ptr<Constant::ValueType> value =    std::make_unique<Constant::ValueType>(*(yyvsp[0].string_literal));
        (yyval.constant) = new Constant((yylsp[0]).first_line, (yylsp[0]).first_column, std::move(value));
    }
#line 1678 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 31: /* StatementList: Epsilon  */
#line 330 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
            {
        (yyval.stmts) = nullptr;
    }
#line 1686 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 32: /* StatementList: Statements  */
#line 334 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
               {
        (yyval.stmts) = (yyvsp[0].stmts);
    }
#line 1694 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 33: /* Statements: Statement  */
#line 339 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
              {
        (yyval.stmts) = new std::vector<std::unique_ptr<AstNode>>;
        std::unique_ptr<AstNode> stmt((yyvsp[0].node));
        (yyval.stmts)->push_back(std::move(stmt));
    }
#line 1704 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 34: /* Statements: Statements Statement  */
#line 345 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                         {
        std::unique_ptr<AstNode> stmt((yyvsp[0].node));
        (yyval.stmts)->push_back(std::move(stmt));
    }
#line 1713 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 35: /* Statement: CompoundStatement  */
#line 351 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                      {
        (yyval.node) = (yyvsp[0].compound_stmt);
    }
#line 1721 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 36: /* Statement: Simple  */
#line 355 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1729 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 40: /* CompoundStatement: L_PAREN DeclList StatementList R_PAREN  */
#line 367 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                                           {
        std::unique_ptr<std::vector<std::unique_ptr<DeclStmt>>> p_decls((yyvsp[-2].decls));
        std::unique_ptr<std::vector<std::unique_ptr<AstNode>>> p_stmts((yyvsp[-1].stmts));
        (yyval.compound_stmt) = new CompoundStmt((yylsp[-3]).first_line, (yylsp[-3]).first_column, std::move(p_decls), std::move(p_stmts));
    }
#line 1739 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 42: /* Simple: Return  */
#line 377 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
           {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1747 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 43: /* Simple: Break  */
#line 381 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
          {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1755 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 44: /* Simple: Continue  */
#line 385 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
             {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1763 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 45: /* Simple: SEMI  */
#line 389 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
         {
        (yyval.node) = new NullStmt((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1771 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 51: /* Return: KW_RETURN Expression SEMI  */
#line 414 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                              {
        std::unique_ptr<Expression> expr((yyvsp[-1].expr));
        (yyval.node) = new ReturnStmt((yylsp[-2]).first_line, (yylsp[-2]).first_column, std::move(expr));
    }
#line 1780 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 52: /* Break: KW_BREAK SEMI  */
#line 421 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                  {
        (yyval.node) = new BreakStmt((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1788 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 53: /* Continue: KW_CONTINUE SEMI  */
#line 427 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                     {
        (yyval.node) = new ContinueStmt((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1796 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 55: /* ArgumentList: Epsilon  */
#line 437 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
            {
        (yyval.exprs) = nullptr;
    }
#line 1804 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 56: /* ArgumentList: Arguments  */
#line 441 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
              {
        (yyval.exprs) = (yyvsp[0].exprs);
    }
#line 1812 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 57: /* Arguments: Expression  */
#line 446 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
               {
        (yyval.exprs) = new std::vector<std::unique_ptr<Expression>>;
        std::unique_ptr<Expression> expr((yyvsp[0].expr));
        (yyval.exprs)->push_back(std::move(expr));
    }
#line 1822 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 58: /* Arguments: Arguments COMMA Expression  */
#line 452 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
                               {
        (yyval.exprs) = (yyvsp[-2].exprs);
        std::unique_ptr<Expression> expr((yyvsp[0].expr));
        (yyval.exprs)->push_back(std::move(expr));
    }
#line 1832 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;

  case 59: /* Expression: Constant  */
#line 459 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"
             {
        (yyval.expr) = (yyvsp[0].constant);   
    }
#line 1840 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"
    break;


#line 1844 "/Users/daidaiso/Project/ntou-compiler-project/build/parser.cpp"

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
  *++yylsp = yyloc;

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
      yyerror (ctx, YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, ctx);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, ctx);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (ctx, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, ctx);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, ctx);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 505 "/Users/daidaiso/Project/ntou-compiler-project/src/parser.y"


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
