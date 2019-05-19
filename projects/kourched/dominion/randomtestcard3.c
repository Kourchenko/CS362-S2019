#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "dominion.h"
#include "dominion_helpers.h"

void RANDOM_TEST_CARD_SMITHY(struct gameState *state) {
    int currentPlayer = 1;
    int randomHandPos = rand() % numHandCards(&state);
    int randomNumActions = rand() % 10;
    int cardDrawn;
    
    while (1) {
        cardEffectGreatHall(randomHandPos, currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];
        if (state->numActions == randomNumActions && 
            cardDrawn == adventurer ||
            cardDrawn == gardens ||
            cardDrawn == embargo ||
            cardDrawn == village ||
            cardDrawn == minion ||
            cardDrawn == mine ||
            cardDrawn == cutpurse ||
            cardDrawn == sea_hag ||
            cardDrawn == tribute ||
            cardDrawn == smithy) {
                print(" Card Drawn ");
                exit(200);
            }
    }
}


int main(int argc, char *argv[]) {
    srand(time(NULL));
    struct gameState G;
    int result;
    int random = rand() % 10;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

    result = initializeGame(2, k, random, &G);

    RANDOM_TEST_CARD_SMITHY(&G);
    return 0;
}