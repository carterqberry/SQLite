#include "pool.h"
#include <cassert>
#include <iostream>
#include <cstring>
using namespace std;

Pool::Pool(size_t elemSize, size_t blockSize, bool traceFlag)
   : elemSize(elemSize), blockSize(blockSize), traceFlag(traceFlag)
{
   // Allocate the initial block
}

Pool::~Pool()
{
   // Delete each row, then the main array of pointers
}

void Pool::link(char* base)
{
}

void Pool::expand()
{
   // Expand pool by 1 block (row)

   // Allocate/initialize the new block
}

void* Pool::allocate()
{
   // Expand if exhausted

   // Update free pointer

   // Return pointer to old free space
}

void Pool::deallocate(void* p)
{
   // Prepend p to the free list
}

