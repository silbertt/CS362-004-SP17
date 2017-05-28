/***************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 3-Card Test 1
 * Testing smithy card function
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

	printf("UNIT TEST CARD 1-Smithy Card Function\n\n");
	
	struct gameState state;
	int passFail = 0;
	int i, j, k;	
	int bonus = 0;
	int cardCall, deck, handCount;
	
	int kingdom[10] = {smithy, adventurer, village, embargo, minion, salvager, feast, sea_hag, tribute, remodel};
	//to load deck with arbitary cards
	for(i = 0; i < 5; i++){
		for(k = 0; k < 10; k++){
			state.hand[i][k] = copper;
			state.deck[i][k] = copper;
		}
	}


	//to ensure it checks all locations in the deck	
	for(i = 0; i < 5 ; i++){
		//to check each location 1000 times
		for(j = 0; j < 60; j++){
			initializeGame(4, kingdom, 40, &state);//initalize game
			deck = state.deckCount[0]; //get number of cards in deck
			state.hand[0][i] = smithy; //to set where the smithy card is
			handCount = state.handCount[0]; //to get number of cards in hand
			cardCall = cardEffect(smithy, 0, 0, 0, &state, i, &bonus);//call function
			//deck should have three cards removed (-3)
			if((deck - 3) != state.deckCount[0]){
				passFail = 1;
				printf("TEST FAILED-WRONG NUMBER OF CARDS IN DECK\n");
			}
			//hand should have 3 new cards and be missing the smity card (+2)
			if((handCount + 2) != state.handCount[0]){
				passFail = 1;
				printf("TEST FAILED-WRONG NUMBER OF CARDS IN HAND\n");				
			}
			//to ensure the smithy card is no longer int he hand
			for(k = 0; k < state.handCount[0]; k++){
				if(state.hand[0][k] == smithy){
					passFail = 1;
					printf("TEST FAILED - SMITHY STILL IN HAND\n");
				}
			}
		}	
	}

	if(passFail == 0){printf("TEST PASSED\n\n");}
	else{printf("TEST FAILED\n\n");}
	
	return 0;
}
