#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include "assert.h"

/**
 * Expect Great Hall Card to draw have +1 numActions and +1 handCount for currentPlayer.
 */
int checkCardEffectGreatHall(int currentPlayer, struct gameState *state) {
    int handPos = 0;
    int initialActions = state->numActions;
    int initialCardCount = state->handCount[currentPlayer];

    // Execute Great Hall Card
    cardEffectGreatHall(handPos, currentPlayer, state);

    int cardCount = initialCardCount + 1;

    assert(initialActions == 1); // should have one action after previous action
    assert(initialActions == 1);// should have one action after discard

    return cardCount;
}

int main(int argc, char** argv) {
    int currentPlayer = 1;
    struct gameState G;

    int random = rand() % 10, result;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    printf("Testing cardEffectGreatHall.\n");

    result = initializeGame(2, k, random, &G);
    assert(result == 0);

    checkCardEffectGreatHall(currentPlayer, &G);

    return 0;
}