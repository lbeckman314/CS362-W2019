#include "myAssert.h"
#include "dominion.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    // adventurer
    int player = 0;
    int drawntreasure = 0;
    struct gameState *testGame = newGame();

    testGame->deckCount[player] = 5;
    testGame->handCount[player] = 5;

    int temphand[testGame->handCount[player]];
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 10, testGame);

    myAssert(play_adventurer(player, temphand, testGame) == 0);

    int lastCard = testGame->hand[player][testGame->handCount[player]-1];
    myAssert(lastCard == copper || lastCard == silver || lastCard == gold);
    //printf("card: %d\n", testGame->hand[player][testGame->handCount[player]-1]);
}

