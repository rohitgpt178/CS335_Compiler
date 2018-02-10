all:
	g++ -std=c++11 -c codegen.cpp
	g++ -std=c++11 -c tac.cpp
	g++ -o final codegen.o tac.o
	./final test.ir
