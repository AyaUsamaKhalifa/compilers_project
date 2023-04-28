%{
    /*Definition section */
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "parser.tab.h"  // Here we include token definitions
%}
 
%%
"if"                {printf("if\n"); return IF;}     
"else"              {printf("else\n"); return ELSE;}
"for"               {printf("for\n"); return FOR;}
"while"             {printf("while\n"); return WHILE;}
"do"                {printf("do\n"); return DO;}
"switch"            {printf("switch\n"); return SWITCH;}
"case"              {printf("case\n"); return CASE;}
"break"             {printf("break\n"); return BREAK;}
"return"            {printf("return\n"); return RETURN;}
"void"              {printf("void\n"); return VOID;}
"enum"              {printf("enum\n"); return ENUM;}

"int"               {printf("int\n"); return INT_TYPE;}
"char"              {printf("char\n"); return CHAR_TYPE;}
"bool"              {printf("bool\n"); return BOOL_TYPE;}
"float"             {printf("float\n"); return FLOAT_TYPE;}
"string"            {printf("string\n"); return STRING_TYPE;}
"const"             {printf("const\n"); return CONST;}

"print"             {printf("print\n"); return PRINT;}

[\+\-\*/=\>\<\(\)\{\}:;!,\%]   {printf("%c\n",*yytext); return *yytext;} 

"=="                {printf("%s \n",yytext); return EE;}
"!="                {printf("%s \n",yytext); return NE;}
">="                {printf("%s \n",yytext); return GE;}
"<="                {printf("%s \n",yytext); return LE;}

"&&"                {printf("%s \n",yytext); return AND;}
"||"                {printf("%s \n",yytext); return OR;}


0|-?[1-9][0-9]*                    {yylval.integer_val=atoi(yytext); printf("integer %d \n",yylval.integer_val); return INTEGER;}
-?(0|[1-9][0-9]*)\.[0-9]*[1-9]   {yylval.float_val=strtof(yytext, NULL); printf("float %f \n",yylval.float_val); return FLOAT;}

"true"                           {yylval.integer_val=1; printf("%d \n",yylval.integer_val); return BOOL_TRUE;}
"false"                          {yylval.integer_val=0; printf("%d \n",yylval.integer_val); return BOOL_FALSE;}

\'.\'                              {yylval.char_val=*(yytext+1); printf("char %c \n",yylval.char_val); return CHAR;}
\".*\"                             {yylval.string_val=strtok(yytext, "\""); printf("string %s \n",yylval.string_val); return STRING;}
[_a-zA-Z][_a-zA-Z0-9]*            {yylval.string_val=yytext; printf("variable %s \n",yylval.string_val); return VARIABLE;}


[ \t\n]+                   ;//printf("white space\n");              

.                          yyerror("invalid character");
%%