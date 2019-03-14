#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

/* Random test for Great Hall card */
int testGreatHall(int player, struct gameState *gameFinish)
{
	struct gameState gameStart;

	memcpy(&gameStart, gameFinish, sizeof(struct gameState));
	cardEffect(great_hall, 0, 0, 0, gameFinish, 0, 0);

	assert(gameFinish->coins == gameStart.coins);
	assert(gameFinish->numBuys == gameStart.numBuys);
	assert(gameFinish->numActions >= gameStart.numActions);

	return 0;
}

int main()
{
	struct gameState game;
	int tests, player, random1, random2, random3;

	int seed = 900000000;
	int k[10] = {adventurer, council_room, feast, gardens, mine,
		remodel, smithy, village, baron, great_hall};

	memset(&game, 0, sizeof(struct gameState));
	printf("Great Hall Random Tests\n");

	for (tests = 0; tests < 2000; tests++) {
		initializeGame(2, k, seed, &game);
		player = Random() * 2;

		random1 = Random() * MAX_HAND;
		random2 = Random() * MAX_DECK;
		random3 = Random() * MAX_HAND;

		game.handCount[player] = random1;
		game.deckCount[player] = random2;
		game.discardCount[player] = random3;
		game.whoseTurn =  player;

		for (int i = 0; i < game.deckCount[player]; i++) {
			game.hand[player][i] = (Random() * 26) + 1;
		}

		testGreatHall(player, &game);
	}

	printf("Tests passed\n");
}
