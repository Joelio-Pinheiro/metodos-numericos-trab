all: main

files:
	g++ -c cppfiles/exceptions.cpp -o bin/exceptions.o
	g++ -c cppfiles/util.cpp -o bin/util.o
	g++ -c cppfiles/numethods.cpp -o bin/numethods.o

linklib: files
	ar rcs bin/libmain.a bin/exceptions.o bin/util.o bin/numethods.o

main: linklib
	g++ main.cpp -L"bin" -lmain -o main