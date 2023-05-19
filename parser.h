#pragma once
#include <stdbool.h>

typedef enum {
    Constant_Node,
    Identifier_Node,
    Operator_Node,
    Type_Node
} nodeEnum;

typedef enum {
    IntType,
    FloatType,
    StringType,
    BoolType,
    VoidType,
    CharType,
    EnumType,
    ConstType,
    Error,
} typeEnum;

typedef struct {
    char* name;
} IdentifierNodeType;

typedef struct {
    typeEnum constType;
    union
    {
        int intVal;
        float floatVal;
        char* stringVal;
        bool boolVal;  
        char charVal;
    };
} ConstantNodeType;

typedef struct {
    int oper;
    int nops;
    struct nodeTypeTag *op[1];
} OperatorNodeType;

typedef struct {
    typeEnum type;
} TypeNodeType;


typedef struct nodeTypeTag {
    nodeEnum type;
    union {
        ConstantNodeType constant;
        IdentifierNodeType identifier;
        OperatorNodeType oper;
        TypeNodeType defineType;
    };
} nodeType;