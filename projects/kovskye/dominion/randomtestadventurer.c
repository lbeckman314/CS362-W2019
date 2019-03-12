#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

int testAdventurer(int player, struct gameState *gameFinish)
{
	struct gameState gameStart;
	int i;

	int cardDrawn = 0;
	int treasureStart = 0;
	int treasureFinish = 0;
	int handStart = gameFinish->handCount[player];
	int handFinish = gameFinish->handCount[player];

	memcpy(&gameStart, gameFinish, sizeof(struct gameState));
	cardEffect(adventurer, 0, 0, 0, gameFinish, 0, 0);

	for (i = 0; i < handStart; i++) {
		cardDrawn = gameStart.hand[player][i];

		if (cardDrawn == copper) {
			treasureStart++;
		} else if (cardDrawn == silver) {
			treasureStart++;
		} else if (cardDrawn == gold) {
			treasureStart++;
		}
	}

	for (i = 0; i < handFinish; i++) {
		cardDrawn = gameFinish->hand[player][i];

		if (cardDrawn == copper) {
			treasureFinish++;
		} else if (cardDrawn == silver) {
			treasureFinish++;
		} else if (cardDrawn == gold) {
			treasureFinish++;
		}
	}

	assert((treasureFinish - treasureStart) >= 0);

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
	printf("Adventurer Random Tests\n");

	for (tests = 0; tests < 2000; tests++) {
		initializeGame(2, k, seed, &game);
		player = Random() * 2;

		random1 = Random() * MAX_HAND;
		random2 = Random() * MAX_DECK;
		random3 = Random() * MAX_HAND;

		game.handCount[player] = random1;
		game.deckCount[player] = random2;
		game.discardCount[player] = random3;
		game.whoseTurn = player;

		for (int i = 0; i < game.deckCount[player]; i++) {
			game.hand[player][i] = (Random() * 26) + 1;
		}

		testAdventurer(player, &game);
	}

	printf("tests passed!\n");

	return 0;
}
