// ctest.h: Simple but effective automated test scaffolding
// Author: Chuck Allison, 2003-2007
// Permission to use granted provided source is cited

#ifndef TEST_H
#define TEST_H

#include <stdio.h>

static size_t nPass = 0;
static size_t nFail = 0;
static void do_test(const char* condText, int cond, const char* fileName, long lineNumber) {
  if (!cond) {
     printf("FAILURE: %s in file %s on line %d\n",condText,fileName,lineNumber);
     ++nFail;
  }
  else
     ++nPass;
}
static void do_fail(const char* text, const char* fileName, long lineNumber) {
  printf("FAILURE: %s in file %s on line %d\n",text,fileName,lineNumber);
  ++nFail;
}
static void succeed(void) {
  ++nPass;
}
static void report(void) {
  printf("\nTest Report:\n\n\tNumber of Passes = %d\n\tNumber of Failures = %d\n",
         nPass,nFail);
}

#define test(cond) do_test(#cond, cond, __FILE__, __LINE__)
#define fail_(text) do_fail(text, __FILE__, __LINE__)

#endif
