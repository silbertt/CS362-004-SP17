/***************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 3-Unit Test 2 
 * Function scoreFor
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

	printf("\nUNIT TEST 2-TESTING scoreFor Function\n\n");
	struct gameState state;
	//scoring cards
	int scoreCards[6] = {curse, estate, duchy, province, great_hall, gardens}; 
	int scoreFunction, scoreManual = 0; //to hold the overall score from function/manual add	
	int passFail = 0; //to check if the test passes

	//set the number of cards in each pile
	state.handCount[0] = 3;
	state.discardCount[0] = 3;
	state.deckCount[0] = 3;

	int i;
	for(i = 0; i < 3; i++){
		state.hand[0][i] = scoreCards[0]; //add three curse cards to handcount
		scoreManual -= 1;
		state.discard[0][i] = scoreCards[2];//add duchy cards 
		scoreManual += 3;
		state.deck[0][i] = scoreCards[3]; //add province cards
		scoreManual +=6;
	}

	scoreFunction = scoreFor(0, &state);
	if(scoreFunction != scoreManual){passFail = 1;} //if test failes
//	printf("Score Manual = %d\n", scoreManual);
//	printf("Score function = %d\n", scoreFunction);

	scoreManual = 0;
	for(i = 0; i < 3; i++){
		state.hand[0][i] = scoreCards[1]; //add three curse cards to handcount
		scoreManual += 1;
		state.discard[0][i] = scoreCards[2];//add duchy cards 
		scoreManual += 3;
		state.deck[0][i] = scoreCards[4]; //add province cards
		scoreManual +=1;
	}

	scoreFunction = scoreFor(0, &state);
	if(scoreFunction != scoreManual){passFail = 1;} //if test failes
//	printf("Score Manual = %d\n", scoreManual);
//	printf("Score function = %d\n", scoreFunction);
	
	scoreManual = 0;
	for(i = 0; i < 3; i++){
		state.hand[0][i] = scoreCards[3]; //add three curse cards to handcount
		scoreManual += 6;
		state.discard[0][i] = scoreCards[4];//add duchy cards 
		scoreManual += 1;
		state.deck[0][i] = scoreCards[5]; //add province cards
		scoreManual = scoreManual + (fullDeckCount(0, 0, &state)/10);
	}

	scoreFunction = scoreFor(0, &state);
	if(scoreFunction != scoreManual){passFail = 1;} //if test failes
//	printf("Score Manual = %d\n", scoreManual);
//	printf("Score function = %d\n", scoreFunction);
	
	scoreManual = 0;
	for(i = 0; i < 3; i++){
		state.hand[0][i] = scoreCards[1]; //add three curse cards to handcount
		scoreManual += 1;
		state.discard[0][i] = scoreCards[2];//add duchy cards 
		scoreManual += 3;
		state.deck[0][i] = scoreCards[0]; //add province cards
		scoreManual -=1;
	}

	scoreFunction = scoreFor(0, &state);
	if(scoreFunction != scoreManual){passFail = 1;} //if test failes
//	printf("Score Manual = %d\n", scoreManual);
//	printf("Score function = %d\n", scoreFunction);

	if(passFail == 0){printf("TEST PASSED\n\n");}//if test passed
	else{printf("TEST FAILED\n\n");}//if test failed

	return 0;
}
