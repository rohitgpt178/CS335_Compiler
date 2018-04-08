all:
	bison -d src/parserIR.y
	flex src/lexer.l
	g++ -std=c++11 lex.yy.c parserIR.tab.c -o bin/irgen
	
clean:
	rm lex.yy.c
	rm parserIR.tab.c		
	rm parserIR.tab.h
	rm bin/irgen
	rm temp.txt
