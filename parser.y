%{
    /*Definition section */
    #include <stdio.h>
    void yyerror(const char *str);
    //printing may be removed
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
root: root statement | root functional_statement {printf("functions"); return 0;} | ;

statement:  conditional_statement 
            { printf("conditional_statement"); return 0;} 
            |  
            loop_statement 
            { printf("loop_statement"); return 0;} 
            |  
            assignment { printf("assignment"); return 0;} 
            |
            ;

recursive_statement: recursive_statement statement | ;
            

//---------conditional statement---------// 
conditional_statement:  if_conditional_statement { printf("if statement");} 
                        | 
                        switch_conditional_statement { printf("switch statement");} 
                        |; 

if_conditional_statement: IF '(' comparator ')' '{'recursive_statement'}'  ELSE '{'recursive_statement'}' {} | IF '(' comparator ')' '{'recursive_statement'}' {}; 

switch_conditional_statement: SWITCH '('comparator')' '{' case_statement '}';

case_statement: case_statement CASE variable_value ':' recursive_statement BREAK; // hna lazem nzwd elvalues elly elmafrood treturn

//---------loop statement---------// 
loop_statement: for_loop_statement 
                | 
                while_loop_statement 
                | 
                do_while_loop_statement 
                | ;

for_loop_statement: FOR '(' assignment comparator assignment')' '{' recursive_statement '}'; // hna lazem nzwd elvalues elly elmafrood treturn

while_loop_statement: WHILE '(' comparator ')' '{' recursive_statement '}'; 

do_while_loop_statement: DO '{' recursive_statement '}' WHILE '(' comparator ')'; 
 
//-------------assignments-------------//
assignment: variable_Type VARIABLE '=' first_operation';'; // hna lazem nzwd elvalues elly elmafrood treturn
first_operation: first_operation '+' second_operation | first_operation '-' second_operation | second_operation;
second_operation: second_operation '*' third_operation | second_operation '/' third_operation | third_operation;
third_operation: variable_value | VARIABLE | '('first_operation')';  

//------------functions---------------//
functional_statement: function | enum_statement ;
function_statement_type: function_statement_type statement | ;
function_statement_void: function_statement_void statement | ; 
function_parameters: function_parameters variable_Type VARIABLE | ; // semi colon not added yet?
function: variable_Type VARIABLE '(' function_parameters ')' '{' function_statement_type '}' RETURN return_types';' | VOID VARIABLE '(' function_parameters ')' '{' function_statement_void '}';
return_types: comparator | first_operation ;
enum_statement: ENUM '{'enum_variables'}';
enum_variables =  enum_variables VARIABLE '=' first_operation | enum_variables VARIABLE;

//-------------comparators------------//
comparator: VARIABLE comparator_operator variable_value | VARIABLE comparator_operator VARIABLE | variable_value comparator_operator VARIABLE | variable_value comparator_operator variable_value | BOOL_FALSE | BOOL_TRUE ;//hna lessa mzwdnash eloperator
comparator_operator: EE | NE | GE | LE | AND | OR;

//------------variables---------------//
variable_Type: INT_TYPE | CHAR_TYPE | BOOL_TYPE | FLOAT_TYPE | STRING_TYPE; 

variable_value: INTEGER | FLOAT | BOOL_FALSE | BOOL_TRUE | CHAR | STRING; // hna lazem nzwd elvalues elly elmafrood treturn


%%

void yyerror(const char *str)
{
    fprintf(stderr,"error: %s\n",str);
}
 
int yywrap()
{
    return 1;
} 
  
// int main()
// {
//     yylex();
//     return 0;
// }