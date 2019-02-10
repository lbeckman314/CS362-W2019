#include "myAssert.h"
#include "dominion.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    struct gameState *testGame = newGame();
    int testPlayers[MAX_PLAYERS];

    testGame->numPlayers = 2;

    testGame->hand[testPlayers[0]][0] = curse;
    testGame->hand[testPlayers[0]][0] = curse;
    testGame->hand[testPlayers[0]][0] = curse;
    testGame->hand[testPlayers[0]][0] = curse;
    testGame->hand[testPlayers[0]][0] = curse;

    getWinners(testPlayers, testGame);
}

