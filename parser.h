#pragma once
#include <stdbool.h>
#include<vector>
using namespace std; 

typedef enum {
    Constant_Node,
    Identifier_Node,
    Operator_Node,
    Type_Node,
    ArgumentNode
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
typedef struct {
    vector<typeEnum> arguments;
    vector<char*> argumentsNames;
} ArgumentNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;
    union {
        ConstantNodeType constant;
        IdentifierNodeType identifier;
        OperatorNodeType oper;
        TypeNodeType defineType;
        ArgumentNodeType argumentType;
    };
} nodeType;