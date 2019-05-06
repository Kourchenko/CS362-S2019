#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include "assert.h"

/**
 * Expect Minion Card to add +2 coins for choice==1 for currentPlayer.
 */
int checkCardEffectSteward(int card, struct gameState *state) {
    int choice1 = 1, choice2 = 0, choice3 = 0;
    int handPos = 0;
    int preCoins = state->coins;
    // Execute Steward Card
    cardEffect(card, choice1, choice2, choice3, state, handPos, 0);
    
    assert(preCoins -= state->coins+2); // should have +2 coins

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

    checkCardEffectSteward(steward, &G);

    return 0;
}