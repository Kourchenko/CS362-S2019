#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "dominion.h"
#include "dominion_helpers.h"

void RANDOM_TEST_CARD_ADVENTURER(struct gameState *state) {
    int cardDrawn = 0;
    int randomDrawnTreasure;
    int randomDeckCount;
    int currentPlayer = 1;
    
    int iterations = 0;
    while (1) {
        iterations++;
        randomDrawnTreasure = rand() % 3;
        randomDeckCount = rand() % 10;
        cardEffectAdventurer(cardDrawn = 0, randomDrawnTreasure, currentPlayer, state);

        if (state->handCount[currentPlayer] == 0) {
            printf("Iteration %d", iterations);
            printf(" HandCount = 0 ");
            exit(200);
        } else if (state->deckCount[currentPlayer] == randomDeckCount) {
            printf("Iteration %d", iterations);
            printf(" Random Deck Count = %d", randomDeckCount);
            exit(200);
        }
    }
}


int main(int argc, char *argv[]) {
    srand(time(NULL));
    struct gameState G;
    int result;
    int random = rand() % 10;
    int k[10]= {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy };

    result = initializeGame(2, k, random, &G);

    RANDOM_TEST_CARD_ADVENTURER(&G);
    return 0;
}