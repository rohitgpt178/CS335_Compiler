all:
	bison -d src/parserIR.y
	flex src/lexer.l
	g++ lex.yy.c parserIR.tab.c src/html.cpp -o bin/parserIR
	chmod +x bin/parser
	
clean:
	rm lex.yy.c
	rm parserIR.tab.c		
	rm parserIR.tab.h
	rm bin/parserIR
	rm temp.txt
	rm ir.txt
	rm *.html
