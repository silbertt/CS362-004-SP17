/***************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 3-Unit Test 
 * Cardtest for village Cardd
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

	printf("UNIT TEST CARD 4 - Village  Card Function\n\n");

	struct gameState state;
	int passFail = 0;
	int i, k;
	int beforeHand, beforeDeck, result, action;
	int bonus = 0;
	//state.deckCount[0] = 15;
	//state.handCount[0] = 5;		
	
	int kingdom[10] = {smithy, adventurer, village, embargo, minion, salvager, feast, sea_hag, tribute, remodel};
	//to fill deck
	for(i = 0; i < 5; i++){
		for(k = 0; k < MAX_DECK; k++){
			state.hand[i][k] = copper;
			state.deck[i][k] = copper;

		}
	}

	for(i = 0; i < 2; i++){
		for(k = 0; k < 60; k++){
			initializeGame(i, kingdom, 23, &state);
			state.hand[0][i] = village;
			beforeDeck = state.deckCount[0];
			beforeHand = state.handCount[0];	
			action = state.numActions;		
			result = cardEffect(village, 0, 0, 0, &state, i, &bonus);
			//printf("RESULT %d\n", result);
			//printf("BEFORE Hand %d\n", beforeHand);
			//printf("BEFORE Deck %d\n", beforeDeck);
			//printf("ACTIONS BEFore %d\n", action);
			//printf("AFTER Hand %d\n", state.handCount[0]); 
			//printf("AFTER Deck %d\n", state.deckCount[0]);
			//printf("ACTIONS AFTER %d\n\n", state.numActions);
			if(beforeHand != state.handCount[0]){
				passFail = 1;
				printf("TEST FAILED - EITHER NO CARDS ADDED OR MORE THAN 1 CARD ADDED\n");
			}
			if((action + 2) != state.numActions){
				passFail = 1;

				//printf("beforeDeck %d\n", beforeDeck-2);
				//printf("afterDeck %d\n", state.deckCount[0]);
				printf("TEST FAILED - NUMBER OF ACTIONS NOT +2\n");
			}
		}
	}
	if(passFail == 0){printf("TEST PASSED\n\n");}
	else{printf("TEST FAILED\n\n");}	

	return 0;
}
