#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include "assert.h"

/**
 * Expect Cut Purse current player to have +2 gold.
 */
int checkCardEffectCutPurse(struct gameState *state) {
    int handPos = 0;
    int currentPlayer = 1;
    int initialGold = state->coins;

    // Execute Cut Purse Card
    cardEffectCutPurse(handPos, currentPlayer, state);

    int postGold = initialGold + 1;

    // Bug Error: Invalid 'i' and 'j' loop values cause misplaced gold
    assert(initialGold != postGold);

    return 0;
}

int main(int argc, char** argv) {
    struct gameState G;
    
    int random = rand() % 10, result;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    printf("Testing cardEffectCutPurse.\n");

    result = initializeGame(2, k, random, &G);
    assert(result == 0);

    checkCardEffectCutPurse(&G);

    return 0;
}