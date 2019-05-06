#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include "assert.h"

/**
 * Expect Smithy Card to draw 3 cards into handCount of currentPlayer.
 */
int checkCardEffectGreatHall(int currentPlayer, struct gameState *state) {
    int handPos = 0;

    cardEffectGreatHall(handPos, currentPlayer, state);
    int cardCount = state->handCount[currentPlayer];

    return cardCount;
}

int main(int argc, char** argv) {
    int currentPlayer = 1;
    struct gameState G;
    int random = rand() % 10, result;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    printf("Testing cardEffectSmithy.\n");

    result = initializeGame(2, k, random, &G);
    assert(result == 0);

    struct gameState *state = &G;

    int preCardCount = state->handCount[currentPlayer];
    int postCardCount = checkCardEffectSmithy(currentPlayer, &G);

    assert(preCardCount != postCardCount);
    return 0;
}