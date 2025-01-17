all: main

files:
	mkdir -p bin

	g++ -c cppfiles/exceptions.cpp -o bin/exceptions.o
	g++ -c cppfiles/util.cpp -o bin/util.o
	g++ -c cppfiles/numethods.cpp -o bin/numethods.o
	g++ -c cppfiles/rocket.cpp -o bin/rocket.o

linklib: files
	ar rcs bin/libmain.a bin/exceptions.o bin/util.o bin/numethods.o bin/rocket.o

main: linklib
	g++ main.cpp -L"bin" -lmain -o main