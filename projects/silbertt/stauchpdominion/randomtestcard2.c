/**************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 4 - Random Testing
 * Testing adventurer card
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

	printf("RANDOM TEST 2 - 'ADVENTURER' - CARD FUNCTION\n\n");

	//create all variables needed for the game
	struct gameState state;
	int players[4] = {1, 2, 3, 4};
	int passFail = 0;
	int kingdom[10] = {smithy, adventurer, village, embargo, minion, salvager, feast, sea_hag, tribute, remodel};
	int treasure[3] = {gold, silver, copper};
	int i, k, j, randNumPlayers, randTurn, handCount, deckCount, discardCount, hPosition, randHandi = 0;

	int deckGen[16] = {smithy, adventurer, village, embargo, minion, salvager, feast, sea_hag, tribute, remodel, gold, silver, copper, duchy, estate, province};
	 
	int tempH, bonus;	
	
	//go through 10K hands
	for(i = 0; i < 10000; i++){
		//to get number of players
		randNumPlayers = floor(Random() * 3) + 2;
		//determine who's turn it is
		randTurn = floor(Random() * randNumPlayers) + 0;
		//get random amounts of cards in the decks
		//to ensure valid numbers in each 'deck'
		do{
			deckCount = state.deckCount[randTurn] = floor(Random() * MAX_DECK);
			handCount = state.handCount[randTurn] = floor(Random() * MAX_HAND);
			discardCount = state.discardCount[randTurn] = floor(Random() * MAX_DECK);
		}while(deckCount <= 5 && handCount <= 5 && discardCount <=5);
		
		state.whoseTurn = randTurn;
		//printf("deckvount %d\n", deckCount);
		//printf("handocount %d\n", handCount);	
		//printf("discardCount %d\n", discardCount);	
		//to generate random cards for deck
		for(k = 0; k < deckCount; k++){
			state.deck[randTurn][k] = floor(Random() * 27);
			//printf("Deck random is %d\n", state.deck[randTurn][k]);
			//printf("DECK %d\n", state.deck[randTurn][k]);
		}
		//to ensure there are at least two treasure cards
		state.deck[randTurn][2] = 6;
		state.deck[randTurn][3] = 6;

		//printf("HAND COUNT %d\n", handCount);
		//to to generate random hand
		for(k = 0; k < handCount; k++){
			//printf("HAND INTERATION %d\n", k);
			state.hand[randTurn][k] = floor(Random() * 27);
			//printf("HAND %d\n", state.hand[randTurn][k]);
		}
		//printf("******OUT OF LOOPS*****\n");	
				//set the position
		hPosition = floor(Random() * state.handCount[randTurn]);
				
		//adventurerPlay(randTurn, &state, &tempH);
		//edited to run with new dominion.c
		//playAdventurer(&state);
		cardEffect(adventurer, 0, 0, 0, &state, hPosition, &bonus);
	       	//printf("CARD PLAYED\n");	
		//check to ensure hand has two additional cards		
		if((handCount + 1) != state.handCount[randTurn]){
			//printf("ERROR ON HAND COUNT AT %d\n\n", i);
			//printf("PLAYERS %d\n", randNumPlayers);
			//printf("PLAYER TURN %d\n", randTurn);
			//printf("Turn %d\n", randTurn);
			//printf("PLAYERS %d\n", randNumPlayers);
			//printf("HAND BEFORE %d\n", handCount);
			//printf("HAND AFTER %d\n", state.handCount[randTurn]);
			//printf("DECK BEFORE %d\n", deckCount);
			//printf("DECK AFTER %d\n", state.deckCount[randTurn]);
			//printf("DISCARD BEFORE %d\n", discardCount);
			//printf("DISCARD AFTER %d\n", state.discardCount[randTurn]);
			passFail = 1;
		}
	}

	if(passFail == 0){
		printf("----ADVENTURER CARD PASSED----\n\n");
	}
	else{
		printf("*****ADVENTURER CARD FAILED*****\n\n");
	}
	 













}
