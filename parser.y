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
    //Quadraples data:
    FILE* OutputQuadraplesFile;
    int Labels;
    int CaseLabels;
    int EndSwitchLabel;
    int EnumValue;
    int TempVariables;

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
    nodeType *createParameterList(nodeType * node, nodeType * identifier);
    nodeType *addToParameterList(nodeType * parameterList, nodeType* node, nodeType * parameter);

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
                                $$=operation(SWITCH,2,identifier($3),$6);
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
            | ENUM VARIABLE VARIABLE '=' VARIABLE 
            {printf("assignment: ENUM VARIABLE VARIABLE = VARIABLE\n");
            $$=operation('=',4,defineType(EnumType),identifier($2),identifier($3),identifier($5));
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
            $$ = addToParameterList($1, $3, identifier($4));
            //$$=operation('p',3,$3,identifier($4),$1);
            } 
            | variable_Type VARIABLE 
            {printf("parameter: variable_Type VARIABLE\n");
            $$ = createParameterList($1, identifier($2));
            //$$=operation('p',2,$1,identifier($2));
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

nodeType *createParameterList(nodeType * node, nodeType * identifier) {
    nodeType *p;
    if ((p = (nodeType *)malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = ArgumentNode;
    p->argumentType.arguments.push_back(node->defineType.type);
    p->argumentType.argumentsNames.push_back(identifier->identifier.name);
    return p;
}

nodeType *addToParameterList(nodeType * parameterList, nodeType* node, nodeType * parameter){
    nodeType *p;
    if ((p = (nodeType *)malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");
    p->type = ArgumentNode;
    parameterList->argumentType.arguments.push_back(node->defineType.type);
    parameterList->argumentType.argumentsNames.push_back(parameter->identifier.name);
    return parameterList;
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

         //TODO: enums 
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
                case IF: 
                {   
                    //call exec on operands
                    switch(p->oper.nops){
                        case 2:{
                            int CurrentLabel = Labels;
                            execute(p->oper.op[0]);
                            fprintf(OutputQuadraplesFile, "JZ L%d\n", Labels++);
                            currentScope=st->switchScope(currentScope);
                            execute(p->oper.op[1]);
                            currentScope = st->switchBack(currentScope);
                            fprintf(OutputQuadraplesFile, "L%d:\n",CurrentLabel);
                            break;
                        }
                        case 3:{
                            //exp
                            int CurrentLabel = Labels;
                            execute(p->oper.op[0]);
                            fprintf(OutputQuadraplesFile, "JZ L%d\n", Labels++); //x
                            currentScope=st->switchScope(currentScope);
                            //statemnts
                            execute(p->oper.op[1]);
                            int CurrentLabel2 = Labels;
                            fprintf(OutputQuadraplesFile, "JZ L%d\n", Labels++); //y
                            currentScope = st->switchBack(currentScope);
                            currentScope=st->switchScope(currentScope);
                            fprintf(OutputQuadraplesFile, "L%d:\n",CurrentLabel); //x
                            // statements 2
                            execute(p->oper.op[2]);
                            fprintf(OutputQuadraplesFile, "L%d:\n",CurrentLabel2); //y
                            currentScope = st->switchBack(currentScope);
                            break;
                        }
                    }
                    break;
                }
                case FOR: 
                {
                    int CurrentLabel = Labels;
                    //switch scope
                    currentScope=st->switchScope(currentScope);
                    //Assignment 1
                    execute(p->oper.op[0]);
                    fprintf(OutputQuadraplesFile, "L%d:\n",Labels++);   //Label in = labels
                    //Expression
                    execute(p->oper.op[1]);
                    fprintf(OutputQuadraplesFile, "JZ L%d\n", Labels++);  // jmp label out
                    //Statements
                    execute(p->oper.op[3]);
                    //Assignment 2
                    execute(p->oper.op[2]);
                    fprintf(OutputQuadraplesFile, "JMP L%d\n", CurrentLabel);   //jmp label in
                    fprintf(OutputQuadraplesFile, "L%d:\n",++CurrentLabel);   //label out = label +1 
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case WHILE:
                { 
                    int CurrentLabel = Labels;
                    //switch scope
                    currentScope=st->switchScope(currentScope);
                    fprintf(OutputQuadraplesFile, "L%d:\n",Labels++); //label in
                    //exp
                    execute(p->oper.op[0]);
                    int CurrentLabel2 = Labels;
                    fprintf(OutputQuadraplesFile, "JZ L%d\n", Labels++); //jz label out
                    //statment
                    execute(p->oper.op[1]);
                    fprintf(OutputQuadraplesFile, "JMP L%d\n", CurrentLabel);   //jmp label in
                    fprintf(OutputQuadraplesFile, "L%d:\n",CurrentLabel2); //label out
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case DO: 
                {
                    //switch scope
                    int CurrentLabel = Labels;
                    fprintf(OutputQuadraplesFile, "L%d:\n",Labels++); 
                    currentScope=st->switchScope(currentScope);
                    //Statements
                    execute(p->oper.op[0]);
                    //Expression
                    execute(p->oper.op[1]);
                    fprintf(OutputQuadraplesFile, "JZ L%d\n", Labels);
                    fprintf(OutputQuadraplesFile, "JMP L%d\n", CurrentLabel);

                    fprintf(OutputQuadraplesFile, "L%d:\n",Labels++); 
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    break;
                }
                case SWITCH:    
                {
                    TempVariables ++;
                    EndSwitchLabel++;
                    //execute(p->oper.op[0]);
                    typeEnum varType = getIdentifierType(p->oper.op[0]->identifier.name);
                    if(varType != CharType && varType != IntType){
                        yyerror("This type of variable is not supported in switch statement");
                        return Error;
                    }
                    fprintf(OutputQuadraplesFile, "PUSH %s\n", p->oper.op[0]->identifier.name);
                    fprintf(OutputQuadraplesFile, "POP Temp%d\n", TempVariables);
                    int CurrentEndSwitch = EndSwitchLabel;
                    execute(p->oper.op[1]);
                    fprintf(OutputQuadraplesFile, "E%d:\n",CurrentEndSwitch); 
                    break;
                }
                case CASE: 
                {
                    //switch scopes
                    int CurrentTempVar = TempVariables;
                    int CurrentEndSwitch = EndSwitchLabel;
                    currentScope=st->switchScope(currentScope);
                    execute(p->oper.op[0]);
                    int CurrentCaseLabel = CaseLabels;
                    fprintf(OutputQuadraplesFile, "PUSH Temp%d\n", CurrentTempVar);
                    typeEnum caseConst = execute(p->oper.op[1]);
                    if(caseConst != IntType && caseConst != CharType){
                        yyerror("This type of case is not supported in switch statement");
                        return Error;
                    }
                    fprintf(OutputQuadraplesFile, "COMP_E\n");
                    fprintf(OutputQuadraplesFile, "JZ C%d\n", CaseLabels++);  
                    //Statements
                    execute(p->oper.op[2]);
                    fprintf(OutputQuadraplesFile, "JMP E%d\n", CurrentEndSwitch);  
                    //switching the scope back 
                    currentScope = st->switchBack(currentScope);
                    fprintf(OutputQuadraplesFile, "C%d:\n",CurrentCaseLabel); 
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
                            //update the function map in the symbol table
                            st->updateFunctionMap(p->oper.op[1]->identifier.name, p->oper.op[2]);
                            execute(p->oper.op[0]);
                            // execute(p->oper.op[1]);
                            //execute(p->oper.op[2]); //parameters
                            //insert parameters in symbol table
                            if(p->oper.op[2] != NULL){
                                for(int i=0; i < p->oper.op[2]->argumentType.arguments.size(); i++){
                                    bool isInserted = st->insert(p->oper.op[2]->argumentType.argumentsNames[i],"parameter",p->oper.op[2]->argumentType.arguments[i],currentScope);
                                    printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                                    if(!isInserted){
                                        yyerror("parameter already exists in the current scope");
                                    }
                                    fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[2]->argumentType.argumentsNames[i]);
                                }
                            }
                            execute(p->oper.op[3]);
                            break;
                        }
                        case 5:
                        {
                            //update the function map in the symbol table
                            st->updateFunctionMap(p->oper.op[1]->identifier.name, p->oper.op[2]);
                            execute(p->oper.op[0]);
                            // execute(p->oper.op[1]);
                            //execute(p->oper.op[2]); //parameters
                            //insert parameters in symbol table
                            if(p->oper.op[2] != NULL){
                                for(int i=0; i < p->oper.op[2]->argumentType.arguments.size(); i++){
                                    bool isInserted = st->insert(p->oper.op[2]->argumentType.argumentsNames[i],"parameter",p->oper.op[2]->argumentType.arguments[i],currentScope);
                                    printf("!!!!!!!!!!!!!!!!!trying to insert symbol: %s, isInserted: %d\n",p->oper.op[1]->identifier.name,isInserted);
                                    if(!isInserted){
                                        yyerror("parameter already exists in the current scope");
                                    }
                                    fprintf(OutputQuadraplesFile, "POP %s\n", p->oper.op[2]->argumentType.argumentsNames[i]);
                                }
                            }
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
                case 'c': //parameters call => fun(x, y, z) parameters are x, y and z
                {
                    execute(p->oper.op[0]);
                    execute(p->oper.op[1]);
                    break;
                }
                case 'f': //function call 
                {
                    // execute(p->oper.op[0]);
                    typeEnum funcType = getIdentifierType(p->oper.op[0]->identifier.name);
                    printf("function call\n");
                    execute(p->oper.op[1]);
                    fprintf(OutputQuadraplesFile, "CALL %s\n", p->oper.op[0]->identifier.name);
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
    
    //int and float are compatible => cast to float
    if(typeOP1 == IntType && typeOP2 == FloatType || typeOP1 == FloatType && typeOP2 == IntType)
    {
        return FloatType;
    }

    //int and char are compatible => cast to int
    if(typeOP1 == IntType && typeOP2 == CharType || typeOP1 == CharType && typeOP2 == IntType){
        return IntType;
    }

    //float and char are compatible => cast to float
    if(typeOP1 == FloatType && typeOP2 == CharType || typeOP1 == CharType && typeOP2 == FloatType){
        return FloatType;
    }

    //int and bool are compatible => cast to integer
    if(typeOP1 == IntType && typeOP2 == BoolType || typeOP1 == BoolType && typeOP2 == IntType){
        return IntType;
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
    TempVariables = 0;
    yyparse();

    fclose(fp);
    fclose(errorsFile);
    fclose(OutputQuadraplesFile);
    st->print(currentScope);

    return 0;
}