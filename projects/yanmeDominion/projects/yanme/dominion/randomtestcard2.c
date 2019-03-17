/*
 * randomtestcard2.c
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestcard2: randomtestcard2.c 
 *      gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)
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

#define TESTCARD "mine"
#define MAXPLAYERS 4

int main(int argc, char* argv[]) {
    // seed the random generator
    srand(time(NULL));

    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);


    printf("----------------- Testing Card: %s ----------------\n", TESTCARD);

    // ----------- TEST 1: random test --------------

    printf("TEST 1: random test\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    
    do {
        choice1 = rand() % (gold + 1 - copper) + gold;
        choice2 = rand() % (treasure_map + 1 - curse) + treasure_map;
    } while(getCost(testG.hand[thisPlayer][choice1]) + 3 > getCost(choice2));

    myAssert(getCost(testG.hand[thisPlayer][choice1]) + 3 <= getCost(choice2));

    //printf("%d :: %d\n", testG.supplyCount[choice2], G.supplyCount[choice2]);

    printf("%d :: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);
    cardEffect(mine, choice1, choice2, choice3, &testG, handpos, &bonus);

    //printf("%d :: %d\n", testG.hand[ thisPlayer ][ testG.handCount[thisPlayer] ], choice2);

    myAssert(testG.handCount[thisPlayer] == G.handCount[thisPlayer]);
    printf("%d :: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);

    //printf("%d :: %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer]);

    // decrease number in supply pile
    myAssert(testG.supplyCount[choice2] == G.supplyCount[choice2]);
    //printf("%d :: %d\n", testG.supplyCount[choice2], G.supplyCount[choice2]);

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);

    return 0;
}

