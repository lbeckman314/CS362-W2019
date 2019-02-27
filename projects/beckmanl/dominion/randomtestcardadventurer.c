/*
 * randomtestcardadventurer.c
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestcardadventurer: randomtestcardadventurer.c 
 *      gcc -o randomtestcardadventurer -g randomtestcardadventurer.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include "myAssert.c"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TESTCARD "adventurer"
#define MAXPLAYERS 4
#define MINPLAYERS 2

int main(int argc, char* argv[]) {
    // seed the random generator
    srand(time(NULL));
    int numPlayersRandom = -5;
    int thisPlayerRandom = -5;
    numPlayersRandom = rand() % (MAXPLAYERS - 1 - MINPLAYERS) + MAXPLAYERS;

    //choice1 = rand() % (gold + 1 - copper) + gold;
    thisPlayerRandom = rand() % numPlayersRandom;
    printf("numPlayers: %d\n", numPlayersRandom);
    printf("thisPlayer: %d\n", thisPlayerRandom);

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayersRandom, k, seed, &G);
    

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- TEST 1: random test --------------

    //printf("deck count: %d\n", G->deckCount[thisPlayer]);
    //printf("hand count: %d\n", G->handCount[thisPlayer]);

    printf("TEST 1: random test\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    testG.supplyCount[gold] = 100;

    int drawntreasure = 0;
    int cardDrawn = -5;

    int n;
    for (n = 0; n < testG.handCount[thisPlayer]; n++) {
        cardDrawn = testG.hand[thisPlayer][n];
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
            drawntreasure++;
        }
    }

    int drawntreasurePre = drawntreasure;
    drawntreasure = 0;

    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    for (n = 0; n < testG.handCount[thisPlayer]; n++) {
        cardDrawn = testG.hand[thisPlayer][n];
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
            drawntreasure++;
        }
    }

    myAssert(drawntreasure == drawntreasurePre + 2);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}
