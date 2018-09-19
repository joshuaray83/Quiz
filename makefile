quiz.exe: quiz.c quiz.o
	gcc -Wall -ansi -pedantic -c quiz.c
	gcc -o quiz.exe quiz.o
