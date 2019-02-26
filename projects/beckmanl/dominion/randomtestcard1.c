/*
An overview of the random generator structure1.
    Identify the method under test
    Identify all the dependencies (parameters)
    Write code to generate random inputs for the chosen method
    Invoke the method (execute the method)
    Check if stopping criterion (like time or number of loops) is not satisfied, if not go back to step 2.

Note on inputs:
    If the input is a primitive data type, generate a random primitive value, etc.
    If the input is an array, create an array and initialize it with some random values, etc.
    Try to “stay random” but shift the probability space (e.g., if you choose int numCoppersInDeck = rand() % 20 and int numAdventurersToPlay = rand() % 10. There must be a logical reason in the code specification for choosing 20 and 10.

You also need to improve your oracles (step 5) (i.e., assertions "if/print in our case") until you feel that all the problems that should be caught are caught! Make sure your Oracle helps you develop a ‘rock solid’ random generator and not just a random generator.
*/

/*
 * randomtestcard.c
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestcard1: randomtestcard1.c randomtestcard2.c randomtestcardadventurer.c 
 *      gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TESTCARD "smithy"
#define MAXPLAYERS 4

int main(int argc, char* argv[]) {
    // seed the random generator
    srand(time(NULL));
    int numPlayersRandom = -5;
    int thisPlayerRandom = -5;
    numPlayersRandom = rand() % MAXPLAYERS;
    if (numPlayersRandom < 2) {
        numPlayersRandom += 2;
    }
    thisPlayerRandom = rand() % numPlayersRandom; 
    printf("numPlayers: %d\n", numPlayersRandom);
    printf("thisPlayer: %d\n", thisPlayerRandom);

    int newCards = 0;
    int discarded = 1;
    int xtraCoins = 0;
    int shuffledCards = 0;

    int i, j, m;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int remove1, remove2;
    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
            sea_hag, tribute, smithy, council_room};

    //numPlayersRandom = 2;
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
    // printf("handcount: %d\n", testG.handCount[thisPlayer]);
    // printf("deck: %d\n", testG.deckCount[thisPlayer]);
    // printf("newCards: %d\n", newCards);
    // printf("discarded: %d\n", discarded);
    // printf("shuffledCards: %d\n", shuffledCards);
    // printf("-----\n");
    cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);
    // printf("handcount: %d\n", testG.handCount[thisPlayer]);
    // printf("deck: %d\n", testG.deckCount[thisPlayer]);
    // printf("newCards: %d\n", newCards);
    // printf("discarded: %d\n", discarded);
    // printf("shuffledCards: %d\n", shuffledCards);
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + 2);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - 4);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + 2);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] + 3);

    printf("-----\n");
    //cardEffect(smithy, choice1, choice2, choice3, &testG, handpos, &bonus);

    // printf("handcount: %d\n", testG.handCount[thisPlayerRandom]);
    // printf("deck: %d\n", testG.deckCount[thisPlayerRandom]);
    // printf("newCards: %d\n", newCards);
    // printf("discarded: %d\n", discarded);
    // printf("shuffledCards: %d\n", shuffledCards);


    // tests that the removed cards are no longer in the player's hand
    /*
    for (m=0; m<testG.handCount[thisPlayer]; m++) {
        printf("(%d)", testG.hand[thisPlayer][m]);
        assert(testG.hand[thisPlayer][m] != remove1);
        assert(testG.hand[thisPlayer][m] != remove2);
    }
    

    /*
    newCards = 2;
    xtraCoins = 0;
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
    assert(testG.coins == G.coins + xtraCoins);

    // ----------- TEST 2: choice1 = 2 = +2 coins --------------
    printf("TEST 2: choice1 = 2 = +2 coins\n");

    // copy the game state to a test case
    memcpy(&testG, &G, sizeof(struct gameState));
    choice1 = 2;
    cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);

    newCards = 0;
    xtraCoins = 2;
    printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
    printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
    printf("coins = %d, expected = %d\n", testG.coins, G.coins + xtraCoins);
    assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
    assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
    assert(testG.coins == G.coins + xtraCoins);

    // ----------- TEST 3: choice1 = 3 = trash two cards --------------

    printf("TEST 3: choice1 = 3 = trash two cards\n");
    choice1 = 3;

    // cycle through each eligible combination of 2 cards to trash
    for (i=1; i<G.handCount[thisPlayer]; i++) {
        for (j=i+1; j<G.handCount[thisPlayer]; j++) {

            G.hand[thisPlayer][0] = steward;
            G.hand[thisPlayer][1] = copper;
            G.hand[thisPlayer][2] = duchy;
            G.hand[thisPlayer][3] = estate;
            G.hand[thisPlayer][4] = feast;

            // copy the game state to a test case
            memcpy(&testG, &G, sizeof(struct gameState));

            printf("starting cards: ");
            for (m=0; m<testG.handCount[thisPlayer]; m++) {
                printf("(%d)", testG.hand[thisPlayer][m]);
            }
            printf("; ");

            choice2 = j;
            choice3 = i;
            remove1 = testG.hand[thisPlayer][i];
            remove2 = testG.hand[thisPlayer][j];
            cardEffect(steward, choice1, choice2, choice3, &testG, handpos, &bonus);

            printf("removed: (%d)(%d); ", remove1, remove2);
            printf("ending cards: ");

            // tests that the removed cards are no longer in the player's hand
            for (m=0; m<testG.handCount[thisPlayer]; m++) {
                printf("(%d)", testG.hand[thisPlayer][m]);
                assert(testG.hand[thisPlayer][m] != remove1);
                assert(testG.hand[thisPlayer][m] != remove2);
            }
            printf(", expected: ");
            for (m=1; m<G.handCount[thisPlayer]; m++) {
                if (G.hand[thisPlayer][m] != G.hand[thisPlayer][i] && G.hand[thisPlayer][m] != G.hand[thisPlayer][j]) {
                    printf("(%d)", G.hand[thisPlayer][m]);
                }
            }
            printf("\n");

            // tests for the appropriate number of remaining cards
            newCards = 0;
            xtraCoins = 0;
            discarded = 3;
            if (i==1 && j==2) {
                printf("hand count = %d, expected = %d\n", testG.handCount[thisPlayer], G.handCount[thisPlayer] + newCards - discarded);
                printf("deck count = %d, expected = %d\n", testG.deckCount[thisPlayer], G.deckCount[thisPlayer] - newCards + shuffledCards);
            }
            assert(testG.handCount[thisPlayer] == G.handCount[thisPlayer] + newCards - discarded);
            assert(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer] - newCards + shuffledCards);
        }

    }
    */

    printf("\n >>>>> SUCCESS: Testing complete %s <<<<<\n\n", TESTCARD);


    return 0;
}
