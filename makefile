all:function1.o function2.o q1.c q2.c
	gcc -Wall -std=c99 -pedantic function1.o q1.c -o q1
	gcc -Wall -std=c99 -pedantic function2.o q2.c -o q2
	rm *.o
function1.o:function1.c
	gcc -Wall -std=c99 -pedantic -c function1.c
function2.o:function2.c
	gcc -Wall -std=c99 -pedantic -c function2.c	
