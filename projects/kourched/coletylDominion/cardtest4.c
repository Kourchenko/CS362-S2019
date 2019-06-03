/*
 ** cardtest4.c
 **   
*/

/*
 * Testing the Great Hall cardEffect portion
*/


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include "assertT.h"
#define TESTCARD "Great Hall"

int main() {
	int newCards = 0;
	int discarded = 1;
	int xtraCoins = 0;
	int shuffledCards = 0;
	int i, j, m;
	int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
	int remove1, remove2;
	int seed = 1000;
	int numPlayers = 2;
	int thisPlayer = 0;
	struct gameState G, testG;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
		sea_hag, tribute, smithy, council_room};

	// initialize a game &testG and player cards
	initializeGame(numPlayers, k, seed, &G);
	printf("----------------- Testing Card: %s ----------------\n", TESTCARD);
	// ----------- TEST 1: Test the smithy function --------------
	printf("TEST 1: \n");
	
	memcpy(&testG, &G, sizeof(struct gameState));
	int currentPlayer = whoseTurn(&testG);	
	gainCard(16, &testG, 1, 0);

	int prevHand = testG.handCount[currentPlayer];
	int prevActions = testG.numActions;
	cardEffect(great_hall, choice1, choice2, choice3, &testG, handpos, &bonus);
	int gainedCards = testG.handCount[currentPlayer] - prevHand;
	int gainedActions = testG.numActions - prevActions;
	printf("Gained  %i actions, %i cards in hand\n", gainedActions, gainedCards+1); 
	assertT(gainedActions == 1);	
	assertT(gainedCards+1 == 1);	

}
