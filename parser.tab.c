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
#line 1 "parser.y"

    /*Definition section */
    #include "common.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include<string.h>
    #include <stdarg.h>
    #include "parser.h"

    #include "symbolTable.h"
    extern FILE *yyin;
    extern int yylex(void);
    void yyerror(const char *str);
    void read_file(char *filename);
    FILE* errorsFile;
    //Quadraples data:
    FILE* OutputQuadraplesFile;
    int Labels;
    int CaseLabels;
    int EndSwitchLabel;
    int EnumValue;

    nodeType *operation(int oper, int nops, ...);
    nodeType *identifier(char *name);
    nodeType *constantInteger(int value);
    nodeType *constantFloat(float value);
    nodeType *constantBool(bool value);
    nodeType *constantChar(char value);
    nodeType *constantString(char *value);
    nodeType *defineType(typeEnum type);
    typeEnum checkCompatibility(typeEnum type1, typeEnum type2);
    typeEnum execute(nodeType *p);
    typeEnum getIdentifierType(char* identifierName);

    void freeNode(nodeType *p);

    symbolTable* st = new symbolTable();
    Node *currentScope = new Node();
    Node *rootScope = currentScope;
    //printing may be removed
    // extern char* last_token;

#line 113 "parser.tab.c"

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
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 44 "parser.y"

        #include "parser.h"

#line 160 "parser.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    FOR = 260,
    WHILE = 261,
    DO = 262,
    SWITCH = 263,
    CASE = 264,
    BREAK = 265,
    RETURN = 266,
    ENUM = 267,
    VOID = 268,
    INT_TYPE = 269,
    CHAR_TYPE = 270,
    BOOL_TYPE = 271,
    FLOAT_TYPE = 272,
    STRING_TYPE = 273,
    CONST = 274,
    PRINT = 275,
    EE = 276,
    NE = 277,
    GE = 278,
    LE = 279,
    AND = 280,
    OR = 281,
    INTEGER = 282,
    FLOAT = 283,
    BOOL_FALSE = 284,
    BOOL_TRUE = 285,
    CHAR = 286,
    STRING = 287,
    VARIABLE = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 49 "parser.y"

    int integer_val;
    char* string_val;
    float float_val;
    char char_val;
    bool bool_val;
    nodeType* node;

#line 214 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   481

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  184

#define YYUNDEFTOK  2
#define YYMAXUTOK   288


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
       2,     2,     2,    48,     2,     2,     2,    47,     2,     2,
      35,    36,    45,    43,    49,    44,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    34,
      42,    40,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,    38,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    80,    80,    84,    88,    93,    96,   101,   106,   115,
     120,   126,   131,   140,   144,   150,   156,   161,   167,   172,
     177,   186,   192,   199,   206,   211,   215,   219,   224,   231,
     235,   241,   245,   251,   255,   259,   265,   269,   273,   277,
     281,   287,   291,   295,   301,   305,   309,   313,   319,   323,
     327,   333,   337,   341,   345,   352,   358,   362,   368,   373,
     378,   382,   388,   393,   398,   402,   408,   412,   418,   424,
     430,   434,   438,   442,   449,   453,   457,   461,   465,   471,
     475,   479,   483,   487,   491
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "DO",
  "SWITCH", "CASE", "BREAK", "RETURN", "ENUM", "VOID", "INT_TYPE",
  "CHAR_TYPE", "BOOL_TYPE", "FLOAT_TYPE", "STRING_TYPE", "CONST", "PRINT",
  "EE", "NE", "GE", "LE", "AND", "OR", "INTEGER", "FLOAT", "BOOL_FALSE",
  "BOOL_TRUE", "CHAR", "STRING", "VARIABLE", "';'", "'('", "')'", "'{'",
  "'}'", "':'", "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'!'", "','", "$accept", "program", "root", "statement",
  "recursive_statement", "conditional_statement",
  "if_conditional_statement", "switch_conditional_statement",
  "case_statement", "loop_statement", "for_loop_statement",
  "while_loop_statement", "do_while_loop_statement", "assignment",
  "expressions", "first", "second", "third", "fourth", "fifth", "sixth",
  "seventh", "function_call", "functional_statement",
  "function_parameters", "parameter", "function_parameters_calls",
  "parameter_calls", "function", "return_types", "enum_statement",
  "enum_variables", "variable_Type", "variable_value", YY_NULLPTR
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
     285,   286,   287,   288,    59,    40,    41,   123,   125,    58,
      61,    62,    60,    43,    45,    42,    47,    37,    33,    44
};
# endif

#define YYPACT_NINF (-60)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -60,    18,    33,   -60,   -11,    21,    24,    32,    36,    47,
      53,   -60,   -60,   -60,   -60,   -60,   137,   -60,   -60,   -60,
     -60,   -60,   -60,    38,   -21,   -21,   -21,   -60,   -60,   -60,
     -60,   -60,   -60,   -60,   -60,    57,    41,    68,    22,    34,
      46,    37,   -60,   -60,   -60,   -60,   -60,   -60,    62,   -60,
     -21,   433,   -21,   -60,    66,     0,    71,    70,   -21,   -21,
      73,    -7,   -60,   -60,   -60,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,    39,    -6,
      76,    67,    77,    -5,   112,    80,    81,    89,   137,    85,
      41,   101,    99,    41,   -60,    68,    22,    34,    34,    46,
      46,    46,    46,    37,    37,   -60,   -60,   -60,   137,   -21,
     120,   116,   -21,   118,   128,   160,   -60,   130,   136,   142,
     -33,   154,   143,   162,   -21,   -60,   -21,   157,    41,   -60,
      -9,   -60,   161,   -60,   -60,   -21,   -60,   164,   165,   137,
     -60,    41,    41,   172,   156,   433,   200,   -21,     4,    41,
     158,   -60,   166,   -60,   197,   174,   -60,    -4,   149,   -60,
     -21,   244,   -60,   288,   176,   183,   -60,   182,    41,   -60,
     -21,   -60,   -60,   -60,    41,   177,   323,   367,   411,   184,
     -60,   -60,   -60,   -60
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,    84,    53,     0,     0,     0,     3,     6,    12,
      11,     7,    18,    19,    20,     0,    28,    30,    32,    35,
      40,    43,    47,    50,    54,     4,    56,    57,     0,    52,
       0,     0,     0,    10,     0,     0,     0,     0,    63,     0,
      53,     0,    48,    49,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    59,     0,
      65,     0,    62,    25,    51,    29,    31,    33,    34,    38,
      39,    36,    37,    41,    42,    44,    45,    46,    59,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,    73,
       0,     0,    58,     0,     0,    55,     0,     0,    24,    10,
       0,    10,     0,    17,    26,     0,    69,     0,     0,     0,
      61,    27,    64,     0,     0,     0,     0,     0,     0,    72,
      71,    10,     0,    10,    14,     0,    22,     0,     0,    15,
       0,     0,    60,     0,     0,     0,    23,     0,    70,    67,
       0,    10,    10,    10,    68,     0,     0,     0,     0,     0,
      13,    21,    16,    66
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -60,   -60,   -60,   221,   -59,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,   -60,   -49,   -24,   159,   168,    30,    63,    31,
     -22,   -60,   -60,   -60,   117,   -60,   -60,   -60,   -60,   -60,
     -60,   -60,    -1,    78
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   116,    84,    28,    29,    30,   148,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,   121,   122,    91,    92,    46,   175,
      47,   120,    82,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,    48,    81,    62,    63,   136,    17,    18,    19,    20,
      21,    22,    60,   158,    24,    57,   137,    65,     3,    65,
      65,    65,    65,    25,    50,   145,    79,    26,    83,    94,
     110,   114,   166,    86,    90,    93,     4,    87,     5,     6,
       7,     8,   159,    67,    68,     9,    10,    11,    12,    13,
      14,    15,    16,   105,   106,   107,    51,    69,    70,    52,
      17,    18,    19,    20,    21,    22,    23,    65,    24,    53,
     144,    54,   146,    58,   108,    71,    72,    25,    59,   109,
      55,    26,    75,    76,    77,   128,    56,   123,   130,    73,
      74,    64,   161,    66,   163,    78,   155,    97,    98,    85,
     141,   112,   142,    89,   103,   104,    88,   123,    58,   111,
     113,   149,   176,   177,   178,     4,   117,     5,     6,     7,
       8,   118,   119,   157,    80,   124,    11,    12,    13,    14,
      15,    16,    99,   100,   101,   102,   168,   125,   152,    17,
      18,    19,    20,    21,    22,    23,   174,    24,   126,    86,
     115,    11,    12,    13,    14,    15,    25,   129,   109,     4,
      26,     5,     6,     7,     8,   131,   132,   133,    80,   134,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,   135,    17,    18,    19,    20,    21,    22,    23,
     138,    24,   139,   143,   154,   140,   147,   150,   160,   162,
      25,   164,   151,     4,    26,     5,     6,     7,     8,   153,
     165,   179,    80,   171,    11,    12,    13,    14,    15,    16,
     172,   173,   183,    27,    95,   127,     0,    17,    18,    19,
      20,    21,    22,    23,    96,    24,   167,     0,   156,     0,
       0,     0,     0,     0,    25,     0,     0,     4,    26,     5,
       6,     7,     8,     0,     0,     0,    80,     0,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    21,    22,    23,     0,    24,
       0,     0,   169,     0,     0,     0,     0,     0,    25,     0,
       0,     4,    26,     5,     6,     7,     8,     0,     0,   170,
      80,     0,    11,    12,    13,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
      22,    23,     0,    24,     0,     0,     4,     0,     5,     6,
       7,     8,    25,     0,     0,    80,    26,    11,    12,    13,
      14,    15,    16,     0,     0,     0,     0,     0,     0,     0,
      17,    18,    19,    20,    21,    22,    23,     0,    24,     0,
       0,   180,     0,     0,     0,     0,     0,    25,     0,     0,
       4,    26,     5,     6,     7,     8,     0,     0,     0,    80,
       0,    11,    12,    13,    14,    15,    16,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,    22,
      23,     0,    24,     0,     0,   181,     0,     0,     0,     0,
       0,    25,     0,     0,     4,    26,     5,     6,     7,     8,
       0,   182,     0,    80,     0,    11,    12,    13,    14,    15,
      16,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,    22,    23,    80,    24,    11,    12,    13,
      14,    15,    16,     0,     0,    25,     0,     0,     0,    26,
      17,    18,    19,    20,    21,    22,    23,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26
};

static const yytype_int16 yycheck[] =
{
      24,     2,    51,    25,    26,    38,    27,    28,    29,    30,
      31,    32,    33,     9,    35,    16,    49,    26,     0,    26,
      26,    26,    26,    44,    35,    34,    50,    48,    52,    36,
      36,    36,    36,    33,    58,    59,     3,    37,     5,     6,
       7,     8,    38,    21,    22,    12,    13,    14,    15,    16,
      17,    18,    19,    75,    76,    77,    35,    23,    24,    35,
      27,    28,    29,    30,    31,    32,    33,    26,    35,    37,
     129,    35,   131,    35,    35,    41,    42,    44,    40,    40,
      33,    48,    45,    46,    47,   109,    33,    88,   112,    43,
      44,    34,   151,    25,   153,    33,   145,    67,    68,    33,
     124,    34,   126,    33,    73,    74,    35,   108,    35,    33,
      33,   135,   171,   172,   173,     3,    36,     5,     6,     7,
       8,    40,    33,   147,    12,    40,    14,    15,    16,    17,
      18,    19,    69,    70,    71,    72,   160,    36,   139,    27,
      28,    29,    30,    31,    32,    33,   170,    35,    49,    33,
      38,    14,    15,    16,    17,    18,    44,    37,    40,     3,
      48,     5,     6,     7,     8,    37,     6,    37,    12,    33,
      14,    15,    16,    17,    18,    19,    27,    28,    29,    30,
      31,    32,    40,    27,    28,    29,    30,    31,    32,    33,
      36,    35,    49,    36,    38,    33,    35,    33,    40,    33,
      44,     4,    37,     3,    48,     5,     6,     7,     8,    37,
      36,    34,    12,    37,    14,    15,    16,    17,    18,    19,
      37,    39,    38,     2,    65,   108,    -1,    27,    28,    29,
      30,    31,    32,    33,    66,    35,   158,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,     3,    48,     5,
       6,     7,     8,    -1,    -1,    -1,    12,    -1,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    33,    -1,    35,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,     3,    48,     5,     6,     7,     8,    -1,    -1,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    -1,    -1,     3,    -1,     5,     6,
       7,     8,    44,    -1,    -1,    12,    48,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
       3,    48,     5,     6,     7,     8,    -1,    -1,    -1,    12,
      -1,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,     3,    48,     5,     6,     7,     8,
      -1,    10,    -1,    12,    -1,    14,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,    28,
      29,    30,    31,    32,    33,    12,    35,    14,    15,    16,
      17,    18,    19,    -1,    -1,    44,    -1,    -1,    -1,    48,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     3,     5,     6,     7,     8,    12,
      13,    14,    15,    16,    17,    18,    19,    27,    28,    29,
      30,    31,    32,    33,    35,    44,    48,    53,    55,    56,
      57,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    78,    80,    82,    83,
      35,    35,    35,    37,    35,    33,    33,    82,    35,    40,
      33,    64,    70,    70,    34,    26,    25,    21,    22,    23,
      24,    41,    42,    43,    44,    45,    46,    47,    33,    64,
      12,    63,    82,    64,    54,    33,    33,    37,    35,    33,
      64,    76,    77,    64,    36,    65,    66,    67,    67,    68,
      68,    68,    68,    69,    69,    70,    70,    70,    35,    40,
      36,    33,    34,    33,    36,    38,    53,    36,    40,    33,
      81,    74,    75,    82,    40,    36,    49,    74,    64,    37,
      64,    37,     6,    37,    33,    40,    38,    49,    36,    49,
      33,    64,    64,    36,    54,    34,    54,    35,    58,    64,
      33,    37,    82,    37,    38,    63,    38,    64,     9,    38,
      40,    54,    33,    54,     4,    36,    36,    83,    64,    38,
      11,    37,    37,    39,    64,    79,    54,    54,    54,    34,
      38,    38,    10,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      59,    60,    61,    62,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    66,    66,    67,    67,    67,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    71,    71,    71,    71,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    80,
      81,    81,    81,    81,    82,    82,    82,    82,    82,    83,
      83,    83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     1,     1,     2,     2,
       0,     1,     1,    11,     7,     7,     6,     0,     1,     1,
       1,    11,     7,     8,     4,     3,     5,     5,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       1,     3,     1,     1,     1,     4,     1,     1,     1,     0,
       4,     2,     1,     0,     3,     1,    11,     8,     1,     5,
       5,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
#line 80 "parser.y"
              {printf("end of program\n");}
#line 1577 "parser.tab.c"
    break;

  case 3:
#line 85 "parser.y"
        {printf("root: root statement\n"); printf("-------------------------------------\n");
        execute((yyvsp[0].node));
        }
#line 1585 "parser.tab.c"
    break;

  case 4:
#line 89 "parser.y"
        {printf("root functional_statement\n"); printf("-------------------------------------\n");
        execute((yyvsp[0].node));
        }
#line 1593 "parser.tab.c"
    break;

  case 5:
#line 93 "parser.y"
        {printf("root: \n");}
#line 1599 "parser.tab.c"
    break;

  case 6:
#line 97 "parser.y"
            { printf("statement: conditional_statement\n");
            (yyval.node)=(yyvsp[0].node);
            }
#line 1607 "parser.tab.c"
    break;

  case 7:
#line 102 "parser.y"
            { printf("statement: loop_statement\n");
            (yyval.node)=(yyvsp[0].node);
            }
#line 1615 "parser.tab.c"
    break;

  case 8:
#line 107 "parser.y"
            { printf("statement: assignment;\n");
            (yyval.node)=(yyvsp[-1].node);
            }
#line 1623 "parser.tab.c"
    break;

  case 9:
#line 116 "parser.y"
                    {printf("recursive_statement: recursive_statement statement\n");
                    (yyval.node)=operation(';',2,(yyvsp[-1].node),(yyvsp[0].node));
                    }
#line 1631 "parser.tab.c"
    break;

  case 10:
#line 120 "parser.y"
                    {printf("recursive_statement: \n");
                    (yyval.node)=NULL;
                    }
#line 1639 "parser.tab.c"
    break;

  case 11:
#line 127 "parser.y"
                        {printf("conditional_statement: switch_conditional_statement\n");
                        (yyval.node)=(yyvsp[0].node);
                        }
#line 1647 "parser.tab.c"
    break;

  case 12:
#line 132 "parser.y"
                        {printf("conditional_statement: if_conditional_statement\n");
                        (yyval.node)=(yyvsp[0].node);
                        }
#line 1655 "parser.tab.c"
    break;

  case 13:
#line 141 "parser.y"
                            {printf("if_conditional_statement: if(exp){recursive_statement} else{recursive_statement}\n");
                            (yyval.node)=operation(IF,3,(yyvsp[-8].node),(yyvsp[-5].node),(yyvsp[-1].node));
                            }
#line 1663 "parser.tab.c"
    break;

  case 14:
#line 145 "parser.y"
                            {printf("if_conditional_statement: if(exp){recursive_statement}\n");
                            (yyval.node)=operation(IF,2,(yyvsp[-4].node),(yyvsp[-1].node));
                            }
#line 1671 "parser.tab.c"
    break;

  case 15:
#line 151 "parser.y"
                                {printf("switch_conditional_statement: switch(VARIABLE){case_statement}\n");
                                (yyval.node)=operation(SWITCH,2,identifier((yyvsp[-4].string_val)),(yyvsp[-1].node));
                                }
#line 1679 "parser.tab.c"
    break;

  case 16:
#line 157 "parser.y"
                {printf("case_statement: case_statement case variable_value: recursive_statement break\n");
                (yyval.node)=operation(CASE,3,(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node));
                }
#line 1687 "parser.tab.c"
    break;

  case 17:
#line 161 "parser.y"
                {printf("case_statement: \n");
                (yyval.node)=NULL;
                }
#line 1695 "parser.tab.c"
    break;

  case 18:
#line 168 "parser.y"
                {printf("loop_statement: for_loop_statement\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 1703 "parser.tab.c"
    break;

  case 19:
#line 173 "parser.y"
                {printf("loop_statement: while_loop_statement\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 1711 "parser.tab.c"
    break;

  case 20:
#line 178 "parser.y"
                {printf("loop_statement: do_while_loop_statement\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 1719 "parser.tab.c"
    break;

  case 21:
#line 187 "parser.y"
                    {printf("for_loop_statement: for(assignment; exp; assignment){recursive_statement}\n");
                    (yyval.node)=operation(FOR,4,(yyvsp[-8].node),(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node));
                    }
#line 1727 "parser.tab.c"
    break;

  case 22:
#line 193 "parser.y"
                    {printf("while_loop_statement: while(exp){recursive_statement}\n");
                    (yyval.node)=operation(WHILE,2,(yyvsp[-4].node),(yyvsp[-1].node));
                    }
#line 1735 "parser.tab.c"
    break;

  case 23:
#line 200 "parser.y"
                        {printf("do_while_loop_statement: do{recursive_statement} while{exp}\n");
                        (yyval.node)=operation(DO,2,(yyvsp[-5].node),(yyvsp[-1].node));
                        }
#line 1743 "parser.tab.c"
    break;

  case 24:
#line 207 "parser.y"
            {
            printf("assignment: variable_Type VARIABLE = exp\n");
            (yyval.node)=operation('=',3,(yyvsp[-3].node),identifier((yyvsp[-2].string_val)),(yyvsp[0].node));
            }
#line 1752 "parser.tab.c"
    break;

  case 25:
#line 212 "parser.y"
            {printf("assignment: VARIABLE = exp\n");
            (yyval.node)=operation('=',2,identifier((yyvsp[-2].string_val)),(yyvsp[0].node));
            }
#line 1760 "parser.tab.c"
    break;

  case 26:
#line 216 "parser.y"
            {printf("assignment: ENUM VARIABLE VARIABLE = VARIABLE\n");
            (yyval.node)=operation('=',4,defineType(EnumType),identifier((yyvsp[-3].string_val)),identifier((yyvsp[-2].string_val)),identifier((yyvsp[0].string_val)));
            }
#line 1768 "parser.tab.c"
    break;

  case 27:
#line 220 "parser.y"
            {
            printf("assignment: CONST variable_Type VARIABLE = exp\n");
            (yyval.node)=operation('=',4,defineType(ConstType),(yyvsp[-3].node),identifier((yyvsp[-2].string_val)),(yyvsp[0].node));
            }
#line 1777 "parser.tab.c"
    break;

  case 28:
#line 225 "parser.y"
            {printf("assignment: exp\n");
            (yyval.node) = (yyvsp[0].node);
            }
#line 1785 "parser.tab.c"
    break;

  case 29:
#line 232 "parser.y"
            {printf("exp: exp || first \n");
            (yyval.node)=operation(OR,2,(yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1793 "parser.tab.c"
    break;

  case 30:
#line 236 "parser.y"
            {printf("exp: first \n");
            (yyval.node)=(yyvsp[0].node);
            }
#line 1801 "parser.tab.c"
    break;

  case 31:
#line 242 "parser.y"
        {printf("first: first && second\n");
        (yyval.node)=operation(AND,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1809 "parser.tab.c"
    break;

  case 32:
#line 246 "parser.y"
        {printf("first: second\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1817 "parser.tab.c"
    break;

  case 33:
#line 252 "parser.y"
        {printf("second: second == third\n");
        (yyval.node)=operation(EE,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1825 "parser.tab.c"
    break;

  case 34:
#line 256 "parser.y"
        {printf("second: second != third\n");
        (yyval.node)=operation(NE,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1833 "parser.tab.c"
    break;

  case 35:
#line 260 "parser.y"
        {printf("second: third\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1841 "parser.tab.c"
    break;

  case 36:
#line 266 "parser.y"
        {printf("third: third > fourth\n");
        (yyval.node)=operation('>',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1849 "parser.tab.c"
    break;

  case 37:
#line 270 "parser.y"
        {printf("third: third < fourth\n");
        (yyval.node)=operation('<',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1857 "parser.tab.c"
    break;

  case 38:
#line 274 "parser.y"
        {printf("third: third >= fourth\n");
        (yyval.node)=operation(GE,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1865 "parser.tab.c"
    break;

  case 39:
#line 278 "parser.y"
        {printf("third: third <= fourth\n");
        (yyval.node)=operation(LE,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1873 "parser.tab.c"
    break;

  case 40:
#line 282 "parser.y"
        {printf("third: fourth\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1881 "parser.tab.c"
    break;

  case 41:
#line 288 "parser.y"
        {printf("fourth: fourth + fifth\n");
        (yyval.node)=operation('+',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1889 "parser.tab.c"
    break;

  case 42:
#line 292 "parser.y"
        {printf("fourth: fourth - fifth\n");
        (yyval.node)=operation('-',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1897 "parser.tab.c"
    break;

  case 43:
#line 296 "parser.y"
        {printf("fourth: fifth\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1905 "parser.tab.c"
    break;

  case 44:
#line 302 "parser.y"
        {printf("fifth: fifth * sixth\n");
        (yyval.node)=operation('*',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1913 "parser.tab.c"
    break;

  case 45:
#line 306 "parser.y"
        {printf("fifth: fifth / sixth\n");
        (yyval.node)=operation('/',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1921 "parser.tab.c"
    break;

  case 46:
#line 310 "parser.y"
        {printf("fifth: fifth %% sixth\n");
        (yyval.node)=operation('%',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1929 "parser.tab.c"
    break;

  case 47:
#line 314 "parser.y"
        {printf("fifth: sixth\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1937 "parser.tab.c"
    break;

  case 48:
#line 320 "parser.y"
        {printf("sixth: - sixth\n");
        (yyval.node)=operation('-',1,(yyvsp[0].node));
        }
#line 1945 "parser.tab.c"
    break;

  case 49:
#line 324 "parser.y"
        {printf("sixth: ! sixth\n");
        (yyval.node)=operation('!',1,(yyvsp[0].node));
        }
#line 1953 "parser.tab.c"
    break;

  case 50:
#line 328 "parser.y"
        {printf("sixth: seventh\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1961 "parser.tab.c"
    break;

  case 51:
#line 334 "parser.y"
        {printf("seventh: (exp)\n");
        (yyval.node)=(yyvsp[-1].node);
        }
#line 1969 "parser.tab.c"
    break;

  case 52:
#line 338 "parser.y"
        {printf("seventh: variable_value\n");
        (yyval.node) = (yyvsp[0].node);
        }
#line 1977 "parser.tab.c"
    break;

  case 53:
#line 342 "parser.y"
        {printf("seventh: VARIABLE\n");
        (yyval.node) = identifier((yyvsp[0].string_val));
        }
#line 1985 "parser.tab.c"
    break;

  case 54:
#line 346 "parser.y"
        {printf("seventh: function_call\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1993 "parser.tab.c"
    break;

  case 55:
#line 353 "parser.y"
                {printf("function_call: VARIABLE (function_parameters_calls)\n");
                (yyval.node)=operation('f',2,identifier((yyvsp[-3].string_val)),(yyvsp[-1].node));
                }
#line 2001 "parser.tab.c"
    break;

  case 56:
#line 359 "parser.y"
                    {printf("functional_statement: function\n");
                    (yyval.node)=(yyvsp[0].node);
                    }
#line 2009 "parser.tab.c"
    break;

  case 57:
#line 363 "parser.y"
                    {printf("functional_statement: enum_statement\n");
                    (yyval.node)=(yyvsp[0].node);
                    }
#line 2017 "parser.tab.c"
    break;

  case 58:
#line 369 "parser.y"
                    {printf("function_parameters: parameter\n");
                    (yyval.node)=(yyvsp[0].node);
                    }
#line 2025 "parser.tab.c"
    break;

  case 59:
#line 373 "parser.y"
                    {printf("function_parameters: \n");
                    (yyval.node)=NULL;
                    }
#line 2033 "parser.tab.c"
    break;

  case 60:
#line 379 "parser.y"
            {printf("parameter: parameter, variable_Type VARIABLE\n");
            (yyval.node)=operation('p',3,(yyvsp[-1].node),identifier((yyvsp[0].string_val)),(yyvsp[-3].node));
            }
#line 2041 "parser.tab.c"
    break;

  case 61:
#line 383 "parser.y"
            {printf("parameter: variable_Type VARIABLE\n");
            (yyval.node)=operation('p',2,(yyvsp[-1].node),identifier((yyvsp[0].string_val)));
            }
#line 2049 "parser.tab.c"
    break;

  case 62:
#line 389 "parser.y"
                            {printf("function_parameters_calls: parameter_calls\n");
                            (yyval.node)=(yyvsp[0].node);
                            }
#line 2057 "parser.tab.c"
    break;

  case 63:
#line 393 "parser.y"
                            {printf("function_parameters_calls: \n");
                            (yyval.node)=NULL;
                            }
#line 2065 "parser.tab.c"
    break;

  case 64:
#line 399 "parser.y"
                {printf("parameter_calls: parameter_calls, exp\n");
                (yyval.node)=operation('c',2,(yyvsp[-2].node),(yyvsp[0].node));
                }
#line 2073 "parser.tab.c"
    break;

  case 65:
#line 403 "parser.y"
                {printf("parameter_calls: exp\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 2081 "parser.tab.c"
    break;

  case 66:
#line 409 "parser.y"
        {printf("function: variable_Type  (function_parameters){recursive_statement RETURN return_types ;}\n");
        (yyval.node)=operation('d',5,(yyvsp[-10].node),identifier((yyvsp[-9].string_val)),(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
        }
#line 2089 "parser.tab.c"
    break;

  case 67:
#line 413 "parser.y"
        {printf("function: void VARIABLE (function_parameters) {recursive_statement}\n");
        (yyval.node)=operation('d',4,defineType(VoidType),identifier((yyvsp[-6].string_val)),(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 2097 "parser.tab.c"
    break;

  case 68:
#line 419 "parser.y"
                {printf("return_types: expressions\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 2105 "parser.tab.c"
    break;

  case 69:
#line 425 "parser.y"
                {printf("enum_statement: enum VARIABLE {enum_variables}\n");
                (yyval.node)=operation(ENUM,2,identifier((yyvsp[-3].string_val)),(yyvsp[-1].node));
                }
#line 2113 "parser.tab.c"
    break;

  case 70:
#line 431 "parser.y"
                {printf("enum_variables: enum_variables, VARIABLE = exp\n");
                (yyval.node)=operation(',',3,(yyvsp[-4].node),identifier((yyvsp[-2].string_val)),(yyvsp[0].node));
                }
#line 2121 "parser.tab.c"
    break;

  case 71:
#line 435 "parser.y"
                {printf("enum_variables: enum_variables, VARIABLE\n");
                (yyval.node)=operation(',',2,(yyvsp[-2].node),identifier((yyvsp[0].string_val)));
                }
#line 2129 "parser.tab.c"
    break;

  case 72:
#line 439 "parser.y"
                {printf("enum_variables:VARIABLE = exp\n");
                (yyval.node)=operation(',',2,identifier((yyvsp[-2].string_val)),(yyvsp[0].node));
                }
#line 2137 "parser.tab.c"
    break;

  case 73:
#line 443 "parser.y"
                {printf("enum_variables: VARIABLE\n");
                (yyval.node)=operation(',',1,identifier((yyvsp[0].string_val)));
                }
#line 2145 "parser.tab.c"
    break;

  case 74:
#line 450 "parser.y"
                {printf("variable_Type: int\n");
                (yyval.node) = defineType(IntType);
                }
#line 2153 "parser.tab.c"
    break;

  case 75:
#line 454 "parser.y"
                {printf("variable_Type: char\n");
                (yyval.node) = defineType(CharType);
                }
#line 2161 "parser.tab.c"
    break;

  case 76:
#line 458 "parser.y"
                {printf("variable_Type: bool\n");
                (yyval.node) = defineType(BoolType);
                }
#line 2169 "parser.tab.c"
    break;

  case 77:
#line 462 "parser.y"
                {printf("variable_Type: float\n");
                (yyval.node) = defineType(FloatType);
                }
#line 2177 "parser.tab.c"
    break;

  case 78:
#line 466 "parser.y"
                {printf("variable_Type: string\n");
                (yyval.node) = defineType(StringType);
                }
#line 2185 "parser.tab.c"
    break;

  case 79:
#line 472 "parser.y"
                {printf("variable_value: int value \n");
                (yyval.node) = constantInteger((yyvsp[0].integer_val));
                }
#line 2193 "parser.tab.c"
    break;

  case 80:
#line 476 "parser.y"
                {printf("variable_value: float value \n");
                (yyval.node) = constantFloat((yyvsp[0].float_val));
                }
#line 2201 "parser.tab.c"
    break;

  case 81:
#line 480 "parser.y"
                {printf("variable_value: false \n");
                (yyval.node) = constantBool((yyvsp[0].integer_val));
                }
#line 2209 "parser.tab.c"
    break;

  case 82:
#line 484 "parser.y"
                {printf("variable_value: true \n");
                (yyval.node) = constantBool((yyvsp[0].integer_val));
                }
#line 2217 "parser.tab.c"
    break;

  case 83:
#line 488 "parser.y"
                {printf("variable_value: char value \n");
                (yyval.node) = constantChar((yyvsp[0].char_val));
                }
#line 2225 "parser.tab.c"
    break;

  case 84:
#line 492 "parser.y"
                {printf("variable_value: string value \n");
                (yyval.node) = constantString((yyvsp[0].string_val));
                }
#line 2233 "parser.tab.c"
    break;


#line 2237 "parser.tab.c"

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
#line 498 "parser.y"


#define SIZEOF_NODETYPE ((char*)&p->constant - (char*)p)

nodeType *constantInteger(int value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.intVal = value;
    p->constant.constType = IntType;
    printf("constant integer: %d\n", value);
    return p;
}

nodeType *constantFloat(float value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.floatVal = value;
    p->constant.constType = FloatType;
    printf("constant float: %f\n", value);
    return p;
}

nodeType *constantBool(bool value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.boolVal = value;
    p->constant.constType = BoolType;
    printf("constant boolean: %d\n", value);
    return p;
}

nodeType *constantChar(char value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.charVal = value;
    p->constant.constType = CharType;
    printf("constant char: %c\n", value);
    return p;
}

nodeType *constantString(char* value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.stringVal = value;
    p->constant.constType = StringType;
    printf("constant string: %s\n", value);
    return p;
}

nodeType *defineType(typeEnum type) {
    nodeType *p;
    if ((p = (nodeType *)malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Type_Node;
    p->defineType.type = type;
    return p;
}

nodeType *identifier(char* i) {
    nodeType *p;
    if ((p = (nodeType *)malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Identifier_Node;
    p->identifier.name = i;
    return p;
}

nodeType *operation(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    if ((p = (nodeType* )malloc(sizeof(nodeType) + (nops - 1)*sizeof(nodeType*))) == NULL)
        yyerror("out of memory");
    p->type = Operator_Node;
    p->oper.oper = oper;
    p->oper.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->oper.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == Operator_Node) {
        for (i = 0; i < p->oper.nops; i++)
            freeNode(p->oper.op[i]);
    }
    free(p);
}

typeEnum execute(nodeType *p){

    if(p == NULL) return Error;
    switch(p->type)
    {
        case Constant_Node:
        {
            if(p->constant.constType == IntType)
            {
                EnumValue = p->constant.intVal;
                fprintf(OutputQuadraplesFile, "PUSH %d\n", p->constant.intVal);
            }
            else if(p->constant.constType == FloatType)
            {
                fprintf(OutputQuadraplesFile, "PUSH %f\n", p->constant.floatVal);
            }
            else if(p->constant.constType == StringType)
            {
                fprintf(OutputQuadraplesFile, "PUSH %s\n", p->constant.stringVal);
            }
            else if(p->constant.constType == BoolType)
            {
                if(p->constant.boolVal)
                {
                    fprintf(OutputQuadraplesFile, "PUSH true\n");
                }
                else
                {
                    fprintf(OutputQuadraplesFile, "PUSH false\n");
                }
                
            }
            else if(p->constant.constType == CharType)
            {
                fprintf(OutputQuadraplesFile, "PUSH %c\n", p->constant.charVal);
            }
            else if(p->constant.constType == EnumType)
            {
                //TODO:
                // fprintf(OutputQuadraplesFile, "PUSH %s\n", p->identifier.name);
            }

            //printf("Inside execute function check value!!!!!!!!: %d \n", p->constant.constType);
            return p->constant.constType;
            break;
        }

         //TODO: check if enums are ok, void func ?   
        case Identifier_Node:   
        {
            string typeIdentifier = st->checkType(p->identifier.name, currentScope);
            if(typeIdentifier == "integer")
            {
                fprintf(OutputQuadraplesFile, "PUSH %s\n", p->identifier.name);
                return IntType;
            }
            else if(typeIdentifier == "float")
            {
                fprintf(OutputQuadraplesFile, "PUSH %s\n", p->identifier.name);
                return FloatType;
            }
            else if(typeIdentifier == "string")
            {
                fprintf(OutputQuadraplesFile, "PUSH %s\n", p->identifier.name);
                return StringType;
            }
            else if(typeIdentifier == "boolean")
            {
                fprintf(OutputQuadraplesFile, "PUSH %s\n", p->identifier.name);
                return BoolType;
            }
            else if(typeIdentifier == "void")
            {
                return VoidType;
            }
            else if(typeIdentifier == "char")
            {
                fprintf(OutputQuadraplesFile, "PUSH %s\n", p->identifier.name);
                return CharType;
            }
            else if(typeIdentifier == "enum")
            {
                EnumValue = -1;
                return EnumType;
            }
            else if(typeIdentifier == "const")
            {
                fprintf(OutputQuadraplesFile, "PUSH %s\n", p->identifier.name);
                return ConstType;
            }
            else
            {
                yyerror("variable was not declared in this scope");
                return Error;
            }
            break;
        }

        case Type_Node:
        {
            return p->defineType.type;
            break;
        }

        case Operator_Node:
            switch(p->oper.oper){
                case IF: //TODO:
                {   
                    //call exec on operands
                    switch(p->oper.nops){
                        case 2:{
                            execute(p->oper.op[0]);
                            currentScope=st->switchScope(currentScope);
                            execute(p->oper.op[1]);
                            currentScope = st->switchBack(currentScope);
                            break;
                        }
                        case 3:{
                            execute(p->oper.op[0]);
                            currentScope=st->switchScope(currentScope);
                            execute(p->oper.op[1]);
                            currentScope = st->switchBack(currentScope);
                            currentScope=st->switchScope(currentScope);
                            execute(p->oper.op[2]);
                            currentScope = st->switchBack(currentScope);
                            break;
                        }
                    }
                    break;
                }
                case FOR:   //TODO:
                {
                    //switch scope
                    currentScope=st->switchScope(currentScope);
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    execute(p->oper.op[2]);
                    execute(p->oper.op[3]);
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case WHILE: //TODO:
                { 
                    //switch scope
                    currentScope=st->switchScope(currentScope);
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case DO:    //TODO:
                {
                    //switch scope
                    currentScope=st->switchScope(currentScope);
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case SWITCH:    //TODO:
                {
                    //execute(p->oper.op[0]);
                    typeEnum varType = getIdentifierType(p->oper.op[0]->identifier.name);
                    if(varType != CharType && varType != IntType){
                        yyerror("This type of variable is not supported in switch statement");
                        return Error;
                    }
                    execute(p->oper.op[1]);
                    break;
                }
                case CASE:  //TODO:
                {
                    //switch scopes
                    currentScope=st->switchScope(currentScope);
                    execute(p->oper.op[0]);
                    typeEnum caseConst = execute(p->oper.op[1]);
                    if(caseConst != IntType && caseConst != CharType){
                        yyerror("This type of case is not supported in switch statement");
                        return Error;
                    }
                    execute(p->oper.op[2]);
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case ENUM:
                {
                    //insert in symbol table
                    bool isInserted = st->insert(p->oper.op[0]->identifier.name,"enum",6,currentScope);
                    printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[0]->identifier.name,isInserted);
                    if(!isInserted){
                        yyerror("variable already exists in the current scope");
                    }
                    //switch scope
                    currentScope=st->switchScope(currentScope);
                    //update enum map
                    st->updateEnumMap(currentScope,p->oper.op[0]->identifier.name);
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case AND:
                {
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    if((typeOP1 != BoolType && typeOP1 != IntType) || (typeOP2 != BoolType && typeOP2 != IntType)){
                        yyerror("This type of operands are not supported in this operation");
                        return Error;
                    }
                    fprintf(OutputQuadraplesFile, "AND \n");
                    return BoolType;
                    break;
                }
                case OR:
                {
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    if((typeOP1 != BoolType && typeOP1 != IntType) || (typeOP2 != BoolType && typeOP2 != IntType)){
                        yyerror("This type of operands are not supported in this operation");
                        return Error;
                    }
                    fprintf(OutputQuadraplesFile, "OR \n");
                    return BoolType;
                    break;
                }
                case EE:
                {
                    //if operand is of type operation, call function on it
                    //else, check type compatability
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                    if(finalType == Error)
                    {
                        yyerror("types are not compatible");
                    }
                    fprintf(OutputQuadraplesFile, "COMP_E \n");
                    return BoolType;
                    break;
                }
                case NE:
                {
                    //if operand is of type operation, call function on it
                    //else, check type compatability
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                    if(finalType == Error)
                    {
                        yyerror("types are not compatible");
                    }
                    fprintf(OutputQuadraplesFile, "COMP_NE \n");
                    return BoolType;
                    break;
                }
                case GE:
                {
                    //if operand is of type operation, call function on it
                    //else, check type compatability
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                    if(finalType == Error)
                    {
                        yyerror("types are not compatible");
                    }
                    fprintf(OutputQuadraplesFile, "COMP_GE \n");
                    return BoolType;
                    break;
                }
                case LE:
                {
                    //if operand is of type operation, call function on it
                    //else, check type compatability
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                    if(finalType == Error)
                    {
                        yyerror("types are not compatible");
                    }
                    fprintf(OutputQuadraplesFile, "COMP_LE \n");
                    return BoolType;
                    break;
                }
                case '>':
                {
                    //if operand is of type operation, call function on it
                    //else, check type compatability
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                    if(finalType == Error)
                    {
                        yyerror("types are not compatible");
                    }
                    fprintf(OutputQuadraplesFile, "COMP_G \n");
                    return BoolType;
                    break;
                }
                case '<':
                {
                    //if operand is of type operation, call function on it
                    //else, check type compatability
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                    if(finalType == Error)
                    {
                        yyerror("types are not compatible");
                    }
                    fprintf(OutputQuadraplesFile, "COMP_L \n");
                    return BoolType;
                    break;
                }
                case '!':
                {
                    typeEnum typeOP = execute(p->oper.op[0]);
                    fprintf(OutputQuadraplesFile, "NOT \n");
                    if(typeOP == BoolType || typeOP == IntType)
                    {
                        return BoolType;
                    }
                    else
                    {
                        yyerror("the ! operator doesnt support this type");
                        return Error;
                    }
                    break;
                }
                case '*':
                {
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                    printf("first operand type: %d, second operand type: %d, result type: %d\n",typeOP1,typeOP2,finalType);
                    if(finalType == Error)
                    {
                        yyerror("types are not compatible");
                    }
                    fprintf(OutputQuadraplesFile, "MULTIPLY \n");
                    return finalType;
                    break;
                }
                case '/':
                {
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                    if(finalType == Error)
                    {
                        yyerror("types are not compatible");
                    }
                    fprintf(OutputQuadraplesFile, "DIVIDE \n");
                    return finalType;
                    break;
                }
                case '+':
                {
                    //if operand is of type operation, call function on it
                    //else, check type compatability
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                    printf("first operand type: %d, second operand type: %d, result type: %d\n",typeOP1,typeOP2,finalType);
                    if(finalType == Error)
                    {
                        yyerror("types are not compatible");
                    }
                    fprintf(OutputQuadraplesFile, "PLUS \n");
                    return finalType;
                    break;
                }
                case '-': 
                {
                    switch (p->oper.nops){
                        case 1:
                        {
                            typeEnum typeOP = execute(p->oper.op[0]);
                            if(typeOP != FloatType && typeOP != IntType){
                                yyerror("This operator doesn't support this type of operand");
                                return Error;
                            }
                            fprintf(OutputQuadraplesFile, "NEG \n");
                            return typeOP;
                            break;
                        }
                        case 2:
                        {
                            typeEnum typeOP1 = execute(p->oper.op[0]);
                            typeEnum typeOP2 = execute(p->oper.op[1]);
                            typeEnum finalType = checkCompatibility(typeOP1,typeOP2);
                            if(finalType == Error)
                            {
                                yyerror("types are not compatible");
                            }
                            fprintf(OutputQuadraplesFile, "MINUS \n");
                            return finalType;
                            break;
                        }
                    }

                    break;
                }
                case '%':
                {
                    typeEnum typeOP1 = execute(p->oper.op[0]);
                    typeEnum typeOP2 = execute(p->oper.op[1]);
                    fprintf(OutputQuadraplesFile, "MOD \n");
                    if(typeOP1 == IntType && typeOP2 == IntType)
                    {
                        printf("here\n");
                        return IntType;
                    }
                    else
                    {
                        yyerror("mod operator only accepts integer operands");
                        return Error;
                    }
                    
                    break;
                }
                case '=':
                {
                    switch(p->oper.nops){
                        case 2:{ 
                            //check if its a constant
                            string kind = st->checkKind(p->oper.op[0]->identifier.name, currentScope);
                            if(kind == "constant"){
                                yyerror("assignment of read only variable");
                                return Error;
                            }
                            //check if its an enum variable
                            if(kind == "enum variable")
                            {
                                //if the rhs is not an identifier => error
                                if(p->oper.op[1]->type!=Identifier_Node){
                                    yyerror("Invalid enum operation");
                                    return Error;
                                }
                                string enumName = st->checkType(p->oper.op[0]->identifier.name, currentScope); //get the enum type name
                                bool isValid = st->checkEnum(enumName,p->oper.op[1]->identifier.name,currentScope);   //check if the value to be assigned to the enum is a variable of that enum type
                                if(!isValid)
                                {
                                    yyerror("Invalid enum operation");
                                    return Error;
                                }
                                return EnumType;
                            }
                            //check type mismatch
                            typeEnum varType = getIdentifierType(p->oper.op[0]->identifier.name);
                            typeEnum exprType = execute(p->oper.op[1]);
                            typeEnum finalType = checkCompatibility(varType, exprType);
                            if(finalType==Error){
                                yyerror("Type mismatch in 2 operands");
                                return Error;
                            }
                            fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[0]->identifier.name);
                            return varType;
                            break;
                        }
                        case 3:{
                            //check for type mismatch
                            typeEnum varType = execute(p->oper.op[0]);
                            typeEnum exprType = execute(p->oper.op[2]);
                            typeEnum finalType = checkCompatibility(varType, exprType);
                            if(finalType==Error)
                            {
                                yyerror("Type mismatch in 3 operands");
                                return Error;
                            }
                            //insert in symbol table
                            bool isInserted = st->insert(p->oper.op[1]->identifier.name,"variable",p->oper.op[0]->defineType.type,currentScope);
                            printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                            if(!isInserted){
                                yyerror("variable already exists in the current scope");
                            }
                            fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[1]->identifier.name);
                            //execute(p->oper.op[1]); 
                            //st->print(currentScope);
                            break;
                        } 
                        case 4: //enum => enum enum_name variable_name = expression OR const => const type var_name = expression
                        {
                            if(p->oper.op[0]->defineType.type==ConstType){
                                //check for type mismatch
                                typeEnum varType = execute(p->oper.op[1]);
                                typeEnum exprType = execute(p->oper.op[3]);
                                typeEnum finalType = checkCompatibility(varType, exprType);
                                if(finalType==Error)
                                {
                                    yyerror("Type mismatch in 4 operands");
                                    return Error;
                                }
                                //insert in symbol table
                                bool isInserted = st->insert(p->oper.op[2]->identifier.name,"constant",p->oper.op[1]->defineType.type,currentScope);
                                printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[2]->identifier.name,isInserted);
                                if(!isInserted){
                                    yyerror("variable already exists in the current scope");
                                }
                                fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[2]->identifier.name);
                            }
                            else if(p->oper.op[0]->defineType.type==EnumType)
                            {
                                typeEnum varType = execute(p->oper.op[1]); //if the enum is not defined in the current scope it prints an error
                                if(varType==Error)
                                {
                                    yyerror("Enum wasnt defined in the current scope");
                                    return Error;
                                }
                                //check for type mismatch
                                bool isDefined = st->checkEnum(p->oper.op[1]->identifier.name,p->oper.op[3]->identifier.name,currentScope);
                                if(!isDefined) 
                                {
                                    yyerror("invalid enum operation");
                                    return Error;
                                }
                                //insert in symbol table
                                bool isInserted = st->insertEnumVar(p->oper.op[2]->identifier.name,"enum variable",p->oper.op[1]->identifier.name,currentScope);
                                printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[2]->identifier.name,isInserted);
                                if(!isInserted){
                                    yyerror("variable already exists in the current scope");
                                }
                                fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[2]->identifier.name);
                            }
                        }
                            break;
                    }
                    break;
                }
                case ';':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case ',': //enum variables in enum definition => enum x {variable1 = variablevalue1, variable2}
                {
                    switch(p->oper.nops){
                        case 1: //enum x{variable1}
                        {
                            //insert in the symbol table
                            bool isInserted = st->insert(p->oper.op[0]->identifier.name,"enum constant",0,currentScope);
                            printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[0]->identifier.name,isInserted);
                            if(!isInserted){
                                yyerror("enum variable already exists in the current scope");
                            }

                            fprintf(OutputQuadraplesFile, "PUSH %d\n", ++EnumValue);
                            fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[0]->identifier.name);
                            break;
                        }
                        case 2:
                        {
                            if(p->oper.op[0]->type==Identifier_Node){
                                typeEnum enumvartype = execute(p->oper.op[1]);
                                if(enumvartype != IntType){
                                    yyerror("enum variable value must be an integer");
                                    return Error;
                                }
                                //insert in the symbol table
                                bool isInserted = st->insert(p->oper.op[0]->identifier.name,"enum constant",0,currentScope);
                                printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[0]->identifier.name,isInserted);
                                if(!isInserted){
                                    yyerror("enum variable already exists in the current scope");
                                }
                                execute(p->oper.op[1]); //TODO check
                                fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[0]->identifier.name);
                            }
                            else 
                            {
                                //insert in the symbol table
                                bool isInserted = st->insert(p->oper.op[1]->identifier.name,"enum constant",0,currentScope);
                                printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                                if(!isInserted){
                                    yyerror("enum variable already exists in the current scope");
                                }
                                execute(p->oper.op[0]);
                                fprintf(OutputQuadraplesFile, "PUSH %d\n", ++EnumValue);
                                fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[1]->identifier.name);
                            }
                            
                            break;
                        }
                        case 3:
                        {
                            execute(p->oper.op[0]); //enum variables
                            typeEnum enumvartype3 = execute(p->oper.op[2]);
                            if(enumvartype3 != IntType){
                                yyerror("enum variable value must be an integer");
                                return Error;
                            }
                            //insert in the symbol table
                            bool isInserted = st->insert(p->oper.op[1]->identifier.name,"enum constant",0,currentScope);
                            printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                            if(!isInserted){
                                yyerror("enum variable already exists in the current scope");
                            }
                            execute(p->oper.op[2]); //TODO check
                            fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[1]->identifier.name);
                            break;
                        }
                    }
                    break;
                }
                //TODO: Done?
                case 'd': //function definition
                {
                    //insert in the symbol table
                    bool isInserted = st->insert(p->oper.op[1]->identifier.name,"function",p->oper.op[0]->defineType.type,currentScope);
                    printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                    if(!isInserted){
                        yyerror("function already exists in the current scope");
                    }
                    
                    //switch scope
                    Node * tempNode = new Node();
                    tempNode = currentScope;
                    //will make the function the root scope because the definitions inside of it 
                    //shouldnt have the global scope as their parent scope
                    currentScope=st->functionScope(currentScope);
                    fprintf(OutputQuadraplesFile, "%s: \n", p->oper.op[1]->identifier.name);
                    switch(p->oper.nops){
                        case 4:{
                            execute(p->oper.op[0]);
                            // execute(p->oper.op[1]);
                            execute(p->oper.op[2]);
                            execute(p->oper.op[3]);
                            break;
                        }
                        case 5:{
                            execute(p->oper.op[0]);
                            // execute(p->oper.op[1]);
                            execute(p->oper.op[2]);
                            execute(p->oper.op[3]);
                            execute(p->oper.op[4]);
                            break;
                        }
                    }
                    //switching the scope back 
                    currentScope->parent=tempNode;
                    currentScope = st->switchBack(currentScope);
                    fprintf(OutputQuadraplesFile, "END_FUNC\n");
                    break;
                }
                //TODO: Done
                case 'c': //parameters call => fun(x, y, z) parameters are x, y and z
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                //TODO: Done
                case 'f': //function call 
                {
                    // execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    fprintf(OutputQuadraplesFile, "CALL %s\n", p->oper.op[0]->identifier.name);
                    break;
                }
                //TODO: Done
                case 'p': //parameter list in function definition
                {//insert in symbol table
                    bool isInserted = st->insert(p->oper.op[1]->identifier.name,"parameter",p->oper.op[0]->defineType.type,currentScope);
                    printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                    if(!isInserted){
                        yyerror("parameter already exists in the current scope");
                    }
                    //st->print(currentScope);
                    switch(p->oper.nops){
                        case 2:
                        {
                            execute(p->oper.op[0]);
                            // execute(p->oper.op[1]);
                            fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[1]->identifier.name);
                            break;
                        }
                        case 3:
                        {
                            execute(p->oper.op[0]);
                            // execute(p->oper.op[1]);
                            fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[1]->identifier.name);
                            execute(p->oper.op[2]);
                            break;
                        }
                    }
                    break;
                }
            }
            break;
    }
    return Error;

}

typeEnum getIdentifierType(char* identifierName) 
{
    string typeIdentifier = st->checkType(identifierName, currentScope);
    if(typeIdentifier == "integer")
    {
        return IntType;
    }
    else if(typeIdentifier == "float")
    {
        return FloatType;
    }
    else if(typeIdentifier == "string")
    {
        return StringType;
    }
    else if(typeIdentifier == "boolean")
    {
        return BoolType;
    }
    else if(typeIdentifier == "void")
    {
        return VoidType;
    }
    else if(typeIdentifier == "char")
    {
        return CharType;
    }
    else if(typeIdentifier == "enum")
    {
        return EnumType;
    }
    else if(typeIdentifier == "const")
    {
        return ConstType;
    }
    else
    {
        yyerror("variable was not declared in this scope");
        return Error;
    }
}

typeEnum checkCompatibility(typeEnum typeOP1, typeEnum typeOP2)
{
    if(typeOP1 == typeOP2)
    {
        return typeOP1;
    }
    
    //int and float are compatible
    if(typeOP1 == IntType && typeOP2 == FloatType || typeOP1 == FloatType && typeOP2 == IntType)
    {
        return FloatType;
    }

    //int and char are compatible
    if(typeOP1 == IntType && typeOP2 == CharType || typeOP1 == CharType && typeOP2 == IntType){
        return IntType;
    }

    //float and char are compatible
    if(typeOP1 == FloatType && typeOP2 == CharType || typeOP1 == CharType && typeOP2 == FloatType){
        return FloatType;
    }

    return Error;
}


void yyerror(const char *str)
{
    fprintf(stderr,"error: %s, Last token: %s \n",str, last_token);
    fprintf(errorsFile,"error: %s\n",str);
}

int yywrap()
{
    return 1;
} 

void read_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    // Read input from file and process it as needed

    fclose(fp);
}

int main(int argc, char **argv) {
    FILE *fp = stdin;
    if (argc > 1) {
        fp = fopen(argv[1], "r");
        if (!fp) {
            perror("Error opening file");
            return 1;
        }
    }

    errorsFile = fopen("errors.txt", "w");

    yyin = fp;
    //Quadraples data initialization:
    OutputQuadraplesFile = fopen("output.txt", "w");
    Labels = 0;
    CaseLabels = 0;
    EndSwitchLabel = 0;
    EnumValue = -1;
    yyparse();

    fclose(fp);
    fclose(errorsFile);
    fclose(OutputQuadraplesFile);
    st->print(currentScope);

    return 0;
}
