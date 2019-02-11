#include "myAssert.h"
#include "dominion_helpers.h"
#include "dominion.c"
#include <stdio.h>

void supplyCountTest(struct gameState testGame);
void provinceCountTest(struct gameState testGame);

int main(int argc, char* argv[])
{
    // isGameOver function
    struct gameState testGame;

    int i;
    for (i = 0; i < 25; i++)
    {
        testGame.supplyCount[i] = 1;
    }

    supplyCountTest(testGame);
    provinceCountTest(testGame);
}


void supplyCountTest(struct gameState testGame)
{
    int i;
    myAssert(isGameOver(&testGame) == 0);

    for (i = 0; i < 3; i++)
    {
        testGame.supplyCount[i] = 0;
    }

    myAssert(isGameOver(&testGame) == 1);
}


void provinceCountTest(struct gameState testGame)
{

    testGame.supplyCount[province] = 100;
    myAssert(isGameOver(&testGame) == 0);

    testGame.supplyCount[province] = 0;
    myAssert(isGameOver(&testGame) == 1);
}
