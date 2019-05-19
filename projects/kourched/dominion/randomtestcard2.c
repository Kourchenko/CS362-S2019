#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include "dominion.h"
#include "dominion_helpers.h"

void RANDOM_TEST_CARD_SMITHY(struct gameState *state) {
    int currentPlayer = 1;
    int randomHandPos = rand() % numHandCards(&state);
    int cardDrawn;
    
    while (1) {
        cardEffectSmithy(randomHandPos, currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];

        if (cardDrawn == smithy) {
            print(" Drew Smithy: Top Card ");
            exit(200);
        } else if (cardDrawn == adventurer) {
            print (" Drew Adventurer: Top Card ");
            exit(200);
        } else if (cardDrawn == gardens) {
            print(" Drew Gardens: Top Card ");
            exit(200);
        } else if (cardDrawn == embargo) {
            print(" Drew Embargo: Top Card ");
            exit(200);
        } else if (cardDrawn == village) {
            print (" Drew Village: Top Card ");
            exit(200);
        } else if (cardDrawn == minion) {
            print(" Drew Minion: Top Card ");
            exit(200);
        } else if (cardDrawn == mine) {
            print(" Drew Mine: Top Card ");
            exit(200);
        } else if (cardDrawn == cutpurse) {
            print (" Drew Cut Purse: Top Card ");
            exit(200);
        } else if (cardDrawn == sea_hag) {
            print(" Drew Sea Hag: Top Card ");
            exit(200);
        } else if (cardDrawn == tribute) {
            print(" Drew Tribute: Top Card ");
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