lsw03:		lsw03.o	lsw03f_add.o	lsw03f_sub.o 
		gcc -Wall -o lsw03 lsw03.o lsw03f_add.o
lsw03.o:		lsw03.c	lsw03f_add.o	lsw03f_sub.o 
		gcc -Wall -c lsw03.c lsw03f_add.o lsw03f_sub.o
lsw03f_add.o:	lsw03f_add.c
		gcc -Wall -c lsw03f_add.c
lsw03f_sub.o:	lsw03f_sub.c
		gcc -Wall -c lsw03f_sub.c