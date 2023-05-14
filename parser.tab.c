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
#line 2 "parser.y"

    /*Definition section */
    #include "parser.h"
    #include "common.h"
    #include <stdio.h>
    #include <stdlib.h>
<<<<<<< Updated upstream
=======
    #include <stdarg.h>
    #include<string.h>
>>>>>>> Stashed changes
    #include "symbolTable.h"
    extern FILE *yyin;
    void yyerror(const char *str);
    void read_file(char *filename);

<<<<<<< Updated upstream
=======
    nodeType *opration(int oper, int nops, ...);
    nodeType *identifier(char *name);
    nodeType *constant(int value);
    void freeNode(nodeType *p);

    symbolTable* st = new symbolTable();
>>>>>>> Stashed changes
    Node *currentScope = new Node();
    //printing may be removed
    // extern char* last_token;

<<<<<<< Updated upstream
#line 86 "parser.tab.c"
=======
#line 96 "parser.tab.c"
>>>>>>> Stashed changes

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
  YYSYMBOL_root = 51,                      /* root  */
  YYSYMBOL_statement = 52,                 /* statement  */
  YYSYMBOL_recursive_statement = 53,       /* recursive_statement  */
  YYSYMBOL_conditional_statement = 54,     /* conditional_statement  */
  YYSYMBOL_if_conditional_statement = 55,  /* if_conditional_statement  */
  YYSYMBOL_switch_conditional_statement = 56, /* switch_conditional_statement  */
  YYSYMBOL_case_statement = 57,            /* case_statement  */
  YYSYMBOL_loop_statement = 58,            /* loop_statement  */
  YYSYMBOL_for_loop_statement = 59,        /* for_loop_statement  */
  YYSYMBOL_while_loop_statement = 60,      /* while_loop_statement  */
  YYSYMBOL_do_while_loop_statement = 61,   /* do_while_loop_statement  */
  YYSYMBOL_assignment = 62,                /* assignment  */
  YYSYMBOL_expressions = 63,               /* expressions  */
  YYSYMBOL_first = 64,                     /* first  */
  YYSYMBOL_second = 65,                    /* second  */
  YYSYMBOL_third = 66,                     /* third  */
  YYSYMBOL_fourth = 67,                    /* fourth  */
  YYSYMBOL_fifth = 68,                     /* fifth  */
  YYSYMBOL_sixth = 69,                     /* sixth  */
  YYSYMBOL_seventh = 70,                   /* seventh  */
  YYSYMBOL_function_call = 71,             /* function_call  */
  YYSYMBOL_functional_statement = 72,      /* functional_statement  */
  YYSYMBOL_function_parameters = 73,       /* function_parameters  */
  YYSYMBOL_parameter = 74,                 /* parameter  */
  YYSYMBOL_function_parameters_calls = 75, /* function_parameters_calls  */
  YYSYMBOL_parameter_calls = 76,           /* parameter_calls  */
  YYSYMBOL_function = 77,                  /* function  */
  YYSYMBOL_return_types = 78,              /* return_types  */
  YYSYMBOL_enum_statement = 79,            /* enum_statement  */
  YYSYMBOL_enum_variables = 80,            /* enum_variables  */
  YYSYMBOL_variable_Type = 81,             /* variable_Type  */
  YYSYMBOL_variable_value = 82             /* variable_value  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   466

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

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
static const yytype_uint8 yyrline[] =
{
<<<<<<< Updated upstream
       0,    38,    38,    40,    41,    43,    46,    49,    54,    57,
      60,    63,    69,    71,    74,    77,    80,    83,    86,    89,
      95,    98,   102,   106,   109,   111,   113,   117,   119,   122,
     124,   127,   129,   131,   134,   136,   138,   140,   142,   145,
     147,   149,   152,   154,   156,   158,   161,   163,   165,   168,
     170,   172,   174,   178,   181,   183,   186,   189,   191,   193,
     196,   199,   201,   203,   206,   208,   211,   214,   217,   219,
     221,   223,   227,   230,   233,   236,   239,   243,   245,   247,
     249,   251,   253
=======
       0,    58,    58,    60,    61,    63,    66,    69,    74,    77,
      80,    83,    89,    91,    94,    97,   100,   103,   106,   109,
     115,   118,   122,   126,   130,   132,   134,   138,   140,   143,
     145,   148,   150,   152,   155,   157,   159,   161,   163,   166,
     168,   170,   173,   175,   177,   179,   182,   184,   186,   189,
     191,   193,   195,   199,   202,   204,   207,   210,   212,   214,
     217,   220,   222,   224,   227,   229,   232,   235,   238,   240,
     242,   244,   248,   252,   256,   260,   264,   269,   273,   276,
     278,   280,   282
>>>>>>> Stashed changes
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
  "'*'", "'/'", "'%'", "'!'", "','", "$accept", "root", "statement",
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

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -52,    32,   -52,   -16,    23,    34,    -1,    44,    51,    62,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -18,   -21,   -21,   -21,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,    43,    71,    92,    50,     1,   -28,   105,
     -52,   -52,   -52,   -52,   -52,   -52,    85,   -52,   -21,   418,
     -21,   -52,    87,    37,    86,   -21,   -21,    94,    -6,   -52,
     -52,   -52,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,    17,    15,    98,   106,   108,
      30,    95,   109,   114,   134,    73,    71,   130,   126,    71,
     -52,    92,    50,     1,     1,   -28,   -28,   -28,   -28,   105,
     105,   -52,   -52,   -52,    73,   -21,   140,   145,   -21,   142,
     143,   175,   -52,   146,   -21,   144,   -20,   150,   138,   161,
     -52,   -21,   159,    71,   -52,   -13,   -52,   163,   -52,    71,
     -21,   -52,   171,   168,    73,   -52,    71,   169,   141,   418,
     185,   -21,    -7,    71,   156,   -52,   174,   -52,   204,   173,
     -52,    42,   133,   -52,   -21,   229,   -52,   273,   182,   184,
     -52,   172,    71,   -52,   -21,   -52,   -52,   -52,    71,   176,
     308,   352,   396,   186,   -52,   -52,   -52,   -52
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     1,     0,     0,     0,     0,     0,     0,     0,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    51,     0,     0,     0,     2,     5,    11,    10,     6,
      17,    18,    19,     0,    26,    28,    30,    33,    38,    41,
      45,    48,    52,     3,    54,    55,     0,    50,     0,     0,
       0,     9,     0,     0,     0,    61,     0,    51,     0,    46,
      47,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    57,    63,     0,    60,    24,
      49,    27,    29,    31,    32,    36,    37,    34,    35,    39,
      40,    42,    43,    44,    57,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     0,    71,     0,     0,    56,     0,
      53,     0,     0,    23,     9,     0,     9,     0,    16,    25,
       0,    67,     0,     0,     0,    59,    62,     0,     0,     0,
       0,     0,     0,    70,    69,     9,     0,     9,    13,     0,
      21,     0,     0,    14,     0,     0,    58,     0,     0,     0,
      22,     0,    68,    65,     0,     9,     9,     9,    66,     0,
       0,     0,     0,     0,    12,    20,    15,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   221,   -51,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -46,   -22,   164,   162,    41,    69,    11,   -19,
     -52,   -52,   -52,   123,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,     0,    76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,   112,    81,    26,    27,    28,   142,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,   117,   118,    87,    88,    44,   169,    45,
     116,    79,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      58,    46,   152,    78,    59,    60,    15,    16,    17,    18,
      19,    20,    57,    62,    22,    70,    71,    55,   131,    48,
      62,   139,    56,    23,    66,    67,    76,    24,    80,   132,
      90,   153,     2,    86,    89,     3,    51,     4,     5,     6,
       7,    62,    68,    69,     8,     9,    10,    11,    12,    13,
      14,   106,   104,   101,   102,   103,    62,   105,    49,    15,
      16,    17,    18,    19,    20,    21,   110,    22,    62,    50,
      83,    64,    65,   138,    84,   140,    23,    61,   160,    52,
      24,    99,   100,   123,    53,   119,   125,    10,    11,    12,
      13,    14,   129,   149,   155,    54,   157,    62,     3,   136,
       4,     5,     6,     7,   119,    93,    94,    77,   143,    10,
      11,    12,    13,    14,   170,   171,   172,    63,    75,   151,
      82,    85,    15,    16,    17,    18,    19,    20,    21,    55,
      22,   107,   162,   111,   146,    95,    96,    97,    98,    23,
     108,   109,   168,    24,     3,   113,     4,     5,     6,     7,
      72,    73,    74,    77,   114,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   120,   115,    15,    16,
      17,    18,    19,    20,    21,   121,    22,   124,    83,   148,
     126,   127,   105,   128,   130,    23,   133,   134,     3,    24,
       4,     5,     6,     7,   135,   137,   154,    77,   141,    10,
      11,    12,    13,    14,   144,   145,   147,   156,   158,   159,
     173,   167,    15,    16,    17,    18,    19,    20,    21,   165,
      22,   166,    25,   150,   177,    92,    91,   122,   161,    23,
       0,     0,     3,    24,     4,     5,     6,     7,     0,     0,
       0,    77,     0,    10,    11,    12,    13,    14,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
      19,    20,    21,     0,    22,     0,     0,   163,     0,     0,
       0,     0,     0,    23,     0,     0,     3,    24,     4,     5,
       6,     7,     0,     0,   164,    77,     0,    10,    11,    12,
      13,    14,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,    17,    18,    19,    20,    21,     0,    22,     0,
       0,     3,     0,     4,     5,     6,     7,    23,     0,     0,
      77,    24,    10,    11,    12,    13,    14,     0,     0,     0,
       0,     0,     0,     0,     0,    15,    16,    17,    18,    19,
      20,    21,     0,    22,     0,     0,   174,     0,     0,     0,
       0,     0,    23,     0,     0,     3,    24,     4,     5,     6,
       7,     0,     0,     0,    77,     0,    10,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,    15,
      16,    17,    18,    19,    20,    21,     0,    22,     0,     0,
     175,     0,     0,     0,     0,     0,    23,     0,     0,     3,
      24,     4,     5,     6,     7,     0,   176,     0,    77,     0,
      10,    11,    12,    13,    14,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,    19,    20,    21,
      77,    22,    10,    11,    12,    13,    14,     0,     0,     0,
      23,     0,     0,     0,    24,    15,    16,    17,    18,    19,
      20,    21,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,    24
};

static const yytype_int16 yycheck[] =
{
      22,     1,     9,    49,    23,    24,    27,    28,    29,    30,
      31,    32,    33,    26,    35,    43,    44,    35,    38,    35,
      26,    34,    40,    44,    23,    24,    48,    48,    50,    49,
      36,    38,     0,    55,    56,     3,    37,     5,     6,     7,
       8,    26,    41,    42,    12,    13,    14,    15,    16,    17,
      18,    36,    35,    72,    73,    74,    26,    40,    35,    27,
      28,    29,    30,    31,    32,    33,    36,    35,    26,    35,
      33,    21,    22,   124,    37,   126,    44,    34,    36,    35,
      48,    70,    71,   105,    33,    85,   108,    14,    15,    16,
      17,    18,   114,   139,   145,    33,   147,    26,     3,   121,
       5,     6,     7,     8,   104,    64,    65,    12,   130,    14,
      15,    16,    17,    18,   165,   166,   167,    25,    33,   141,
      33,    35,    27,    28,    29,    30,    31,    32,    33,    35,
      35,    33,   154,    38,   134,    66,    67,    68,    69,    44,
      34,    33,   164,    48,     3,    36,     5,     6,     7,     8,
      45,    46,    47,    12,    40,    14,    15,    16,    17,    18,
      27,    28,    29,    30,    31,    32,    36,    33,    27,    28,
      29,    30,    31,    32,    33,    49,    35,    37,    33,    38,
      37,     6,    40,    37,    40,    44,    36,    49,     3,    48,
       5,     6,     7,     8,    33,    36,    40,    12,    35,    14,
      15,    16,    17,    18,    33,    37,    37,    33,     4,    36,
      34,    39,    27,    28,    29,    30,    31,    32,    33,    37,
      35,    37,     1,    38,    38,    63,    62,   104,   152,    44,
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

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,     0,     3,     5,     6,     7,     8,    12,    13,
      14,    15,    16,    17,    18,    27,    28,    29,    30,    31,
      32,    33,    35,    44,    48,    52,    54,    55,    56,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    77,    79,    81,    82,    35,    35,
      35,    37,    35,    33,    33,    35,    40,    33,    63,    69,
      69,    34,    26,    25,    21,    22,    23,    24,    41,    42,
      43,    44,    45,    46,    47,    33,    63,    12,    62,    81,
      63,    53,    33,    33,    37,    35,    63,    75,    76,    63,
      36,    64,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    69,    69,    69,    35,    40,    36,    33,    34,    33,
      36,    38,    52,    36,    40,    33,    80,    73,    74,    81,
      36,    49,    73,    63,    37,    63,    37,     6,    37,    63,
      40,    38,    49,    36,    49,    33,    63,    36,    53,    34,
      53,    35,    57,    63,    33,    37,    81,    37,    38,    62,
      38,    63,     9,    38,    40,    53,    33,    53,     4,    36,
      36,    82,    63,    38,    11,    37,    37,    39,    63,    78,
      53,    53,    53,    34,    38,    38,    10,    38
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    51,    51,    52,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    57,    57,    58,    58,    58,
      59,    60,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    66,    67,
      67,    67,    68,    68,    68,    68,    69,    69,    69,    70,
      70,    70,    70,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    79,    80,    80,
      80,    80,    81,    81,    81,    81,    81,    82,    82,    82,
      82,    82,    82
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     2,     2,     0,
       1,     1,    11,     7,     7,     6,     0,     1,     1,     1,
      11,     7,     8,     4,     3,     5,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     2,     2,     1,     3,
       1,     1,     1,     4,     1,     1,     1,     0,     4,     2,
       1,     0,     3,     1,    11,     8,     1,     5,     5,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
  case 2: /* root: root statement  */
<<<<<<< Updated upstream
#line 39 "parser.y"
        {printf("root: root statement\n"); printf("-------------------------------------\n");}
#line 1331 "parser.tab.c"
    break;

  case 3: /* root: root functional_statement  */
#line 41 "parser.y"
        {printf("root functional_statement\n"); printf("-------------------------------------\n");}
#line 1337 "parser.tab.c"
    break;

  case 4: /* root: %empty  */
#line 41 "parser.y"
                                                                                                      {printf("root: \n");}
#line 1343 "parser.tab.c"
    break;

  case 5: /* statement: conditional_statement  */
#line 44 "parser.y"
            { printf("statement: conditional_statement\n");}
#line 1349 "parser.tab.c"
    break;

  case 6: /* statement: loop_statement  */
#line 47 "parser.y"
            { printf("statement: loop_statement\n");}
#line 1355 "parser.tab.c"
    break;

  case 7: /* statement: assignment ';'  */
#line 49 "parser.y"
                           { printf("statement: assignment;\n");}
#line 1361 "parser.tab.c"
    break;

  case 8: /* recursive_statement: recursive_statement statement  */
#line 55 "parser.y"
                    {printf("recursive_statement: recursive_statement statement\n");}
#line 1367 "parser.tab.c"
    break;

  case 9: /* recursive_statement: %empty  */
#line 57 "parser.y"
                    {printf("recursive_statement: \n");}
#line 1373 "parser.tab.c"
    break;

  case 10: /* conditional_statement: switch_conditional_statement  */
#line 61 "parser.y"
                        {printf("conditional_statement: switch_conditional_statement\n");}
#line 1379 "parser.tab.c"
    break;

  case 11: /* conditional_statement: if_conditional_statement  */
#line 64 "parser.y"
                        {printf("conditional_statement: if_conditional_statement\n");}
#line 1385 "parser.tab.c"
    break;

  case 12: /* if_conditional_statement: IF '(' expressions ')' '{' recursive_statement '}' ELSE '{' recursive_statement '}'  */
#line 70 "parser.y"
                            {printf("if_conditional_statement: if(exp){recursive_statement} else{recursive_statement}\n");}
#line 1391 "parser.tab.c"
    break;

  case 13: /* if_conditional_statement: IF '(' expressions ')' '{' recursive_statement '}'  */
#line 72 "parser.y"
                            {printf("if_conditional_statement: if(exp){recursive_statement}\n");}
#line 1397 "parser.tab.c"
    break;

  case 14: /* switch_conditional_statement: SWITCH '(' VARIABLE ')' '{' case_statement '}'  */
#line 75 "parser.y"
                                {printf("switch_conditional_statement: switch(VARIABLE){case_statement}\n");}
#line 1403 "parser.tab.c"
    break;

  case 15: /* case_statement: case_statement CASE variable_value ':' recursive_statement BREAK  */
#line 78 "parser.y"
                {printf("case_statement: case_statement case variable_value: recursive_statement break\n");}
#line 1409 "parser.tab.c"
    break;

  case 16: /* case_statement: %empty  */
#line 80 "parser.y"
                {printf("case_statement: \n");}
#line 1415 "parser.tab.c"
    break;

  case 17: /* loop_statement: for_loop_statement  */
#line 84 "parser.y"
                {printf("loop_statement: for_loop_statement\n");}
#line 1421 "parser.tab.c"
    break;

  case 18: /* loop_statement: while_loop_statement  */
#line 87 "parser.y"
                {printf("loop_statement: while_loop_statement\n");}
#line 1427 "parser.tab.c"
    break;

  case 19: /* loop_statement: do_while_loop_statement  */
#line 90 "parser.y"
                {printf("loop_statement: do_while_loop_statement\n");}
#line 1433 "parser.tab.c"
    break;

  case 20: /* for_loop_statement: FOR '(' assignment ';' expressions ';' assignment ')' '{' recursive_statement '}'  */
#line 96 "parser.y"
                    {printf("for_loop_statement: for(assignment; exp; assignment){recursive_statement}\n");}
#line 1439 "parser.tab.c"
    break;

  case 21: /* while_loop_statement: WHILE '(' expressions ')' '{' recursive_statement '}'  */
#line 99 "parser.y"
                    {printf("while_loop_statement: while(exp){recursive_statement}\n");}
#line 1445 "parser.tab.c"
    break;

  case 22: /* do_while_loop_statement: DO '{' recursive_statement '}' WHILE '(' expressions ')'  */
#line 103 "parser.y"
                        {printf("do_while_loop_statement: do{recursive_statement} while{exp}\n");}
#line 1451 "parser.tab.c"
    break;

  case 23: /* assignment: variable_Type VARIABLE '=' expressions  */
#line 107 "parser.y"
            {printf("assignment: variable_Type VARIABLE = exp\n");
            insert((yyvsp[-2].string_val), "variable", (yyvsp[-3].char*), currentScope);}
#line 1458 "parser.tab.c"
    break;

  case 24: /* assignment: VARIABLE '=' expressions  */
#line 110 "parser.y"
            {printf("assignment: VARIABLE = exp\n");}
#line 1464 "parser.tab.c"
    break;

  case 25: /* assignment: ENUM VARIABLE VARIABLE '=' expressions  */
#line 112 "parser.y"
            {printf("assignment: ENUM VARIABLE VARIABLE = exp\n");}
#line 1470 "parser.tab.c"
    break;

  case 26: /* assignment: expressions  */
#line 114 "parser.y"
            {printf("assignment: exp\n");}
#line 1476 "parser.tab.c"
=======
#line 59 "parser.y"
        {printf("root: root statement\n"); printf("-------------------------------------\n");}
#line 1341 "parser.tab.c"
    break;

  case 3: /* root: root functional_statement  */
#line 61 "parser.y"
        {printf("root functional_statement\n"); printf("-------------------------------------\n");}
#line 1347 "parser.tab.c"
    break;

  case 4: /* root: %empty  */
#line 61 "parser.y"
                                                                                                      {printf("root: \n");}
#line 1353 "parser.tab.c"
    break;

  case 5: /* statement: conditional_statement  */
#line 64 "parser.y"
            { printf("statement: conditional_statement\n");}
#line 1359 "parser.tab.c"
    break;

  case 6: /* statement: loop_statement  */
#line 67 "parser.y"
            { printf("statement: loop_statement\n");}
#line 1365 "parser.tab.c"
    break;

  case 7: /* statement: assignment ';'  */
#line 69 "parser.y"
                           { printf("statement: assignment;\n");}
#line 1371 "parser.tab.c"
    break;

  case 8: /* recursive_statement: recursive_statement statement  */
#line 75 "parser.y"
                    {printf("recursive_statement: recursive_statement statement\n");}
#line 1377 "parser.tab.c"
    break;

  case 9: /* recursive_statement: %empty  */
#line 77 "parser.y"
                    {printf("recursive_statement: \n");}
#line 1383 "parser.tab.c"
    break;

  case 10: /* conditional_statement: switch_conditional_statement  */
#line 81 "parser.y"
                        {printf("conditional_statement: switch_conditional_statement\n");}
#line 1389 "parser.tab.c"
    break;

  case 11: /* conditional_statement: if_conditional_statement  */
#line 84 "parser.y"
                        {printf("conditional_statement: if_conditional_statement\n");}
#line 1395 "parser.tab.c"
    break;

  case 12: /* if_conditional_statement: IF '(' expressions ')' '{' recursive_statement '}' ELSE '{' recursive_statement '}'  */
#line 90 "parser.y"
                            {printf("if_conditional_statement: if(exp){recursive_statement} else{recursive_statement}\n");}
#line 1401 "parser.tab.c"
    break;

  case 13: /* if_conditional_statement: IF '(' expressions ')' '{' recursive_statement '}'  */
#line 92 "parser.y"
                            {printf("if_conditional_statement: if(exp){recursive_statement}\n");}
#line 1407 "parser.tab.c"
    break;

  case 14: /* switch_conditional_statement: SWITCH '(' VARIABLE ')' '{' case_statement '}'  */
#line 95 "parser.y"
                                {printf("switch_conditional_statement: switch(VARIABLE){case_statement}\n");}
#line 1413 "parser.tab.c"
    break;

  case 15: /* case_statement: case_statement CASE variable_value ':' recursive_statement BREAK  */
#line 98 "parser.y"
                {printf("case_statement: case_statement case variable_value: recursive_statement break\n");}
#line 1419 "parser.tab.c"
    break;

  case 16: /* case_statement: %empty  */
#line 100 "parser.y"
                {printf("case_statement: \n");}
#line 1425 "parser.tab.c"
    break;

  case 17: /* loop_statement: for_loop_statement  */
#line 104 "parser.y"
                {printf("loop_statement: for_loop_statement\n");}
#line 1431 "parser.tab.c"
    break;

  case 18: /* loop_statement: while_loop_statement  */
#line 107 "parser.y"
                {printf("loop_statement: while_loop_statement\n");}
#line 1437 "parser.tab.c"
    break;

  case 19: /* loop_statement: do_while_loop_statement  */
#line 110 "parser.y"
                {printf("loop_statement: do_while_loop_statement\n");}
#line 1443 "parser.tab.c"
    break;

  case 20: /* for_loop_statement: FOR '(' assignment ';' expressions ';' assignment ')' '{' recursive_statement '}'  */
#line 116 "parser.y"
                    {printf("for_loop_statement: for(assignment; exp; assignment){recursive_statement}\n");}
#line 1449 "parser.tab.c"
    break;

  case 21: /* while_loop_statement: WHILE '(' expressions ')' '{' recursive_statement '}'  */
#line 119 "parser.y"
                    {printf("while_loop_statement: while(exp){recursive_statement}\n");}
#line 1455 "parser.tab.c"
    break;

  case 22: /* do_while_loop_statement: DO '{' recursive_statement '}' WHILE '(' expressions ')'  */
#line 123 "parser.y"
                        {printf("do_while_loop_statement: do{recursive_statement} while{exp}\n");}
#line 1461 "parser.tab.c"
    break;

  case 23: /* assignment: variable_Type VARIABLE '=' expressions  */
#line 127 "parser.y"
            {printf("assignment: variable_Type VARIABLE = exp\n");
            //st->insert($2, "Variable", $1, currentScope);
            }
#line 1469 "parser.tab.c"
    break;

  case 24: /* assignment: VARIABLE '=' expressions  */
#line 131 "parser.y"
            {printf("assignment: VARIABLE = exp\n");}
#line 1475 "parser.tab.c"
    break;

  case 25: /* assignment: ENUM VARIABLE VARIABLE '=' expressions  */
#line 133 "parser.y"
            {printf("assignment: ENUM VARIABLE VARIABLE = exp\n");}
#line 1481 "parser.tab.c"
>>>>>>> Stashed changes
    break;

  case 26: /* assignment: expressions  */
#line 135 "parser.y"
            {printf("assignment: exp\n");}
#line 1487 "parser.tab.c"
    break;

  case 27: /* expressions: expressions OR first  */
<<<<<<< Updated upstream
#line 118 "parser.y"
            {printf("exp: exp || first \n");}
#line 1482 "parser.tab.c"
    break;

  case 28: /* expressions: first  */
#line 120 "parser.y"
            {printf("exp: first \n");}
#line 1488 "parser.tab.c"
    break;

  case 29: /* first: first AND second  */
#line 123 "parser.y"
        {printf("first: first && second\n");}
#line 1494 "parser.tab.c"
    break;

  case 30: /* first: second  */
#line 125 "parser.y"
        {printf("first: second\n");}
#line 1500 "parser.tab.c"
    break;

  case 31: /* second: second EE third  */
#line 128 "parser.y"
        {printf("second: second == third\n");}
#line 1506 "parser.tab.c"
    break;

  case 32: /* second: second NE third  */
#line 130 "parser.y"
        {printf("second: second != third\n");}
#line 1512 "parser.tab.c"
    break;

  case 33: /* second: third  */
#line 132 "parser.y"
        {printf("second: third\n");}
#line 1518 "parser.tab.c"
    break;

  case 34: /* third: third '>' fourth  */
#line 135 "parser.y"
        {printf("third: third > fourth\n");}
#line 1524 "parser.tab.c"
    break;

  case 35: /* third: third '<' fourth  */
#line 137 "parser.y"
        {printf("third: third < fourth\n");}
#line 1530 "parser.tab.c"
    break;

  case 36: /* third: third GE fourth  */
#line 139 "parser.y"
        {printf("third: third >= fourth\n");}
#line 1536 "parser.tab.c"
    break;

  case 37: /* third: third LE fourth  */
#line 141 "parser.y"
        {printf("third: third <= fourth\n");}
#line 1542 "parser.tab.c"
    break;

  case 38: /* third: fourth  */
#line 143 "parser.y"
        {printf("third: fourth\n");}
#line 1548 "parser.tab.c"
    break;

  case 39: /* fourth: fourth '+' fifth  */
#line 146 "parser.y"
        {printf("fourth: fourth + fifth\n");}
#line 1554 "parser.tab.c"
    break;

  case 40: /* fourth: fourth '-' fifth  */
#line 148 "parser.y"
        {printf("fourth: fourth - fifth\n");}
#line 1560 "parser.tab.c"
    break;

  case 41: /* fourth: fifth  */
#line 150 "parser.y"
        {printf("fourth: fifth\n");}
#line 1566 "parser.tab.c"
    break;

  case 42: /* fifth: fifth '*' sixth  */
#line 153 "parser.y"
        {printf("fifth: fifth * sixth\n");}
#line 1572 "parser.tab.c"
    break;

  case 43: /* fifth: fifth '/' sixth  */
#line 155 "parser.y"
        {printf("fifth: fifth / sixth\n");}
#line 1578 "parser.tab.c"
    break;

  case 44: /* fifth: fifth '%' sixth  */
#line 157 "parser.y"
        {printf("fifth: fifth % sixth\n");}
#line 1584 "parser.tab.c"
    break;

  case 45: /* fifth: sixth  */
#line 159 "parser.y"
        {printf("fifth: sixth\n");}
#line 1590 "parser.tab.c"
    break;

  case 46: /* sixth: '-' sixth  */
#line 162 "parser.y"
        {printf("sixth: - sixth\n");}
#line 1596 "parser.tab.c"
    break;

  case 47: /* sixth: '!' sixth  */
#line 164 "parser.y"
        {printf("sixth: ! sixth\n");}
#line 1602 "parser.tab.c"
    break;

  case 48: /* sixth: seventh  */
#line 166 "parser.y"
        {printf("sixth: seventh\n");}
#line 1608 "parser.tab.c"
    break;

  case 49: /* seventh: '(' expressions ')'  */
#line 169 "parser.y"
        {printf("seventh: (exp)\n");}
#line 1614 "parser.tab.c"
    break;

  case 50: /* seventh: variable_value  */
#line 171 "parser.y"
        {printf("seventh: variable_value\n");}
#line 1620 "parser.tab.c"
    break;

  case 51: /* seventh: VARIABLE  */
#line 173 "parser.y"
        {printf("seventh: VARIABLE\n");}
#line 1626 "parser.tab.c"
    break;

  case 52: /* seventh: function_call  */
#line 175 "parser.y"
        {printf("seventh: function_call\n");}
#line 1632 "parser.tab.c"
    break;

  case 53: /* function_call: VARIABLE '(' function_parameters_calls ')'  */
#line 179 "parser.y"
                {printf("function_call: VARIABLE (function_parameters_calls)\n");}
#line 1638 "parser.tab.c"
    break;

  case 54: /* functional_statement: function  */
#line 182 "parser.y"
                    {printf("functional_statement: function\n");}
#line 1644 "parser.tab.c"
    break;

  case 55: /* functional_statement: enum_statement  */
#line 184 "parser.y"
                    {printf("functional_statement: enum_statement\n");}
#line 1650 "parser.tab.c"
    break;

  case 56: /* function_parameters: parameter  */
#line 187 "parser.y"
                    {printf("function_parameters: parameter\n");}
#line 1656 "parser.tab.c"
    break;

  case 57: /* function_parameters: %empty  */
#line 189 "parser.y"
                    {printf("function_parameters: \n");}
#line 1662 "parser.tab.c"
    break;

  case 58: /* parameter: parameter ',' variable_Type VARIABLE  */
#line 192 "parser.y"
            {printf("parameter: parameter, variable_Type VARIABLE\n");}
#line 1668 "parser.tab.c"
    break;

  case 59: /* parameter: variable_Type VARIABLE  */
#line 194 "parser.y"
            {printf("parameter: variable_Type VARIABLE\n");}
#line 1674 "parser.tab.c"
    break;

  case 60: /* function_parameters_calls: parameter_calls  */
#line 197 "parser.y"
                            {printf("function_parameters_calls: parameter_calls\n");}
#line 1680 "parser.tab.c"
    break;

  case 61: /* function_parameters_calls: %empty  */
#line 199 "parser.y"
                            {printf("function_parameters_calls: \n");}
#line 1686 "parser.tab.c"
    break;

  case 62: /* parameter_calls: parameter_calls ',' expressions  */
#line 202 "parser.y"
                {printf("parameter_calls: parameter_calls, exp\n");}
#line 1692 "parser.tab.c"
    break;

  case 63: /* parameter_calls: expressions  */
#line 204 "parser.y"
                {printf("parameter_calls: exp\n");}
#line 1698 "parser.tab.c"
    break;

  case 64: /* function: variable_Type VARIABLE '(' function_parameters ')' '{' recursive_statement RETURN return_types ';' '}'  */
#line 207 "parser.y"
        {printf("function: variable_Type  (function_parameters){recursive_statement RETURN return_types ;}\n");}
#line 1704 "parser.tab.c"
    break;

  case 65: /* function: VOID VARIABLE '(' function_parameters ')' '{' recursive_statement '}'  */
#line 209 "parser.y"
        {printf("function: void VARIABLE (function_parameters) {recursive_statement}\n");}
#line 1710 "parser.tab.c"
    break;

  case 66: /* return_types: expressions  */
#line 212 "parser.y"
                {printf("return_types: expressions\n");}
#line 1716 "parser.tab.c"
    break;

  case 67: /* enum_statement: ENUM VARIABLE '{' enum_variables '}'  */
#line 215 "parser.y"
                {printf("enum_statement: enum VARIABLE {enum_variables}\n");}
#line 1722 "parser.tab.c"
    break;

  case 68: /* enum_variables: enum_variables ',' VARIABLE '=' expressions  */
#line 218 "parser.y"
                {printf("enum_variables: enum_variables, VARIABLE = exp\n");}
#line 1728 "parser.tab.c"
    break;

  case 69: /* enum_variables: enum_variables ',' VARIABLE  */
#line 220 "parser.y"
                {printf("enum_variables: enum_variables, VARIABLE\n");}
#line 1734 "parser.tab.c"
    break;

  case 70: /* enum_variables: VARIABLE '=' expressions  */
#line 222 "parser.y"
                {printf("enum_variables:VARIABLE = exp\n");}
#line 1740 "parser.tab.c"
    break;

  case 71: /* enum_variables: VARIABLE  */
#line 224 "parser.y"
                {printf("enum_variables: VARIABLE\n");}
#line 1746 "parser.tab.c"
    break;

  case 72: /* variable_Type: INT_TYPE  */
#line 228 "parser.y"
                {printf("variable_Type: int\n");
                (yyval.char*) = "int";}
#line 1753 "parser.tab.c"
    break;

  case 73: /* variable_Type: CHAR_TYPE  */
#line 231 "parser.y"
                {printf("variable_Type: char\n"
                (yyval.char*) = "char");}
#line 1760 "parser.tab.c"
    break;

  case 74: /* variable_Type: BOOL_TYPE  */
#line 234 "parser.y"
                {printf("variable_Type: bool\n");
                (yyval.char*) = "bool";}
#line 1767 "parser.tab.c"
    break;

  case 75: /* variable_Type: FLOAT_TYPE  */
#line 237 "parser.y"
                {printf("variable_Type: float\n");
                (yyval.char*) = "float";}
#line 1774 "parser.tab.c"
    break;

  case 76: /* variable_Type: STRING_TYPE  */
#line 240 "parser.y"
                {printf("variable_Type: strng\n");
                (yyval.char*) = "string";}
#line 1781 "parser.tab.c"
    break;

  case 77: /* variable_value: INTEGER  */
#line 244 "parser.y"
                {printf("variable_value: int value \n");}
#line 1787 "parser.tab.c"
    break;

  case 78: /* variable_value: FLOAT  */
#line 246 "parser.y"
                {printf("variable_value: float value \n");}
#line 1793 "parser.tab.c"
    break;

  case 79: /* variable_value: BOOL_FALSE  */
#line 248 "parser.y"
                {printf("variable_value: false \n");}
#line 1799 "parser.tab.c"
    break;

  case 80: /* variable_value: BOOL_TRUE  */
#line 250 "parser.y"
                {printf("variable_value: true \n");}
#line 1805 "parser.tab.c"
    break;

  case 81: /* variable_value: CHAR  */
#line 252 "parser.y"
                {printf("variable_value: char value \n");}
#line 1811 "parser.tab.c"
    break;

  case 82: /* variable_value: STRING  */
#line 254 "parser.y"
                {printf("variable_value: string value \n");}
#line 1817 "parser.tab.c"
    break;


#line 1821 "parser.tab.c"
=======
#line 139 "parser.y"
            {printf("exp: exp || first \n");}
#line 1493 "parser.tab.c"
    break;

  case 28: /* expressions: first  */
#line 141 "parser.y"
            {printf("exp: first \n");}
#line 1499 "parser.tab.c"
    break;

  case 29: /* first: first AND second  */
#line 144 "parser.y"
        {printf("first: first && second\n");}
#line 1505 "parser.tab.c"
    break;

  case 30: /* first: second  */
#line 146 "parser.y"
        {printf("first: second\n");}
#line 1511 "parser.tab.c"
    break;

  case 31: /* second: second EE third  */
#line 149 "parser.y"
        {printf("second: second == third\n");}
#line 1517 "parser.tab.c"
    break;

  case 32: /* second: second NE third  */
#line 151 "parser.y"
        {printf("second: second != third\n");}
#line 1523 "parser.tab.c"
    break;

  case 33: /* second: third  */
#line 153 "parser.y"
        {printf("second: third\n");}
#line 1529 "parser.tab.c"
    break;

  case 34: /* third: third '>' fourth  */
#line 156 "parser.y"
        {printf("third: third > fourth\n");}
#line 1535 "parser.tab.c"
    break;

  case 35: /* third: third '<' fourth  */
#line 158 "parser.y"
        {printf("third: third < fourth\n");}
#line 1541 "parser.tab.c"
    break;

  case 36: /* third: third GE fourth  */
#line 160 "parser.y"
        {printf("third: third >= fourth\n");}
#line 1547 "parser.tab.c"
    break;

  case 37: /* third: third LE fourth  */
#line 162 "parser.y"
        {printf("third: third <= fourth\n");}
#line 1553 "parser.tab.c"
    break;

  case 38: /* third: fourth  */
#line 164 "parser.y"
        {printf("third: fourth\n");}
#line 1559 "parser.tab.c"
    break;

  case 39: /* fourth: fourth '+' fifth  */
#line 167 "parser.y"
        {printf("fourth: fourth + fifth\n");}
#line 1565 "parser.tab.c"
    break;

  case 40: /* fourth: fourth '-' fifth  */
#line 169 "parser.y"
        {printf("fourth: fourth - fifth\n");}
#line 1571 "parser.tab.c"
    break;

  case 41: /* fourth: fifth  */
#line 171 "parser.y"
        {printf("fourth: fifth\n");}
#line 1577 "parser.tab.c"
    break;

  case 42: /* fifth: fifth '*' sixth  */
#line 174 "parser.y"
        {printf("fifth: fifth * sixth\n");}
#line 1583 "parser.tab.c"
    break;

  case 43: /* fifth: fifth '/' sixth  */
#line 176 "parser.y"
        {printf("fifth: fifth / sixth\n");}
#line 1589 "parser.tab.c"
    break;

  case 44: /* fifth: fifth '%' sixth  */
#line 178 "parser.y"
        {printf("fifth: fifth %% sixth\n");}
#line 1595 "parser.tab.c"
    break;

  case 45: /* fifth: sixth  */
#line 180 "parser.y"
        {printf("fifth: sixth\n");}
#line 1601 "parser.tab.c"
    break;

  case 46: /* sixth: '-' sixth  */
#line 183 "parser.y"
        {printf("sixth: - sixth\n");}
#line 1607 "parser.tab.c"
    break;

  case 47: /* sixth: '!' sixth  */
#line 185 "parser.y"
        {printf("sixth: ! sixth\n");}
#line 1613 "parser.tab.c"
    break;

  case 48: /* sixth: seventh  */
#line 187 "parser.y"
        {printf("sixth: seventh\n");}
#line 1619 "parser.tab.c"
    break;

  case 49: /* seventh: '(' expressions ')'  */
#line 190 "parser.y"
        {printf("seventh: (exp)\n");}
#line 1625 "parser.tab.c"
    break;

  case 50: /* seventh: variable_value  */
#line 192 "parser.y"
        {printf("seventh: variable_value\n");}
#line 1631 "parser.tab.c"
    break;

  case 51: /* seventh: VARIABLE  */
#line 194 "parser.y"
        {printf("seventh: VARIABLE\n");}
#line 1637 "parser.tab.c"
    break;

  case 52: /* seventh: function_call  */
#line 196 "parser.y"
        {printf("seventh: function_call\n");}
#line 1643 "parser.tab.c"
    break;

  case 53: /* function_call: VARIABLE '(' function_parameters_calls ')'  */
#line 200 "parser.y"
                {printf("function_call: VARIABLE (function_parameters_calls)\n");}
#line 1649 "parser.tab.c"
    break;

  case 54: /* functional_statement: function  */
#line 203 "parser.y"
                    {printf("functional_statement: function\n");}
#line 1655 "parser.tab.c"
    break;

  case 55: /* functional_statement: enum_statement  */
#line 205 "parser.y"
                    {printf("functional_statement: enum_statement\n");}
#line 1661 "parser.tab.c"
    break;

  case 56: /* function_parameters: parameter  */
#line 208 "parser.y"
                    {printf("function_parameters: parameter\n");}
#line 1667 "parser.tab.c"
    break;

  case 57: /* function_parameters: %empty  */
#line 210 "parser.y"
                    {printf("function_parameters: \n");}
#line 1673 "parser.tab.c"
    break;

  case 58: /* parameter: parameter ',' variable_Type VARIABLE  */
#line 213 "parser.y"
            {printf("parameter: parameter, variable_Type VARIABLE\n");}
#line 1679 "parser.tab.c"
    break;

  case 59: /* parameter: variable_Type VARIABLE  */
#line 215 "parser.y"
            {printf("parameter: variable_Type VARIABLE\n");}
#line 1685 "parser.tab.c"
    break;

  case 60: /* function_parameters_calls: parameter_calls  */
#line 218 "parser.y"
                            {printf("function_parameters_calls: parameter_calls\n");}
#line 1691 "parser.tab.c"
    break;

  case 61: /* function_parameters_calls: %empty  */
#line 220 "parser.y"
                            {printf("function_parameters_calls: \n");}
#line 1697 "parser.tab.c"
    break;

  case 62: /* parameter_calls: parameter_calls ',' expressions  */
#line 223 "parser.y"
                {printf("parameter_calls: parameter_calls, exp\n");}
#line 1703 "parser.tab.c"
    break;

  case 63: /* parameter_calls: expressions  */
#line 225 "parser.y"
                {printf("parameter_calls: exp\n");}
#line 1709 "parser.tab.c"
    break;

  case 64: /* function: variable_Type VARIABLE '(' function_parameters ')' '{' recursive_statement RETURN return_types ';' '}'  */
#line 228 "parser.y"
        {printf("function: variable_Type  (function_parameters){recursive_statement RETURN return_types ;}\n");}
#line 1715 "parser.tab.c"
    break;

  case 65: /* function: VOID VARIABLE '(' function_parameters ')' '{' recursive_statement '}'  */
#line 230 "parser.y"
        {printf("function: void VARIABLE (function_parameters) {recursive_statement}\n");}
#line 1721 "parser.tab.c"
    break;

  case 66: /* return_types: expressions  */
#line 233 "parser.y"
                {printf("return_types: expressions\n");}
#line 1727 "parser.tab.c"
    break;

  case 67: /* enum_statement: ENUM VARIABLE '{' enum_variables '}'  */
#line 236 "parser.y"
                {printf("enum_statement: enum VARIABLE {enum_variables}\n");}
#line 1733 "parser.tab.c"
    break;

  case 68: /* enum_variables: enum_variables ',' VARIABLE '=' expressions  */
#line 239 "parser.y"
                {printf("enum_variables: enum_variables, VARIABLE = exp\n");}
#line 1739 "parser.tab.c"
    break;

  case 69: /* enum_variables: enum_variables ',' VARIABLE  */
#line 241 "parser.y"
                {printf("enum_variables: enum_variables, VARIABLE\n");}
#line 1745 "parser.tab.c"
    break;

  case 70: /* enum_variables: VARIABLE '=' expressions  */
#line 243 "parser.y"
                {printf("enum_variables:VARIABLE = exp\n");}
#line 1751 "parser.tab.c"
    break;

  case 71: /* enum_variables: VARIABLE  */
#line 245 "parser.y"
                {printf("enum_variables: VARIABLE\n");}
#line 1757 "parser.tab.c"
    break;

  case 72: /* variable_Type: INT_TYPE  */
#line 249 "parser.y"
                {printf("variable_Type: int\n");
                //$$ = (char*)"int";
                }
#line 1765 "parser.tab.c"
    break;

  case 73: /* variable_Type: CHAR_TYPE  */
#line 253 "parser.y"
                {printf("variable_Type: char\n");
                //$$ = (char*)"char";
                }
#line 1773 "parser.tab.c"
    break;

  case 74: /* variable_Type: BOOL_TYPE  */
#line 257 "parser.y"
                {printf("variable_Type: bool\n");
                //$$ = (char*)"bool";
                }
#line 1781 "parser.tab.c"
    break;

  case 75: /* variable_Type: FLOAT_TYPE  */
#line 261 "parser.y"
                {printf("variable_Type: float\n");
                //$$ = (char*)"float";
                }
#line 1789 "parser.tab.c"
    break;

  case 76: /* variable_Type: STRING_TYPE  */
#line 265 "parser.y"
                {printf("variable_Type: string\n");
                //$$ = (char*)"string";
                }
#line 1797 "parser.tab.c"
    break;

  case 77: /* variable_value: INTEGER  */
#line 270 "parser.y"
                {printf("variable_value: int value \n");
                (yyval.node) = constant((yyvsp[0].integer_val));
                }
#line 1805 "parser.tab.c"
    break;

  case 78: /* variable_value: FLOAT  */
#line 274 "parser.y"
                {printf("variable_value: float value \n");
                }
#line 1812 "parser.tab.c"
    break;

  case 79: /* variable_value: BOOL_FALSE  */
#line 277 "parser.y"
                {printf("variable_value: false \n");}
#line 1818 "parser.tab.c"
    break;

  case 80: /* variable_value: BOOL_TRUE  */
#line 279 "parser.y"
                {printf("variable_value: true \n");}
#line 1824 "parser.tab.c"
    break;

  case 81: /* variable_value: CHAR  */
#line 281 "parser.y"
                {printf("variable_value: char value \n");}
#line 1830 "parser.tab.c"
    break;

  case 82: /* variable_value: STRING  */
#line 283 "parser.y"
                {printf("variable_value: string value \n");}
#line 1836 "parser.tab.c"
    break;


#line 1840 "parser.tab.c"
>>>>>>> Stashed changes

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
  yyerror (YY_("memory exhausted"));
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

<<<<<<< Updated upstream
#line 257 "parser.y"
=======
#line 286 "parser.y"
>>>>>>> Stashed changes


#define SIZEOF_NODETYPE ((char*)&p->constant - (char*)p)

nodeType *constant(int value) {
    nodeType *p;
    if ((p = (nodeType* )malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Constant_Node;
    p->constant.value = value;
    return p;
}

nodeType *variable(char* i) {
    nodeType *p;
    if ((p = (nodeType *)malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = Identifier_Node;
    p->identifier.name = i;
    return p;
}

nodeType *opration(int oper, int nops, ...) {
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

void yyerror(const char *str)
{
    fprintf(stderr,"error: %s, Last token:\n%s \n",str, last_token);
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

    print(currentScope);

    yyin = fp;

    yyparse();

    fclose(fp);
    return 0;
}

