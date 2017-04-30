/***************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 3-Unit Test 
 * Cardtest for Adventurer card
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

	printf("UNIT TEST CARD 2-Adventurer Card Function\n\n");

	struct gameState state;
	int passFail = 0;
	int i, k;
	int beforeHand, beforeDeck, result;
	int bonus = 0;
	//state.deckCount[0] = 15;
	//state.handCount[0] = 5;		
	
	int kingdom[10] = {smithy, adventurer, village, embargo, minion, salvager, feast, sea_hag, tribute, remodel};
	for(i = 0; i < 5; i++){
		for(k = 0; k < 15; k++){
			state.hand[i][k] = copper;
			state.deck[i][k] = copper;
		}
	}

	//to go through all 4 players
	for(i = 0; i < 5; i++){
		for(k = 0; k < 60; k++){
			initializeGame(i, kingdom, 23, &state);
			state.hand[0][i] = adventurer;
			beforeDeck = state.deckCount[0];
			beforeHand = state.handCount[0];			
			result = cardEffect(adventurer, 0, 0, 0, &state, i, &bonus);
			//printf("RESULT %d\n", result);
			//printf("BEFORE Hand %d\n", beforeHand);
			//printf("BEFORE Deck %d\n", beforeDeck);
			//printf("AFTER Hand %d\n", state.handCount[0]); 
			//printf("AFTER Deck %d\n\n", state.deckCount[0]);
			if((beforeHand + 2) != state.handCount[0]){
				passFail = 1;
				printf("TEST FAILED - LESS THAN TWO CARDS ADDED TO HAND\n");
			}
			if((beforeDeck - 2) > state.deckCount[0]){
				passFail = 1;

				//printf("beforeDeck %d\n", beforeDeck-2);
				//printf("afterDeck %d\n", state.deckCount[0]);
				printf("TEST FAILED - LESS THAN TWO CARDS REMOVED FROM DECK\n");
			}
		}
	}
	if(passFail == 0){printf("TEST PASSED\n\n");}
	else{printf("TEST FAILED\n\n");}	

	return 0;
}
