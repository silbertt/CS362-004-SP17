/***************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 3-Unit Test 2
 * Unit test of numHandCards function
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

	printf("UNIT TEST 3-TESTING numHandCards Function\n\n");

	struct gameState state;
	int passFail = 0;//to check if the test passes
	int i, j;
	int testFunction = 0;
	
	//to hold kingdom cards for initialization
	int kingdom[10] = {adventurer, smithy, village, embargo, minion, salvager, feast, sea_hag, tribute, remodel};
	//to check for two-four player and different seeds, should all be 5
	for(i = 2; i < 5; i++){
		for(j = 1; j < 501; j++){ 
			initializeGame(i, kingdom, j, &state);
			testFunction = numHandCards(&state);
			if(testFunction != 5){passFail = 1;}//if test fails
		}
	}
	
	if(passFail == 0){printf("TEST PASSED\n\n");}
	else{printf("TEST FAILED, NOT EQUAL TO 5\n\n");}

	return 0;
}
