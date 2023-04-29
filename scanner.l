%{
    /*Definition section */
    #include "common.h"
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "parser.tab.h"  // Here we include token definitions
    // extern char* last_token;

%}
%%
"if"                {/*printf("if\n");*/ last_token = "if"; return IF;}     
"else"              {/*printf("else\n");*/ last_token = "else"; return ELSE;}
"for"               {/*printf("for\n");*/ last_token = "for"; return FOR;}
"while"             {/*printf("while\n");*/ last_token = "while"; return WHILE;}
"do"                {/*printf("do\n");*/ last_token = "do"; return DO;}
"switch"            {/*printf("switch\n");*/ last_token = "switch"; return SWITCH;}
"case"              {/*printf("case\n");*/ last_token = "case"; return CASE;}
"break"             {/*printf("break\n");*/ last_token = "break"; return BREAK;}
"return"            {/*printf("return\n");*/ last_token = "return"; return RETURN;}
"void"              {/*printf("void\n");*/ last_token = "void"; return VOID;}
"enum"              {/*printf("enum\n");*/ last_token = "enum"; return ENUM;}

"int"               {/*printf("int\n");*/ last_token = "int"; return INT_TYPE;}
"char"              {/*printf("char\n");*/ last_token = "char"; return CHAR_TYPE;}
"bool"              {/*printf("bool\n");*/ last_token = "bool"; return BOOL_TYPE;}
"float"             {/*printf("float\n");*/ last_token = "float"; return FLOAT_TYPE;}
"string"            {/*printf("string\n");*/ last_token = "string"; return STRING_TYPE;}
"const"             {/*printf("const\n");*/ last_token = "const"; return CONST;}

"print"             {/*printf("print\n");*/ last_token = "print"; return PRINT;}

[\+\-\*/=\>\<\(\)\{\}:;!,\%]   {/*printf("%c\n",*yytext);*/ last_token = yytext ;return *yytext;} 

"=="                {/*printf("%s \n",yytext);*/ last_token = "=="; return EE;}
"!="                {/*printf("%s \n",yytext);*/ last_token = "!="; return NE;}
">="                {/*printf("%s \n",yytext);*/ last_token = ">="; return GE;}
"<="                {/*printf("%s \n",yytext);*/ last_token = "<="; return LE;}

"&&"                {/*printf("%s \n",yytext);*/ last_token = "&&"; return AND;}
"||"                {/*printf("%s \n",yytext);*/ last_token = "||"; return OR;}


0|-?[1-9][0-9]*                    {yylval.integer_val=atoi(yytext); /*printf("integer %d \n",yylval.integer_val);*/ last_token = malloc(strlen(yytext) + 1); strcpy(last_token, yytext); return INTEGER;}
-?(0|[1-9][0-9]*)\.[0-9]*[1-9]   {yylval.float_val=strtof(yytext, NULL); /*printf("float %f \n",yylval.float_val);*/ last_token = malloc(strlen(yytext) + 1); strcpy(last_token, yytext); return FLOAT;}

"true"                           {yylval.integer_val=1; /*printf("%d \n",yylval.integer_val);*/ last_token = "true"; return BOOL_TRUE;}
"false"                          {yylval.integer_val=0; /*printf("%d \n",yylval.integer_val);*/ last_token = "false"; return BOOL_FALSE;}

\'.\'                              {yylval.char_val=*(yytext+1); /*printf("char %c \n",yylval.char_val);*/last_token = malloc(2); last_token[0] = yylval.char_val; last_token[1] = '\0'; return CHAR;}
\".*\"                             {yylval.string_val=strtok(yytext, "\""); /*printf("string %s \n",yylval.string_val);*/last_token = malloc(strlen(yylval.string_val) + 1); strcpy(last_token, yylval.string_val); return STRING;}
[_a-zA-Z][_a-zA-Z0-9]*            {yylval.string_val=yytext; /*printf("variable %s \n",yylval.string_val);*/ last_token = malloc(strlen(yylval.string_val) + 1); strcpy(last_token, yylval.string_val); return VARIABLE;}


[ \t\n\r]+                    ; //printf("white space\n");              

.                          {last_token = yytext; yyerror("invalid character");}
%%
