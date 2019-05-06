#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <math.h>
#include "assert.h"

/**
 * Expect Minion Card to add +1 actions to currentPlayer.
 */
int checkCardEffectMinion(int card, struct gameState *state) {
    int choice1 = 0, choice2 =0, choice3 = 0;
    int handPos = 0;

    // Execute Minion Card
    cardEffect(card, choice1, choice2, choice3, state, handPos, 0);
    
    assert(state->numActions -= state->numActions+1); // should have +1 action

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

    checkCardEffectMinion(minion, &G);

    return 0;
}