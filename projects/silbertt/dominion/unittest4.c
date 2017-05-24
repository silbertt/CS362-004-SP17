/***************************************
 * Teage Silbert
 * CS362 SP17
 * Assignment 3-Unit Test 2
 * Unit test to test supplyCount function
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

	printf("UNIT TEST 4-TESTING supplyCount Function\n\n");

	struct gameState state;
	int passFail = 0;//to check if the test passes
	int i, j;
	int testFunction = 0;
	
	//to hold kindom cards for initialization
	int kingdom[10] = {adventurer, smithy, village, embargo, minion, salvager, feast, sea_hag, tribute, remodel};

	for(i = 2; i < 7; i++){
		for(j = 1; j < 1001; j++){
			initializeGame(i, kingdom, j, &state);
			testFunction = supplyCount(i, &state);
			//if a test fails
			if(state.supplyCount[i] != testFunction){passFail =1;}
		}
	}

	if(passFail == 0){printf("TEST PASSED\n");}
	else{printf("TEST FAILED\n");}

	return 0;
}
