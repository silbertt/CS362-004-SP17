/******************************************************************************
** Patrick Stauch
** domtesthelpers.h
**
** A small library of functions used for testing the implementation of dominion
*******************************************************************************/

#include "dominion.h"

int testAssertEqual(char* tesName, int expected, int value);

int testAssertNotEqual(char* testName, int expected, int value);

int testAssert(char* testName, int testValue);
