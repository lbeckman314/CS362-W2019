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
#define maxplayers 4
#define minplayers 2

int main(int argc, char* argv[]) {
    // seed the random generator
    srand(time(NULL));
    int numplayers = -5;
    int thisplayer = -5;
    numplayers = rand() % (maxplayers - 1 - minplayers) + maxplayers;

    thisplayer = rand() % numplayers;
    thisplayer = 0;
    printf("numplayers: %d\n", numplayers);
    printf("thisplayer: %d\n", thisplayer);

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numplayers, k, seed, &G);
    

    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- TEST 1: random test --------------

    //printf("deck count: %d\n", G->deckCount[thisplayer]);
    printf("hand count: %d\n", G.handCount[0]);
    printf("hand count: %d\n", G.handCount[1]);
    printf("hand count: %d\n", G.handCount[2]);
    printf("hand count: %d\n", G.handCount[3]);

    printf("TEST 1: random test\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    testG.supplyCount[gold] = 100;

    int drawntreasure = 0;
    int cardDrawn = -5;

    int n;
    for (n = 0; n < testG.handCount[thisplayer]; n++) {
        cardDrawn = testG.hand[thisplayer][n];
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
            drawntreasure++;
        }
    }

    int drawntreasurePre = drawntreasure;
    drawntreasure = 0;

    cardEffect(adventurer, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("testhand: %d\n", testG.handCount[thisplayer]);
    for (n = 0; n < testG.handCount[thisplayer]; n++) {
        cardDrawn = testG.hand[thisplayer][n];
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold) {
            drawntreasure++;
        }
    }

    if (drawntreasure > 0) {
        myAssert(drawntreasure == drawntreasurePre + 2);
    }
    else {
        myAssert(drawntreasure == drawntreasurePre);
    }
    printf("%d :: %d\n", drawntreasure, drawntreasurePre);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}
