%{
    /*Definition section */
    #include <stdio.h>
    void yyerror(const char *str);
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
root: expr { printf("result"); return 0;}
expr: STRING
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