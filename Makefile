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
	bison -d -o parser.tab.c parser.y
	flex -o lex.yy.c scanner.l
	g++ -o parser parser.tab.c lex.yy.c common.c symbolTable.cpp 
	./parser < input.txt

clean:
	rm -f *.o  
	rm -f parser.tab.* scanner.tab.*
	rm -f lex.yy.* parser.tab.*
