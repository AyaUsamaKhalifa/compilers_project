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
//TODO: [] mod operator [] -- and ++ []

root: root statement | root functional_statement {printf("functions\n");} | ;

statement:  conditional_statement 
            { printf("conditional_statement\n");} 
            |  
            loop_statement 
            { printf("loop_statement\n");} 
            |  
            assignment ';' { printf("assignment\n");} 
            |
            ;

recursive_statement: recursive_statement statement | ;
            

//---------conditional statement---------// 
conditional_statement:  switch_conditional_statement 
                        |
                        if_conditional_statement 
                        |
                        ; 

if_conditional_statement: IF '(' expressions ')' '{'recursive_statement'}'  ELSE '{'recursive_statement'}' {} | IF '(' expressions ')' '{'recursive_statement'}' {}; 

switch_conditional_statement: SWITCH '('VARIABLE')' '{' case_statement '}';

case_statement: case_statement CASE variable_value ':' recursive_statement BREAK | ; // hna lazem nzwd elvalues elly elmafrood treturn

//---------loop statement---------// 
loop_statement: for_loop_statement 
                | 
                while_loop_statement 
                | 
                do_while_loop_statement 
                | ;

for_loop_statement: FOR '(' assignment ';' expressions ';' assignment')' '{' recursive_statement '}'; // hna lazem nzwd elvalues elly elmafrood treturn

while_loop_statement: WHILE '(' expressions ')' '{' recursive_statement '}'; 

do_while_loop_statement: DO '{' recursive_statement '}' WHILE '(' expressions ')'; 

//-------------assignments-------------//
assignment: variable_Type VARIABLE '=' expressions | VARIABLE '=' expressions | ENUM VARIABLE VARIABLE '=' expressions | expressions; // hna lazem nzwd elvalues elly elmafrood treturn
//first_operation: first_operation '+' second_operation | first_operation '-' second_operation | second_operation;
//second_operation: second_operation '*' third_operation | second_operation '/' third_operation | third_operation;
//third_operation: variable_value | VARIABLE | '('first_operation')';

//------------Expressions-------------//
expressions: expressions OR first | first;
first: first AND second | second;
second: second EE third | second NE third | third;
third: third '>' fourth | third '<' fourth | third GE fourth | third LE fourth | fourth ;
fourth: fourth '+' fifth | fourth '-' fifth | fifth;
fifth: fifth '*' sixth | fifth '/' sixth | fifth '%' sixth | sixth;
sixth: '-' sixth | '!' sixth | seventh;
seventh: '(' expressions ')' | variable_value | VARIABLE | function_call;

//------------functions---------------//
function_call: VARIABLE '(' function_parameters_calls ')';
functional_statement: function | enum_statement ;
function_parameters: parameter | ; // semi colon not added yet?
parameter: parameter ',' variable_Type VARIABLE | variable_Type VARIABLE;
function_parameters_calls: parameter_calls | ;
parameter_calls: parameter_calls ',' expressions | expressions ;
function: variable_Type VARIABLE '(' function_parameters ')' '{' recursive_statement RETURN return_types';' '}' | VOID VARIABLE '(' function_parameters ')' '{' recursive_statement '}';
return_types: expressions ;
enum_statement: ENUM VARIABLE '{'enum_variables'}';
enum_variables:  enum_variables ',' VARIABLE '=' expressions | enum_variables ',' VARIABLE | VARIABLE '=' expressions | VARIABLE;

//-------------comparators------------//
//comparator: VARIABLE comparator_operator variable_value | VARIABLE comparator_operator VARIABLE | variable_value comparator_operator VARIABLE | variable_value comparator_operator variable_value | BOOL_FALSE | BOOL_TRUE | VARIABLE;//hna lessa mzwdnash eloperator
//comparator_operator: EE | NE | GE | LE | AND | OR | '>' | '<' ;
//comparisons_list: first_comparator {printf("A list of comparisons detected: \n");} | ;
//first_comparator: first_comparator OR second_comparator {printf("x || y: \n");}| second_comparator ;
//second_comparator: second_comparator AND third_comparator {printf("x && y: \n");}| third_comparator ;
//third_comparator: '!' third_comparator {printf("!x: \n");} | fourth_comparator ;
//fourth_comparator: '(' comparisons_list ')' {printf("This is of higher priority \n");}| comparator ;


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

int main()
{
    yyparse();
    return 0;
}