#include "myAssert.h"
#include "dominion.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    // village
    int player = 0;
    struct gameState *testGame = newGame();

    testGame->deckCount[player] = 5;
    testGame->handCount[player] = 5;


    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    initializeGame(2, k, 10, testGame);

    int actions = testGame->numActions;
    int actionsOld = actions;
    //int hand = testGame->handCount[player];
    //int handOld = hand;

    int card = village;
    int choice1 = 0;
    int choice2 = 0;
    int choice3 = 0;
    int handPos = 0;
    int bonusVal = 0;
    int *bonus = &bonusVal;

    myAssert(cardEffect(card, choice1, choice2, choice3, testGame, handPos, bonus) == 0);

    actions = testGame->numActions;
    //hand = testGame->handCount[player];
    myAssert(actions == actionsOld + 2);
    //myAssert(hand == handOld - 1);
    //myAssert(testGame->handCount[player][handPos] == -1);
    //printf("handPos: %d\n", testGame->handCount[player][handPos]);
    ///printf("actions: %d, actionsOld: %d\n", actions, actionsOld);
    //printf("hand: %d, handOld: %d\n", hand, handOld);
}
