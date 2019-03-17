#include "myAssert.h"
#include "dominion.h"
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

    myAssert(play_mine(player, choice1, choice2, testGame, handPos) == 0);
}
