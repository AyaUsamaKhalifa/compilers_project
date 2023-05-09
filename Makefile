.DEFAULT_GOAL := run_and_build

build_flex:
	flex scanner.l
	gcc -o scanner lex.yy.c -lfl

run_flex: 
	./scanner

build_all:
	flex scanner.l
	bison -d parser.y
	gcc -o parser parser.tab.c lex.yy.c -lfl

run_all:
	./parser

run_and_build:
	flex scanner.l 
	bison -d parser.y
	g++ -c symbolTable.cpp
	gcc -c parser common.c parser.tab.c lex.yy.c -lfl
	g++ -o symbolTable.o lex.yy.o parser.tab.o common.o -lfl
	./parser < input.txt

