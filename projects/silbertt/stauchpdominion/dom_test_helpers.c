/******************************************************************************
** Patrick Stauch
** domtesthelpers.h
**
** A small library of functions used for testing the implementation of dominion
*******************************************************************************/

#include <stdio.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "dom_test_helpers.h"

#define SHOWTESTPASS 0
#define SHOWTESTFAIL 0

int testAssertEqual(char* testName, int expected, int value)
{
  if (expected == value)
  {
    #if SHOWTESTPASS
      printf("\"%s\" PASSED\n", testName);
    #endif
    return 1;
  }
  else
  {
    #if SHOWTESTFAIL
      printf("\"%s\" FAIL value %d expected %d\n", testName,value,expected);
    #endif
    return 0;
  }
}

int testAssertNotEqual(char* testName, int expected, int value)
{
    if (expected != value)
  {
    #if SHOWTESTPASS
      printf("\"%s\" PASSED\n", testName);
    #endif
    return 1;
  }
  else
  {
    #if SHOWTESTFAIL
      printf("\"%s\" FAIL value %d expected %d\n", testName,value,expected);
    #endif
    return 0;
  }
}

int testAssert(char* testName, int testValue)
{
  if (testValue)
  {
    #if SHOWTESTPASS
      printf("\"%s\" PASSED\n", testName);
    #endif
    return 1;
  }
  else
  {
    #if SHOWTESTFAIL
      printf("\"%s\" FAIL\n", testName);
    #endif
    return 0;
  }
}
