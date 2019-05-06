#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include "assert.h"

/**
 * Expect Adventurer handCount to be less than or equal to 0 for the initial state, as we drew until we drew treasures for currentPlayer.
 */
int checkCardEffectAdventurer(struct gameState *state) {
    int cardDrawn = 0;
    int drawnTreasure = 0;
    int currentPlayer = 1;
    int initialHandCount = state->hand[currentPlayer][state->handCount[currentPlayer]];

    // Execute Great Hall Card
    cardEffectAdventurer(cardDrawn, drawnTreasure, currentPlayer, state);
    int postHandCount = state->hand[currentPlayer][state->handCount[currentPlayer]];
    assert(initialHandCount == postHandCount); // should have less

    return 0;
}

int main(int argc, char** argv) {
    struct gameState G;

    int random = rand() % 10, result;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    printf("Testing cardEffectAdventurer.\n");

    result = initializeGame(2, k, random, &G);
    assert(result == 0);

    checkCardEffectAdventurer(&G);

    return 0;
}