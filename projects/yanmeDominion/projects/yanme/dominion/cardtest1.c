#include "myAssert.h"
#include "dominion.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    // smithy
    int player = 0;
    struct gameState *testGame = newGame();
    int handPos = 0;
    testGame->deckCount[player] = 5;
    testGame->handCount[player] = 5;

    myAssert(play_smithy(player, handPos, testGame) == 0); 
    myAssert(testGame->deckCount[player] == 2);
    myAssert(testGame->handCount[player] == 7);
    printf("deck count: %d\n", testGame->deckCount[player]);
    printf("hand count: %d\n", testGame->handCount[player]);

    play_smithy(player, handPos, testGame); 
    myAssert(testGame->deckCount[player] == 0);
    myAssert(testGame->handCount[player] == 8);
    //printf("deck count: %d\n", testGame->deckCount[player]);
    //printf("hand count: %d\n", testGame->handCount[player]);
}
