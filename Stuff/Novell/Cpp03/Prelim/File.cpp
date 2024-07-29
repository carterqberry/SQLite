#include <iostream>
#include <cassert>
#include <cstdio>
using namespace std;

class File {
   FILE* fp;
public:
   File(const char* fname) {
      fp = fopen(fname, "r");
      if (fp == 0)
         throw "File open error";
      cout << "File opened\n";
   }
   const char* getline() {
      char buf[BUFSIZ];
      return fgets(buf, BUFSIZ, fp);
   }
   ~File() {
      assert(fp != 0);
      fclose(fp);
      cout << "File closed\n";
   }
};

int main() {
   File f("File.cpp");
   cout << f.getline();
}

/* Output:
File opened
#include <iostream>
File closed
*/
