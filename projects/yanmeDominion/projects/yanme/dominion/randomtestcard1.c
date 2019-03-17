/*
 * randomtestcard1.c
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestcard1: randomtestcard1.c 
 *      gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "smithy"
#define MAXPLAYERS 4
#define MINPLAYERS 2

int main(int argc, char* argv[]) {
    // seed the random generator
    srand(time(NULL));
    int numPlayers = -5;
    int thisPlayer = -5;
    numPlayers = rand() % (MAXPLAYERS - 1 - MINPLAYERS) + MAXPLAYERS;
    thisPlayer = rand() % numPlayers; 
    printf("numPlayers: %d\n", numPlayers);
    printf("thisPlayer: %d\n", thisPlayer);

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);


    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- TEST 1: random test --------------

    //printf("deck count: %d\n", G->deckCount[thisPlayer]);
    //printf("hand count: %d\n", G->handCount[thisPlayer]);

    printf("TEST 1: random test\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 1;
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 2);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 3);
    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 2);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 3);
    myAssert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 2);
    myAssert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 3);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}
