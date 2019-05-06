#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include "assert.h"

/**
 * Expect Embargo Card to add +2 gold to currentPlayer and +1 Embargo Tokens.
 */

int checkCardEffectEmbargo(struct gameState *state) {
    int handPos = 0;
    int currentPlayer = 1;
    int choice1 = 0;
    int choice2 = 1;
    int initialGold = state->coins;

    // Execute Embargo Card
    cardEffectEmbargo(choice1, choice2, handPos, currentPlayer, state);

    int postGold = initialGold;
    assert(initialGold == postGold);
    assert(state->embargoTokens[choice1] == 1); // should be +1 embargo tokens
    return 0;
}

int main(int argc, char** argv) {
    struct gameState G;
    
    int random = rand() % 10, result;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};

    printf("Testing cardEffectEmbargo.\n");

    result = initializeGame(2, k, random, &G);
    assert(result == 0);

    checkCardEffectEmbargo(&G);

    return 0;
}