%{
    /*Definition section */
    #include "common.h"
    #include <stdio.h>
    #include <stdlib.h>
    extern FILE *yyin;
    void yyerror(const char *str);
    void read_file(char *filename);
    //printing may be removed
    // extern char* last_token;
%}


%union {
    int integer_val;
    char* string_val;
    float float_val;
    char char_val;
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



%%
root:   root statement 
        {printf("root: root statement\n"); printf("-------------------------------------\n");} 
        | root functional_statement 
        {printf("root functional_statement\n"); printf("-------------------------------------\n");} | {printf("root: \n");}

statement:  conditional_statement 
            { printf("statement: conditional_statement\n");} 
            |  
            loop_statement 
            { printf("statement: loop_statement\n");} 
            |  
            assignment ';' { printf("statement: assignment;\n");} 
//! rule useless 
            // |
            // ;
            
recursive_statement: recursive_statement statement 
                    {printf("recursive_statement: recursive_statement statement\n");} 
                    | 
                    {printf("recursive_statement: \n");}
            
//---------conditional statement---------// 
conditional_statement:  switch_conditional_statement 
                        {printf("conditional_statement: switch_conditional_statement\n");} 
                        |
                        if_conditional_statement 
                        {printf("conditional_statement: if_conditional_statement\n");} 
//! rule useless
                        // |
                        // ;

if_conditional_statement:   IF '(' expressions ')' '{'recursive_statement'}'  ELSE '{'recursive_statement'}' 
                            {printf("if_conditional_statement: if(exp){recursive_statement} else{recursive_statement}\n");} 
                            | IF '(' expressions ')' '{'recursive_statement'}' 
                            {printf("if_conditional_statement: if(exp){recursive_statement}\n");}; 

switch_conditional_statement:   SWITCH '('VARIABLE')' '{' case_statement '}' 
                                {printf("switch_conditional_statement: switch(VARIABLE){case_statement}\n");} 

case_statement: case_statement CASE variable_value ':' recursive_statement BREAK  
                {printf("case_statement: case_statement case variable_value: recursive_statement break\n");} 
                |  
                {printf("case_statement: \n");} ; //? hna lazem nzwd elvalues elly elmafrood treturn

//---------loop statement---------// 
loop_statement: for_loop_statement  
                {printf("loop_statement: for_loop_statement\n");} 
                | 
                while_loop_statement 
                {printf("loop_statement: while_loop_statement\n");} 
                | 
                do_while_loop_statement 
                {printf("loop_statement: do_while_loop_statement\n");} 
//! rule useless                
                // | 
                // ;

for_loop_statement: FOR '(' assignment ';' expressions ';' assignment')' '{' recursive_statement '}' 
                    {printf("for_loop_statement: for(assignment; exp; assignment){recursive_statement}\n");} // hna lazem nzwd elvalues elly elmafrood treturn

while_loop_statement: WHILE '(' expressions ')' '{' recursive_statement '}'  
                    {printf("while_loop_statement: while(exp){recursive_statement}\n");} 


do_while_loop_statement: DO '{' recursive_statement '}' WHILE '(' expressions ')'  
                        {printf("do_while_loop_statement: do{recursive_statement} while{exp}\n");}

//-------------assignments-------------//
assignment: variable_Type VARIABLE '=' expressions  
            {printf("assignment: variable_Type VARIABLE = exp\n");} 
            | VARIABLE '=' expressions  
            {printf("assignment: VARIABLE = exp\n");}  
            | ENUM VARIABLE VARIABLE '=' expressions 
            {printf("assignment: ENUM VARIABLE VARIABLE = exp\n");} 
            | expressions  
            {printf("assignment: exp\n");}  //? hna lazem nzwd elvalues elly elmafrood treturn

//------------Expressions-------------//
expressions: expressions OR first 
            {printf("exp: exp || first \n");} 
            | first  
            {printf("exp: first \n");}

first: first AND second 
        {printf("first: first && second\n");} 
        | second 
        {printf("first: second\n");} 

second: second EE third 
        {printf("second: second == third\n");} 
        | second NE third  
        {printf("second: second != third\n");} 
        | third  
        {printf("second: third\n");} 

third:  third '>' fourth 
        {printf("third: third > fourth\n");} 
        | third '<' fourth 
        {printf("third: third < fourth\n");} 
        | third GE fourth 
        {printf("third: third >= fourth\n");} 
        | third LE fourth 
        {printf("third: third <= fourth\n");} 
        | fourth 
        {printf("third: fourth\n");}

fourth: fourth '+' fifth 
        {printf("fourth: fourth + fifth\n");} 
        | fourth '-' fifth 
        {printf("fourth: fourth - fifth\n");} 
        | fifth 
        {printf("fourth: fifth\n");} 

fifth:  fifth '*' sixth 
        {printf("fifth: fifth * sixth\n");} 
        | fifth '/' sixth 
        {printf("fifth: fifth / sixth\n");} 
        | fifth '%' sixth 
        {printf("fifth: fifth % sixth\n");} 
        | sixth 
        {printf("fifth: sixth\n");} 

sixth:  '-' sixth  
        {printf("sixth: - sixth\n");} 
        | '!' sixth 
        {printf("sixth: ! sixth\n");} 
        | seventh  
        {printf("sixth: seventh\n");} 

seventh: '(' expressions ')' 
        {printf("seventh: (exp)\n");} 
        | variable_value  
        {printf("seventh: variable_value\n");} 
        | VARIABLE 
        {printf("seventh: VARIABLE\n");} 
        | function_call 
        {printf("seventh: function_call\n");} 

//------------functions---------------//
function_call:  VARIABLE '(' function_parameters_calls ')' 
                {printf("function_call: VARIABLE (function_parameters_calls)\n");}

functional_statement: function 
                    {printf("functional_statement: function\n");}
                    | enum_statement 
                    {printf("functional_statement: enum_statement\n");}

function_parameters: parameter 
                    {printf("function_parameters: parameter\n");} 
                    | 
                    {printf("function_parameters: \n");}  //? semi colon not added yet?

parameter:  parameter ',' variable_Type VARIABLE  
            {printf("parameter: parameter, variable_Type VARIABLE\n");} 
            | variable_Type VARIABLE 
            {printf("parameter: variable_Type VARIABLE\n");} 

function_parameters_calls:  parameter_calls 
                            {printf("function_parameters_calls: parameter_calls\n");} 
                            | 
                            {printf("function_parameters_calls: \n");} 

parameter_calls: parameter_calls ',' expressions 
                {printf("parameter_calls: parameter_calls, exp\n");} 
                | expressions 
                {printf("parameter_calls: exp\n");} 

function: variable_Type VARIABLE '(' function_parameters ')' '{' recursive_statement RETURN return_types';' '}'  
        {printf("function: variable_Type  (function_parameters){recursive_statement RETURN return_types ;}\n");} 
        | VOID VARIABLE '(' function_parameters ')' '{' recursive_statement '}' 
        {printf("function: void VARIABLE (function_parameters) {recursive_statement}\n");} 

return_types:   expressions  
                {printf("return_types: expressions\n");}

enum_statement: ENUM VARIABLE '{'enum_variables'}' 
                {printf("enum_statement: enum VARIABLE {enum_variables}\n");} 

enum_variables:  enum_variables ',' VARIABLE '=' expressions 
                {printf("enum_variables: enum_variables, VARIABLE = exp\n");} 
                | enum_variables ',' VARIABLE 
                {printf("enum_variables: enum_variables, VARIABLE\n");} 
                | VARIABLE '=' expressions 
                {printf("enum_variables:VARIABLE = exp\n");} 
                | VARIABLE 
                {printf("enum_variables: VARIABLE\n");} ;

//------------variables---------------//
variable_Type:  INT_TYPE  
                {printf("variable_Type: int\n");} 
                | CHAR_TYPE 
                {printf("variable_Type: char\n");} 
                | BOOL_TYPE 
                {printf("variable_Type: bool\n");} 
                | FLOAT_TYPE 
                {printf("variable_Type: float\n");} 
                | STRING_TYPE 
                {printf("variable_Type: strng\n");}  

variable_value: INTEGER  
                {printf("variable_value: int value \n");} 
                | FLOAT 
                {printf("variable_value: float value \n");} 
                | BOOL_FALSE 
                {printf("variable_value: false \n");} 
                | BOOL_TRUE 
                {printf("variable_value: true \n");} 
                | CHAR 
                {printf("variable_value: char value \n");} 
                | STRING
                {printf("variable_value: string value \n");} //? hna lazem nzwd elvalues elly elmafrood treturn


%%

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

    yyin = fp;

    yyparse();

    fclose(fp);
    return 0;
}

