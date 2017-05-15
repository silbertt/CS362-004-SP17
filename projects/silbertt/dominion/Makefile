CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

randomtestResults: randomtestcard1.c randomtestcard2.c randomtestcard3.c
	echo "CARD TEST 1 RESULTS:" > randomtestcard1.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard1.c rngs.o -o randomtestcard1 -lm -g $(CFLAGS)
	randomtestcard1 >> randomtestcard1.out
	gcov -b dominion.c >> randomtestcard1.out
	gcov dominion.c
	cat dominion.c.gcov >> randomtestcard1.out
	echo "CARD TEST 2 RESULTS:" > randomtestcard2.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard2.c rngs.o -o randomtestcard2 -lm -g $(CFLAGS)
	randomtestcard2 >> randomtestcard2.out
	gcov -b dominion.c >> randomtestcard2.out
	gcov dominion.c
	cat dominion.c.gcov >> randomtestcard2.out
	echo "CARD TEST 3 RESULTS:" > randomtestcard3.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o randomtestcard3.c rngs.o -o randomtestcard3 -lm -g $(CFLAGS)
	randomtestcard3 >> randomtestcard3.out
	gcov -b dominion.c >> randomtestcard3.out
	gcov dominion.c
	cat dominion.c.gcov >> randomtestcard3.out

unittestresults.out: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c  dominion.c rngs.c
	echo "TESTING RESULTS:" > unittestresults.out
	echo "UNIT TEST 1" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest1.c rngs.o -o unittest1 -lm -g $(CFLAGS)
	unittest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "TESTING RESULTS:" >> unittestresults.out
	echo "UNIT TEST 2" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest2.c rngs.o -o unittest2 -lm -g $(CFLAGS)
	unittest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "TESTING RESULTS:" >> unittestresults.out
	echo "UNIT TEST 3" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest3.c rngs.o -o unittest3 -lm -g $(CFLAGS)
	unittest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "TESTING RESULTS:" >> unittestresults.out
	echo "UNIT TEST 4" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o unittest4.c rngs.o -o unittest4 -lm -g $(CFLAGS)
	unittest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "TESTING RESULTS:" >> unittestresults.out
	echo "CARD TEST 1" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest1.c rngs.o -o cardtest1 -lm -g $(CFLAGS)
	cardtest1 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "TESTING RESULTS:" >> unittestresults.out
	echo "CARD TEST 2" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest2.c rngs.o -o cardtest2 -lm -g $(CFLAGS)
	cardtest2 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "TESTING RESULTS:" >> unittestresults.out
	echo "CARD TEST 3" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest3.c rngs.o -o cardtest3 -lm -g $(CFLAGS)
	cardtest3 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	echo "TESTING RESULTS:" >> unittestresults.out
	echo "CARD TEST 4" >> unittestresults.out
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 dominion.o cardtest4.c rngs.o -o cardtest4 -lm -g $(CFLAGS)
	cardtest4 >> unittestresults.out
	gcov -b dominion.c >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player testDrawCard testBuyCard badTestDrawCard randomtestResults unittestresults.out

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 unittestresults.out randomtestcard1 randomtestcard2 randomtestcard3 randomtestcard1.out randomtestcard2.out randomtestcard3.out
