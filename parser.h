#pragma once
#include <stdbool.h>

typedef enum {
    Constant_Node,
    Identifier_Node,
    Operator_Node
} nodeEnum;

typedef struct {
    char* name;
} IdentifierNodeType;

typedef struct {
    int value;
} ConstantNodeType;

typedef struct {
    int oper;
    int nops;
    struct nodeTypeTag *op[1];
} OperatorNodeType;


typedef struct nodeTypeTag {
    nodeEnum type;
    union {
        ConstantNodeType constant;
        IdentifierNodeType identifier;
        OperatorNodeType oper;
    };
} nodeType;