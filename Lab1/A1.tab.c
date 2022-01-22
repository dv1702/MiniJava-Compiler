/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "A1.y"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char prg[100000];
bool isParsed = true;

typedef struct Node{
    char* text;
    struct Node* next;
} Node; 

typedef struct List{
    Node* head;
    Node* tail;
} List;

void MakeNull(List *l){
    l = (List*)malloc(sizeof(List));
    l->head = (Node*)malloc(sizeof(Node));
    l->tail = l->head;
    l->head->next = NULL;
}

void Insert(List *l, char* val)
{
    l->tail->next = (Node*)malloc(sizeof(Node));
    l->tail = l->tail->next;
    l->tail->text = val;
}

List *Concatenate(List *l1, List *l2)
{
    l2->head = l2->head->next;
    l1->tail->next = l2->head;
    l1->tail = l2->tail;
    return l1;
}

void PrintList(List *l1){
    Node* tmp = l1->head;
    while(tmp->next){
        puts(tmp->next->text);
        tmp = tmp->next;
    }
}

void Free(List *l){
    Node* tmp = l->head;
    while(tmp->next){
        Node* tmpLol = tmp->next;
        free(tmp);
        tmpLol = tmp;
    }
    free(tmp);
}


#line 131 "A1.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 231 "A1.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_A1_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   110,   110,   117,   121,   126,   130,   134,   139,   144,
     148,   152,   156,   161,   166,   169,   179,   183,   187,   191,
     196,   200,   204,   206,   209,   212,   217,   221,   225,   230,
     234,   237,   241,   245,   248,   252,   256,   260,   265,   269,
     273,   276,   281,   285,   289,   293,   297,   301,   303,   307,
     311,   316,   321,   325,   329,   333,   337,   341,   348,   352,
     356,   360,   365,   369,   373,   377,   382,   386,   391,   395,
     399,   403,   407,   409,   413,   414,   418,   420,   425,   429,
     433,   437,   441,   445,   449,   453,   458,   462,   467,   471,
     475,   479,   483,   487,   491,   496,   502,   506,   510,   515,
     520,   524,   528,   532,   536,   540,   544,   548,   552
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DEFINE_EXPR", "DEFINE_EXPR_0",
  "DEFINE_EXPR_1", "DEFINE_EXPR_2", "DEFINE_STMT", "DEFINE_STMT_0",
  "DEFINE_STMT_1", "DEFINE_STMT_2", "LEFT_ROUND_BRACKET",
  "RIGHT_ROUND_BRACKET", "LEFT_SQR_BRACKET", "RIGHT_SQR_BRACKET",
  "LEFT_CURL_BRACKET", "RIGHT_CURL_BRACKET", "IDENTIFIER",
  "INTEGER_LITERAL", "TRUE", "FALSE", "THIS", "NEW", "INT", "NOT",
  "BOOLEAN", "OPERATOR", "DOT", "COMMA", "LENGTH", "SEMI_COLON", "ASSIGN",
  "IF", "ELSE", "WHILE", "RETURN", "SYSTEM_OUT_PRINTLN", "CLASS",
  "PUBLIC_STATIC_VOID_MAIN", "STRING", "PUBLIC", "EXTENDS", "$accept",
  "Goal", "MainClass", "Class", "MainFuntion", "PublicMain", "String",
  "MainFunctionStatement", "MultipleTypeDeclaration", "WithExtends",
  "Extends", "MultipleType", "MultipleMethod", "MultipleTypeArgsStatement",
  "Public", "MultipleTypeArgs", "MoreTypeArgs", "Return", "Type",
  "IntBrackets", "MacroDefinition", "MacroDefStatement", "DefineStmt",
  "DefineStmt0", "DefineStmt1", "DefineStmt2", "Statement",
  "IdentifierStatement", "ElsePart", "SysOut", "Semicolon", "Assign", "If",
  "Else", "While", "MacroDefExpression", "DefineExpr", "DefineExpr0",
  "DefineExpr1", "DefineExpr2", "Expression", "SubExpression",
  "NonZeroExpression", "PositiveExpression", "Operation",
  "PrimaryExpression", "BoolVal", "This", "Length", "New", "Int", "Not",
  "Dot", "Boolean", "ThreeArgs", "MoreArgs", "TwoArgs", "OneArg",
  "Integer", "Identifier", "LRbracket", "RRbracket", "LSbracket",
  "RSbracket", "LCbracket", "RCbracket", "Comma", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF (-157)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     292,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,    27,
      -8,   292,    29,    29,    29,    29,   292,    29,    29,    29,
      29,  -157,  -157,    -8,    29,  -157,  -157,    41,    41,    41,
      41,  -157,    41,    41,    41,    41,    29,  -157,    44,  -157,
      29,    50,    29,    29,    29,    50,    29,    29,    -1,  -157,
      33,    50,    37,  -157,    44,    50,  -157,    50,    37,    50,
      41,    50,    50,  -157,  -157,    29,    -6,  -157,    58,    41,
      44,  -157,    29,    67,    44,    44,    29,    41,   252,    41,
      41,    44,  -157,  -157,    35,    29,    68,  -157,  -157,  -157,
    -157,    54,    67,    37,  -157,  -157,  -157,    58,    41,    41,
      41,    45,    67,    67,    67,  -157,   252,  -157,  -157,  -157,
    -157,  -157,  -157,    50,   147,  -157,  -157,     3,   252,  -157,
      41,   252,   252,   252,    -6,  -157,    58,    -6,    53,  -157,
    -157,    90,  -157,    68,    58,    29,  -157,   252,   252,   252,
    -157,  -157,   252,   252,   252,    58,    58,    58,    50,  -157,
    -157,  -157,  -157,  -157,   252,  -157,    29,   252,    68,    41,
    -157,   252,    50,    50,    50,    35,    -8,    29,  -157,    -6,
    -157,  -157,    90,  -157,    37,    50,    50,    50,    53,    37,
      50,    90,  -157,  -157,  -157,  -157,  -157,  -157,    41,    90,
     252,    50,    50,  -157,  -157,  -157,    58,  -157,    41,  -157,
      29,  -157,    29,    53,    67,    67,    67,  -157,   252,    53,
      69,   252,  -157,    90,  -157,  -157,    -8,    -6,    50,    37,
      67,    80,    67,  -157,    37,  -157,   252,    50,  -157,  -157,
      50,    29,    44,  -157,  -157,  -157,  -157,    67,  -157,  -157,
      53,  -157,    44,    37,    83,    67,    67,    62,  -157,    -6,
      58,    41,  -157,  -157,    79,    29,  -157,    45,    29,  -157,
     252,  -157,   252,    53,    37,    50,    53,    62,  -157,    53,
      58,  -157,  -157,    35,  -157
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      33,    62,    63,    64,    65,    38,    39,    40,    41,     0,
       0,    33,     0,     0,     0,     0,    33,     0,     0,     0,
       0,     1,     4,    10,     0,    32,   101,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     2,     0,   102,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   106,
       0,     0,     0,   103,     0,     0,    99,     0,     0,     0,
       0,     0,     0,    13,     9,     0,    15,     6,     0,     0,
       0,   108,     0,    47,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    94,    17,     0,    30,    27,    28,   107,
       3,     0,    47,     0,    55,    57,    52,     0,     0,     0,
       0,     0,    47,    47,    47,    98,     0,   100,    86,    87,
      88,    90,    92,     0,    72,    79,    81,     0,     0,    78,
      80,     0,     0,     0,    15,    20,     0,     0,     0,   104,
      26,     0,     7,     0,     0,     0,    35,     0,     0,     0,
      54,    45,     0,    74,     0,     0,     0,     0,     0,    59,
      77,    93,    89,    66,     0,    70,     0,     0,     0,     0,
      84,    74,     0,     0,     0,    17,    10,     0,    53,    15,
     105,    29,     0,    34,    97,     0,     0,     0,     0,    76,
       0,     0,    42,    36,    37,    58,    68,    80,     0,     0,
       0,     0,     0,    85,    60,    61,     0,    12,     0,    14,
       0,    95,     0,     0,    47,    47,    47,    73,     0,     0,
       0,    74,    69,     0,    83,    67,    10,    22,     0,    97,
      47,     0,    47,    48,    76,    50,     0,     0,    82,    11,
       0,     0,     0,    96,    43,    56,    44,    47,    46,    75,
       0,    71,     0,    24,     0,    47,    47,    47,    21,     0,
       0,     0,    51,    49,     0,     0,    19,    28,     0,     5,
       0,    25,     0,     0,    24,     0,     0,    47,    23,     0,
       0,    18,     8,    17,    16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -157,  -157,  -157,   110,  -157,  -157,  -157,  -157,  -153,  -157,
    -157,  -120,  -155,  -145,  -157,  -157,  -140,  -157,  -106,  -157,
      86,  -157,  -157,  -157,  -157,  -157,   109,  -157,  -157,  -119,
      17,   -82,  -157,  -157,  -157,  -157,  -157,  -157,  -157,  -157,
      28,  -157,  -139,   -94,  -157,  -109,  -157,  -157,  -157,  -157,
      22,  -157,  -157,  -157,    96,   -72,   107,   112,  -157,   -12,
       9,    76,   -63,  -156,    78,   -79,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    23,    36,    68,    69,   133,   250,    37,    64,
      65,    84,   126,   254,   127,   230,   248,   262,    85,   130,
      10,    11,    12,    13,    14,    15,   256,   141,   236,    98,
     169,   142,    99,   237,   100,    16,    17,    18,    19,    20,
     179,   153,   180,   207,   154,   114,   115,   116,   155,   117,
      86,   118,   156,    87,    51,   201,    57,    55,   119,   120,
     121,    54,   144,   171,   102,    90,   202
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    28,    29,    30,   165,    32,    33,    34,    35,    72,
     196,    26,    38,   197,    49,    76,   200,    82,   136,    83,
      26,   167,   192,   131,    48,   210,    82,    21,    52,    22,
      56,    58,    52,   212,    56,    58,    40,    41,    42,    43,
      63,    44,    45,    46,    47,   186,    26,   166,   189,   199,
     135,   157,    39,    81,    88,   173,    39,   228,   129,    49,
      93,   101,    53,   229,   105,    71,   182,   183,   184,    78,
     172,    67,   227,   128,    89,   125,   140,    49,    91,    26,
     101,   129,    49,   168,    26,    82,   106,    83,   122,   123,
     101,   101,   101,   132,    94,   190,    95,    25,    96,    94,
     140,    95,    31,    96,   170,   159,   113,   137,   138,   139,
     143,   231,    88,   235,   261,    88,    50,   216,   274,    96,
      24,    60,   271,   174,   268,   251,    66,    70,   226,   161,
     239,    74,    73,    75,   148,    77,   208,    79,    80,   158,
      59,   255,   187,   258,   188,   187,   160,   233,    92,   162,
     163,   164,   103,   104,    62,   198,     0,    88,    61,   124,
     129,   255,     0,     0,     0,   175,   176,   177,   191,     0,
     178,   259,   181,   150,   151,     0,   152,     0,     0,     0,
       0,   208,    97,     0,     0,     0,     0,     0,   218,   149,
     219,   273,   101,   101,   101,   206,     0,   211,     0,     0,
     249,   134,     0,     0,     0,    88,     0,   217,   101,     0,
     101,   145,   146,   147,     0,     0,     0,     0,   213,   243,
     220,   249,     0,     0,   185,   101,   225,     0,     0,     0,
       0,     0,     0,   101,   101,   257,   224,    88,   193,   194,
     195,     0,     0,   263,     0,     0,   264,     0,     0,     0,
       0,   203,   204,   205,   240,   257,   209,   246,     0,     0,
     260,     0,     0,    39,     0,     0,   143,   214,   215,    26,
     107,   108,   109,   110,   111,     0,   112,     0,     0,     0,
     267,     0,     0,   270,     0,     0,   272,     0,   265,     0,
     266,     0,     0,     0,   232,     1,     2,     3,     4,     5,
       6,     7,     8,   241,     0,     0,   242,     0,     0,     0,
     244,     0,     0,   221,   222,   223,     0,     0,     0,     0,
     247,     0,     0,     0,     0,     0,     0,     0,     0,   234,
       0,   238,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   269,     0,     0,     0,     0,   245,     0,     0,     0,
       0,     0,     0,     0,   252,   253
};

static const yytype_int16 yycheck[] =
{
      12,    13,    14,    15,   124,    17,    18,    19,    20,    52,
     165,    17,    24,   166,    15,    58,   172,    23,    97,    25,
      17,   127,   161,    86,    36,   181,    23,     0,    40,    37,
      42,    43,    44,   189,    46,    47,    27,    28,    29,    30,
      41,    32,    33,    34,    35,   154,    17,   126,   157,   169,
      93,   114,    11,    65,    66,   134,    11,   213,    13,    15,
      72,    73,    12,   216,    76,    28,   145,   146,   147,    60,
     133,    38,   211,    85,    16,    40,    31,    15,    69,    17,
      92,    13,    15,    30,    17,    23,    77,    25,    79,    80,
     102,   103,   104,    39,    32,   158,    34,    11,    36,    32,
      31,    34,    16,    36,    14,   117,    78,    98,    99,   100,
     101,   217,   124,    33,    35,   127,    38,   196,   273,    36,
      10,    45,   267,   135,   264,   244,    48,    51,   210,   120,
     224,    55,    54,    57,   106,    59,   179,    61,    62,   117,
      44,   247,   154,   249,   156,   157,   118,   219,    70,   121,
     122,   123,    74,    75,    47,   167,    -1,   169,    46,    81,
      13,   267,    -1,    -1,    -1,   137,   138,   139,   159,    -1,
     142,   250,   144,    26,    27,    -1,    29,    -1,    -1,    -1,
      -1,   224,    73,    -1,    -1,    -1,    -1,    -1,   200,   113,
     202,   270,   204,   205,   206,   178,    -1,   188,    -1,    -1,
     243,    92,    -1,    -1,    -1,   217,    -1,   198,   220,    -1,
     222,   102,   103,   104,    -1,    -1,    -1,    -1,   190,   231,
     203,   264,    -1,    -1,   148,   237,   209,    -1,    -1,    -1,
      -1,    -1,    -1,   245,   246,   247,   208,   249,   162,   163,
     164,    -1,    -1,   255,    -1,    -1,   258,    -1,    -1,    -1,
      -1,   175,   176,   177,   226,   267,   180,   240,    -1,    -1,
     251,    -1,    -1,    11,    -1,    -1,   257,   191,   192,    17,
      18,    19,    20,    21,    22,    -1,    24,    -1,    -1,    -1,
     263,    -1,    -1,   266,    -1,    -1,   269,    -1,   260,    -1,
     262,    -1,    -1,    -1,   218,     3,     4,     5,     6,     7,
       8,     9,    10,   227,    -1,    -1,   230,    -1,    -1,    -1,
     232,    -1,    -1,   204,   205,   206,    -1,    -1,    -1,    -1,
     242,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   220,
      -1,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   265,    -1,    -1,    -1,    -1,   237,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   245,   246
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    43,
      62,    63,    64,    65,    66,    67,    77,    78,    79,    80,
      81,     0,    37,    44,    45,    62,    17,   101,   101,   101,
     101,    62,   101,   101,   101,   101,    45,    50,   101,    11,
     102,   102,   102,   102,   102,   102,   102,   102,   101,    15,
     106,    96,   101,    12,   103,    99,   101,    98,   101,    96,
     103,    99,    98,    41,    51,    52,   106,    38,    46,    47,
     103,    28,   108,   106,   103,   103,   108,   103,   102,   103,
     103,   101,    23,    25,    53,    60,    92,    95,   101,    16,
     107,   102,   106,   101,    32,    34,    36,    68,    71,    74,
      76,   101,   106,   106,   106,   101,   102,    18,    19,    20,
      21,    22,    24,    82,    87,    88,    89,    91,    93,   100,
     101,   102,   102,   102,   106,    40,    54,    56,   101,    13,
      61,   104,    39,    48,    68,   108,   107,   102,   102,   102,
      31,    69,    73,   102,   104,    68,    68,    68,    82,   103,
      26,    27,    29,    83,    86,    90,    94,   104,    92,   101,
      82,   102,    82,    82,    82,    53,   107,    60,    30,    72,
      14,   105,   104,   107,   101,    82,    82,    82,    82,    82,
      84,    82,   107,   107,   107,   103,    87,   101,   101,    87,
     104,   102,    84,   103,   103,   103,    54,    50,   101,    53,
     105,    97,   108,   103,   103,   103,    72,    85,   108,   103,
     105,   102,   105,    82,   103,   103,   107,   102,   101,   101,
      72,    68,    68,    68,    82,    72,    73,    84,   105,    50,
      57,    60,   103,    97,    68,    33,    70,    75,    68,    85,
      82,   103,   103,   101,   106,    68,    72,   106,    58,   108,
      49,    71,    68,    68,    55,    60,    68,   101,    60,   107,
     102,    35,    59,   101,   101,    82,    82,    72,    58,   103,
      72,    55,    72,   107,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      50,    51,    51,    52,    53,    53,    54,    54,    55,    55,
      56,    57,    57,    58,    58,    59,    60,    60,    60,    61,
      61,    62,    62,    62,    63,    63,    63,    63,    64,    65,
      66,    67,    68,    68,    68,    68,    68,    68,    69,    69,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    77,
      77,    77,    78,    79,    80,    81,    82,    82,    83,    83,
      83,    83,    83,    84,    84,    85,    85,    86,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     5,     1,    10,     1,     1,     5,     3,
       0,     7,     5,     1,     4,     0,    13,     0,     4,     1,
       1,     3,     0,     4,     0,     1,     2,     1,     1,     2,
       0,     2,     2,     0,     8,     7,     8,     8,     1,     1,
       1,     1,     3,     6,     6,     2,     6,     0,     4,     7,
       4,     3,     1,     1,     1,     1,     1,     1,     8,     7,
       8,     8,     1,     1,     1,     1,     2,     4,     2,     3,
       1,     5,     0,     2,     0,     3,     0,     1,     1,     1,
       1,     1,     5,     4,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     6,     3,     0,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 110 "A1.y"
                                                          {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
    PrintList((yyval.list));
    Free((yyval.list));
}
#line 1620 "A1.tab.c"
    break;

  case 3:
#line 117 "A1.y"
                                                             {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate ((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))))));
}
#line 1629 "A1.tab.c"
    break;

  case 4:
#line 121 "A1.y"
                  { 
    MakeNull((yyval.list));
    Insert((yyval.list), "class ");
}
#line 1638 "A1.tab.c"
    break;

  case 5:
#line 126 "A1.y"
                                                                                                                             {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-9].list), Concatenate((yyvsp[-8].list), Concatenate((yyvsp[-7].list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))))))));
}
#line 1647 "A1.tab.c"
    break;

  case 6:
#line 130 "A1.y"
                                      { 
    MakeNull((yyval.list));
    Insert((yyval.list), "public static void main ");
 }
#line 1656 "A1.tab.c"
    break;

  case 7:
#line 134 "A1.y"
                     { 
    MakeNull((yyval.list));
    Insert((yyval.list), "String ");
}
#line 1665 "A1.tab.c"
    break;

  case 8:
#line 139 "A1.y"
                                                                        {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))))));
}
#line 1674 "A1.tab.c"
    break;

  case 9:
#line 144 "A1.y"
                                                       {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
}
#line 1683 "A1.tab.c"
    break;

  case 10:
#line 148 "A1.y"
                           { 
                           MakeNull((yyval.list));
                        }
#line 1691 "A1.tab.c"
    break;

  case 11:
#line 152 "A1.y"
                                                                                                         {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))))))));
}
#line 1700 "A1.tab.c"
    break;

  case 12:
#line 156 "A1.y"
                                                                                      {
                MakeNull((yyval.list));
                Concatenate((yyval.list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))); 
            }
#line 1709 "A1.tab.c"
    break;

  case 13:
#line 161 "A1.y"
                   { 
    MakeNull((yyval.list));
    Insert((yyval.list), "extends ");
 }
#line 1718 "A1.tab.c"
    break;

  case 14:
#line 166 "A1.y"
                                                      {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))));
}
#line 1727 "A1.tab.c"
    break;

  case 15:
#line 169 "A1.y"
    { 
    MakeNull((yyval.list));
}
#line 1735 "A1.tab.c"
    break;

  case 16:
#line 179 "A1.y"
                                                                                                                                                                      {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-12].list), Concatenate((yyvsp[-11].list), Concatenate((yyvsp[-10].list), Concatenate((yyvsp[-9].list), Concatenate((yyvsp[-8].list), Concatenate((yyvsp[-7].list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))))))))))))));
}
#line 1744 "A1.tab.c"
    break;

  case 17:
#line 183 "A1.y"
                 {
                   MakeNull((yyval.list));
                }
#line 1752 "A1.tab.c"
    break;

  case 18:
#line 187 "A1.y"
                                                                                {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))));
}
#line 1761 "A1.tab.c"
    break;

  case 19:
#line 191 "A1.y"
                                      {
                              MakeNull((yyval.list));
                              Concatenate((yyval.list), (yyvsp[0].list));
                          }
#line 1770 "A1.tab.c"
    break;

  case 20:
#line 196 "A1.y"
                 { 
    MakeNull((yyval.list));
    Insert((yyval.list), "public ");
}
#line 1779 "A1.tab.c"
    break;

  case 21:
#line 200 "A1.y"
                                                {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
}
#line 1788 "A1.tab.c"
    break;

  case 22:
#line 204 "A1.y"
                   { 
                     MakeNull((yyval.list)); }
#line 1795 "A1.tab.c"
    break;

  case 23:
#line 206 "A1.y"
                                                  {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))));
}
#line 1804 "A1.tab.c"
    break;

  case 24:
#line 209 "A1.y"
    { 
    MakeNull((yyval.list));
}
#line 1812 "A1.tab.c"
    break;

  case 25:
#line 212 "A1.y"
                 { 
    MakeNull((yyval.list));
    Insert((yyval.list), "return ");
}
#line 1821 "A1.tab.c"
    break;

  case 26:
#line 217 "A1.y"
                       {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)));
}
#line 1830 "A1.tab.c"
    break;

  case 27:
#line 221 "A1.y"
               {
         MakeNull((yyval.list));
         Concatenate((yyval.list), (yyvsp[0].list));
     }
#line 1839 "A1.tab.c"
    break;

  case 28:
#line 225 "A1.y"
                  {
         MakeNull((yyval.list));
         Concatenate((yyval.list), (yyvsp[0].list));
     }
#line 1848 "A1.tab.c"
    break;

  case 29:
#line 230 "A1.y"
                                  {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)));
}
#line 1857 "A1.tab.c"
    break;

  case 30:
#line 234 "A1.y"
              { MakeNull((yyval.list));}
#line 1863 "A1.tab.c"
    break;

  case 31:
#line 237 "A1.y"
                                                     {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)));
}
#line 1872 "A1.tab.c"
    break;

  case 32:
#line 241 "A1.y"
                                                    {
                    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)));
                }
#line 1881 "A1.tab.c"
    break;

  case 33:
#line 245 "A1.y"
                  { 
                    MakeNull((yyval.list));}
#line 1888 "A1.tab.c"
    break;

  case 34:
#line 248 "A1.y"
                                                                                                      {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-7].list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))))));
}
#line 1897 "A1.tab.c"
    break;

  case 35:
#line 252 "A1.y"
                                                                                              {
                       MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))))))));
                   }
#line 1906 "A1.tab.c"
    break;

  case 36:
#line 256 "A1.y"
                                                                                                     {
                       MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-7].list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))))));
                   }
#line 1915 "A1.tab.c"
    break;

  case 37:
#line 260 "A1.y"
                                                                                                      {
                       MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-7].list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))))));
                   }
#line 1924 "A1.tab.c"
    break;

  case 38:
#line 265 "A1.y"
                           { 
    MakeNull((yyval.list));
    Insert((yyval.list), "#defineStmt ");
 }
#line 1933 "A1.tab.c"
    break;

  case 39:
#line 269 "A1.y"
                            { 
    MakeNull((yyval.list));
    Insert((yyval.list), "#defineStmt0 ");
}
#line 1942 "A1.tab.c"
    break;

  case 40:
#line 273 "A1.y"
                             { 
    MakeNull((yyval.list));
    Insert((yyval.list), "#defineStmt1 ");}
#line 1950 "A1.tab.c"
    break;

  case 41:
#line 276 "A1.y"
                             { 
    MakeNull((yyval.list));
    Insert((yyval.list), "#defineStmt2 ");
}
#line 1959 "A1.tab.c"
    break;

  case 42:
#line 281 "A1.y"
                                           {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
}
#line 1968 "A1.tab.c"
    break;

  case 43:
#line 285 "A1.y"
                                                                       {
               MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))));
           }
#line 1977 "A1.tab.c"
    break;

  case 44:
#line 289 "A1.y"
                                                                  {
               MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))));
           }
#line 1986 "A1.tab.c"
    break;

  case 45:
#line 293 "A1.y"
                                            {
               MakeNull((yyval.list));
               Concatenate((yyval.list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)));
           }
#line 1995 "A1.tab.c"
    break;

  case 46:
#line 297 "A1.y"
                                                                      {
               MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))));
           }
#line 2004 "A1.tab.c"
    break;

  case 47:
#line 301 "A1.y"
             { MakeNull((yyval.list));}
#line 2010 "A1.tab.c"
    break;

  case 48:
#line 303 "A1.y"
                                                            {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))));
}
#line 2019 "A1.tab.c"
    break;

  case 49:
#line 307 "A1.y"
                                                                                           {
                        MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))))))));
                    }
#line 2028 "A1.tab.c"
    break;

  case 50:
#line 311 "A1.y"
                                                                      {
                        MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))));
                    }
#line 2037 "A1.tab.c"
    break;

  case 51:
#line 316 "A1.y"
                                    {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
}
#line 2046 "A1.tab.c"
    break;

  case 52:
#line 321 "A1.y"
                             { 
    MakeNull((yyval.list));
    Insert((yyval.list), "System.out.println");
}
#line 2055 "A1.tab.c"
    break;

  case 53:
#line 325 "A1.y"
                        { 
    MakeNull((yyval.list));
    Insert((yyval.list), ";\n");
 }
#line 2064 "A1.tab.c"
    break;

  case 54:
#line 329 "A1.y"
                    { 
    MakeNull((yyval.list));
    Insert((yyval.list), "=");
}
#line 2073 "A1.tab.c"
    break;

  case 55:
#line 333 "A1.y"
                { 
    MakeNull((yyval.list));
    Insert((yyval.list), "if");
}
#line 2082 "A1.tab.c"
    break;

  case 56:
#line 337 "A1.y"
                  { 
    MakeNull((yyval.list));
    Insert((yyval.list), "else");
}
#line 2091 "A1.tab.c"
    break;

  case 57:
#line 341 "A1.y"
                  { 
    MakeNull((yyval.list));
    Insert((yyval.list), "while");
}
#line 2100 "A1.tab.c"
    break;

  case 58:
#line 348 "A1.y"
                                                                                                        {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-7].list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))))));
}
#line 2109 "A1.tab.c"
    break;

  case 59:
#line 352 "A1.y"
                                                                                               {
                       MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list),(yyvsp[0].list))))))));
                   }
#line 2118 "A1.tab.c"
    break;

  case 60:
#line 356 "A1.y"
                                                                                                      {
                       MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-7].list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))))));
                   }
#line 2127 "A1.tab.c"
    break;

  case 61:
#line 360 "A1.y"
                                                                                                       {
                       MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-7].list), Concatenate((yyvsp[-6].list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))))));
                   }
#line 2136 "A1.tab.c"
    break;

  case 62:
#line 365 "A1.y"
                            { 
    MakeNull((yyval.list));
    Insert((yyval.list), "#defineExpr ");
 }
#line 2145 "A1.tab.c"
    break;

  case 63:
#line 369 "A1.y"
                              { 
    MakeNull((yyval.list));
    Insert((yyval.list), "#defineExpr0 ");
}
#line 2154 "A1.tab.c"
    break;

  case 64:
#line 373 "A1.y"
                              { 
    MakeNull((yyval.list));
    Insert((yyval.list), "#defineExpr1 ");
}
#line 2163 "A1.tab.c"
    break;

  case 65:
#line 377 "A1.y"
                             { 
    MakeNull((yyval.list));
    Insert((yyval.list), "#defineExpr2 ");
}
#line 2172 "A1.tab.c"
    break;

  case 66:
#line 382 "A1.y"
                                             {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)));
}
#line 2181 "A1.tab.c"
    break;

  case 67:
#line 386 "A1.y"
                                                              {
               MakeNull((yyval.list));
               Concatenate((yyval.list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))));
           }
#line 2190 "A1.tab.c"
    break;

  case 68:
#line 391 "A1.y"
                                            {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)));
}
#line 2199 "A1.tab.c"
    break;

  case 69:
#line 395 "A1.y"
                                                      {
                  MakeNull((yyval.list));
                  Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
              }
#line 2208 "A1.tab.c"
    break;

  case 70:
#line 399 "A1.y"
                       {
                  MakeNull((yyval.list));
                  Concatenate((yyval.list), (yyvsp[0].list));
              }
#line 2217 "A1.tab.c"
    break;

  case 71:
#line 403 "A1.y"
                                                                     {
                  MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list),(yyvsp[0].list))))));
              }
#line 2226 "A1.tab.c"
    break;

  case 72:
#line 407 "A1.y"
                { MakeNull((yyval.list));}
#line 2232 "A1.tab.c"
    break;

  case 73:
#line 409 "A1.y"
                                                  {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)));
}
#line 2241 "A1.tab.c"
    break;

  case 74:
#line 413 "A1.y"
                    { MakeNull((yyval.list)); }
#line 2247 "A1.tab.c"
    break;

  case 75:
#line 414 "A1.y"
                                                         {
                        MakeNull((yyval.list));
                        Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
                    }
#line 2256 "A1.tab.c"
    break;

  case 76:
#line 418 "A1.y"
                    { MakeNull((yyval.list)); }
#line 2262 "A1.tab.c"
    break;

  case 77:
#line 420 "A1.y"
                      {
    MakeNull((yyval.list));
    Insert((yyval.list), (yyvsp[0].string));
            }
#line 2271 "A1.tab.c"
    break;

  case 78:
#line 425 "A1.y"
                            {
    MakeNull((yyval.list));
    Concatenate((yyval.list), (yyvsp[0].list));
}
#line 2280 "A1.tab.c"
    break;

  case 79:
#line 429 "A1.y"
                            {
                      MakeNull((yyval.list));
    Concatenate((yyval.list), (yyvsp[0].list));
                  }
#line 2289 "A1.tab.c"
    break;

  case 80:
#line 433 "A1.y"
                               {
                      MakeNull((yyval.list));
    Concatenate((yyval.list), (yyvsp[0].list));
                  }
#line 2298 "A1.tab.c"
    break;

  case 81:
#line 437 "A1.y"
                         {
                      MakeNull((yyval.list));
    Concatenate((yyval.list), (yyvsp[0].list));
                  }
#line 2307 "A1.tab.c"
    break;

  case 82:
#line 441 "A1.y"
                                                           {
                      MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))))));
                  }
#line 2316 "A1.tab.c"
    break;

  case 83:
#line 445 "A1.y"
                                                       {
                      MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))));
                  }
#line 2325 "A1.tab.c"
    break;

  case 84:
#line 449 "A1.y"
                                   {
                      MakeNull((yyval.list));
                      Concatenate((yyval.list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)));
                  }
#line 2334 "A1.tab.c"
    break;

  case 85:
#line 453 "A1.y"
                                                   {
                      MakeNull((yyval.list));
                      Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
                  }
#line 2343 "A1.tab.c"
    break;

  case 86:
#line 458 "A1.y"
               {
            MakeNull((yyval.list));
            Insert((yyval.list), "true ");
        }
#line 2352 "A1.tab.c"
    break;

  case 87:
#line 462 "A1.y"
                {
           MakeNull((yyval.list));
           Insert((yyval.list), "false ");
        }
#line 2361 "A1.tab.c"
    break;

  case 88:
#line 467 "A1.y"
             { 
    MakeNull((yyval.list));
    Insert((yyval.list), "this");
 }
#line 2370 "A1.tab.c"
    break;

  case 89:
#line 471 "A1.y"
                 { 
    MakeNull((yyval.list));
    Insert((yyval.list), ".length ");
}
#line 2379 "A1.tab.c"
    break;

  case 90:
#line 475 "A1.y"
           { 
    MakeNull((yyval.list));
    Insert((yyval.list), "new ");
 }
#line 2388 "A1.tab.c"
    break;

  case 91:
#line 479 "A1.y"
           { 
    MakeNull((yyval.list));
    Insert((yyval.list), "int ");
 }
#line 2397 "A1.tab.c"
    break;

  case 92:
#line 483 "A1.y"
           { 
    MakeNull((yyval.list));
    Insert((yyval.list), "!");
 }
#line 2406 "A1.tab.c"
    break;

  case 93:
#line 487 "A1.y"
          { 
    MakeNull((yyval.list));
    Insert((yyval.list), ".");
 }
#line 2415 "A1.tab.c"
    break;

  case 94:
#line 491 "A1.y"
                  { 
    MakeNull((yyval.list));
    Insert((yyval.list), "boolean ");
}
#line 2424 "A1.tab.c"
    break;

  case 95:
#line 496 "A1.y"
                                                                  {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-5].list), Concatenate((yyvsp[-4].list), Concatenate((yyvsp[-3].list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list)))))));
}
#line 2433 "A1.tab.c"
    break;

  case 96:
#line 502 "A1.y"
                                      {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
}
#line 2442 "A1.tab.c"
    break;

  case 97:
#line 506 "A1.y"
            {
    MakeNull((yyval.list));
}
#line 2450 "A1.tab.c"
    break;

  case 98:
#line 510 "A1.y"
                                        {
    MakeNull((yyval.list));
    Concatenate((yyval.list), Concatenate((yyvsp[-2].list), Concatenate((yyvsp[-1].list), (yyvsp[0].list))));
}
#line 2459 "A1.tab.c"
    break;

  case 99:
#line 515 "A1.y"
                       {
    MakeNull((yyval.list));
    Concatenate((yyval.list), (yyvsp[0].list));
}
#line 2468 "A1.tab.c"
    break;

  case 100:
#line 520 "A1.y"
                          {
               MakeNull((yyval.list));
               Insert((yyval.list), (yyvsp[0].string));
            }
#line 2477 "A1.tab.c"
    break;

  case 101:
#line 524 "A1.y"
                        {
               MakeNull((yyval.list));
               Insert((yyval.list), (yyvsp[0].string));
            }
#line 2486 "A1.tab.c"
    break;

  case 102:
#line 528 "A1.y"
                               {
                MakeNull((yyval.list));
                Insert((yyval.list), "( ");
            }
#line 2495 "A1.tab.c"
    break;

  case 103:
#line 532 "A1.y"
                                {
                MakeNull((yyval.list));
                Insert((yyval.list), ") ");
            }
#line 2504 "A1.tab.c"
    break;

  case 104:
#line 536 "A1.y"
                             {
                MakeNull((yyval.list));
                Insert((yyval.list), "[ ");
            }
#line 2513 "A1.tab.c"
    break;

  case 105:
#line 540 "A1.y"
                              {
                MakeNull((yyval.list));
                Insert((yyval.list), "] ");
            }
#line 2522 "A1.tab.c"
    break;

  case 106:
#line 544 "A1.y"
                              {
                MakeNull((yyval.list));
                Insert((yyval.list), "\n{\n");
            }
#line 2531 "A1.tab.c"
    break;

  case 107:
#line 548 "A1.y"
                               {
                MakeNull((yyval.list));
                Insert((yyval.list), "\n}\n");
            }
#line 2540 "A1.tab.c"
    break;

  case 108:
#line 552 "A1.y"
                  {
                MakeNull((yyval.list));
                Insert((yyval.list), ", ");
            }
#line 2549 "A1.tab.c"
    break;


#line 2553 "A1.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 556 "A1.y"






int yyerror()
{
    printf("//Failed to parse input code\n");
    return 0;  
}

int main()
{
    // #ifdef YYDEBUG
    // yydebug = 1;  
    // #endif
    yyparse();
    return 0;
}
