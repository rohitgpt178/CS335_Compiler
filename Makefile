all:
	flex src/lexer.l
	mv lex.yy.c src/
	g++ src/scanner.cpp src/lex.yy.c -o bin/lexer
