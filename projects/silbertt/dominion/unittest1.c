/***************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 3-Unit Test 1
 * Unit test of updateCoins in dominion.c
 * ************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(int argc, char** argv){

	printf("UNIT TEST 1-TESTING updateCoins Function\n\n");
	//create a game state struct to work with
	struct gameState state;

	//set number of coins to 0
	state.coins = 0;
	
	//to hold whether the test passes or fails
	int passFail = 0;
	int i;
	//to continuously add coins and check if it works
	for(i = 0; i < 100; i++){
		state.handCount[0] = i+1;
		state.hand[0][i] = gold;
		updateCoins(0, &state, 0);
		//to checok if it is a multiple of 3
		if(state.coins != ((i + 1) * 3)){
			passFail = 1;
		}	
	}
	//if passed
	if(passFail == 0){
		printf("TEST PASSED\n");
	}
	else{
		printf("TEST FAILED ON GOLD\n");
	}

	//to reset the coins	
	state.coins = 0;
	
	//to check the silver coins
	for(i = 0; i < 100; i++){
		state.handCount[0] = i+1;
		state.hand[0][i] = silver;
		updateCoins(0, &state, 0);
		//to checok if it is a multiple of 3
		if(state.coins != ((i + 1) * 2)){
			passFail = 1;
		}	
	}
	//if passed
	if(passFail == 0){
		printf("TEST PASSED\n");
	}
	else{
		printf("TEST FAILED ON SILVER\n");
	}

	//to reset the coings
	state.coins = 0;

	//to check the copper coins
	for(i = 0; i < 100; i++){
		state.handCount[0] = i+1;
		state.hand[0][i] = copper;
		updateCoins(0, &state, 0);
		//to checok if it is a multiple of 3
		if(state.coins != i + 1){
			passFail = 1;
		}	
	}
	//if passed
	if(passFail == 0){
		printf("TEST PASSED\n");
	}
	else{
		printf("TEST FAILED ON COPPER\n");
	}

	//to reset the coings
	state.coins = 0;

	//to check the bonus items
	for(i = 0; i < 100; i++){
		state.handCount[0] = i+1;
		state.hand[0][i] = NULL;
		updateCoins(0, &state, i + 1);
		//to checok if it is a multiple of 3
		if(state.coins != i + 1){
			passFail = 1;
		}	
	}
	//if passed
	if(passFail == 0){
		printf("TEST PASSED\n");
	}
	else{
		printf("TEST FAILED ON BONUS\n");
	}
	
	
	return 0;
}
