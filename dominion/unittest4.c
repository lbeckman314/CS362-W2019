#include "myAssert.h"
#include "dominion.c"
#include <stdio.h>

void test1(int player, struct gameState *testGame);
void test2(int player, struct gameState *testGame);

int main(int argc, char* argv[])
{
    // updateCoins function

    struct gameState *testGame = newGame();
    int player = 0;

    test1(player, testGame);
    test2(player, testGame);
}


void test1(int player, struct gameState *testGame)
{
    int bonus = 0;
    testGame->handCount[player] = 5;
    testGame->hand[player][0] = copper;
    testGame->hand[player][1] = copper;
    testGame->hand[player][2] = silver;
    testGame->hand[player][3] = silver;
    testGame->hand[player][4] = gold;

    updateCoins(player, testGame, bonus);
    myAssert(testGame->coins == 9);
}

void test2(int player, struct gameState *testGame)
{
    int bonus = 2;
    testGame->handCount[player] = 3;
    testGame->hand[player][0] = copper;
    testGame->hand[player][1] = silver;
    testGame->hand[player][2] = gold;

    updateCoins(player, testGame, bonus);
    myAssert(testGame->coins == 8);
}
