all: compile run

compile:
	g++ main.cpp md5/md5.cpp -o main

run:
	./main