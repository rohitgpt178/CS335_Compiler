all:
	bison -d src/parserIR.y
	flex src/lexer.l
	g++ -std=c++11 lex.yy.c parserIR.tab.c -o bin/irgen
	g++ -std=c++11 -c src/translate.cpp
	g++ -std=c++11 -c src/tac.cpp
	g++ -o bin/codegen translate.o tac.o
	chmod +x compile
	chmod +x run

clean:
	rm lex.yy.c
	rm parserIR.tab.c		
	rm parserIR.tab.h
	rm bin/irgen
	rm temp.txt
	rm *.o
	rm bin/codegen
	rm *.ir
	rm *.s
