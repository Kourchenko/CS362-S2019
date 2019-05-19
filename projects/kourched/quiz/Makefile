CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme.o:
	gcc -o testme -g testme.c $(CFLAGS)

runtests: testme.o
	./testme &> unittest.out
	gcov testme.c >> unittest.out
	cat testme.c.gcov >> unittest.out

clean:
	rm -f *.o *.gcno *.out testme