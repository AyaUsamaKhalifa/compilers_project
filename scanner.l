%{
    /*Definition section */
    #include "common.h"
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "parser.tab.h"  // Here we include token definitions
    // extern char* last_token;

%}

%option noyywrap

%%
"if"                { last_token = (char*) "if"; return IF;}     
"else"              { last_token = (char*) "else"; return ELSE;}
"for"               { last_token = (char*) "for"; return FOR;}
"while"             { last_token = (char*) "while"; return WHILE;}
"do"                {last_token = (char*) "do"; return DO;}
"switch"            { last_token = (char*) "switch"; return SWITCH;}
"case"              { last_token = (char*) "case"; return CASE;}
"break"             { last_token = (char*) "break"; return BREAK;}
"return"            { last_token = (char*) "return"; return RETURN;}
"void"              { last_token = (char*) "void"; return VOID;}
"enum"              { last_token = (char*) "enum"; return ENUM;}

"int"               { last_token = (char*) "int"; return INT_TYPE;}
"char"              { last_token = (char*) "char"; return CHAR_TYPE;}
"bool"              { last_token = (char*) "bool"; return BOOL_TYPE;}
"float"             { last_token = (char*)"float"; return FLOAT_TYPE;}
"string"            { last_token = (char*)"string"; return STRING_TYPE;}
"const"             { last_token = (char*)"const"; return CONST;}

"print"             { last_token = (char*)"print"; return PRINT;}

[\+\-\*/=\>\<\(\)\{\}:;!,\%]   { last_token = yytext ;return *yytext;} 

"=="                { last_token = (char*)"=="; return EE;}
"!="                { last_token = (char*)"!="; return NE;}
">="                { last_token = (char*)">="; return GE;}
"<="                { last_token = (char*)"<="; return LE;}

"&&"                { last_token = (char*)"&&"; return AND;}
"||"                { last_token = (char*)"||"; return OR;}


0|-?[1-9][0-9]*                    {yylval.integer_val=atoi(yytext); last_token = (char*) malloc(strlen(yytext) + 1); strcpy(last_token, yytext); return INTEGER;}
-?(0|[1-9][0-9]*)\.[0-9]*[1-9]   {yylval.float_val=strtof(yytext, NULL); last_token = (char*) malloc(strlen(yytext) + 1); strcpy(last_token, yytext); return FLOAT;}

"true"                           {yylval.integer_val=1; last_token = (char*)"true"; return BOOL_TRUE;}
"false"                          {yylval.integer_val=0; last_token = (char*)"false"; return BOOL_FALSE;}

\'.\'                              {yylval.char_val=*(yytext+1);last_token = (char*) malloc(2); last_token[0] = yylval.char_val; last_token[1] = '\0'; return CHAR;}
\".*\"                             {yylval.string_val=strtok(yytext, "\""); last_token = (char*) malloc(strlen(yylval.string_val) + 1); strcpy(last_token, yylval.string_val); return STRING;}
[_a-zA-Z][_a-zA-Z0-9]*            {yylval.string_val=yytext;  last_token = (char*) malloc(strlen(yylval.string_val) + 1); strcpy(last_token, yylval.string_val); return VARIABLE;}


[ \t\n\r]+                    ;              

.                          {last_token = yytext; YYerror;}
%%