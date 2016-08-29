lsw:			main.o	lswf.o
			gcc -o lsw		main.o	lswf.o
main.o:			main.c	lswf.o
			gcc -c -Wall main.c
lswf.o:			lswf.c		lsw06.h
			gcc -c -Wall lswf.c