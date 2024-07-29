#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

// Read ints from a file into an array
int readInts(const char* fileName, int*& nums)
{
   // Initialize array
   enum {EXTENT = 10};
   nums = new int[EXTENT];
   int capacity = EXTENT;
   int numRead = 0;

   // Read numbers
   ifstream inf(fileName);
   if (inf) {
      int num;
      while (inf >> num) {
         if (numRead == capacity) {
            // Extend array
            capacity += EXTENT;
            int* newNums = new int[capacity];
            
            // Copy elements (could use memcpy here)
            for (int i = 0; i < numRead; ++i)
               newNums[i] = nums[i];

            // Delete old array
            delete [] nums;
            nums = newNums;
         }

         // Add new element
         assert(numRead < capacity);
         nums[numRead++] = num;
      }
   }

   return numRead;
}

int main(int argc, char* argv[])
{
   if (argc > 1)
   {
      int* nums;
      int nInts = readInts(argv[1], nums);
      cout << "Read " << nInts << " numbers\n";
      for (int i = 0; i < nInts; ++i)
         cout << nums[i] << ' ';
   }
}

