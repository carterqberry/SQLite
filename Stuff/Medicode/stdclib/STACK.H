/* stack.h: Macros for a stack -
 *
 *   A simple-minded stack mechanism. The user's
 *   program must define the following in the scope
 *   where they are used:
 *
 *   MAXSTACK            The dimension of the stack
 *   size_t stkptr_ = 0; The stack pointer
 *   T stk_[MAXSTACK];   The stack: an array of type T
 *
 *   Execution aborts if the stack overflows or
 *   underflows.
 */

#include <assert.h>

/* Stack operations: */
#define PUSH(x) \
  (assert(stkptr_ < MAXSTACK), stk_[stkptr_++] = (x))
#define POP() \
  (assert(stkptr_ > 0), stk_[--stkptr_])
