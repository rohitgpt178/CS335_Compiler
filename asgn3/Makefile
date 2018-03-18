all:
	bison -d src/parserIR.y
	flex src/lexer.l
	g++ lex.yy.c parserIR.tab.c src/html.cpp -o bin/parser
	
clean:
	rm lex.yy.c
	rm parserIR.tab.c		
	rm parserIR.tab.h
	rm bin/parser
	rm temp.txt
	rm ir.txt
	rm prog.html
