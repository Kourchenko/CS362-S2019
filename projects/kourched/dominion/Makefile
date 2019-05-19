CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard1: gcc -0 randomtestcard1 -g randomtestcard1.c $(CFLAGS)
	./randomtestcard1 &> randomtestcard1.out
	gcov randomtestcard1.c >> randomtestcard1.out
	cat randomtestcard1.c.gcov >> randomtestcard1.out

randomtestcard2: gcc -0 randomtestcard2 -g randomtestcard2.c $(CFLAGS)
	./randomtestcard2 &> randomtestcard2.out
	gcov randomtestcard2.c >> randomtestcard2.out
	cat randomtestcard2.c.gcov >> randomtestcard2.out

randomtestcard3: gcc -0 randomtestcard3 -g randomtestcard3.c $(CFLAGS)
	./randomtestcard3 &> randomtestcard3.out
	gcov randomtestcard3.c >> randomtestcard3.out
	cat randomtestcard3.c.gcov >> randomtestcard3.out

testAllRandomTestCards: randomtestcard1 randomtestcard2 randomtestcard3
	echo "randomtestcard1.c.gcov" > randomtestcardresults.out
	cat randomtestcard1.c.gcov >> randomtestcardresults.out
	echo "randomtestcard2.c.gcov" >> randomtestcardresults.out
	cat randomtestcard2.c.gcov >> randomtestcardresults.out
	echo "randomtestcard3.c.gcov" >> randomtestcardresults.out
	cat randomtestcard3.c.gcov >> randomtestcardresults.out

cleanrandomtestcards: rm -f *.o *.gcno *.out randomtestcard1 randomtestcard2 randomtestcard3

#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
