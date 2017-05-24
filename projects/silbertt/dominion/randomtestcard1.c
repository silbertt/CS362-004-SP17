/**************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 4 - Random Testing
 * Testing Smithy card function
 * ***********************************/

#include "dominion.h"
#include "dominion_helpers.h" 
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, char** argv){

	printf("RANDOM TEST 1 - 'SMITHY' - CARD FUNCTION\n\n");

	//create all variables needed for the game
	struct gameState state;
	int players[4] = {1, 2, 3, 4};
	int passFail = 0;
	int kingdom[10] = {smithy, adventurer, village, embargo, minion, salvager, feast, sea_hag, tribute, remodel};
	int treasure[3] = {gold, silver, copper};
	int i, randNumPlayers, randTurn, handCount, deckCount, hPosition;
	
	//go through 10K hands
	for(i = 0; i < 10000; i ++){
		//to get number of players
		randNumPlayers = floor(Random() * 3) + 2;
		//determine who's turn it is
		randTurn = floor(Random() * randNumPlayers) + 0;
		//get random amounts of cards in the decks
		deckCount = state.deckCount[randTurn] = floor(Random() * MAX_DECK);
		handCount = state.handCount[randTurn] = floor(Random() * MAX_DECK);
		
		//set the position
		hPosition = floor(Random() * state.handCount[randTurn]);
		//add smithy card to deck
		state.hand[randTurn][hPosition] = smithy;
				
		smithyPlay(randTurn, &state, hPosition);
	       	
		//check to ensure hand has two additional cards		
		if((handCount + 2) != state.handCount[randTurn]){
			printf("ERROR ON HAND COUNT ON TEST %d\n\n", i);
			printf("PLAYERS %d\n", randNumPlayers);
			printf("PLAYER TURN %d\n", randTurn);
			printf("HAND BEFORE %d\n", handCount);
			printf("DECK BEFORE %d\n", deckCount);
			printf("HAND AFTER %d\n", state.handCount[randTurn]);
			printf("DECK AFTER %d\n", state.deckCount[randTurn]);
			passFail = 1;
		}
		//check to ensure the deck has three less cards
		if((deckCount - 3) != state.deckCount[randTurn]){
			printf("ERROR ON DECK COUNT ON TEST %d\n\n", i);
			printf("PLAYERS %d\n", randNumPlayers);
			printf("PLAYER TURN %d\n", randTurn);
			printf("HAND BEFORE %d\n", handCount);
			printf("DECK BEFORE %d\n", deckCount);
			printf("HAND AFTER %d\n", state.handCount[randTurn]);
			printf("DECK AFTER %d\n", state.deckCount[randTurn]);
			passFail = 1;
		}
		
	}

	if(passFail == 0){
		printf("----SMITHY CARD PASSED----\n\n");
	}
	else{
		printf("*****SMITHY CARD FAILED*****\n\n");
	}
	 













}
