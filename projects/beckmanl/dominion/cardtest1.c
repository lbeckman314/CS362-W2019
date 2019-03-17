#include "myAssert.h"
#include "dominion.c"
#include <stdio.h>

int main(int argc, char* argv[])
{
    // smithy
    int player = 0;
    struct gameState *testGame = newGame();
    int handPos = 0;
    testGame->deckCount[player] = 5;
    testGame->handCount[player] = 5;

    myAssert(mySmithy(player, testGame, handPos) == 0); 
    myAssert(testGame->deckCount[player] == 2);
    myAssert(testGame->handCount[player] == 7);

    mySmithy(player, testGame, handPos); 
    myAssert(testGame->deckCount[player] == 0);
    myAssert(testGame->handCount[player] == 8);
    //printf("deck count: %d\n", testGame->deckCount[player]);
    //printf("hand count: %d\n", testGame->handCount[player]);
}
