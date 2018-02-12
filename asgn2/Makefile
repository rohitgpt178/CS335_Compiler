all:
	g++ -std=c++11 -c src/translate.cpp
	g++ -std=c++11 -c src/tac.cpp
	g++ -o bin/codegen translate.o tac.o

clean:
	rm *.o
	rm bin/codegen
