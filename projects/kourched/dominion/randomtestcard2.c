#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "dominion.h"
#include "dominion_helpers.h"

void RANDOM_TEST_CARD_SMITHY(struct gameState *state) {
    int currentPlayer = 1;
    int randomHandPos = rand() % 10;
    int cardDrawn;
    int iterations = 0;
    while (1) {
        iterations++;
        printf("Iteration: %d\n", iterations);

        cardEffectSmithy(randomHandPos, currentPlayer, state);
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];

        if (cardDrawn == smithy) {
            printf(" Drew Smithy: Top Card ");
            break;
        } else if (cardDrawn == adventurer) {
            printf(" Drew Adventurer: Top Card ");
            break;
        } else if (cardDrawn == gardens) {
            printf(" Drew Gardens: Top Card ");
            break;
        } else if (cardDrawn == embargo) {
            printf(" Drew Embargo: Top Card ");
            break;
        } else if (cardDrawn == village) {
            printf(" Drew Village: Top Card ");
            break;
        } else if (cardDrawn == minion) {
            printf(" Drew Minion: Top Card ");
            break;
        } else if (cardDrawn == mine) {
            printf(" Drew Mine: Top Card ");
            break;
        } else if (cardDrawn == cutpurse) {
            printf(" Drew Cut Purse: Top Card ");
            break;
        } else if (cardDrawn == sea_hag) {
            printf(" Drew Sea Hag: Top Card ");
            break;
        } else if (cardDrawn == tribute) {
            printf(" Drew Tribute: Top Card ");
            break;
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