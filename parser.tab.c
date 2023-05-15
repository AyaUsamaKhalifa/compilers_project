/* A Bison parser, made by GNU Bison 3.7.5.  */

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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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

    nodeType *operation(int oper, int nops, ...);
    nodeType *identifier(char *name);
    nodeType *constantInteger(int value);
    nodeType *constantFloat(float value);
    nodeType *constantBool(bool value);
    nodeType *constantChar(char value);
    nodeType *constantString(char *value);
    nodeType *defineType(typeEnum type);
    int execute(nodeType *p);

    void freeNode(nodeType *p);

    symbolTable* st = new symbolTable();
    Node *currentScope = new Node();
    Node *rootScope = currentScope;
    //printing may be removed
    // extern char* last_token;

#line 106 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_SWITCH = 8,                     /* SWITCH  */
  YYSYMBOL_CASE = 9,                       /* CASE  */
  YYSYMBOL_BREAK = 10,                     /* BREAK  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_ENUM = 12,                      /* ENUM  */
  YYSYMBOL_VOID = 13,                      /* VOID  */
  YYSYMBOL_INT_TYPE = 14,                  /* INT_TYPE  */
  YYSYMBOL_CHAR_TYPE = 15,                 /* CHAR_TYPE  */
  YYSYMBOL_BOOL_TYPE = 16,                 /* BOOL_TYPE  */
  YYSYMBOL_FLOAT_TYPE = 17,                /* FLOAT_TYPE  */
  YYSYMBOL_STRING_TYPE = 18,               /* STRING_TYPE  */
  YYSYMBOL_CONST = 19,                     /* CONST  */
  YYSYMBOL_PRINT = 20,                     /* PRINT  */
  YYSYMBOL_EE = 21,                        /* EE  */
  YYSYMBOL_NE = 22,                        /* NE  */
  YYSYMBOL_GE = 23,                        /* GE  */
  YYSYMBOL_LE = 24,                        /* LE  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_INTEGER = 27,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 28,                     /* FLOAT  */
  YYSYMBOL_BOOL_FALSE = 29,                /* BOOL_FALSE  */
  YYSYMBOL_BOOL_TRUE = 30,                 /* BOOL_TRUE  */
  YYSYMBOL_CHAR = 31,                      /* CHAR  */
  YYSYMBOL_STRING = 32,                    /* STRING  */
  YYSYMBOL_VARIABLE = 33,                  /* VARIABLE  */
  YYSYMBOL_34_ = 34,                       /* ';'  */
  YYSYMBOL_35_ = 35,                       /* '('  */
  YYSYMBOL_36_ = 36,                       /* ')'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* ':'  */
  YYSYMBOL_40_ = 40,                       /* '='  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_42_ = 42,                       /* '<'  */
  YYSYMBOL_43_ = 43,                       /* '+'  */
  YYSYMBOL_44_ = 44,                       /* '-'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '/'  */
  YYSYMBOL_47_ = 47,                       /* '%'  */
  YYSYMBOL_48_ = 48,                       /* '!'  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_root = 52,                      /* root  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_recursive_statement = 54,       /* recursive_statement  */
  YYSYMBOL_conditional_statement = 55,     /* conditional_statement  */
  YYSYMBOL_if_conditional_statement = 56,  /* if_conditional_statement  */
  YYSYMBOL_switch_conditional_statement = 57, /* switch_conditional_statement  */
  YYSYMBOL_case_statement = 58,            /* case_statement  */
  YYSYMBOL_loop_statement = 59,            /* loop_statement  */
  YYSYMBOL_for_loop_statement = 60,        /* for_loop_statement  */
  YYSYMBOL_while_loop_statement = 61,      /* while_loop_statement  */
  YYSYMBOL_do_while_loop_statement = 62,   /* do_while_loop_statement  */
  YYSYMBOL_assignment = 63,                /* assignment  */
  YYSYMBOL_expressions = 64,               /* expressions  */
  YYSYMBOL_first = 65,                     /* first  */
  YYSYMBOL_second = 66,                    /* second  */
  YYSYMBOL_third = 67,                     /* third  */
  YYSYMBOL_fourth = 68,                    /* fourth  */
  YYSYMBOL_fifth = 69,                     /* fifth  */
  YYSYMBOL_sixth = 70,                     /* sixth  */
  YYSYMBOL_seventh = 71,                   /* seventh  */
  YYSYMBOL_function_call = 72,             /* function_call  */
  YYSYMBOL_functional_statement = 73,      /* functional_statement  */
  YYSYMBOL_function_parameters = 74,       /* function_parameters  */
  YYSYMBOL_parameter = 75,                 /* parameter  */
  YYSYMBOL_function_parameters_calls = 76, /* function_parameters_calls  */
  YYSYMBOL_parameter_calls = 77,           /* parameter_calls  */
  YYSYMBOL_function = 78,                  /* function  */
  YYSYMBOL_return_types = 79,              /* return_types  */
  YYSYMBOL_enum_statement = 80,            /* enum_statement  */
  YYSYMBOL_enum_variables = 81,            /* enum_variables  */
  YYSYMBOL_variable_Type = 82,             /* variable_Type  */
  YYSYMBOL_variable_value = 83             /* variable_value  */
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
#define YYLAST   466

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
       0,    72,    72,    76,    80,    85,    88,    93,    98,   107,
     112,   118,   123,   132,   136,   142,   148,   153,   159,   164,
     169,   178,   184,   191,   198,   203,   207,   211,   218,   222,
     228,   232,   238,   242,   246,   252,   256,   260,   264,   268,
     274,   278,   282,   288,   292,   296,   300,   306,   310,   314,
     320,   324,   328,   332,   339,   345,   349,   355,   360,   365,
     369,   375,   380,   385,   389,   395,   399,   405,   411,   417,
     421,   425,   429,   436,   440,   444,   448,   452,   458,   462,
     466,   470,   474,   478
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "DO", "SWITCH", "CASE", "BREAK", "RETURN", "ENUM", "VOID",
  "INT_TYPE", "CHAR_TYPE", "BOOL_TYPE", "FLOAT_TYPE", "STRING_TYPE",
  "CONST", "PRINT", "EE", "NE", "GE", "LE", "AND", "OR", "INTEGER",
  "FLOAT", "BOOL_FALSE", "BOOL_TRUE", "CHAR", "STRING", "VARIABLE", "';'",
  "'('", "')'", "'{'", "'}'", "':'", "'='", "'>'", "'<'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "','", "$accept", "program", "root",
  "statement", "recursive_statement", "conditional_statement",
  "if_conditional_statement", "switch_conditional_statement",
  "case_statement", "loop_statement", "for_loop_statement",
  "while_loop_statement", "do_while_loop_statement", "assignment",
  "expressions", "first", "second", "third", "fourth", "fifth", "sixth",
  "seventh", "function_call", "functional_statement",
  "function_parameters", "parameter", "function_parameters_calls",
  "parameter_calls", "function", "return_types", "enum_statement",
  "enum_variables", "variable_Type", "variable_value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
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
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -53,    29,    32,   -53,    23,    44,    49,   -22,    62,     3,
      87,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,    17,   -21,   -21,   -21,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -53,    43,    69,    96,    60,     1,   -26,
      25,   -53,   -53,   -53,   -53,   -53,   -53,    98,   -53,   -21,
     418,   -21,   -53,   107,   -17,    94,   -21,   -21,   106,    -4,
     -53,   -53,   -53,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,    34,    15,   112,   116,
     118,    30,    95,   130,   114,   119,    73,    69,   131,   126,
      69,   -53,    96,    60,     1,     1,   -26,   -26,   -26,   -26,
      25,    25,   -53,   -53,   -53,    73,   -21,   140,   145,   -21,
     142,   143,   175,   -53,   146,   -21,   144,   -19,   150,   138,
     161,   -53,   -21,   159,    69,   -53,   -13,   -53,   163,   -53,
      69,   -21,   -53,   171,   168,    73,   -53,    69,   169,   141,
     418,   185,   -21,    -7,    69,   156,   -53,   174,   -53,   204,
     173,   -53,    42,   133,   -53,   -21,   229,   -53,   273,   182,
     184,   -53,   172,    69,   -53,   -21,   -53,   -53,   -53,    69,
     176,   308,   352,   396,   186,   -53,   -53,   -53,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    52,     0,     0,     0,     3,     6,    12,    11,
       7,    18,    19,    20,     0,    27,    29,    31,    34,    39,
      42,    46,    49,    53,     4,    55,    56,     0,    51,     0,
       0,     0,    10,     0,     0,     0,    62,     0,    52,     0,
      47,    48,     8,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    58,    64,     0,    61,
      25,    50,    28,    30,    32,    33,    37,    38,    35,    36,
      40,    41,    43,    44,    45,    58,     0,     0,     0,     0,
       0,     0,     0,     9,     0,     0,    72,     0,     0,    57,
       0,    54,     0,     0,    24,    10,     0,    10,     0,    17,
      26,     0,    68,     0,     0,     0,    60,    63,     0,     0,
       0,     0,     0,     0,    71,    70,    10,     0,    10,    14,
       0,    22,     0,     0,    15,     0,     0,    59,     0,     0,
       0,    23,     0,    69,    66,     0,    10,    10,    10,    67,
       0,     0,     0,     0,     0,    13,    21,    16,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -53,   -53,   -53,   220,   -52,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,   -47,   -23,   162,   164,    40,    68,    46,
     -20,   -53,   -53,   -53,   121,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,    -1,    74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,   113,    82,    27,    28,    29,   143,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,   118,   119,    88,    89,    45,   170,
      46,   117,    80,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      59,    47,   153,    79,    60,    61,    16,    17,    18,    19,
      20,    21,    58,    63,    23,    52,    84,    71,    72,   132,
      85,   140,    63,    24,    67,    68,    77,    25,    81,     3,
     133,   154,    91,    87,    90,     4,    54,     5,     6,     7,
       8,    63,    69,    70,     9,    10,    11,    12,    13,    14,
      15,   107,    56,   102,   103,   104,    63,    57,    49,    16,
      17,    18,    19,    20,    21,    22,   111,    23,    63,   105,
      73,    74,    75,   139,   106,   141,    24,    62,   161,    50,
      25,    65,    66,   124,    51,   120,   126,    11,    12,    13,
      14,    15,   130,   150,   156,    63,   158,    53,     4,   137,
       5,     6,     7,     8,   120,    94,    95,    78,   144,    11,
      12,    13,    14,    15,   171,   172,   173,   100,   101,   152,
      55,    64,    16,    17,    18,    19,    20,    21,    22,    86,
      23,    76,   163,   112,   147,    96,    97,    98,    99,    24,
      83,    56,   169,    25,     4,   108,     5,     6,     7,     8,
     109,   110,   116,    78,   115,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   114,   121,    16,    17,
      18,    19,    20,    21,    22,   122,    23,   125,    84,   149,
     127,   128,   106,   129,   131,    24,   134,   135,     4,    25,
       5,     6,     7,     8,   136,   138,   155,    78,   142,    11,
      12,    13,    14,    15,   145,   146,   148,   157,   159,   160,
     174,   168,    16,    17,    18,    19,    20,    21,    22,   166,
      23,   167,    26,   151,   178,    92,   123,   162,    93,    24,
       0,     0,     4,    25,     5,     6,     7,     8,     0,     0,
       0,    78,     0,    11,    12,    13,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,    18,    19,
      20,    21,    22,     0,    23,     0,     0,   164,     0,     0,
       0,     0,     0,    24,     0,     0,     4,    25,     5,     6,
       7,     8,     0,     0,   165,    78,     0,    11,    12,    13,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
      16,    17,    18,    19,    20,    21,    22,     0,    23,     0,
       0,     4,     0,     5,     6,     7,     8,    24,     0,     0,
      78,    25,    11,    12,    13,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,    18,    19,    20,
      21,    22,     0,    23,     0,     0,   175,     0,     0,     0,
       0,     0,    24,     0,     0,     4,    25,     5,     6,     7,
       8,     0,     0,     0,    78,     0,    11,    12,    13,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,    16,
      17,    18,    19,    20,    21,    22,     0,    23,     0,     0,
     176,     0,     0,     0,     0,     0,    24,     0,     0,     4,
      25,     5,     6,     7,     8,     0,   177,     0,    78,     0,
      11,    12,    13,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,    16,    17,    18,    19,    20,    21,    22,
      78,    23,    11,    12,    13,    14,    15,     0,     0,     0,
      24,     0,     0,     0,    25,    16,    17,    18,    19,    20,
      21,    22,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,     0,    25
};

static const yytype_int16 yycheck[] =
{
      23,     2,     9,    50,    24,    25,    27,    28,    29,    30,
      31,    32,    33,    26,    35,    37,    33,    43,    44,    38,
      37,    34,    26,    44,    23,    24,    49,    48,    51,     0,
      49,    38,    36,    56,    57,     3,    33,     5,     6,     7,
       8,    26,    41,    42,    12,    13,    14,    15,    16,    17,
      18,    36,    35,    73,    74,    75,    26,    40,    35,    27,
      28,    29,    30,    31,    32,    33,    36,    35,    26,    35,
      45,    46,    47,   125,    40,   127,    44,    34,    36,    35,
      48,    21,    22,   106,    35,    86,   109,    14,    15,    16,
      17,    18,   115,   140,   146,    26,   148,    35,     3,   122,
       5,     6,     7,     8,   105,    65,    66,    12,   131,    14,
      15,    16,    17,    18,   166,   167,   168,    71,    72,   142,
      33,    25,    27,    28,    29,    30,    31,    32,    33,    35,
      35,    33,   155,    38,   135,    67,    68,    69,    70,    44,
      33,    35,   165,    48,     3,    33,     5,     6,     7,     8,
      34,    33,    33,    12,    40,    14,    15,    16,    17,    18,
      27,    28,    29,    30,    31,    32,    36,    36,    27,    28,
      29,    30,    31,    32,    33,    49,    35,    37,    33,    38,
      37,     6,    40,    37,    40,    44,    36,    49,     3,    48,
       5,     6,     7,     8,    33,    36,    40,    12,    35,    14,
      15,    16,    17,    18,    33,    37,    37,    33,     4,    36,
      34,    39,    27,    28,    29,    30,    31,    32,    33,    37,
      35,    37,     2,    38,    38,    63,   105,   153,    64,    44,
      -1,    -1,     3,    48,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    -1,    14,    15,    16,    17,    18,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,     3,    48,     5,     6,
       7,     8,    -1,    -1,    11,    12,    -1,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    -1,    35,    -1,
      -1,     3,    -1,     5,     6,     7,     8,    44,    -1,    -1,
      12,    48,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,     3,    48,     5,     6,     7,
       8,    -1,    -1,    -1,    12,    -1,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    -1,    35,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,     3,
      48,     5,     6,     7,     8,    -1,    10,    -1,    12,    -1,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      12,    35,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    48,    27,    28,    29,    30,    31,
      32,    33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     3,     5,     6,     7,     8,    12,
      13,    14,    15,    16,    17,    18,    27,    28,    29,    30,
      31,    32,    33,    35,    44,    48,    53,    55,    56,    57,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    78,    80,    82,    83,    35,
      35,    35,    37,    35,    33,    33,    35,    40,    33,    64,
      70,    70,    34,    26,    25,    21,    22,    23,    24,    41,
      42,    43,    44,    45,    46,    47,    33,    64,    12,    63,
      82,    64,    54,    33,    33,    37,    35,    64,    76,    77,
      64,    36,    65,    66,    67,    67,    68,    68,    68,    68,
      69,    69,    70,    70,    70,    35,    40,    36,    33,    34,
      33,    36,    38,    53,    36,    40,    33,    81,    74,    75,
      82,    36,    49,    74,    64,    37,    64,    37,     6,    37,
      64,    40,    38,    49,    36,    49,    33,    64,    36,    54,
      34,    54,    35,    58,    64,    33,    37,    82,    37,    38,
      63,    38,    64,     9,    38,    40,    54,    33,    54,     4,
      36,    36,    83,    64,    38,    11,    37,    37,    39,    64,
      79,    54,    54,    54,    34,    38,    38,    10,    38
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    58,    58,    59,    59,
      59,    60,    61,    62,    63,    63,    63,    63,    64,    64,
      65,    65,    66,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    68,    69,    69,    69,    69,    70,    70,    70,
      71,    71,    71,    71,    72,    73,    73,    74,    74,    75,
      75,    76,    76,    77,    77,    78,    78,    79,    80,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    83,    83,
      83,    83,    83,    83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     1,     1,     2,     2,
       0,     1,     1,    11,     7,     7,     6,     0,     1,     1,
       1,    11,     7,     8,     4,     3,     5,     1,     3,     1,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     1,
       3,     1,     1,     1,     4,     1,     1,     1,     0,     4,
       2,     1,     0,     3,     1,    11,     8,     1,     5,     5,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
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
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

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
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
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
  case 2: /* program: root  */
#line 72 "parser.y"
              {printf("end of program\n");}
#line 1363 "parser.tab.c"
    break;

  case 3: /* root: root statement  */
#line 77 "parser.y"
        {printf("root: root statement\n"); printf("-------------------------------------\n");
        execute((yyvsp[0].node));
        }
#line 1371 "parser.tab.c"
    break;

  case 4: /* root: root functional_statement  */
#line 81 "parser.y"
        {printf("root functional_statement\n"); printf("-------------------------------------\n");
        execute((yyvsp[0].node));
        }
#line 1379 "parser.tab.c"
    break;

  case 5: /* root: %empty  */
#line 85 "parser.y"
        {printf("root: \n");}
#line 1385 "parser.tab.c"
    break;

  case 6: /* statement: conditional_statement  */
#line 89 "parser.y"
            { printf("statement: conditional_statement\n");
            (yyval.node)=(yyvsp[0].node);
            }
#line 1393 "parser.tab.c"
    break;

  case 7: /* statement: loop_statement  */
#line 94 "parser.y"
            { printf("statement: loop_statement\n");
            (yyval.node)=(yyvsp[0].node);
            }
#line 1401 "parser.tab.c"
    break;

  case 8: /* statement: assignment ';'  */
#line 99 "parser.y"
            { printf("statement: assignment;\n");
            (yyval.node)=(yyvsp[-1].node);
            }
#line 1409 "parser.tab.c"
    break;

  case 9: /* recursive_statement: recursive_statement statement  */
#line 108 "parser.y"
                    {printf("recursive_statement: recursive_statement statement\n");
                    (yyval.node)=operation(';',2,(yyvsp[-1].node),(yyvsp[0].node));
                    }
#line 1417 "parser.tab.c"
    break;

  case 10: /* recursive_statement: %empty  */
#line 112 "parser.y"
                    {printf("recursive_statement: \n");
                    (yyval.node)=NULL;
                    }
#line 1425 "parser.tab.c"
    break;

  case 11: /* conditional_statement: switch_conditional_statement  */
#line 119 "parser.y"
                        {printf("conditional_statement: switch_conditional_statement\n");
                        (yyval.node)=(yyvsp[0].node);
                        }
#line 1433 "parser.tab.c"
    break;

  case 12: /* conditional_statement: if_conditional_statement  */
#line 124 "parser.y"
                        {printf("conditional_statement: if_conditional_statement\n");
                        (yyval.node)=(yyvsp[0].node);
                        }
#line 1441 "parser.tab.c"
    break;

  case 13: /* if_conditional_statement: IF '(' expressions ')' '{' recursive_statement '}' ELSE '{' recursive_statement '}'  */
#line 133 "parser.y"
                            {printf("if_conditional_statement: if(exp){recursive_statement} else{recursive_statement}\n");
                            (yyval.node)=operation(IF,3,(yyvsp[-8].node),(yyvsp[-5].node),(yyvsp[-1].node));
                            }
#line 1449 "parser.tab.c"
    break;

  case 14: /* if_conditional_statement: IF '(' expressions ')' '{' recursive_statement '}'  */
#line 137 "parser.y"
                            {printf("if_conditional_statement: if(exp){recursive_statement}\n");
                            (yyval.node)=operation(IF,2,(yyvsp[-4].node),(yyvsp[-1].node));
                            }
#line 1457 "parser.tab.c"
    break;

  case 15: /* switch_conditional_statement: SWITCH '(' VARIABLE ')' '{' case_statement '}'  */
#line 143 "parser.y"
                                {printf("switch_conditional_statement: switch(VARIABLE){case_statement}\n");
                                (yyval.node)=operation(SWITCH,2,(yyvsp[-4].string_val),(yyvsp[-1].node));
                                }
#line 1465 "parser.tab.c"
    break;

  case 16: /* case_statement: case_statement CASE variable_value ':' recursive_statement BREAK  */
#line 149 "parser.y"
                {printf("case_statement: case_statement case variable_value: recursive_statement break\n");
                (yyval.node)=operation(CASE,3,(yyvsp[-5].node),(yyvsp[-3].node),(yyvsp[-1].node));
                }
#line 1473 "parser.tab.c"
    break;

  case 17: /* case_statement: %empty  */
#line 153 "parser.y"
                {printf("case_statement: \n");
                (yyval.node)=NULL;
                }
#line 1481 "parser.tab.c"
    break;

  case 18: /* loop_statement: for_loop_statement  */
#line 160 "parser.y"
                {printf("loop_statement: for_loop_statement\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 1489 "parser.tab.c"
    break;

  case 19: /* loop_statement: while_loop_statement  */
#line 165 "parser.y"
                {printf("loop_statement: while_loop_statement\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 1497 "parser.tab.c"
    break;

  case 20: /* loop_statement: do_while_loop_statement  */
#line 170 "parser.y"
                {printf("loop_statement: do_while_loop_statement\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 1505 "parser.tab.c"
    break;

  case 21: /* for_loop_statement: FOR '(' assignment ';' expressions ';' assignment ')' '{' recursive_statement '}'  */
#line 179 "parser.y"
                    {printf("for_loop_statement: for(assignment; exp; assignment){recursive_statement}\n");
                    (yyval.node)=operation(FOR,4,(yyvsp[-8].node),(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node));
                    }
#line 1513 "parser.tab.c"
    break;

  case 22: /* while_loop_statement: WHILE '(' expressions ')' '{' recursive_statement '}'  */
#line 185 "parser.y"
                    {printf("while_loop_statement: while(exp){recursive_statement}\n");
                    (yyval.node)=operation(WHILE,2,(yyvsp[-4].node),(yyvsp[-1].node));
                    }
#line 1521 "parser.tab.c"
    break;

  case 23: /* do_while_loop_statement: DO '{' recursive_statement '}' WHILE '(' expressions ')'  */
#line 192 "parser.y"
                        {printf("do_while_loop_statement: do{recursive_statement} while{exp}\n");
                        (yyval.node)=operation(DO,2,(yyvsp[-5].node),(yyvsp[-1].node));
                        }
#line 1529 "parser.tab.c"
    break;

  case 24: /* assignment: variable_Type VARIABLE '=' expressions  */
#line 199 "parser.y"
            {
            printf("assignment: variable_Type VARIABLE = exp\n");
            (yyval.node)=operation('=',3,(yyvsp[-3].node),identifier((yyvsp[-2].string_val)),(yyvsp[0].node));
            }
#line 1538 "parser.tab.c"
    break;

  case 25: /* assignment: VARIABLE '=' expressions  */
#line 204 "parser.y"
            {printf("assignment: VARIABLE = exp\n");
            (yyval.node)=operation('=',2,identifier((yyvsp[-2].string_val)),(yyvsp[0].node));
            }
#line 1546 "parser.tab.c"
    break;

  case 26: /* assignment: ENUM VARIABLE VARIABLE '=' expressions  */
#line 208 "parser.y"
            {printf("assignment: ENUM VARIABLE VARIABLE = exp\n");
            (yyval.node)=operation('=',4,defineType(EnumType),identifier((yyvsp[-3].string_val)),identifier((yyvsp[-2].string_val)),(yyvsp[0].node));
            }
#line 1554 "parser.tab.c"
    break;

  case 27: /* assignment: expressions  */
#line 212 "parser.y"
            {printf("assignment: exp\n");
            (yyval.node) = (yyvsp[0].node);
            }
#line 1562 "parser.tab.c"
    break;

  case 28: /* expressions: expressions OR first  */
#line 219 "parser.y"
            {printf("exp: exp || first \n");
            (yyval.node)=operation(OR,2,(yyvsp[-2].node),(yyvsp[0].node));
            }
#line 1570 "parser.tab.c"
    break;

  case 29: /* expressions: first  */
#line 223 "parser.y"
            {printf("exp: first \n");
            (yyval.node)=(yyvsp[0].node);
            }
#line 1578 "parser.tab.c"
    break;

  case 30: /* first: first AND second  */
#line 229 "parser.y"
        {printf("first: first && second\n");
        (yyval.node)=operation(AND,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1586 "parser.tab.c"
    break;

  case 31: /* first: second  */
#line 233 "parser.y"
        {printf("first: second\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1594 "parser.tab.c"
    break;

  case 32: /* second: second EE third  */
#line 239 "parser.y"
        {printf("second: second == third\n");
        (yyval.node)=operation(EE,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1602 "parser.tab.c"
    break;

  case 33: /* second: second NE third  */
#line 243 "parser.y"
        {printf("second: second != third\n");
        (yyval.node)=operation(NE,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1610 "parser.tab.c"
    break;

  case 34: /* second: third  */
#line 247 "parser.y"
        {printf("second: third\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1618 "parser.tab.c"
    break;

  case 35: /* third: third '>' fourth  */
#line 253 "parser.y"
        {printf("third: third > fourth\n");
        (yyval.node)=operation('>',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1626 "parser.tab.c"
    break;

  case 36: /* third: third '<' fourth  */
#line 257 "parser.y"
        {printf("third: third < fourth\n");
        (yyval.node)=operation('<',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1634 "parser.tab.c"
    break;

  case 37: /* third: third GE fourth  */
#line 261 "parser.y"
        {printf("third: third >= fourth\n");
        (yyval.node)=operation(GE,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1642 "parser.tab.c"
    break;

  case 38: /* third: third LE fourth  */
#line 265 "parser.y"
        {printf("third: third <= fourth\n");
        (yyval.node)=operation(LE,2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1650 "parser.tab.c"
    break;

  case 39: /* third: fourth  */
#line 269 "parser.y"
        {printf("third: fourth\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1658 "parser.tab.c"
    break;

  case 40: /* fourth: fourth '+' fifth  */
#line 275 "parser.y"
        {printf("fourth: fourth + fifth\n");
        (yyval.node)=operation('+',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1666 "parser.tab.c"
    break;

  case 41: /* fourth: fourth '-' fifth  */
#line 279 "parser.y"
        {printf("fourth: fourth - fifth\n");
        (yyval.node)=operation('-',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1674 "parser.tab.c"
    break;

  case 42: /* fourth: fifth  */
#line 283 "parser.y"
        {printf("fourth: fifth\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1682 "parser.tab.c"
    break;

  case 43: /* fifth: fifth '*' sixth  */
#line 289 "parser.y"
        {printf("fifth: fifth * sixth\n");
        (yyval.node)=operation('*',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1690 "parser.tab.c"
    break;

  case 44: /* fifth: fifth '/' sixth  */
#line 293 "parser.y"
        {printf("fifth: fifth / sixth\n");
        (yyval.node)=operation('/',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1698 "parser.tab.c"
    break;

  case 45: /* fifth: fifth '%' sixth  */
#line 297 "parser.y"
        {printf("fifth: fifth %% sixth\n");
        (yyval.node)=operation('%',2,(yyvsp[-2].node),(yyvsp[0].node));
        }
#line 1706 "parser.tab.c"
    break;

  case 46: /* fifth: sixth  */
#line 301 "parser.y"
        {printf("fifth: sixth\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1714 "parser.tab.c"
    break;

  case 47: /* sixth: '-' sixth  */
#line 307 "parser.y"
        {printf("sixth: - sixth\n");
        (yyval.node)=operation('-',1,(yyvsp[0].node));
        }
#line 1722 "parser.tab.c"
    break;

  case 48: /* sixth: '!' sixth  */
#line 311 "parser.y"
        {printf("sixth: ! sixth\n");
        (yyval.node)=operation('!',1,(yyvsp[0].node));
        }
#line 1730 "parser.tab.c"
    break;

  case 49: /* sixth: seventh  */
#line 315 "parser.y"
        {printf("sixth: seventh\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1738 "parser.tab.c"
    break;

  case 50: /* seventh: '(' expressions ')'  */
#line 321 "parser.y"
        {printf("seventh: (exp)\n");
        (yyval.node)=(yyvsp[-1].node);
        }
#line 1746 "parser.tab.c"
    break;

  case 51: /* seventh: variable_value  */
#line 325 "parser.y"
        {printf("seventh: variable_value\n");
        (yyval.node) = (yyvsp[0].node);
        }
#line 1754 "parser.tab.c"
    break;

  case 52: /* seventh: VARIABLE  */
#line 329 "parser.y"
        {printf("seventh: VARIABLE\n");
        (yyval.node) = identifier((yyvsp[0].string_val));
        }
#line 1762 "parser.tab.c"
    break;

  case 53: /* seventh: function_call  */
#line 333 "parser.y"
        {printf("seventh: function_call\n");
        (yyval.node)=(yyvsp[0].node);
        }
#line 1770 "parser.tab.c"
    break;

  case 54: /* function_call: VARIABLE '(' function_parameters_calls ')'  */
#line 340 "parser.y"
                {printf("function_call: VARIABLE (function_parameters_calls)\n");
                (yyval.node)=operation('f',2,identifier((yyvsp[-3].string_val)),(yyvsp[-1].node));
                }
#line 1778 "parser.tab.c"
    break;

  case 55: /* functional_statement: function  */
#line 346 "parser.y"
                    {printf("functional_statement: function\n");
                    (yyval.node)=(yyvsp[0].node);
                    }
#line 1786 "parser.tab.c"
    break;

  case 56: /* functional_statement: enum_statement  */
#line 350 "parser.y"
                    {printf("functional_statement: enum_statement\n");
                    (yyval.node)=(yyvsp[0].node);
                    }
#line 1794 "parser.tab.c"
    break;

  case 57: /* function_parameters: parameter  */
#line 356 "parser.y"
                    {printf("function_parameters: parameter\n");
                    (yyval.node)=(yyvsp[0].node);
                    }
#line 1802 "parser.tab.c"
    break;

  case 58: /* function_parameters: %empty  */
#line 360 "parser.y"
                    {printf("function_parameters: \n");
                    (yyval.node)=NULL;
                    }
#line 1810 "parser.tab.c"
    break;

  case 59: /* parameter: parameter ',' variable_Type VARIABLE  */
#line 366 "parser.y"
            {printf("parameter: parameter, variable_Type VARIABLE\n");
            (yyval.node)=operation('p',3,(yyvsp[-1].node),identifier((yyvsp[0].string_val)),(yyvsp[-3].node));
            }
#line 1818 "parser.tab.c"
    break;

  case 60: /* parameter: variable_Type VARIABLE  */
#line 370 "parser.y"
            {printf("parameter: variable_Type VARIABLE\n");
            (yyval.node)=operation('p',2,(yyvsp[-1].node),identifier((yyvsp[0].string_val)));
            }
#line 1826 "parser.tab.c"
    break;

  case 61: /* function_parameters_calls: parameter_calls  */
#line 376 "parser.y"
                            {printf("function_parameters_calls: parameter_calls\n");
                            (yyval.node)=(yyvsp[0].node);
                            }
#line 1834 "parser.tab.c"
    break;

  case 62: /* function_parameters_calls: %empty  */
#line 380 "parser.y"
                            {printf("function_parameters_calls: \n");
                            (yyval.node)=NULL;
                            }
#line 1842 "parser.tab.c"
    break;

  case 63: /* parameter_calls: parameter_calls ',' expressions  */
#line 386 "parser.y"
                {printf("parameter_calls: parameter_calls, exp\n");
                (yyval.node)=operation('c',2,(yyvsp[-2].node),(yyvsp[0].node));
                }
#line 1850 "parser.tab.c"
    break;

  case 64: /* parameter_calls: expressions  */
#line 390 "parser.y"
                {printf("parameter_calls: exp\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 1858 "parser.tab.c"
    break;

  case 65: /* function: variable_Type VARIABLE '(' function_parameters ')' '{' recursive_statement RETURN return_types ';' '}'  */
#line 396 "parser.y"
        {printf("function: variable_Type  (function_parameters){recursive_statement RETURN return_types ;}\n");
        (yyval.node)=operation('d',5,(yyvsp[-10].node),identifier((yyvsp[-9].string_val)),(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
        }
#line 1866 "parser.tab.c"
    break;

  case 66: /* function: VOID VARIABLE '(' function_parameters ')' '{' recursive_statement '}'  */
#line 400 "parser.y"
        {printf("function: void VARIABLE (function_parameters) {recursive_statement}\n");
        (yyval.node)=operation('d',5,defineType(VoidType),identifier((yyvsp[-6].string_val)),(yyvsp[-4].node),(yyvsp[-1].node));
        }
#line 1874 "parser.tab.c"
    break;

  case 67: /* return_types: expressions  */
#line 406 "parser.y"
                {printf("return_types: expressions\n");
                (yyval.node)=(yyvsp[0].node);
                }
#line 1882 "parser.tab.c"
    break;

  case 68: /* enum_statement: ENUM VARIABLE '{' enum_variables '}'  */
#line 412 "parser.y"
                {printf("enum_statement: enum VARIABLE {enum_variables}\n");
                (yyval.node)=operation(ENUM,2,identifier((yyvsp[-3].string_val)),(yyvsp[-1].node));
                }
#line 1890 "parser.tab.c"
    break;

  case 69: /* enum_variables: enum_variables ',' VARIABLE '=' expressions  */
#line 418 "parser.y"
                {printf("enum_variables: enum_variables, VARIABLE = exp\n");
                (yyval.node)=operation(',',2,(yyvsp[-4].node),operation('=',2,identifier((yyvsp[-2].string_val)),(yyvsp[0].node)));
                }
#line 1898 "parser.tab.c"
    break;

  case 70: /* enum_variables: enum_variables ',' VARIABLE  */
#line 422 "parser.y"
                {printf("enum_variables: enum_variables, VARIABLE\n");
                (yyval.node)=operation(',',2,(yyvsp[-2].node),identifier((yyvsp[0].string_val)));
                }
#line 1906 "parser.tab.c"
    break;

  case 71: /* enum_variables: VARIABLE '=' expressions  */
#line 426 "parser.y"
                {printf("enum_variables:VARIABLE = exp\n");
                (yyval.node)=operation('=',2,identifier((yyvsp[-2].string_val)),(yyvsp[0].node));
                }
#line 1914 "parser.tab.c"
    break;

  case 72: /* enum_variables: VARIABLE  */
#line 430 "parser.y"
                {printf("enum_variables: VARIABLE\n");
                (yyval.node)=identifier((yyvsp[0].string_val));
                }
#line 1922 "parser.tab.c"
    break;

  case 73: /* variable_Type: INT_TYPE  */
#line 437 "parser.y"
                {printf("variable_Type: int\n");
                (yyval.node) = defineType(IntType);
                }
#line 1930 "parser.tab.c"
    break;

  case 74: /* variable_Type: CHAR_TYPE  */
#line 441 "parser.y"
                {printf("variable_Type: char\n");
                (yyval.node) = defineType(CharType);
                }
#line 1938 "parser.tab.c"
    break;

  case 75: /* variable_Type: BOOL_TYPE  */
#line 445 "parser.y"
                {printf("variable_Type: bool\n");
                (yyval.node) = defineType(BoolType);
                }
#line 1946 "parser.tab.c"
    break;

  case 76: /* variable_Type: FLOAT_TYPE  */
#line 449 "parser.y"
                {printf("variable_Type: float\n");
                (yyval.node) = defineType(FloatType);
                }
#line 1954 "parser.tab.c"
    break;

  case 77: /* variable_Type: STRING_TYPE  */
#line 453 "parser.y"
                {printf("variable_Type: string\n");
                (yyval.node) = defineType(StringType);
                }
#line 1962 "parser.tab.c"
    break;

  case 78: /* variable_value: INTEGER  */
#line 459 "parser.y"
                {printf("variable_value: int value \n");
                (yyval.node) = constantInteger((yyvsp[0].integer_val));
                }
#line 1970 "parser.tab.c"
    break;

  case 79: /* variable_value: FLOAT  */
#line 463 "parser.y"
                {printf("variable_value: float value \n");
                (yyval.node) = constantFloat((yyvsp[0].float_val));
                }
#line 1978 "parser.tab.c"
    break;

  case 80: /* variable_value: BOOL_FALSE  */
#line 467 "parser.y"
                {printf("variable_value: false \n");
                (yyval.node) = constantBool((yyvsp[0].integer_val));
                }
#line 1986 "parser.tab.c"
    break;

  case 81: /* variable_value: BOOL_TRUE  */
#line 471 "parser.y"
                {printf("variable_value: true \n");
                (yyval.node) = constantBool((yyvsp[0].integer_val));
                }
#line 1994 "parser.tab.c"
    break;

  case 82: /* variable_value: CHAR  */
#line 475 "parser.y"
                {printf("variable_value: char value \n");
                (yyval.node) = constantChar((yyvsp[0].char_val));
                }
#line 2002 "parser.tab.c"
    break;

  case 83: /* variable_value: STRING  */
#line 479 "parser.y"
                {printf("variable_value: string value \n");
                (yyval.node) = constantString((yyvsp[0].string_val));
                }
#line 2010 "parser.tab.c"
    break;


#line 2014 "parser.tab.c"

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
      yyerror (YY_("syntax error"));
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


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

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


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 485 "parser.y"


#define SIZEOF_NODETYPE ((char*)&p->constant - (char*)p)

nodeType *constantInteger(int value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.intVal = value;
    printf("constant integer: %d\n", value);
    return p;
}

nodeType *constantFloat(float value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.floatVal = value;
    printf("constant float: %f\n", value);
    return p;
}

nodeType *constantBool(bool value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.boolVal = value;
    printf("constant boolean: %d\n", value);
    return p;
}

nodeType *constantChar(char value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.charVal = value;
    printf("constant char: %c\n", value);
    return p;
}

nodeType *constantString(char* value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.stringVal = value;
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

int execute(nodeType *p){

    if(p == NULL) return 0;
    switch(p->type)
    {
        case Constant_Node:
            break;

        case Identifier_Node:

            break;

        case Type_Node:

            break;

        case Operator_Node:
            switch(p->oper.oper){
                case IF: {
                    //switch scope
                    Node* newNode = new Node();
                    newNode->parent = currentScope;
                    currentScope->children.push_back(newNode);
                    currentScope = newNode;
                    //call exec on operands
                    switch(p->oper.nops){
                        case 2:{
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            break;
                        }
                        case 3:{
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            execute(p->oper.op[2]);
                            break;
                        }
                    }
                    //switching the scope back 
                    currentScope = currentScope->parent;
                    break;
                }
                case FOR:
                {
                    //switch scope
                    Node* newNode = new Node();
                    newNode->parent = currentScope;
                    currentScope->children.push_back(newNode);
                    currentScope = newNode;
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    execute(p->oper.op[2]);
                    execute(p->oper.op[3]);
                    //switching the scope back 
                    currentScope = currentScope->parent;
                    break;
                }
                case WHILE:
                { 
                    //switch scope
                    Node* newNode = new Node();
                    newNode->parent = currentScope;
                    currentScope->children.push_back(newNode);
                    currentScope = newNode;
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    //switching the scope back 
                    currentScope = currentScope->parent;
                    break;
                }
                case DO:
                {
                    //switch scope
                    Node* newNode = new Node();
                    newNode->parent = currentScope;
                    currentScope->children.push_back(newNode);
                    currentScope = newNode;
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    //switching the scope back 
                    currentScope = currentScope->parent;
                    break;
                }
                case SWITCH:
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case CASE:
                {
                    //switch scopes
                    Node* newNode = new Node();
                    newNode->parent = currentScope;
                    currentScope->children.push_back(newNode);
                    currentScope = newNode;
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    execute(p->oper.op[2]);
                    //switching the scope back 
                    currentScope = currentScope->parent;
                    break;
                }
                case AND:
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case OR:
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case EE:
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case NE:
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case GE:
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case LE:
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case ENUM:
                {
                    //switch scope
                    Node* newNode = new Node();
                    newNode->parent = currentScope;
                    currentScope->children.push_back(newNode);
                    currentScope = newNode;
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    //switching the scope back 
                    currentScope = currentScope->parent;
                    break;
                }
                case ';':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case '=':
                {
                    switch(p->oper.nops){
                        case 2:
                            break;
                        case 3:{
                            //insert in symbol table
                            bool isInserted = st->insert(p->oper.op[1]->identifier.name,"variable",p->oper.op[0]->defineType.type,currentScope);
                            printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                            if(!isInserted){
                                yyerror("ERROR: variable already exists in the current scope");
                            }
                            //st->print(currentScope);
                            break;
                        } 
                        case 4:
                            break;
                    }
                    break;
                }
                case '>':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case '<':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case '!':
                {
                    execute(p->oper.op[0]);
                    break;
                }
                case '*':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case '/':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case '+':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case '-':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case '%':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case ',':
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case 'd': //function definition
                {
                    //switch scope
                    Node* newNode = new Node();
                    newNode->parent = currentScope;
                    currentScope->children.push_back(newNode);
                    currentScope = newNode;
                    //insert in the symbol table
                    bool isInserted = st->insert(p->oper.op[1]->identifier.name,"function",p->oper.op[0]->defineType.type,currentScope);
                    printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                    if(!isInserted){
                        yyerror("ERROR: function already exists in the current scope");
                    }
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    execute(p->oper.op[2]);
                    execute(p->oper.op[3]);
                    execute(p->oper.op[4]);
                    //st->print(currentScope);
                    //switching the scope back 
                    currentScope = currentScope->parent;
                    break;
                }
                case 'c': //parameters call => fun(x, y,  z) parameters are x, y and z
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case 'f': //function call 
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case 'p': //parameter list in function definition
                {//insert in symbol table
                    bool isInserted = st->insert(p->oper.op[1]->identifier.name,"parameter",p->oper.op[0]->defineType.type,currentScope);
                    printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                    if(!isInserted){
                        yyerror("ERROR: parameter already exists in the current scope");
                    }
                    //st->print(currentScope);
                    switch(p->oper.nops){
                        case 2:
                        {
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            break;
                        }
                        case 3:
                        {
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            execute(p->oper.op[2]);
                            break;
                        }
                    }
                    break;
                }
            }
            break;
    }
    return 0;

}

void yyerror(const char *str)
{
    fprintf(stderr,"error: %s, Last token:\n%s \n",str, last_token);
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

    yyparse();

    fclose(fp);
    fclose(errorsFile);

    st->print(currentScope);

    return 0;
}
