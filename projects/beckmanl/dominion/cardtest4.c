#include "myAssert.h"
#include "dominion.c"
#include <stdio.h>

int main(int argc, char* argv[])
{
    // mine
    int player = 0;
    struct gameState *testGame = newGame();

    testGame->deckCount[player] = 5;
    testGame->handCount[player] = 5;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 10, testGame);

    int choice1 = copper;
    int choice2 = silver;
    int handPos = 0;

    myAssert(myMine(player, testGame, choice1, choice2, handPos) == 0);
}
