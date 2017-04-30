/***************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 3-Unit Teet 
 * Cardtest for great hall card
 * ************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int main(int argc, char** argv){

	printf("UNIT TEST CARD 3-Great Hall Card Function\n\n");

	struct gameState state;
	int passFail = 0;
	int i, k;
	int beforeHand, beforeDeck, result, actions;
	int bonus = 0;
	//state.deckCount[0] = 15;
	//state.handCount[0] = 5;		
	
	int kingdom[10] = {smithy, adventurer, great_hall, embargo, minion, salvager, feast, sea_hag, tribute, remodel};
	for(i = 0; i < 5; i++){
		for(k = 0; k < MAX_HAND; k++){
			state.hand[i][k] = copper;
			state.deck[i][k] = copper;
		}
	}

	//to go through all 4 players
	for(i = 0; i < 5; i++){
		for(k = 0; k < 60; k++){
			initializeGame(i, kingdom, 23, &state);
			state.hand[0][i] = great_hall;
			beforeDeck = state.deckCount[0];
			beforeHand = state.handCount[0];
			actions = state.numActions;			
			result = cardEffect(great_hall, 0, 0, 0, &state, i, &bonus);
			//printf("K %d, I %d\n", k, i);
				//to ensure number of actions is increased
			if((actions + 1) != state.numActions){
				passFail = 1;
				printf("TEST FAILED - EITHER NO ACTIONS OR MORE THAN 1 ACTION ADDED\n");
			}
			//to ensure that 1 card is added to hand (the great hall card is discarded)
			if(beforeHand != state.handCount[0]){
				passFail = 1;

				printf("TEST FAILED - NUMBER OF CARDS ADDED TO HAND INCORRECT\n");
			}
		}
	}
	if(passFail == 0){printf("TEST PASSED\n\n");}
	else{printf("TEST FAILED\n\n");}

	return 0;
}
