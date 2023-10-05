main : main.c copy.c
	gcc -o main main.c copy.c
main.c : main.c copy.h
	gcc -c main.c
copy.o : copy.c
	gcc -c copy.c
