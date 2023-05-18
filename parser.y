%{
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
%}

%code requires{
        #include "parser.h"
}


%union {
    int integer_val;
    char* string_val;
    float float_val;
    char char_val;
    bool bool_val;
    nodeType* node;
}

%token IF ELSE FOR WHILE DO SWITCH CASE BREAK RETURN ENUM VOID 
%token INT_TYPE CHAR_TYPE BOOL_TYPE FLOAT_TYPE STRING_TYPE CONST
%token PRINT 
%token <string_val> EE NE GE LE AND OR
%token <integer_val> INTEGER 
%token <float_val> FLOAT 
%token <integer_val> BOOL_FALSE BOOL_TRUE 
%token <char_val> CHAR 
%token <string_val> STRING 
%token <string_val> VARIABLE

%type <node> statement recursive_statement conditional_statement
                if_conditional_statement switch_conditional_statement
                case_statement loop_statement for_loop_statement
                while_loop_statement do_while_loop_statement assignment
                expressions first second third fourth fifth sixth seventh
                function_call functional_statement function_parameters parameter
                function_parameters_calls parameter_calls function return_types
                enum_statement enum_variables variable_Type variable_value

%%

program: root {printf("end of program\n");}
         ;


root:   root statement 
        {printf("root: root statement\n"); printf("-------------------------------------\n");
        execute($2);
        } 
        | root functional_statement 
        {printf("root functional_statement\n"); printf("-------------------------------------\n");
        execute($2);
        } 
        | 
        {printf("root: \n");}
        ;

statement:  conditional_statement 
            { printf("statement: conditional_statement\n");
            $$=$1;
            } 
            |  
            loop_statement 
            { printf("statement: loop_statement\n");
            $$=$1;
            } 
            |  
            assignment ';' 
            { printf("statement: assignment;\n");
            $$=$1;
            } 
            ;
//! rule useless 
            // |
            // ;
            
recursive_statement: recursive_statement statement 
                    {printf("recursive_statement: recursive_statement statement\n");
                    $$=operation(';',2,$1,$2);
                    } 
                    | 
                    {printf("recursive_statement: \n");
                    $$=NULL;
                    }
                    ;
            
//---------conditional statement---------// 
conditional_statement:  switch_conditional_statement 
                        {printf("conditional_statement: switch_conditional_statement\n");
                        $$=$1;
                        } 
                        |
                        if_conditional_statement 
                        {printf("conditional_statement: if_conditional_statement\n");
                        $$=$1;
                        } 
                        ;
//! rule useless
                        // |
                        // ;

if_conditional_statement:   IF '(' expressions ')' '{'recursive_statement'}'  ELSE '{'recursive_statement'}' 
                            {printf("if_conditional_statement: if(exp){recursive_statement} else{recursive_statement}\n");
                            $$=operation(IF,3,$3,$6,$10);
                            } 
                            | IF '(' expressions ')' '{'recursive_statement'}' 
                            {printf("if_conditional_statement: if(exp){recursive_statement}\n");
                            $$=operation(IF,2,$3,$6);
                            }
                            ; 

switch_conditional_statement:   SWITCH '('VARIABLE')' '{' case_statement '}' 
                                {printf("switch_conditional_statement: switch(VARIABLE){case_statement}\n");
                                $$=operation(SWITCH,2,$3,$6);
                                } 
                                ;

case_statement: case_statement CASE variable_value ':' recursive_statement BREAK  
                {printf("case_statement: case_statement case variable_value: recursive_statement break\n");
                $$=operation(CASE,3,$1,$3,$5);
                } 
                |  
                {printf("case_statement: \n");
                $$=NULL;
                } 
                ; //? hna lazem nzwd elvalues elly elmafrood treturn

//---------loop statement---------// 
loop_statement: for_loop_statement  
                {printf("loop_statement: for_loop_statement\n");
                $$=$1;
                } 
                | 
                while_loop_statement 
                {printf("loop_statement: while_loop_statement\n");
                $$=$1;
                } 
                | 
                do_while_loop_statement 
                {printf("loop_statement: do_while_loop_statement\n");
                $$=$1;
                } 
                ;
//! rule useless                
                // | 
                // ;

for_loop_statement: FOR '(' assignment ';' expressions ';' assignment')' '{' recursive_statement '}' 
                    {printf("for_loop_statement: for(assignment; exp; assignment){recursive_statement}\n");
                    $$=operation(FOR,4,$3,$5,$7,$10);
                    } // hna lazem nzwd elvalues elly elmafrood treturn
                    ;

while_loop_statement: WHILE '(' expressions ')' '{' recursive_statement '}'  
                    {printf("while_loop_statement: while(exp){recursive_statement}\n");
                    $$=operation(WHILE,2,$3,$6);
                    } 
                    ;


do_while_loop_statement: DO '{' recursive_statement '}' WHILE '(' expressions ')'  
                        {printf("do_while_loop_statement: do{recursive_statement} while{exp}\n");
                        $$=operation(DO,2,$3,$7);
                        }
                        ;

//-------------assignments-------------//
assignment: variable_Type VARIABLE '=' expressions  
            {
            printf("assignment: variable_Type VARIABLE = exp\n");
            $$=operation('=',3,$1,identifier($2),$4);
            } 
            | VARIABLE '=' expressions  
            {printf("assignment: VARIABLE = exp\n");
            $$=operation('=',2,identifier($1),$3);
            }  
            | ENUM VARIABLE VARIABLE '=' expressions 
            {printf("assignment: ENUM VARIABLE VARIABLE = exp\n");
            $$=operation('=',4,defineType(EnumType),identifier($2),identifier($3),$5);
            } 
            | CONST variable_Type VARIABLE '=' expressions
            {
            printf("assignment: CONST variable_Type VARIABLE = exp\n");
            $$=operation('=',4,defineType(ConstType),$2,identifier($3),$5);
            }
            | expressions  
            {printf("assignment: exp\n");
            $$ = $1;
            }
            ;  //? hna lazem nzwd elvalues elly elmafrood treturn

//------------Expressions-------------//
expressions: expressions OR first 
            {printf("exp: exp || first \n");
            $$=operation(OR,2,$1,$3);
            } 
            | first  
            {printf("exp: first \n");
            $$=$1;
            }
            ;

first: first AND second 
        {printf("first: first && second\n");
        $$=operation(AND,2,$1,$3);
        } 
        | second 
        {printf("first: second\n");
        $$=$1;
        }
        ; 

second: second EE third 
        {printf("second: second == third\n");
        $$=operation(EE,2,$1,$3);
        } 
        | second NE third  
        {printf("second: second != third\n");
        $$=operation(NE,2,$1,$3);
        } 
        | third  
        {printf("second: third\n");
        $$=$1;
        } 
        ;

third:  third '>' fourth 
        {printf("third: third > fourth\n");
        $$=operation('>',2,$1,$3);
        } 
        | third '<' fourth 
        {printf("third: third < fourth\n");
        $$=operation('<',2,$1,$3);
        } 
        | third GE fourth 
        {printf("third: third >= fourth\n");
        $$=operation(GE,2,$1,$3);
        } 
        | third LE fourth 
        {printf("third: third <= fourth\n");
        $$=operation(LE,2,$1,$3);
        } 
        | fourth 
        {printf("third: fourth\n");
        $$=$1;
        }
        ;

fourth: fourth '+' fifth 
        {printf("fourth: fourth + fifth\n");
        $$=operation('+',2,$1,$3);
        } 
        | fourth '-' fifth 
        {printf("fourth: fourth - fifth\n");
        $$=operation('-',2,$1,$3);
        } 
        | fifth 
        {printf("fourth: fifth\n");
        $$=$1;
        } 
        ;

fifth:  fifth '*' sixth 
        {printf("fifth: fifth * sixth\n");
        $$=operation('*',2,$1,$3);
        } 
        | fifth '/' sixth 
        {printf("fifth: fifth / sixth\n");
        $$=operation('/',2,$1,$3);
        } 
        | fifth '%' sixth 
        {printf("fifth: fifth %% sixth\n");
        $$=operation('%',2,$1,$3);
        } 
        | sixth 
        {printf("fifth: sixth\n");
        $$=$1;
        }
        ; 

sixth:  '-' sixth  
        {printf("sixth: - sixth\n");
        $$=operation('-',1,$2);
        } 
        | '!' sixth 
        {printf("sixth: ! sixth\n");
        $$=operation('!',1,$2);
        } 
        | seventh  
        {printf("sixth: seventh\n");
        $$=$1;
        } 
        ;

seventh: '(' expressions ')' 
        {printf("seventh: (exp)\n");
        $$=$2;
        } 
        | variable_value  
        {printf("seventh: variable_value\n");
        $$ = $1;
        } 
        | VARIABLE 
        {printf("seventh: VARIABLE\n");
        $$ = identifier($1);
        } 
        | function_call 
        {printf("seventh: function_call\n");
        $$=$1;
        }
        ; 

//------------functions---------------//
function_call:  VARIABLE '(' function_parameters_calls ')' 
                {printf("function_call: VARIABLE (function_parameters_calls)\n");
                $$=operation('f',2,identifier($1),$3);
                }
                ;

functional_statement: function 
                    {printf("functional_statement: function\n");
                    $$=$1;
                    }
                    | enum_statement 
                    {printf("functional_statement: enum_statement\n");
                    $$=$1;
                    }
                    ;

function_parameters: parameter 
                    {printf("function_parameters: parameter\n");
                    $$=$1;
                    } 
                    | 
                    {printf("function_parameters: \n");
                    $$=NULL;
                    }
                    ;  //? semi colon not added yet?

parameter:  parameter ',' variable_Type VARIABLE  
            {printf("parameter: parameter, variable_Type VARIABLE\n");
            $$=operation('p',3,$3,identifier($4),$1);
            } 
            | variable_Type VARIABLE 
            {printf("parameter: variable_Type VARIABLE\n");
            $$=operation('p',2,$1,identifier($2));
            } 
            ;

function_parameters_calls:  parameter_calls 
                            {printf("function_parameters_calls: parameter_calls\n");
                            $$=$1;
                            } 
                            | 
                            {printf("function_parameters_calls: \n");
                            $$=NULL;
                            }
                            ; 

parameter_calls: parameter_calls ',' expressions 
                {printf("parameter_calls: parameter_calls, exp\n");
                $$=operation('c',2,$1,$3);
                } 
                | expressions 
                {printf("parameter_calls: exp\n");
                $$=$1;
                } 
                ;

function: variable_Type VARIABLE '(' function_parameters ')' '{' recursive_statement RETURN return_types';' '}'  
        {printf("function: variable_Type  (function_parameters){recursive_statement RETURN return_types ;}\n");
        $$=operation('d',5,$1,identifier($2),$4,$7,$9);
        } 
        | VOID VARIABLE '(' function_parameters ')' '{' recursive_statement '}' 
        {printf("function: void VARIABLE (function_parameters) {recursive_statement}\n");
        $$=operation('d',4,defineType(VoidType),identifier($2),$4,$7);
        } 
        ;

return_types:   expressions  
                {printf("return_types: expressions\n");
                $$=$1;
                }
                ;

enum_statement: ENUM VARIABLE '{'enum_variables'}' 
                {printf("enum_statement: enum VARIABLE {enum_variables}\n");
                $$=operation(ENUM,2,identifier($2),$4);
                }
                ; 

enum_variables:  enum_variables ',' VARIABLE '=' expressions 
                {printf("enum_variables: enum_variables, VARIABLE = exp\n");
                $$=operation(',',3,$1,identifier($3),$5);
                } 
                | enum_variables ',' VARIABLE 
                {printf("enum_variables: enum_variables, VARIABLE\n");
                $$=operation(',',2,$1,identifier($3));
                } 
                | VARIABLE '=' expressions 
                {printf("enum_variables:VARIABLE = exp\n");
                $$=operation(',',2,identifier($1),$3);
                } 
                | VARIABLE 
                {printf("enum_variables: VARIABLE\n");
                $$=operation(',',1,identifier($1));
                } 
                ;

//------------variables---------------//
variable_Type:  INT_TYPE  
                {printf("variable_Type: int\n");
                $$ = defineType(IntType);
                } 
                | CHAR_TYPE 
                {printf("variable_Type: char\n");
                $$ = defineType(CharType);
                } 
                | BOOL_TYPE 
                {printf("variable_Type: bool\n");
                $$ = defineType(BoolType);
                } 
                | FLOAT_TYPE 
                {printf("variable_Type: float\n");
                $$ = defineType(FloatType);
                } 
                | STRING_TYPE 
                {printf("variable_Type: string\n");
                $$ = defineType(StringType);
                }
                ;  

variable_value: INTEGER  
                {printf("variable_value: int value \n");
                $$ = constantInteger($1);
                } 
                | FLOAT 
                {printf("variable_value: float value \n");
                $$ = constantFloat($1);
                } 
                | BOOL_FALSE 
                {printf("variable_value: false \n");
                $$ = constantBool($1);
                } 
                | BOOL_TRUE 
                {printf("variable_value: true \n");
                $$ = constantBool($1);
                } 
                | CHAR 
                {printf("variable_value: char value \n");
                $$ = constantChar($1);
                } 
                | STRING
                {printf("variable_value: string value \n");
                $$ = constantString($1);
                } 
                ;//? hna lazem nzwd elvalues elly elmafrood treturn


%%

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
                    currentScope=st->switchScope(currentScope);
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
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case FOR:
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
                case WHILE:
                { 
                    //switch scope
                    currentScope=st->switchScope(currentScope);
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case DO:
                {
                    //switch scope
                    currentScope=st->switchScope(currentScope);
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
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
                    currentScope=st->switchScope(currentScope);
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    execute(p->oper.op[2]);
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
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
                    //insert in symbol table
                    bool isInserted = st->insert(p->oper.op[0]->identifier.name,"enum",6,currentScope);
                    printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[0]->identifier.name,isInserted);
                    if(!isInserted){
                        yyerror("ERROR: variable already exists in the current scope");
                    }
                    //switch scope
                    currentScope=st->switchScope(currentScope);
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
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
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            break;
                        case 3:{
                            //insert in symbol table
                            bool isInserted = st->insert(p->oper.op[1]->identifier.name,"variable",p->oper.op[0]->defineType.type,currentScope);
                            printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                            if(!isInserted){
                                yyerror("ERROR: variable already exists in the current scope");
                            }
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            execute(p->oper.op[2]);
                            //st->print(currentScope);
                            break;
                        } 
                        case 4: //enum => enum enum_name variable_name = expression OR const => const type var_name = expression
                        {
                            if(p->oper.op[0]->defineType.type==ConstType){
                                //insert in symbol table
                                bool isInserted = st->insert(p->oper.op[2]->identifier.name,"constant",p->oper.op[1]->defineType.type,currentScope);
                                printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[2]->identifier.name,isInserted);
                                if(!isInserted){
                                    yyerror("ERROR: variable already exists in the current scope");
                                }
                            }
                            else if(p->oper.op[0]->defineType.type==EnumType)
                            {
                                //insert in symbol table
                                bool isInserted = st->insert(p->oper.op[2]->identifier.name,"variable",6,currentScope);
                                printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[2]->identifier.name,isInserted);
                                if(!isInserted){
                                    yyerror("ERROR: variable already exists in the current scope");
                                }
                            }
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            execute(p->oper.op[2]);
                            execute(p->oper.op[3]);
                        }
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
                case ',': //enum variables in enum definition => enum x {variable1 = variablevalue1, variable2}
                {
                    switch(p->oper.nops){
                        case 1: //enum x{variable1}
                        {
                            //insert in the symbol table
                            bool isInserted = st->insert(p->oper.op[0]->identifier.name,"enum constant",0,currentScope);
                            printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[0]->identifier.name,isInserted);
                            if(!isInserted){
                                 yyerror("ERROR: enum variable already exists in the current scope");
                            }
                            execute(p->oper.op[0]);
                            break;
                        }
                        case 2:
                        {
                            if(p->oper.op[0]->type==Identifier_Node){
                                //insert in the symbol table
                                bool isInserted = st->insert(p->oper.op[0]->identifier.name,"enum constant",0,currentScope);
                                printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[0]->identifier.name,isInserted);
                                if(!isInserted){
                                     yyerror("ERROR: enum variable already exists in the current scope");
                                }
                            }
                            else 
                            {
                                //insert in the symbol table
                                bool isInserted = st->insert(p->oper.op[1]->identifier.name,"enum constant",0,currentScope);
                                printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                                if(!isInserted){
                                     yyerror("ERROR: enum variable already exists in the current scope");
                                }

                            }
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            break;
                        }
                        case 3:
                        {
                            execute(p->oper.op[0]); //enum variables
                            //insert in the symbol table
                            bool isInserted = st->insert(p->oper.op[1]->identifier.name,"enum constant",0,currentScope);
                            printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                            if(!isInserted){
                                 yyerror("ERROR: enum variable already exists in the current scope");
                            }
                            execute(p->oper.op[1]);
                            execute(p->oper.op[2]);
                            break;
                        }
                    }
                    break;
                }
                case 'd': //function definition
                {
                    //insert in the symbol table
                    bool isInserted = st->insert(p->oper.op[1]->identifier.name,"function",p->oper.op[0]->defineType.type,currentScope);
                    printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                    if(!isInserted){
                        yyerror("ERROR: function already exists in the current scope");
                    }
                    
                    //switch scope
                    Node * tempNode = new Node();
                    tempNode = currentScope;
                    //will make the function the root scope because the definitions inside of it 
                    //shouldnt have the global scope as their parent scope
                    currentScope=st->functionScope(currentScope);
                
                    switch(p->oper.nops){
                        case 4:{
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            execute(p->oper.op[2]);
                            execute(p->oper.op[3]);
                            break;
                        }
                        case 5:{
                            execute(p->oper.op[0]);
                            execute(p->oper.op[1]);
                            execute(p->oper.op[2]);
                            execute(p->oper.op[3]);
                            execute(p->oper.op[4]);
                            break;
                        }
                    }
                    //switching the scope back 
                    currentScope->parent=tempNode;
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case 'c': //parameters call => fun(x, y, z) parameters are x, y and z
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